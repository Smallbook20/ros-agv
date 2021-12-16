#include "ros/ros.h"
#include "beginner_tutorials/student.h"


void chatterCallback(const beginner_tutorials::student::ConstPtr& msg)
{
  ROS_INFO("Mssv: %s", msg->studentId.c_str());
  ROS_INFO("Ho va Ten: %s", msg->fullName.c_str());
  ROS_INFO("Lop: %s \n", msg->grade.c_str());
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listenerInfo");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter_with_student", 1000, chatterCallback);
  ros::spin();

  return 0;
}