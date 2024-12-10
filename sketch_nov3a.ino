#include <Servo.h>


const int buttonPin = 2;  // 버튼이 연결된 핀 번호
int lastButtonState = LOW; // 버튼의 이전 상태 (초기값 LOW)
int buttonState;           // 현재 버튼 상태

Servo myServo;             // 서보 모터 객체 생성
const int servoPin = 9;    // 서보 모터가 연결된 핀 번호
int initialPosition = 0;   // 서보 모터 초기 위치 (0도)
int activatedPosition = 90; // 서보 모터 활성화 위치 (90도)

void setup() {
  pinMode(buttonPin, INPUT); // 버튼 핀을 입력으로 설정
  myServo.attach(servoPin);  // 서보 모터 핀 연결
  myServo.write(initialPosition); // 서보 모터를 초기 위치로 설정
  Serial.begin(115200);       // 시리얼 통신 시작
}

void loop() {
  buttonState = digitalRead(buttonPin); // 버튼 상태 읽기

  // 버튼이 눌렸다가 떼어진 상태를 확인
  if (lastButtonState == HIGH && buttonState == LOW) {
    Serial.println("Button released!"); // 버튼이 떼어졌음을 알림
    delay(5000);
    // 서보 모터 회전
    myServo.write(activatedPosition); // 활성화 위치로 이동
    delay(3000);                      // 3초 대기
    myServo.write(initialPosition);   // 초기 위치로 복귀
  }

  // 버튼 상태를 저장하여 다음 루프에서 비교
  lastButtonState = buttonState;
}