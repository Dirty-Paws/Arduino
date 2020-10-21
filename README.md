# Arduino

Bu repository'de akıllı mama kabına Arduino Uno CH340 üzerindeki sensörlerin çalışmasını sağlayan sistem bulunmaktadır. 


## Kullanılan Sensörler

        HC-SR04 Ultrasonik Sensör
        LM35 Sıcaklık Sensörü
        Su Seviye Modülü
        5mm LDR Fotosel
        
   
### Sensörlerin Kullanım Amaçları
        
   **HC-SR04 Ultrasonik Sensör:**  Dostumuz mama kabına yaklaştığında servo motor ile kabın açılmasını sağlaması için kullanılmaktadır. 
        
   **LM35 Sıcaklık Sensörü:** Yapay zeka eğitiminde prediction'ını yüksek tutmak için veri sağladığımız ekstra bir özellik. Sıcak havalarda daha çok su tüketimi olabilir, 
   soğuk havalarda ise daha çok mama tüketimi olabilir tarzında yaklaşımlar için kullanılmaktadır.
   
   **Su Seviye Modülü:** Akıllı mama kabına ek olarak su kabının olmasını öngördük. App kullanan gönüllülerimiz ilerleyen süreçte suyun bitip bitmediğini de görmeleri planlanmaktadır.
   
   **5mm LDR Fotosel:** Mama kabında mama bittiği zaman kabın şeffaflığı sayesinde kabın altı ışık alacaktır. Böylece mamanın bittiği öngörülecektir. 




## Dataların Toplanması 

Dataların toplanması için [teraterm](https://osdn.net/projects/ttssh2/releases/) yazılımı kullanılmıştır. 
