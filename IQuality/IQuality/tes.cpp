/**
 * @function EqualizeHist_Demo.cpp
 * @brief Demo code for equalizeHist function
 * @author OpenCV team
 */

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

/**
 * @function main
 */
void main()
{
    string path = "C:/Users/ASUS/Pictures/project/fire001/00075.jpg";
    //	VideoCapture cap(0);
    Mat img = imread(path), imgResize, imgThreshold, imgHisto;
    //! [Load image]

    //! [Convert to grayscale]
    cvtColor(img, img, COLOR_BGR2GRAY);
    //! [Convert to grayscale]

    //! [Apply Histogram Equalization]
    Mat dst;
    equalizeHist(img, dst);
    //! [Apply Histogram Equalization]

    //! [Display results]
    imshow("Source image", img);
    imshow("Equalized Image", dst);
    //! [Display results]

    //! [Wait until user exits the program]
    waitKey();
    //! [Wait until user exits the program]


}