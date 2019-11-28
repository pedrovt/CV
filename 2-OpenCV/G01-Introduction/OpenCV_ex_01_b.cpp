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


// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;


int main( void )
{
    // To store an image

	cv::Mat image1;
	cv::Mat image2;

	// Read an image from file

	// Note the flag : IMREAD_UNCHANGED

	// Question : which other flags can be used ?

	image1 = cv::imread( "deti.bmp", cv::IMREAD_UNCHANGED );
	image2 = cv::imread( "deti.jpg", cv::IMREAD_UNCHANGED );

	if( image1.empty() || image2.empty() )
	{
	    // NOT SUCCESSFUL : the data attribute is empty

	    std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	// #########################################
	cv::Mat result;

	cv::subtract(image1, image2, result);

	// #########################################
	// Display the images
	
	cv::namedWindow( "Display window : deti.bmp", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "Display window : deti.jpg", cv::WINDOW_AUTOSIZE );
	cv::namedWindow( "Display window : result", cv::WINDOW_AUTOSIZE );

	cv::imshow( "Display window : deti.bmp", image1 );
    cv::imshow( "Display window : deti.jpg", image2 );
	cv::imshow( "Display window : result", result );

	// Wait for a pressed key
    cv::waitKey( 0 );
	
	// Destroy the window --- Actually not needed in such a simple program
	cv::destroyWindow( "Display window : deti.bmp" );
	cv::destroyWindow( "Display window : deti.jpg" );
	cv::destroyWindow( "Display window : result" );
	
	return 0;
}
