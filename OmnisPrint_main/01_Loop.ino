/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Loop

void loop() {
  unsigned long cMillis = millis();

  if (SkipToScroll == 0){  //skip directly to screen scrolling

//  Calculate voltage & current
  readVoltage();
  readCurrent();
  U = getVoltageAverage();
  I = getCurrentaverage();

  if (I < 0.01) {  //ignore small current
    I = 0.00;
  }

//  Calculate power, maxP, avgP, and energy
  P = round(U * I);

  if (P > MaxP) {
    MaxP = P;
  }

  AvgP = E / (cMillis * (1 / 3.6e9));

  if (cMillis - EnergyMillis >= 400) {  //Energy
    interval = cMillis - EnergyMillis;
    E = E + (P * (interval * (1 / 3.6e9)));
    EnergyMillis = cMillis;
  }

  EC = E * ec;  //energy cost

  C = EC + FC;  //total cost

  PowerLED();

  PrintingTimeVoid();

  MaterialVoid();

  if (FilRunoutSensor == 1) {
    FilamentRunoutSensor();
  }
  if (FilJamsSensor == 1) {
    FilamentJamsSensor();
  }
  if (AutoOffStart == 1) {
    AutoOffVoid();
  }

  PrintingVoid();

  if (AutoScrollMode > 0){
    AutoScrollVoid();
  }

  if (cMillis - SpoolPercentageMillis >= 1000) {
    SpoolPercentage();
    SpoolPercentageMillis = cMillis;
  }

  if (AutomaticConnecting < 3) {
    AutoConnect();
  }

  if (OnClickSound == 1 && UpdateButton == 1){
      ledcWriteTone(3, 1976);
      OnClickSoundON = 1;
      OnClickSoundMillis = cMillis;
    }

  if (cMillis - OnClickSoundMillis >= 40 && OnClickSoundON == 1){
    ledcWriteTone(3, 0);
    OnClickSoundON = 0;
  }


  if (FILChange > 0) { //////////////////////////////////////////////////////////////*  Rotary encoder updates  */
    FL = FL + 0.002;
    FilPrintingMillis = cMillis;
    FW = FW + (currentMATLW * 0.000002);
    FC = FC + ((currentMATLW * 0.002) * (currentMATFC / 1000));

    if (Material == "PLA"){
      PLAFL = PLAFL + 0.002;
    } else if (Material == "PETG"){
      PETGFL = PETGFL + 0.002;
    } else if (Material == "ABS"){
      ABSFL = ABSFL + 0.002;
    } else if (Material == "TPU"){
      TPUFL = TPUFL + 0.002;
    } else if (Material == "Nylon"){
      NylonFL = NylonFL + 0.002;
    } else if (Material == "PVA"){
      PVAFL = PVAFL + 0.002;
    } else if (Material == "HIPS"){
      HIPSFL = HIPSFL + 0.002;
    } else if (Material == "ASA"){
      ASAFL = ASAFL + 0.002;
    } else if (Material == "PC"){
      PCFL = PCFL + 0.002;
    } else if (Material == "Custom1"){
      Custom1FL = Custom1FL + 0.002;
    } else if (Material == "Custom2"){
      Custom2FL = Custom2FL + 0.002;
    }

    if (CurrentSpool == 1) {
      Spool1FW = Spool1FW - (currentMATLW * 0.002);
      if (Spool1FW < 0) {
        Spool1FW = 0;
      }
      Spool1Percentage = round((Spool1FW / Spool1Weight) * 100);
    } else if (CurrentSpool == 2) {
      Spool2FW = Spool2FW - (currentMATLW * 0.002);
      if (Spool2FW < 0) {
        Spool2FW = 0;
      }
      Spool2Percentage = round((Spool2FW / Spool2Weight) * 100);
    } else if (CurrentSpool == 3) {
      Spool3FW = Spool3FW - (currentMATLW * 0.002);
      if (Spool3FW < 0) {
        Spool3FW = 0;
      }
      Spool3Percentage = round((Spool3FW / Spool3Weight) * 100);
    } else if (CurrentSpool == 4) {
      Spool4FW = Spool4FW - (currentMATLW * 0.002);
      if (Spool4FW < 0) {
        Spool4FW = 0;
      }
      Spool4Percentage = round((Spool4FW / Spool4Weight) * 100);
    } else if (CurrentSpool == 5) {
      Spool5FW = Spool5FW - (currentMATLW * 0.002);
      if (Spool5FW < 0) {
        Spool5FW = 0;
      }
      Spool5Percentage = round((Spool5FW / Spool5Weight) * 100);
    }
    FILChange = FILChange - 1;


  } else if (FILChange < 0) {
    FL = FL - 0.002;
    FW = FW - (currentMATLW * 0.000002);
    FC = FC - ((currentMATLW * 0.002) * (currentMATFC / 1000));

    if (Material == "PLA"){
      PLAFL = PLAFL - 0.002;
    } else if (Material == "PETG"){
      PETGFL = PETGFL - 0.002;
    } else if (Material == "ABS"){
      ABSFL = ABSFL - 0.002;
    } else if (Material == "TPU"){
      TPUFL = TPUFL - 0.002;
    } else if (Material == "Nylon"){
      NylonFL = NylonFL - 0.002;
    } else if (Material == "PVA"){
      PVAFL = PVAFL - 0.002;
    } else if (Material == "HIPS"){
      HIPSFL = HIPSFL - 0.002;
    } else if (Material == "ASA"){
      ASAFL = ASAFL - 0.002;
    } else if (Material == "PC"){
      PCFL = PCFL - 0.002;
    } else if (Material == "Custom1"){
      Custom1FL = Custom1FL - 0.002;
    } else if (Material == "Custom2"){
      Custom2FL = Custom2FL - 0.002;
    }

    if (CurrentSpool == 1) {
      Spool1FW = Spool1FW + (currentMATLW * 0.002);
    } else if (CurrentSpool == 2) {
      Spool2FW = Spool2FW + (currentMATLW * 0.002);
    } else if (CurrentSpool == 3) {
      Spool3FW = Spool3FW + (currentMATLW * 0.002);
    } else if (CurrentSpool == 4) {
      Spool4FW = Spool4FW + (currentMATLW * 0.002);
    } else if (CurrentSpool == 5) {
      Spool5FW = Spool5FW + (currentMATLW * 0.002);
    }
    FILChange = FILChange + 1;
  }

  if (CostChange > 0) {
    ecEdit = ecEdit + 0.01;
    if (ecEdit > 1.00) {
      ecEdit = 1.00;
    }
    CostChange = CostChange - 1;
  } else if (CostChange < 0) {
    ecEdit = ecEdit - 0.01;
    if (ecEdit < 0) {
      ecEdit = 0;
    }
    CostChange = CostChange + 1;
  }

  if (Densitycm3Change > 0) {
    Densitycm3Edit = Densitycm3Edit + 0.01;
    if (Densitycm3Edit > 8.00) {
      Densitycm3Edit = 8.00;
    }
    DensitymEdit = Densitycm3Edit * 2.40528;
    Densitycm3Change = Densitycm3Change - 1;
  } else if (Densitycm3Change < 0) {
    Densitycm3Edit = Densitycm3Edit - 0.01;
    if (Densitycm3Edit < 0) {
      Densitycm3Edit = 0;
    }
    DensitymEdit = Densitycm3Edit * 2.40528;
    Densitycm3Change = Densitycm3Change + 1;
  }

  if (DensitymChange > 0) {
    DensitymEdit = DensitymEdit + 0.01;
    if (DensitymEdit > 8.00) {
      DensitymEdit = 8.00;
    }
    Densitycm3Edit = DensitymEdit / 2.40528;
    DensitymChange = DensitymChange - 1;
  } else if (DensitymChange < 0) {
    DensitymEdit = DensitymEdit - 0.01;
    if (DensitymEdit < 0) {
      DensitymEdit = 0;
    }
    Densitycm3Edit = DensitymEdit / 2.40528;
    DensitymChange = DensitymChange + 1;
  }

  if (CostkgChange > 0) {
    CostkgEdit = CostkgEdit + 0.05;
    if (CostkgEdit > 64.00) {
      CostkgEdit = 64.00;
    }
    CostkgChange = CostkgChange - 1;
  } else if (CostkgChange < 0) {
    CostkgEdit = CostkgEdit - 0.05;
    if (CostkgEdit < 0) {
      CostkgEdit = 0;
    }
    CostkgChange = CostkgChange + 1;
  }

  if (SpoolMatEditChange > 0) {
    SpoolMaterial[SpoolEditSelect - 1] = SpoolMaterial[SpoolEditSelect - 1] + 1;
    if (SpoolMaterial[SpoolEditSelect - 1] > 11) {
      SpoolMaterial[SpoolEditSelect - 1] = 11;
    }
    SpoolMatEditChange = SpoolMatEditChange - 1;
  } else if (SpoolMatEditChange < 0) {
    SpoolMaterial[SpoolEditSelect - 1] = SpoolMaterial[SpoolEditSelect - 1] - 1;
    if (SpoolMaterial[SpoolEditSelect - 1] < 1) {
      SpoolMaterial[SpoolEditSelect - 1] = 1;
    }
    SpoolMatEditChange = SpoolMatEditChange + 1;
  }

  if (SpoolWeightEditChange > 0) {
    if (SpoolEditSelect == 1 && Spool1Weight < 9950) {
      Spool1Weight = Spool1Weight + 50;
      Spool1FW = Spool1Weight;
    } else if (SpoolEditSelect == 2 && Spool2Weight < 9950) {
      Spool2Weight = Spool2Weight + 50;
      Spool2FW = Spool2Weight;
    } else if (SpoolEditSelect == 3 && Spool3Weight < 9950) {
      Spool3Weight = Spool3Weight + 50;
      Spool3FW = Spool3Weight;
    } else if (SpoolEditSelect == 4 && Spool4Weight < 9950) {
      Spool4Weight = Spool4Weight + 50;
      Spool4FW = Spool4Weight;
    } else if (SpoolEditSelect == 5 && Spool5Weight < 9950) {
      Spool5Weight = Spool5Weight + 50;
      Spool5FW = Spool5Weight;
    }
    SpoolWeightEditChange = SpoolWeightEditChange - 1;
  } else if (SpoolWeightEditChange < 0) {
    if (SpoolEditSelect == 1 && Spool1Weight > 50) {
      Spool1Weight = Spool1Weight - 50;
      Spool1FW = Spool1Weight;
    } else if (SpoolEditSelect == 2 && Spool2Weight > 50) {
      Spool2Weight = Spool2Weight - 50;
      Spool2FW = Spool2Weight;
    } else if (SpoolEditSelect == 3 && Spool3Weight > 50) {
      Spool3Weight = Spool3Weight - 50;
      Spool3FW = Spool3Weight;
    } else if (SpoolEditSelect == 4 && Spool4Weight > 50) {
      Spool4Weight = Spool4Weight - 50;
      Spool4FW = Spool4Weight;
    } else if (SpoolEditSelect == 5 && Spool5Weight > 50) {
      Spool5Weight = Spool5Weight - 50;
      Spool5FW = Spool5Weight;
    }
    SpoolWeightEditChange = SpoolWeightEditChange + 1;
  }

  if (AutoOffTimeEditChange > 0) {
    AutoOffMillis = AutoOffMillis + 1800000;
    if (AutoOffMillis > 86400000) {
      AutoOffMillis = 86400000;
    }
    AutoOffTimeEditChange = AutoOffTimeEditChange - 1;
  } else if (AutoOffTimeEditChange < 0) {
    AutoOffMillis = AutoOffMillis - 1800000;
    if (AutoOffMillis < 0 || AutoOffMillis > 86400000) {
      AutoOffMillis = 0;
    }
    AutoOffTimeEditChange = AutoOffTimeEditChange + 1;
  }

  if (BrightnessEditChange > 0) {
    BrightnessPercentage = BrightnessPercentage + 10;
    if (BrightnessPercentage > 100) {
      BrightnessPercentage = 100;
    }
    BrightnessEditChange = BrightnessEditChange - 1;
  } else if (BrightnessEditChange < 0) {
    BrightnessPercentage = BrightnessPercentage - 10;
    if (BrightnessPercentage < 10) {
      BrightnessPercentage = 10;
    }
    BrightnessEditChange = BrightnessEditChange + 1;
  }

  if (AutoScrollEditChange > 0) {
    if (AutoScrollMillis < 60000){
      AutoScrollMillis = AutoScrollMillis + 15000;
    } else {
      AutoScrollMillis = AutoScrollMillis + 60000;
    }
    
    if (AutoScrollMillis > 1800000) {
      AutoScrollMillis = 1800000;
    }
    AutoScrollEditChange = AutoScrollEditChange - 1;
  } else if (AutoScrollEditChange < 0) {
    if (AutoScrollMillis < 60000){
      AutoScrollMillis = AutoScrollMillis - 15000;
    } else {
      AutoScrollMillis = AutoScrollMillis - 60000;
    }

    if (AutoScrollMillis < 15000 || AutoScrollMillis > 1800000) {
      AutoScrollMillis = 15000;
    }
    AutoScrollEditChange = AutoScrollEditChange + 1;
  }

  if (LEDBrightnessEditChange > 0) {
    LEDBrightnessPercentage = LEDBrightnessPercentage + 10;
    if (LEDBrightnessPercentage > 100) {
      LEDBrightnessPercentage = 100;
    }
    LEDBrightnessEditChange = LEDBrightnessEditChange - 1;
  } else if (LEDBrightnessEditChange < 0) {
    LEDBrightnessPercentage = LEDBrightnessPercentage - 10;
    if (LEDBrightnessPercentage < 10) {
      LEDBrightnessPercentage = 10;
    }
    LEDBrightnessEditChange = LEDBrightnessEditChange + 1;
  }

  } else {
    SkipToScroll = 0;
  }

  if (screen == "HomeScreen") { ///////////////////////////////////////////////////////////////////////////////////////////////*    Home screen  */
    if (clearScreen < 2 && cMillis - HomeScreenMillis0 >= 5) {
      HomeScreenMillis0 = cMillis;
      if (clearScreen == 0) {

        
        SpriteDefine();
        ScreenXScroll = 160;
        DoubleScreenBarX = 0;
        if (LastScreen != "Energy" && LastScreen != "Energy2" && LastScreen != "Filament" && LastScreen != "Filament2"){
          ScreenBarX = 64;
        } else {
          while (ScreenBarX != 64){
            ScreenScroll();
          }
        }

        
        if(ScreenXScroll == 0){
          SlowPRing = 1;
        } else if (ScreenXScroll != 0 && screen == "HomeScreen"){
          tft.fillRect(0, 0, 160, 128, TFT_BLACK);  // Start from top-left pixel (x,y,wigth,height)
          ScreenXScroll = 0;
        }
       
      } else if (clearScreen == 1) {
        SpritesDelete();
        LastScreen = "HomeScreen";
        tft.fillRect(0, 0, 160, 15, GreyBlue);
        tft.drawLine(0, 15, 159, 15, LightGreen);
        tft.drawLine(64, 127, 96, 127, TFT_WHITE);
        tft.setTextFont(2);
        tft.setTextColor(Purple);
        tft.setCursor(15, 15); // Set position (x,y)
        tft.print("Voltage");
        tft.setCursor(95, 15);
        tft.print("Current");
        tft.setCursor(87, 62);
        tft.print("Total Cost");
      }
      if (screen == "HomeScreen"){
        clearScreen = clearScreen + 1;
      }
    }

    if (clearScreen == 2 && cMillis - HomeScreenMillis1 >= 50) {
      HomeScreenMillis1 = cMillis;

     if (cMillis - HomeScreenTextMillis >= 200){
      HomeScreenTextMillis = cMillis;
      
      tft.setTextFont(4);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setCursor(6, 32); // Set position (x,y)
      if (U < 9.995) {
        tft.print(U);
      } else {
        tft.print(U,1);
      }
      tft.println("V   ");
      tft.setCursor(85, 32);
      if (I < 9.995) {
        tft.print(I);
      } else {
        tft.print(I,1);
      }
      tft.println("A");


      tft.setTextPadding(tft.textWidth("999.9", 4));
        if (C < 10.00) {
          tft.drawFloat(C, 3, 87, 77, 4);
        } else if (C >= 10.00 && E < 100.00){
          tft.drawFloat(C, 2, 87, 77, 4);
        } else if (C >= 100.00 && E < 1000.00){
          tft.drawFloat(C, 1, 87, 77, 4);
        } else if (C >= 1000.00){
          tft.drawNumber(C, 87, 77, 4);
        }
        tft.setTextPadding(0);


        if (Currency == "$"){
          tft.pushImage(110, 101, 11, 16, DollarIcon);
        } else if (Currency == "E"){
          tft.pushImage(110, 101, 11, 16, EuroIcon);
        } else if (Currency == "P"){
          tft.pushImage(110, 101, 11, 16, PoundIcon);
        } else if (Currency == "A$"){
          tft.pushImage(110, 101, 22, 16, ADollarIcon);
        } else if (Currency == "C$"){
          tft.pushImage(110, 101, 22, 16, CDollarIcon);
        }


      tft.setTextFont(1);
      tft.setTextColor(LightGreen, GreyBlue);
      if (AutomaticConnecting == 0 || AutomaticConnecting == 3 && NoFilament == 0) {
        tft.setTextDatum(TR_DATUM);
        tft.setTextPadding(tft.textWidth("Custom2", 1));
        tft.drawString(Material, 155, 4, 1);
        tft.setTextPadding(0);
        tft.setTextDatum(TL_DATUM);

        if (FilRunoutSensor == 1) {
          tft.setCursor(18, 4);
          tft.print("R");
        } else if (FilRunoutSensor == 0) {
          tft.setCursor(18, 4);
          tft.print(" ");
        }
        if (FilJamsSensor == 1) {
          tft.setCursor(28, 4);
          tft.print("J");
        } else if (FilJamsSensor == 0) {
          tft.setCursor(28, 4);
          tft.print(" ");
        }
        if (AutoOff == 1) {
          tft.pushImage(38, 1, 13, 13, AutoOffIcon);
        } else if (AutoOff == 0) {
          tft.fillRect(38, 1, 13, 13, GreyBlue);
        }

        if (RelayState == 1){
          tft.drawCircle(8, 7, 5, LightGreen);
          tft.drawLine(7, 2, 9, 2, GreyBlue);
          tft.drawLine(8, 1, 8, 6, LightGreen);
        } else {
          tft.drawCircle(8, 7, 5, TFT_RED);
          tft.drawLine(7, 2, 9, 2, GreyBlue);
          tft.drawLine(8, 1, 8, 6, TFT_RED);
        }

        if (CurrentSpool == 0) {
          tft.setTextColor(LightGreen, GreyBlue);
          tft.setCursor(80, 4);
          tft.print("  ");
          tft.drawCircle(100, 7, 5, TFT_RED);
          tft.drawCircle(100, 7, 2, TFT_RED);
          tft.drawLine(105, 3, 106, 3, TFT_RED);

        }
        else if (CurrentSpool > 0) {
          tft.setTextColor(LightGreen, GreyBlue);
          tft.setCursor(80, 4);
          tft.print(CurrentSpool);
          tft.println(".");
          tft.drawCircle(100, 7, 5, LightGreen);
          tft.drawCircle(100, 7, 2, LightGreen);
          tft.drawLine(105, 3, 106, 3, LightGreen);
        }


        if (WiFi.status() == WL_CONNECTED || APMode == "ON"){
          tft.pushImage(58, 2, 16, 11, WifiSmall);
        } else if (WiFi.status() != WL_CONNECTED && APMode == "OFF"){
          tft.fillRect(58, 2, 16, 11, GreyBlue);
        }
        
      } else if (NoFilament == 1) {
        tft.setCursor(20, 4);
        tft.setTextColor(TFT_RED, GreyBlue);
        tft.print("No Filament");

        if (RelayState == 1){
          tft.drawCircle(8, 7, 5, LightGreen);
          tft.drawLine(7, 2, 9, 2, GreyBlue);
          tft.drawLine(8, 1, 8, 6, LightGreen);
        } else {
          tft.drawCircle(8, 7, 5, TFT_RED);
          tft.drawLine(7, 2, 9, 2, GreyBlue);
          tft.drawLine(8, 1, 8, 6, TFT_RED);
        }
      }
      tft.setTextColor(TFT_WHITE, TFT_BLACK); 
     }
       PowerRing();
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Energy screen  */
  else if (screen == "Energy") {
    if (clearScreen < 2 && cMillis - EnergyScreenMillis0 >= 5) {
      EnergyScreenMillis0 = cMillis;
      if (clearScreen == 0) {

        
        SpriteDefine();
        ScreenXScroll = 160;
        DoubleScreenBarX = 0;
        while (ScreenBarX != 32){
          ScreenScroll();
        }

       
        if(ScreenXScroll == 0){
          ScreenXScroll = 0;
        } else{
          tft.fillRect(1, 1, 158, 126, TFT_BLACK);  // Start from top-left pixel (x,y,wigth,height)
          tft.fillRoundRect(10, 4, 140, 40, 8, GreyBlue);
          ScreenXScroll = 0;
        }
        
      } else if (clearScreen == 1) {
        SpritesDelete();
        LastScreen = "Energy";
        tft.drawLine(32, 127, 64, 127, TFT_WHITE);
        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(60, 62);
        tft.print("Time");

        tft.setTextFont(2);
        tft.setCursor(45, 25);
        tft.print("Used Energy");
        
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(Purple);
        tft.setCursor(20, 96);
        tft.print("Electrical Cost");

        tft.pushImage(18, 9, 19, 28, LightningBolt);
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EnergyScreenMillis1 >= 100) {
      EnergyScreenMillis1 = cMillis;

      tft.setTextColor(TFT_WHITE, GreyBlue);
      tft.setTextFont(4);

      tft.setTextDatum(TR_DATUM);
      tft.setTextPadding(tft.textWidth("9999.9", 4));
      if (EnergyUnit == 0) {
        if (E < 10.00) {
          tft.drawFloat(E, 4, 121, 5, 4);
        } else if (E >= 10.00 && E < 100.00){
          tft.drawFloat(E, 3, 121, 5, 4);
        } else if (E >= 100.00 && E < 1000.00){
          tft.drawFloat(E, 2, 121, 5, 4);
        } else if (E >= 1000.00){
          tft.drawFloat(E, 1, 121, 5, 4);
        }
        tft.setTextPadding(0);
        tft.drawString("kWh", 147, 10, 2);
     }
     else if (EnergyUnit == 1) {
      tft.setTextPadding(tft.textWidth("9999.9", 4));
        if (E * 1000.00 < 10.00) {
          tft.drawFloat(E * 1000.00, 4, 121, 5, 4);
        } else if (E * 1000.00 >= 10.00 && E * 1000.00 < 100.00){
          tft.drawFloat(E * 1000.00, 3, 121, 5, 4);
        } else if (E * 1000.00 >= 100.00 && E * 1000.00 < 1000.00){
          tft.drawFloat(E * 1000.00, 2, 121, 5, 4);
        } else if (E * 1000.00 >= 1000.00){
          tft.drawFloat(E * 1000.00, 1, 121, 5, 4);
        }
        tft.setTextPadding(0);
        tft.drawString("Wh", 142, 10, 2);
     }
     else if (EnergyUnit == 2) {
      if (E < 1.00) {
        tft.setTextPadding(tft.textWidth("9999.9", 4));
        if (E * 1000.00 < 10.00) {
          tft.drawFloat(E * 1000.00, 4, 121, 5, 4);
        } else if (E * 1000.00 >= 10.00 && E * 1000.00 < 100.00){
          tft.drawFloat(E * 1000.00, 3, 121, 5, 4);
        } else if (E * 1000.00 >= 100.00 && E * 1000.00 < 1000.00){
          tft.drawFloat(E * 1000.00, 2, 121, 5, 4);
        } else if (E * 1000.00 >= 1000.00){
          tft.drawFloat(E * 1000.00, 1, 121, 5, 4);
        }
        tft.setTextPadding(0);
        tft.drawString("Wh", 142, 10, 2);
      }
      else {
        tft.setTextPadding(tft.textWidth("9999.9", 4));
        if (E < 10.00) {
          tft.drawFloat(E, 4, 121, 5, 4);
        } else if (E >= 10.00 && E < 100.00){
          tft.drawFloat(E, 3, 121, 5, 4);
        } else if (E >= 100.00 && E < 1000.00){
          tft.drawFloat(E, 2, 121, 5, 4);
        } else if (E >= 1000.00){
          tft.drawFloat(E, 1, 121, 5, 4);
        }
        tft.setTextPadding(0);
        tft.drawString("kWh", 147, 10, 2);
      }
     }
      tft.setTextDatum(TL_DATUM);

      tft.setTextColor(Purple);
      tft.setTextFont(2);
      tft.setCursor(45, 25); //24, 15
      tft.print("Used Energy");
      

      tft.setTextFont(4);
      tft.setTextColor(TFT_WHITE, TFT_BLACK);

      tft.setTextDatum(TR_DATUM);
      tft.setTextPadding(tft.textWidth("9999.9", 4));
        if (EC < 10.00) {
          tft.drawFloat(EC, 4, 107, 100, 4);
        } else if (EC >= 10.00 && EC < 100.00){
          tft.drawFloat(EC, 3, 107, 100, 4);
        } else if (EC >= 100.00 && EC < 1000.00){
          tft.drawFloat(EC, 2, 107, 100, 4);
        } else if (EC >= 1000.00){
          tft.drawFloat(EC, 1, 107, 100, 4);
        }
        tft.setTextPadding(0);
        tft.setTextDatum(TL_DATUM);


        if (Currency == "$"){
          tft.pushImage(110, 103, 11, 16, DollarIcon);
        } else if (Currency == "E"){
          tft.pushImage(110, 103, 11, 16, EuroIcon);
        } else if (Currency == "P"){
          tft.pushImage(110, 103, 11, 16, PoundIcon);
        } else if (Currency == "A$"){
          tft.pushImage(110, 103, 22, 16, ADollarIcon);
        } else if (Currency == "C$"){
          tft.pushImage(110, 103, 22, 16, CDollarIcon);
        }


      dtostrf(second(), 2, 0, seconds);  // (<variable>,<amount of digits we are going to use>,<amount of decimal digits>,<string name>)
      dtostrf(minute(), 2, 0, minutes);
      dtostrf(hour(), 2, 0, hours);
      dtostrf(day() - 1, 2, 0, days);
      tft.setTextFont(2);
      tft.setCursor(125, 65);
      tft.print(seconds);
      tft.println("s ");
      tft.setCursor(85, 65);
      tft.print(minutes);
      tft.println("m ");
      tft.setCursor(45, 65);
      tft.print(hours);
      tft.println("h ");
      tft.setCursor(8, 65);
      tft.print(days);
      tft.println("d");
    }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////*  Energy 2 screen  */
  else if (screen == "Energy2") {
    if (clearScreen < 2 && cMillis - Energy2ScreenMillis0 >= 5) {
      Energy2ScreenMillis0 = cMillis;
      if (clearScreen == 0) {


        SpriteDefine();
        ScreenXScroll = 160;
        DoubleScreenBarX = 0;
        while (ScreenBarX != 0){
          ScreenScroll();
        }

        
        if(ScreenXScroll == 0){
          ScreenXScroll = 0;
        } else{
          tft.fillRect(1, 1, 158, 126, TFT_BLACK);  // Start from top-left pixel (x,y,wigth,height)
          tft.fillRoundRect(5, 5, 70, 52, 8, GreyBlue);
          tft.fillRoundRect(85, 5, 70, 52, 8, GreyBlue);
          ScreenXScroll = 0;
        }
        
      } else if (clearScreen == 1) {
        SpritesDelete();
        LastScreen = "Energy2";
        tft.drawLine(0, 127, 32, 127, TFT_WHITE);
        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(12, 22); //15
        tft.print("Avg. P");
        tft.setCursor(92, 22);
        tft.print("Max. P");
      }
      
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - Energy2ScreenMillis1 >= 100) {
      Energy2ScreenMillis1 = cMillis;
      tft.setTextColor(Purple);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      
      if (PrintingON == 1) {
        tft.setTextColor(Purple);
        tft.setCursor(13, 84);
        tft.print("Printing");
        i = i + Add;
        if (i >= 27 || i == 0){
          Add = - Add;
        }
        if (i >= 0 && i <= 26){
          tft.pushImage(94, 75, 58, 39, PrinterGif[i]);
        }
        
      } else if (PrintingON == 0) {
        if (RelayState == 0){
          tft.setCursor(18, 90);
          tft.print("Printer");
          tft.setCursor(31, 110);
          tft.print("Off");
        } else {
          tft.setCursor(10, 98);
          tft.print("Standby");
        }
        tft.pushImage(94, 75, 58, 39, PrinterGif[0]);
      }
      
      tft.setTextColor(TFT_WHITE, GreyBlue);
      tft.setTextFont(4);

      tft.setTextDatum(TR_DATUM);
      tft.setTextPadding(tft.textWidth("999", 4));
      tft.drawNumber(AvgP, 54, 31, 4);
      tft.setTextPadding(0);
      tft.drawString("W", 66, 36, 2);

      tft.setTextPadding(tft.textWidth("999", 4));
      tft.drawNumber(MaxP, 134, 31, 4);
      tft.setTextPadding(0);
      tft.drawString("W", 146, 36, 2);
      tft.setTextDatum(TL_DATUM);

      if (PrintingON == 1){
        tft.setTextColor(TFT_WHITE, TFT_BLACK);

        tft.setTextDatum(TC_DATUM);
        tft.setTextPadding(tft.textWidth("999", 2));
        tft.drawNumber(PrintHour, 44, 89, 2);
        tft.setTextPadding(0);
        tft.drawString("h", 61, 89, 2);

        tft.setTextDatum(TR_DATUM);
        tft.setTextPadding(tft.textWidth("99", 2));
        tft.drawNumber(PrintMin, 28, 106, 2);
        tft.setTextPadding(0);
        tft.drawString("m", 38, 106, 2);

        tft.setTextPadding(tft.textWidth("99", 2));
        tft.drawNumber(PrintSec, 68, 106, 2);
        tft.setTextPadding(0);
        tft.drawString("s", 77, 106, 2);
        tft.setTextDatum(TL_DATUM);
      }
    }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament screen  */
  else if (screen == "Filament") {
    if (clearScreen < 2 && cMillis - FilamentScreenMillis0 >= 5) {
      FilamentScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        
        
        SpriteDefine();
        ScreenXScroll = 160;
        DoubleScreenBarX = 0;
        while (ScreenBarX != 96){
          ScreenScroll();
        }

       
        if(ScreenXScroll == 0){
          ScreenXScroll = 0;
          SlowPRing = 1;
        } else{
          tft.fillRect(0, 0, 160, 128, TFT_BLACK);
          tft.fillRoundRect(5, 5, 150, 72, 8, GreyBlue);
          ScreenXScroll = 0;
        }
        
      } else if (clearScreen == 1) {
        SpritesDelete();
        LastScreen = "Filament";
        tft.drawLine(96, 127, 128, 127, TFT_WHITE);
        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.pushImage(10, 11, 36, 44, GreenFilSpool);
        tft.setCursor(8, 15);
        tft.setCursor(62, 96);
        tft.print("Cost");
        tft.setTextFont(2);
        tft.setCursor(38, 58);
        tft.print("Filament Used");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - FilamentScreenMillis1 >= 200) {
      FilamentScreenMillis1 = cMillis;

      tft.setTextColor(TFT_WHITE, GreyBlue);
      tft.setTextDatum(TR_DATUM);
      tft.setTextPadding(tft.textWidth("90000.0", 4));
      if (FL < 9999.99) {
        tft.drawFloat(FL, 2, 136, 8, 4);
      } else {
        tft.drawFloat(FL, 1, 136, 8, 4);
      }

      if (FW < 0.99999) {
        tft.drawFloat(FW * 1000, 2, 136, 34, 4);
      } else if (FW >= 0.99999 && FW < 9.99999) {
        tft.drawFloat(FW, 4, 136, 34, 4);
      } else if (FW >= 9.99999 && FW < 99.99999) {
        tft.drawFloat(FW, 3, 136, 34, 4);
      } else if (FW >= 99.99999 && FW < 999.99999) {
        tft.drawFloat(FW, 2, 136, 34, 4);
      } else {
        tft.drawFloat(FW, 1, 136, 34, 4);
      }

      tft.setTextPadding(tft.textWidth("kg", 2));
      tft.setTextDatum(TL_DATUM);
      tft.drawString("m", 138, 12, 2);
      if (FW < 0.99999) {
        tft.drawString("g", 138, 38, 2);
      } else {
        tft.drawString("kg", 138, 38, 2);
      }
      tft.setTextPadding(0);


      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextDatum(TR_DATUM);
      tft.setTextPadding(tft.textWidth("-9999.9", 4));
        if (FC < 10.00) {
          tft.drawFloat(FC, 4, 107, 100, 4);
        } else if (FC >= 10.00 && FC < 100.00){
          tft.drawFloat(FC, 3, 107, 100, 4);
        } else if (FC >= 100.00 && FC < 1000.00){
          tft.drawFloat(FC, 2, 107, 100, 4);
        } else if (FC >= 1000.00){
          tft.drawFloat(FC, 1, 107, 100, 4);
        }
        tft.setTextPadding(0);
        tft.setTextDatum(TL_DATUM);


        if (Currency == "$"){
          tft.pushImage(110, 103, 11, 16, DollarIcon);
        } else if (Currency == "E"){
          tft.pushImage(110, 103, 11, 16, EuroIcon);
        } else if (Currency == "P"){
          tft.pushImage(110, 103, 11, 16, PoundIcon);
        } else if (Currency == "A$"){
          tft.pushImage(110, 103, 22, 16, ADollarIcon);
        } else if (Currency == "C$"){
          tft.pushImage(110, 103, 22, 16, CDollarIcon);
        }
    }
  }

/////////////////////////////////////////////////////////////////////////////////////////////* Filament 2. screen  */
  else if (screen == "Filament2") {
    if (clearScreen < 2 && cMillis - Filament2ScreenMillis0 >= 5) {
      Filament2ScreenMillis0 = cMillis;
      if (clearScreen == 0) {


        SpriteDefine();
        ScreenXScroll = 160;
        DoubleScreenBarX = 0;
        while (ScreenBarX != 128){
          ScreenScroll();
        }


        if(ScreenXScroll == 0){
          ScreenXScroll = 0;
        } else {
          tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          ScreenXScroll = 0;
          if (CurrentSpool > 0){
            tft.fillRoundRect(10, 25, 140, 64, 8, GreyBlue);
            LastCurSpoolPercentage = -1;
          }
        }
        
      } else if (clearScreen == 1) {
        SpritesDelete();
        LastScreen = "Filament2";
        tft.drawLine(128, 127, 160, 127, TFT_WHITE);
        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextDatum(TC_DATUM);
        tft.drawString("Filament Spool", 79, 1, GFXFF);
        tft.setCursor(17, 15);
        tft.setCursor(59, 60);
        if (CurrentSpool == 0){
          tft.drawString("Spool not", 79, 26, GFXFF);
          tft.drawString("selected", 79, 46, GFXFF);
          tft.pushImage(52, 68, 58, 51, FilSpoolDark);
        } else if (CurrentSpool > 0) {
          LastCurSpoolPercentage = -1;
          SpoolBar = 1;
        }
        tft.setTextDatum(TL_DATUM);
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - Filament2ScreenMillis1 >= 100) {
      Filament2ScreenMillis1 = cMillis;

      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      tft.setTextDatum(TC_DATUM);
      if (CurrentSpool > 0) {
        SpoolShow();
      }
      tft.setTextDatum(TL_DATUM);
    }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Main Settings  */
  else if (screen == "MainSettings") {
    if (clearScreen < 2 && cMillis - MainSettingsScreenMillis0 >= 5) {
      MainSettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        if (SettingsSelect < 6){
          while (SettingsBarY != 0){
            SettingsBarY = SettingsBarY - 1;
            tft.drawLine(159, SettingsBarY, 159, SettingsBarY + 64, Purple);
            tft.drawLine(159, SettingsBarY + 65, 159, SettingsBarY + 65, TFT_BLACK);
            delay(3);
        }
        } else if (SettingsSelect > 5){
          while (SettingsBarY != 64){
            SettingsBarY = SettingsBarY + 1;
            tft.drawLine(159, SettingsBarY, 159, SettingsBarY + 64, Purple);
            tft.drawLine(159, SettingsBarY - 1, 159, SettingsBarY - 1, TFT_BLACK);
            delay(3);
        }
        }
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
        LastScreen == "MainSettings";

        tft.setTextFont(2);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

        if (SettingsSelect < 6) {
          tft.drawLine(159, 0, 159, 64, Purple);
        }
        if (SettingsSelect > 5) {
          tft.drawLine(159, 64, 159, 128, Purple);
        }

      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - MainSettingsScreenMillis1 >= 20) {
      MainSettingsScreenMillis1 = cMillis;
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (SettingsSelect == 0) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Home Screen");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Energy Cost");
        tft.setCursor(15, 60); tft.print("Currency");
        tft.setCursor(15, 80); tft.print("Underglow");
        tft.setCursor(15, 100); tft.print("WiFi");
        tft.pushImage(65, 87, 23, 18, WiFiIcon);
        tft.setCursor(15, 120); tft.print("Filament");
      } else if (SettingsSelect == 1) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Home Screen");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("Energy Cost");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 60); tft.print("Currency");
        tft.setCursor(15, 80); tft.print("Underglow");
        tft.setCursor(15, 100); tft.print("WiFi");
        tft.pushImage(65, 87, 23, 18, WiFiIcon);
        tft.setCursor(15, 120); tft.print("Filament");
      } else if (SettingsSelect == 2) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Home Screen");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("Currency");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Energy Cost");
        tft.setCursor(15, 80); tft.print("Underglow");
        tft.setCursor(15, 100); tft.print("WiFi");
        tft.pushImage(65, 87, 23, 18, WiFiIcon);
        tft.setCursor(15, 120); tft.print("Filament");
      } else if (SettingsSelect == 3) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Home Screen");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("Underglow");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Energy Cost");
        tft.setCursor(15, 60); tft.print("Currency");
        tft.setCursor(15, 100); tft.print("WiFi");
        tft.pushImage(65, 87, 23, 18, WiFiIcon);
        tft.setCursor(15, 120); tft.print("Filament");
      } else if (SettingsSelect == 4) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Home Screen");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 100); tft.print("WiFi");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Energy Cost");
        tft.setCursor(15, 60); tft.print("Currency");
        tft.setCursor(15, 80); tft.print("Underglow");
        tft.pushImage(65, 87, 23, 18, WiFiIcon);
        tft.setCursor(15, 120); tft.print("Filament");
      } else if (SettingsSelect == 5) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Home Screen");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 120); tft.print("Filament");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Energy Cost");
        tft.setCursor(15, 60); tft.print("Currency");
        tft.setCursor(15, 80); tft.print("Underglow");
        tft.setCursor(15, 100); tft.print("WiFi");
        tft.pushImage(65, 87, 23, 18, WiFiIcon);

      } else if (SettingsSelect == 6) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Auto Off");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Brightness");
        tft.setCursor(15, 60); tft.print("Sound");
        tft.pushImage(77, 46, 21, 18, Sound);
        tft.setCursor(15, 80); tft.print("Auto Scroll");
        tft.setCursor(15, 100); tft.print("Save / Erase");
        tft.setCursor(15, 120); tft.print("Reset Settings");
      } else if (SettingsSelect == 7) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("Brightness");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("Auto Off");
        tft.setCursor(15, 60); tft.print("Sound");
        tft.pushImage(77, 46, 21, 18, Sound);
        tft.setCursor(15, 80); tft.print("Auto Scroll");
        tft.setCursor(15, 100); tft.print("Save / Erase");
        tft.setCursor(15, 120); tft.print("Reset Settings");
      } else if (SettingsSelect == 8) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("Sound");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("Auto Off");
        tft.setCursor(15, 40); tft.print("Brightness");
        tft.pushImage(77, 46, 21, 18, Sound);
        tft.setCursor(15, 80); tft.print("Auto Scroll");
        tft.setCursor(15, 100); tft.print("Save / Erase");
        tft.setCursor(15, 120); tft.print("Reset Settings");
      } else if (SettingsSelect == 9) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("Auto Scroll");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("Auto Off");
        tft.setCursor(15, 40); tft.print("Brightness");
        tft.setCursor(15, 60); tft.print("Sound");
        tft.pushImage(77, 46, 21, 18, Sound);
        tft.setCursor(15, 100); tft.print("Save / Erase");
        tft.setCursor(15, 120); tft.print("Reset Settings");
      } else if (SettingsSelect == 10) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 100); tft.print("Save / Erase");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("Auto Off");
        tft.setCursor(15, 40); tft.print("Brightness");
        tft.setCursor(15, 60); tft.print("Sound");
        tft.pushImage(77, 46, 21, 18, Sound);
        tft.setCursor(15, 80); tft.print("Auto Scroll");
        tft.setCursor(15, 120); tft.print("Reset Settings");
      } else if (SettingsSelect == 11) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 120); tft.print("Reset Settings");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("Auto Off");
        tft.setCursor(15, 40); tft.print("Brightness");
        tft.setCursor(15, 60); tft.print("Sound");
        tft.pushImage(77, 46, 21, 18, Sound);
        tft.setCursor(15, 80); tft.print("Auto Scroll");
        tft.setCursor(15, 100); tft.print("Save / Erase");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////* Filament Settings  */
  else if (screen == "FilamentSettings") {
    if (clearScreen < 2 && cMillis - FilamentSettingsScreenMillis0 >= 5) {
      FilamentSettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        if (SettingsSelect < 6){
          while (SettingsBarY != 0){
            SettingsBarY = SettingsBarY - 1;
            tft.drawLine(159, SettingsBarY, 159, SettingsBarY + 64, Purple);
            tft.drawLine(159, SettingsBarY + 65, 159, SettingsBarY + 65, TFT_BLACK);
            delay(3);
        }
        } else if (SettingsSelect > 5){
          while (SettingsBarY != 64){
            SettingsBarY = SettingsBarY + 1;
            tft.drawLine(159, SettingsBarY, 159, SettingsBarY + 64, Purple);
            tft.drawLine(159, SettingsBarY - 1, 159, SettingsBarY - 1, TFT_BLACK);
            delay(3);
        }
        }
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
        LastScreen = "FilamentSettings";

        tft.setTextColor(Purple, TFT_BLACK);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        if (SettingsSelect < 6) {
          tft.drawLine(159, 0, 159, 64, Purple);
        }
        if (SettingsSelect > 5) {
          tft.drawLine(159, 64, 159, 128, Purple);
        }
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - FilamentSettingsScreenMillis1 >= 20) {
      FilamentSettingsScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (SettingsSelect == 0) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE); 
        tft.setCursor(15, 40); tft.print("PLA");
        tft.setCursor(15, 60); tft.print("PETG");
        tft.setCursor(15, 80); tft.print("ABS");
        tft.setCursor(15, 100); tft.print("TPU");
        tft.setCursor(15, 120); tft.print("Nylon");
      } else if (SettingsSelect == 1) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("PLA");
        tft.setTextColor(TFT_WHITE); 
        tft.setCursor(15, 60); tft.print("PETG");
        tft.setCursor(15, 80); tft.print("ABS");
        tft.setCursor(15, 100); tft.print("TPU");
        tft.setCursor(15, 120); tft.print("Nylon");
      } else if (SettingsSelect == 2) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("PETG");
        tft.setTextColor(TFT_WHITE); 
        tft.setCursor(15, 40); tft.print("PLA");
        tft.setCursor(15, 80); tft.print("ABS");
        tft.setCursor(15, 100); tft.print("TPU");
        tft.setCursor(15, 120); tft.print("Nylon");
      } else if (SettingsSelect == 3) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("ABS");
        tft.setTextColor(TFT_WHITE); 
        tft.setCursor(15, 40); tft.print("PLA");
        tft.setCursor(15, 60); tft.print("PETG");
        tft.setCursor(15, 100); tft.print("TPU");
        tft.setCursor(15, 120); tft.print("Nylon");
      } else if (SettingsSelect == 4) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 100); tft.print("TPU");
        tft.setTextColor(TFT_WHITE); 
        tft.setCursor(15, 40); tft.print("PLA");
        tft.setCursor(15, 60); tft.print("PETG");
        tft.setCursor(15, 80); tft.print("ABS");
        tft.setCursor(15, 120); tft.print("Nylon");
      } else if (SettingsSelect == 5) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 120); tft.print("Nylon");
        tft.setTextColor(TFT_WHITE); 
        tft.setCursor(15, 40); tft.print("PLA");
        tft.setCursor(15, 60); tft.print("PETG");
        tft.setCursor(15, 80); tft.print("ABS");
        tft.setCursor(15, 100); tft.print("TPU");

      } else if (SettingsSelect == 6) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("PVA");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("HIPS");
        tft.setCursor(15, 60); tft.print("ASA");
        tft.setCursor(15, 80); tft.print("PC");
        tft.setCursor(15, 100); tft.print("Custom 1");
        tft.setCursor(15, 120); tft.print("Custom 2");
      } else if (SettingsSelect == 7) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("HIPS");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("PVA");
        tft.setCursor(15, 60); tft.print("ASA");
        tft.setCursor(15, 80); tft.print("PC");
        tft.setCursor(15, 100); tft.print("Custom 1");
        tft.setCursor(15, 120); tft.print("Custom 2");
      } else if (SettingsSelect == 8) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("ASA");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("PVA");
        tft.setCursor(15, 40); tft.print("HIPS");
        tft.setCursor(15, 80); tft.print("PC");
        tft.setCursor(15, 100); tft.print("Custom 1");
        tft.setCursor(15, 120); tft.print("Custom 2");
      } else if (SettingsSelect == 9) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("PC");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("PVA");
        tft.setCursor(15, 40); tft.print("HIPS");
        tft.setCursor(15, 60); tft.print("ASA");
        tft.setCursor(15, 100); tft.print("Custom 1");
        tft.setCursor(15, 120); tft.print("Custom 2");
      } else if (SettingsSelect == 10) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 100); tft.print("Custom 1");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("PVA");
        tft.setCursor(15, 40); tft.print("HIPS");
        tft.setCursor(15, 60); tft.print("ASA");
        tft.setCursor(15, 80); tft.print("PC");
        tft.setCursor(15, 120); tft.print("Custom 2");
      } else if (SettingsSelect == 11) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 120); tft.print("Custom 2");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 20); tft.print("PVA");
        tft.setCursor(15, 40); tft.print("HIPS");
        tft.setCursor(15, 60); tft.print("ASA");
        tft.setCursor(15, 80); tft.print("PC");
        tft.setCursor(15, 100); tft.print("Custom 1");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Spool Select Settings  */
  else if (screen == "SpoolSelectSettings") {
    if (clearScreen < 2 && cMillis - SpoolSelectSettingsScreenMillis0 >= 5) {
      SpoolSelectSettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
        LastScreen = "SpoolSelectSettings";

      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SpoolSelectSettingsScreenMillis1 >= 10) {
      SpoolSelectSettingsScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

        if (SettingsSelect == 0){
          tft.setTextColor(LightGreen);
        } else {
          tft.setTextColor(LightRed);
        }
        tft.setCursor(20, 20); tft.print("x None x");

        for (int i = 0; i < 5; i++) {
          if (SettingsSelect == i + 1){
            tft.setTextColor(LightGreen);
          } else {
            tft.setTextColor(TFT_WHITE);
          }

          tft.setCursor(20, ((i + 1) * 20) + 20);
          tft.print(i + 1);
          tft.println(".");

          if (SpoolMaterial[i] == 1) {
            CurSpoolMatText = "PLA";
          } else if (SpoolMaterial[i] == 2) {
            CurSpoolMatText = "PETG";
          } else if (SpoolMaterial[i] == 3) {
            CurSpoolMatText = "ABS";
          } else if (SpoolMaterial[i] == 4) {
            CurSpoolMatText = "TPU";
          } else if (SpoolMaterial[i] == 5) {
            CurSpoolMatText = "Nylon";
          } else if (SpoolMaterial[i] == 6) {
            CurSpoolMatText = "PVA";
          } else if (SpoolMaterial[i] == 7) {
            CurSpoolMatText = "HIPS";
          } else if (SpoolMaterial[i] == 8) {
            CurSpoolMatText = "ASA";
          } else if (SpoolMaterial[i] == 9) {
            CurSpoolMatText = "PC";
          } else if (SpoolMaterial[i] == 10) {
            CurSpoolMatText = "Custom1";
          } else if (SpoolMaterial[i] == 11) {
            CurSpoolMatText = "Custom2";
          }
          tft.setCursor(40, ((i + 1) * 20) + 20);
          tft.print(CurSpoolMatText);
        }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Energy Cost Settings  */
  else if (screen == "EnergyCost") {
    if (clearScreen < 2 && cMillis - EnergyCostScreenMillis0 >= 5) {
      EnergyCostScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
        ecEdit = ec;
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EnergyCostScreenMillis1 >= 100) {
      EnergyCostScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (SettingsSelect == 0){
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Save");
        tft.setCursor(15, 60); tft.print("Cost:");
      } else if (SettingsSelect == 1){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("Save");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 60); tft.print("Cost:");
      } else if (SettingsSelect == 2){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("Cost:");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Save");
      }
      tft.setCursor(97, 88); tft.print("/kWh");
      tft.setTextColor(Purple);
      tft.setCursor(15, 115); tft.print("Energy Cost");

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(62, 72);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(62, 72, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(62, 72, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setTextColor(Purple, TFT_BLACK);
      tft.setCursor(80, 47);
      tft.print(ecEdit);
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Energy Settings  */
  else if (screen == "EnergySettings") {
    if (clearScreen < 2 && cMillis - EnergySettingsScreenMillis0 >= 5) {
      EnergySettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
        LastScreen = "EnergySettings";

        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(15, 20);
        tft.print("Back");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(15, 40);
        tft.print("Automatic");
        tft.setCursor(15, 60);
        tft.print("kWh");
        tft.setCursor(15, 80);
        tft.print("Wh");
        tft.setCursor(15, 110);
        tft.setTextColor(Purple);
        tft.print("Energy Unit");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EnergySettingsScreenMillis1 >= 20) {
      EnergySettingsScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextColor(LightGreen);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (SettingsSelect == 0) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Automatic");
        tft.setCursor(15, 60); tft.print("kWh");
        tft.setCursor(15, 80); tft.print("Wh");
      } else if (SettingsSelect == 1) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("Automatic");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 60); tft.print("kWh");
        tft.setCursor(15, 80); tft.print("Wh");
      } else if (SettingsSelect == 2) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("kWh");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Automatic");
        tft.setCursor(15, 80); tft.print("Wh");
      } else if (SettingsSelect == 3) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("Wh");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Automatic");
        tft.setCursor(15, 60); tft.print("kWh");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Power Settings  */
  else if (screen == "PowerSettings") {
    if (clearScreen < 2 && cMillis - PowerSettingsScreenMillis0 >= 5) {
      PowerSettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
        LastScreen = "PowerSettings";

        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(15, 20);
        tft.print("Back");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(15, 40);
        tft.print("Power");
        tft.setCursor(15, 110);
        tft.setTextColor(Purple);
        tft.print("Control");

        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        if (RelayState == 0){
          tft.setTextColor(LightRed, TFT_BLACK);
          tft.drawString("Off", 80, 26, GFXFF);
        } else if (RelayState == 1){
          tft.setTextColor(LightGreen, TFT_BLACK);
          tft.drawString("On  ", 80, 26, GFXFF);
        }
        
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        if (PausePrint == 0){
          tft.drawString("Pause     ", 15, 46, GFXFF);
        } else{
          tft.drawString("Resume", 15, 46, GFXFF);
        }
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - PowerSettingsScreenMillis1 >= 20) {
      PowerSettingsScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (SettingsSelect == 0) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Power");
        if (PausePrint == 0) {
          tft.setCursor(15, 60); tft.print("Pause     ");
        } else {
          tft.setCursor(15, 60); tft.print("Resume");
        }
      } else if (SettingsSelect == 1) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("Power");
        tft.setTextColor(TFT_WHITE);
        if (PausePrint == 0) {
          tft.setCursor(15, 60); tft.print("Pause     ");
        } else {
          tft.setCursor(15, 60); tft.print("Resume");
        }
      } else if (SettingsSelect == 2) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        if (PausePrint == 0) {
          tft.setCursor(15, 60); tft.print("Pause     ");
        } else {
          tft.setCursor(15, 60); tft.print("Resume");
        }
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Power");
      }
      
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Currency Settings  */
  else if (screen == "Currency") {
    if (clearScreen < 2 && cMillis - CurrencyScreenMillis0 >= 5) {
      CurrencyScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {

      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - CurrencyScreenMillis1 >= 20) {
      CurrencyScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (SettingsSelect == 0) {
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("USD $");
        tft.setCursor(15, 60); tft.print("EUR E");
        tft.setCursor(15, 80); tft.print("GBP P");
        tft.setCursor(15, 100); tft.print("AUD A$");
        tft.setCursor(15, 120); tft.print("CAD C$");
      } else if (SettingsSelect == 1) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("USD $");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 60); tft.print("EUR E");
        tft.setCursor(15, 80); tft.print("GBP P");
        tft.setCursor(15, 100); tft.print("AUD A$");
        tft.setCursor(15, 120); tft.print("CAD C$");
      } else if (SettingsSelect == 2) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("EUR E");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("USD $");
        tft.setCursor(15, 80); tft.print("GBP P");
        tft.setCursor(15, 100); tft.print("AUD A$");
        tft.setCursor(15, 120); tft.print("CAD C$");
      } else if (SettingsSelect == 3) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("GBP P");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("USD $");
        tft.setCursor(15, 60); tft.print("EUR E");
        tft.setCursor(15, 100); tft.print("AUD A$");
        tft.setCursor(15, 120); tft.print("CAD C$");
      } else if (SettingsSelect == 4) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 100); tft.print("AUD A$");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("USD $");
        tft.setCursor(15, 60); tft.print("EUR E");
        tft.setCursor(15, 80); tft.print("GBP P");
        tft.setCursor(15, 120); tft.print("CAD C$");
      } else if (SettingsSelect == 5) {
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 120); tft.print("CAD C$");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("USD $");
        tft.setCursor(15, 60); tft.print("EUR E");
        tft.setCursor(15, 80); tft.print("GBP P");
        tft.setCursor(15, 100); tft.print("AUD A$");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  LED Settings  */
  else if (screen == "PowerLED") {
    if (clearScreen < 2 && cMillis - PowerLEDScreenMillis0 >= 5) {
      PowerLEDScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(0, 0, 160, 128, TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(20, 20);
        tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(20, 60);
        tft.print("Mode:");
        tft.setCursor(20, 40);
        tft.print("LED:");
        tft.setCursor(20, 80);
        tft.print("Sparkle:");
        tft.setCursor(20, 100);
        tft.print("B Level:");
        tft.setTextColor(Purple);
        tft.setCursor(20, 120);
        tft.print("Underglow");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - PowerLEDScreenMillis1 >= 20) {
      PowerLEDScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      SettingsSelectVoid();

      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.setCursor(65, 28);
      if (LED == 0){
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.print("OFF");
      } else if (LED == 1){
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.print("ON  ");
      }

      tft.setCursor(100, 68);
      if (LEDSparkle == 0){
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.print("OFF");
      } else if (LEDSparkle == 1){
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.print("ON  ");
      }

      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(75, 48);
      if (LEDMode == 0){
        tft.print("Classic");
      } else if (LEDMode == 1){
        tft.print("Middle ");
      } else if (LEDMode == 2){
        tft.print("Sides  ");
      }
      
      tft.setTextSize(1);
      tft.setTextFont(4);
      tft.setCursor(92, 84);
      tft.print(LEDBrightnessPercentage);
      if (LEDBrightnessPercentage < 100){
        tft.print("%   ");
      } else {
        tft.print("%");
      }

      FastLED.setBrightness(map(LEDBrightnessPercentage, 0, 100, 0, 255));
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  WiFi  */
  else if (screen == "WiFi") {
    if (clearScreen < 2 && cMillis - WiFiScreenMillis0 >= 5) {
      WiFiScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 0, 159, 128, TFT_BLACK);
      } else if (clearScreen == 1) {
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - WiFiScreenMillis1 >= 50) {
      WiFiScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(Purple);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      tft.setCursor(20, 20);
      tft.print("Back");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setCursor(20, 40);
      tft.print("Network");
      tft.setCursor(20, 60);
      tft.print("AP Mode");
      tft.setCursor(20, 80);
      tft.print("Saved Net.");
      tft.setCursor(20, 100);
      tft.print("OFF");
      tft.setTextColor(Purple);
      tft.setCursor(45, 120);
      tft.print("Wifi");
      tft.pushImage(85, 105, 23, 18, WiFiIcon);
      if (Network == "OFF") {
        tft.setTextColor(LightRed);
        tft.setCursor(115, 40);
        tft.print("OFF");
      } else if (Network == "ON") {
        tft.setTextColor(LightGreen);
        tft.setCursor(115, 40);
        tft.print("ON");
      }
      if (APMode == "OFF") {
        tft.setTextColor(LightRed);
        tft.setCursor(115, 60);
        tft.print("OFF");
      } else if (APMode == "ON") {
        tft.setTextColor(LightGreen);
        tft.setCursor(115, 60);
        tft.print("ON");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Save  */
  else if (screen == "Save") {
    if (clearScreen < 31 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(35, 45, 90, 40, 8, GreyBlue);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(35, 45, 90, 40, 8, LightGreen);
        tft.setTextColor(LightGreen);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(52, 70);
        tft.print("Saved");
      } else if (clearScreen == 20) {
        screen = "MainSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 11;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Wifi OFF  */
  else if (screen == "WiFiOFF") {
    if (clearScreen < 31 && cMillis - WiFiOFFScreenMillis >= 50) {
      WiFiOFFScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(25, 45, 110, 40, 8, GreyBlue);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(25, 45, 110, 40, 8, LightRed);
        tft.setTextColor(LightRed);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(40, 70);
        tft.print("WiFi OFF");
        WiFi.softAP("3D Meter", "1234567890", 1, 1);
        WiFi.disconnect();
        Network = "OFF";
        APMode = "OFF";
      } else if (clearScreen == 20) {
        screen = "MainSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 11;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Access Point Mode  */
  else if (screen == "AP") {
    if (clearScreen < 2 && cMillis - APScreenMillis0 >= 50) {
      APScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {

        WiFi.mode(WIFI_AP);
        WiFi.setSleep(false);
        WiFi.softAP("OmnisPrint", "1234567890");
        IPAddress IP = WiFi.softAPIP();
        server.begin();
        APMode = "ON";
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - APScreenMillis1 >= 100) {
      APScreenMillis1 = cMillis;

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      tft.setCursor(24, 20);
      tft.print("AP Mode ON");
      tft.setTextFont(2);
      tft.setCursor(68, 40);
      tft.print("OmnisPrint");
      tft.setCursor(57, 60);
      tft.print("1234567890");
      tft.setCursor(57, 80);
      tft.print(WiFi.softAPIP());
      tft.setTextColor(Purple);
      tft.setCursor(10, 40);
      tft.print("SSID:");
      tft.setCursor(10, 60);
      tft.print("Pass:");
      tft.setCursor(10, 80);
      tft.print("IP:");

      tft.setTextColor(LightGreen);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      tft.setCursor(57, 114);
      tft.print("Back");
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Network Scan Settings  */
  else if (screen == "NetworkScan") {
    if (clearScreen < 2 && cMillis - NetworkScanScreenMillis0 >= 50) {
      NetworkScanScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {

        WiFi.disconnect();
        WiFi.mode(WIFI_AP_STA);
        WiFi.setSleep(false);        
        WiFi.softAP("3D Meter", "1234567890");
        IPAddress IP = WiFi.softAPIP();
        server.begin();
        APMode = "ON";

        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(40, 70);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.print("Scaning");
        tft.setTextFont(1);
        WiFiScanEnable = 1;
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - NetworkScanScreenMillis1 >= 100) {
      NetworkScanScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      if (cMillis - ScanMillis >= 24000 || WiFiScanEnable == 1) {
        ScanMillis = cMillis;
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
        tft.setCursor(44, 70);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.print("Scanning");
        Net1PassOPEN = 0;
        Net2PassOPEN = 0;
        Net3PassOPEN = 0;
        Net4PassOPEN = 0;
        Net5PassOPEN = 0;
        WiFiScanEnable = 0;

        int n = WiFi.scanNetworks();
        if (n == 0) {
          tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          tft.setTextColor(LightRed);
          tft.setCursor(20, 70);
          SettingsSelect = 0;
          SettingsCounter = 0;
          SettingsMaxSelect = 0;
          tft.print("No Networks");
        } else {
          SettingsMaxSelect = n;
          tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          tft.setTextColor(TFT_WHITE, TFT_BLACK);
          tft.setTextFont(1);
          for (int i = 0; i < n; ++i) {
            if (i < 4) {
              // Print SSID and RSSI for each network found
              tft.setCursor(20, ((i + 2) * 20) - 8);
              tft.print(WiFi.SSID(i));
              tft.print((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");

              if (i == 0) {
                Net1SSIDString = WiFi.SSID(i);
                if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                  Net1PassOPEN = 1;
                }
              } else if (i == 1) {
                Net2SSIDString = WiFi.SSID(i);
                if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                  Net2PassOPEN = 1;
                }
              } else if (i == 2) {
                Net3SSIDString = WiFi.SSID(i);
                if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                  Net3PassOPEN = 1;
                }
              } else if (i == 3) {
                Net4SSIDString = WiFi.SSID(i);
                if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                  Net4PassOPEN = 1;
                }
              } else if (i == 4) {
                Net5SSIDString = WiFi.SSID(i);
                if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
                  Net5PassOPEN = 1;
                }
              }
            }
          }
        }

      } else {

        SettingsSelectVoid();

        tft.setTextColor(Purple);
        //tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(20, 20);
        tft.print("Back");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Open WiFi Connecting  */
  else if (screen == "WiFiOPENConnecting") {
    if (clearScreen < 2 && cMillis - WiFiOPENScreenMillis0 >= 50) {
      WiFiOPENScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        dot = 0;
        WiFi.disconnect();
        Network = "OFF";
        OPENWiFiBegin = 0;
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - WiFiOPENScreenMillis1 >= 100) {
      WiFiOPENScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_BLUE);
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(20, 20);
      tft.print("-Cancel-");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);

      if (OPENWiFiBegin == 0) {
        tft.setTextFont(1);
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(20, 110);
        if (Net1PassOPEN == 1 && NetToConnect == 1) {
          WiFi.begin(Net1SSIDString.c_str());
          tft.print(Net1SSIDString);
          OPENWiFiBegin = 1;
        } else if (Net2PassOPEN == 1 && NetToConnect == 2) {
          WiFi.begin(Net2SSIDString.c_str());
          tft.print(Net2SSIDString);
          OPENWiFiBegin = 1;
        } else if (Net3PassOPEN == 1 && NetToConnect == 3) {
          WiFi.begin(Net3SSIDString.c_str());
          tft.print(Net3SSIDString);
          OPENWiFiBegin = 1;
        } else if (Net4PassOPEN == 1 && NetToConnect == 4) {
          WiFi.begin(Net4SSIDString.c_str());
          tft.print(Net4SSIDString);
          OPENWiFiBegin = 1;
        } else if (Net5PassOPEN == 1 && NetToConnect == 5) {
          WiFi.begin(Net5SSIDString.c_str());
          tft.print(Net5SSIDString);
          OPENWiFiBegin = 1;
        }
      } else if (WiFi.status() != WL_CONNECTED && cMillis - OpenConnectingMillis >= 400) {
        OpenConnectingMillis = cMillis;
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(26, 55);
        tft.print("Connecting");
        tft.setTextFont(4);
        if (dot == 0) {
          dot = 1;
          tft.setCursor(66, 70);
          tft.print(".   ");
        } else if (dot == 1) {
          dot = 2;
          tft.setCursor(66, 70);
          tft.print("..  ");
        } else if (dot == 2) {
          dot = 0;
          tft.setCursor(66, 70);
          tft.print("...");
        }
      } else if (WiFi.status() == WL_CONNECTED) {
        SettingsMaxSelect = 1;
        screen = "ConnectedSave";
        clearScreen = 0;
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Connected  */
  else if (screen == "Connected") {
    if (clearScreen < 60 && cMillis - ConnectedScreenMillis >= 50) {
      ConnectedScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        
        tft.setCursor(28, 40);
        tft.print("Connected");
        tft.setCursor(65, 70);
        tft.print("IP:");
        tft.setTextFont(2);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 90);
        tft.print(WiFi.localIP());
      } else if (clearScreen >= 50) {
        server.begin();
        Network = "ON";
        screen = "MainSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 11;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Connected Save  */
  else if (screen == "ConnectedSave") {
    if (clearScreen < 110 && cMillis - ConnectedSaveScreenMillis >= 50) {
      ConnectedSaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(Purple);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(28, 20);
        tft.print("Connected");
        tft.setCursor(65, 40);
        tft.print("IP:");
        tft.setCursor(20, 80);
        tft.print("Save Net ?");
        tft.setCursor(20, 100);
        tft.print("No");
        tft.setCursor(20, 120);
        tft.print("Yes");
        tft.setTextFont(2);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(10, 48);
        tft.print(WiFi.localIP());
      } else if (clearScreen > 1 && clearScreen < 100) {
        if (SettingsSelect == 0) {
          tft.setCursor(7, 87);
          tft.print(">");
          tft.setCursor(7, 105);
          tft.print("  ");
        } else if (SettingsSelect == 1) {
          tft.setCursor(7, 87);
          tft.print("  ");
          tft.setCursor(7, 105);
          tft.print(">");
        }
      } else if (clearScreen >= 100) {
        server.begin();
        Network = "ON";
        screen = "MainSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 11;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Save Network Settings  */
  else if (screen == "SaveNet") {
    if (clearScreen < 2 && cMillis - SaveNetScreenMillis0 >= 50) {
      SaveNetScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SaveNetScreenMillis1 >= 100) {
      SaveNetScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(Purple);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      tft.setCursor(20, 20);
      tft.print("Back");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setCursor(20, 40);
      tft.print("1");
      tft.setCursor(20, 60);
      tft.print("2");
      tft.setCursor(20, 80);
      tft.print("3");
      tft.setCursor(20, 100);
      tft.print("4");
      tft.setCursor(20, 120);
      tft.print("5");
      tft.setTextFont(1);
      tft.setCursor(35, 35);
      tft.print(SavedNet1SSIDString);
      tft.setCursor(35, 55);
      tft.print(SavedNet2SSIDString);
      tft.setCursor(35, 75);
      tft.print(SavedNet3SSIDString);
      tft.setCursor(35, 95);
      tft.print(SavedNet4SSIDString);
      tft.setCursor(35, 115);
      tft.print(SavedNet5SSIDString);
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  WiFi Connect  */
  else if (screen == "WiFiConnect") {
    if (clearScreen < 2 && cMillis - WiFiConnectScreenMillis0 >= 50) {
      WiFiConnectScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        WiFi.disconnect();
        Network = "OFF";
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

        tft.setTextColor(Purple);
        tft.setCursor(20, 20);
        tft.print("Cancel");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(32, 44);
        tft.print("Waiting for");
        tft.setCursor(40, 62);
        tft.print("Password");
        tft.setTextFont(1);
        tft.setTextColor(LightGreen);
        tft.setCursor(14, 115);
        tft.print("Network > Send Password");
        PassConnect = 0;
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - WiFiConnectScreenMillis1 >= 100) {
      WiFiConnectScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextDatum(TC_DATUM);
      tft.setTextFont(1);
      tft.setCursor(80, 78);
      if (PassConnect < 2) {
        if (NetToConnect == 1) {
          tft.drawString(Net1SSIDString, 80, 78, 1);
          if (PassConnect == 1) {
            WiFi.begin(Net1SSIDString.c_str(), NetPassString.c_str());
            PassConnect = 2;
            tft.setTextColor(TFT_BLACK);
            tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          }
        } else if (NetToConnect == 2) {
          tft.drawString(Net2SSIDString, 80, 78, 1);
          if (PassConnect == 1) {
            WiFi.begin(Net2SSIDString.c_str(), NetPassString.c_str());
            PassConnect = 2;
            tft.setTextColor(TFT_BLACK);
            tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          }
        } else if (NetToConnect == 3) {
          tft.drawString(Net3SSIDString, 80, 78, 1);
          if (PassConnect == 1) {
            WiFi.begin(Net3SSIDString.c_str(), NetPassString.c_str());
            PassConnect = 2;
            tft.setTextColor(TFT_BLACK);
            tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          }
        } else if (NetToConnect == 4) {
          tft.drawString(Net4SSIDString, 80, 78, 1);
          if (PassConnect == 1) {
            WiFi.begin(Net4SSIDString.c_str(), NetPassString.c_str());
            PassConnect = 2;
            tft.setTextColor(TFT_BLACK);
            tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          }
        } else if (NetToConnect == 5) {
          tft.drawString(Net5SSIDString, 80, 78, 1);
          if (PassConnect == 1) {
            WiFi.begin(Net5SSIDString.c_str(), NetPassString.c_str());
            PassConnect = 2;
            tft.setTextColor(TFT_BLACK);
            tft.fillRect(1, 1, 158, 126, TFT_BLACK);
          }
        }
        tft.setTextDatum(TL_DATUM);
      }
      if (PassConnect == 2) {
        if (WiFi.status() != WL_CONNECTED && cMillis - PassConnectingMillis >= 400) {
          PassConnectingMillis = cMillis;
          tft.setFreeFont(&FreeSansBold9pt7b);
          tft.setTextColor(TFT_WHITE, TFT_BLACK);
          tft.setCursor(20, 20);
          tft.print("-Cancel-");
          tft.setTextColor(TFT_RED, TFT_BLACK);
          tft.setCursor(26, 55);
          tft.print("Connecting");
          tft.setTextFont(4);
          if (dot == 0) {
            dot = 1;
            tft.setCursor(66, 70);
            tft.print(".   ");
          } else if (dot == 1) {
            dot = 2;
            tft.setCursor(66, 70);
            tft.print("..  ");
          } else if (dot == 2) {
            dot = 0;
            tft.setCursor(66, 70);
            tft.print("...");
          }
        } else if (WiFi.status() == WL_CONNECTED) {
          SettingsMaxSelect = 1;
          screen = "ConnectedSave";
          clearScreen = 0;
        }
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Saved Network Settings  */
  else if (screen == "SavedNet") {
    if (clearScreen < 2 && cMillis - SavedNetScreenMillis0 >= 50) {
      SavedNetScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SavedNetScreenMillis1 >= 50) {
      SavedNetScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_BLUE);
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(20, 20);
      tft.print("-Back-");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setCursor(20, 40);
      tft.print("1");
      tft.setCursor(20, 60);
      tft.print("2");
      tft.setCursor(20, 80);
      tft.print("3");
      tft.setCursor(20, 100);
      tft.print("4");
      tft.setCursor(20, 120);
      tft.print("5");
      tft.setTextFont(1);
      tft.setCursor(35, 32);
      tft.print(SavedNet1SSIDString);
      tft.setCursor(35, 52);
      tft.print(SavedNet2SSIDString);
      tft.setCursor(35, 72);
      tft.print(SavedNet3SSIDString);
      tft.setCursor(35, 92);
      tft.print(SavedNet4SSIDString);
      tft.setCursor(35, 112);
      tft.print(SavedNet5SSIDString);
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Saved Net Edit Settings  */
  else if (screen == "SavedNetEdit") {
    if (clearScreen < 2 && cMillis - SavedNetEditScreenMillis0 >= 50) {
      SavedNetEditScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SavedNetEditScreenMillis1 >= 100) {
      SavedNetEditScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_BLUE);
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(20, 20);
      tft.print("-Back-");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setCursor(20, 40);
      tft.print("Connect");
      tft.setCursor(20, 60);
      tft.print("AutoCon");
      tft.setCursor(20, 80);
      tft.print("Delete Net");

      AutoConnectEdit();
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Saved WiFi Connecting  */
  else if (screen == "SavedWiFiConnecting") {
    if (clearScreen < 2 && cMillis - SavedWiFiScreenMillis0 >= 50) {
      SavedWiFiScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        dot = 0;
        WiFi.disconnect();
        Network = "OFF";
        SavedConnecting = 0;
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SavedWiFiScreenMillis1 >= 100) {
      SavedWiFiScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_BLUE);
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(20, 20);
      tft.print("-Cancel-");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);

      if (WiFi.status() != WL_CONNECTED && cMillis - SavedConnectingMillis >= 400) {
        SavedConnectingMillis = cMillis;
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(26, 55);
        tft.print("Connecting");
        tft.setTextFont(4);
        if (dot == 0) {
          dot = 1;
          tft.setCursor(66, 70);
          tft.print(".   ");
        } else if (dot == 1) {
          dot = 2;
          tft.setCursor(66, 70);
          tft.print("..  ");
        } else if (dot == 2) {
          dot = 0;
          tft.setCursor(66, 70);
          tft.print("...");
        }
      } else if (WiFi.status() == WL_CONNECTED) {
        screen = "Connected";
        clearScreen = 0;
      }
      if (SavedConnecting == 0) {
        AutoConnectEdit();
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////*  Deleted  */
  else if (screen == "Deleted") {
    if (clearScreen < 31 && cMillis - DeletedScreenMillis >= 50) {
      DeletedScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(25, 45, 100, 40, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(25, 45, 100, 40, 8, TFT_YELLOW);
        tft.setTextColor(TFT_RED);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(35, 70);
        tft.print("Deleted");
      } else if (clearScreen == 20) {
        screen = "SavedNet";
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Settings  */
  else if (screen == "FilamentMainSettings") {
    if (clearScreen < 2 && cMillis - FilamentMainSettingsScreenMillis0 >= 20) {
      FilamentMainSettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 0, 159, 128, TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("Back");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Materials");
        tft.setCursor(20, 60);
        tft.print("Spool Edit");
        tft.setCursor(20, 80);
        tft.print("Fil. Runout");
        tft.setCursor(20, 100);
        tft.print("Fil. Jams");
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(38, 120);
        tft.print("Filament");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - FilamentMainSettingsScreenMillis1 >= 20) {
      FilamentMainSettingsScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Materials Edit  */
  else if (screen == "MaterialsEdit") {
    if (clearScreen < 2 && cMillis - MaterialsEditScreenMillis0 >= 50) {
      MaterialsEditScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        if (SettingsSelect < 6){
          while (SettingsBarY != 0){
            SettingsBarY = SettingsBarY - 1;
            tft.drawLine(159, SettingsBarY, 159, SettingsBarY + 64, TFT_MAGENTA);
            tft.drawLine(159, SettingsBarY + 65, 159, SettingsBarY + 65, TFT_YELLOW);
            delay(3);
        }
        } else if (SettingsSelect > 5){
          while (SettingsBarY != 64){
            SettingsBarY = SettingsBarY + 1;
            tft.drawLine(159, SettingsBarY, 159, SettingsBarY + 64, TFT_MAGENTA);
            tft.drawLine(159, SettingsBarY - 1, 159, SettingsBarY - 1, TFT_YELLOW);
            delay(3);
        }
        }
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - MaterialsEditScreenMillis1 >= 100) {
      MaterialsEditScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_BLUE);
      tft.setFreeFont(&FreeSansBold9pt7b);
      if (SettingsSelect < 6) {
        tft.drawLine(159, 0, 159, 64, TFT_MAGENTA);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("PLA");
        tft.setCursor(20, 60);
        tft.print("PETG");
        tft.setCursor(20, 80);
        tft.print("ABS");
        tft.setCursor(20, 100);
        tft.print("TPU");
        tft.setCursor(20, 120);
        tft.print("Nylon");
      }
      if (SettingsSelect > 5) {
        tft.drawLine(159, 64, 159, 128, TFT_MAGENTA);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 20);
        tft.print("PVA");
        tft.setCursor(20, 40);
        tft.print("HIPS");
        tft.setCursor(20, 60);
        tft.print("ASA");
        tft.setCursor(20, 80);
        tft.print("PC");
        tft.setCursor(20, 100);
        tft.print("Custom 1");
        tft.setCursor(20, 120);
        tft.print("Custom 2");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit PLA  */
  else if (screen == "EditPLA") {
    if (clearScreen < 2 && cMillis - EditPLAScreenMillis0 >= 50) {
      EditPLAScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditPLAScreenMillis1 >= 100) {
      EditPLAScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent PLA");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(PLAFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float PLAFW = PLAFL * PLALW;
      if (PLAFW < 1000.00){
        tft.print(PLAFL, 0);
        tft.print("g");
      } else {
        tft.print(PLAFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit PETG  */
  else if (screen == "EditPETG") {
    if (clearScreen < 2 && cMillis - EditPETGScreenMillis0 >= 50) {
      EditPETGScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditPETGScreenMillis1 >= 100) {
      EditPETGScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent PETG");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(PETGFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float PETGFW = PETGFL * PETGLW;
      if (PETGFW < 1000.00){
        tft.print(PETGFL, 0);
        tft.print("g");
      } else {
        tft.print(PETGFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit ABS  */
  else if (screen == "EditABS") {
    if (clearScreen < 2 && cMillis - EditABSScreenMillis0 >= 50) {
      EditABSScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditABSScreenMillis1 >= 100) {
      EditABSScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent ABS");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(ABSFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float ABSFW = ABSFL * ABSLW;
      if (ABSFW < 1000.00){
        tft.print(ABSFL, 0);
        tft.print("g");
      } else {
        tft.print(ABSFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit TPU  */
  else if (screen == "EditTPU") {
    if (clearScreen < 2 && cMillis - EditTPUScreenMillis0 >= 50) {
      EditTPUScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditTPUScreenMillis1 >= 100) {
      EditTPUScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent TPU");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(TPUFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float TPUFW = TPUFL * TPULW;
      if (TPUFW < 1000.00){
        tft.print(TPUFL, 0);
        tft.print("g");
      } else {
        tft.print(TPUFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit Nylon  */
  else if (screen == "EditNylon") {
    if (clearScreen < 2 && cMillis - EditNylonScreenMillis0 >= 50) {
      EditNylonScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditNylonScreenMillis1 >= 100) {
      EditNylonScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent Nylon");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(NylonFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float NylonFW = NylonFL * NylonLW;
      if (NylonFW < 1000.00){
        tft.print(NylonFL, 0);
        tft.print("g");
      } else {
        tft.print(NylonFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit PVA  */
  else if (screen == "EditPVA") {
    if (clearScreen < 2 && cMillis - EditPVAScreenMillis0 >= 50) {
      EditPVAScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditPVAScreenMillis1 >= 100) {
      EditPVAScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent PVA");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(PVAFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float PVAFW = PVAFL * PVALW;
      if (PVAFW < 1000.00){
        tft.print(PVAFL, 0);
        tft.print("g");
      } else {
        tft.print(PVAFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit HIPS  */
  else if (screen == "EditHIPS") {
    if (clearScreen < 2 && cMillis - EditHIPSScreenMillis0 >= 50) {
      EditHIPSScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditHIPSScreenMillis1 >= 100) {
      EditHIPSScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent HIPS");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(HIPSFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float HIPSFW = HIPSFL * HIPSLW;
      if (HIPSFW < 1000.00){
        tft.print(HIPSFL, 0);
        tft.print("g");
      } else {
        tft.print(HIPSFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit ASA  */
  else if (screen == "EditASA") {
    if (clearScreen < 2 && cMillis - EditASAScreenMillis0 >= 50) {
      EditASAScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditASAScreenMillis1 >= 100) {
      EditASAScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent ASA");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(ASAFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float ASAFW = ASAFL * ASALW;
      if (ASAFW < 1000.00){
        tft.print(ASAFL, 0);
        tft.print("g");
      } else {
        tft.print(ASAFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit PC  */
  else if (screen == "EditPC") {
    if (clearScreen < 2 && cMillis - EditPCScreenMillis0 >= 50) {
      EditPCScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditPCScreenMillis1 >= 100) {
      EditPCScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent PC");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(PCFL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float PCFW = PCFL * PCLW;
      if (PCFW < 1000.00){
        tft.print(PCFL, 0);
        tft.print("g");
      } else {
        tft.print(PCFL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit Custom1  */
  else if (screen == "EditCustom1") {
    if (clearScreen < 2 && cMillis - EditCustom1ScreenMillis0 >= 50) {
      EditCustom1ScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditCustom1ScreenMillis1 >= 100) {
      EditCustom1ScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent Custom1");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(Custom1FL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float Custom1FW = Custom1FL * Custom1LW;
      if (Custom1FW < 1000.00){
        tft.print(Custom1FL, 0);
        tft.print("g");
      } else {
        tft.print(Custom1FL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit Custom2  */
  else if (screen == "EditCustom2") {
    if (clearScreen < 2 && cMillis - EditCustom2ScreenMillis0 >= 50) {
      EditCustom2ScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Density g / m");
        tft.setCursor(20, 60);
        tft.print("Cost ");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - EditCustom2ScreenMillis1 >= 100) {
      EditCustom2ScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(70, 45);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(70, 45, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(100, 60);
      tft.print(" / kg");
      tft.setTextColor(TFT_RED);
      tft.setCursor(20, 80);
      tft.print("Spent Custom2");
      
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
      tft.setTextFont(2);
      tft.setCursor(20, 85);
      tft.print(Custom2FL, 0);
      tft.print("m");

      tft.setCursor(20, 105); 
      float Custom2FW = Custom2FL * Custom2LW;
      if (Custom2FW < 1000.00){
        tft.print(Custom2FL, 0);
        tft.print("g");
      } else {
        tft.print(Custom2FL / 1000.00, 0);
        tft.print("kg");
      }
    }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit Materials Density  */
  else if (screen == "Density") {
    if (clearScreen < 2 && cMillis - DensityScreenMillis0 >= 50) {
      DensityScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - DensityScreenMillis1 >= 100) {
      DensityScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_BLUE);
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setCursor(20, 20);
      tft.print("-Back-");
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setCursor(90, 40);
      tft.print("g/cm3");
      tft.setCursor(90, 60);
      tft.print("g/m");
      tft.setTextColor(TFT_GREEN);
      tft.setCursor(20, 83);
      tft.print("Save");
      tft.setTextColor(TFT_YELLOW);
      tft.setCursor(20, 110);
      tft.print(EditMaterial);
      tft.print(" Density");

      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(20, 28);
      tft.print(Densitycm3Edit);
      tft.setCursor(20, 48);
      tft.print(DensitymEdit);
      if (DensitymEdit < 10.00){
        tft.print(" ");
      }
      tft.setTextSize(1);
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Material Save  */
  else if (screen == "MaterialSave") {
    if (clearScreen < 31 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(30, 45, 100, 40, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(30, 45, 100, 40, 8, LightGreen);
        tft.setTextColor(LightGreen);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(50, 70);
        tft.print("Saved");
      } else if (clearScreen == 10) {
        screen = "Edit" + EditMaterial;
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 2;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Edit Materials Cost  */
  else if (screen == "MaterialCostEdit") {
    if (clearScreen < 2 && cMillis - DensityScreenMillis0 >= 50) {
      DensityScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(125, 40);
        tft.print("/kg");
        tft.setTextColor(TFT_GREEN);
        tft.setCursor(20, 63);
        tft.print("Save");
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(20, 110);
        tft.print(EditMaterial);
        tft.print(" Cost");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - DensityScreenMillis1 >= 100) {
      DensityScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(20, 28);
      tft.print(CostkgEdit);
      if (CostkgEdit < 10.00){
        tft.print(" ");
      }
      tft.setTextSize(1);

      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(90, 25);
      if (CurrencyChange == 1){
        CurrencyChange = 0;
        if (Currency == "$"){
        tft.print(" $   ");
      } else if (Currency == "E"){
        tft.print("       ");
        tft.pushImage(90, 25, 18, 18, EuroIcon);
      } else if (Currency == "P"){
        tft.print("       ");
        tft.pushImage(90, 25, 18, 18, PoundIcon);
      } else if (Currency == "A$"){
        tft.print("A$");
      } else if (Currency == "C$"){
        tft.print("C$");
      }
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Spool Select Settings  */
  else if (screen == "FilSpoolSelectSettings") {
    if (clearScreen < 2 && cMillis - FilSpoolSelectSettingsScreenMillis0 >= 5) {
      FilSpoolSelectSettingsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);

        for (int i = 0; i < 5; i++) {
          tft.setCursor(20, ((i + 1) * 20) + 20);
          tft.print(i + 1);
          tft.print(". ");

          if (SpoolMaterial[i] == 1) {
            CurSpoolMatText = "PLA";
          } else if (SpoolMaterial[i] == 2) {
            CurSpoolMatText = "PETG";
          } else if (SpoolMaterial[i] == 3) {
            CurSpoolMatText = "ABS";
          } else if (SpoolMaterial[i] == 4) {
            CurSpoolMatText = "TPU";
          } else if (SpoolMaterial[i] == 5) {
            CurSpoolMatText = "Nylon";
          } else if (SpoolMaterial[i] == 6) {
            CurSpoolMatText = "PVA";
          } else if (SpoolMaterial[i] == 7) {
            ;
            CurSpoolMatText = "HIPS";
          } else if (SpoolMaterial[i] == 8) {
            CurSpoolMatText = "ASA";
          } else if (SpoolMaterial[i] == 9) {
            CurSpoolMatText = "PC";
          } else if (SpoolMaterial[i] == 10) {
            CurSpoolMatText = "Custom1";
          } else if (SpoolMaterial[i] == 11) {
            CurSpoolMatText = "Custom2";
          }
          tft.print(CurSpoolMatText);
        }
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - FilSpoolSelectSettingsScreenMillis1 >= 10) {
      FilSpoolSelectSettingsScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Spool Edit Settings  */
  else if (screen == "SpoolEdit") {
    if (clearScreen < 2 && cMillis - SpoolEditScreenMillis0 >= 5) {
      SpoolEditScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 40);
        tft.print("Mat:");
        tft.setCursor(20, 60);
        tft.print("Weight:");
        tft.setCursor(20, 80);
        tft.print("Reset Spool");
        tft.setCursor(40, 120);
        tft.setTextColor(TFT_YELLOW);
        tft.print(SpoolEditSelect);
        tft.println(". Spool");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SpoolEditScreenMillis1 >= 10) {
      SpoolEditScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);

      SettingsSelectVoid();

      tft.setTextFont(1);
      tft.setTextSize(2);

      if (SpoolMaterial[SpoolEditSelect - 1] == 1) {
        CurSpoolMatText = "PLA    ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 2) {
        CurSpoolMatText = "PETG   ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 3) {
        CurSpoolMatText = "ABS    ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 4) {
        CurSpoolMatText = "TPU    ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 5) {
        CurSpoolMatText = "Nylon  ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 6) {
        CurSpoolMatText = "PVA    ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 7) {
        ;
        CurSpoolMatText = "HIPS   ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 8) {
        CurSpoolMatText = "ASA    ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 9) {
        CurSpoolMatText = "PC     ";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 10) {
        CurSpoolMatText = "Custom1";
      } else if (SpoolMaterial[SpoolEditSelect - 1] == 11) {
        CurSpoolMatText = "Custom2";
      }
      Material = CurSpoolMatText;

      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setCursor(65, 27);
      tft.print(CurSpoolMatText);
      tft.setCursor(90, 47);
      if (SpoolEditSelect == 1) {
        tft.print(Spool1Weight);
        if (Spool1Weight < 100) {
          tft.println("  ");
        } else if (Spool1Weight < 1000) {
          tft.println(" ");
        }
        tft.setCursor(30, 87);
        tft.print(Spool1Percentage);
      } else if (SpoolEditSelect == 2) {
        tft.print(Spool2Weight);
        if (Spool2Weight < 100) {
          tft.println("  ");
        } else if (Spool2Weight < 1000) {
          tft.println(" ");
        }
        tft.setCursor(30, 87);
        tft.print(Spool2Percentage);
      } else if (SpoolEditSelect == 3) {
        tft.print(Spool3Weight);
        if (Spool3Weight < 100) {
          tft.println("  ");
        } else if (Spool3Weight < 1000) {
          tft.println(" ");
        }
        tft.setCursor(30, 87);
        tft.print(Spool3Percentage);
      } else if (SpoolEditSelect == 4) {
        tft.print(Spool4Weight);
        if (Spool4Weight < 100) {
          tft.println("  ");
        } else if (Spool4Weight < 1000) {
          tft.println(" ");
        }
        tft.setCursor(30, 87);
        tft.print(Spool4Percentage);
      } else if (SpoolEditSelect == 5) {
        tft.print(Spool5Weight);
        if (Spool5Weight < 100) {
          tft.println("  ");
        } else if (Spool5Weight < 1000) {
          tft.println(" ");
        }
        tft.setCursor(30, 87);
        tft.print(Spool5Percentage);
      }
      tft.print("% Left");
      tft.setCursor(142, 47);
      tft.print("g");

      tft.setTextSize(1);
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Reset Spool  */
  else if (screen == "ResetSpool") {
    if (clearScreen < 31 && cMillis - ResetSpoolScreenMillis >= 50) {
      ResetSpoolScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(25, 40, 110, 50, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(25, 40, 110, 50, 8, LightRed);
        tft.setTextColor(LightRed);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(44, 60);
        tft.print("Spool ");
        tft.print(SpoolEditSelect);
        tft.print(".");
        tft.setCursor(53, 80);
        tft.print("Reset");
      } else if (clearScreen == 20) {
        if (SpoolEditSelect == 1) {
          Spool1FW = Spool1Weight;
        } else if (SpoolEditSelect == 2) {
          Spool2FW = Spool2Weight;
        } else if (SpoolEditSelect == 3) {
          Spool3FW = Spool3Weight;
        } else if (SpoolEditSelect == 4) {
          Spool4FW = Spool4Weight;
        } else if (SpoolEditSelect == 5) {
          Spool5FW = Spool5Weight;
        }
        screen = "FilSpoolSelectSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Runout Sensor Settings  */
  else if (screen == "FilRunout") {
    if (clearScreen < 2 && cMillis - FilRunoutScreenMillis0 >= 5) {
      FilRunoutScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("Back");
        tft.setTextColor(TFT_GREEN);
        tft.setCursor(20, 40);
        tft.print("ON");
        tft.setTextColor(TFT_RED);
        tft.setCursor(20, 60);
        tft.print("OFF");
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(42, 100);
        tft.print("Filament");
        tft.setCursor(18, 120);
        tft.print("Runout Sensor");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - FilRunoutScreenMillis1 >= 20) {
      FilRunoutScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Sensor Save  */
  else if (screen == "FilSensorSave") {
    if (clearScreen < 31 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(30, 45, 100, 40, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(30, 45, 100, 40, 8, LightGreen);
        tft.setTextColor(LightGreen);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(52, 70);
        tft.print("Saved");
      } else if (clearScreen == 20) {
        screen = "FilamentMainSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 4;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  No Filament  */
  else if (screen == "NoFilament") {
    if (clearScreen < 51 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(10, 15, 140, 100, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(10, 15, 140, 100, 8, LightRed);
        tft.setTextColor(LightRed);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextDatum(TC_DATUM);
        tft.setCursor(28, 35);
        tft.print("No Filament");
        tft.setCursor(42, 55);
        tft.print("Detected");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(36, 85);
        tft.print("3D Printer");
        tft.setCursor(32, 105);
        tft.print("Power OFF");
      } else if (clearScreen == 50) {
        tft.fillRect(30, 70, 100, 40, TFT_BLACK);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(43, 85);
        tft.print("Click To");
        tft.setCursor(37, 105);
        tft.print("Power ON");
      }
      tft.setTextDatum(TL_DATUM);
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Loaded  */
  else if (screen == "FilamentLoaded") {
    if (clearScreen < 51 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(10, 15, 140, 100, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(10, 15, 140, 100, 8, LightGreen);
        tft.setTextColor(LightGreen);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(42, 35);
        tft.print("Filament");
        tft.setCursor(48, 55);
        tft.print("Loaded");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(36, 85);
        tft.print("3D Printer");
        tft.setCursor(36, 105);
        tft.print("Power ON");
        if (AlertsSound == 1){
          ledcWriteTone(3, 523);
        }
      } else if (clearScreen == 5 && AlertsSound == 1) {
        ledcWriteTone(3, 587);
      } else if (clearScreen == 9 && AlertsSound == 1) {
        ledcWriteTone(3, 659);
      } else if (clearScreen == 13 && AlertsSound == 1) {
        ledcWriteTone(3, 0);
      } else if (clearScreen == 50) {
        screen = "HomeScreen";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 4;
        clearScreen = - 1;
        CurrencyChange = 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Jams Sensor Settings  */
  else if (screen == "FilJams") {
    if (clearScreen < 2 && cMillis - FilJamsScreenMillis0 >= 5) {
      FilJamsScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillScreen(TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("Back");
        tft.setTextColor(TFT_GREEN);
        tft.setCursor(20, 40);
        tft.print("ON");
        tft.setTextColor(TFT_RED);
        tft.setCursor(20, 60);
        tft.print("OFF");
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(42, 100);
        tft.print("Filament");
        tft.setCursor(22, 120);
        tft.print("Jams Sensor");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - FilRunoutScreenMillis1 >= 20) {
      FilRunoutScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Printing ON  */
  else if (screen == "PrintingON") {
    if (clearScreen < 51 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(10, 45, 140, 40, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(10, 45, 140, 40, 8, LightGreen);
        tft.setTextColor(LightGreen);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(30, 70);
        tft.print("Printing ON");
        if (PrintingSound == 1){
          ledcWriteTone(3, 523);
        }
      } else if (clearScreen == 5 && PrintingSound == 1) {
        ledcWriteTone(3, 587);
      } else if (clearScreen == 9 && PrintingSound == 1) {
        ledcWriteTone(3, 659);
      } else if (clearScreen == 13 && PrintingSound == 1) {
        ledcWriteTone(3, 0);
      } else if (clearScreen == 30) {
        screen = PrevScreen;
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 4;
        clearScreen = - 1;
        CurrencyChange = 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Printing OFF  */
  else if (screen == "PrintingOFF") {
    if (clearScreen < 51 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(10, 45, 140, 40, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(10, 45, 140, 40, 8, LightRed);
        tft.setTextColor(LightRed);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(25, 70);
        tft.print("Printing OFF");
        if (PrintingSound == 1){
          ledcWriteTone(3, 659);
        }
      } else if (clearScreen == 5 && PrintingSound == 1) {
        ledcWriteTone(3, 587);
      } else if (clearScreen == 9 && PrintingSound == 1) {
        ledcWriteTone(3, 523);
      } else if (clearScreen == 13 && PrintingSound == 1) {
        ledcWriteTone(3, 0);
      } else if (clearScreen == 30) {
        screen = PrevScreen;
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 4;
        clearScreen = - 1;
        CurrencyChange = 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Jam Detected  */
  else if (screen == "FilJamDetected") {
    if (clearScreen < 51 && cMillis - FilJamScreenMillis0 >= 50) {
      FilJamScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(10, 15, 140, 100, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(10, 15, 140, 100, 8, LightRed);
        tft.setTextColor(LightRed);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(47, 35);
        tft.print("Fil. Jam");
        tft.setCursor(42, 55);
        tft.print("Detected");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(36, 85);
        tft.print("3D Printer");
        tft.setCursor(32, 105);
        tft.print("Power OFF");
      }
      if (clearScreen == 50) {
        tft.fillRect(30, 70, 100, 40, TFT_BLACK);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(43, 85);
        tft.print("Click To");
        tft.setCursor(37, 105);
        tft.print("Power ON");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 51 && cMillis - AutoOffScreenMillis1 >= 20) {
      AutoOffScreenMillis1 = cMillis;
    }
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Automatic OFF  */
  else if (screen == "AutoOff") {
    if (clearScreen < 2 && cMillis - AutoOffScreenMillis0 >= 5) {
      AutoOffScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 0, 159, 128, TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(20, 20);
        tft.print("Back");
        tft.setTextColor(TFT_GREEN);
        tft.setCursor(20, 40);
        tft.print("ON");
        tft.setTextColor(TFT_RED);
        tft.setCursor(20, 60);
        tft.print("OFF");
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.setCursor(20, 80);
        tft.print("Start After");
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(40, 120);
        tft.print("Auto Off");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - AutoOffScreenMillis1 >= 20) {
      AutoOffScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.setCursor(40, 87);
      tft.print(AutoOffMillis / 3600000);  // // - DIV
      tft.println("h  ");
      tft.setCursor(90, 87);
      tft.print((AutoOffMillis % 3600000) / 60000);  // % - MOD
      tft.println("m  ");
      tft.setTextSize(1);
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  AutoOff Save  */
  else if (screen == "AutoOffSave") {
    if (clearScreen < 31 && cMillis - SaveScreenMillis >= 50) {
      SaveScreenMillis = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(30, 45, 100, 40, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(30, 45, 100, 40, 8, TFT_GREEN);
        tft.setTextColor(TFT_GREEN);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(53, 70);
        tft.print("Saved");
      } else if (clearScreen == 20) {
        screen = "MainSettings";
        SettingsSelect = 0;
        SettingsCounter = 0;
        SettingsMaxSelect = 11;
        clearScreen = - 1;
      }
      clearScreen = clearScreen + 1;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Automatic Off Screen  */
  else if (screen == "AutoOffScreen") {
    if (clearScreen < 51 && cMillis - AutoOFFScreenMillis0 >= 50) {
      AutoOFFScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRoundRect(10, 15, 140, 100, 8, TFT_BLACK);
      } else if (clearScreen == 1) {
        tft.drawRoundRect(10, 15, 140, 100, 8, LightRed);
        tft.setTextColor(LightRed);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setCursor(42, 35);
        tft.print("Auto Off");
        tft.setCursor(33, 55);
        tft.print("Print Done");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(36, 85);
        tft.print("3D Printer");
        tft.setCursor(32, 105);
        tft.print("Power OFF");
      }
      if (clearScreen == 50) {
        tft.fillRect(30, 70, 100, 40, TFT_BLACK);
        tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(43, 85);
        tft.print("Click To");
        tft.setCursor(37, 105);
        tft.print("Power ON");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 51 && cMillis - AutoOFFScreenMillis1 >= 20) {
      AutoOFFScreenMillis1 = cMillis;
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Brightness Settings  */
  else if (screen == "Brightness") {
    if (clearScreen < 2 && cMillis - BrightnessScreenMillis0 >= 5) {
      BrightnessScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 0, 159, 128, TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(Purple);
        tft.setCursor(50, 100); tft.print("Screen");
        tft.setCursor(32, 120); tft.print("Brightness");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - BrightnessScreenMillis1 >= 20) {
      BrightnessScreenMillis1 = cMillis;

      tft.setTextColor(LightRed, TFT_BLACK);
      tft.setTextFont(4);
      tft.setCursor(80, 25);
      tft.print(BrightnessPercentage);
      tft.print("%   ");

      ScreenLEDA = map(BrightnessPercentage, 0, 100, 0, 255);
      ledcAnalogWrite(CHANNEL_SCREEN, ScreenLEDA);

      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      if (SettingsSelect == 0){
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Level:");
        tft.setCursor(15, 60); tft.print("Save");
      } else if (SettingsSelect == 1){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("Level:");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 60); tft.print("Save");
      } else if (SettingsSelect == 2){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("Save");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("Level:");
      }
    }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Sound Settings  */
  else if (screen == "Sound") {
    if (clearScreen < 2 && cMillis - SoundScreenMillis0 >= 5) {
      SoundScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 0, 159, 128, TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(Purple);
        tft.setCursor(35, 120);
        tft.print("Sound");
        tft.pushImage(100, 105, 21, 18, Sound);
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - SoundScreenMillis1 >= 20) {
      SoundScreenMillis1 = cMillis;

      tft.setTextFont(1);
      tft.setTextSize(2);

      tft.setCursor(105, 27);
      if (OnClickSound == 1){
        tft.setTextColor(LightGreen, TFT_BLACK);
        tft.print("ON  ");
      } else {
        tft.setTextColor(LightRed, TFT_BLACK);
        tft.print("OFF");
      }
      tft.setCursor(105, 47);
      if (AlertsSound == 1){
        tft.setTextColor(LightGreen, TFT_BLACK);
        tft.print("ON  ");
      } else {
        tft.setTextColor(LightRed, TFT_BLACK);
        tft.print("OFF");
      }
      tft.setCursor(105, 67);
      if (PrintingSound == 1){
        tft.setTextColor(LightGreen, TFT_BLACK);
        tft.print("ON  ");
      } else {
        tft.setTextColor(LightRed, TFT_BLACK);
        tft.print("OFF");
      }
      tft.setTextSize(1);

      tft.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      if (SettingsSelect == 0){
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("On Click");
        tft.setCursor(15, 60); tft.print("Alerts");
        tft.setCursor(15, 80); tft.print("Printing");
      } else if (SettingsSelect == 1){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 40); tft.print("On Click");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 60); tft.print("Alerts");
        tft.setCursor(15, 80); tft.print("Printing");
      } else if (SettingsSelect == 2){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 60); tft.print("Alerts");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("On Click");
        tft.setCursor(15, 80); tft.print("Printing");
      } else if (SettingsSelect == 3){
        tft.setTextColor(Purple);
        tft.setCursor(15, 20); tft.print("Back");
        tft.setTextColor(LightGreen);
        tft.setCursor(15, 80); tft.print("Printing");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(15, 40); tft.print("On Click");
        tft.setCursor(15, 60); tft.print("Alerts");
      }
    }
  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Auto Scroll  */
  else if (screen == "AutoScroll") {
    if (clearScreen < 2 && cMillis - AutoScrollScreenMillis0 >= 5) {
      AutoScrollScreenMillis0 = cMillis;
      if (clearScreen == 0) {
        tft.fillRect(1, 1, 158, 126, TFT_BLACK);
      } else if (clearScreen == 1) {

        tft.setTextColor(TFT_BLUE);
        tft.setFreeFont(&FreeSansBold9pt7b);
        tft.setCursor(20, 20);
        tft.print("-Back-");
        tft.setTextColor(TFT_WHITE);
        tft.setCursor(20, 40);
        tft.print("OFF");
        tft.setCursor(20, 60);
        tft.print("3 Screens");
        tft.setCursor(20, 80);
        tft.print("All Screens");
        tft.setCursor(20, 100);
        tft.print("Start:");
        tft.setTextColor(TFT_YELLOW);
        tft.setCursor(24, 120);
        tft.print("Auto Scroll");
      }
      clearScreen = clearScreen + 1;
    }

    if (clearScreen == 2 && cMillis - AutoScrollScreenMillis1 >= 20) {
      AutoScrollScreenMillis1 = cMillis;
      tft.setTextColor(TFT_WHITE, TFT_BLACK);
      tft.setFreeFont(&FreeSansBold9pt7b);

      SettingsSelectVoid();

      tft.setTextColor(TFT_RED, TFT_BLACK);
      tft.setTextFont(1);
      tft.setTextSize(2);
      tft.setCursor(90, 87);
      if (AutoScrollMillis < 60000){
        tft.print(AutoScrollMillis / 1000);
        tft.print("s ");
      } else if (AutoScrollMillis >= 60000){
        tft.print(AutoScrollMillis / 60000);
        tft.print("m ");
      }
      tft.setTextSize(1);
    }
  }

UpdateButtonVoid();

}
