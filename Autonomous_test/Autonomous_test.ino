// 3. Include the CoDrone library in your code
#include <CoDrone.h>
// 1. Add the method that runs once, before anything else
void setup ()
{
  //   4. Set up the thread - HINT: 115200
  CoDrone.begin(115200);
  //   5. Create a byte array that holds your specific drone address
  byte droneAddress[6] = {0x3F, 0xAe, 0x61, 0x78, 0xD5, 0xA4};
  //   6. Connect to your drone using the address - HINT: It functions as an AddressInputDrone
  CoDrone.AutoConnect(AddressInputDrone, droneAddress);
}
// 2. Add the method that runs repeatedly once the program starts
void loop ()
{
  byte left = digitalRead(11);
  byte middle = digitalRead(14);
  byte right = digitalRead(18);
  if (left == 1)
  {
    CoDrone.FlightEvent(Stop);
  }
  else if (right == 1)
  {
    CoDrone.FlightEvent(TakeOff);
    THROTTLE = 100;
    CoDrone.Control();
    PITCH = 80;
     delay (1000);
    CoDrone.Control();
    ROLL = 80;
    delay (500);
    CoDrone.Control();
    PITCH = -80;
    delay (500);
    CoDrone.Control();
    ROLL = -80;
    delay (500);
    CoDrone.Control();
    THROTTLE = 50;
    delay (500);
    CoDrone.Control();
    THROTTLE = 40;
    delay (300);
    CoDrone.Control();
    delay (100);
    THROTTLE = 20;
    CoDrone.Control();
    THROTTLE = 0;
    delay (100);
    CoDrone.Control();
  }
  else if (middle == 1)
  {
    CoDrone.FlightEvent(Landing);
  }
}

//        12. Go up with a speed of 100
//        Send the command - HINT: Use .Control()
//        Wait for one second - HINT: Use delay(____);

//        13. Go forward (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        14. Go right (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        15. Go back (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        16. Go left (80) and keep going up with a speed of 80
//        Send the command
//        Wait for half a second

//        17. Land

