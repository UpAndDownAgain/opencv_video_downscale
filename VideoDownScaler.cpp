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



VideoDownScaler::~VideoDownScaler() {
    video.release();
}

void VideoDownScaler::downsize(double ratio, std::string &outFile) {
    cv::Mat frame;
    cv::Mat transformedFrame;

    double frame_width = video.get(CV_CAP_PROP_FRAME_WIDTH);
    double frame_height = video.get(CV_CAP_PROP_FRAME_HEIGHT);

    this->output = new cv::VideoWriter(outFile, CV_FOURCC('M','J','P', 'G'), 1,
                                       cv::Size(frame_width * ratio, frame_height * ratio ));

    while(true){
        video >> frame;
        if(frame.empty()) break;

        cv::resize(frame, transformedFrame, cv::Size(), ratio, ratio);
        cv::cvtColor(transformedFrame, transformedFrame, cv::COLOR_RGB2BGR);
        output->write(transformedFrame);
    }

    this->output->release();
}