//This is a testing file for iLead Vex Robotics 2019, this is not intended for competition use

#include "robot-config.h"
bool tankControl;//boolean that when true enables tank control and when false enables arcade control

void toggleControl() { //Function that toggles control between arcade and tank by the use of a boolean

	if (tankControl == false)
	{
		tankControl = true;
	}
	else if (tankControl == true)
	{
		tankControl = false;
	}
}

void liftControls() //controls for the lift on the robot
{
	if (Controller1.ButtonR1.pressing() == true) //Lift Up
	{
		LiftMotor.spin(directionType::fwd, 75, velocityUnits::pct);
	}
	else if (Controller1.ButtonL1.pressing() == true) //LiftMotor will go down when the L1 button is pressed on the controller
	{
		LiftMotor.spin(directionType::rev, 75, velocityUnits::pct); //makes the lift go down 
	}
	else //if no control statement is true then stops the lift motor and leaves it in position
	{
		LiftMotor.stop();
	}
	//Second Lift
	if (Controller1.ButtonR1.pressing() == true) //LiftMotor2 Up
	{
		LiftMotor2.spin(directionType::fwd, 75, velocityUnits::pct);
	}
	else if (Controller1.ButtonL2.pressing() == true) //LiftMotor2 will go down when l2 is pressed
	{
		LiftMotor2.spin(directionType::rev, 75, velocityUnits::pct); //will make the second stage of the lift go down
	}
	else
	{
		LiftMotor2.stop();
	}
}

void robotControls() { //Tank and arcade controls for the robot
	liftControls(); //enables lift controls for the robot

	if (tankControl == false) { //Arcade Control (1 joystick)
		LeftMotor.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value()) / 2, velocityUnits::pct); //Averages left joystick's x and y axis for smoother control
		RightMotor.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value()) / 2, velocityUnits::pct); //averages left joystick's x and y axis for smoother control
	}

	else if (tankControl == true) { //Tank Control (2 joysticks)
		LeftMotor.spin(directionType::rev, (Controller1.Axis3.value()), velocityUnits::pct); //LeftMotor goes forward whenever the left joystick is pressed forward
		RightMotor.spin(directionType::fwd, (Controller1.Axis2.value()), velocityUnits::pct); //RightMotor goes forward whenever the right joystick is pressed forward
	}
}

int main() { //main function
	tankControl = false; //Tank Control default state
	while (true) { //infinite loop
		Controller1.ButtonX.pressed(toggleControl); //runs the toggle control function whenever button x is pressed on the controller
		robotControls(); //function for the controls on the robot
	}
}