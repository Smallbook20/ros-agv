#include "ros/ros.h"
#include "beginner_tutorials/AverageScore.h"

bool cal_average_score(beginner_tutorials::AverageScore::Request  &req,
         beginner_tutorials::AverageScore::Response &res)
{
  res.averageScore = (req.scoreA + req.scoreB + req.scoreC) / 3;
  ROS_INFO("request: x=%ld, y=%ld z =%ld", (long int)req.scoreA, (long int)req.scoreB, (long int)req.scoreB);
  ROS_INFO("sending back response: [%f]", res.averageScore);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "cal_average_score_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("cal_average_score", cal_average_score);
  ROS_INFO("Ready to calculate avarage score.");
  ros::spin();

  return 0;
}