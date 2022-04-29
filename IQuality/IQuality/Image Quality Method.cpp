#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void main() {
	string path = "C:/Users/ASUS/Pictures/project/fire001/00001.jpg";
	Mat img = imread(path,0);
	namedWindow("original", WINDOW_AUTOSIZE);
	imshow("original", img);
	Mat imgThreshold, imgHisto;


	//binary threshold
	threshold(img, imgThreshold, 125, 255, THRESH_BINARY);
	imshow("Threshold", imgThreshold);

 // //piece-wise linear transformation
	//int hor1 = 100, hor2 = 140, ver1 = 40, ver2 = 210;
	//for (int i = 0; i < img.rows; i++) {
	//	for (int j = 0; j < img.cols; j++)
	//	{
	//		int x = ((int)img.at<uchar>(i, j));
	//		if (x >= 0 && x < hor1) {
	//			int x1 = 0, y1 = 0, x2 = hor1, y2 = ver1;
	//			img.at<uchar>(i, j) = (((x - x1) * (y2 - y1) / (x2 - x1)) + y1);
	//		}
	//		else if (x >= hor1 && x < hor2) {
	//			int x1 = hor1, y1 = ver1, x2 = hor2, y2 = ver2;
	//			img.at<uchar>(i, j) = (((x - x1) * (y2 - y1) / (x2 - x1)) + y1);
	//		}
	//		else if (x >= hor2 && x < 255) {
	//			int x1 = hor2, y1 = ver2, x2 = 255, y2 = 255;
	//			img.at<uchar>(i, j) = (((x - x1) * (y2 - y1) / (x2 - x1)) + y1);
	//		}
	//	}
	//}
	//imshow("piece-wise linear transformation", img); 


	////***********HISTOGRAM EQUALIZATION****************
	//equalizeHist(img, img);
	//imshow("histogram", img);


	//*************SPATIAL FILTERING******************

//Sharpening
	Mat laplacian, sharpenedImage;
	int kernel_size = 3;
	int depth = -1;
	Point anchor = Point(-1, -1);
	int delta = 0;
	Mat kernel = Mat::zeros(kernel_size, kernel_size, CV_32F);
	kernel.at<float>(0, 1) = -1;
	kernel.at<float>(1, 2) = -1;
	kernel.at<float>(2, 1) = -1;
	kernel.at<float>(1, 1) = 4;

	filter2D(img, laplacian, depth, kernel, anchor, delta, BORDER_DEFAULT);
	laplacian = 2 * laplacian;
	sharpenedImage = img + laplacian;

	imshow("laplacian", laplacian);
	imshow("sharpaned", sharpenedImage);
	waitKey();
}

