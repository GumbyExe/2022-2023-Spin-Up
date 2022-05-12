#include "main.h"
using namespace pros;

extern Controller controller;

// drive motors
extern Motor leftF;
extern Motor leftB;
extern Motor rightF;
extern Motor rightB;

// inertial sensor
extern Imu imu;

double inToEnc(double inches);

#define driveWheelDiam 4
#define driveWheelRad 2

#define ticksPerRev 900
  // 1800 ticks/rev with 36:1 gears
  // 900 ticks/rev with 18:1 gears
  // 300 ticks/rev with 6:1 gears

#define PI      3.141592653589793238462643383279
#define halfPI  1.570796326794896619231321691639
#define twoPI	  6.283185307179586476925286766559
