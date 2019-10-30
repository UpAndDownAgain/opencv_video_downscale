//
// Created by nrg on 10/30/19.
//

#include "VideoDownScaler.h"

VideoDownScaler::VideoDownScaler(std::string &inFile) {
    this->video.open(inFile);
    if(!this->video.isOpened()){
        throw std::invalid_argument("error opening file");
    }

}

void &VideoDownScaler::downsize(double ratio, std::string &outFile) {
    cv::Mat frame;
    cv::Size originalSize;

    video >> frame;
    originalSize = frame.size();

    this->output = new cv::VideoWriter(outFile, CV_FOURCC('M','J','P', 'G'), 23,
            cv::Size(originalSize.width * ratio, originalSize.height * ratio ));
}
