/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Setup

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  
  ledcSetup(3, 2000, 8);
  ledcAttachPin(BuzzerPin, 3);

  ledcSetup(CHANNEL_SCREEN, LEDfreq, LEDresolution);
  ledcAttachPin(ScreenLED, CHANNEL_SCREEN);

  tft.init();
  tft.fillScreen(TFT_BLACK);
  tft.setRotation(1);
  tft.setSwapBytes(true);

  pinMode(button, INPUT);

  pinMode(FILpin1, INPUT_PULLUP);
  pinMode(FILpin2, INPUT_PULLUP);

  pinMode(FilRunoutSensorPin, INPUT);
  pinMode(FilSensorPause, OUTPUT);
  pinMode(RelayPin, OUTPUT);

  xTaskCreatePinnedToCore(
                  Task2code,   // Task function.
                  "Task2",     // name of task.
                  10000,       // Stack size of task
                  NULL,        // parameter of the task
                  2,           // priority of the task
                  &Task2,      // Task handle to keep track of created task
                  0);           // pin task to core 0 */

  delay(100);

  Serial.begin(115200);

  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }


  Firebase.begin(FIREBASE_HOST,FIREBASE_Authorization_key);

  attachInterrupt(digitalPinToInterrupt(25), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(26), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(27), BUTTON, HIGH);

  attachInterrupt(digitalPinToInterrupt(4), FILupdateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(17), FILupdateEncoder, CHANGE);

  digitalWrite(RelayPin, HIGH);

  ScreenLEDA = map(BrightnessPercentage, 0, 100, 0, 255);
  ledcAnalogWrite(CHANNEL_SCREEN, ScreenLEDA);


