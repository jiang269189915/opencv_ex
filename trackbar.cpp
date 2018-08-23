#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

#define WINDOWS_NAME "线性混合示例"
const int g_nMaxAlphaValue = 100;
int g_nAlphaValue;

Mat g_srcImage1, g_srcImage2, g_dstImage;

void on_trackbar(int g_nAlphaValue, void*) {
    double d_gAlphaValue = (double)g_nAlphaValue/g_nMaxAlphaValue;
    double d_gBetaValue = 1.0 - d_gAlphaValue;
    addWeighted(g_srcImage1, d_gAlphaValue, g_srcImage2, d_gBetaValue,
        0.0, g_dstImage);
    imshow(WINDOWS_NAME, g_dstImage);
}
int main(int argc, char** argv) {
    if(argc < 3) {
        printf("USAGE: ./trackbar image_path1 image_path2\n");
        return -1;
    }
    char* path1 = argv[1];
    char* path2 = argv[2];
    g_srcImage1 = imread(path1);
    g_srcImage2 = imread(path2);
    resize(g_srcImage1, g_srcImage1, g_srcImage2.size());
    if(!g_srcImage1.data or !g_srcImage2.data) {
        printf("failed to load image1:%si or image:%s\n", 
            path1, path2);
        return -1;
    }
    namedWindow(WINDOWS_NAME, 1);
    char trackbar_name[50];
    sprintf(trackbar_name, "Transparent Value: %d", g_nMaxAlphaValue);
    createTrackbar(trackbar_name, WINDOWS_NAME, &g_nAlphaValue, 
        g_nMaxAlphaValue, on_trackbar);
    on_trackbar(g_nAlphaValue, 0);
    waitKey(0);
    return 0;
}
