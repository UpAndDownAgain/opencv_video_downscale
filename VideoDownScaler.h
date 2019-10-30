//
// Created by nrg on 10/30/19.
//

#ifndef OPENCV_VIDEO_DOWNSCALE_VIDEODOWNSCALER_H
#define OPENCV_VIDEO_DOWNSCALE_VIDEODOWNSCALER_H

#import <opencv2/opencv.hpp>
#import <exception>

class VideoDownScaler {
private:
    cv::VideoCapture video;
    cv::VideoWriter *output;
    cv::Mat frame;
public:
    VideoDownScaler(cv::VideoCapture &cap): video(cap){};
    VideoDownScaler(std::string &inFile);

    void downsize(double ratio, std::string &outFile);
};


#endif //OPENCV_VIDEO_DOWNSCALE_VIDEODOWNSCALER_H
