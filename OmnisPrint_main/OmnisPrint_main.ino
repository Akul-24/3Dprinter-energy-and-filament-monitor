/* This tab includes variables declaration and some functions */



///////////////////////////////*  Libraries  */
#include <WiFi.h>
#include <FirebaseESP32.h>

#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
AsyncWebServer server(80);

#include <TimeLib.h>

#include <FastLED.h>

#include <Preferences.h>
Preferences preferences;

#include <TFT_eSPI.h>
#include <SPI.h>
TFT_eSPI tft = TFT_eSPI();
#define GFXFF 1

#include <Rotary.h>

//////////////////////////////////*  Images  */
#include "EuroIconFile.h"
#include "ADollarIconFile.h"
#include "CDollarIconFile.h"
#include "PoundIconFile.h"
#include "FilSpoolFileDark.h"
#include "GreenFilSpoolFile.h"
#include "WiFiIconFile.h"
#include "WifiSmallFile.h"
#include "SoundFile.h"
#include "AutoOffFile.h"
#include "LightningBoltFile.h"
#include "BackIconFile.h"
#include "PrinterFile.h"
#include "DollarIconFile.h"
int i = 0;
int Add = 1;

////////////////////////////////////////////////*  Custom colors  */
#define LightGreen 0x07EC //0, 255, 100
#define LightRed 0xF8A5  //255, 20, 40
#define GreyBlue 0x2147   //36, 42, 56
#define Purple 0x7BBF   //120, 119, 255

////////////////////////////////////////////////////////////////////////////////////////////*  Millis  */
unsigned long HomeScreenMillis0 = 0; // Home screen clear
unsigned long HomeScreenMillis1 = 0; //Home screen
unsigned long HomeScreenTextMillis = 0;  //Home screen refresh text
unsigned long PowerRingMillis = 0;  //Power ring text refresh

unsigned long EnergyScreenMillis0 = 0; //Energy screen clear
unsigned long EnergyScreenMillis1 = 0; //Energy screen
unsigned long EnergySettingsScreenMillis0 = 0; //Energy settings screen clear
unsigned long EnergySettingsScreenMillis1 = 0; //Energy settings screen

unsigned long Energy2ScreenMillis0 = 0; //Energy 2 screen clear
unsigned long Energy2ScreenMillis1 = 0; //Energy 2 screen
unsigned long PowerSettingsScreenMillis0 = 0; //Power/Pause Settings clear
unsigned long PowerSettingsScreenMillis1 = 0; //Power/Pause Settings

unsigned long FilamentScreenMillis0 = 0; //Filament screen clear
unsigned long FilamentScreenMillis1 = 0; //Filament screen
unsigned long Filament2ScreenMillis0 = 0; //Filament 2 screen clear
unsigned long Filament2ScreenMillis1 = 0; //Filament 2 screen
unsigned long FilamentSettingsScreenMillis0 = 0; //Filament settings screen clear
unsigned long FilamentSettingsScreenMillis1 = 0; //Filament settings screen
unsigned long SpoolSelectSettingsScreenMillis0 = 0; //Spool Select settings screen clear
unsigned long SpoolSelectSettingsScreenMillis1 = 0; //Spool Select settings screen


unsigned long MainSettingsScreenMillis0 = 0; //Main settings screen clear
unsigned long MainSettingsScreenMillis1 = 0; //Main settings screen

unsigned long EnergyCostScreenMillis0 = 0; //Energy Cost screen clear
unsigned long EnergyCostScreenMillis1 = 0; //Energy Cost screen

unsigned long SaveScreenMillis = 0; //Save Screen
unsigned long WiFiOFFScreenMillis = 0; //WiFi OFF Screen

unsigned long CurrencyScreenMillis0 = 0; //Currency screen clear
unsigned long CurrencyScreenMillis1 = 0; //Currency screen

unsigned long PowerLEDScreenMillis0 = 0; //PowerLED screen clear
unsigned long PowerLEDScreenMillis1 = 0; //PowerLED screen

unsigned long WiFiScreenMillis0 = 0; //WiFi screen clear
unsigned long WiFiScreenMillis1 = 0; //WiFi screen

unsigned long WiFiOPENScreenMillis0 = 0; //Open WiFi screen clear
unsigned long WiFiOPENScreenMillis1 = 0; //Open WiFi screen

unsigned long OpenConnectingMillis = 0; //Open WiFi Connecting
unsigned long ConnectedScreenMillis = 0; //WiFi Connected

unsigned long ConnectedSaveScreenMillis = 0; //Connected Save Screen

unsigned long WiFiConnectScreenMillis0 = 0; //WiFi Connect screen clear
unsigned long WiFiConnectScreenMillis1 = 0; //WiFi Connect screen
unsigned long PassConnectingMillis = 0; //Password WiFi Connecting

unsigned long NetworkScanScreenMillis0; //Scan Network screen clear
unsigned long NetworkScanScreenMillis1; //Scan Network screen

unsigned long ScanMillis; //Scan Millis
unsigned long ScanDelayMillis; //Scan Delay Millis

unsigned long APScreenMillis0 = 0; //Acess Point screen clear
unsigned long APScreenMillis1 = 0; //Acess Point screen

unsigned long SavedNetScreenMillis0 = 0; //Saved Networks screen clear
unsigned long SavedNetScreenMillis1 = 0; //Saved Networks screen

unsigned long SaveNetScreenMillis0 = 0; //Save Networks screen clear
unsigned long SaveNetScreenMillis1 = 0; //Save Networks screen

unsigned long SavedNetEditScreenMillis0 = 0; //Saved Net Edit screen clear
unsigned long SavedNetEditScreenMillis1 = 0; //Saved Net Edit screen

unsigned long SavedConnectingMillis = 0; //Connecting to Saved Network
unsigned long SavedWiFiScreenMillis0 = 0; //Saved Network Connecting screen clear
unsigned long SavedWiFiScreenMillis1 = 0; //Saved Network Connecting screen

unsigned long DeletedScreenMillis = 0; //Deleted Screen

unsigned long FilamentMainSettingsScreenMillis0 = 0;  // Main Filament Settings clear
unsigned long FilamentMainSettingsScreenMillis1 = 0;  // Main Filament Settings

unsigned long MaterialsEditScreenMillis0 = 0;  //Materials Edit Settings clear
unsigned long MaterialsEditScreenMillis1 = 0;  //Materials Edit Settings

unsigned long EditPLAScreenMillis0 = 0;  //Edit PLA clear
unsigned long EditPLAScreenMillis1 = 0;  //Edit PLA

unsigned long EditPETGScreenMillis0 = 0;  //Edit PETG clear
unsigned long EditPETGScreenMillis1 = 0;  //Edit PETG

unsigned long EditABSScreenMillis0 = 0;  //Edit ABS clear
unsigned long EditABSScreenMillis1 = 0;  //Edit ABS

unsigned long EditTPUScreenMillis0 = 0;  //Edit TPU clear
unsigned long EditTPUScreenMillis1 = 0;  //Edit TPU

unsigned long EditNylonScreenMillis0 = 0;  //Edit Nylon clear
unsigned long EditNylonScreenMillis1 = 0;  //Edit Nylon

unsigned long EditPVAScreenMillis0 = 0;  //Edit PVA clear
unsigned long EditPVAScreenMillis1 = 0;  //Edit PVA

unsigned long EditHIPSScreenMillis0 = 0;  //Edit HIPS clear
unsigned long EditHIPSScreenMillis1 = 0;  //Edit HIPS

unsigned long EditASAScreenMillis0 = 0;  //Edit ASA clear
unsigned long EditASAScreenMillis1 = 0;  //Edit ASA

unsigned long EditPCScreenMillis0 = 0;  //Edit PC clear
unsigned long EditPCScreenMillis1 = 0;  //Edit PC

