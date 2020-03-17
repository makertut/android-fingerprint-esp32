#include<WiFi.h>

#define WIFI_STA_NAME "SSID"
#define WIFI_STA_PASS "Password"

WiFiServer server(80);

const int relay = D2;
String inData = "";
String unlockString = "MakerTutor";
bool unlock = false;
int period = 5000; 
unsigned long time_now = 0;

void setup() {
  
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(relay , OUTPUT);

  digitalWrite( relay , LOW);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_STA_NAME);

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_STA_NAME, WIFI_STA_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }

  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("");
  Serial.println("Hello0 WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("new client");
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        if( c== '\n'){

         if( unlockString.equals(inData)){
             // unlock
             digitalWrite(relay,HIGH);
             unlock = true;
             time_now = millis() + period;
         }
          
           inData="";
          
           break;
        }else{
           inData += (char) c;
        }
      }
      delay(1);
    }
    client.stop();
    Serial.println("client disonnected");
  }
  delay(10);

  if( unlock && ( millis() >= time_now  ) ){
        digitalWrite(relay , LOW);
        unlock = false;
  }
  
}
