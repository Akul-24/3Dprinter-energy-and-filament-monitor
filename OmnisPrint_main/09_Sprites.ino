void SpriteDefine(){

  if (screen == "HomeScreen" || LastScreen == "HomeScreen"){
    voltage1.setTextColor(Purple, TFT_BLACK);
    voltage1.createSprite(50, 16);
    voltage1.fillSprite(TFT_BLACK);
    voltage1.drawString("Voltage", 2, 0, 2);

    current1.setTextColor(Purple, TFT_BLACK);
    current1.createSprite(50, 16);
    current1.fillSprite(TFT_BLACK);
    current1.drawString("Current", 2, 0, 2);

    cost1.setTextColor(Purple, TFT_BLACK);
    cost1.createSprite(68, 16);
    cost1.fillSprite(TFT_BLACK);
    cost1.drawString("Total Cost", 2, 0, 2);
  

    voltage2.createSprite(68, 26);
    voltage2.fillSprite(TFT_BLACK);
    voltage2.setTextFont(4);
    voltage2.setCursor(2, 0);
    if (U < 10.00) {
        voltage2.print(U);
      } else {
        voltage2.print(U,1);
      }
      voltage2.println("V   ");

    current2.createSprite(69, 26); //66
    current2.fillSprite(TFT_BLACK);
    current2.setTextFont(4);
    current2.setCursor(2, 0);
      if (I < 10.00) {
        current2.print(I);
      } else {
        current2.print(I,1);
      }
      current2.println("A");
  
    cost2.createSprite(75, 26);
    cost2.fillSprite(TFT_BLACK);
    cost2.setTextFont(4);
    cost2.setCursor(2, 0);
    if (C < 10.00) {
          cost2.drawFloat(C, 3, 2, 0, 4);
        } else if (C >= 10.00 && E < 100.00){
          cost2.drawFloat(C, 2, 2, 0, 4);
        } else if (C >= 100.00 && E < 1000.00){
          cost2.drawFloat(C, 1, 2, 0, 4);
        } else if (C >= 1000.00){
          cost2.drawNumber(C, 2, 0, 4);
        }

    CurrencySprite.createSprite(26, 16);
    CurrencySprite.fillSprite(TFT_BLACK);
    CurrencySprite.setSwapBytes(true);
    if (Currency == "$"){
      CurrencySprite.pushImage(2, 0, 11, 16, DollarIcon);
    } else if (Currency == "E"){
      CurrencySprite.pushImage(2, 0, 11, 16, EuroIcon);
    } else if (Currency == "P"){
      CurrencySprite.pushImage(2, 0, 11, 16, PoundIcon);
    } else if (Currency == "A$"){
      CurrencySprite.pushImage(2, 0, 22, 16, ADollarIcon);
    } else if (Currency == "C$"){
      CurrencySprite.pushImage(2, 0, 22, 16, CDollarIcon);
    }
  }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy
  if (screen == "Energy" || LastScreen == "Energy"){

    UsedEnergy.createSprite(144, 40);
    UsedEnergy.fillSprite(TFT_BLACK);
    UsedEnergy.setSwapBytes(true);
    UsedEnergy.fillRoundRect(2, 0, 140, 40, 8, GreyBlue);
    UsedEnergy.pushImage(10, 5, 19, 28, LightningBolt);

    UsedEnergy.setTextColor(TFT_WHITE, GreyBlue);
    UsedEnergy.setTextDatum(TR_DATUM);
      if (EnergyUnit == 0) {
        if (E < 10.00) {
          UsedEnergy.drawFloat(E, 4, 113, 1, 4);
        } else if (E >= 10.00 && E < 100.00){
          UsedEnergy.drawFloat(E, 3, 113, 1, 4);
        } else if (E >= 100.00 && E < 1000.00){
          UsedEnergy.drawFloat(E, 2, 113, 1, 4);
        } else if (E >= 1000.00){
          UsedEnergy.drawFloat(E, 1, 113, 1, 4);
        }
        UsedEnergy.drawString("kWh", 139, 6, 2);
     }
     else if (EnergyUnit == 1) {
        if (E * 1000.00 < 10.00) {
          UsedEnergy.drawFloat(E * 1000.00, 4, 113, 1, 4);
        } else if (E * 1000.00 >= 10.00 && E * 1000.00 < 100.00){
          UsedEnergy.drawFloat(E * 1000.00, 3, 113, 1, 4);
        } else if (E * 1000.00 >= 100.00 && E * 1000.00 < 1000.00){
          UsedEnergy.drawFloat(E * 1000.00, 2, 113, 1, 4);
        } else if (E * 1000.00 >= 1000.00){
          UsedEnergy.drawFloat(E * 1000.00, 1, 113, 1, 4);
        }
        UsedEnergy.drawString("Wh", 134, 6, 2);
     }
     else if (EnergyUnit == 2) {
      if (E < 1.00) {
        if (E * 1000.00 < 10.00) {
          UsedEnergy.drawFloat(E * 1000.00, 4, 113, 1, 4);
        } else if (E * 1000.00 >= 10.00 && E * 1000.00 < 100.00){
          UsedEnergy.drawFloat(E * 1000.00, 3, 113, 1, 4);
        } else if (E * 1000.00 >= 100.00 && E * 1000.00 < 1000.00){
          UsedEnergy.drawFloat(E * 1000.00, 2, 113, 1, 4);
        } else if (E * 1000.00 >= 1000.00){
          UsedEnergy.drawFloat(E * 1000.00, 1, 113, 1, 4);
        }
        UsedEnergy.drawString("Wh", 134, 6, 2);
      }
      else {
        if (E < 10.00) {
          UsedEnergy.drawFloat(E, 4, 113, 1, 4);
        } else if (E >= 10.00 && E < 100.00){
          UsedEnergy.drawFloat(E, 3, 113, 1, 4);
        } else if (E >= 100.00 && E < 1000.00){
          UsedEnergy.drawFloat(E, 2, 113, 1, 4);
        } else if (E >= 1000.00){
          UsedEnergy.drawFloat(E, 1, 113, 1, 4);
        }
        UsedEnergy.drawString("kWh", 139, 6, 2);
      }
     }
     UsedEnergy.setTextDatum(TL_DATUM);

    UsedEnergy.setTextColor(Purple, GreyBlue);
    UsedEnergy.drawString("Used Energy", 37, 21, 2);

    Time.setTextColor(Purple, TFT_BLACK);
    Time.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    Time.createSprite(47, 19);
    Time.fillSprite(TFT_BLACK);
    Time.drawString("Time", 2, 0);

    ElectricalCost.setTextColor(Purple, TFT_BLACK);
    ElectricalCost.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    ElectricalCost.createSprite(129, 19);
    ElectricalCost.fillSprite(TFT_BLACK);
    ElectricalCost.drawString("Electrical Cost", 2, 0);

    dtostrf(second(), 2, 0, seconds);
    dtostrf(minute(), 2, 0, minutes);
    dtostrf(hour(), 2, 0, hours);
    dtostrf(day() - 1, 2, 0, days);
    TimeValue.createSprite(144, 16);
    TimeValue.fillSprite(TFT_BLACK);
    TimeValue.setTextFont(2);
    TimeValue.setCursor(119, 0);
    TimeValue.print(seconds);
    TimeValue.println("s");
    TimeValue.setCursor(79, 0);
    TimeValue.print(minutes);
    TimeValue.println("m");
    TimeValue.setCursor(39, 0);
    TimeValue.print(hours);
    TimeValue.println("h");
    TimeValue.setCursor(2, 0);
    TimeValue.print(days);
    TimeValue.println("d");

    ElCostValue.createSprite(81, 26);
    ElCostValue.fillSprite(TFT_BLACK);
      if (EC < 10.00) {
          ElCostValue.drawFloat(EC, 4, 2, 0, 4);
        } else if (EC >= 10.00 && EC < 100.00){
          ElCostValue.drawFloat(EC, 3, 2, 0, 4);
        } else if (EC >= 100.00 && EC < 1000.00){
          ElCostValue.drawFloat(EC, 2, 2, 0, 4);
        } else if (EC >= 1000.00){
          ElCostValue.drawFloat(EC, 1, 2, 0, 4);
        }

    CurrencySprite.createSprite(26, 16);
    CurrencySprite.fillSprite(TFT_BLACK);
    CurrencySprite.setSwapBytes(true);
    if (Currency == "$"){
      CurrencySprite.pushImage(2, 0, 11, 16, DollarIcon);
    } else if (Currency == "E"){
      CurrencySprite.pushImage(2, 0, 11, 16, EuroIcon);
    } else if (Currency == "P"){
      CurrencySprite.pushImage(2, 0, 11, 16, PoundIcon);
    } else if (Currency == "A$"){
      CurrencySprite.pushImage(2, 0, 22, 16, ADollarIcon);
    } else if (Currency == "C$"){
      CurrencySprite.pushImage(2, 0, 22, 16, CDollarIcon);
    }
  }



/////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament
  if (screen == "Filament" || LastScreen == "Filament"){

    FilamentUsed.setTextColor(Purple, GreyBlue);
    FilamentUsed.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    FilamentUsed.createSprite(154, 72);
    FilamentUsed.fillSprite(TFT_BLACK);
    FilamentUsed.setSwapBytes(true);
    FilamentUsed.fillRoundRect(2, 0, 150, 72, 8, GreyBlue);
    FilamentUsed.pushImage(7, 6, 36, 44, GreenFilSpool);
    FilamentUsed.drawString("Filament Used", 35, 53, 2);
    FilamentUsed.setTextColor(TFT_WHITE, GreyBlue);
    FilamentUsed.setTextDatum(TR_DATUM);
    if (FL < 9999.99) {
      FilamentUsed.drawFloat(FL, 2, 133, 3, 4);
    } else {
      FilamentUsed.drawFloat(FL, 1, 133, 3, 4);
    }

      if (FW < 0.99999) {
        FilamentUsed.drawFloat(FW * 1000, 2, 133, 29, 4);
      } else if (FW >= 0.99999 && FW < 9.99999) {
        FilamentUsed.drawFloat(FW, 4, 133, 29, 4);
      } else if (FW >= 9.99999 && FW < 99.99999) {
        FilamentUsed.drawFloat(FW, 3, 133, 29, 4);
      } else if (FW >= 99.99999 && FW < 999.99999) {
        FilamentUsed.drawFloat(FW, 2, 133, 29, 4);
      } else {
        FilamentUsed.drawFloat(FW, 1, 133, 29, 4);
      }

      FilamentUsed.setTextDatum(TL_DATUM);
      FilamentUsed.drawString("m", 135, 7, 2);
      if (FW < 0.99999) {
        FilamentUsed.drawString("g", 135, 33, 2);
      } else {
        FilamentUsed.drawString("kg", 135, 33, 2);
      }

    FilamentCost.setTextColor(Purple, TFT_BLACK);
    FilamentCost.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    FilamentCost.createSprite(44, 19);
    FilamentCost.fillSprite(TFT_BLACK);
    FilamentCost.drawString("Cost", 2, 0);

    FilamentCostV.createSprite(81 + tft.textWidth("-", 4), 26); //81
    FilamentCostV.fillSprite(TFT_BLACK);
    FilamentCostV.setTextFont(4);
    FilamentCostV.setCursor(13, 0);
    if (FC < 10.00) {
      FilamentCostV.drawFloat(FC, 4, 2, 0, 4);
    } else if (FC >= 10.00 && FC < 100.00){
      FilamentCostV.drawFloat(FC, 3, 2, 0, 4);
    } else if (FC >= 100.00 && FC < 1000.00){
      FilamentCostV.drawFloat(FC, 2, 2, 0, 4);
    } else if (FC >= 1000.00){
      FilamentCostV.drawFloat(FC, 1, 2, 0, 4);
    }

    CurrencySprite.createSprite(26, 16);
    CurrencySprite.fillSprite(TFT_BLACK);
    CurrencySprite.setSwapBytes(true);
    if (Currency == "$"){
      CurrencySprite.pushImage(2, 0, 11, 16, DollarIcon);
    } else if (Currency == "E"){
      CurrencySprite.pushImage(2, 0, 11, 16, EuroIcon);
    } else if (Currency == "P"){
      CurrencySprite.pushImage(2, 0, 11, 16, PoundIcon);
    } else if (Currency == "A$"){
      CurrencySprite.pushImage(2, 0, 22, 16, ADollarIcon);
    } else if (Currency == "C$"){
      CurrencySprite.pushImage(2, 0, 22, 16, CDollarIcon);
    }
  }


/////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy 2
  if (screen == "Energy2" || LastScreen == "Energy2"){

    AvgPsprite.createSprite(74, 52);
    AvgPsprite.fillSprite(TFT_BLACK);
    AvgPsprite.fillRoundRect(2, 0, 70, 52, 8, GreyBlue);
    AvgPsprite.setTextColor(Purple);
    AvgPsprite.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    AvgPsprite.setCursor(9, 17);
    AvgPsprite.print("Avg. P");
    AvgPsprite.setTextColor(TFT_WHITE, GreyBlue);
    AvgPsprite.setTextDatum(TR_DATUM);
    AvgPsprite.setTextPadding(tft.textWidth("999", 4));
    AvgPsprite.drawNumber(AvgP, 51, 26, 4);
    AvgPsprite.setTextPadding(0);
    AvgPsprite.drawString("W", 63, 31, 2);
    AvgPsprite.setTextDatum(TL_DATUM);

    MaxPsprite.createSprite(74, 52);
    MaxPsprite.fillSprite(TFT_BLACK);
    MaxPsprite.fillRoundRect(2, 0, 70, 52, 8, GreyBlue);
    MaxPsprite.setTextColor(Purple);
    MaxPsprite.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    MaxPsprite.setCursor(9, 17);
    MaxPsprite.print("Max. P");
    MaxPsprite.setTextColor(TFT_WHITE, GreyBlue);
    MaxPsprite.setTextDatum(TR_DATUM);
    MaxPsprite.setTextPadding(tft.textWidth("999", 4));
    MaxPsprite.drawNumber(MaxP, 51, 26, 4);
    MaxPsprite.setTextPadding(0);
    MaxPsprite.drawString("W", 63, 31, 2);
    MaxPsprite.setTextDatum(TL_DATUM);

    if (PrintingON == 0){
      if (RelayState == 0){
        PrinterSprite.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        PrinterSprite.fillSprite(TFT_BLACK);
        PrinterSprite.setTextColor(Purple);
        PrinterSprite.createSprite(62, 19);
        PrinterSprite.drawString("Printer", 2, 0);

        Off.setTextColor(Purple);
        Off.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        Off.createSprite(32, 19);
        Off.fillSprite(TFT_BLACK);
        Off.drawString("Off", 2, 0);
      } else {
        Standby.setTextColor(Purple);
        Standby.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
        Standby.createSprite(74, 19);
        Standby.fillSprite(TFT_BLACK);
        Standby.drawString("Standby", 2, 0);
      }
    }

    if (PrintingON == 1){
      Printing.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
      Printing.createSprite(71, 19);
      Printing.fillSprite(TFT_BLACK);
      Printing.setTextColor(Purple);
      Printing.drawString("Printing", 2, 0);

      Printsec.setTextDatum(TR_DATUM);
      Printsec.createSprite(28, 16);
      Printsec.fillSprite(TFT_BLACK);
      Printsec.setTextColor(TFT_WHITE);
      Printsec.setTextPadding(tft.textWidth("99", 2));
      Printsec.drawNumber(PrintSec, 18, 0, 2);
      Printsec.setTextPadding(0);
      Printsec.drawString("s", 27, 0, 2);

      Printmin.setTextDatum(TR_DATUM);
      Printmin.createSprite(29, 16);
      Printmin.fillSprite(TFT_BLACK);
      Printmin.setTextColor(TFT_WHITE);
      Printmin.setTextPadding(tft.textWidth("99", 2));
      Printmin.drawNumber(PrintMin, 18, 0, 2);
      Printmin.setTextPadding(0);
      Printmin.drawString("m", 28, 0, 2);

      Printhour.setTextDatum(TC_DATUM);
      Printhour.createSprite(36, 16);
      Printhour.fillSprite(TFT_BLACK);
      Printhour.setTextColor(TFT_WHITE);
      Printhour.setTextPadding(tft.textWidth("999", 2));
      Printhour.drawNumber(PrintHour, 14, 0, 2);
      Printhour.setTextPadding(0);
      Printhour.drawString("h", 31, 0, 2);
      }
    }



////////////////////////////////////////////////////////////////////////////////////// Filament 2
  if (screen == "Filament2" || LastScreen == "Filament2") {
    FilamentSpool.setTextColor(Purple, TFT_BLACK);
    FilamentSpool.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    FilamentSpool.createSprite(132, 19);
    FilamentSpool.fillSprite(TFT_BLACK);
    FilamentSpool.drawString("Filament Spool", 2, 0);

    FilamentStats.setTextColor(Purple, TFT_BLACK);
    FilamentStats.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    FilamentStats.createSprite(144, 64);
    FilamentStats.fillRoundRect(2, 0, 140, 64, 8, GreyBlue);
    FilamentStats.setTextDatum(TC_DATUM);
    FilamentStats.setTextColor(TFT_WHITE);
    FilamentStats.drawString((String)CurrentSpool + ". " + CurSpoolMatText, 71, 3, GFXFF);
    FilamentStats.setTextColor(TFT_WHITE, GreyBlue);
    FilamentStats.drawString((String)CurSpoolFW + "g / " + (String)CurSpoolWeight + "g", 71, 25, 2);
    FilamentStats.drawString((String)(int)(CurSpoolFL) + "m / " + (String)CurSpoolLenght + "m", 71, 45, 2);
    FilamentStats.setTextColor(TFT_WHITE, TFT_BLACK);
    if (CurSpoolPercentage > 100){
      FilamentStats.drawString((String)100 + "% Left", 71, 69, 2);
    } else {
      FilamentStats.drawString((String)CurSpoolPercentage + "% Left", 71, 69, 2);
    }

    CurSpoolPerSprite.setTextColor(TFT_WHITE, TFT_BLACK);
    CurSpoolPerSprite.setTextFont(2);
    CurSpoolPerSprite.createSprite(68, 16);
    CurSpoolPerSprite.fillSprite(TFT_BLACK);
    CurSpoolPerSprite.setTextDatum(TC_DATUM);
    CurSpoolPerSprite.drawString((String)CurSpoolPercentage + "% Left", 35, 0, 2);

    NoSpool.setTextColor(Purple, TFT_BLACK);
    NoSpool.setFreeFont(&Segoe_UI_Bold_1_9pt7b);
    NoSpool.createSprite(86, 39);
    NoSpool.fillSprite(TFT_BLACK);
    NoSpool.drawString("Spool not", 2, 0, GFXFF);
    NoSpool.drawString("selected", 9, 20, GFXFF);
  }
  
}
