/*
 * OpenCV_ex_16.c
 *
 * THE SOBEL OPERATOR
 *
 * J. Madeira - Dec 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio

#include "stdafx.h"


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

	// Display image

	cv::imshow( "Imagem Original", originalImage );

	// Print some image features

	std::cout << "ORIGINAL IMAGE" << std::endl;

    printImageFeatures( originalImage );

    // 3 x 3 SOBEL Op.

    cv::Mat sobelImage_3x3_X;

    cv::Sobel( originalImage, sobelImage_3x3_X, CV_16S, 1, 0, 3 );

    cv::namedWindow( "Sobel 3 x 3 - X", cv::WINDOW_AUTOSIZE );

    cv::imshow( "Sobel 3 x 3 - X", sobelImage_3x3_X );

    // Scaling to 8 bits

    cv::Mat image_8_bits;

    cv::convertScaleAbs( sobelImage_3x3_X, image_8_bits );

    cv::namedWindow( "8 bits - Sobel 3 x 3 - X", cv::WINDOW_AUTOSIZE );

    cv::imshow( "8 bits - Sobel 3 x 3 - X", image_8_bits );

    cv::Mat sobelImage_3x3_Y;

    cv::Sobel( originalImage, sobelImage_3x3_Y, CV_16S, 0, 1, 3 );

    // Scaling to 8 bits

    cv::convertScaleAbs( sobelImage_3x3_Y, image_8_bits );

    cv::namedWindow( "8 bits - Sobel 3 x 3 - Y", cv::WINDOW_AUTOSIZE );

    cv::imshow( "8 bits - Sobel 3 x 3 - Y", image_8_bits );

    // Waiting

    cv::waitKey( 0 );

	// Destroy the windows

	cv::destroyAllWindows();

	return 0;
}
