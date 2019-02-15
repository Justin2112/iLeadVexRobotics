#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

//Creates a competition object that allows access to Competition methods.
vex::competition    Competition;

/*////////////////////
//  AUTONOMOUS CODE //
////////////////////*/

void moveForward(int speed, float seconds) {
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	RightMotor.spin(directionType::fwd, speed, velocityUnits::pct);
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
void spoolControls() { //Controls for the spool motor
	if (Controller1.ButtonUp.pressing() == true) //SpoolMotor up
	{
		SpoolMotor.spin(directionType::fwd, 75, velocityUnits::pct); //moves spool motor up while pressed    
	}
	else if (Controller1.ButtonDown.pressing() == true) //SpoolMotor down while pressed
	{
		SpoolMotor.spin(directionType::rev, 75, velocityUnits::pct); //moves spool motor down
	}
	else
	{
		SpoolMotor.stop();
	}
}
void robotControls() { //Tank, arcade and lift controls for the robot
	liftControls(); //enables lift controls for the robot
	spoolControls(); //enables controls for the spool motor
	LeftMotor.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value()), velocityUnits::pct); //Averages left joystick's x and y axis for smoother control
	RightMotor.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value()), velocityUnits::pct); //averages left joystick's x and y axis for smoother control
}
/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
	// ..........................................................................
	// Insert autonomous user code here.
	// ..........................................................................

}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*  This task is used to control your robot during the user control phase of  */
/*  a VEX Competition.                                                        */
/*                                                                            */
/*  You must modify the code to add your own robot specific commands here.    */
/*----------------------------------------------------------------------------*/

void usercontrol(void) {
	// User control code here, inside the loop
	while (1) {
		robotControls();
		vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
	}
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

	//Run the pre-autonomous function. 
	pre_auton();

	//Set up callbacks for autonomous and driver control periods.
	Competition.autonomous(autonomous);
	Competition.drivercontrol(usercontrol);

	//Prevent main from exiting with an infinite loop.                        
	while (1) {
		vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
	}

}