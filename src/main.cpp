
//True=gears False=boiler
#include <opencv2/opencv.hpp>
#include <boost/lexical_cast.hpp>

#include "CmdLineInterface.hpp"
#include "AppConfig.hpp"
#include "Target.hpp"
#include "TargetDetector.hpp"
#include "TargetProcessor.hpp"
#include "VideoDevice.hpp"
#include <string>
#include <sstream>

namespace patch
{
template < typename T > std::string to_string( const T& n )
{
    std::ostringstream stm ;
    stm << n ;
    return stm.str() ;
}
}

#include <iostream>

int main(int argc, char* argv[])
{

    TargetDetector detector;
    TargetProcessor processor;
    VideoDevice Camera;
    CmdLineInterface interface(argc, argv);
    AppConfig config = interface.getConfig();

    if(config.getIsDevice()) {
        Camera.startCapture(config.getDeviceID());
    }

    cv::Mat Image;

    int loop = 1;
    //cv::namedWindow("Live Video Feed", cv::WINDOW_NORMAL);
    //cv::namedWindow("General", cv::WINDOW_NORMAL);

    while(cv::waitKey(30) != 27)
    {
        cv::Mat background(Size(1000,1000), CV_8UC1, Scalar(255, 255, 255 ));

        std::cout << "While Loop #" << loop << std::endl;

        Image = Camera.getImage();

        if(!Image.data) { // check if gearCamera image is valid
            std::cout << "Failed to read Image" << std::endl;
            return -1;
        }


        Target* target = detector.processImage(Image); //Gears

        bool foundTarget = false;


        std::cout<<"right"<<std::endl;

        if (target != NULL)
        {
               if(target != NULL){
                    foundTarget = true;
                }
                else{
                    foundTarget = false;
                }
                std::cout << "Got Type Target: " << foundTarget << std::endl;


            std::cout<<"in if"<<std::endl;
            std::cout <<"About to check the value of foundTarget" << std::endl;
            if(foundTarget)
            {
                std::cout <<"Target was found " << std::endl;

                processor.loadTarget(target);
                // middle value should be changed to the object's real width (The width of the Gear "rectangle is 10.25 in.)


                double Distance = processor.calculateDistance();

                double Azimuth = processor.calculateAzimuth();

                double Altitude = processor.calculateAltitude();

                std::string dis = "distance (Gear): " + patch::to_string(Distance);
                std::string alt = "altitude (Gear): " + patch::to_string(Altitude);
                std::string azi = "azimuth (Gear): " + patch::to_string(Azimuth);

                //cv::putText(background, dis, cv::Point(50,100),
                //cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cv::Scalar(0, 255, 0),
                //1);

                //cv::putText(background, alt, cv::Point(50,200),
                //cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cv::Scalar(0, 255, 0),
                //1);

                //cv::putText(background, azi, cv::Point(50,400),
                //cv::FONT_HERSHEY_COMPLEX_SMALL, 2, cv::Scalar(0, 255, 0),
                //1);
                //if (config.getIsHeadless() == 0)  					//for background
                ////imshow("General", background);


                //information to send (Networking)
            }

            std::cout << "\n\nUpdated Livefeed\n\n";
            loop++;
            delete target;
            //refresh loop
        }
        GaussianBlur(Image, Image,Size(3,3),31);

            //imshow("Feed", Image);
            //imshow("BoilerFeed", boilerImage);


    }
    return 0;
}
