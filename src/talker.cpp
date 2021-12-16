#include "ros/ros.h"
#include "beginner_tutorials/student.h"

int main(int argc, char **argv)
{
  if (argc != 7)
  {
    ROS_INFO("usage: talker x1 x2 x3 x4 x5 x6");
    ROS_INFO("%s", argv[6]);
    return 1;
  }
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<beginner_tutorials::student>("chatter_with_student", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    beginner_tutorials::student msg;
    msg.studentId = argv[1];
    msg.fullName = argv[2];
    msg.grade = argv[3];
    msg.scoreA = atof(argv[4]);
    msg.scoreB = atof(argv[5]);
    msg.scoreC = atof(argv[6]);

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