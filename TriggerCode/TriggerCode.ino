#include <CoDrone.h>
int step;
unsigned long startTime;
void setup ()

{
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x3F, 0xAe, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);

}

void loop()
{
  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if (left == 1)
  {
    CoDrone.FlightEvent(Stop);
    step = 0;
  }
  else if (right == 1)
  {
    step = step + 1;

    if (step > 4)
    {
      step = 0;
    }
    CoDrone.Buzz (3000, 7);
    delay(500);
    CoDrone.FlightEvent(Landing);
  }
  else if (middle == 1)
  {
    CoDrone.FlightEvent(Landing);

  }
  if (step == 1)
  {
    THROTTLE = 100;
    PITCH = 30;
    CoDrone.Control();
  }
  else if (step == 2)
  {
    PITCH = 30;
    THROTTLE = 60;
    CoDrone.Control();
  }
  else if (step == 3)
  {
    ROLL = -20;
    CoDrone.Control();
  }
  else if (step == 4)
  {
    PITCH = 20;
    CoDrone.Control();
  }
  else {
    CoDrone.FlightEvent(Landing);
  }

}
