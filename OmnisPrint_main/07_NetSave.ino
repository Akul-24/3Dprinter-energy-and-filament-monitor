////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Save Network

void SaveNetVoid() {
  if (NetToConnect == 1) {
    if (SettingsSelect == 1) {
      SavedNet1SSIDString = Net1SSIDString;
      SavedNet1PassString = NetPassString;
      preferences.putString("ssid1", SavedNet1SSIDString); 
      preferences.putString("pass1", SavedNet1PassString);
      
    } else if (SettingsSelect == 2) {
      SavedNet2SSIDString = Net1SSIDString;
      SavedNet2PassString = NetPassString;
      preferences.putString("ssid2", SavedNet2SSIDString); 
      preferences.putString("pass2", SavedNet2PassString);
      
    } else if (SettingsSelect == 3) {
      SavedNet3SSIDString = Net1SSIDString;
      SavedNet3PassString = NetPassString;
      preferences.putString("ssid3", SavedNet3SSIDString); 
      preferences.putString("pass3", SavedNet3PassString);
      
    } else if (SettingsSelect == 4) {
      SavedNet4SSIDString = Net1SSIDString;
      SavedNet4PassString = NetPassString;
      preferences.putString("ssid4", SavedNet4SSIDString); 
      preferences.putString("pass4", SavedNet4PassString);
      
    } else if (SettingsSelect == 5) {
      SavedNet5SSIDString = Net1SSIDString;
      SavedNet5PassString = NetPassString;
      preferences.putString("ssid5", SavedNet5SSIDString); 
      preferences.putString("pass5", SavedNet5PassString);
    }


  } else if (NetToConnect == 2) {
    if (SettingsSelect == 1) {
      SavedNet1SSIDString = Net2SSIDString;
      SavedNet1PassString = NetPassString;
      preferences.putString("ssid1", SavedNet1SSIDString); 
      preferences.putString("pass1", SavedNet1PassString);
      
    } else if (SettingsSelect == 2) {
      SavedNet2SSIDString = Net2SSIDString;
      SavedNet2PassString = NetPassString;
      preferences.putString("ssid2", SavedNet2SSIDString); 
      preferences.putString("pass2", SavedNet2PassString);
      
    } else if (SettingsSelect == 3) {
      SavedNet3SSIDString = Net2SSIDString;
      SavedNet3PassString = NetPassString;
      preferences.putString("ssid3", SavedNet3SSIDString); 
      preferences.putString("pass3", SavedNet3PassString);
      
    } else if (SettingsSelect == 4) {
      SavedNet4SSIDString = Net2SSIDString;
      SavedNet4PassString = NetPassString;
      preferences.putString("ssid4", SavedNet4SSIDString); 
      preferences.putString("pass4", SavedNet4PassString);
      
    } else if (SettingsSelect == 5) {
      SavedNet5SSIDString = Net2SSIDString;
      SavedNet5PassString = NetPassString;
      preferences.putString("ssid5", SavedNet5SSIDString); 
      preferences.putString("pass5", SavedNet5PassString);
    }


  } else if (NetToConnect == 3) {
    if (SettingsSelect == 1) {
      SavedNet1SSIDString = Net3SSIDString;
      SavedNet1PassString = NetPassString;
      preferences.putString("ssid1", SavedNet1SSIDString); 
      preferences.putString("pass1", SavedNet1PassString);
      
    } else if (SettingsSelect == 2) {
      SavedNet2SSIDString = Net3SSIDString;
      SavedNet2PassString = NetPassString;
      preferences.putString("ssid2", SavedNet2SSIDString); 
      preferences.putString("pass2", SavedNet2PassString);
      
    } else if (SettingsSelect == 3) {
      SavedNet3SSIDString = Net3SSIDString;
      SavedNet3PassString = NetPassString;
      preferences.putString("ssid3", SavedNet3SSIDString); 
      preferences.putString("pass3", SavedNet3PassString);
      
    } else if (SettingsSelect == 4) {
      SavedNet4SSIDString = Net3SSIDString;
      SavedNet4PassString = NetPassString;
      preferences.putString("ssid4", SavedNet4SSIDString); 
      preferences.putString("pass4", SavedNet4PassString);
      
    } else if (SettingsSelect == 5) {
      SavedNet5SSIDString = Net3SSIDString;
      SavedNet5PassString = NetPassString;
      preferences.putString("ssid5", SavedNet5SSIDString); 
      preferences.putString("pass5", SavedNet5PassString);
    }

  } else if (NetToConnect == 4) {
    if (SettingsSelect == 1) {
      SavedNet1SSIDString = Net4SSIDString;
      SavedNet1PassString = NetPassString;
      preferences.putString("ssid1", SavedNet1SSIDString); 
      preferences.putString("pass1", SavedNet1PassString);
      
    } else if (SettingsSelect == 2) {
      SavedNet2SSIDString = Net4SSIDString;
      SavedNet2PassString = NetPassString;
      preferences.putString("ssid2", SavedNet2SSIDString); 
      preferences.putString("pass2", SavedNet2PassString);
      
    } else if (SettingsSelect == 3) {
      SavedNet3SSIDString = Net4SSIDString;
      SavedNet3PassString = NetPassString;
      preferences.putString("ssid3", SavedNet3SSIDString); 
      preferences.putString("pass3", SavedNet3PassString);
      
    } else if (SettingsSelect == 4) {
      SavedNet4SSIDString = Net4SSIDString;
      SavedNet4PassString = NetPassString;
      preferences.putString("ssid4", SavedNet4SSIDString); 
      preferences.putString("pass4", SavedNet4PassString);
      
    } else if (SettingsSelect == 5) {
      SavedNet5SSIDString = Net4SSIDString;
      SavedNet5PassString = NetPassString;
      preferences.putString("ssid5", SavedNet5SSIDString); 
      preferences.putString("pass5", SavedNet5PassString);
    }

  } else if (NetToConnect == 5) {
    if (SettingsSelect == 1) {
      SavedNet1SSIDString = Net5SSIDString;
      SavedNet1PassString = NetPassString;
      preferences.putString("ssid1", SavedNet1SSIDString); 
      preferences.putString("pass1", SavedNet1PassString);
      
    } else if (SettingsSelect == 2) {
      SavedNet2SSIDString = Net5SSIDString;
      SavedNet2PassString = NetPassString;
      preferences.putString("ssid2", SavedNet2SSIDString); 
      preferences.putString("pass2", SavedNet2PassString);
      
    } else if (SettingsSelect == 3) {
      SavedNet3SSIDString = Net5SSIDString;
      SavedNet3PassString = NetPassString;
      preferences.putString("ssid3", SavedNet3SSIDString); 
      preferences.putString("pass3", SavedNet3PassString);
      
    } else if (SettingsSelect == 4) {
      SavedNet4SSIDString = Net5SSIDString;
      SavedNet4PassString = NetPassString;
      preferences.putString("ssid4", SavedNet4SSIDString); 
      preferences.putString("pass4", SavedNet4PassString);
      
    } else if (SettingsSelect == 5) {
      SavedNet5SSIDString = Net5SSIDString;
      SavedNet5PassString = NetPassString;
      preferences.putString("ssid5", SavedNet5SSIDString); 
      preferences.putString("pass5", SavedNet5PassString);
    }
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Auto Connect Edit
void AutoConnectEdit() {
  tft.setTextFont(1);
  tft.setCursor(20, 110);
  
  if (NetToConnect == 1) {
    tft.print(SavedNet1SSIDString);
    tft.setFreeFont(&FreeSansBold9pt7b);
    if (screen == "SavedWiFiConnecting") {
      WiFi.begin(SavedNet1SSIDString.c_str(), SavedNet1PassString.c_str());
      SavedConnecting = 1;
    } else {
      tft.setTextFont(4);
      if (AutoConnect1 == "OFF") {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("OFF");
      } else if (AutoConnect1 == "ON") {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("ON  ");
      }
      if (AutoConnectONOFF == 1) {
        if (AutoConnect1 == "ON") {
          AutoConnect1 = "OFF";
          preferences.putBool("AC1", 0);
        } else {
          AutoConnect1 = "ON";
          AutoConnect2 = "OFF";
          AutoConnect3 = "OFF";
          AutoConnect4 = "OFF";
          AutoConnect5 = "OFF";
          preferences.putBool("AC1", 1);
          preferences.putBool("AC2", 0);
          preferences.putBool("AC3", 0);
          preferences.putBool("AC4", 0);
          preferences.putBool("AC5", 0);
        }
        AutoConnectONOFF = 0;
      }
    }
    
  } else if (NetToConnect == 2) {
    tft.print(SavedNet2SSIDString);
    tft.setFreeFont(&FreeSansBold9pt7b);
    if (screen == "SavedWiFiConnecting") {
      WiFi.begin(SavedNet2SSIDString.c_str(), SavedNet2PassString.c_str());
      SavedConnecting = 1;
    } else {
      tft.setTextFont(4);
      if (AutoConnect2 == "OFF") {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("OFF");
      } else if (AutoConnect2 == "ON") {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("ON  ");
      }
      if (AutoConnectONOFF == 1) {
        if (AutoConnect2 == "ON") {
          AutoConnect2 = "OFF";
          preferences.putBool("AC2", 0);
        } else {
          AutoConnect2 = "ON";
          AutoConnect1 = "OFF";
          AutoConnect3 = "OFF";
          AutoConnect4 = "OFF";
          AutoConnect5 = "OFF";
          preferences.putBool("AC1", 0);
          preferences.putBool("AC2", 1);
          preferences.putBool("AC3", 0);
          preferences.putBool("AC4", 0);
          preferences.putBool("AC5", 0);
        }
        AutoConnectONOFF = 0;
      }
    }
  } else if (NetToConnect == 3) {
    tft.print(SavedNet3SSIDString);
    tft.setFreeFont(&FreeSansBold9pt7b);
    if (screen == "SavedWiFiConnecting") {
      WiFi.begin(SavedNet3SSIDString.c_str(), SavedNet3PassString.c_str());
      SavedConnecting = 1;
    } else {
      tft.setTextFont(4);
      if (AutoConnect3 == "OFF") {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("OFF");
      } else if (AutoConnect3 == "ON") {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("ON  ");
      }
      if (AutoConnectONOFF == 1) {
        if (AutoConnect3 == "ON") {
          AutoConnect3 = "OFF";
          preferences.putBool("AC3", 0);
        } else {
          AutoConnect3 = "ON";
          AutoConnect1 = "OFF";
          AutoConnect1 = "OFF";
          AutoConnect4 = "OFF";
          AutoConnect5 = "OFF";
          preferences.putBool("AC1", 0);
          preferences.putBool("AC2", 0);
          preferences.putBool("AC3", 1);
          preferences.putBool("AC4", 0);
          preferences.putBool("AC5", 0);
        }
        AutoConnectONOFF = 0;
      }
    }
  } else if (NetToConnect == 4) {
    tft.print(SavedNet4SSIDString);
    tft.setFreeFont(&FreeSansBold9pt7b);
    if (screen == "SavedWiFiConnecting") {
      WiFi.begin(SavedNet4SSIDString.c_str(), SavedNet4PassString.c_str());
      SavedConnecting = 1;
    } else {
      tft.setTextFont(4);
      if (AutoConnect4 == "OFF") {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("OFF");
      } else if (AutoConnect4 == "ON") {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("ON  ");
      }
      if (AutoConnectONOFF == 1) {
        if (AutoConnect4 == "ON") {
          AutoConnect4 = "OFF";
          preferences.putBool("AC4", 0);
        } else {
          AutoConnect4 = "ON";
          AutoConnect1 = "OFF";
          AutoConnect1 = "OFF";
          AutoConnect3 = "OFF";
          AutoConnect5 = "OFF";
          preferences.putBool("AC1", 0);
          preferences.putBool("AC2", 0);
          preferences.putBool("AC3", 0);
          preferences.putBool("AC4", 1);
          preferences.putBool("AC5", 0);
        }
        AutoConnectONOFF = 0;
      }
    }
  } else if (NetToConnect == 5) {
    tft.print(SavedNet5SSIDString);
    tft.setFreeFont(&FreeSansBold9pt7b);
    if (screen == "SavedWiFiConnecting") {
      WiFi.begin(SavedNet5SSIDString.c_str(), SavedNet5PassString.c_str());
      SavedConnecting = 1;
    } else {
      tft.setTextFont(4);
      if (AutoConnect5 == "OFF") {
        tft.setTextColor(TFT_RED, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("OFF");
      } else if (AutoConnect5 == "ON") {
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setCursor(108, 45);
        tft.print("ON  ");
      }
      if (AutoConnectONOFF == 1) {
        if (AutoConnect5 == "ON") {
          AutoConnect5 = "OFF";
          preferences.putBool("AC5", 0);
        } else {
          AutoConnect5 = "ON";
          AutoConnect1 = "OFF";
          AutoConnect2 = "OFF";
          AutoConnect3 = "OFF";
          AutoConnect4 = "OFF";
          preferences.putBool("AC1", 0);
          preferences.putBool("AC2", 0);
          preferences.putBool("AC3", 0);
          preferences.putBool("AC4", 0);
          preferences.putBool("AC5", 1);
        }
        AutoConnectONOFF = 0;
      }
    }
  }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Auto Connect
void AutoConnect() {
  if (AutomaticConnecting == 0) {
    if (AutoConnect1 == "ON") {
      WiFi.begin(SavedNet1SSIDString.c_str(), SavedNet1PassString.c_str());
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 1;
    } else if (AutoConnect2 == "ON") {
      WiFi.begin(SavedNet2SSIDString.c_str(), SavedNet2PassString.c_str());
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 1;
    } else if (AutoConnect3 == "ON") {
      WiFi.begin(SavedNet3SSIDString.c_str(), SavedNet3PassString.c_str());
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 1;
    } else if (AutoConnect4 == "ON") {
      WiFi.begin(SavedNet4SSIDString.c_str(), SavedNet4PassString.c_str());
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 1;
    } else if (AutoConnect5 == "ON") {
      WiFi.begin(SavedNet5SSIDString.c_str(), SavedNet5PassString.c_str());
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 1;
    }
  } else if (AutomaticConnecting == 1) {
    tft.setTextColor(TFT_YELLOW, TFT_BLUE);
    if (WiFi.status() != WL_CONNECTED && screen == "HomeScreen" && LastScreen == "HomeScreen" && millis() - AutomaticConnectingMillis <= 10000) {
      tft.setTextFont(1);
      tft.setTextColor(LightGreen, GreyBlue);
      tft.setCursor(8, 4);
      tft.print("Connecting");
    } else if (WiFi.status() == WL_CONNECTED && screen == "HomeScreen" && LastScreen == "HomeScreen") {
      tft.setTextFont(1);
      tft.setTextColor(LightGreen, GreyBlue);
      tft.setCursor(8, 4);
      tft.print("Connected   ");
      Network = "ON";
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 2;
    } else if (millis() - AutomaticConnectingMillis > 10000 && screen == "HomeScreen" && LastScreen == "HomeScreen") {
      tft.setTextFont(1);
      tft.setTextColor(LightGreen, GreyBlue);
      tft.setCursor(8, 4);
      tft.print("Failed    ");
      AutomaticConnectingMillis = millis();
      AutomaticConnecting = 2;
    }
  } else if (AutomaticConnecting == 2) {
    tft.setTextColor(LightGreen, GreyBlue);
    if (millis() - AutomaticConnectingMillis > 3000 && screen == "HomeScreen" && LastScreen == "HomeScreen") {
      tft.setTextFont(1);
      tft.setCursor(8, 4);
      tft.print("          ");
      AutomaticConnecting = 3;
    }
  }
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Delete Network
void DeleteNet() {
  if (NetToConnect == 1) {
    SavedNet1SSIDString = "";
    SavedNet1PassString = "";
    preferences.putString("ssid1", ""); 
    preferences.putString("pass1", "");
    AutoConnect1 = "OFF";
    preferences.putBool("AC1", 0);
    
  } else if (NetToConnect == 2) {
    SavedNet2SSIDString = "";
    SavedNet2PassString = "";
    preferences.putString("ssid2", ""); 
    preferences.putString("pass2", "");
    AutoConnect2 = "OFF";
    preferences.putBool("AC2", 0); 
    
  } else if (NetToConnect == 3) {
    SavedNet3SSIDString = "";
    SavedNet3PassString = "";
    preferences.putString("ssid3", ""); 
    preferences.putString("pass3", "");
    AutoConnect3 = "OFF";
    preferences.putBool("AC3", 0);
    
  } else if (NetToConnect == 4) {
    SavedNet4SSIDString = "";
    SavedNet4PassString = "";
    preferences.putString("ssid4", ""); 
    preferences.putString("pass4", "");
    AutoConnect4 = "OFF";
    preferences.putBool("AC4", 0);
    
  } else if (NetToConnect == 5) {
    SavedNet5SSIDString = "";
    SavedNet5PassString = "";
    preferences.putString("ssid5", ""); 
    preferences.putString("pass5", "");
    AutoConnect5 = "OFF";
    preferences.putBool("AC5", 0);
  }
}
