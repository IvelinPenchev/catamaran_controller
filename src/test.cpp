#include "catamaran_controller/test.h"
#include <iostream>
#include <stdio.h>



PropellerTest::PropellerTest(ros::NodeHandle n, int left_pin) : left_esc_(left_pin)
{
  gnss_sub_ = n.subscribe("gnss_data", 1000, &PropellerTest::gnss_data_callback_, this);
  ROS_INFO("Subscribed to gnss!");
  first_menu_();
  
}

PropellerTest::~PropellerTest() { }


///////////////////// PRIVATE ////////////////////////

void PropellerTest::gnss_data_callback_(const gnss_l86_interface::GnssData::ConstPtr& gnss_msg)
{
  gnss_data_.latitude = gnss_msg->latitude;
  gnss_data_.longitude = gnss_msg->longitude;
  gnss_data_.fix = gnss_msg->fix;
  gnss_data_.timestamp = gnss_msg->timestamp;
  // ROS_INFO("Message received!");
}

void PropellerTest::first_menu_()
{
  ros::Rate loop_rate(10);
  int choice;
  bool quit = false;

  do 
  {
    ROS_INFO(" ");
    ROS_INFO("How do you want to control the boat?");
    ROS_INFO("  Press 1 for differential control");
    ROS_INFO("  Press 2 for dual control");
    ROS_INFO("  Press 3 for max step input");

    std::cin >> choice;
    
    switch (choice)
    {
      case 1:
        // ROS_INFO_STREAM("Your choice was " << choice);
        break;
      case 2:
        // ROS_INFO_STREAM("Your choice was " << choice);
        dual_control_();
        break;
      case 3:
        // ROS_INFO_STREAM("Your choice was " << choice);
        break;
      default:
        ROS_INFO("Read the instructions you idiot, your answer doesn't make any sense!");
        quit = true;
        break;        
    }

    if (quit)
      break;

    ros::spinOnce();
    loop_rate.sleep();
  }
  while (ros::ok()); 
}

void PropellerTest::dual_control_()
{
  ROS_INFO(" ");
  ROS_INFO("------------- DUAL CONTROL MENU ----------------");
  ROS_INFO("--1 to increase, 2 to decrease, anything else to stop--");
  int key;
  do
  {
    std::cin >> key;
    ROS_INFO_STREAM("You pressed " << key);
    if (key != 1 && key != 2) break;
    
  }
  while(true);
}
