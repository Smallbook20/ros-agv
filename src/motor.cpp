#include "ros/ros.h"
#include "beginner_tutorials/irSensor.h"
#include "beginner_tutorials/locationMap.h"
#include "beginner_tutorials/press.h"

int leftSpeed;
int rightSpeed;

void turnLeft() {
    ROS_INFO("Turning Left");
    leftSpeed = -100;
    rightSpeed = 200;
}
void turnRight() {
    ROS_INFO("Turning Right");
    leftSpeed = 200;
    rightSpeed = -100;
}
void goForward() {
    ROS_INFO("Going Forward");
    leftSpeed = 300;
    rightSpeed = 300;
}
void goBackward() {
    ROS_INFO("Going Backward");
    leftSpeed = -200;
    rightSpeed = -200;
}

void stop() {
    ROS_INFO("Stop !");
    leftSpeed = 0;
    rightSpeed = 0;
}

int direction(std::string irSensor) {
    if (irSensor.compare(5, 1, "1") == 0) return 4; //stop
    else if (irSensor.compare(0, 5, "10001") == 0) return 1; //turn left
    else if (irSensor.compare(0, 5, "10000") == 0 || irSensor.compare(0, 5, "11001") == 0) return 2; //turn right
    else if (irSensor.compare(0, 5, "00001") == 0 || irSensor.compare(0, 5, "10011") == 0) return 0; //go forward
    else return 3; //go backward
}

int detectPressKeyBoard(std::string pressedKey) {
    if (pressedKey.compare("w") == 0 || pressedKey.compare("W") == 0) return 1; //go forward
    else if (pressedKey.compare("a") == 0 || pressedKey.compare("A") == 0) return 0; //turn left
    else if (pressedKey.compare("s") == 0 || pressedKey.compare("S") == 0) return 3; //go backward
    else if (pressedKey.compare("d") == 0 || pressedKey.compare("D") == 0) return 2; //turn right
    else return 4;
}

void speed(const beginner_tutorials::irSensor::ConstPtr& msg) {
    switch (direction(msg->irSensor.c_str()))
    {
        case 0:
            turnLeft();
            break;
        case 1:
            goForward();
            break;
        case 2:
            turnRight();
            break;
        case 3:
            goBackward();
            break;
        case 4:
            stop();
            break;
    }
    ROS_INFO("Left Speed: %d", leftSpeed);
    ROS_INFO("Right Speed: %d", rightSpeed);
}
void calDirection (std::string location) {
    if (location.compare("A1") == 0){
        ROS_INFO("Direction: F R L");
    }
    else if (location.compare("B1") == 0) {
        ROS_INFO("Direction: F L R F");
    }
}

void locationMap(const beginner_tutorials::locationMap::ConstPtr& msg) {
    ROS_INFO(" Location: %s",  msg->locationMap.c_str());
    calDirection(msg->locationMap.c_str());
    
}

void pressKeyBoard(const beginner_tutorials::press::ConstPtr& msg) {
    switch (detectPressKeyBoard(msg->pressedKey.c_str()))
    {
        case 0:
            turnLeft();
            break;
        case 1:
            goForward();
            break;
        case 2:
            turnRight();
            break;
        case 3:
            goBackward();
            break;
        case 4: 
            ROS_INFO("Invalid controll");
            break;
    }
    ROS_INFO("Left Speed: %d", leftSpeed);
    ROS_INFO("Right Speed: %d", rightSpeed);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "motor");
  ros::NodeHandle n;
  ros::Subscriber sub_ir_signal = n.subscribe("send_ir_signal", 2000, speed);
  ros::Subscriber sub_location = n.subscribe("send_location", 1000, locationMap);
  ros::Subscriber sub_press = n.subscribe("send_press_key_board", 1000, pressKeyBoard);
  ros::spin();

  return 0;
}