unsigned long EditCustom1ScreenMillis0 = 0;  //Edit Custom1 clear
unsigned long EditCustom1ScreenMillis1 = 0;  //Edit Custom1

unsigned long EditCustom2ScreenMillis0 = 0;  //Edit Custom2 clear
unsigned long EditCustom2ScreenMillis1 = 0;  //Edit Custom2

unsigned long DensityScreenMillis0 = 0;  //Edit Material Density clear
unsigned long DensityScreenMillis1 = 0;  //Edit Material Density

unsigned long FilSpoolSelectSettingsScreenMillis0 = 0; //Filament Spool Select settings screen clear
unsigned long FilSpoolSelectSettingsScreenMillis1 = 0; //Filament Spool Select settings screen

unsigned long SpoolEditScreenMillis0 = 0;  //Edit Spool Settings screen clear
unsigned long SpoolEditScreenMillis1 = 0;  //Edit Spool Settings screen clear

unsigned long ResetSpoolScreenMillis = 0;  //Reset Spool screen

unsigned long SpoolPercentageMillis = 0;  //Spool Percentage Update

unsigned long FilRunoutScreenMillis0 = 0; //Filament Runout Sensor screen clear
unsigned long FilRunoutScreenMillis1 = 0; //Filament Runout Sensor screen

unsigned long FilJamsScreenMillis0 = 0; //Filament Jams Sensor screen clear
unsigned long FilJamsScreenMillis1 = 0; //Filament Jams Sensor screen

unsigned long FilJamScreenMillis0 = 0; //Filament Jam Detected screen clear
unsigned long FilJamScreenMillis1 = 0; //Filament Jam Detected screen

unsigned long AutoOffScreenMillis0 = 0; //Automatic Off screen clear
unsigned long AutoOffScreenMillis1 = 0; //Automatic Off screen

unsigned long AutoOFFScreenMillis0 = 0; //Automatic OFF screen clear
unsigned long AutoOFFScreenMillis1 = 0; //Automatic OFF screen

unsigned long BrightnessScreenMillis0 = 0;  //Brightness screen clear
unsigned long BrightnessScreenMillis1 = 0;  //Brightness screen

unsigned long SoundScreenMillis0 = 0;  //Sound screen clear
unsigned long SoundScreenMillis1 = 0;  //Sound screen

unsigned long AutoScrollScreenMillis0 = 0;  //AutoScroll screen clear
unsigned long AutoScrollScreenMillis1 = 0;  //AutoScroll screen


////////////////////////////////////////////////////////////////////////////////////////////*  WiFi & Firebase  */
int WiFiScanEnable = 0;
int NetToConnect = 0;

String Network = "OFF";
String APMode = "OFF";

int OPENWiFiBegin = 0;
int dot = 0;          //Open WiFi Connecting dot
int PassConnect = 0;  //Pass Got - Connect To WiFi

int AutomaticConnecting = 0;                 //Automatic Connecting Start
unsigned long AutomaticConnectingMillis = 0; //Automatic Connecting

int AutoConnectONOFF = 0; //Automatic Connecting ON/OFF
int SavedConnecting = 0;  //Saved Net WiFi Connecting

String AutoConnect1 = "OFF";  //Automatic Connect Networks
String AutoConnect2 = "OFF";
String AutoConnect3 = "OFF";
String AutoConnect4 = "OFF";
String AutoConnect5 = "OFF";


char* FIREBASE_HOST = "espfirebase-65c78-default-rtdb.firebaseio.com";
char* FIREBASE_Authorization_key = "K7J8WWLAQ6g8ZsmDLHXrcksbbow7LwZnjV1EK7Ih";

FirebaseData firebaseData;
FirebaseJson json;

///////////////////////////////////////////////////////////////////////////////////////////////*  Scanning Networks  */
String NetPassString = "";

int Net1PassOPEN = 0;
String Net1SSIDString = "";

int Net2PassOPEN = 0;
String Net2SSIDString = "";

int Net3PassOPEN = 0;
String Net3SSIDString = "";

int Net4PassOPEN = 0;
String Net4SSIDString = "";

int Net5PassOPEN = 0;
String Net5SSIDString = "";

////////////////////////////////////////////////////////////////////////////////* Saved Networks  */
String SavedNet1SSIDString = "";
String SavedNet1PassString = "";

String SavedNet2SSIDString = "";
String SavedNet2PassString = "";

String SavedNet3SSIDString = "";
String SavedNet3PassString = "";

String SavedNet4SSIDString = "";
String SavedNet4PassString = "";

String SavedNet5SSIDString = "";
String SavedNet5PassString = "";

////////////////////////////////////////////////////////////////////////////////////*  Edit Material Settings  */
String EditMaterial = "PLA";  //Material To Edit Density And Cost
int Densitycm3 = 0;  //Density Edit g/cm3
int Densitym = 0;  //Density Edit g/m
float Densitycm3Edit = 0.00;  //Density Edit g/cm3
float DensitymEdit = 0.00;  //Density Edit g/m

int Costkg = 0;  //Cost Edit $/kg
float CostkgEdit = 0.00;  //Cost Edit $/kg

//////////////////////////////////////////////////////////////////////////////*  Energy screen Time & Button Millis  */
char seconds[10];
char minutes[10];
char hours[10];
char days[10];

unsigned long EnergyMillis = 0; //Energy
unsigned long ButtonMillis = 0; //Button
int UpdateButton = 0;
int interval = 0;  //energy interval

//////////////////////////////////////////////////////////////////////////////*  Values  */
/*  Voltage measurment  */
float arduinoVCC = 3.3;             // voltage
unsigned long ValueR1 = 9940;       // voltage divider r1
unsigned long ValueR2 = 151100;     // voltage divider r2
const int inputResolution = 4095;
const float average_of = 500;
float voltage;  //voltage read
float voltage_sensed;
float U = 0;    //voltage

/*  Current measurment  */
float I = 0;      //current
float Current;
float cvoltage = 0;
float VCC = 3.3;  // supply voltage

int P = 0;          //power
int AvgP = 0;       //Average power
int MaxP = 0;       //Max power
float E = 0.0000;   //energy
float C = 0.00;     //cost
float FL = 0.00;    //fimament lenght (m)
float FW = 0.00;    //fimament weight (kg)
float EC = 0.00;    //Energy cost
float FC = 0.00;    //Filament cost
float ec = 0.2;     //cost per kWh
float ecEdit = 0;   //Edit cost per kWh
float fc = 0.00;    //cost per gram

//////////////////////////////////////////////////////////////////////////////*  Rotary Encoder Updates  */
int FILChange = 0;              //Update Filament Counter
int stepOld;
int sensor01;
int sensor02;
int CostChange = 0;             //Update Cost Edit Counter
int Densitycm3Change = 0;       //Update Density (g/cm3) Counter
int DensitymChange = 0;         //Update Density (g/m) Counter
int CostkgChange = 0;           //Update Cost kg Counter
int SpoolMatEditChange = 0;     //Update Spool Material Edit
int SpoolWeightEditChange = 0;  //Update Spool Weight Edit

//////////////////////////////////////////////////////////////////////////////////*  Materials  */
String Material = "PLA";
float currentMATLW = 0.00;  //Current Material lenght to weight
float currentMATFC = 0.00;  //Current Material filament cost per gram

float PLALW = 3.00;  //PLA fimament length to weight (g per meter)
float PLAFC = 22.00;  //PLA fimament cost per kg
float PLAFL = 0;

float PETGLW = 3.05;  //PETG fimament length to weight (g per meter)
float PETGFC = 24.00;  //PETG fimament cost per kg
float PETGFL = 0;

float ABSLW = 2.50;  //ABS fimament length to weight (g per meter)
float ABSFC = 23.00;  //ABS fimament cost per kg
float ABSFL = 0;

