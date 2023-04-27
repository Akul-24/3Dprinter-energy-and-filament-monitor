void ScreenScroll(){

///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy to Home screen
  if (screen == "HomeScreen" && LastScreen == "Energy"){

    voltage1.pushSprite(ScreenXScroll + 14 - 3, 15);
    current1.pushSprite(ScreenXScroll + 94 - 3, 15);
    cost1.pushSprite(ScreenXScroll + 86 - 3, 62);
    
    voltage2.pushSprite(ScreenXScroll + 5 - 3, 32);
    current2.pushSprite(ScreenXScroll + 84 - 3, 32);
    cost2.pushSprite(ScreenXScroll + 86 - 3, 77);

    CurrencySprite.pushSprite(ScreenXScroll + 109 - 3, 101);
    tft.drawLine(ScreenXScroll - 1, 0, ScreenXScroll - 1, 14, GreyBlue);
    tft.drawLine(ScreenXScroll, 0, ScreenXScroll, 14, GreyBlue);


    UsedEnergy.pushSprite(ScreenXScroll + 10 - 160 - 2, 4);
    tft.drawLine(ScreenXScroll - 10, 4, ScreenXScroll - 10, 44, TFT_BLACK);
    tft.drawLine(ScreenXScroll - 9, 4, ScreenXScroll - 9, 44, TFT_BLACK);
    Time.pushSprite(ScreenXScroll + 60 - 160 - 2, 48);
    ElectricalCost.pushSprite(ScreenXScroll + 20 - 160 - 2, 82);

    TimeValue.pushSprite(ScreenXScroll + 8 - 160 - 2, 65);
    ElCostValue.pushSprite(ScreenXScroll + 30 - 160 - 2, 100);
    CurrencySprite.pushSprite(ScreenXScroll + 110 - 160 - 2, 103);

    ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX + 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(64 + DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(32 - 1 - 32 + DoubleScreenBarX, 127, TFT_BLACK);
      }
      }
   }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Home screen to Energy
   else if (screen == "Energy" && LastScreen == "HomeScreen"){

      voltage1.pushSprite(14 + 160 - ScreenXScroll, 15);
      current1.pushSprite(94 + 160 - ScreenXScroll, 15);
      cost1.pushSprite(86 + 160 - ScreenXScroll, 62);
    
      voltage2.pushSprite(5 + 160 - ScreenXScroll, 32);
      current2.pushSprite(84 + 160 - ScreenXScroll, 32);
      cost2.pushSprite(86 + 160 - ScreenXScroll, 77);

      CurrencySprite.pushSprite(109 + 160 - ScreenXScroll, 101);
      tft.drawLine(6 + 160 - ScreenXScroll, 58, 6 + 160 - ScreenXScroll, 123, TFT_BLACK);
      tft.drawLine(5 + 160 - ScreenXScroll, 58, 5 + 160 - ScreenXScroll, 123, TFT_BLACK);

      tft.drawLine(0 + 160 - ScreenXScroll, 0, 0 + 160 - ScreenXScroll, 15, TFT_BLACK);
      tft.drawLine(1 + 160 - ScreenXScroll, 0, 1 + 160 - ScreenXScroll, 15, TFT_BLACK);


      UsedEnergy.pushSprite(10 - ScreenXScroll, 4);
      Time.pushSprite(60 - ScreenXScroll, 48);
      ElectricalCost.pushSprite(20 - ScreenXScroll, 82);

      TimeValue.pushSprite(8 - ScreenXScroll, 65);
      ElCostValue.pushSprite(30 - ScreenXScroll, 100);
      CurrencySprite.pushSprite(110 - ScreenXScroll, 103);

      ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX - 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(64 - DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(96 + 1 + 32 - DoubleScreenBarX, 127, TFT_BLACK);
      }
      }
  }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Home screen to Filament
  else if (screen == "Filament" && LastScreen == "HomeScreen"){


      voltage1.pushSprite(ScreenXScroll + 14 - 2 - 160, 15);
      current1.pushSprite(ScreenXScroll + 94 - 2 - 160, 15);
      cost1.pushSprite(ScreenXScroll + 86 - 2 - 160, 62);
    
      voltage2.pushSprite(ScreenXScroll + 5 - 2 - 160, 32);
      current2.pushSprite(ScreenXScroll + 84 - 2 - 160, 32);
      cost2.pushSprite(ScreenXScroll + 86 - 2 - 160, 77);

      CurrencySprite.pushSprite(ScreenXScroll + 109 - 2 - 160, 101);
      tft.drawLine(6 + ScreenXScroll + 70 - 160, 58, 6 + ScreenXScroll + 70 - 160, 123, TFT_BLACK);
      tft.drawLine(5 + ScreenXScroll + 70 - 160, 58, 5 + ScreenXScroll + 70 - 160, 123, TFT_BLACK);

      tft.drawLine(ScreenXScroll - 1, 0, ScreenXScroll - 1, 15, TFT_BLACK);
      tft.drawLine(ScreenXScroll - 2, 0,ScreenXScroll - 2, 15, TFT_BLACK);


      FilamentUsed.pushSprite(ScreenXScroll + 4 - 3, 5);
      FilamentCost.pushSprite(ScreenXScroll + 61 - 3, 82);
      if (FC < 0){
        FilamentCostV.pushSprite(ScreenXScroll + 29 - 3 - tft.textWidth("-", 4), 100);
      } else {
        FilamentCostV.pushSprite(ScreenXScroll + 29 - 3, 100);
      }
      CurrencySprite.pushSprite(ScreenXScroll + 109 - 3, 103);

      ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX + 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(96 + DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(64 - 1 - 32 + DoubleScreenBarX, 127, TFT_BLACK);
      }
      }
  }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament to Home screen
  else if (screen == "HomeScreen" && LastScreen == "Filament"){

    voltage1.pushSprite(14 - ScreenXScroll + 1, 15);
    current1.pushSprite(94 - ScreenXScroll + 1, 15);
    cost1.pushSprite(86 - ScreenXScroll + 1, 62);
    
    voltage2.pushSprite(5 - ScreenXScroll + 1, 32);
    current2.pushSprite(84 - ScreenXScroll + 1, 32);
    cost2.pushSprite(86 - ScreenXScroll + 1, 77);
    
    CurrencySprite.pushSprite(109 - ScreenXScroll + 1, 101);
    tft.drawLine(160 - ScreenXScroll, 0, 160 - ScreenXScroll, 14, GreyBlue);
    tft.drawLine(161 - ScreenXScroll, 0, 161 - ScreenXScroll, 14, GreyBlue);


    FilamentUsed.pushSprite(4 - 1 - ScreenXScroll + 160, 5);
    FilamentCost.pushSprite(61 - 1 - ScreenXScroll + 160, 82);
    if (FC < 0){
      FilamentCostV.pushSprite(29 - 1 - ScreenXScroll + 160 - tft.textWidth("-", 4), 100);
    } else {
      FilamentCostV.pushSprite(29 - 1 - ScreenXScroll + 160, 100);
    }
    CurrencySprite.pushSprite(109 - 1 - ScreenXScroll + 160, 103);

    ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX - 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(96 - DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(128 + 1 + 32 - DoubleScreenBarX, 127, TFT_BLACK);
      }
      }
  }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy to Filament
   else if (screen == "Filament" && LastScreen == "Energy"){

    UsedEnergy.pushSprite(ScreenXScroll + 10 - 160 - 2, 4);
    tft.drawLine(ScreenXScroll - 10, 4, ScreenXScroll - 10, 44, TFT_BLACK);
    tft.drawLine(ScreenXScroll - 9, 4, ScreenXScroll - 9, 44, TFT_BLACK);
    Time.pushSprite(ScreenXScroll + 60 - 160 - 2, 48);
    ElectricalCost.pushSprite(ScreenXScroll + 20 - 160 - 2, 82);

    TimeValue.pushSprite(ScreenXScroll + 8 - 160 - 2, 65);
    ElCostValue.pushSprite(ScreenXScroll + 30 - 160 - 2, 100);
    CurrencySprite.pushSprite(ScreenXScroll + 110 - 160 - 2, 103);


    FilamentUsed.pushSprite(ScreenXScroll + 4 - 3, 5);
      FilamentCost.pushSprite(ScreenXScroll + 61 - 3, 82);
      if (FC < 0){
        FilamentCostV.pushSprite(ScreenXScroll + 29 - 3 - tft.textWidth("-", 4), 100);
      } else {
        FilamentCostV.pushSprite(ScreenXScroll + 29 - 3, 100);
      }
      CurrencySprite.pushSprite(ScreenXScroll + 109 - 3, 103);


      ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX = DoubleScreenBarX + 2;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX + 1;
      }
      if (DoubleScreenBarX <= 64){
        tft.drawPixel(96 + DoubleScreenBarX - 32, 127, TFT_WHITE);
        tft.drawPixel(96 + DoubleScreenBarX - 1 - 32, 127, TFT_WHITE);
      } else{
        tft.drawPixel(64 - 1 - 64 + DoubleScreenBarX - 32, 127, TFT_BLACK);
        tft.drawPixel(64 - 1 - 64 + DoubleScreenBarX - 1 - 32, 127, TFT_BLACK);
      }
      }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament to Energy2
   } else if (screen == "Energy2" && LastScreen == "Filament"){

     FilamentUsed.pushSprite(4 - 1 - ScreenXScroll + 160, 5);
    FilamentCost.pushSprite(61 - 1 - ScreenXScroll + 160, 82);
    if (FC < 0){
      FilamentCostV.pushSprite(29 - 1 - ScreenXScroll + 160 - tft.textWidth("-", 4), 100);
    } else {
      FilamentCostV.pushSprite(29 - 1 - ScreenXScroll + 160, 100);
    }
    CurrencySprite.pushSprite(109 - 1 - ScreenXScroll + 160, 103);


    AvgPsprite.pushSprite(5 - ScreenXScroll, 5);
    MaxPsprite.pushSprite(85 - ScreenXScroll, 5);
        
    if (PrintingON == 0){
      if (RelayState == 0){
        PrinterSprite.pushSprite(18 - ScreenXScroll, 76);
        Off.pushSprite(31 - ScreenXScroll, 96);
      } else {
        Standby.pushSprite(10 - ScreenXScroll, 84);
      }
    }
    else {
      Printing.pushSprite(13 - ScreenXScroll, 70);
      Printsec.pushSprite(51 - ScreenXScroll + 1, 106);
      Printmin.pushSprite(11 - ScreenXScroll + 1, 106);
      Printhour.pushSprite(31 - ScreenXScroll + 1, 89);
    }


    ScreenXScroll -= 2;

      if (ScreenXScroll > 126){
        ScrollDivider = 1;
      } else {
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX = DoubleScreenBarX + 4;
        ScreenBarX = ScreenBarX - 2;
      if (DoubleScreenBarX <= 96){
        tft.drawLine(94 - DoubleScreenBarX + 1, 127, 98 - DoubleScreenBarX + 1, 127, TFT_WHITE);
      } else{
        tft.drawLine(224 - DoubleScreenBarX + 1, 127, 228 - DoubleScreenBarX + 1, 127, TFT_BLACK);
      }
      }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy 2 to Filament 2
   } else if (screen == "Filament2" && LastScreen == "Energy2"){

    AvgPsprite.pushSprite(ScreenXScroll - 150, 5);
    MaxPsprite.pushSprite(ScreenXScroll - 75, 5);
    
    tft.drawLine(ScreenXScroll, 75, ScreenXScroll, 120, TFT_BLACK);
    tft.drawLine(ScreenXScroll - 1, 75, ScreenXScroll - 1, 120, TFT_BLACK);

    if (PrintingON == 0){
      if (RelayState == 0){
        PrinterSprite.pushSprite(ScreenXScroll - 142, 76);
        Off.pushSprite(ScreenXScroll - 129, 96);
      } else {
        Standby.pushSprite(ScreenXScroll - 150, 84);
      }
    }
    else {
      Printing.pushSprite(ScreenXScroll - 147, 70);
      Printsec.pushSprite(ScreenXScroll - 109, 106);
      Printmin.pushSprite(ScreenXScroll - 149, 106);
      Printhour.pushSprite(ScreenXScroll - 129, 89);
    }


    FilamentSpool.pushSprite(14 + ScreenXScroll - 1, 1);
    if (CurrentSpool == 0) {
      NoSpool.pushSprite(35 + ScreenXScroll - 1, 26);
    } else if (CurrentSpool > 0) {
      FilamentStats.pushSprite(7 + ScreenXScroll - 1, 25);
      CurSpoolPerSprite.pushSprite(43 + ScreenXScroll - 1, 94);
    }


    ScreenXScroll -= 2;

      if (ScreenXScroll > 62){
        ScrollDivider = 1;
      } else {
        ScrollDivider = 2;
      }


    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX = DoubleScreenBarX + 4;
        ScreenBarX = ScreenBarX + 2;
      if (DoubleScreenBarX <= 128){
        tft.drawLine(DoubleScreenBarX + 29, 127,DoubleScreenBarX + 33, 127, TFT_WHITE);
      } else{
        tft.drawLine(DoubleScreenBarX - 128, 127,DoubleScreenBarX - 132, 127, TFT_BLACK);
      }
      }
   }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament 2 to Home screen
   else if (screen == "HomeScreen" && LastScreen == "Filament2"){

     FilamentSpool.pushSprite(14 - ScreenXScroll - 1 + 160, 1);
    if (CurrentSpool == 0) {
      NoSpool.pushSprite(35 - ScreenXScroll - 1 + 160, 26);
      tft.drawLine(-ScreenXScroll + 198, 68, -ScreenXScroll + 198, 125, TFT_BLACK);
      tft.drawLine(-ScreenXScroll + 199, 68, -ScreenXScroll + 199, 125, TFT_BLACK);
    } else if (CurrentSpool > 0) {
      FilamentStats.pushSprite(7 - ScreenXScroll - 1 + 160, 25);
      CurSpoolPerSprite.pushSprite(43 - ScreenXScroll - 1 + 160, 94);
      tft.drawLine(-ScreenXScroll + 188, 112, -ScreenXScroll + 188, 120, TFT_BLACK);
      tft.drawLine(-ScreenXScroll + 187, 112, -ScreenXScroll + 187, 120, TFT_BLACK);
    }


    voltage1.pushSprite(14 - ScreenXScroll + 1, 15);
    current1.pushSprite(94 - ScreenXScroll + 1, 15);
    cost1.pushSprite(86 - ScreenXScroll + 1, 62);
    
    voltage2.pushSprite(5 - ScreenXScroll + 1, 32);
    current2.pushSprite(84 - ScreenXScroll + 1, 32);
    cost2.pushSprite(86 - ScreenXScroll + 1, 77);
    
    CurrencySprite.pushSprite(109 - ScreenXScroll + 1, 101);


      ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX = DoubleScreenBarX + 2;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX - 1;
      }
      if (DoubleScreenBarX <= 64){
        tft.drawPixel(130 - DoubleScreenBarX, 127, TFT_WHITE);
        tft.drawPixel(130 - DoubleScreenBarX - 1, 127, TFT_WHITE);
      } else{
        tft.drawPixel(226 - DoubleScreenBarX, 127, TFT_BLACK);
        tft.drawPixel(226 - DoubleScreenBarX - 1, 127, TFT_BLACK);
      }
      }
   }


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Energy2 to Home screen
   else if (screen == "HomeScreen" && LastScreen == "Energy2"){

    AvgPsprite.pushSprite(ScreenXScroll - 150, 5);
    MaxPsprite.pushSprite(ScreenXScroll - 75, 5);
    
    tft.drawLine(ScreenXScroll, 75, ScreenXScroll, 120, TFT_BLACK);
    tft.drawLine(ScreenXScroll - 1, 75, ScreenXScroll - 1, 120, TFT_BLACK);

    if (PrintingON == 0){
      if (RelayState == 0){
        PrinterSprite.pushSprite(ScreenXScroll - 142, 76);
        Off.pushSprite(ScreenXScroll - 129, 96);
      } else {
        Standby.pushSprite(ScreenXScroll - 150, 84);
      }
    }
    else {
      Printing.pushSprite(ScreenXScroll - 147, 70);
      Printsec.pushSprite(ScreenXScroll - 109, 106);
      Printmin.pushSprite(ScreenXScroll - 149, 106);
      Printhour.pushSprite(ScreenXScroll - 129, 89);
    }


    voltage1.pushSprite(ScreenXScroll + 14 - 3, 15);
    current1.pushSprite(ScreenXScroll + 94 - 3, 15);
    cost1.pushSprite(ScreenXScroll + 86 - 3, 62);
    
    voltage2.pushSprite(ScreenXScroll + 5 - 3, 32);
    current2.pushSprite(ScreenXScroll + 84 - 3, 32);
    cost2.pushSprite(ScreenXScroll + 86 - 3, 77);

    CurrencySprite.pushSprite(ScreenXScroll + 109 - 3, 101);
    tft.drawLine(ScreenXScroll - 1, 0, ScreenXScroll - 1, 14, GreyBlue);
    tft.drawLine(ScreenXScroll, 0, ScreenXScroll, 14, GreyBlue);


      ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX = DoubleScreenBarX + 2;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX + 1;
      }
      if (DoubleScreenBarX <= 64){
        tft.drawPixel(64 + DoubleScreenBarX - 32, 127, TFT_WHITE);
        tft.drawPixel(64 + DoubleScreenBarX - 1 - 32, 127, TFT_WHITE);
      } else{
        tft.drawPixel(32 - 1 - 64 + DoubleScreenBarX - 32, 127, TFT_BLACK);
        tft.drawPixel(32 - 1 - 64 + DoubleScreenBarX - 1 - 32, 127, TFT_BLACK);
      }
      }

   }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Energy to Energy 2  
   else if (screen == "Energy2" && LastScreen == "Energy"){

    UsedEnergy.pushSprite(10 + 160 - ScreenXScroll, 4);
    Time.pushSprite(60 + 160 - ScreenXScroll, 48);
    ElectricalCost.pushSprite(20 + 160 - ScreenXScroll, 82);

    TimeValue.pushSprite(8 + 160 - ScreenXScroll, 65);
    ElCostValue.pushSprite(30 + 160 - ScreenXScroll, 100);
    CurrencySprite.pushSprite(110 + 160 - ScreenXScroll, 103);
    tft.drawLine(169 - ScreenXScroll, 4, 169 - ScreenXScroll, 44, TFT_BLACK);
    tft.drawLine(168 - ScreenXScroll, 4, 168 - ScreenXScroll, 44, TFT_BLACK);
    

    AvgPsprite.pushSprite(5 - ScreenXScroll, 5);
    MaxPsprite.pushSprite(85 - ScreenXScroll, 5);
        
    if (PrintingON == 0){
      if (RelayState == 0){
        PrinterSprite.pushSprite(18 - ScreenXScroll, 76);
        Off.pushSprite(31 - ScreenXScroll, 96);
      } else {
        Standby.pushSprite(10 - ScreenXScroll, 84);
      }
    }
    else {
      Printing.pushSprite(13 - ScreenXScroll, 70);
      Printsec.pushSprite(51 - ScreenXScroll + 1, 106);
      Printmin.pushSprite(11 - ScreenXScroll + 1, 106);
      Printhour.pushSprite(31 - ScreenXScroll + 1, 89);
    }

    ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX - 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(32 - DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(64 + 1 + 32 - DoubleScreenBarX, 127, TFT_BLACK);
      }
      }

   }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// Energy 2 to Energy
   else if (screen == "Energy" && LastScreen == "Energy2"){
    
    AvgPsprite.pushSprite(ScreenXScroll - 150, 5);
    MaxPsprite.pushSprite(ScreenXScroll - 75, 5);
    
    tft.drawLine(ScreenXScroll, 75, ScreenXScroll, 120, TFT_BLACK);
    tft.drawLine(ScreenXScroll - 1, 75, ScreenXScroll - 1, 120, TFT_BLACK);

    if (PrintingON == 0){
      if (RelayState == 0){
        PrinterSprite.pushSprite(ScreenXScroll - 142, 76);
        Off.pushSprite(ScreenXScroll - 129, 96);
      } else {
        Standby.pushSprite(ScreenXScroll - 150, 84);
      }
    }
    else {
      Printing.pushSprite(ScreenXScroll - 147, 70);
      Printsec.pushSprite(ScreenXScroll - 109, 106);
      Printmin.pushSprite(ScreenXScroll - 149, 106);
      Printhour.pushSprite(ScreenXScroll - 129, 89);
    }


    UsedEnergy.pushSprite(ScreenXScroll + 10 - 4, 4);
    Time.pushSprite(ScreenXScroll + 60 - 4, 48);
    ElectricalCost.pushSprite(ScreenXScroll + 20 - 4, 82);

    TimeValue.pushSprite(ScreenXScroll + 8 - 4, 65);
    ElCostValue.pushSprite(ScreenXScroll + 30 - 4, 100);
    CurrencySprite.pushSprite(ScreenXScroll + 110 - 4, 103);

    ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX + 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(32 + DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(0 - 1 - 32 + DoubleScreenBarX, 127, TFT_BLACK);
      }
      }

   }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament to Filment2
  else if (screen == "Filament2" && LastScreen == "Filament"){

    FilamentUsed.pushSprite(ScreenXScroll - 160 + 4, 5);
    FilamentCost.pushSprite(ScreenXScroll - 160 + 61, 83);
    if (FC < 0){
      FilamentCostV.pushSprite(ScreenXScroll - 160 + 29 - tft.textWidth("-", 4), 100);
    } else {
      FilamentCostV.pushSprite(ScreenXScroll - 160 + 29, 100);
    }
    CurrencySprite.pushSprite(ScreenXScroll - 160 + 109, 103);

    FilamentSpool.pushSprite(14 + ScreenXScroll - 1, 1);
    if (CurrentSpool == 0) {
      NoSpool.pushSprite(35 + ScreenXScroll - 1, 26);
    } else if (CurrentSpool > 0) {
      FilamentStats.pushSprite(7 + ScreenXScroll - 1, 25);
      CurSpoolPerSprite.pushSprite(43 + ScreenXScroll - 1, 94);
    }
  

    ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX + 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(128 + DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(96 - 1 - 32 + DoubleScreenBarX, 127, TFT_BLACK);
      }
      }
   }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////  Filament2 to Filment
  else if (screen == "Filament" && LastScreen == "Filament2"){

    FilamentSpool.pushSprite(14 - ScreenXScroll - 1 + 160, 1);
    if (CurrentSpool == 0) {
      NoSpool.pushSprite(35 - ScreenXScroll - 1 + 160, 26);
      tft.drawLine(-ScreenXScroll + 198, 68, -ScreenXScroll + 198, 125, TFT_BLACK);
      tft.drawLine(-ScreenXScroll + 199, 68, -ScreenXScroll + 199, 125, TFT_BLACK);
    } else if (CurrentSpool > 0) {
      FilamentStats.pushSprite(7 - ScreenXScroll - 1 + 160, 25);
      CurSpoolPerSprite.pushSprite(43 - ScreenXScroll - 1 + 160, 94);
      tft.drawLine(-ScreenXScroll + 188, 112, -ScreenXScroll + 188, 120, TFT_BLACK);
      tft.drawLine(-ScreenXScroll + 187, 112, -ScreenXScroll + 187, 120, TFT_BLACK);
    }

    FilamentUsed.pushSprite(-ScreenXScroll + 4 + 1, 5);
    FilamentCost.pushSprite(-ScreenXScroll + 61 + 1, 82);
    if (FC < 0){
      FilamentCostV.pushSprite(-ScreenXScroll + 29 + 1 - tft.textWidth("-", 4), 100);
    } else {
      FilamentCostV.pushSprite(-ScreenXScroll + 29 + 1, 100);
    }
    CurrencySprite.pushSprite(-ScreenXScroll + 109 + 1, 103);
  

    ScreenXScroll -= 2;

    if (ScreenXScroll > 65){
        ScrollDivider = 1;
      } else{
        ScrollDivider = 2;
      }

    if((ScreenXScroll / 2) % ScrollDivider == 0){
      DoubleScreenBarX ++;
      if (DoubleScreenBarX % 2 == 0){
        ScreenBarX = ScreenBarX - 1;
      }
      if (DoubleScreenBarX <= 32){
        tft.drawPixel(128 - DoubleScreenBarX, 127, TFT_WHITE);
      } else{
        tft.drawPixel(193 - DoubleScreenBarX, 127, TFT_BLACK);
      }
      }
  }
   
}
