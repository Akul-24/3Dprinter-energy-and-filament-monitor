///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  Power LED

void PowerLED() {
  if (LEDMode == 0){
  if (LED == 1 && P < 10) {                        //Blue LED
    if (PLED == 10){
      if (LEDColour != 1){
        PLED = 0;
      }
      LEDColour = 1;
    }
  } else if (LED == 1 && P >= 10 && P <= 100) {    //Green LED
    if (PLED == 10){
      if (LEDColour != 2){
        PLED = 0;
      }
      LEDColour = 2;
    }  
  } else if (LED == 1 && P > 100) {                //Red LED
    if (PLED == 10){
      if (LEDColour != 3){
        PLED = 0;
      }
      LEDColour = 3;
    }
  } else if (LED == 0) {                           //LED OFF
    if (PLED == 10){
      if (LEDColour != 0){
        PLED = 0;
      }
      LEDColour = 0;
    }
  }

  if (PLED < 10){
    if (LEDColour == 1){
      leds[PLED] = CRGB(0, 0, 255);
    } else if (LEDColour == 2){
      leds[PLED] = CRGB(0, 255, 0);
    } else if (LEDColour == 3){
      leds[PLED] = CRGB(255, 0, 0);
    } else if (LEDColour == 0){
      leds[PLED] = CRGB(0, 0, 0);
    }
    FastLED.show();
    PLED = PLED + 1;
  }
  
  } else if (LEDMode == 1){
    if (LED == 1 && P < 10) {                        //Blue LED
    if (PLED == 10){
      if (LEDColour != 1){
        PLED = 5;
      }
      LEDColour = 1;
    }
  } else if (LED == 1 && P >= 10 && P <= 100) {    //Green LED
    if (PLED == 10){
      if (LEDColour != 2){
        PLED = 5;
      }
      LEDColour = 2;
    }  
  } else if (LED == 1 && P > 100) {                //Red LED
    if (PLED == 10){
      if (LEDColour != 3){
        PLED = 5;
      }
      LEDColour = 3;
    }
  } else if (LED == 0) {                           //LED OFF
    if (PLED == 10){
      if (LEDColour != 0){
        PLED = 5;
      }
      LEDColour = 0;
    }
  }

  if (PLED < 10){
    if (LEDColour == 1){
      leds[PLED] = CRGB(0, 0, 255);
      leds[9 - PLED] = CRGB(0, 0, 255);
    } else if (LEDColour == 2){
      leds[PLED] = CRGB(0, 255, 0);
      leds[9 - PLED] = CRGB(0, 255, 0);
    } else if (LEDColour == 3){
      leds[PLED] = CRGB(255, 0, 0);
      leds[9 - PLED] = CRGB(255, 0, 0);
    } else if (LEDColour == 0){
      leds[PLED] = CRGB(0, 0, 0);
      leds[9 - PLED] = CRGB(0, 0, 0);
    }
    FastLED.show();
    PLED = PLED + 1;
  }
  
  } else if (LEDMode == 2){

    if (LED == 1 && P < 10){
      if (PLED - 3 >= 0)
        leds[PLED - 3] = CRGB(0, 0, 0);

      if (PLED - 2 >= 0 && PLED - 2 < 11)
        leds[PLED - 2] = CRGB(0, 0, 255);

      if (PLED - 1 >= 0 && PLED - 1 < 11)
        leds[PLED - 1] = CRGB(0, 0, 255);

      if (PLED >= 0 && PLED < 11)
        leds[PLED] = CRGB(0, 0, 255);

    } else if (LED == 1 && P >= 10 && P <= 100){
      if (PLED - 3 >= 0)
        leds[PLED - 3] = CRGB(0, 0, 0);

      if (PLED - 2 >= 0 && PLED - 2 < 11)
        leds[PLED - 2] = CRGB(0, 255, 0);

      if (PLED - 1 >= 0 && PLED - 1 < 11)
        leds[PLED - 1] = CRGB(0, 255, 0);

      if (PLED >= 0 && PLED < 11)
        leds[PLED] = CRGB(0, 255, 0);

    } else if (LED == 1 && P > 100){
      if (PLED - 3 >= 0)
        leds[PLED - 3] = CRGB(0, 0, 0);

      if (PLED - 2 >= 0 && PLED - 2 < 11)
        leds[PLED - 2] = CRGB(255, 0, 0);

      if (PLED - 1 >= 0 && PLED - 1 < 11)
        leds[PLED - 1] = CRGB(255, 0, 0);

      if (PLED >= 0 && PLED < 11)
        leds[PLED] = CRGB(255, 0, 0);

    } else if (LED == 0){
      if (PLED - 3 >= 0)
        leds[PLED - 3] = CRGB(0, 0, 0);
    }
    FastLED.show();
    PLED = PLED + 1;

    if (PLED == 13){
      PLED = 0;
    }


  }


  if ((PLED == 10 && LEDColour != 0 && LEDMode != 2) || (PLED >= 5 && LEDColour != 0 && LEDMode == 2)){
    if (millis() - L1 > random(500, 1000)){
  if (B > 0){
    B = B - 17;
    leds[rLED1] = CRGB(B, B, B);
    FastLED.show();
  }
  else if (B == 0){
    if (millis () - L1 > 2400 && LEDSparkle == 1){
      if (LEDColour == 3){
        leds[rLED1] = CRGB(255, 0, 0); 
      } else if (LEDColour == 2){
        leds[rLED1] = CRGB(0, 255, 0); 
      } else {
        leds[rLED1] = CRGB(0, 0, 255); 
      }
      FastLED.show();
      rLED1 = random(9);
      if (rLED1 == rLED2 || rLED1 == rLED3){
        rLED1 = random(9);
      }
      B = 255;
      L1 = millis();
      SparkleState1 = 0;
    } else if (LEDSparkle == 1 || SparkleState1 == 0){
      B = -255;
      SparkleState1 = 1;
    }
   } else if (B < 0){
     B = B + 17;
     if (LEDColour == 3){
        leds[rLED1] = CRGB(B + 255, 0, 0); 
      } else if (LEDColour == 2){
        leds[rLED1] = CRGB(0, B + 255, 0); 
      } else {
        leds[rLED1] = CRGB(0, 0, B + 255); 
      }
     FastLED.show();
   }
  }


  if (millis() - L2 > random(1000, 1500)){
  if (B2 > 0){
    B2 = B2 - 17;
    leds[rLED2] = CRGB(B2, B2, B2);
    FastLED.show();
  }
  else if (B2 == 0){
    if (millis () - L2 > 3000 && LEDSparkle == 1){
      if (LEDColour == 3){
        leds[rLED2] = CRGB(255, 0, 0); 
      } else if (LEDColour == 2){
        leds[rLED2] = CRGB(0, 255, 0); 
      } else {
        leds[rLED2] = CRGB(0, 0, 255); 
      }
      FastLED.show();
      rLED2 = random(9);
      if (rLED2 == rLED1 || rLED2 == rLED3){
        rLED2 = random(9);
      }
      B2 = 255;
      L2 = millis();
      SparkleState2 = 0;
    } else if (LEDSparkle == 1 || SparkleState2 == 0){
      B2 = -255;
      SparkleState2 = 1;
    }
   } else if (B2 < 0){
     B2 = B2 + 17;
     if (LEDColour == 3){
        leds[rLED2] = CRGB(B2 + 255, 0, 0); 
      } else if (LEDColour == 2){
        leds[rLED2] = CRGB(0, B2 + 255, 0); 
      } else {
        leds[rLED2] = CRGB(0, 0, B2 + 255); 
      }
     FastLED.show();
   }
  }
  }
}