float TPULW = 2.91;  //TPU fimament length to weight (g per meter)
float TPUFC = 60.00;  //TPU fimament cost per kg
float TPUFL = 0;

float NylonLW = 2.75;  //Nylon fimament length to weight (g per meter)
float NylonFC = 80.00;  //Nylon fimament cost per kg
float NylonFL = 0;

float PVALW = 2.96;  //PVA fimament length to weight (g per meter)
float PVAFC = 90.00;  //PVA fimament cost per kg
float PVAFL = 0;

float HIPSLW = 2.60;  //HIPS fimament length to weight (g per meter)
float HIPSFC = 30.00;  //HIPS fimament cost per kg
float HIPSFL = 0;

float ASALW = 2.52;  //ASA fimament length to weight (g per meter)
float ASAFC = 35.00;  //ASA fimament cost per kg
float ASAFL = 0;

float PCLW = 2.86;  //PC fimament length to weight (g per meter)
float PCFC = 60.00;  //PC fimament cost per kg
float PCFL = 0;

float Custom1LW = 0.00;  //Custom1 fimament length to weight (g per meter)
float Custom1FC = 0.000;  //Custom1 fimament cost per kg
float Custom1FL = 0;

float Custom2LW = 0.00;  //Custom2 fimament length to weight (g per meter)
float Custom2FC = 0.000;  //Custom2 fimament cost per kg
float Custom2FL = 0;

////////////////////////////////////////////////////////////////////////////*  Spools  (1-PLA 2-PETG 3-ABS 4-TPU 5-Nylon 6-PVA 7-HIPS 8-ASA 9-PC 10-Custom1 11-Custom2)  */
int CurrentSpool = 0;  //Currently used spool

int SpoolMaterial[] = {1, 2, 3, 4, 5};
String CurSpoolMatText = "PLA";  //Current Spool material text

int Spool1Weight = 1000;    //Spool 1 total weight (g)
int Spool2Weight = 2000;    //Spool 2 total weight (g)
int Spool3Weight = 1500;    //Spool 3 total weight (g)
int Spool4Weight = 1000;    //Spool 4 total weight (g)
int Spool5Weight = 1000;    //Spool 5 total weight (g)
int CurSpoolWeight = 1000;  //Current Spool weight (g)

int CurSpoolLenght = 333;  //Current Spool lenght (m)

float Spool1FL = 0;   //Spool 1 filament lenght left
float Spool2FL = 0;   //Spool 2 filament lenght left
float Spool3FL = 0;   //Spool 3 filament lenght left
float Spool4FL = 0;   //Spool 4 filament lenght left
float Spool5FL = 0;   //Spool 5 filament lenght left
float CurSpoolFL = 0; //Current Spool fialment lenght left

float Spool1FW = 1000;  //Spool 1 filament weight left
float Spool2FW = 2000;  //Spool 2 filament weight left
float Spool3FW = 1500;  //Spool 3 filament weight left
float Spool4FW = 1000;  //Spool 4 filament weight left
float Spool5FW = 1000;  //Spool 5 filament weight left
float CurSpoolFW = 0;   //Current Spool filament weight left

int Spool1Percentage = 100;  //Spool 1 Percentage
int Spool2Percentage = 100;  //Spool 2 Percentage
int Spool3Percentage = 100;  //Spool 3 Percentage
int Spool4Percentage = 100;  //Spool 4 Percentage
int Spool5Percentage = 100;  //Spool 5 Percentage
int CurSpoolPercentage = 0;  //Current Spool Percentage
int LastCurSpoolPercentage;  //Last Current spool percentage

int SpoolEditSelect = 0;  //Spool Edit Select
int SpoolMatEdit = 0;     //Spool Material Edit ON/OFF
int SpoolWeightEdit = 0;  //Spool Weight Edit ON/OFF
int SpoolBar = 0;         //Draw spool percentage bar

//////////////////////////////////////////////////////////////////////////*  Settings & Screen  */
int EnergyUnit = 2;     //Energy unit
String Currency = "$";  //Currency
int CostEdit = 0;       //Cost Edit
int CurrencyChange = 1;

int ScreenCounter = 0;
int SettingsCounter = 0;
int clearScreen = 1;
int SettingsSelect = 0;       //current cursor position 
int SettingsMaxSelect = 0;    //number of selectable items per screen

String screen = "HomeScreen"; //current screen

int ScreenBarX = 64;          //used for scrolling
int SettingsBarY = 0;
int ScreenXScroll = 0;

const char* ssid = "Moja mreza";  // Enter SSID here
const char* password = "internetluka";  //Enter Password here

/////////////////////////////////////////////////////////////////////////*  Buzzer (Sound), Relay, Auto Scroll, Auto Save  */
int BuzzerPin = 22;
unsigned long BuzzerNoFilMillis = 0;
unsigned long BuzzerNoFilTimeoutMillis = 0;
int BuzzerState = 0;
int BuzzerOFF = 0;

int OnClickSound = 0;
int AlertsSound = 1;
int PrintingSound = 1;
unsigned long OnClickSoundMillis = 0;
int OnClickSoundON = 0;

int RelayPin = 16;
int RelayState = 1;

unsigned long AutoScrollMillis = 15000;
int AutoScrollMode = 0;  // 0 = OFF, 1 = 3 Screens, 2 = All Screens
int AutoScrollEdit = 0;
int AutoScrollEditChange = 0;
unsigned long AutoScrollScreenMillis = 0;
int AutoScrollScreenCounter = 0;
unsigned long NoTouchMillis = 0;

int AutoSave = 1;
int AutoSaveON = 0;

////////////////////////////////////////////////////////////////////////////////*  Filament Runout, Jams Sensor, Printing & Auto Off  */
int FilRunoutSensorPin = 35;          //Connected to pin G35
int FilRunoutSensor = 0;              //Filament Runout Sensor OFF/ON
unsigned long FilRunoutSensorMillis = 0;
int NoFil = 0;                        //No filament detected (FilRunoutSensorPin == LOW)
int NoFilament = 0;                   //No filament
int FilSensorPause = 21;              //Filament sensor pause print pin
int PausePrint = 0;

int FilJamsSensor = 0;                  //Filament Jams Sensor OFF/ON
int FilJammed = 0;                      //Filament jammed
unsigned long FilJamsPrintingMillis = 0;
unsigned long BuzzerFilJamTimeoutMillis = 0;
unsigned long BuzzerFilJamMillis = 0;

int PrintingON = 0;                   //Printing ON
int PrintingP = 0;                    //Printing Power (P >= 30)
String PrevScreen = "";               //Save Previous Screen
unsigned long PrintingMillis = 0;     //Printing Time
unsigned long FilPrintingMillis = 0;
unsigned long PrintingPMillis = 0;
float PrintSec = 0;                   //Printing Seconds
int PrintMin = 0;                     //Printing Minutes
int PrintHour = 0;                    //Printing Hours
unsigned long PrintingTime = 0;
unsigned long PrintingMillisLeft = 0;

int AutoOff = 0;                      //Automatic Off
int AutoOffStart = 0;                 //Automatic Off Start (Printer Off)
unsigned long AutoOffMillis = 0;
int AutoOffTimeEdit = 0;              //Edit Auto Off Time
int AutoOffTimeEditChange = 0;
unsigned long BuzzerAutoOffTimeoutMillis = 0;
unsigned long BuzzerAutoOffMillis = 0;

///////////////////////////////////////////////////////////////////////////////*  Rotary Encoder  */
int button = 27;  //Rotary Encoder Button

Rotary rotary = Rotary(26, 25);
int LastScreenCounter;

const byte FILpin1 = 4;  // Connected to DT on KY-040
const byte FILpin2 = 17;  // Connected to CLK on KY-040
int FILstate = 0;

