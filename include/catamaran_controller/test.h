#include <string>
#include <ros/ros.h>
#include <ros/console.h>
#include "catamaran_controller/force_to_pwm.h"
#include "gnss_l86_interface/gnss_l86_lib.h"
#include "gnss_l86_interface/GnssData.h" 
#include "catamaran_controller/esc_lib.h"
#include <cstdlib>
#include <unistd.h>
#include <pigpiod_if2.h>

class PropellerTest
{
  private:
    ForceToPWM force_converter_;
    position gnss_data_;
    ros::Subscriber gnss_sub_;
    esc_lib left_esc_;
    void gnss_data_callback_(const gnss_l86_interface::GnssData::ConstPtr& gnss_msg);
    void first_menu_();
    void dual_control_();
    

  public:
    PropellerTest(ros::NodeHandle n, int left_pin);
    ~PropellerTest();
};