////////////////////////////////////////////////////////////*  Web server - app  */

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain","Astas");
  });

  server.on("/_SCREEN1", HTTP_GET, [] (AsyncWebServerRequest *request) {

      Value = String(U) + "_" + String(I) + "_" + String(P) + "_" + String(AvgP) + "_" + String(MaxP) + "_" + String(C) + "_" + String(E) + "_" + String(EC) + "_" + String(FC) + "_" + String(FL) + "_" + String(FW * 1000) + "_";

      Value = Value + String(day() - 1) + ":" + String(hour()) + ":" + String(minute()) + ":" + String(second()) + "_";

      Value = Value + String(PrintHour) + ":" + String(PrintMin) + ":" + String(int(PrintSec)) + "_";

      if (screen == "SpoolSelectSettings"){
        Value = Value + "Choosing spool" + "_";
      } else{
        Value = Value + String(CurrentSpool) + ". " + CurSpoolMatText + "_";
      }

      Value = Value + String(CurSpoolFW, 0) + "/" + String(CurSpoolWeight) + "_";

      Value = Value + String(CurSpoolFL, 0) + "/" + String(CurSpoolLenght) + "_";

      Value = Value + String(CurSpoolPercentage) + "_";

      Value = Value + String(Material) + "_";

      if (RelayState == 1){
          Value = Value + String(PrintingON) + "_";
        } else {
          Value = Value + "off" + "_";
        }
    
    request->send(200, "text/plain", Value);
  });


  server.on("/_SCREEN2", HTTP_GET, [] (AsyncWebServerRequest *request) {

      Value = String(Material) + "_";

      if (RelayState == 1){
          Value = Value + String(PrintingON) + "_";
        } else {
          Value = Value + "off" + "_";
        }

        Value = Value + String(RelayState) + "_" + String(LED) + "_" + String(FilRunoutSensor) + "_" + String(FilJamsSensor) + "_" + String(CurrentSpool) + "_" + String(AutoOff) + "_" + String(AutoOffMillis) + "_" + String(LEDMode) + "_" + String(LEDBrightnessPercentage) + "_" + String(LEDSparkle) + "_";
    
    request->send(200, "text/plain", Value);
  });

  server.on("/_LEDON", HTTP_GET, [](AsyncWebServerRequest *request) {
    LED = 1;
  });

  server.on("/_LEDOFF", HTTP_GET, [](AsyncWebServerRequest *request) {
    LED = 0;
  });

  server.on("/_ON", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(RelayPin, HIGH);
    RelayState = 1;
    if (screen == "Energy2"){
      clearScreen = 0;
    }
  });

  server.on("/_OFF", HTTP_GET, [](AsyncWebServerRequest *request) {
    digitalWrite(RelayPin, LOW);
    RelayState = 0;
    if (screen == "Energy2"){
      clearScreen = 0;
    }
  });

  server.on("/_mat", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        Material = String(p->value());
        clearScreen = 0;
  });

  server.on("/_SPOOL", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String SPOOLRec = String(p->value());
        CurrentSpool = SPOOLRec.toInt();
  });

  server.on("/_RUNOUT0", HTTP_GET, [](AsyncWebServerRequest *request) {
        FilRunoutSensor = 0;
        NoFilament = 0;
        NoFil = 0;
        if (LastScreen == "HomeScreen"){
          ScreenXScroll = 160;
          clearScreen = 0;
        }
        BuzzerState = 0;
        ledcWriteTone(3, 0);
        digitalWrite(RelayPin, HIGH);
        RelayState = 1;
  });

  server.on("/_RUNOUT1", HTTP_GET, [](AsyncWebServerRequest *request) {
        FilRunoutSensor = 1;
  });

  server.on("/_JAMS0", HTTP_GET, [](AsyncWebServerRequest *request) {
        FilJamsSensor = 0;
        FilJammed = 0;
        digitalWrite(RelayPin, HIGH);
        RelayState = 1;
  });

  server.on("/_JAMS1", HTTP_GET, [](AsyncWebServerRequest *request) {
        FilJamsSensor = 1;
  });

  server.on("/_AUTOOFF0", HTTP_GET, [](AsyncWebServerRequest *request) {
        AutoOff = 0;
        digitalWrite(RelayPin, HIGH);
        RelayState = 1;
  });

  server.on("/_AUTOOFF1", HTTP_GET, [](AsyncWebServerRequest *request) {
        AutoOff = 1;
  });

  server.on("/_AUTOOFFTIME", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String AutoOFFTimeRec = String(p->value());
        AutoOffMillis = AutoOFFTimeRec.toInt();
  });

  server.on("/_WIFI", HTTP_GET, [](AsyncWebServerRequest *request) {
     if (screen == "WiFiConnect"){  
        AsyncWebParameter* p = request->getParam(0);
        NetPassString = String(p->value());
        if (NetPassString != "") {
            PassConnect = 1;
        }
     }      
  });

  server.on("/_SCREEN3", HTTP_GET, [] (AsyncWebServerRequest *request) {

      Value = String(Material) + "_";

      if (RelayState == 1){
          Value = Value + String(PrintingON) + "_";
        } else {
          Value = Value + "off" + "_";
        }

    request->send(200, "text/plain", Value);
  });

  server.on("/_LEDBRIGHTNESS", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String LEDPercentageString = String(p->value());
        LEDBrightnessPercentage = LEDPercentageString.toInt();
        FastLED.setBrightness(map(LEDBrightnessPercentage, 0, 100, 0, 255));
  });

  server.on("/_LEDMODE", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String LEDModeString = String(p->value());
        LEDMode = LEDModeString.toInt();
  });

  server.on("/_SPARKLE", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String SparkleString = String(p->value());
        LEDSparkle = SparkleString.toInt();
  });


  server.on("/_SETTINGS", HTTP_GET, [] (AsyncWebServerRequest *request) {

      Value = String(ec) + "_" + String(EnergyUnit) + "_" + Currency + "_" + String(BrightnessPercentage) + "_" + String(OnClickSound) + "_" + String(AlertsSound) + "_" + String(PrintingSound) + "_" + String(AutoScrollMode) + "_" + String(AutoScrollMillis) + "_";

    request->send(200, "text/plain", Value);
  });

  server.on("/_ENERGYCOST", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String EnergyCost = String(p->value());
        ec = EnergyCost.toFloat();
  });

  server.on("/_ENERGYUNIT", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String EnergyUnitString = String(p->value());
        EnergyUnit = EnergyUnitString.toInt();
        clearScreen = 0;
  });

  server.on("/_SCREENBRIGHTNESS", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String ScreenBrightness = String(p->value());
        ScreenLEDA = map(ScreenBrightness.toInt(), 0, 100, 0, 255);
        ledcAnalogWrite(CHANNEL_SCREEN, ScreenLEDA);
  });

  server.on("/_CURRENCY", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        Currency = String(p->value());
        if (Currency.indexOf("A") != -1 || Currency.indexOf("C") != -1){
          Currency = Currency + "$";
        }
        clearScreen = 0;
  });

  server.on("/_ONCLICKSOUND", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String OnClickSoundString = String(p->value());
        OnClickSound = OnClickSoundString.toInt();
  });

  server.on("/_ALERTSSOUND", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String AlertsSoundString = String(p->value());
        AlertsSound = AlertsSoundString.toInt();
  });

  server.on("/_PRINTINGSOUND", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String PrintingSoundString = String(p->value());
        PrintingSound = PrintingSoundString.toInt();
  });

  server.on("/_AUTOSCROLLMODE", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String AutoScrollModeString = String(p->value());
        AutoScrollMode = AutoScrollModeString.toInt();
  });

  server.on("/_AUTOSCROLLMILLIS", HTTP_GET, [](AsyncWebServerRequest *request) {
        AsyncWebParameter* p = request->getParam(0);
        String AutoScrollMillisString = String(p->value());
        AutoScrollMillis = AutoScrollMillisString.toInt();
  });

  
  AsyncElegantOTA.begin(&server);    // Start ElegantOTA
  server.begin();


    xTaskCreatePinnedToCore(
        Task1code,   // Task function.
        "Task1",     // name of task.
        10000,       // Stack size of task
        NULL,        // parameter of the task
        1,           // priority of the task
        &Task1,      // Task handle to keep track of created task
        0);          // pin task to core 0 

