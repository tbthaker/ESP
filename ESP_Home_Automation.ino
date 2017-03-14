***********************************************************************************************
Author: Tejas Thaker    
mail id: tbthaker@gmail.com
***********************************************************************************************


#include <ESP8266WiFi.h>

const char* ssid = "ESP";
const char* password = "12345678";
IPAddress ip(192, 168, 43, 9); 
IPAddress gateway(192, 168, 43, 254); 
IPAddress subnet(255, 255, 255, 0); 

int switch1 = 16; 
int switch2 = 14; 
int switch3 = 12; 
int switch4 = 13; 
int value1,value2,value3,value4;

WiFiServer server(80);
void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  value1=value2=value3=value4=LOW;
}
void loop() 
{
  WiFiClient client = server.available();
  if (!client) 
  {
    return;
  }
  Serial.println("new client");
  while(!client.available())
  {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  if (request.indexOf("/LED=ON1") != -1)
  {
    digitalWrite(switch1, HIGH);
    value1 = HIGH;
  } 
  if (request.indexOf("/LED=OFF1") != -1)
  {
   digitalWrite(switch1, LOW);
    value1 = LOW;
  }

  if (request.indexOf("/LED=ON2") != -1)
  {
    digitalWrite(switch2, HIGH);
    value2 = HIGH;
  } 
  if (request.indexOf("/LED=OFF2") != -1)
  {
    digitalWrite(switch2, LOW);
    value2 = LOW;
  }
  if (request.indexOf("/LED=ON3") != -1)
  {
    digitalWrite(switch3, HIGH);
    value3 = HIGH;
  } 
  if (request.indexOf("/LED=OFF3") != -1)
  {
    digitalWrite(switch3, LOW);
    value3 = LOW;
  }
  if (request.indexOf("/LED=ON4") != -1)
  {
    digitalWrite(switch4, HIGH);
    value4 = HIGH;
  } 

  if (request.indexOf("/LED=OFF4") != -1)
  {
    digitalWrite(switch4, LOW);
    value4 = LOW;
  }
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<center>");
  client.println("<body>");
client.println("<body bgcolor=celeste>");
//client.println("<border>");
client.println("<border 1px solid black>");
//client.println("<body = bgcolor=teal>");

  client.println("<div><font size=95><font color=’chocolate ’><h1><class=dotted>...Home Automation...</font></font color></h1></div>");
  client.println("</border>"); 
  client.println("<br><br>");    
  client.println("<br><br>");
  client.println("<br>");
  client.println("<table>");
  client.println(" <border><table><tr><td><font size=90><font color=’chocolate ’><b>Switch 1--- </b><a href=\"LED=ON1\"><button><font size=75><font color= GREEN>ON</button></a>&nbsp;<a href=\"/LED=OFF1\"><button><font size=75><font color= RED>OFF</button></font></a><br></tr></td></table></border>");
  client.println(" <table><tr><td><font size=95><font color=’chocolate ’><b>Switch 2--- </b><a href=\"LED=ON2\"><button><font size=75><font color= GREEN>ON</button></a>&nbsp;<a href=\"/LED=OFF2\"><button><font size=75><font color= RED>OFF</button></font></a><br></tr></td></table>");
  client.println(" <table><tr><td><font size=95><font color=’chocolate ’><b>Switch 3--- </b><a href=\"LED=ON3\"><button><font size=75><font color= GREEN>ON</button></a>&nbsp;<a href=\"/LED=OFF3\"><button><font size=75><font color= RED>OFF</button></font></a><br></tr></td></table>");
  client.println(" <table><tr><td><font size=95><font color=’chocolate ’><b>Switch 4--- </b><a href=\"LED=ON4\"><button><font size=75><font color= GREEN>ON</button></a>&nbsp;<a href=\"/LED=OFF4\"><button><font size=75><font color= RED>OFF</button></font></a></tr></td></table>");
  client.println("<br><br>");    
     if(value1 == HIGH) 
     {
        client.print("<td><font size=60><font color=’chocolate ’>Device1 is: </font>");
        client.print("<font size=75><font color= GREEN>ON</font>");  

     } 
    else 
    {
      client.print("<font size=75><font color=’chocolate ’>Device1 is: </font>");
      client.print("<font size=75><font color= RED>OFF</font>");
  
    }
     client.println("<br>");
         if(value2 == HIGH) 
     {
        client.print("<font size=75><font color=’chocolate ’>Device2 is: </font>");
        client.print("<font size=75><font color= GREEN>ON</font>");  

     } 
    else 
    {
      client.print("<font size=75><font color=’chocolate ’>Device2 is: </font>");
      client.print("<font size=75><font color= RED>OFF</font>");
  
    }
     client.println("<br>");
         if(value3 == HIGH) 
     {
        client.print("<font size=75><font color=’chocolate ’>Device3 is: </font>");
        client.print("<font size=75><font color= GREEN>ON</font>");  

     } 
    else 
    {
      client.print("<font size=75><font color=’chocolate ’>Device3 is: </font>");
      client.print("<font size=75><font color= RED>OFF</font>");
  
    }
     client.println("<br>");
     if(value4 == HIGH) 
     {
        client.print("<font size=75><font color=’chocolate ’>Device4 is: </font>");
        client.print("<font size=75><font color= GREEN>ON</font>");  

     } 
    else 
    {
      client.print("<font size=75><font color=’chocolate ’>Device4 is: </font>");
      client.print("<font size=75><font color= RED>OFF</font></td></tr></table>");
  
    }
       client.println("</table>");
  client.println("</body>");
  client.println("</center>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
