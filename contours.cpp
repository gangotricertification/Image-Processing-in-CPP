#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{ 
	RNG rng(12345);
	Mat img = imread("C:/Users/ashum/Desktop/circle1.jpg");
	cvtColor(img, img, COLOR_BGR2GRAY);
	//blur(img, img,Size(3,3));
	Mat can;
	Mat thr;
	//threshold(img,thr,)
	double otsu;
	otsu = threshold(img, img, 0, 255, THRESH_BINARY+THRESH_OTSU);
	Canny(img, can, otsu, otsu * 2, 3, true);
	//Canny(img, can, 100,200);
	String window = "Canny";
	namedWindow(window);
	imshow(window, can);
	waitKey(0);
	destroyWindow(window);

	
	vector<vector<Point>> contours;
	vector<Vec4i> heir;
	findContours(can, contours, heir, RETR_TREE, CHAIN_APPROX_SIMPLE);
	Mat draw = Mat::zeros(can.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		drawContours(draw, contours, i, Scalar(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256)));

	}

	String window1 = "CONTOR";
	namedWindow(window1);
	imshow(window1, draw);
	waitKey(0);
	destroyWindow(window1);

}
