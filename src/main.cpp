#include <ESP32Servo.h>

Servo myservo;

int servoPin = 14;

void setup()
{
  myservo.setPeriodHertz(50);
  myservo.attach(servoPin, 500, 2400);
}

// add soft movement function that move between 0 and 90 degrees
void softMove(int start, int end, int step, int delayTime)
{
  if (start < end)
  {
    for (int i = start; i <= end; i += step)
    {
      myservo.write(i);
      delay(delayTime);
    }
  }
  else
  {
    for (int i = start; i >= end; i -= step)
    {
      myservo.write(i);
      delay(delayTime);
    }
  }
}

void loop()
{

  softMove(0, 90, 1, 25);
  delay(1000);
  softMove(90, 0, 1, 25);
  delay(1000);
}
