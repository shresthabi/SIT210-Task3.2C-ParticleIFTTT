int photoresistor = A0;
int led = A5;
bool light_status = false;

void setup() {
    pinMode(photoresistor, INPUT);
    pinMode(led, OUTPUT);
   
}

void loop() {
    digitalWrite(led, HIGH);
    int light = analogRead(photoresistor);
    Particle.publish("light_status", String(light));
    
    if(light >= 30 && !light_status){
        light_status = true;
        Particle.publish("light_status", "ON");
    }else if(light < 30 && light_status){
        light_status = false;
        Particle.publish("light_status", "OFF");
    }
    delay(5000);
    digitalWrite(led,LOW);
    delay(5000);
}


