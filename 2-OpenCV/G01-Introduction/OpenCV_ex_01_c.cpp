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

cv::Mat image1;

void on_mouse( int event, int x, int y, int flags, void *param );
int main( void )
{
    // To store an image

	

	// Read an image from file

	// Note the flag : IMREAD_UNCHANGED

	// Question : which other flags can be used ?

	image1 = cv::imread( "deti.bmp", cv::IMREAD_UNCHANGED );


	if( image1.empty() )
	{
	    // NOT SUCCESSFUL : the data attribute is empty

	    std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	cv::setMouseCallback("Image", on_mouse);

	// #########################################
	// Display the images
	
	cv::namedWindow( "Display window : deti.bmp", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Display window : deti.bmp", image1 );
    
	// Wait for a pressed key
    cv::waitKey( 0 );
	
	// Destroy the window --- Actually not needed in such a simple program
	cv::destroyWindow( "Display window : deti.bmp" );

	
	return 0;
}

void on_mouse( int event, int x, int y, int flags, void *param ) {
	if (event == CV_EVENT_RBUTTONDOWN) {
		// Filled circle of radius 25
		std::cout << "Hello" << std::endl;
		cv::circle(image1, cv::Point(x, y), 25, CV_RGB(255, 0, 0), CV_FILLED);

		cv::imshow( "Display window : deti.bmp", image1 );
	}
}
