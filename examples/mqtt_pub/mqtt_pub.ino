#include <ESP8266WiFi.h>
#include <MQTT.h>


#define CLIENT_ID "client1"

// create MQTT object
MQTT myMqtt(CLIENT_ID, "192.168.1.50", 1883);

//
const char* ssid     = "ssid";
const char* password = "ssid_password";

boolean bIsConnected = false;

//
void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Connecting to MQTT server");  

  // setup callbacks
  myMqtt.onConnected(myConnectedCb);
  myMqtt.onDisconnected(myDisconnectedCb);
  myMqtt.onPublished(myPublishedCb);
  myMqtt.onData(myDataCb);
  
  delay(10);
}

//
void loop() {

  if (bIsConnected) {
    int value = analogRead(A0);
  
    String topic("/");
    topic += CLIENT_ID;
    topic += "/value";
    
    String valueStr(value);
  
    // publish value to topic
    boolean result = myMqtt.publish(topic, valueStr);
  } else {
    // try to connect to mqtt server
    myMqtt.connect();
  }
  
  delay(100);
}


/*
 * 
 */
void myConnectedCb() {
  Serial.println("connected to MQTT server");
  bIsConnected = true;
}

void myDisconnectedCb() {
  Serial.println("disconnected. try to reconnect...");
  bIsConnected = false;
}

void myPublishedCb() {
  //Serial.println("published.");
}

void myDataCb(String& topic, String& data) {
  
  Serial.print(topic);
  Serial.print(": ");
  Serial.println(data);
}



