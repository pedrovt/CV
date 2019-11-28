/*
 * OpenCV_ex_01.cpp
 *
 * Simple example - Opening and displaying an image
 *
 * J. Madeira - Nov 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio

//#include "stdafx.h"


// The remaining #includes

#include <iostream>

// Basic OpenCV functionalities

#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"

// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;



void on_mouse( int event, int x, int y, int flags, void *param );
int main( void )
{
    // To store an image
	cv::Mat src;
	cv::Mat image1;
	cv::Mat image2;
	cv::Mat image3;
	cv::Mat image4;
	cv::Mat image5;
	

	// Read an image from file

	// Note the flag : IMREAD_UNCHANGED

	// Question : which other flags can be used ?

	src = cv::imread( "lena.jpg", cv::IMREAD_UNCHANGED );


	if( src.empty() )
	{
	    // NOT SUCCESSFUL : the data attribute is empty

	    std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	

	// #########################################
	cv::threshold(src, image1, 127, 255, cv::THRESH_BINARY);
	cv::threshold(src, image2, 127, 255, cv::THRESH_BINARY_INV);
	cv::threshold(src, image3, 127, 255, cv::THRESH_TRUNC);
	cv::threshold(src, image4, 127, 255, cv::THRESH_TOZERO);
	cv::threshold(src, image5, 127, 255, cv::THRESH_TOZERO_INV);


	// Display the images
	cv::namedWindow( "Display window : Original", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : Original", src );

	cv::namedWindow( "Display window : THRESH_BINARY", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : THRESH_BINARY", image1 );

	cv::namedWindow( "Display window : THRESH_BINARY_INV", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : THRESH_BINARY_INV", image2 );

	cv::namedWindow( "Display window : THRESH_TRUNC", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : THRESH_TRUNC", image3 );

	cv::namedWindow( "Display window : THRESH_TOZERO", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : THRESH_TOZERO", image4 );

	cv::namedWindow( "Display window : THRESH_TOZERO_INV", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : THRESH_TOZERO_INV", image5 );
    
	// Wait for a pressed key
    cv::waitKey( 0 );
	
	// Destroy the window --- Actually not needed in such a simple program
	cv::destroyWindow( "Display window : deti.bmp" );

	
	return 0;
}

