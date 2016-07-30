#include <CoDrone.h>
void setup() {
  CoDrone.begin(115200);
  byte droneAddress[6] = {0x3F, 0xAe, 0x61, 0x78, 0xD5, 0xA4};
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
  CoDrone.BattleBegin(TEAM_BLUE);
}

void loop() {
  // put your main code here, to run repeatedly:

  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if (left == 1)
  {
    CoDrone.FlightEvent(Stop);
  }
  else if (right == 1)
  {
  CoDrone.BattleShooting();
  CoDrone.ButtonPreesHoldWait(18);
  CoDrone.Buzz (2500,7);
  }
  else if (middle == 1)
  {
    CoDrone.FlightEvent(Landing);
  }
  THROTTLE = CoDrone.AnalogScaleChange(analogRead(A5));
  PITCH = CoDrone.AnalogScaleChange(analogRead(A4));
  ROLL = -1 * CoDrone.AnalogScaleChange(analogRead(A3));
  YAW = -1 * CoDrone.AnalogScaleChange(analogRead(A6));
  CoDrone.Control();
}
