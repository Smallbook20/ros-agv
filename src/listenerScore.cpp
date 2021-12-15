#include "ros/ros.h"
#include "beginner_tutorials/student.h"


void chatterCallback(const beginner_tutorials::student::ConstPtr& msg)
{
  float studentScore = (msg->scoreA + msg->scoreB + msg->scoreC) / 3;
  ROS_INFO("Diem trung binh: [%f]", studentScore);
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listenerScore");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter_with_student", 1000, chatterCallback);
  ros::spin();

  return 0;
}