// 定义触摸引脚 T0 = GPIO4
#define TOUCH_PIN 4
// 定义LED引脚 GPIO2
#define LED_PIN 2

// 触摸阈值
const int threshold = 25;

// PWM 设置
const int freq = 5000;
const int resolution = 8;

// 档位控制：1慢 2中 3快
int speedLevel = 1;
bool lastTouched = false;

void setup() {
  // PWM 绑定引脚
  ledcAttach(LED_PIN, freq, resolution);
}

void loop() {

  int touchVal = touchRead(TOUCH_PIN);
  bool isTouched = (touchVal < threshold);


  if (isTouched && !lastTouched) {
    speedLevel++;
    if (speedLevel > 3) speedLevel = 1;
  }
  lastTouched = isTouched;


  int step = 1;
  if (speedLevel == 1) step = 1;
  if (speedLevel == 2) step = 3;
  if (speedLevel == 3) step = 6;


  for (int duty = 0; duty <= 255; duty += step) {
    ledcWrite(LED_PIN, duty);
    delay(6);
  }


  for (int duty = 255; duty >= 0; duty -= step) {
    ledcWrite(LED_PIN, duty);
    delay(6);
  }
}