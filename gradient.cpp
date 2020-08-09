//CODE TAKEN FROM:
//https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html


#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>

using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernel_size = 3;
const char* window_name = "Edge Map";

void using_Sobel(int ksize, int scale, int delta, int ddepth)
{
  Mat grad_x,grad_y;
  Mat abs_g_x,abs_g_y;

  Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);
  Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, BORDER_DEFAULT);

  convertScaleAbs(grad_x,abs_g_x);
  convertScaleAbs(grad_y,abs_g_y);
  addWeighted(abs_g_x,0.5,abs_g_y,0.5,0,src_gray);




}

static void CannyThreshold(int, void*)
{
    blur( src_gray, detected_edges, Size(3,3) );
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    dst = Scalar::all(0);
    src_gray.copyTo( dst, detected_edges);
    imwrite("Deku_gray_border.jpeg",dst);
    imshow( window_name, dst );

}

int main( int argc, char** argv )
{
 cv::CommandLineParser parser( argc, argv, 
                               "{@input   |Deku_2.jpg|input image}"
                               "{ksize   k|1|ksize (hit 'K' to increase its value at run time)}"
                               "{scale   s|1|scale (hit 'S' to increase its value at run time)}"
                               "{delta   d|0|delta (hit 'D' to increase its value at run time)}"
                               "{help    h|false|show help message}" );
  std::string image_loc = samples::findFile("Deku_2.png");
  src = imread(image_loc,IMREAD_COLOR);
  //src = imread( samples::findFile( parser.get<String>( "@input" ) ), IMREAD_COLOR ); // Load an image
  if( src.empty() )
  {
    std::cout << "Could not open or find the image!\n" << std::endl;
    //std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
    return -1;
  }
  int ksize = parser.get<int>("ksize");
  int scale = parser.get<int>("scale");
  int delta = parser.get<int>("delta");
  int ddepth = CV_16S;

  //GaussianBlur(src,src_gray,Size(3,3),0,0,BORDER_DEFAULT);
  cvtColor( src, src_gray, COLOR_BGR2GRAY );
  using_Sobel(ksize,scale,delta,ddepth);
  imwrite("deku_sobel.jpg",src_gray);
  imshow("deku_sobel.jpg",src_gray);
  //createTrackbar( "Min Threshold:", window_name, &lowThreshold, max_lowThreshold, CannyThreshold );
  //CannyThreshold(0, 0);
  waitKey(0);
  return 0;
}
