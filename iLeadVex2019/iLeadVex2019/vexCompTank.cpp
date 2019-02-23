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

void moveForward(int speed, float seconds) { //moves the robot forward in set speed for set seconds
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	RightMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void moveBackwards(int speed, float seconds) { //moves the robot backwards in set speed for set seconds
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::rev, speed, velocityUnits::pct);
	RightMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void pivotRight(int speed, float seconds) { //pivots the robot right for set speed and set seconds
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	RightMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void pivotLeft(int speed, float seconds) { //pivots the robot left for set speed and set seconds
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LeftMotor.spin(directionType::rev, speed, velocityUnits::pct);
	RightMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
	LeftMotor.stop();
	RightMotor.stop();
}
void firstLift(int speed, float seconds) { //spins the lift motor for set speed and set seconds
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LiftMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
}
void secondLift(int speed, float seconds) { //spins the second lift motor by set speed and set seconds
	seconds = seconds * 1000; //multiplies value by 1000 to convert to milliseconds
	LiftMotor2.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
}
void spoolRelease(int speed, float seconds) //retracts string from spool
{
	seconds = seconds * 1000;
	SpoolMotor.spin(directionType::fwd, speed, velocityUnits::pct);
	task::sleep(seconds);
	SpoolMotor.stop();
}
void spoolRetract(int speed, float seconds) //releases string from spool
{
	seconds = seconds * 1000;
	SpoolMotor.spin(directionType::rev, speed, velocityUnits::pct);
	task::sleep(seconds);
	SpoolMotor.stop();
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
void clawControls() { //Controls for the claw and claw arm
					  //Claw Arm control
	if (Controller1.ButtonX.pressing() == true)
	{
		ClawArmMotor.spin(directionType::rev, 90, velocityUnits::pct);
	}
	else if (Controller1.ButtonB.pressing() == true)
	{
		ClawArmMotor.spin(directionType::fwd, 90, velocityUnits::pct);
	}
	else
	{
		ClawArmMotor.stop();
	}
	//Claw Controls
	if (Controller1.ButtonLeft.pressing() == true)
	{
		ClawMotor.spin(directionType::fwd, 40, velocityUnits::pct);
	}
	else if (Controller1.ButtonRight.pressing() == true)
	{
		ClawMotor.spin(directionType::rev, 40, velocityUnits::pct);
	}
	else
	{
		ClawMotor.stop();
	}
}
void launcherControls() { //Controls the launcher arm
	if (Controller1.ButtonY.pressing() == true)
	{
		LauncherMotor.spin(directionType::rev, 100, velocityUnits::pct);
	}
	else
	{
		LauncherMotor.stop();
	}
}
void robotControls() { //Tank, arcade and lift controls for the robot
	liftControls(); //enables lift controls for the robot
	spoolControls(); //enables controls for the spool motor
	clawControls(); //enables controls for the claw and claw arm motor
	launcherControls(); //enables controls for the launcher motor
	LeftMotor.spin(directionType::fwd, (Controller1.Axis3.value()), velocityUnits::pct); //LeftMotor goes forward whenever the left joystick is pressed forward
	RightMotor.spin(directionType::rev, (Controller1.Axis2.value()), velocityUnits::pct); //RightMotor goes forward whenever the right joystick is pressed forward
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

	spoolRelease(60, 2.5); //Lowers the lift sstring
	moveForward(100, 3); //moves forward for 3 seconds at full speed
	firstLift(75, 1.5); //lifts the first lift up for 1.5 seconds
	spoolRetract(40, 0.25); //releases lift string
	moveBackwards(50, 1); //moves backwards at half speed for 1 second
	LiftMotor.stop(); //stops the lift motor
	moveBackwards(100, 0.5); //move backwards at full speed for 2.75 seconds
	pivotRight(100, 0.25); //pivots the robot slightly to the right
	spoolRelease(60, 1.25); //releases the spool string more to allow for lift
	secondLift(75, 1.5); //the second stage of the lift goes up to lift the game object
	moveForward(30, 0.3); //moves the robot forward towards the pole for the game object
	LiftMotor2.spin(directionType::fwd, 75, velocityUnits::pct); //lowers the 2nd lift motor
	task::sleep(1500); //waits 1.5 seconds
	LiftMotor2.stop(); //stops the 2nd lift motor
	LiftMotor.spin(directionType::rev, 75, velocityUnits::pct); //lowers the 1st lift motor
	task::sleep(1500); //waits 1.5 seconds
	LiftMotor.stop(); //stops the 1st lift motor
	moveBackwards(30, 0.3); //moves the robot backwards
	pivotLeft(100, 0.25); //pivots the robot left
	moveBackwards(100, 2.5); //moves the robot backwards to park in starting space

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