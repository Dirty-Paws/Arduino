  #include <Servo.h>

  
  #define RX 2
  #define TX 3
  #define trigPin 7
  #define echoPin 6

  
  int lm35Pin = A2;
  int seviye=A1;
  int okunan_deger = 0;
  float sicaklik_gerilim = 0;
  float sicaklik = 0;
  
  #define led 9

  
 
  
  Servo servo;
 
  





    void setup() {

  
          Serial.begin (9600);
          
          pinMode(led,OUTPUT);
          pinMode(trigPin, OUTPUT);
          pinMode(echoPin, INPUT);
          servo.attach(8);
    
    }
            


    void loop() {
        long duration, distance;
            
              
              digitalWrite(trigPin, LOW);
              delayMicroseconds(2);
              digitalWrite(trigPin, HIGH);
              delayMicroseconds(10);
              digitalWrite(trigPin, LOW);
              duration = pulseIn(echoPin, HIGH);
              distance = (duration/2) / 29.1;
              
              okunan_deger = analogRead(lm35Pin);         //Sıcaklık sensörünün çalıştırılması
              sicaklik_gerilim = (okunan_deger / 1023.0)*5000;
              sicaklik = sicaklik_gerilim /10.0; 
            
              Serial.print(sicaklik);
              Serial.println(" celsius");
              
              if (distance < 32) {        // Ultrasonik sensöre 32cmden yakın olduğunda servo motor sayesinde mama kabı açılıyor.
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
              
                if(isik > 80){        // Mama bittiğinde ışık yoğunluğu daha fazla olacağından ışığın fazlalığı = Mama bitmiştir.
                  digitalWrite(led,HIGH);
                  Serial.print("Mama bitti.");
                }
              
                if(isik < 60){
                  digitalWrite(led,LOW);
                } 
              
                    seviye=analogRead(A1);
                    Serial.print("\n Suyun Seviyesi:");
                    Serial.println(seviye);
                                                           
                        
              }
