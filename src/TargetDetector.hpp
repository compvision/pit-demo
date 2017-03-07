#ifndef TARGET_DETECTOR_H
#define TARGET_DETECTOR_H

#include "Target.hpp"
#include <opencv2/opencv.hpp>
using namespace cv;


class TargetDetector
{
public:
    TargetDetector();
    Target* processImage(Mat input, int iterator);

    //thresholds, cannies, contours, filters contours
private:
    Mat thresholdImage(Mat input, int minHue, int maxHue, int minVal, int maxVal);
    Mat canny(Mat input);
    double angle(cv::Point p1, cv::Point p2, cv::Point p0);
    std::vector<std::vector<Point> >  contour(Mat input);
    std::vector<std::vector<Point> > filterContours(std::vector<std::vector<Point> > contours, cv::Mat img);
    std::vector<Point> arcCheck1(std::vector<Point> input);
    int iterator = 1;
};

#endif
