
#include<iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <map>;


using namespace cv;
using namespace std;


int main()


{
	Mat img = imread("C:/Users/ashum/Desktop/child2.jpg");
	//Mat img = imread("C:/Users/ashum/Desktop/steel/actual/bad10.bmp");
	Mat gray;

	cvtColor(img, gray, COLOR_BGR2GRAY);


	int histogram[256];

	// initialize all intensity values to 0
	int pp = 0;
	for (int i = 0; i < 255; i++)
	{
		histogram[i] = 0;
	}


	// calculate the no of pixels for each intensity values
	//cout << "\n------------------>"<<crp[i].at<uchar>(12, 36)<<">-----------------\n";
	for (int y = 0; y < img.rows; y++)
	{
		for (int x = 0; x < img.cols; x++)
		{
			//cout << x;
			Vec2b color = img.at<Vec2b>(Point(x, y));
			histogram[color[1]]++;
			//cout << "x" << color;

		}
		//cout << histogram[y] << "---------";
	}
	//cout << "\n sddssdsdsdsdsdsdsdsdsds";
	map<int, int> dic;
	int black_thr, white_thr;
	
	for (int i = 0; i < 256; i++)
	{
		cout << histogram[i] << "----" << i << "  \n";
		dic[i] = histogram[i];
		//if (histogram[i] <= 30)
		//{
		//	if(i)
		//}
	}
	for (int i = 0; i < 256; i++)
	{
		if (dic[i] > 50)
		{
			black_thr = i;
			break;
		}
	}
	for (int i = 255; i >= 0; i--)
	{
		if (dic[i] > 50)
		{
			white_thr = i;
			break;
		}
	}
	cout << "lower threshold" << black_thr;
	cout << "\n higher threshold" << white_thr;

	
	for (int i = 0; i < 256; i++)
	{

	}
	Mat img1, img2;
	img1 = img.clone();
	//threshold(img1,img,)


	// draw the histograms

	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / 256);

	Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

	// find the maximum intensity element from histogram
	int max = histogram[0];
	for (int i = 1; i < 256; i++) {
		if (max < histogram[i]) {
			max = histogram[i];
		}
	}

	// normalize the histogram between 0 and histImage.rows

	for (int i = 0; i < 255; i++) {
		histogram[i] = ((double)histogram[i] / max) * histImage.rows;
	}

	// draw the intensity line for histogram
	for (int i = 0; i < 255; i++)
	{
		line(histImage, Point(bin_w * (i), hist_h),
			Point(bin_w * (i), hist_h - histogram[i]),
			Scalar(0, 0, 0), 1, 8, 0);
	}
	cout << "sdffffffffffffffffffffffff";
	// display histogram
	//namedWindow("Intensity Histogram", CV_WINDOW_AUTOSIZE);
	imshow("Intensity Histogram", histImage);
	Mat parentimg = imread("C:/Users/ashum/Desktop/steel/actual/parent2.jpg");
	Mat parentgray;
	cvtColor(parentimg, parentgray, COLOR_BGR2GRAY);
	Mat thr;
	//threshold(parentgray, thr, white_thr, 255, THRESH_BINARY);
	threshold(parentgray, thr, black_thr+10, 255, THRESH_BINARY);
	Mat newim = 255 - thr;
	imshow("sdfs", newim);
	//namedWindow("Image", CV_WINDOW_AUTOSIZE);
	imshow("parent", parentgray);
	imshow("Image", gray);
	waitKey();
	return 0;
}


/*
{
	Mat img = imread("C:/Users/ashum/Desktop/circle2.jpg");

	for (int i = 0; i < img.cols; i++)
	{
		int black_cnt = 0;
		for (int j = 0; j < img.rows; j++)
		{
			if (img.at<cv::Vec3b>(j, i)[0] == 0)
				black_cnt++;
		}
		if (black_cnt == img.rows)
			continue;
		else
		{
			Rect roi(i, 0, img.cols - i, img.rows);
			img = img(roi);
			break;
		}
	}
	imshow("Result", img);
	waitKey(0);
	return 0;

}
*/