/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Rotary Encoder Update

void updateEncoder() {

  unsigned char result = rotary.process();

  if (result == DIR_CW || result == DIR_CCW) {
    
  NoTouchMillis = millis();

  if (NoFilament == 1 && millis() - BuzzerNoFilTimeoutMillis < 10000) {
    BuzzerNoFilTimeoutMillis = millis() - 10000;
  } else if (FilJammed == 1 && millis() - BuzzerFilJamTimeoutMillis < 10000) {
    BuzzerFilJamTimeoutMillis = millis() - 10000;
  } else if (AutoOffStart == 1 && millis() - BuzzerAutoOffTimeoutMillis < 10000) {
    BuzzerAutoOffTimeoutMillis = millis() - 10000;
  }
  if (FilJammed == 1) {
    FilJammed = 0;
    screen = PrevScreen;
    ledcWriteTone(3, 0);
    RelayState = 1;
    digitalWrite(RelayPin, HIGH);
  }
  if (AutoOffStart == 1) {
    AutoOffStart = 0;
    ledcWriteTone(3, 0);
    RelayState = 1;
    digitalWrite(RelayPin, HIGH);
    screen = "HomeScreen";
    clearScreen = 0;
    CurrencyChange = 1;
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

  }

  if ((screen == "HomeScreen" || screen == "Energy" || screen == "Energy2" || screen == "Filament" || screen == "Filament2") && ScreenXScroll == 0) {
    if (result == DIR_CW) {
      if (ScreenCounter < 2){
        if (ScreenCounter == 1 && LastScreen == "Energy"){
          ScreenCounter++;
        } else if (ScreenCounter == 0 && LastScreen == "HomeScreen"){
          ScreenCounter++;
        } else if (ScreenCounter == -1 && LastScreen == "Filament"){
          ScreenCounter++;
        } else if (ScreenCounter == -2 && LastScreen == "Filament2"){
          ScreenCounter++;
        }
        LastScreenCounter = ScreenCounter;
      }
    }
    else if (result == DIR_CCW) {
      if (ScreenCounter > -2){
        if (ScreenCounter == 2 && LastScreen == "Energy2"){
          ScreenCounter--;
        } else if (ScreenCounter == 1 && LastScreen == "Energy"){
          ScreenCounter--;
        } else if (ScreenCounter == 0 && LastScreen == "HomeScreen"){
          ScreenCounter--;
        } else if (ScreenCounter == -1 && LastScreen == "Filament"){
          ScreenCounter--;
        }
        LastScreenCounter = ScreenCounter;
      }
    }


    if (ScreenCounter == -2 && screen == "Filament") {
      screen = "Filament2";
      clearScreen = 0;
      ScreenXScroll = 0;
    } else if (ScreenCounter == -1 && (screen == "Filament2" || screen == "HomeScreen")) {
      screen = "Filament";
      CurrencyChange = 1;
      clearScreen = 0;
      ScreenXScroll = 0;
    } else if (ScreenCounter == 0 && (screen == "Energy" || screen == "Filament")) {
      screen = "HomeScreen";
      CurrencyChange = 1;
      clearScreen = 0;
      ScreenXScroll = 0;
    } else if (ScreenCounter == 1 && (screen == "Energy2" || screen == "HomeScreen")) {
      screen = "Energy";
      CurrencyChange = 1;
      clearScreen = 0;
      ScreenXScroll = 0;
    } else if (ScreenCounter == 2 && screen == "Energy") {
      screen = "Energy2";
      clearScreen = 0;
      ScreenXScroll = 0;
    } else {
      ScreenCounter = LastScreenCounter;
    }
    
    
  } else if (CostEdit == 0 && Densitycm3 == 0 && Densitym == 0 && Costkg == 0 && SpoolMatEdit == 0 && SpoolWeightEdit == 0 && AutoOffTimeEdit == 0  && BrightnessEdit == 0 && AutoScrollEdit == 0 && LEDBrightnessEdit == 0) {        //Normal Mode
    if (result == DIR_CW) {
      SettingsCounter++;
      if (SettingsCounter > SettingsMaxSelect) {
        SettingsCounter = SettingsMaxSelect;
      }
      if (SettingsCounter == 6) {
        clearScreen = 0;
      }
    }
    else if (result == DIR_CCW) {
      SettingsCounter--;
      if (SettingsCounter < 0) {
        SettingsCounter = 0;
      }
      if (SettingsCounter == 5) {
        clearScreen = 0;
      }
    }
    SettingsSelect = SettingsCounter;
  }
  else if (CostEdit == 1) {                 //Cost Edit
    if (result == DIR_CW) {
      CostChange = CostChange + 1;
    }
    else if (result == DIR_CCW) {
      CostChange = CostChange - 1;
    }
  }

  else if (Densitycm3 == 1) {                  //Density g/cm3 Edit
    if (result == DIR_CW) {
      Densitycm3Change = Densitycm3Change + 1;
    }
    else if (result == DIR_CCW) {
      Densitycm3Change = Densitycm3Change - 1;
    }
  }

  else if (Densitym == 1) {                  //Density g/m Edit
    if (result == DIR_CW) {
      DensitymChange = DensitymChange + 1;
    }
    else if (result == DIR_CCW) {
      DensitymChange = DensitymChange - 1;
    }
  }

  else if (Costkg == 1) {                  //Cost kg Currency/kg Edit
    if (result == DIR_CW) {
      CostkgChange = CostkgChange + 1;
    }
    else if (result == DIR_CCW) {
      CostkgChange = CostkgChange - 1;
    }
  }

  else if (SpoolMatEdit == 1) {                  //Spool Material Edit
    if (result == DIR_CW) {
      SpoolMatEditChange = SpoolMatEditChange + 1;
    }
    else if (result == DIR_CCW) {
      SpoolMatEditChange = SpoolMatEditChange - 1;
    }
  }

  else if (SpoolWeightEdit == 1) {                  //Spool Weight Edit
    if (result == DIR_CW) {
      SpoolWeightEditChange = SpoolWeightEditChange + 1;
    }
    else if (result == DIR_CCW) {
      SpoolWeightEditChange = SpoolWeightEditChange - 1;
    }
  }

  else if (AutoOffTimeEdit == 1) {                  //Auto Off Time Edit
    if (result == DIR_CW) {
      AutoOffTimeEditChange = AutoOffTimeEditChange + 1;
    }
    else if (result == DIR_CCW) {
      AutoOffTimeEditChange = AutoOffTimeEditChange - 1;
    }
  }

  else if (BrightnessEdit == 1) {                  //Brightness Edit
    if (result == DIR_CW) {
      BrightnessEditChange = BrightnessEditChange + 1;
    }
    else if (result == DIR_CCW) {
      BrightnessEditChange = BrightnessEditChange - 1;
    }
  }

  else if (AutoScrollEdit == 1) {                  //Auto Scroll Edit
    if (result == DIR_CW) {
      AutoScrollEditChange = AutoScrollEditChange + 1;
    }
    else if (result == DIR_CCW) {
      AutoScrollEditChange = AutoScrollEditChange - 1;
    }
  }

  else if (LEDBrightnessEdit == 1) {                  //LED Brightness Edit
    if (result == DIR_CW) {
      LEDBrightnessEditChange = LEDBrightnessEditChange + 1;
    }
    else if (result == DIR_CCW) {
      LEDBrightnessEditChange = LEDBrightnessEditChange - 1;
    }
  }
  }
}






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Button
void BUTTON() {
  if (millis() - ButtonMillis >= 200) {
    ButtonMillis = millis();
    NoTouchMillis = ButtonMillis;

    UpdateButton = 1;
  }
}
