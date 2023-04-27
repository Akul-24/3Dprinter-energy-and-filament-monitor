///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Update Button

void UpdateButtonVoid()
{

if (UpdateButton == 1){
  UpdateButton = 0;

  if (NoFilament == 1 && millis() - BuzzerNoFilTimeoutMillis < 10000) {
      BuzzerNoFilTimeoutMillis = millis() - 10000;
    } else if (FilJammed == 1 && millis() - BuzzerFilJamTimeoutMillis < 10000) {
      BuzzerFilJamTimeoutMillis = millis() - 10000;
    } else if (AutoOffStart == 1 && millis() - BuzzerAutoOffTimeoutMillis < 10000) {
      BuzzerAutoOffTimeoutMillis = millis() - 10000;
    }

    if (FilJammed == 1) {
      FilJammed = 0;
      CurrencyChange = 1;
      ledcWriteTone(3, 0);
      RelayState = 1;
      digitalWrite(RelayPin, HIGH);
    }
    if (AutoOffStart == 1) {
      AutoOffStart = 0;
      CurrencyChange = 1;
      ledcWriteTone(3, 0);
      RelayState = 1;
      digitalWrite(RelayPin, HIGH);
    }
    if (screen == "NoFilament" && NoFilament == 1){
      ledcWriteTone(3, 0);
      RelayState = 1;
      digitalWrite(RelayPin, HIGH);
      screen = "HomeScreen";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 4;
      clearScreen = 0;
      CurrencyChange = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Home Screens
} else if (screen == "HomeScreen") { //To Main Settings Screen
      screen = "MainSettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "Filament") { //To Filament Settings Screen
      SettingsSelect = 1;
      SettingsCounter = 1;
      screen = "FilamentSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "Filament2") { //To Spool Select Settings Screen
      SettingsSelect = 0;
      SettingsCounter = 0;
      screen = "SpoolSelectSettings";
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "Energy") { //To Energy Settings Screen
      screen = "EnergySettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
    } else if (screen == "Energy2") { //To Energy2 Settings Screen
      screen = "PowerSettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament Select
    } else if (screen == "FilamentSettings" && SettingsSelect == 0) { //Back to Filament 1 Screen
      screen = "Filament";
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 1) { //Back to Filament 1 Screen (PLA)
      screen = "Filament";
      Material = "PLA";
      CurrentSpool = 0;
      preferences.putInt("mat", 0);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 2) { //Back to Filament 1 Screen (PETG)
      screen = "Filament";
      Material = "PETG";
      CurrentSpool = 0;
      preferences.putInt("mat", 1);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 3) { //Back to Filament 1 Screen (ABS)
      screen = "Filament";
      Material = "ABS";
      CurrentSpool = 0;
      preferences.putInt("mat", 2);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 4) { //Back to Filament 1 Screen (TPU)
      screen = "Filament";
      Material = "TPU";
      CurrentSpool = 0;
      preferences.putInt("mat", 3);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 5) { //Back to Filament 1 Screen (Nylon)
      screen = "Filament";
      Material = "Nylon";
      CurrentSpool = 0;
      preferences.putInt("mat", 4);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 6) { //Back to Filament 1 Screen (PVA)
      screen = "Filament";
      Material = "PVA";
      CurrentSpool = 0;
      preferences.putInt("mat", 5);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 7) { //Back to Filament 1 Screen (HIPS)
      screen = "Filament";
      Material = "HIPS";
      CurrentSpool = 0;
      preferences.putInt("mat", 6);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 8) { //Back to Filament 1 Screen (ASA)
      screen = "Filament";
      Material = "ASA";
      CurrentSpool = 0;
      preferences.putInt("mat", 7);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 9) { //Back to Filament 1 Screen (PC)
      screen = "Filament";
      Material = "PC";
      CurrentSpool = 0;
      preferences.putInt("mat", 8);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 10) { //Back to Filament 1 Screen (Custom1)
      screen = "Filament";
      Material = "Custom1";
      CurrentSpool = 0;
      preferences.putInt("mat", 9);
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilamentSettings" && SettingsSelect == 11) { //Back to Filament 1 Screen (Custom2)
      screen = "Filament";
      Material = "Custom2";
      CurrentSpool = 0;
      preferences.putInt("mat", 10);
      clearScreen = 0;
      CurrencyChange = 1;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Spool Select
    } else if (screen == "SpoolSelectSettings" && SettingsSelect == 0) { //Back to Filament 2 Screen (None)
      screen = "Filament2";
      CurrentSpool = 0;
      clearScreen = 0;
    } else if (screen == "SpoolSelectSettings" && SettingsSelect == 1) { //Back to Filament 2 Screen (1. Spool)
      screen = "Filament2";
      CurrentSpool = 1;
      clearScreen = 0;
    } else if (screen == "SpoolSelectSettings" && SettingsSelect == 2) { //Back to Filament 2 Screen (2. Spool)
      screen = "Filament2";
      CurrentSpool = 2;
      clearScreen = 0;
    } else if (screen == "SpoolSelectSettings" && SettingsSelect == 3) { //Back to Filament 2 Screen (3. Spool)
      screen = "Filament2";
      CurrentSpool = 3;
      clearScreen = 0;
    } else if (screen == "SpoolSelectSettings" && SettingsSelect == 4) { //Back to Filament 2 Screen (4. Spool)
      screen = "Filament2";
      CurrentSpool = 4;
      clearScreen = 0;
    } else if (screen == "SpoolSelectSettings" && SettingsSelect == 5) { //Back to Filament 2 Screen (5. Spool)
      screen = "Filament2";
      CurrentSpool = 5;
      clearScreen = 0;

    } else if (screen == "EnergySettings" && SettingsSelect == 0) { //Back to Energy 1 Screen
      screen = "Energy";
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MainSettings" && SettingsSelect == 0) { //Back to Home Screen
      screen = "HomeScreen";
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MainSettings" && SettingsSelect == 1) { //Main settings To Energy Cost
      screen = "EnergyCost";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy Unit
    } else if (screen == "EnergySettings" && SettingsSelect == 1) { //Energy Automatic Unit Select (Auto)
      screen = "Energy";
      clearScreen = 0;
      EnergyUnit = 2;
      preferences.putInt("eu", EnergyUnit);
      CurrencyChange = 1;
    } else if (screen == "EnergySettings" && SettingsSelect == 2) { //Energy kWh Unit Select (kWh)
      screen = "Energy";
      clearScreen = 0;
      EnergyUnit = 0;
      preferences.putInt("eu", EnergyUnit);
      CurrencyChange = 1;
    } else if (screen == "EnergySettings" && SettingsSelect == 3) { //Energy Wh Unit Select (Wh)
      screen = "Energy";
      clearScreen = 0;
      EnergyUnit = 1;
      preferences.putInt("eu", EnergyUnit);
      CurrencyChange = 1;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Power Settings  
    } else if (screen == "PowerSettings" && SettingsSelect == 0) { //Back to Home Screen
      screen = "Energy2";
      clearScreen = 0;
    } else if (screen == "PowerSettings" && SettingsSelect == 1) { //Power Select (ON/OFF)
      if(RelayState == 1){
        RelayState = 0;
        digitalWrite(RelayPin, LOW);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(LightRed, TFT_BLACK);
        tft.drawString("Off", 80, 26, GFXFF);
        
      } else{
        RelayState = 1;
        digitalWrite(RelayPin, HIGH);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(LightGreen, TFT_BLACK);
        tft.drawString("On  ", 80, 26, GFXFF);
      }
    } else if (screen == "PowerSettings" && SettingsSelect == 2) { //Pause Select (Pause / Resume)
      if(PausePrint == 1){
        PausePrint = 0;
        digitalWrite(FilSensorPause, LOW);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(LightGreen, TFT_BLACK);
        tft.drawString("Pause     ", 15, 46, GFXFF);
      } else{
        PausePrint = 1;
        digitalWrite(FilSensorPause, HIGH);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(LightGreen, TFT_BLACK);
        tft.drawString("Resume", 15, 46, GFXFF);
      }
    } else if (screen == "EnergySettings" && SettingsSelect == 3) { //Energy Wh Unit Select (Wh)
      screen = "Energy";
      clearScreen = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy Cost
    } else if (screen == "EnergyCost" && SettingsSelect == 0) { //Energy Cost To Main Settings (Back)
      screen = "MainSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "EnergyCost" && SettingsSelect == 2 && CostEdit == 0) { //Energy Cost Edit (Edit ON)
      CostEdit = 1;
    } else if (screen == "EnergyCost" && SettingsSelect == 2 && CostEdit == 1) { //Energy Cost Edit (Edit OFF)
      CostEdit = 0;
    } else if (screen == "EnergyCost" && SettingsSelect == 1) { //Energy Cost Edit (Save)
      ec = ecEdit;
      screen = "Save";
      clearScreen = 0;
      preferences.putInt("ec", ec * 100);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Currency
    } else if (screen == "Currency" && SettingsSelect == 0) { //Currency To Main Settings (Back)
      screen = "MainSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "MainSettings" && SettingsSelect == 2) { //Main Settings To Currency
      screen = "Currency";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 5;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "Currency" && SettingsSelect == 1) { //Currency To Main Settings (USD)
      screen = "Save";
      Currency = "$";
      preferences.putInt("currency", 0);
      clearScreen = 0;
    } else if (screen == "Currency" && SettingsSelect == 2) { //Currency To Main Settings (EUR)
      screen = "Save";
      Currency = "E";
      preferences.putInt("currency", 1);
      clearScreen = 0;
    } else if (screen == "Currency" && SettingsSelect == 3) { //Currency To Main Settings (GBP)
      screen = "Save";
      Currency = "P";
      preferences.putInt("currency", 2);
      clearScreen = 0;
    } else if (screen == "Currency" && SettingsSelect == 4) { //Currency To Main Settings (AUD)
      screen = "Save";
      Currency = "A$";
      preferences.putInt("currency", 3);
      clearScreen = 0;
    } else if (screen == "Currency" && SettingsSelect == 5) { //Currency To Main Settings (CAD)
      screen = "Save";
      Currency = "C$";
      preferences.putInt("currency", 4);
      clearScreen = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Power LED
    } else if (screen == "MainSettings" && SettingsSelect == 3) { //Main Settings To Power LED
      screen = "PowerLED";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "PowerLED" && SettingsSelect == 0) { //Power LED To Main Settings (Back)
      screen = "MainSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "PowerLED" && SettingsSelect == 1) { //Power LED ON - OFF (ON / OFF)
      if (LED == 1){
        LED = 0;
      } else if (LED == 0){
        LED = 1;
      }
      preferences.putInt("LED", LED);
    } else if (screen == "PowerLED" && SettingsSelect == 2) { //Power LED Mode Edit (Mode)
      LEDMode = LEDMode + 1;
      if (LEDMode == 3){
        LEDMode = 0;
      }
      preferences.putInt("LEDMode", LEDMode);
    } else if (screen == "PowerLED" && SettingsSelect == 3) { //Power LED Sparkle (ON / OFF)
      if (LEDSparkle == 1){
        LEDSparkle = 0;
      } else if (LEDSparkle == 0){
        LEDSparkle = 1;
      }
      preferences.putInt("LEDSparkle", LEDSparkle);
    }  else if (screen == "PowerLED" && SettingsSelect == 4 && LEDBrightnessEdit == 0) { //Power LED Edit Brightness ON (Brightness)
      LEDBrightnessEdit = 1;
    } else if (screen == "PowerLED" && SettingsSelect == 4 && LEDBrightnessEdit == 1) { //Power LED Edit Brightness OFF (Brightness)
      LEDBrightnessEdit = 0;
      preferences.putInt("LEDBrightness", LEDBrightnessPercentage);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  WiFi
    } else if (screen == "MainSettings" && SettingsSelect == 4) { //Main Settings To WiFi
      screen = "WiFi";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "WiFi" && SettingsSelect == 0) { //WiFi To Main Settings (Back)
      screen = "MainSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "WiFi" && SettingsSelect == 1) { //WiFi To Network (Network)
      screen = "NetworkScan";
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "WiFi" && SettingsSelect == 2) { //WiFi To AP (Access Point)
      screen = "AP";
      clearScreen = 0;
    } else if (screen == "WiFi" && SettingsSelect == 3) { //WiFi To Saved Networks (Saved Net.)
      screen = "SavedNet";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "WiFi" && SettingsSelect == 4) { //WiFi OFF (OFF)
      screen = "WiFiOFF";
      clearScreen = 0;
    } else if (screen == "AP") { //Access Point To WiFi
      screen = "WiFi";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Network Scan
    } else if (screen == "NetworkScan" && SettingsSelect == 0) { //Network Scan To WiFi
      screen = "WiFi";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "NetworkScan" && SettingsSelect == 1) { //Network Scan To Net1
      NetToConnect = 1;
      if (Net1PassOPEN == 1) {
        screen = "WiFiOPENConnecting";
      } else {
        screen = "WiFiConnect";
      }
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 0;
      clearScreen = 0;
    } else if (screen == "NetworkScan" && SettingsSelect == 2) { //Network Scan To Net2
      NetToConnect = 2;
      if (Net2PassOPEN == 1) {
        screen = "WiFiOPENConnecting";
      } else {
        screen = "WiFiConnect";
      }
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 0;
      clearScreen = 0;
    } else if (screen == "NetworkScan" && SettingsSelect == 3) { //Network Scan To Net3
      NetToConnect = 3;
      if (Net3PassOPEN == 1) {
        screen = "WiFiOPENConnecting";
      } else {
        screen = "WiFiConnect";
      }
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 0;
      clearScreen = 0;
    } else if (screen == "NetworkScan" && SettingsSelect == 4) { //Network Scan To Net4
      NetToConnect = 4;
      if (Net4PassOPEN == 1) {
        screen = "WiFiOPENConnecting";
      } else {
        screen = "WiFiConnect";
      }
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 0;
      clearScreen = 0;
    } else if (screen == "NetworkScan" && SettingsSelect == 5) { //Network Scan To Net5
      NetToConnect = 5;
      if (Net5PassOPEN == 1) {
        screen = "WiFiOPENConnecting";
      } else {
        screen = "WiFiConnect";
      }
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 0;
      clearScreen = 0;
    } else if (screen == "WiFiOPENConnecting" && SettingsSelect == 0) { //Open Connecting Scan To WiFi
      screen = "WiFi";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "WiFiConnect" && SettingsSelect == 0) { //WiFi Connecting To WiFi
      screen = "WiFi";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 4;
      clearScreen = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Saved Networks
    } else if (screen == "SavedNet" && SettingsSelect == 0) { //Saved Networks To WiFi (Back)
      screen = "WiFi";
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "SavedNet" && SettingsSelect == 1 && SavedNet1SSIDString != "") { //Saved Network To Net 1 (SaveNet1)
      screen = "SavedNetEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
      NetToConnect = 1;
    } else if (screen == "SavedNet" && SettingsSelect == 2 && SavedNet2SSIDString != "") { //Savd Network To Net 2 (SaveNet2)
      screen = "SavedNetEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
      NetToConnect = 2;
    } else if (screen == "SavedNet" && SettingsSelect == 3 && SavedNet3SSIDString != "") { //Saved Network To Net 3 (SaveNet3)
      screen = "SavedNetEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
      NetToConnect = 3;
    } else if (screen == "SavedNet" && SettingsSelect == 4 && SavedNet4SSIDString != "") { //Saved Network To Net 4 (SaveNet4)
      screen = "SavedNetEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
      NetToConnect = 4;
    } else if (screen == "SavedNet" && SettingsSelect == 5 && SavedNet5SSIDString != "") { //Saved Network To Net 5 (SaveNet5)
      screen = "SavedNetEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
      NetToConnect = 5;
    } else if (screen == "ConnectedSave" && SettingsSelect == 0) { //Connected Save To MainSettings (NO)
      server.begin();
      Network = "ON";
      screen = "MainSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "ConnectedSave" && SettingsSelect == 1) { //Connected Save To SaveNet (YES)
      server.begin();
      Network = "ON";
      SettingsSelect = 0;
      SettingsCounter = 0;
      screen = "SaveNet";
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "SaveNet" && SettingsSelect == 0) { //Save Network To MainSettings (Back)
      screen = "MainSettings";
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "SaveNet" && SettingsSelect == 1) { //Save Network To MainSettings (SaveNet1)
      SaveNetVoid();
      screen = "Save";
      clearScreen = 0;
    } else if (screen == "SaveNet" && SettingsSelect == 2) { //Save Network To MainSettings (SaveNet2)
      SaveNetVoid();
      screen = "Save";
      clearScreen = 0;
    } else if (screen == "SaveNet" && SettingsSelect == 3) { //Save Network To MainSettings (SaveNet3)
      SaveNetVoid();
      screen = "Save";
      clearScreen = 0;
    } else if (screen == "SaveNet" && SettingsSelect == 4) { //Save Network To MainSettings (SaveNet4)
      SaveNetVoid();
      screen = "Save";
      clearScreen = 0;
    } else if (screen == "SaveNet" && SettingsSelect == 5) { //Save Network To MainSettings (SaveNet5)
      SaveNetVoid();
      screen = "Save";
      clearScreen = 0;
    } else if (screen == "SavedNetEdit" && SettingsSelect == 0) { //Saved Net Edit To Saved Networks (Back)
      screen = "SavedNet";
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "SavedNetEdit" && SettingsSelect == 1) { //Saved Net Edit To Saved WiFi Connecting (Connect)
      screen = "SavedWiFiConnecting";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 0;
      clearScreen = 0;
    } else if (screen == "SavedNetEdit" && SettingsSelect == 2) { //Saved Net Edit To Auto Connect ON/OFF (Auto Connect)
      AutoConnectONOFF = 1;
    } else if (screen == "SavedNetEdit" && SettingsSelect == 3) { //Saved Net Edit To Saved Net (Delete)
      screen = "Deleted";
      DeleteNet();
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "SavedWiFiConnecting" && SettingsSelect == 0) { //Saved WiFi Connecting To Saved Net Edit (Cancel)
      screen = "SavedNetEdit";
      SettingsMaxSelect = 3;
      clearScreen = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament Settings
    } else if (screen == "MainSettings" && SettingsSelect == 5) { //Main Settings To Filament Main Settings
      screen = "FilamentMainSettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "FilamentMainSettings" && SettingsSelect == 0) { //Filament Main Settings To Main Settings (Back)
      screen = "MainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "FilamentMainSettings" && SettingsSelect == 1) { //Filament Main Settings To Materials Edit (Materials)
      screen = "MaterialsEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 11;
      clearScreen = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Materials Edit
    } else if (screen == "MaterialsEdit" && SettingsSelect == 0) { //Materials Edit To Filament Main Settings (Back)
      screen = "FilamentMainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 1) { //Materials Edit To Edit PLA (PLA)
      screen = "EditPLA";
      EditMaterial = "PLA";
      DensitymEdit = PLALW;
      CostkgEdit = PLAFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 2) { //Materials Edit To Edit PETG (PETG)
      screen = "EditPETG";
      EditMaterial = "PETG";
      DensitymEdit = PETGLW;
      CostkgEdit = PETGFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 3) { //Materials Edit To Edit ABS (ABS)
      screen = "EditABS";
      EditMaterial = "ABS";
      DensitymEdit = ABSLW;
      CostkgEdit = ABSFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 4) { //Materials Edit To Edit TPU (TPU)
      screen = "EditTPU";
      EditMaterial = "TPU";
      DensitymEdit = TPULW;
      CostkgEdit = TPUFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 5) { //Materials Edit To Edit Nylon (Nylon)
      screen = "EditNylon";
      EditMaterial = "Nylon";
      DensitymEdit = NylonLW;
      CostkgEdit = NylonFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 6) { //Materials Edit To Edit PVA (PVA)
      screen = "EditPVA";
      EditMaterial = "PVA";
      DensitymEdit = PVALW;
      CostkgEdit = PVAFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 7) { //Materials Edit To Edit HIPS (HIPS)
      screen = "EditHIPS";
      EditMaterial = "HIPS";
      DensitymEdit = HIPSLW;
      CostkgEdit = HIPSFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 8) { //Materials Edit To Edit ASA (ASA)
      screen = "EditASA";
      EditMaterial = "ASA";
      DensitymEdit = ASALW;
      CostkgEdit = ASAFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 9) { //Materials Edit To Edit PC (PC)
      screen = "EditPC";
      EditMaterial = "PC";
      DensitymEdit = PCLW;
      CostkgEdit = PCFC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 10) { //Materials Edit To Edit Custom1 (Custom1)
      screen = "EditCustom1";
      EditMaterial = "Custom1";
      DensitymEdit = Custom1LW;
      CostkgEdit = Custom1FC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "MaterialsEdit" && SettingsSelect == 11) { //Materials Edit To Edit Custom2 (Custom2)
      screen = "EditCustom2";
      EditMaterial = "Custom2";
      DensitymEdit = Custom2LW;
      CostkgEdit = Custom2FC;
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;

    } else if ((screen == "EditPLA" || screen == "EditPETG" || screen == "EditABS" || screen == "EditTPU" || screen == "EditNylon" || screen == "EditPVA" || screen == "EditHIPS" || screen == "EditASA" || screen == "EditPC" || screen == "EditCustom1" || screen == "EditCustom2") && SettingsSelect == 0) { //Edit PLA To Materials Edit (Back)
      screen = "MaterialsEdit";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if ((screen == "EditPLA" || screen == "EditPETG" || screen == "EditABS" || screen == "EditTPU" || screen == "EditNylon" || screen == "EditPVA" || screen == "EditHIPS" || screen == "EditASA" || screen == "EditPC" || screen == "EditCustom1" || screen == "EditCustom2") && SettingsSelect == 1) { //Edit PLA To Density Edit (Density)
      screen = "Density";
      Densitycm3Edit = DensitymEdit / 2.40528;
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 3;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if ((screen == "EditPLA" || screen == "EditPETG" || screen == "EditABS" || screen == "EditTPU" || screen == "EditNylon" || screen == "EditPVA" || screen == "EditHIPS" || screen == "EditASA" || screen == "EditPC" || screen == "EditCustom1" || screen == "EditCustom2") && SettingsSelect == 2) { //Edit PLA To Material Cost Edit (Cost)
      screen = "MaterialCostEdit";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Material Density
    } else if (screen == "Density" && SettingsSelect == 0) { //Density To Edit Material (Back)
      screen = "Edit" + EditMaterial;
      CurrencyChange = 1;
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 2;
      clearScreen = 0;
    } else if (screen == "Density" && SettingsSelect == 1 && Densitycm3 == 0) { //Density g/cm3 ON (g/cm3)
      Densitycm3 = 1;
    } else if (screen == "Density" && SettingsSelect == 1 && Densitycm3 == 1) { //Density g/cm3 OFF (g/cm3)
      Densitycm3 = 0;
    } else if (screen == "Density" && SettingsSelect == 2 && Densitym == 0) { //Density g/m ON (g/m)
      Densitym = 1;
    } else if (screen == "Density" && SettingsSelect == 2 && Densitym == 1) { //Density g/m OFF (g/m)
      Densitym = 0;
    } else if (screen == "Density" && SettingsSelect == 3) { //Density To Save (Save)
      MaterialSaveVoid();
      screen = "MaterialSave";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 2;
      clearScreen = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Material Cost Edit
     } else if (screen == "MaterialCostEdit" && SettingsSelect == 0) { //Material Cost Edit To Edit Material (Back)
      screen = "Edit" + EditMaterial;
      CurrencyChange = 1;
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 2;
      clearScreen = 0;
    } else if (screen == "MaterialCostEdit" && SettingsSelect == 1 && Costkg == 0) { //MaterialCostEdit Currency/kg ON (Currency/kg)
      Costkg = 1;
    } else if (screen == "MaterialCostEdit" && SettingsSelect == 1 && Costkg == 1) { //MaterialCostEdit Currency/cm3 OFF (Currency/kg)
      Costkg = 0;
    } else if (screen == "MaterialCostEdit" && SettingsSelect == 2) { //Material Cost Edit To Save (Save)
      MaterialSaveVoid();
      screen = "MaterialSave";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 2;
      clearScreen = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Filament Spools Edit
    } else if (screen == "FilamentMainSettings" && SettingsSelect == 2) { //Filament Main Settings To Filament Spool Select (Spool Edit)
      screen = "FilSpoolSelectSettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "FilSpoolSelectSettings" && SettingsSelect == 0) { //Spool Edit (Select) To Filament Main Settings (Back)
      screen = "FilamentMainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "FilSpoolSelectSettings" && SettingsSelect == 1) { //Spool Edit Screen (1. Spool)
      screen = "SpoolEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      SpoolEditSelect = 1;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilSpoolSelectSettings" && SettingsSelect == 2) { //Spool Edit Screen (2. Spool)
      screen = "SpoolEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      SpoolEditSelect = 2;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilSpoolSelectSettings" && SettingsSelect == 3) { //Spool Edit Screen (3. Spool)
      screen = "SpoolEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      SpoolEditSelect = 3;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilSpoolSelectSettings" && SettingsSelect == 4) { //Spool Edit Screen (4. Spool)
      screen = "SpoolEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      SpoolEditSelect = 4;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "FilSpoolSelectSettings" && SettingsSelect == 5) { //Spool Edit Screen (5. Spool)
      screen = "SpoolEdit";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      SpoolEditSelect = 5;
      clearScreen = 0;
      CurrencyChange = 1;
    } else if (screen == "SpoolEdit" && SettingsSelect == 0) { //Spool Edit Screen To Spool Select (Back)
      screen = "FilSpoolSelectSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 5;
      clearScreen = 0;
    } else if (screen == "SpoolEdit" && SettingsSelect == 1 && SpoolMatEdit == 0) { //Spool Material Edit ON (Mat)
      SpoolMatEdit = 1;
    } else if (screen == "SpoolEdit" && SettingsSelect == 1 && SpoolMatEdit == 1) { //Spool Material Edit OFF (Mat)
      SpoolMatEdit = 0;
    } else if (screen == "SpoolEdit" && SettingsSelect == 2 && SpoolWeightEdit == 0) { //Spool Weight Edit ON (Weight)
      SpoolWeightEdit = 1;
    } else if (screen == "SpoolEdit" && SettingsSelect == 2 && SpoolWeightEdit == 1) { //Spool Weight Edit OFF (Weight)
      SpoolWeightEdit = 0;
    } else if (screen == "SpoolEdit" && SettingsSelect == 3) { //Spool Edit Screen To Reset Spool (Reset Spool)
      screen = "ResetSpool";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 5;
      clearScreen = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament Runout
    } else if (screen == "FilamentMainSettings" && SettingsSelect == 3) { //Filament Main Settings To Filament Runout Sensor (Fil. Runout)
      screen = "FilRunout";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
    } else if (screen == "FilRunout" && SettingsSelect == 0) { //Filament Runout Sensor To Filament Main Settings (Back)
      screen = "FilamentMainSettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "FilRunout" && SettingsSelect == 1) { //Filament Runout Sensor To Filament Main Settings (ON)
      screen = "FilSensorSave";
      FilRunoutSensor = 1;
      clearScreen = 0;
    } else if (screen == "FilRunout" && SettingsSelect == 2) { //Filament Runout Sensor To Filament Main Settings (OFF)
      screen = "FilSensorSave";
      FilRunoutSensor = 0;
      NoFilament = 0;
      NoFil = 0;
      BuzzerState = 0;
      ledcWriteTone(3, 0);
      clearScreen = 0;
    } else if (screen == "NoFilament") { //No Filament Screen Close
      screen = "HomeScreen";
      clearScreen = 0;
      ledcWriteTone(3, 0);
      CurrencyChange = 1;
    } else if (screen == "FilamentLoaded") { //Filament Loaded Screen Close
      screen = "HomeScreen";
      ledcWriteTone(3, 0);
      clearScreen = 0;
      CurrencyChange = 1;
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament Jams
    else if (screen == "FilamentMainSettings" && SettingsSelect == 4) { //Filament Main Settings To Filament Jams Sensor (Fil. Jams)
      screen = "FilJams";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
    } else if (screen == "FilJams" && SettingsSelect == 0) { //Filament Jams Sensor To Filament Main Settings (Back)
      screen = "FilamentMainSettings";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "FilJams" && SettingsSelect == 1) { //Filament Jams Sensor To Filament Main Settings (ON)
      screen = "FilSensorSave";
      FilJamsSensor = 1;
      clearScreen = 0;
    } else if (screen == "FilJams" && SettingsSelect == 2) { //Filament Jams Sensor To Filament Main Settings (OFF)
      screen = "FilSensorSave";
      FilJamsSensor = 0;
      FilJammed = 0;
      clearScreen = 0;
    } else if (screen == "FilJamDetected") { //Filament Jam Detected Screen Close
      screen = "HomeScreen";
      ledcWriteTone(3, 0);
      clearScreen = 0;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Auto OFF
    else if (screen == "MainSettings" && SettingsSelect == 6) { //Main Settings To Automatic Off (Auto Off)
      screen = "AutoOff";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
    } else if (screen == "AutoOff" && SettingsSelect == 0) { //Auto Off To Main Settings (Back)
      screen = "MainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "AutoOff" && SettingsSelect == 1) { //Auto Off To Main Settings (ON)
      screen = "AutoOffSave";
      AutoOff = 1;
      preferences.putBool("AutoOff", 1);
      preferences.putInt("AutoOffTime", AutoOffMillis);
      clearScreen = 0;
    } else if (screen == "AutoOff" && SettingsSelect == 2) { //Auto Off To Main Settings (OFF)
      screen = "AutoOffSave";
      AutoOff = 0;
      preferences.putBool("AutoOff", 0);
      clearScreen = 0;
    } else if (screen == "AutoOff" && SettingsSelect == 3 && AutoOffTimeEdit == 0) { //Auto Off Time Edit ON (Start After)
      AutoOffTimeEdit = 1;
    } else if (screen == "AutoOff" && SettingsSelect == 3 && AutoOffTimeEdit == 1) { //Auto Off Time Edit OFF (Start After)
      AutoOffTimeEdit = 0;
    } else if (screen == "AutoOffScreen") { //Auto Off Screen Close
      screen = "HomeScreen";
      ledcWriteTone(3, 0);
      clearScreen = 0;
      CurrencyChange = 1;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Screen brightness settings
    else if (screen == "MainSettings" && SettingsSelect == 7) { //Main Settings To Brightness (Brightness)
      screen = "Brightness";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 2;
      clearScreen = 0;
    } else if (screen == "Brightness" && SettingsSelect == 0) { //Brightness To Main Settings (Back)
      screen = "MainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "Brightness" && SettingsSelect == 1 && BrightnessEdit == 0) { //Brightness Edit ON (Brightness)
      BrightnessEdit = 1;
    } else if (screen == "Brightness" && SettingsSelect == 1 && BrightnessEdit == 1) { //Brightness Edit OFF (Brightness)
      BrightnessEdit = 0;
    } else if (screen == "Brightness" && SettingsSelect == 2) { //Brightness To Main Settings (Save)
      screen = "Save";
      preferences.putInt("ScreenB", BrightnessPercentage);
      clearScreen = 0;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Sound Settings
    else if (screen == "MainSettings" && SettingsSelect == 8) { //Main Settings To Sound (Sound)
      screen = "Sound";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 3;
      clearScreen = 0;
    } else if (screen == "Sound" && SettingsSelect == 0) { //Sound To Main Settings (Back)
      screen = "MainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "Sound" && SettingsSelect == 1 && OnClickSound == 0) { //On Click Sound ON (On Click)
      OnClickSound = 1;
      preferences.putBool("SoundClick", 1);
    } else if (screen == "Sound" && SettingsSelect == 1 && OnClickSound == 1) { //On Click Sound OFF (On Click)
      OnClickSound = 0;
      preferences.putBool("SoundClick", 0);
    } else if (screen == "Sound" && SettingsSelect == 2 && AlertsSound == 0) { //Alerts Sound ON (Alerts)
      AlertsSound = 1;
      preferences.putBool("SoundAlerts", 1);
    } else if (screen == "Sound" && SettingsSelect == 2 && AlertsSound == 1) { //Alerts Sound OFF (Alerts)
      AlertsSound = 0;
      preferences.putBool("SoundAlerts", 0);
    } else if (screen == "Sound" && SettingsSelect == 3 && PrintingSound == 0) { //Printing Sound ON (Printing)
      PrintingSound = 1;
      preferences.putBool("SoundPrint", 1);
    } else if (screen == "Sound" && SettingsSelect == 3 && PrintingSound == 1) { //Printing Sound OFF (Printing)
      PrintingSound = 0;
      preferences.putBool("SoundPrint", 0);
    } 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Auto Scroll
    else if (screen == "MainSettings" && SettingsSelect == 9) { //Main Settings To Auto Scroll (Auto Scroll)
      screen = "AutoScroll";
      SettingsSelect = 1;
      SettingsCounter = 1;
      SettingsMaxSelect = 4;
      clearScreen = 0;
    } else if (screen == "AutoScroll" && SettingsSelect == 0) { //Auto Scroll To Main Settings (Back)
      screen = "MainSettings";
      SettingsSelect = 0;
      SettingsCounter = 0;
      SettingsMaxSelect = 11;
      clearScreen = 0;
    } else if (screen == "AutoScroll" && SettingsSelect == 1) { //Auto Scroll OFF (OFF)
      AutoScrollMode = 0;
      preferences.putInt("AutoScroll", 0);
      screen = "Save";
      clearScreen = 0;
    } else if (screen == "AutoScroll" && SettingsSelect == 2) { //3 Screens Auto Scroll ON (3 Screens)
      AutoScrollMode = 1;
      preferences.putInt("AutoScroll", 1);
      preferences.putInt("AScrollMillis", AutoScrollMillis);
      screen = "Save";
      clearScreen = 0;
      AutoScrollScreenCounter = -1;
    } else if (screen == "AutoScroll" && SettingsSelect == 3) { //All Screens Auto Scroll OFF (All Screens)
      AutoScrollMode = 2;
      preferences.putInt("AutoScroll", 2);
      preferences.putInt("AScrollMillis", AutoScrollMillis);
      screen = "Save";
      clearScreen = 0;
      AutoScrollScreenCounter = -1;
    } else if (screen == "AutoScroll" && SettingsSelect == 4 && AutoScrollEdit == 0) { //Auto Scroll Time Edit ON (Start Time)
      AutoScrollEdit = 1;
    } else if (screen == "AutoScroll" && SettingsSelect == 4 && AutoScrollEdit == 1) { //Auto Scroll Time Edit OFF (Start Time)
      AutoScrollEdit = 0;
    } 
}

}
