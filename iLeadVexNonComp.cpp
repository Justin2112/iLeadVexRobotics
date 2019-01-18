#include "robot-config.h"

bool tankControl;

void toggleControl() //Toggles control between arcade and tank; controls are arcade by default
{
	if (Controller1.ButtonR2.pressing() == 1)
	{
		if (tankControl == false)
		{
			tankControl = true;
		}
		else if (tankControl == true)
		{
			tankControl = false;
		}
	}
}

void robotControls() //Tank and arcade controls for the robot
{
	if (tankControl == false) //Arcade Control (1 joystick)
	{
		LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value() + Controller1.Axis4.value()) / 2, velocityUnits::pct);
		RightMotor.spin(directionType::fwd, (Controller1.Axis3.value() - Controller1.Axis4.value()) / 2, velocityUnits::pct);
	}
	else if (tankControl == true) //Tank Control (2 joysticks)
	{
		LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value()), velocityUnits::pct);
		RightMotor.spin(directionType::fwd, (Controller1.Axis2.value()), velocityUnits::pct);
	}
}

int main() {

	tankControl = false;

	while (true) {
		toggleControl();
		robotControls();
	}
}