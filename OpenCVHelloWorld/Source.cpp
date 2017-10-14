#include <algorithm>
#include <conio.h>
#include <iostream>

//OpenCV headers
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/photo.hpp"

using namespace cv;
using namespace std;



//main func
int main(int argc, char **argv)
{
	//image Matrix
	Mat src;
	Mat srcEdited;


	//get image
	string img_path = "../data/1.jpg";
	src = imread(img_path);
	if (src.empty())
	{
		cout << "Image (" << img_path << ") Not Found!" << endl;
		_getch();
		return -1;
	}

	//invert the image
	srcEdited = ~src;

	//image to grayscale
	cvtColor(src, srcEdited, CV_RGB2GRAY);

	namedWindow("Image Original", WINDOW_AUTOSIZE);
	imshow("Image Original", src);
	namedWindow("Image Edited", WINDOW_AUTOSIZE);
	imshow("Image Edited", srcEdited);

	waitKey(0);
	return 0;
}