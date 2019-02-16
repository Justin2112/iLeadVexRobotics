# iLeadVexRobotics
Code and description for one of iLead's Vex Robotics teams for 2019
## Current setup
![Image of vex parts](https://github.com/Justin2112/iLeadVexRobotics/blob/master/vexPartsAndPorts.PNG)
## Vex File 0.9.0 (Unreleased)
#### 2/15/2019
* Made code for autonomous function
* Changed to have autonomous function to start before user control on non-competition file
* Fixed functions spoolRetract(), spoolRelease(), and secondLift() to stop after # of seconds
* Added negative values to be compatible with firstLift() and secondLift() to make the lift motors go in reverse
## Vex File 0.8.0 (Released 2/14/2019)
#### 2/14/2019
* Made competition files for tank and arcade from non-competition file
* Updated vexPartsAndPorts.PNG to have motors added
* Added functions firstLift() and secondLift() to move lift motors during autonomous period
#### 2/12/2019
* Made functions for autonomous like moveForward() and pivotRight()
#### 2/8/2019
* Added SpoolMotor to setup
* Added controls for SpoolMotor to Controller1
## Vex File 0.5.5 (Released 2/5/2019)
* Added LiftMotor2 controls to function liftControls
* Updated C++ file to match current Vex file
## Vex File 0.5 (Released 2/1/2019)
#### 2/1/2019
* Added Vex File compatible with Vex Coding Studio
* Restructured Vex and C++ file
* Added more comments for easier reading
* Added image of vex parts & assigned ports
  ![Image of vex parts](https://github.com/Justin2112/iLeadVexRobotics/blob/master/vexPartsAndPorts.PNG)
#### 1/30/2019
* Added function liftControls and content
* Assigned LiftMotor to port 10
* Fixed issue with arcade controls being reversed (when the joystick was pressed left the robot would go forward instead of left)
#### 1/25/2019
* Fixed the toggle between tank and arcade control
* Made controls arcade by default
#### 1/23/2019
* Added tank controls using controller (2 joysticks)
* Added toggle between tank and arcade controls through the X button on the controller
#### 1/15/2019
* Made Vex non competition file
  * Assigned LeftMotor to port 1
  * Assigned RightMotor to port 2
  * Assigned Controller1
  * Assigned Brain
* Added arcade controls using controller (1 joystick)
