#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
    cv::VideoCapture cap;
    cv::Mat frame;
    cap.open(argv[1]);

    if(! cap.isOpened() ){
        std::cerr << "error otevirani vide" << std::endl;
        return -1;
    }
    while(true){
        cap >> frame;
        if(frame.empty()){
            break;
        }

    }

    return 0;
}