 #include <Servo.h>
  #include <WiFi.h>
  #include <WiFiNINA.h>
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  #include <DHT.h>
  #include <NTPClient.h>
  #include <WiFiUdp.h>
  char ssid[] = "test";
  char pass[] = "";
  int status = WL_IDLE_STATUS;

  char server[] = "https://dirty-paws.ey.r.appspot.com/status";
    
/*
const char* ssid = "OzSonNet-Parlat";
const char* password =  "*********";
  */
  
  #define RX 2
  #define TX 3
  #define trigPin 7
  #define echoPin 6
  #define led 9
  
  int lm35Pin = A2;
  int okunan_deger = 0;
  int sound = 250;
  int seviye=A1;
  
  float sicaklik_gerilim = 0;
  float sicaklik = 0; 
  
  Servo servo;

  String postData;
  String postVariable = "temp=";
  
  WiFiClient client;
  


    void setup() {

  
          Serial.begin (9600);          
          pinMode(led,OUTPUT);
          pinMode(trigPin, OUTPUT);
          pinMode(echoPin, INPUT);
          servo.attach(8);

          while (status != WL_CONNECTED) {
              Serial.print(" Network named: ");
              Serial.println(ssid);
              status = WiFi.begin(ssid, pass);
              delay(10000);
            }
          
            Serial.print("SSID: ");
            Serial.println(WiFi.SSID());
            IPAddress ip = WiFi.localIP();
            IPAddress gateway = WiFi.gatewayIP();
            Serial.print("IP Address: ");
            Serial.println(ip);
          }


/*
          Serial.begin(115200);
          delay(4000);   
 
          WiFi.begin(ssid, password); 
 
      while (WiFi.status() != WL_CONNECTED) { 
        delay(1000);
        Serial.println("Baglanti bekleniyor");
  }
 
  Serial.println("Baglandi");
 
} */
    
    
            


    void loop() {
        long duration, distance; 
            
              
              digitalWrite(trigPin, LOW);
              delayMicroseconds(2);
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              duration = pulseIn(echoPin, HIGH);
              distance = (duration/2) / 29.1;
              
              okunan_deger = analogRead(lm35Pin);
              sicaklik_gerilim = (okunan_deger / 1023.0)*5000;
              sicaklik = sicaklik_gerilim /10.0; 
            
              Serial.print(sicaklik);
              Serial.println(" celsius");
              
              if (distance < 32) {
                  Serial.println("32cm'den daha yakın");
                  servo.write(120);
              }
              else {
                  servo.write(0);
              }
              if (distance > 60 || distance <= 0){
                  Serial.println("60cm'den daha uzak");
              }
              else {
                  Serial.print(distance);
                  Serial.println(" cm");
              }
                delay(500);
              
              
              int isik = analogRead(A0);
                    Serial.print("Isik seviyesi:");
                    Serial.println(isik);
                    delay(750);
              
                if(isik > 250){            // Mama kabının altında ışık sensörü ile boş mama kabı olduğunda ışık alacağından mama kabı boş oluyor. 
                  digitalWrite(led,HIGH);
                  Serial.print("Mama bitti.");
                }
              
                if(isik < 200){
                  digitalWrite(led,LOW);
                } 
              
                    seviye=analogRead(A1);
                    Serial.print("\n Suyun Seviyesi:");
                    Serial.println(seviye);




/*
               if(WiFi.status()== WL_CONNECTED){  
  
                     HTTPClient http;   
  
                     http.begin("http://jsonplaceholder.typicode.com/posts");  
                     http.addHeader("Content-Type", "text/plain");            
                     int httpResponseCode = http.POST("POSTING from ESP32");   
                    
                             if(httpResponseCode>0){
                            
                              String response = http.getString();                       
                            
                              Serial.println(httpResponseCode);   //Print return code
                              Serial.println(response);           //Print request answer
                            
                             }else{
                            
            Serial.print("Error on sending POST: ");
            Serial.println(httpResponseCode);
                    
   }
  
   http.end();  //Free resources
  
 }else{
  
    Serial.println("Error in WiFi connection");   
  
 }
  
  delay(10000);  
          */          
          int reading = analogRead(led);
          float voltage = reading * 5.0;
          voltage /= 1024.0;
          float temperatureC = (voltage - 0.5) * 100 ;
          float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
        
          postData = postVariable + temperatureF;
        
          if (client.connect(server, 80)) {
            client.println("POST /test/post.php HTTP/1.1");
            client.println("Host: https://dirty-paws.ey.r.appspot.com/status");
            client.println("Content-Type: application/x-www-form-urlencoded");
            client.print("Content-Length: ");
            client.println(postData.length());
            client.println();
            client.print(postData);
          }
        
          if (client.connected()) {
            client.stop();
          }
          Serial.println(postData);
        
         
                   
                        
              }
