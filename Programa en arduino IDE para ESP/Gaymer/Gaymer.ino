
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

MDNSResponder mdns;

// Replace with your network credentials
const char* ssid = "construpinos";
const char* password = "C5j23h42";
int Reles[]= {4,5,12,13,14,16};//array to store pin nos

ESP8266WebServer server(80);

String webPage = "";
//int gpio0_pin = 15;
//int gpio2_pin = 5;

void setup(void){
  webPage += "<style>.caja{color:white;font-style: bold;margin:20px;text-align:center;}.pie{color:white;font-style: bold;margin:20px;text-align: left;font-size:20px;text-align:center;margin-top:20px;}.nombres{color:white;font-style: bold;margin:20px;text-align: left;font-size:15px;}.botones{margin:10px;margin-left:0.1%;}</style><div style="background-color:green; width: 100%;height: 100%"><h1 style="color:white;font-style:bold;text-align:center">Control Wi-Fi para iluminacion - Ferreteria Construrama los pinos</h1><div class="caja"><p>Rele #1 </p><a class="botones" href="socket1On/"><button>ON</button></a><a class="botones" href="socket1Off/"><button>OFF</button></a>&nbsp;</div><div class="caja"><p>Rele #2</p><a class="botones" href="socket2On/"><button>ON</button></a><a class="botones" href="socket2Off/"><button>OFF</button></a>&nbsp;</div><div class="caja"><p>Rele #3 </p><a class="botones" href="socket3On/"><button>ON</button></a>&nbsp;<a class="botones" href="socket3Off/"><button>OFF</button></a></div><div class="caja"><p>Rele #4</p><a class="botones" href="socket4On/"><button>ON</button></a><a class="botones" href="socket4Off/"><button>OFF</button></a>&nbsp;</div><div class="caja"><p>Rele #5</p><a class="botones" href="socket5On/"><button>ON</button></a>&nbsp;<a class="botones" href="socket5Off/"><button>OFF</button></a></div><div class="caja"><p>Rele #6</p><a class="botones" href="socket6On/"><button>ON</button></a><a class="botones" href="socket6Off/"><button>OFF</button></a>&nbsp;</div><footer class="pie"><p>Integrantes de ingenieria electronica</p><a class="nombres" href="mailto:gaymersteevenmv@ufps.edu.co">Gaymer Mendoza</a><a class="nombres" href="mailto:Jhonatanricardomg@ufps.edu.co">Jhonatan Montoya</a><a class="nombres" href="mailto:yormanalexanderm@ufps.edu.co">Yorman Mendoza</a></footer></div>";
  // preparing GPIOs
    for(int i = 0; i<6 ; i++)
    {
      pinMode(Reles[i], OUTPUT);
      digitalWrite(Reles[i],HIGH);
    }
  
  delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
  
  server.on("/", [](){
    server.send(200, "text/html", webPage);
  });

  server.on("/socket1On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[0], HIGH);
    delay(500);
  });
  server.on("/socket1Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[0], LOW);
    delay(500); 
  });
   server.on("/socket2On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[1], HIGH);
    delay(500);
  });
  server.on("/socket2Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[1], LOW);
    delay(500); 
  });
   server.on("/socket3On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[2], HIGH);
    delay(500);
  });
  server.on("/socket3Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[2], LOW);
    delay(500); 
  });
   server.on("/socket4On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[3], HIGH);
    delay(500);
  });
  server.on("/socket4Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[3], LOW);
    delay(500); 
  });
  server.on("/socket5On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[4], HIGH);
    delay(500);
  });
  server.on("/socket5Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[4], LOW);
    delay(500); 
  });

  server.on("/socket6On", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[5], HIGH);
    delay(500);
  });
  server.on("/socket6Off", [](){
    server.send(200, "text/html", webPage);
    digitalWrite(Reles[5], LOW);
    delay(500); 
  });


  server.begin();
  Serial.println("Servidor iniciado");
}
 
void loop(void){
  server.handleClient();
} 