////////////////////////////////////////////////////////////////////////////////////////////////////////*  Preferences  */
  preferences.begin("M3D", false);

  EnergyUnit = preferences.getInt("eu", 0);
  ec = preferences.getInt("ec", 0.00) / 100.0;

  String AllCurrency[] = {"$", "E", "P", "A$", "C$"};
  Currency = AllCurrency[preferences.getInt("currency", 0)];

  LED = preferences.getInt("LED", 1);
  LEDMode = preferences.getInt("LEDMode", 0);
  LEDSparkle = preferences.getInt("LEDSparkle", 1);
  LEDBrightnessPercentage = preferences.getInt("LEDBrightness", 20);
  FastLED.setBrightness(map(LEDBrightnessPercentage, 0, 100, 0, 255));

  String AllMaterial[] = {"PLA", "PETG", "ABS", "TPU", "Nylon", "PVA", "HIPS", "ASA", "PC", "Custom1", "Custom2"};
  Material = AllMaterial[preferences.getInt("mat", 0)];
  

  SavedNet1SSIDString = preferences.getString("ssid1", ""); 
  SavedNet1PassString = preferences.getString("pass1", "");

  SavedNet2SSIDString = preferences.getString("ssid2", ""); 
  SavedNet2PassString = preferences.getString("pass2", "");

  SavedNet3SSIDString = preferences.getString("ssid3", ""); 
  SavedNet3PassString = preferences.getString("pass3", "");

  SavedNet4SSIDString = preferences.getString("ssid4", ""); 
  SavedNet4PassString = preferences.getString("pass4", "");

  SavedNet5SSIDString = preferences.getString("ssid5", ""); 
  SavedNet5PassString = preferences.getString("pass5", "");


  if (preferences.getBool("AC1", 0) == 0){
    AutoConnect1 = "OFF";
  } else{
    AutoConnect1 = "ON";
  }
  if (preferences.getBool("AC2", 0) == 0){
    AutoConnect2 = "OFF";
  } else{
    AutoConnect2 = "ON";
  }
  if (preferences.getBool("AC3", 0) == 0){
    AutoConnect3 = "OFF";
  } else{
    AutoConnect3 = "ON";
  }
  if (preferences.getBool("AC4", 0) == 0){
    AutoConnect4 = "OFF";
  } else{
    AutoConnect4 = "ON";
  }
  if (preferences.getBool("AC5", 0) == 0){
    AutoConnect5 = "OFF";
  } else{
    AutoConnect5 = "ON";
  }

  
  if (AutoConnect1 == "OFF" && AutoConnect2 == "OFF" && AutoConnect3 == "OFF" && AutoConnect4 == "OFF" && AutoConnect5 == "OFF") {
    AutomaticConnecting = 3;
  }

  BrightnessPercentage = preferences.getInt("ScreenB", 100);
  ScreenLEDA = map(BrightnessPercentage, 0, 100, 0, 255);
  ledcAnalogWrite(CHANNEL_SCREEN, ScreenLEDA);

  OnClickSound = preferences.getBool("SoundClick", 0);
  AlertsSound = preferences.getBool("SoundAlerts", 1);
  PrintingSound = preferences.getBool("SoundPrint", 1);

  AutoOff = preferences.getBool("AutoOff", 0);
  AutoOffMillis = preferences.getInt("AutoOffTime", 0);

  AutoScrollMode = preferences.getInt("AutoScroll", 0);
  AutoScrollMillis = preferences.getInt("AScrollMillis", 15000);

  //preferences.clear();

  Serial.println("Free Space: ");
  Serial.print(preferences.freeEntries());
}
