// 定义触摸引脚 T0 = GPIO4
#define TOUCH_PIN 4
// 定义板载LED GPIO2
#define LED_PIN 2
#define THRESHOLD 25


bool ledState = false;

bool lastTouched = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {

  int touchVal = touchRead(TOUCH_PIN);
  Serial.print("touch");
  Serial.println(touchVal);


  bool isTouched = (touchVal < THRESHOLD);

 
  if (isTouched && !lastTouched) {

    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    
    Serial.print("LED状态：");
    Serial.println(ledState ? 1: 0);
  }

  lastTouched = isTouched;

  delay(50);
}