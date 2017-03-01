#include "Target.hpp"
#include "TargetProcessor.hpp"
#include <math.h>

TargetProcessor::TargetProcessor()
{
    Width = 0.260; //meters
    focalLength = 700; //varies by camera
    horizCenter = 320; //aslo varies by camera (center horizontal point on video)
    vertCenter = 240; //center vertical point on video

} //constructor

void TargetProcessor::loadTarget(Target* target){
    imageTarWidth = target->getWidth();
    imageTarHeight = target->getHeight();
    imageTarCenter = target->getCenter();
}


void TargetProcessor::temporaryGetPoints(int width, int height, cv::Point center)
{
    imageTarWidth = width;
    imageTarHeight = height;
    imageTarCenter = center;
}

double TargetProcessor::calculateDistance()
{

    return Width * focalLength / imageTarWidth; //returns the distance (m)


}

double TargetProcessor::calculateAzimuth(){ //unsure if this is working properly, but is returning a reasonable looking value{
    double offset = imageTarCenter.x - horizCenter;
    return (atan(offset/focalLength))*(180/M_PI); //in degrees
}

double TargetProcessor::calculateAltitude(){ //same comment as calculateAzimuth(){
    int cameraAngle = 0; //angle the camera is pointing up from the horizon; assumes camera is level
    double offset =  vertCenter - imageTarCenter.y;
    return (atan(offset/focalLength))*(180/M_PI) + cameraAngle; //in degrees
}
