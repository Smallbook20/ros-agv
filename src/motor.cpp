#include "ros/ros.h"
#include "beginner_tutorials/irSensor.h"
#include "beginner_tutorials/locationMap.h"

int leftSpeed;
int rightSpeed;
void turnLeft() {
    leftSpeed = -100;
    rightSpeed = 200;
}
void turnRight() {
    leftSpeed = 200;
    rightSpeed = -100;
}
void goForward() {
    leftSpeed = 300;
    rightSpeed = 300;
}
void goBackward() {
    leftSpeed = -200;
    rightSpeed = -200;
}

void stop() {
    leftSpeed = 0;
    rightSpeed = 0;
}

int direction(int ir1, int ir2, int ir3, int ir4, int ir5) {
    if (ir1 == 1 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 1) return 1; // go forward
    else if (ir1 == 1 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 0 ||
     ir1 == 1 && ir2 == 1 && ir3 == 0 && ir4 == 0 && ir5 == 1) return 2; //turn right
    else if (ir1 == 0 && ir2 == 0 && ir3 == 0 && ir4 == 0 && ir5 == 1 ||
    ir1 == 1 && ir2 == 0 && ir3 == 0 && ir4 == 1 && ir5 == 1) return 0; //turn left
    else return 3; //go backward
}

void speed(const beginner_tutorials::irSensor::ConstPtr& msg) {
    switch (direction(msg->ir1, msg->ir2, msg->ir3, msg->ir4, msg->ir5))
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
    }
    
    if (msg->barrier == 1) {
        stop();
    }
    ROS_INFO("Left Speed: %d", leftSpeed);
    ROS_INFO("Right Speed: %d", rightSpeed);
}
void locationMap(const beginner_tutorials::locationMap::ConstPtr& msg) {
    ROS_INFO(" Location: %s",  msg->locationMap.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "motor");
  ros::NodeHandle n;
  ros::Subscriber sub_ir_signal = n.subscribe("send_ir_signal", 2000, speed);
  ros::Subscriber sub_location = n.subscribe("send_location", 1000,locationMap );
  ros::spin();

  return 0;
}