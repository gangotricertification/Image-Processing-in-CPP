#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:/Users/ashum/Desktop/circle2.jpg");
	String window1 = "circle1";
	namedWindow(window1);
	imshow(window1, img);
	waitKey(0);
	destroyWindow(window1);
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat blur;
	GaussianBlur(gray, blur, Size(3, 3), 0, 0, BORDER_DEFAULT);

	vector<Vec3f> data;
	HoughCircles(gray, data, HOUGH_GRADIENT, 1, gray.rows / 16, 100, 30, 1, 30);
	for (int i = 0; i < data.size(); i++)
	{
		Vec3i pt = data[i];
		Point center = Point(pt[0], pt[1]);
		circle(img, center, 1, Scalar(0, 100, 100), 3, LINE_AA);
		int radii = pt[2];
		circle(img, center,radii , Scalar(255, 0, 255), 3, LINE_AA);
	}
	String window = "circle";
	namedWindow(window);
	imshow(window, img);
	waitKey(0);
	destroyWindow(window);
}