/////////////////////////////////////////////////////////////////////////////*  Power Analog Ring Meter  */
#define RED2RED 0
#define GREEN2GREEN 1
#define BLUE2BLUE 2
#define BLUE2RED 3
#define GREEN2RED 4
#define RED2GREEN 5

#define TFT_GREY 0x2104          // Dark grey 16 bit colour

uint32_t runTime = -99999;       // time for next update

int PrintP = 0;
int PowerRingShow = 0;

TaskHandle_t Task2;

////////////////////////////////////////////////////////////////////////////*  LEDs & Screen Brightness  */
#define LED_PIN     33  //Led Strip pin
#define NUM_LEDS    10  //Number of LEDs
CRGB leds[NUM_LEDS];
int LED = 1;  //Power LED OFF/ON/SAVE/ENERGY SAVE/ERASE
int PLED = 0;
int LEDColour = 0;
int LEDMode = 0;
int LEDBrightnessEdit = 0;
int LEDBrightnessEditChange = 0;
int LEDBrightnessPercentage = 20;

int LEDSparkle = 1;
int SparkleState1 = 0;
int rLED1 = 0;
int B = 0;
unsigned long L1 = 0;
int SparkleState2 = 0;
int rLED2 = 0;
int B2 = 0;
unsigned long L2 = 0;
int rLED3 = 0;
int B3 = 0;
unsigned long L3 = 0;

int LEDresolution = 13;
int LEDfreq = 5000;

void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 255) {
  // calculate duty, 8191 from 2 ^ 13 - 1
  uint32_t duty = (8191 / valueMax) * min(value, valueMax);
  // write duty to LEDC
  ledcWrite(channel, duty);
}

int ScreenLED = 5;  //Screen LED Pin
int ScreenLEDA = 0;  //Screen LED analog
int CHANNEL_SCREEN = 4;
int BrightnessPercentage = 100;
int BrightnessEdit = 0;
int BrightnessEditChange = 0;

/////////////////////////////////////////////////////////////////////////*  SpriteDefine  */
TFT_eSprite voltage1 = TFT_eSprite(&tft);
TFT_eSprite voltage2 = TFT_eSprite(&tft);
TFT_eSprite current1 = TFT_eSprite(&tft);
TFT_eSprite current2 = TFT_eSprite(&tft);
TFT_eSprite cost1 = TFT_eSprite(&tft);
TFT_eSprite cost2 = TFT_eSprite(&tft);
TFT_eSprite CurrencySprite = TFT_eSprite(&tft);

int Frame;
int SlowPRing;
String LastScreen;
int ScrollDivider;
int SkipToScroll;
int DoubleScreenBarX;

TFT_eSprite UsedEnergy = TFT_eSprite(&tft);
TFT_eSprite Time = TFT_eSprite(&tft);
TFT_eSprite ElectricalCost = TFT_eSprite(&tft);
TFT_eSprite EnergyValue = TFT_eSprite(&tft);
TFT_eSprite TimeValue = TFT_eSprite(&tft);
TFT_eSprite ElCostValue = TFT_eSprite(&tft);

TFT_eSprite FilamentUsed = TFT_eSprite(&tft);
TFT_eSprite FilamentCost = TFT_eSprite(&tft);
TFT_eSprite FilamentCostV = TFT_eSprite(&tft);

TFT_eSprite AvgPsprite = TFT_eSprite(&tft);
TFT_eSprite MaxPsprite = TFT_eSprite(&tft);
TFT_eSprite Printing = TFT_eSprite(&tft);
TFT_eSprite Standby = TFT_eSprite(&tft);
TFT_eSprite PrinterSprite = TFT_eSprite(&tft);
TFT_eSprite Off = TFT_eSprite(&tft);
TFT_eSprite Printsec = TFT_eSprite(&tft);
TFT_eSprite Printmin = TFT_eSprite(&tft);
TFT_eSprite Printhour = TFT_eSprite(&tft);

TFT_eSprite FilamentSpool = TFT_eSprite(&tft);
TFT_eSprite FilamentStats = TFT_eSprite(&tft);
TFT_eSprite NoSpool = TFT_eSprite(&tft);
TFT_eSprite CurrentSpoolSprite = TFT_eSprite(&tft);
TFT_eSprite CurSpoolFWSprite = TFT_eSprite(&tft);
TFT_eSprite CurSpoolFLSprite = TFT_eSprite(&tft);
TFT_eSprite CurSpoolPerSprite = TFT_eSprite(&tft);

/////////////////////////////////////////////////////////////////////////////////*  Web Page - App  */
String header;

String Value;

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 1000;

// Set your Static IP address
IPAddress local_IP(192, 168, 1, 184);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);

IPAddress subnet(255, 255, 0, 0);
IPAddress primaryDNS(8, 8, 8, 8);   // optional
IPAddress secondaryDNS(8, 8, 4, 4); // optional

TaskHandle_t Task1;


//*******************************************************************************************************
//                                          - Functions -
//*******************************************************************************************************


//////////////////////////////////////////////////////////////////////////*  Settings Select (this will be removed in new version)  */
void SettingsSelectVoid () {
  tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
  tft.setTextFont(4);
  if (SettingsSelect == 0 || SettingsSelect == 6) {
    tft.setCursor(4, 3);
    tft.print(">");
    tft.setCursor(4, 23);
    tft.print("   ");
    tft.setCursor(4, 43);
    tft.print("   ");
    tft.setCursor(4, 63);
    tft.print("   ");
    tft.setCursor(4, 83);
    tft.print("   ");
    tft.setCursor(4, 101);
    tft.print("   ");
  } else if (SettingsSelect == 1 || SettingsSelect == 7) {
    tft.setCursor(4, 3);
    tft.print("   ");
    tft.setCursor(4, 23);
    tft.print(">");
    tft.setCursor(4, 43);
    tft.print("   ");
    tft.setCursor(4, 63);
    tft.print("   ");
    tft.setCursor(4, 83);
    tft.print("   ");
    tft.setCursor(4, 101);
    tft.print("   ");
  } else if (SettingsSelect == 2 || SettingsSelect == 8) {
    tft.setCursor(4, 3);
    tft.print("   ");
    tft.setCursor(4, 23);
    tft.print("   ");
    tft.setCursor(4, 43);
    tft.print(">");
    tft.setCursor(4, 63);
    tft.print("   ");
    tft.setCursor(4, 83);
    tft.print("   ");
    tft.setCursor(4, 101);
    tft.print("   ");
  } else if (SettingsSelect == 3 || SettingsSelect == 9) {
    tft.setCursor(4, 3);
    tft.print("   ");
    tft.setCursor(4, 23);
    tft.print("   ");
    tft.setCursor(4, 43);
    tft.print("   ");
    tft.setCursor(4, 63);
    tft.print(">");
    tft.setCursor(4, 83);
    tft.print("   ");
    tft.setCursor(4, 101);
    tft.print("   ");
  } else if (SettingsSelect == 4 || SettingsSelect == 10) {
    tft.setCursor(4, 3);
    tft.print("   ");
    tft.setCursor(4, 23);
    tft.print("   ");
    tft.setCursor(4, 43);
    tft.print("   ");
    tft.setCursor(4, 63);
    tft.print("   ");
    tft.setCursor(4, 83);
    tft.print(">");
    tft.setCursor(4, 101);
    tft.print("   ");
  } else if (SettingsSelect == 5 || SettingsSelect == 11) {
    tft.setCursor(4, 3);
    tft.print("   ");
    tft.setCursor(4, 23);
    tft.print("   ");
    tft.setCursor(4, 43);
    tft.print("   ");
    tft.setCursor(4, 63);
    tft.print("   ");
    tft.setCursor(4, 83);
    tft.print("   ");
    tft.setCursor(4, 101);
    tft.print(">");
  }
}


