#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(){
    VideoCapture cap(0);
    Mat frame;
    while(1) {
        cap>>frame;
        cvtColor(frame, frame, CV_BGR2GRAY);
        blur(frame, frame, Size(3,3));
        Canny(frame, frame, 0, 30, 3);
        imshow("video", frame);
        if(waitKey(10)>= 0) break;
    } 
    return 0;

}
