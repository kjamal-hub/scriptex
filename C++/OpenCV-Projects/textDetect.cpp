//
// Created by Kashif Jamal on 07/08/21.
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat large;

    large = imread("/Users/kashifjamal/Desktop/clion/Text2.PNG");

    Mat rgb;
    pyrDown(large, rgb);

    Mat small;
    cvtColor(rgb, small, COLOR_BGR2GRAY);

    Mat grad;
    Mat morphKernel = getStructuringElement(MORPH_ELLIPSE, Size(3,3));
    morphologyEx(small, grad, MORPH_GRADIENT, morphKernel);

    Mat bw;
    threshold(grad, bw, 0.0, 255.0, THRESH_OTSU);

    Mat connected;
    morphKernel = getStructuringElement(MORPH_RECT, Size(9, 1));
    morphologyEx(bw, connected, MORPH_CLOSE, morphKernel);

    Mat mask = Mat::zeros(bw.size(), CV_8UC1);
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    findContours(connected, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE, Point(0,0));
    for (int idx = 0; idx >= 0 ; idx = hierarchy[idx][0]) {
        Rect rect = boundingRect(contours[idx]);

        Mat maskROI(mask, rect);

        drawContours(mask, contours, idx, Scalar(255, 255, 255), FILLED);
        double r = (double)countNonZero(maskROI) / (rect.width * rect.height);

        if (r > 0.45 && rect.height > 8 && rect.width > 8)
            rectangle(rgb, rect, Scalar(0, 255, 0), 2);
    }

    imwrite(string("Text Detection.jpg"), rgb);
    namedWindow("Text_Detected", WINDOW_FREERATIO);
    imshow("text detected", rgb);

    waitKey();
    return 0;
}


