const int ledPin = 2;   
const int ledPin2 = 27;  
const int ledPin3 = 25; 

const int freq = 5000;          
const int resolution = 8;       

void setup() {
  Serial.begin(115200);

  ledcAttach(ledPin, freq, resolution);
  ledcAttach(ledPin2, freq, resolution);
  ledcAttach(ledPin3, freq, resolution);
}

void loop() {
for(int i=0; i<3; i++){
    ledcWrite(ledPin, 255);      
    ledcWrite(ledPin2, 0);     
    ledcWrite(ledPin3, 0);
    delay(200);                 
    ledcWrite(ledPin, 0);        
    delay(200);                 
  }

  for(int i=0; i<3; i++){
    ledcWrite(ledPin, 255);     
    ledcWrite(ledPin2, 0);       
    ledcWrite(ledPin3, 0);
    delay(600);                 
    ledcWrite(ledPin, 0);       
    delay(200);                  
  }

  for(int i=0; i<3; i++){
    ledcWrite(ledPin, 255);    
    ledcWrite(ledPin2, 0);       
    ledcWrite(ledPin3, 0);
    delay(200);                 
    ledcWrite(ledPin, 0);        
    delay(200);                  
  }


  delay(2000);
  Serial.println("SOS");
}