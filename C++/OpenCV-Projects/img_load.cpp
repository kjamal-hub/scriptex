#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img, img1;

    img = imread("Need.jpg");
    img1 = imread("Need.jpg", IMREAD_GRAYSCALE);

    if(!img.data || !img1.data)
    {
       cout << "Sorry File Not Found..." <<endl;
       return -1;
    }


    resize (img, img, Size(640,480));
    resize (img1, img1, Size(640,480));

    namedWindow("Need for Speed", WINDOW_FREERATIO);
    namedWindow("Need-Gray", WINDOW_AUTOSIZE);

    imshow("Need For Speed", img);
    imshow("Need-Gray", img1);

    moveWindow("Need-Gray", 60, 80);
    moveWindow("Need For Speed", 60 + img.cols + 8, 80);


    waitKey();

    return 0;

}
