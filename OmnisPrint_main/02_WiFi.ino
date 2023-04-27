///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                         WiFi Firebase
//*****************************************************************************************************************************

void Task1code( void * pvParameters ) {
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());

  String Value2 = "";
  String Value3 = "";
  int Screen2Counter = 0;

  for (;;) {
    vTaskDelay(500);

    WiFi.setSleep(false);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Screen 1  */

      Value2 = String(U) + "_" + String(I) + "_" + String(P) + "_" + String(AvgP) + "_" + String(MaxP) + "_" + String(C) + "_" + String(E) + "_" + String(EC) + "_" + String(FC) + "_" + String(FL) + "_" + String(FW * 1000) + "_";

      Value2 = Value2 + String(day() - 1) + "_" + String(hour()) + "_" + String(minute()) + "_" + String(second()) + "_";

      Value2 = Value2 + String(PrintHour) + "_" + String(PrintMin) + "_" + String(int(PrintSec)) + "_";

      if (screen == "SpoolSelectSettings"){
        Value2 = Value2 + "6" + "_";
      } else{
        Value2 = Value2 + String(CurrentSpool) + "_";
      }

      if (CurrentSpool == 0 || CurrentSpool == 6){
        Value2 = Value2 + "0_0.00_";
        Value2 = Value2 + "0_0.00_";
        Value2 = Value2 + "0_";
      } else {
        Value2 = Value2 + String(CurSpoolFW, 0) + "_" + String(CurSpoolWeight) + "_";
        Value2 = Value2 + String(CurSpoolFL, 0) + "_" + String(CurSpoolLenght) + "_";
        Value2 = Value2 + String(CurSpoolPercentage) + "_";
      }

      if (RelayState == 1){
          Value2 = Value2 + String(PrintingON) + "_";
        } else {
          Value2 = Value2 + "2" + "_";
        }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Screen 2  */
      if (RelayState == 1){
          Value3 = Value3 + String(PrintingON) + "_";
        } else {
          Value3 = Value3 + "2" + "_";
        }

        Value3 = Value3 + String(RelayState) + "_" + String(LED) + "_" + String(FilRunoutSensor) + "_" + String(FilJamsSensor) + "_" + String(CurrentSpool) + "_" + String(AutoOff) + "_" + String(AutoOffMillis) + "_" + String(LEDMode) + "_" + String(LEDBrightnessPercentage) + "_" + String(LEDSparkle) + "_";

        Screen2Counter = Screen2Counter + 1;
        if (Screen2Counter == 2){
          Screen2Counter = 0;
        }
        Value3 = Value3 + Screen2Counter + "_";


    Firebase.setString(firebaseData, "/APP/SCREEN1", Value2);
    Firebase.setString(firebaseData, "/APP/SCREEN2", Value3);
    Firebase.setString(firebaseData, "/APP/MAT", Material);
    Firebase.setString(firebaseData, "/APP/CURSPOOLMAT", CurSpoolMatText);

    Value2 = "";
    Value3 = "";

    if (Firebase.getString(firebaseData, "/APP/REC")) {
      String RECString = firebaseData.stringData();
      RECString.remove(0, 2);
      RECString.remove(RECString.length() - 2, 2);
      int REC = RECString.toInt();

      if (REC == 0){

    if (Firebase.getString(firebaseData, "/APP/Relay")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/Relay");
      if (recieve == "1"){
        digitalWrite(RelayPin, HIGH);
      } else if (recieve == "0"){
        digitalWrite(RelayPin, LOW);
      }
      RelayState = recieve.toInt();
    }
      } else if (REC == 1){

    if (Firebase.getString(firebaseData, "/APP/LED")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/LED");
      LED = recieve.toInt();
    }
      } else if (REC == 2){

    if (Firebase.getString(firebaseData, "/APP/mat")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(recieve.length() - 2, 2);
      Firebase.deleteNode(firebaseData,  "/APP/mat");
      Material = recieve;
    }
      } else if (REC == 3){

    if (Firebase.getString(firebaseData, "/APP/SPOOL")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/SPOOL");
      CurrentSpool = recieve.toInt();
    }
    } else if (REC == 4){

    if (Firebase.getString(firebaseData, "/APP/RUNOUT")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/RUNOUT");
      if (recieve == "0"){
        FilRunoutSensor = 0;
        NoFilament = 0;
        NoFil = 0;
        BuzzerState = 0;
        ledcWriteTone(3, 0);
        digitalWrite(RelayPin, HIGH);
        RelayState = 1;
      } else if (recieve == "1"){
        FilRunoutSensor = 1;
      }
    }
    } else if (REC == 5){

    if (Firebase.getString(firebaseData, "/APP/JAMS")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/JAMS");
      if (recieve == "0"){
        FilJamsSensor = 0;
        FilJammed = 0;
        digitalWrite(RelayPin, HIGH);
        RelayState = 1;
      } else if (recieve == "1"){
        FilJamsSensor = 1;
      }
    }
    } else if (REC == 6){

    if (Firebase.getString(firebaseData, "/APP/AUTOOFF")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/AUTOOFF");
      if (recieve == "0"){
        AutoOff = 0;
        digitalWrite(RelayPin, HIGH);
        RelayState = 1;
      } else if (recieve == "1"){
        AutoOff = 1;
      }
    }
    } else if (REC == 7){

    if (Firebase.getString(firebaseData, "/APP/AUTOOFFTIME")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(recieve.length() - 2, 2);
      Firebase.deleteNode(firebaseData,  "/APP/AUTOOFFTIME");
      AutoOffMillis = recieve.toInt();
    }
    } else if (REC == 8){

      if (Firebase.getString(firebaseData, "/APP/LEDMODE")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData,  "/APP/LEDMODE");
      LEDMode = recieve.toInt();
      }
    } else if (REC == 9){

      if (Firebase.getString(firebaseData, "/APP/SPARKLE")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(1, 2);
      Firebase.deleteNode(firebaseData, "/APP/SPARKLE");
      LEDSparkle = recieve.toInt();
    }
    } else if (REC == 10){
      
      if (Firebase.getString(firebaseData, "/APP/LEDBRIGHTNESS")) {
      String recieve = firebaseData.stringData();
      recieve.remove(0, 2);
      recieve.remove(recieve.length() - 2, 2);
      Firebase.deleteNode(firebaseData, "/APP/LEDBRIGHTNESS");
      LEDBrightnessPercentage = recieve.toInt();
      FastLED.setBrightness(map(LEDBrightnessPercentage, 0, 100, 0, 255));
    }
    }

    Firebase.deleteNode(firebaseData,  "/APP/REC");
  }

     }
   }
