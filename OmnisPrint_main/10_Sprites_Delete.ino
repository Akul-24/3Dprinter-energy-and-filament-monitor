void SpritesDelete(){
  if (LastScreen == "HomeScreen") {
    voltage1.deleteSprite();
    current1.deleteSprite();
    cost1.deleteSprite();
    voltage2.deleteSprite();
    current2.deleteSprite();
    cost2.deleteSprite();
  } else if (LastScreen == "Energy") {
    UsedEnergy.deleteSprite();
    Time.deleteSprite();
    ElectricalCost.deleteSprite();
    TimeValue.deleteSprite();
    ElCostValue.deleteSprite();
  } else if (LastScreen == "Energy2") {
    AvgPsprite.deleteSprite();
    MaxPsprite.deleteSprite();
    Printing.deleteSprite();
    Standby.deleteSprite();
    PrinterSprite.deleteSprite();
    Off.deleteSprite();
    Printsec.deleteSprite();
    Printmin.deleteSprite();
    Printhour.deleteSprite();
  } else if (LastScreen == "Filament") {
    FilamentUsed.deleteSprite();
    FilamentCost.deleteSprite();
    FilamentCostV.deleteSprite();
    CurrencySprite.deleteSprite();
  } else if (LastScreen == "Filament2") {
    FilamentSpool.deleteSprite();
    NoSpool.deleteSprite();
    FilamentStats.deleteSprite();
    CurSpoolPerSprite.deleteSprite();
  }
}