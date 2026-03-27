// 两个LED引脚
const int ledPin1 = 2;
const int ledPin2 = 4;

// PWM设置
const int freq = 5000;
const int resolution = 8;

void setup() {
  ledcAttach(ledPin1, freq, resolution);
  ledcAttach(ledPin2, freq, resolution);
}

void loop() {
  // A亮 → B暗 
  for(int duty = 0; duty <= 255; duty++){
    ledcWrite(ledPin1, duty);
    ledcWrite(ledPin2, 255 - duty);
    delay(8);
  }

  for(int duty = 255; duty >= 0; duty--){
    ledcWrite(ledPin1, duty);
    ledcWrite(ledPin2, 255 - duty);
    delay(8);
  }
}