#include "robot-config.h"
/*////////////////////
//  AUTONOMOUS CODE //
////////////////////*/

void moveForward(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::rev, speed, velocityUnits::pct);
	RightMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void moveBackwards(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::rev, speed, velocityUnits::pct);
	RightMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void pivotRight(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	RightMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void pivotLeft(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::rev, speed, velocityUnits::pct);
	RightMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void firstLift(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LiftMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
}
void secondLift(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LiftMotor2.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
}
void openClaw(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	ClawMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
}
void closeClaw(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	ClawMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
}
void rotateClaw(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	ClawRotateMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
}
/*////////////////////
//  USER CONTROLS   //
////////////////////*/

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
	if (Controller1.ButtonR2.pressing() == true) //LiftMotor2 Up
	{
		LiftMotor2.spin(directionType::rev, 75, velocityUnits::pct);
	}
	else if (Controller1.ButtonL2.pressing() == true) //LiftMotor2 will go down when l2 is pressed
	{
		LiftMotor2.spin(directionType::fwd, 75, velocityUnits::pct); //will make the second stage of the lift go down
	}
	else
	{
		LiftMotor2.stop();
	}
}

void clawControls() { //Controls for the claw and claw rotation motor
					  //Claw rotation control
	if (Controller1.ButtonDown.pressing() == true)
	{
		ClawRotateMotor.spin(directionType::rev, 50, velocityUnits::pct);
	}
	else if (Controller1.ButtonUp.pressing() == true)
	{
		ClawRotateMotor.spin(directionType::fwd, 50, velocityUnits::pct);
	}
	else
	{
		ClawRotateMotor.stop();
	}
	//Claw Controls
	if (Controller1.ButtonRight.pressing() == true)
	{
		ClawMotor.spin(directionType::fwd, 40, velocityUnits::pct);
	}
	else if (Controller1.ButtonLeft.pressing() == true)
	{
		ClawMotor.spin(directionType::rev, 40, velocityUnits::pct);
	}
	else
	{
		ClawMotor.stop();
	}
}

void robotControls() { //Tank, arcade and lift controls for the robot
	liftControls(); //enables lift controls for the robot
	clawControls(); //enables claw controls for the robot
	LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value()), velocityUnits::pct); //LeftMotor goes forward whenever the left joystick is pressed forward
	RightMotor.spin(directionType::fwd, (Controller1.Axis2.value()), velocityUnits::pct); //RightMotor goes forward whenever the right joystick is pressed forward
}

void autonomous() { //Autonomous instructions for the robot
	moveForward(100, 2.75);
	closeClaw(50, 1.5);
	firstLift(75, 2);
	moveBackwards(100, 2);
	LiftMotor.spin(directionType::rev, 75, velocityUnits::pct);
	task::sleep(1750);
	openClaw(30, 1.5);
	moveBackwards(100, 1);
}
int main() {
	autonomous();
	while (true) {
		robotControls();
	}
}