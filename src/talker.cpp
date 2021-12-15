#include "ros/ros.h"
#include "beginner_tutorials/student.h"

int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::student>("chatter_with_student", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    beginner_tutorials::student msg;
    msg.studentId = "123";
    msg.fullName = "Vu Duc Van";
    msg.grade = "K";
    msg.scoreA = 2.3;
    msg.scoreB = 3.4;
    msg.scoreC = 4.5;

    ROS_INFO("%s", msg.studentId.c_str());
    ROS_INFO("%s", msg.fullName.c_str());
    ROS_INFO("%s", msg.grade.c_str());
    ROS_INFO("%f", msg.scoreA);
    ROS_INFO("%f", msg.scoreB);
    ROS_INFO("%f", msg.scoreC);

    chatter_pub.publish(msg);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}