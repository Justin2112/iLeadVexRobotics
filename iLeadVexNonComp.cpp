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
	if (tankControl == false) { //Arcade Control (1 joystick)
		LeftMotor.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value()), velocityUnits::pct); //Averages left joystick's x and y axis for smoother control
		RightMotor.spin(directionType::fwd, (Controller1.Axis4.value() - Controller1.Axis3.value()), velocityUnits::pct); //averages left joystick's x and y axis for smoother control
	}

	else if (tankControl == true) { //Tank Control (2 joysticks)
		LeftMotor.spin(directionType::rev, (Controller1.Axis3.value()), velocityUnits::pct); //LeftMotor goes forward whenever the left joystick is pressed forward
		RightMotor.spin(directionType::fwd, (Controller1.Axis2.value()), velocityUnits::pct); //RightMotor goes forward whenever the right joystick is pressed forward
	}
}

void autonomous() {
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

int main() { //main function
	tankControl = false; //Tank Control default state
	autonomous();
	while (true) { //infinite loop
		Controller1.ButtonX.pressed(toggleControl); //runs the toggle control function whenever button x is pressed on the controller
		robotControls(); //function for the controls on the robot
	}
}