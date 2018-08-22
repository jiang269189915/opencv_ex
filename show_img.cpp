#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    if(argc < 2){
        cout<<"USAGE:./bin_file PATH"<<endl;
    } 
    char* path = argv[1];
    Mat srcImage = imread(path);
    imshow("Source Picture:", srcImage);

    //resize
    Mat dstImage = Mat::zeros(255, 255, CV_8UC3);
    resize(srcImage, dstImage, Size(srcImage.cols/2, srcImage.rows/2));
    imshow("Resize Picture:", dstImage);

    //erodesion
    Mat element = getStructuringElement(MORPH_RECT, Size(15,15));
    Mat erode_img, blur_img;
    erode(dstImage, erode_img, element);
    imshow("Erode Picture", erode_img);

    //blur 
    blur(dstImage, blur_img, Size(7,7));
    imshow("Blur Picture", blur_img);

    //canny
    Mat grey_img, edge;
    cvtColor(dstImage, grey_img, CV_BGR2GRAY);
    imshow("grey picture", grey_img);
    blur(grey_img, edge, Size(3,3));
    imshow("blur after grey", edge);
    Canny(edge, edge, 3, 9, 3);
    imshow("Canny Picture", edge);
    waitKey(0);
    return 0;
}
