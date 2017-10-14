OpenCV in Visual Studio:
==============

- Download the dependencies

    - OpenCV library: https://opencv.org/releases.html (Win pack)
    
- Extract the OpenCV libraries in to a local path

- Open "OpenCVHelloWorld.sln" using Visual Studio

- Select the Solution Configurations ( Build -> Configuration Manager) as follows,
  
    - Configuration: Debug
    
    - Platform: x64
    
- Add the libraries to the solution
    
    - Project -> OpenCVHelloWorld Properties...
    
    - Select "C/C++" -> "General" (drop down list)
     
      In Right Hand Side select "Additional Include Directories" set the opencv "build\include" path
      <pre>EXample:-  C:\Program Files\opencv\build\include
      </pre>
      
    - Select "Linker" -> "General" (drop down list)
    
      In "Additional Library Directories" set the opencv "build\x64\vc14\lib" path
      <pre>EXample:-  C:\Program Files\opencv\build\x64\vc14\lib
      </pre>
      
    - Select "Linker" -> "Input" (drop down list)
    
       In "Additional Dependencies" select the drop down arrow -> Edit...

       Type "opencv_world320d.lib" and hit OK
       
Voila, You have completed setting things up. Let's CODE

Sample OpenCV project code
==============

<pre>
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

	//display the images
	namedWindow("Image Original", WINDOW_AUTOSIZE);
	imshow("Image Original", src);
	namedWindow("Image Edited", WINDOW_AUTOSIZE);
	imshow("Image Edited", srcEdited);

	waitKey(0);
	return 0;
}

</pre>
     
