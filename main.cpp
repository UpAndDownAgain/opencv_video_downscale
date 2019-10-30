#include <iostream>
#include <opencv2/opencv.hpp>

#include "VideoDownScaler.h"

int main(int argc, char **argv) {
    if(argc != 2){
        std::cerr << "Zadejte cestu k souboru jako argument" << std::endl;
        return -1;
    }

    cv::VideoCapture cap(argv[1]);
    std::string outFile = "downsized";
    VideoDownScaler vid(cap);

    vid.downsize(0.5, outFile);

    return 0;
}