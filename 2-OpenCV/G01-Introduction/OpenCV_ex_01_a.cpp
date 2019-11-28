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

	cv::Mat image;

	// Read an image from file

	// Note the flag : IMREAD_UNCHANGED

	// Question : which other flags can be used ?

	image = cv::imread( "lena.jpg", cv::IMREAD_UNCHANGED );

	if( image.empty() )
	{
	    // NOT SUCCESSFUL : the data attribute is empty

	    std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	// Print requested info

	std::cout << "Number of lines: " 	<< image.size().height  << std::endl;		// Number of lines
	std::cout << "Number of columns: " 	<< image.size().width << std::endl;		// Number of columns
	std::cout << "Number of channels: " << image.channels() << std::endl;		// Number of channels
	std::cout << "Number of depth: " 	<< image.depth() << std::endl;			// Number of bytes per pixel
	if (image.depth() == CV_8U) {
		std::cout << "\t8 bits unsigned " << std::endl;
	}

	// Create a window to display the image
	
    // WINDOW_AUTOSIZE : image size determines window size

	// Question : can the window be resized by the user ?

	// Question : which other flags can be used ?

	cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );

    // Display the image

	


	// #########################################
	// Create a copy and show it 
	cv::Mat copy;

	copy = image.clone();
	
	cv::namedWindow( "Display window copy", cv::WINDOW_AUTOSIZE );

	// #########################################
	// Create a copy and show it 
	int height = image.size().height;
	int width = image.size().width;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (copy.at<uchar>(i,j) < 128) {
				copy.at<uchar>(i,j) = 0; 
			};
		}
	}
	// #########################################
	// Display the image
	cv::imshow( "Display window", image );
    cv::imshow( "Display window copy", copy );

	// Wait for a pressed key
    cv::waitKey( 0 );
	
	// Destroy the window --- Actually not needed in such a simple program
	cv::destroyWindow( "Display window" );
	cv::destroyWindow( "Display window copy" );

	return 0;
}
