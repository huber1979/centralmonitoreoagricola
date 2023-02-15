#include <DHT.h>
#include <DHT_U.h>


DHT dht(8, DHT11);

float temp, hume;
int relay = 2;

void setup() {
    //Paso 1
      pinMode(relay, OUTPUT); // Configurar relay como salida o OUTPUT
    Serial.begin(9600);
    Serial.println("Valor del sensor de humedad");
    dht.begin();
}
  
void loop() {
    //Paso 2
    int humidity = analogRead(A0);
    Serial.print("Lectura:");
    Serial.println(humidity);
    //Paso 3
    if(humidity >= 0 & humidity <= 300){
        Serial.println("Sensor en suelo seco");
        digitalWrite(relay, HIGH); // envia señal alta al relay
  Serial.println("Relay accionado");
 // delay(6000);     
    } else if(humidity > 301 & humidity <= 700){
        Serial.println("Sensor en suelo húmedo");
         digitalWrite(relay, LOW);  // envia señal baja al relay
  Serial.println("Relay no accionado");
  //delay(6000);   
    }else if(humidity >= 701){
        Serial.println("Sensor en agua");
    }
    delay(1000);

 hume = dht.readHumidity();
 temp = dht.readTemperature();

 Serial.println("Temperatura: " + String(temp) + " Humedad: " + String(hume));
 delay(5000); 
}