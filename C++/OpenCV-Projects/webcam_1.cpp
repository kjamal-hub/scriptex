#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
   VideoCapture cap(0);

   if(!cap.isOpened())
        return -1;

   for(;;)
   {
       Mat Frame;
       cap >> Frame;
       namedWindow("Web-cam", WINDOW_FREERATIO);
       imshow("Web-cam", Frame);

       if(waitKey(1) >= 0)
          break;
   }
    return 0;
}
