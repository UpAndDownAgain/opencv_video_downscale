//
// Created by nrg on 10/30/19.
//

#ifndef OPENCV_VIDEO_DOWNSCALE_VIDEODOWNSCALER_H
#define OPENCV_VIDEO_DOWNSCALE_VIDEODOWNSCALER_H

#include <opencv2/opencv.hpp>
#include <exception>

class VideoDownScaler {
private:
    cv::VideoCapture video;
    cv::VideoWriter *output;
public:
    VideoDownScaler(cv::VideoCapture &cap): video(cap){};
    VideoDownScaler(std::string &inFile);
    ~VideoDownScaler();

    void downsize(double ratio, std::string &outFile);
};


#endif //OPENCV_VIDEO_DOWNSCALE_VIDEODOWNSCALER_H