////////////////////////////////////////////////////////////////////////////////*  Filament Encoder  */
void FILupdateEncoder () {
  sensor01 = digitalRead(FILpin1);
  sensor02 = digitalRead(FILpin2);

  if(sensor01 == 1 && sensor02 == 1){
    if(stepOld == 1){
      FILChange--;
    }
    if(stepOld == 3){
      FILChange++;
    }
    stepOld = 0;
  }

  if(sensor01 == 0 && sensor02 == 1){
    if(stepOld == 2){
      FILChange--;
    }
    if(stepOld == 0){
      FILChange++;
    }
    stepOld = 1;
  }

  if(sensor01 == 0 && sensor02 == 0){
    if(stepOld == 3){
      FILChange--;
    }
    if(stepOld == 1){
      FILChange++;
    }
    stepOld = 2;
  }

  if(sensor01 == 1 && sensor02 == 0){
    if(stepOld == 0){
      FILChange--;
    }
    if(stepOld == 2){
      FILChange++;
    }
    stepOld = 3;
  }
}

////////////////////////////////////////////////////////////////////////*  Materials  */
void MaterialVoid() {
  if (Material == "PLA") {
    currentMATLW = PLALW;
    currentMATFC = PLAFC;
  } else if (Material == "PETG") {
    currentMATLW = PETGLW;
    currentMATFC = PETGFC;
  } else if (Material == "ABS") {
    currentMATLW = ABSLW;
    currentMATFC = ABSFC;
  } else if (Material == "TPU") {
    currentMATLW = TPULW;
    currentMATFC = TPUFC;
  } else if (Material == "Nylon") {
    currentMATLW = NylonLW;
    currentMATFC = NylonFC;
  } else if (Material == "PVA") {
    currentMATLW = PVALW;
    currentMATFC = PVAFC;
  } else if (Material == "HIPS") {
    currentMATLW = HIPSLW;
    currentMATFC = HIPSFC;
  } else if (Material == "ASA") {
    currentMATLW = ASALW;
    currentMATFC = ASAFC;
  } else if (Material == "PC") {
    currentMATLW = PCLW;
    currentMATFC = PCFC;
  } else if (Material == "Custom1") {
    currentMATLW = Custom1LW;
    currentMATFC = Custom1FC;
  } else if (Material == "Custom2") {
    currentMATLW = Custom2LW;
    currentMATFC = Custom2FC;
  }
}

