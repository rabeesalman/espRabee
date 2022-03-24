#include <Arduino.h>
#include <Arduino_JSON.h>
#include <source.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
#include <Wire.h>
#include <Arduino_JSON.h>
ESP8266WebServer server(80);
const char *ssid = "TP-Link";
const char *password = "15112020";
/////////////////////
String jsondata = "";
String jsonparameter = "";
JSONVar dataObject;
JSONVar param;
//////////////////////
struct data_Rx_from_Arduino_toesp
{ // 12 data 16 byte total
    float TEMP;
    uint16_t year;
    uint8_t HUMI;
    uint8_t COUNTER;
    uint8_t DAYS;
    uint8_t second;
    uint8_t minuts;
    uint8_t hours;
    uint8_t day_inweek;
    uint8_t day_inmonth;
    uint8_t month_inyear;
    uint8_t GROP;
    /// GROP= 0, 0, FAN, BATT, DOOR,LAMP,WATER,EGG
    ////////  D7,D6, D5,  D4,  D3,  D2,  D1,   D0
    uint8_t Esecond;
    uint8_t Eminuts;
    uint8_t Ehours;
} sensors = {0.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct parameter_from_Arduino_toesp
{
    float SETTMP;
    float TMPHI;
    float TMPLO;
    uint8_t PERIOD; // IN HOURS
    uint8_t HHI;
    uint8_t HLO;
    uint8_t HACHIN;
    bool TURN;
    /// RTC data
    uint8_t YEAR;
    uint8_t MONTH;
    uint8_t DAY;
    uint8_t HOUR;
    uint8_t MINUT;
} ini_values = {0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

struct tosaveinarduino
{
    uint8_t SIGNAL;
    float SETTMP;
    float TMPHI;
    float TMPLO;
    uint8_t PERIOD; // IN HOURS
    uint8_t HHI;
    uint8_t HLO;
    uint8_t HACHIN;
    bool TURN;
    /// RTC data
    uint8_t YEAR;
    uint8_t MONTH;
    uint8_t DAY;
    uint8_t HOUR;
    uint8_t MINUT;
} toarduino = {'s', 0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void data_Creation()
{
    dataObject["TEMP"] = sensors.TEMP;
    dataObject["YEAR"] = sensors.year;
    dataObject["HUMI"] = sensors.HUMI;
    dataObject["COUNTER"] = sensors.COUNTER;
    dataObject["DAYS"] = sensors.DAYS;
    dataObject["SEC"] = sensors.second;
    dataObject["MINUT"] = sensors.minuts;
    dataObject["HOURS"] = sensors.hours;
    dataObject["DINW"] = sensors.day_inweek;
    dataObject["DINM"] = sensors.day_inmonth;
    dataObject["MONTH"] = sensors.month_inyear;
    dataObject["GROP"] = sensors.GROP;
    dataObject["Esecond"] = sensors.Esecond;
    dataObject["Eminuts"] = sensors.Eminuts;
    dataObject["Ehours"] = sensors.Ehours;
    jsondata = JSON.stringify(dataObject);
}

void param_Creation()
{
    param["SETTMP"] = ini_values.SETTMP;
    param["TMPHI"] = ini_values.TMPHI;
    param["TMPLO"] = ini_values.TMPLO;
    param["PERIOD"] = ini_values.PERIOD;
    param["HHI"] = ini_values.HHI;
    param["HLO"] = ini_values.HLO;
    param["HACHIN"] = ini_values.HACHIN;
    param["TURN"] = ini_values.TURN;
    //////////////
    param["YEAR"] = ini_values.YEAR;
    param["MONTH"] = ini_values.MONTH;
    param["DAY"] = ini_values.DAY;
    param["HOUR"] = ini_values.HOUR;
    param["MINUT"] = ini_values.MINUT;
    jsonparameter = JSON.stringify(param);
}

void getData()
{
    char da = 'd';
    Wire.beginTransmission(8);
    Wire.write(da);
    Wire.endTransmission();
    Wire.requestFrom(8, sizeof(sensors));
    Wire.readBytes((byte *)&sensors, sizeof(sensors));
    data_Creation();
    server.send(200, "text/html", jsondata);
    jsondata = "";
}

void getParameters()
{
    char da = 'p';
    Wire.beginTransmission(8);
    Wire.write(da);
    Wire.endTransmission();
    Wire.requestFrom(8, sizeof(ini_values));
    Wire.readBytes((byte *)&ini_values, sizeof(ini_values));
    param_Creation();
    server.send(200, "text/html", jsonparameter);
    jsonparameter = "";
}

void saveparameter()
{
    String s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13;
    bool turn = 0;

    for (uint8_t i = 0; i < server.args(); i++)
    {
        if (server.argName(i) == "a")
        {
            s1 = server.arg(i);
        }
        if (server.argName(i) == "b")
        {
            s2 = server.arg(i);
        }
        if (server.argName(i) == "c")
        {
            s3 = server.arg(i);
        }
        if (server.argName(i) == "e")
        {
            s4 = server.arg(i);
        }
        if (server.argName(i) == "f")
        {
            s5 = server.arg(i);
        }
        if (server.argName(i) == "g")
        {
            s6 = server.arg(i);
        }
        if (server.argName(i) == "h")
        {
            s7 = server.arg(i);
        }
        if (server.argName(i) == "i")
        {
            s8 = server.arg(i);
        }
        if (server.argName(i) == "j")
        {
            s9 = server.arg(i);
        }
        if (server.argName(i) == "k")
        {
            s10 = server.arg(i);
        }
        if (server.argName(i) == "l")
        {
            s11 = server.arg(i);
        }
        if (server.argName(i) == "m")
        {
            s12 = server.arg(i);
        }
        if (server.argName(i) == "n")
        {
            s13 = server.arg(i);
        }
    }
    // server.send(200, "text/plane", s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8);
    toarduino.SIGNAL = 's';
    toarduino.SETTMP = s1.toFloat();
    toarduino.TMPHI = s2.toFloat();
    toarduino.TMPLO = s3.toFloat();
    toarduino.PERIOD = s4.toInt();
    toarduino.HHI = s5.toInt();
    toarduino.HLO = s6.toInt();
    toarduino.HACHIN = s7.toInt();
    if (s8 == "true")
    {
        turn = 1;
    }
    else
    {
        turn = 0;
    }

    toarduino.TURN = turn;
    ////////////////////////
    toarduino.YEAR = s9.toInt();
    toarduino.MONTH = s10.toInt();
    toarduino.DAY = s11.toInt();
    toarduino.HOUR = s12.toInt();
    toarduino.MINUT = s13.toInt();
    /////////////////////////////
    Wire.beginTransmission(8);
    Wire.write((byte *)&toarduino, sizeof(toarduino)); ////send user new parameters  to save it in arduino and respone with new parameters
    Wire.endTransmission();
    ///////
    // Wire.requestFrom(8, sizeof(ini_values));///the incomening new parameters from arduino after saving should go to update the gui
    // Wire.readBytes((byte *)&ini_values, sizeof(ini_values));
    param_Creation();
    server.send(200, "text/html", jsonparameter);
    jsonparameter = "";
}

void setup()
{
    Wire.begin(0, 2);
    delay(300);
    // IPAddress local_IP(192, 168, 4, 4);
    // IPAddress gate_way(192, 168, 4, 1);
    // IPAddress subnet(255, 255, 255, 0);
    // WiFi.softAPConfig(local_IP, gate_way, subnet);
    // WiFi.mode(WIFI_AP);
    // WiFi.softAP("JSON", "");
    MDNS.begin("esp8266");
    WiFi.begin(ssid, password);
    delay(300);
    server.on("/", []()
              { server.send_P(200, "text/html", test); });
    server.on("/getparam", getParameters);
    server.on("/getdata", getData);
    server.on("/saveparam", saveparameter);
    delay(300);
    server.begin();
}

void loop()

{
    server.handleClient();
    MDNS.update();
}
