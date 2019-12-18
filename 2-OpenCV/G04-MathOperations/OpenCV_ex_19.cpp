/*
 * OpenCV_ex_18.c
 *
 *
 * J. Madeira - Dec 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio

// #include "stdafx.h"


// #include <iostream>

#include <iostream>

#include "opencv2/core/core.hpp"

#include "opencv2/imgproc/imgproc.hpp"

#include "opencv2/highgui/highgui.hpp"


// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;


// AUXILIARY  FUNCTION

void printImageFeatures(const cv::Mat &image)
{
	std::cout << std::endl;

	std::cout << "Number of rows : " << image.size().height << std::endl;

	std::cout << "Number of columns : " << image.size().width << std::endl;

	std::cout << "Number of channels : " << image.channels() << std::endl;

	std::cout << "Number of bytes per pixel : " << image.elemSize() << std::endl;

	std::cout << std::endl;
}


// MAIN

int main( int argc, char** argv )
{
    if( argc != 2 )
    {
		std::cout << "The name of the image file is missing !!" << std::endl;

        return -1;
    }

	cv::Mat originalImage;

	originalImage = cv::imread( argv[1], cv::IMREAD_UNCHANGED );

	if( originalImage.empty() )
	{
		// NOT SUCCESSFUL : the data attribute is empty

		std::cout << "Image file could not be open !!" << std::endl;

	    return -1;
	}

	if( originalImage.channels() > 1 )
	{
		// Convert to a single-channel, intensity image
		cv::cvtColor( originalImage, originalImage, cv::COLOR_BGR2GRAY, 1 );
	}

	// Create window
    cv::namedWindow( "Imagem Original", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Imagem Original", originalImage );

	// Print some image features
	std::cout << "ORIGINAL IMAGE" << std::endl;
    printImageFeatures( originalImage );

	// Dilation
	int dilation_size = 11;
    cv::Mat result;
	cv::Mat kernel = cv::getStructuringElement(0, cv::Size( dilation_size, dilation_size ));
	cv::dilate(originalImage, result, kernel);

    cv::namedWindow( "Dilate ", cv::WINDOW_AUTOSIZE );
    cv::imshow( "Dilate ", result);

    // Waiting

    cv::waitKey( 0 );

	// Destroy the windows

	cv::destroyAllWindows();

	return 0;
}