void MaterialSaveVoid() {
  if (EditMaterial == "PLA") {
    PLALW = DensitymEdit;
    PLAFC = CostkgEdit;
  } else if (EditMaterial == "PETG") {
    PETGLW = DensitymEdit;
    PETGFC = CostkgEdit;
  } else if (EditMaterial == "ABS") {
    ABSLW = DensitymEdit;
    ABSFC = CostkgEdit;
  } else if (EditMaterial == "TPU") {
    TPULW = DensitymEdit;
    TPUFC = CostkgEdit;
  } else if (EditMaterial == "Nylon") {
    NylonLW = DensitymEdit;
    NylonFC = CostkgEdit;
  } else if (EditMaterial == "PVA") {
    PVALW = DensitymEdit;
    PVAFC = CostkgEdit;
  } else if (EditMaterial == "HIPS") {
    HIPSLW = DensitymEdit;
    HIPSFC = CostkgEdit;
  } else if (EditMaterial == "ASA") {
    ASALW = DensitymEdit;
    ASAFC = CostkgEdit;
  } else if (EditMaterial == "PC") {
    PCLW = DensitymEdit;
    PCFC = CostkgEdit;
  } else if (EditMaterial == "Custom1") {
    Custom1LW = DensitymEdit;
    Custom1FC = CostkgEdit;
  } else if (EditMaterial == "Custom2") {
    Custom2LW = DensitymEdit;
    Custom2FC = CostkgEdit;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////*  Filament 2 screen show spool  */
void SpoolShow() {
  if (CurrentSpool == 1) {
    CurSpoolWeight = Spool1Weight;
    CurSpoolFW = Spool1FW;
    CurSpoolFL = Spool1FL;
    Spool1Percentage = round((Spool1FW / Spool1Weight) * 100);
    CurSpoolPercentage = Spool1Percentage;
  } else if (CurrentSpool == 2) {
    CurSpoolWeight = Spool2Weight;
    CurSpoolFW = Spool2FW;
    CurSpoolFL = Spool2FL;
    Spool2Percentage = round((Spool2FW / Spool2Weight) * 100);
    CurSpoolPercentage = Spool2Percentage;
  } else if (CurrentSpool == 3) {
    CurSpoolWeight = Spool3Weight;
    CurSpoolFW = Spool3FW;
    CurSpoolFL = Spool3FL;
    Spool3Percentage = round((Spool3FW / Spool3Weight) * 100);
    CurSpoolPercentage = Spool3Percentage;
  } else if (CurrentSpool == 4) {
    CurSpoolWeight = Spool4Weight;
    CurSpoolFW = Spool4FW;
    CurSpoolFL = Spool4FL;
    Spool4Percentage = round((Spool4FW / Spool4Weight) * 100);
    CurSpoolPercentage = Spool4Percentage;
  } else if (CurrentSpool == 5) {
    CurSpoolWeight = Spool5Weight;
    CurSpoolFW = Spool5FW;
    CurSpoolFL = Spool5FL;
    Spool5Percentage = round((Spool5FW / Spool5Weight) * 100);
    CurSpoolPercentage = Spool5Percentage;
  }

  if (SpoolMaterial[CurrentSpool - 1] == 1) {
    CurSpoolLenght = round(CurSpoolWeight / PLALW);
    CurSpoolFL = round(CurSpoolFW / PLALW);
    CurSpoolMatText = "PLA";
  } else if (SpoolMaterial[CurrentSpool - 1] == 2) {
    CurSpoolLenght = round(CurSpoolWeight / PETGLW);
    CurSpoolFL = round(CurSpoolFW / PETGLW);
    CurSpoolMatText = "PETG";
  } else if (SpoolMaterial[CurrentSpool - 1] == 3) {
    CurSpoolLenght = round(CurSpoolWeight / ABSLW);
    CurSpoolFL = round(CurSpoolFW / ABSLW);
    CurSpoolMatText = "ABS";
  } else if (SpoolMaterial[CurrentSpool - 1] == 4) {
    CurSpoolLenght = round(CurSpoolWeight / TPULW);
    CurSpoolFL = round(CurSpoolFW / TPULW);
    CurSpoolMatText = "TPU";
  } else if (SpoolMaterial[CurrentSpool - 1] == 5) {
    CurSpoolLenght = round(CurSpoolWeight / NylonLW);
    CurSpoolFL = round(CurSpoolFW / NylonLW);
    CurSpoolMatText = "Nylon";
  } else if (SpoolMaterial[CurrentSpool - 1] == 6) {
    CurSpoolLenght = round(CurSpoolWeight / PVALW);
    CurSpoolFL = round(CurSpoolFW / PVALW);
    CurSpoolMatText = "PVA";
  } else if (SpoolMaterial[CurrentSpool - 1] == 7) {
    CurSpoolLenght = round(CurSpoolWeight / HIPSLW);
    CurSpoolFL = round(CurSpoolFW / HIPSLW);
    CurSpoolMatText = "HIPS";
  } else if (SpoolMaterial[CurrentSpool - 1] == 8) {
    CurSpoolLenght = round(CurSpoolWeight / ASALW);
    CurSpoolFL = round(CurSpoolFW / ASALW);
    CurSpoolMatText = "ASA";
  } else if (SpoolMaterial[CurrentSpool - 1] == 9) {
    CurSpoolLenght = round(CurSpoolWeight / PCLW);
    CurSpoolFL = round(CurSpoolFW / PCLW);
    CurSpoolMatText = "PC";
  } else if (SpoolMaterial[CurrentSpool - 1] == 10) {
    CurSpoolLenght = round(CurSpoolWeight / Custom1LW);
    CurSpoolFL = round(CurSpoolFW / Custom1LW);
    CurSpoolMatText = "Custom1";
  } else if (SpoolMaterial[CurrentSpool - 1] == 11) {
    CurSpoolLenght = round(CurSpoolWeight / Custom2LW);
    CurSpoolFL = round(CurSpoolFW / Custom2LW);
    CurSpoolMatText = "Custom2";
  }
  Material = CurSpoolMatText;

  tft.setTextPadding(tft.textWidth("10000.00g / 10000g", 2));

  tft.setTextColor(TFT_WHITE);

  tft.drawString((String)CurrentSpool + ". " + CurSpoolMatText, 79, 28, GFXFF);

  tft.setTextColor(TFT_WHITE, GreyBlue);

  tft.drawString((String)CurSpoolFW + "g / " + (String)CurSpoolWeight + "g", 79, 50, 2);

  tft.drawString((String)(int)(CurSpoolFL) + "m / " + (String)CurSpoolLenght + "m", 79, 70, 2);

  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  if (CurSpoolPercentage > 100){
    tft.drawString((String)100 + "% Left", 79, 94, 2);
  } else {
    tft.drawString((String)CurSpoolPercentage + "% Left", 79, 94, 2);
  }

  tft.setTextPadding(0);

  if (LastCurSpoolPercentage != CurSpoolPercentage) {
    LastCurSpoolPercentage = CurSpoolPercentage;
    if (SpoolBar == 1){
        for(int x = 0; x <= 100; x++){
          tft.fillRoundRect(29, 112, x, 8, 4, GreyBlue);
          delay(2);
        }
        for(int x = 0; x <= CurSpoolPercentage; x++){
          tft.fillRoundRect(29, 112, x, 8, 4, LightGreen);
          delay(2);
        }
        SpoolBar = 0;
    } else {
      tft.fillRoundRect(29, 112, 100, 8, 4, GreyBlue);
      tft.fillRoundRect(29, 112, CurSpoolPercentage, 8, 4, LightGreen);
    }
  }
 
}

////////////////////////////////////////////////////////////////////////////////////////*  Spool Percentage  */
void SpoolPercentage() {
  if (CurrentSpool == 1) {
    Spool1Percentage = round((Spool1FW / Spool1Weight) * 100);
    CurSpoolPercentage = Spool1Percentage;
  } else if (CurrentSpool == 2) {
    Spool2Percentage = round((Spool2FW / Spool2Weight) * 100);
    CurSpoolPercentage = Spool2Percentage;
  } else if (CurrentSpool == 3) {
    Spool3Percentage = round((Spool3FW / Spool3Weight) * 100);
    CurSpoolPercentage = Spool3Percentage;
  } else if (CurrentSpool == 4) {
    Spool4Percentage = round((Spool4FW / Spool4Weight) * 100);
    CurSpoolPercentage = Spool4Percentage;
  } else if (CurrentSpool == 5) {
    Spool5Percentage = round((Spool5FW / Spool5Weight) * 100);
    CurSpoolPercentage = Spool5Percentage;
  }

    if (CurrentSpool == 1) {
    CurSpoolWeight = Spool1Weight;
    CurSpoolFW = Spool1FW;
    CurSpoolFL = Spool1FL;
    Spool1Percentage = round((Spool1FW / Spool1Weight) * 100);
    CurSpoolPercentage = Spool1Percentage;
  } else if (CurrentSpool == 2) {
    CurSpoolWeight = Spool2Weight;
    CurSpoolFW = Spool2FW;
    CurSpoolFL = Spool2FL;
    Spool2Percentage = round((Spool2FW / Spool2Weight) * 100);
    CurSpoolPercentage = Spool2Percentage;
  } else if (CurrentSpool == 3) {
    CurSpoolWeight = Spool3Weight;
    CurSpoolFW = Spool3FW;
    CurSpoolFL = Spool3FL;
    Spool3Percentage = round((Spool3FW / Spool3Weight) * 100);
    CurSpoolPercentage = Spool3Percentage;
  } else if (CurrentSpool == 4) {
    CurSpoolWeight = Spool4Weight;
    CurSpoolFW = Spool4FW;
    CurSpoolFL = Spool4FL;
    Spool4Percentage = round((Spool4FW / Spool4Weight) * 100);
    CurSpoolPercentage = Spool4Percentage;
  } else if (CurrentSpool == 5) {
    CurSpoolWeight = Spool5Weight;
    CurSpoolFW = Spool5FW;
    CurSpoolFL = Spool5FL;
    Spool5Percentage = round((Spool5FW / Spool5Weight) * 100);
    CurSpoolPercentage = Spool5Percentage;
  }

  if (SpoolMaterial[CurrentSpool - 1] == 1) {
    CurSpoolLenght = round(CurSpoolWeight / PLALW);
    CurSpoolFL = round(CurSpoolFW / PLALW);
    CurSpoolMatText = "PLA";
  } else if (SpoolMaterial[CurrentSpool - 1] == 2) {
    CurSpoolLenght = round(CurSpoolWeight / PETGLW);
    CurSpoolFL = round(CurSpoolFW / PETGLW);
    CurSpoolMatText = "PETG";
  } else if (SpoolMaterial[CurrentSpool - 1] == 3) {
    CurSpoolLenght = round(CurSpoolWeight / ABSLW);
    CurSpoolFL = round(CurSpoolFW / ABSLW);
    CurSpoolMatText = "ABS";
  } else if (SpoolMaterial[CurrentSpool - 1] == 4) {
    CurSpoolLenght = round(CurSpoolWeight / TPULW);
    CurSpoolFL = round(CurSpoolFW / TPULW);
    CurSpoolMatText = "TPU";
  } else if (SpoolMaterial[CurrentSpool - 1] == 5) {
    CurSpoolLenght = round(CurSpoolWeight / NylonLW);
    CurSpoolFL = round(CurSpoolFW / NylonLW);
    CurSpoolMatText = "Nylon";
  } else if (SpoolMaterial[CurrentSpool - 1] == 6) {
    CurSpoolLenght = round(CurSpoolWeight / PVALW);
    CurSpoolFL = round(CurSpoolFW / PVALW);
    CurSpoolMatText = "PVA";
  } else if (SpoolMaterial[CurrentSpool - 1] == 7) {
    CurSpoolLenght = round(CurSpoolWeight / HIPSLW);
    CurSpoolFL = round(CurSpoolFW / HIPSLW);
    CurSpoolMatText = "HIPS";
  } else if (SpoolMaterial[CurrentSpool - 1] == 8) {
    CurSpoolLenght = round(CurSpoolWeight / ASALW);
    CurSpoolFL = round(CurSpoolFW / ASALW);
    CurSpoolMatText = "ASA";
  } else if (SpoolMaterial[CurrentSpool - 1] == 9) {
    CurSpoolLenght = round(CurSpoolWeight / PCLW);
    CurSpoolFL = round(CurSpoolFW / PCLW);
    CurSpoolMatText = "PC";
  } else if (SpoolMaterial[CurrentSpool - 1] == 10) {
    CurSpoolLenght = round(CurSpoolWeight / Custom1LW);
    CurSpoolFL = round(CurSpoolFW / Custom1LW);
    CurSpoolMatText = "Custom1";
  } else if (SpoolMaterial[CurrentSpool - 1] == 11) {
    CurSpoolLenght = round(CurSpoolWeight / Custom2LW);
    CurSpoolFL = round(CurSpoolFW / Custom2LW);
    CurSpoolMatText = "Custom2";
  }
  if (CurrentSpool > 0){
    Material = CurSpoolMatText;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Runout Sensor  */
void FilamentRunoutSensor() {
  if (digitalRead(FilRunoutSensorPin) == LOW && NoFilament == 1) {
    screen = "FilamentLoaded";
    clearScreen = 0;
    RelayState = 1;
    digitalWrite(RelayPin, HIGH);
    NoFil = 0;
    NoFilament = 0;
    BuzzerState = 0;
  } else if (digitalRead(FilRunoutSensorPin) == HIGH && NoFil == 0) {
    FilRunoutSensorMillis = millis();
    NoFil = 1;
  } else if (digitalRead(FilRunoutSensorPin) == HIGH && NoFil == 1 && millis() - FilRunoutSensorMillis >= 1000 && NoFilament == 0) {
    NoFilament = 1;
    screen = "NoFilament";
    clearScreen = 0;
    if (AlertsSound == 1){
      BuzzerOFF = 0;
    }
    RelayState = 0;
    digitalWrite(RelayPin, LOW);
    BuzzerNoFilTimeoutMillis = millis();
  } else if (NoFilament == 1 && millis() - BuzzerNoFilMillis >= 1000 && millis() - BuzzerNoFilTimeoutMillis < 10000 && AlertsSound == 1) {
    BuzzerNoFilMillis = millis();
    if (BuzzerState == 0) {
      BuzzerState = 1;
      ledcWriteTone(3, 1976);
    } else if (BuzzerState == 1) {
      BuzzerState = 0;
      ledcWriteTone(3, 0);
    }
  } else if (millis() - BuzzerNoFilTimeoutMillis >= 10000 && BuzzerOFF == 0) {
    ledcWriteTone(3, 0);
    BuzzerOFF = 1;
    BuzzerState = 0;
  } else if (BuzzerState == 1 && millis() - BuzzerNoFilTimeoutMillis >= 10000) {
    BuzzerState == 0;
    ledcWriteTone(3, 0);
  }
  if (digitalRead(FilRunoutSensorPin) == LOW && NoFil == 1) {
    NoFil = 0;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Filament Jams Sensor  */
void FilamentJamsSensor() {
  if (PrintingON == 1 && millis() - FilPrintingMillis >= 40000 && FilJammed == 0 && P >= 30) {
    FilJammed = 1;
    RelayState = 0;
    digitalWrite(RelayPin, LOW);
    if (AlertsSound == 1){
      BuzzerOFF = 0;
    }
    BuzzerFilJamTimeoutMillis = millis();
    screen = "FilJamDetected";
    clearScreen = 0;
  } else if (millis() - FilPrintingMillis < 40000) {
    if (FilJammed == 1) {
      FilJammed = 0;
      ledcWriteTone(3, 0);
      BuzzerOFF = 1;
      BuzzerState = 0;
      RelayState = 1;
      digitalWrite(RelayPin, HIGH);
    } else if (FilJammed == 0) {
    }
  } else if (FilJammed == 1 && millis() - BuzzerFilJamMillis >= 1000 && millis() - BuzzerFilJamTimeoutMillis < 10000 && AlertsSound == 1) {
    BuzzerFilJamMillis = millis();
    if (BuzzerState == 0) {
      BuzzerState = 1;
      ledcWriteTone(3, 1976);
    } else if (BuzzerState == 1) {
      BuzzerState = 0;
      ledcWriteTone(3, 0);
    }
  } else if (millis() - BuzzerFilJamTimeoutMillis >= 10000 && BuzzerOFF == 0) {
    ledcWriteTone(3, 0);
    BuzzerOFF = 1;
    BuzzerState = 0;
  } else if (millis() - FilPrintingMillis >= 40000) {
    PrintingMillis = millis();
  } else if (BuzzerState == 1 && millis() - BuzzerFilJamTimeoutMillis >= 10000) {
    BuzzerState = 0;
    ledcWriteTone(3, 0);
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Printing  */
void PrintingVoid() {
  if (P >= 30 && millis() - PrintingMillis >= 40000 && millis() - FilPrintingMillis < 40000 && NoFilament == 0 && FilJammed == 0 && PrintingON == 0) {
    PrintingON = 1;
    PrevScreen = screen;
    screen = "PrintingON";
    clearScreen = 0;
  }

  if (FilJamsSensor == 0) {
    if (PrintingON == 1) {
      if (PrintingP == 0 || millis() - FilPrintingMillis >= 40000 || NoFilament == 1) {
        if (AutoOff == 1 && millis() - PrintingMillis >= AutoOffMillis && NoFilament == 0 && P < 30) {
          AutoOffStart = 1;
          RelayState = 0;
          digitalWrite(RelayPin, LOW);
          BuzzerAutoOffMillis = millis();
          BuzzerAutoOffTimeoutMillis = millis();
          screen = "AutoOffScreen";
          clearScreen = 0;
        } else {
          if (NoFilament == 0) {
            PrevScreen = screen;
            screen = "PrintingOFF";
            clearScreen = 0;
          }
        }
        PrintingON = 0;
        PrintingMillis = millis();
      }
    } else if (PrintingON == 0) {
      if (PrintingP == 0 || millis() - FilPrintingMillis >= 20000 || NoFilament == 1) {
        PrintingON = 0;
        PrintingMillis = millis();
      }
    }
  } else if (FilJamsSensor == 1) {
    if (PrintingON == 1) {
      if (PrintingP == 0 || NoFilament == 1 || FilJammed == 1) {
        if (AutoOff == 1 && millis() - PrintingMillis >= AutoOffMillis && NoFilament == 0 && P < 30) {
          AutoOffStart = 1;
          RelayState = 0;
          digitalWrite(RelayPin, LOW);
          BuzzerAutoOffMillis = millis();
          BuzzerAutoOffTimeoutMillis = millis();
          screen = "AutoOffScreen";
          clearScreen = 0;
        } else {
          if (NoFilament == 0 && P < 30) {
            PrevScreen = screen;
            screen = "PrintingOFF";
            clearScreen = 0;
          }
        }
        PrintingON = 0;
        PrintingMillis = millis();
      }
    } else if (PrintingON == 0) {
      if (PrintingP == 0 || millis() - FilPrintingMillis >= 20000 || NoFilament == 1) {
        PrintingON = 0;
        PrintingMillis = millis();
      }
    }
  }
  if (P >= 30) {
    PrintingP = 1;
    PrintingPMillis = millis();
  } else if (P < 30 && millis() - PrintingPMillis >= 10000) {
    PrintingP = 0;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////*  Automatic Off  */
void AutoOffVoid() {
  if (AlertsSound == 1){
    if (millis() - BuzzerAutoOffMillis >= 1000 && millis() - BuzzerAutoOffTimeoutMillis < 10000) {
    BuzzerAutoOffMillis = millis();
    if (BuzzerState == 0) {
      BuzzerState = 1;
      ledcWriteTone(3, 1976);
    } else if (BuzzerState == 1) {
      BuzzerState = 0;
      ledcWriteTone(3, 0);
    }
  } else if (millis() - BuzzerAutoOffTimeoutMillis >= 10000 && BuzzerOFF == 0) {
    ledcWriteTone(3, 0);
    BuzzerOFF = 1;
    BuzzerState = 0;
  } else if (BuzzerState == 1 && millis() - BuzzerAutoOffTimeoutMillis >= 10000) {
    BuzzerState = 0;
    ledcWriteTone(3, 0);
  }
  }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////*  Printing Time  */
void PrintingTimeVoid() {
  if (PrintingON == 1) {
    if ((millis() - PrintingMillis) - PrintingTime >= 1000) {
      PrintingMillisLeft = PrintingMillisLeft + ((millis() - PrintingMillis) - PrintingTime) - 1000;
      PrintingTime = millis() - PrintingMillis;
      Serial.println(PrintingMillisLeft);
      if (PrintingMillisLeft >= 1000){
        PrintSec = PrintSec + 1;
        PrintingMillisLeft = 0;
      }
      PrintSec = PrintSec + 1;
      if (PrintSec >= 60) {
        PrintMin = PrintMin + 1;
        PrintSec = 0;
      }
      if (PrintMin >= 60) {
        PrintMin = 0;
        PrintHour = PrintHour + 1;
      }
    }
  } else if (PrintingON == 0) {
    PrintSec = 0;
    PrintMin = 0;
    PrintHour = 0;
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////* Analog Power Ring  */

void Task2code( void * pvParameters ) {
  for (;;) {
    if (screen != "HomeScreen"){
      vTaskDelay(100);
    } else {
      vTaskDelay(10);
    }

    if (P > PrintP){
    PrintP = PrintP + 1;
  } else if (P < PrintP){
    PrintP = PrintP - 1;
  } else if (PrintP == P){
    PrintP = P;
  }
 }
}

void PowerRing(){
  int xpos = 7, ypos = 58, gap = 4, radius = 35;
  xpos = gap + ringMeter(PrintP, 0, 350, xpos, ypos, radius, "W", BLUE2RED); // Draw analogue meter
}

  int ringMeter(int value, int vmin, int vmax, int x, int y, int r, char *units, byte scheme)
{
  
  x += r; y += r;   // Calculate coords of centre of ring

  int w = r / 6;    // Width of outer ring is 1/4 of radius
  
  int angle = 150;  // Half the sweep angle of meter (300 degrees)

  int text_colour = 0; // To hold the text colour

  int v = map(value, vmin, vmax, -angle, angle); // Map the value to an angle v

  byte seg = 5; // Segments are 5 degrees wide = 60 segments for 300 degrees
  byte inc = 5; // Draw segments every 5 degrees, increase to 10 for segmented ring

  // Draw colour blocks every inc degrees
  for (int i = -angle; i < angle; i += inc) {
    if (SlowPRing == 1){
      delay(4);
    }

    // Choose colour from scheme
    int colour = 0;
    switch (scheme) {
      case 0: colour = TFT_RED; break; // Fixed colour
      case 1: colour = TFT_GREEN; break; // Fixed colour
      case 2: colour = TFT_BLUE; break; // Fixed colour
      case 3: colour = rainbow(map(i, -angle, angle, 0, 127)); break; // Full spectrum blue to red
      case 4: colour = rainbow(map(i, -angle, angle, 63, 127)); break; // Green to red (high temperature etc)
      case 5: colour = rainbow(map(i, -angle, angle, 127, 63)); break; // Red to green (low battery etc)
      default: colour = TFT_BLUE; break; // Fixed colour
    }

    // Calculate pair of coordinates for segment start
    float sx = cos((i - 90) * 0.0174532925);
    float sy = sin((i - 90) * 0.0174532925);
    uint16_t x0 = sx * (r - w) + x;
    uint16_t y0 = sy * (r - w) + y;
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;

    // Calculate pair of coordinates for segment end
    float sx2 = cos((i + seg - 90) * 0.0174532925);
    float sy2 = sin((i + seg - 90) * 0.0174532925);
    int x2 = sx2 * (r - w) + x;
    int y2 = sy2 * (r - w) + y;
    int x3 = sx2 * r + x;
    int y3 = sy2 * r + y;

    if (i < v) { // Fill in coloured segments with 2 triangles
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, Purple);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, Purple);
      text_colour = colour; // Save the last colour drawn
    }
    else // Fill in blank segments
    {
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, GreyBlue);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, GreyBlue);
    }
  }
  SlowPRing = 0;

  // Convert value to a string
  char buf[10];
  byte len = 3; if (P > 999) len = 4;
  dtostrf(P, len, 0, buf);

    // Set the text colour to default
   tft.setTextColor(TFT_WHITE, TFT_BLACK);
   if (P > 0){
    tft.setTextColor(Purple, TFT_BLACK);
   } else if (P == 0){
     tft.setTextColor(Purple, TFT_BLACK);
   }
  
  // Print value, if the meter is large then use big font 6, othewise use 4

  if(millis() - PowerRingMillis >= 300){
    PowerRingMillis = millis();

  tft.setTextDatum(TC_DATUM);
  tft.setTextPadding(tft.textWidth("999", 4));
  tft.drawNumber(P, x, y - 20, 4);
  tft.setTextPadding(0);
  tft.setTextDatum(TL_DATUM);

  }

  // Print units, if the meter is large then use big font 4, othewise use 2
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawCentreString(units, x, y + 5, 2); // Units display

  // Calculate and return right hand side x coordinate
  return x + r;
}

// #########################################################################
// Return a 16 bit rainbow colour
// #########################################################################
unsigned int rainbow(byte value)  ////////////////  (not used anymore)
{
  // Value is expected to be in range 0-127
  // The value is converted to a spectrum colour from 0 = blue through to 127 = red

  byte red = 0; // Red is the top 5 bits of a 16 bit colour value
  byte green = 0;// Green is the middle 6 bits
  byte blue = 0; // Blue is the bottom 5 bits

  byte quadrant = value / 32;

  if (quadrant == 0) {
    blue = 31;
    green = 2 * (value % 32);
    red = 0;
  }
  if (quadrant == 1) {
    blue = 31 - (value % 32);
    green = 63;
    red = 0;
  }
  if (quadrant == 2) {
    blue = 0;
    green = 63;
    red = value % 32;
  }
  if (quadrant == 3) {
    blue = 0;
    green = 63 - 2 * (value % 32);
    red = 31;
  }
  return (red << 11) + (green << 5) + blue;
}

// #########################################################################
// Return a value in range -1 to +1 for a given phase angle in degrees
// #########################################################################
float sineWave(int phase) {
  return sin(phase * 0.0174532925);
}

//////////////////////////////////////////////////////////////////////////////////* Auto scrool  */
void AutoScrollVoid(){
  if (millis() - NoTouchMillis > AutoScrollMillis){
    if (millis() - AutoScrollScreenMillis >= 5000){
      AutoScrollScreenMillis = millis();
      if (AutoScrollMode == 1){
        AutoScrollScreenCounter = AutoScrollScreenCounter + 1;
        if (AutoScrollScreenCounter > 2){
            AutoScrollScreenCounter = 0;
        }
          if (AutoScrollScreenCounter == 0){
            screen = "HomeScreen";
            ScreenCounter = 0;
            clearScreen = 0;
            CurrencyChange = 1;
          } else if (AutoScrollScreenCounter == 1){
            screen = "Energy";
            ScreenCounter = 1;
            clearScreen = 0;
            CurrencyChange = 1;
          } else if (AutoScrollScreenCounter == 2){
            screen = "Filament";
            ScreenCounter = -1;
            clearScreen = 0;
            CurrencyChange = 1;
          }
      } else if (AutoScrollMode == 2){
          AutoScrollScreenCounter = AutoScrollScreenCounter + 1;
          if (AutoScrollScreenCounter > 4){
            AutoScrollScreenCounter = 0;
          }
          if (AutoScrollScreenCounter == 0){
            screen = "HomeScreen";
            ScreenCounter = 0;
            clearScreen = 0;
            CurrencyChange = 1;
          } else if (AutoScrollScreenCounter == 1){
            screen = "Energy";
            ScreenCounter = 1;
            clearScreen = 0;
            CurrencyChange = 1;
          } else if (AutoScrollScreenCounter == 2){
            screen = "Filament";
            ScreenCounter = -1;
            clearScreen = 0;
            CurrencyChange = 1;
          } else if (AutoScrollScreenCounter == 3){
            screen = "Energy2";
            ScreenCounter = 2;
            clearScreen = 0;
          } else if (AutoScrollScreenCounter == 4){
            screen = "Filament2";
            ScreenCounter = -2;
            clearScreen = 0;
          }
      }
    }
  } else {
    AutoScrollScreenCounter = -1;
  }
}
