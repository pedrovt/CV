/*
 * OpenCV_ex_07.cpp
 *
 * Drawing 2D primitives and user interaction
 *
 * J. Madeira - Dez 2012 + Nov 2017
 */


// Visual Studio ONLY - Allowing for pre-compiled header files

// This has to be the first #include

// Remove it, if you are not using Windows and Visual Studio

#include "stdafx.h"


#include <iostream>


#include "opencv2/core/core.hpp"

#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"


// If you want to "simplify" code writing, you might want to use:

// using namespace cv;

// using namespace std;


// GLOBAL VARIABLES

cv::Mat GRAY_IMAGE;

cv::Mat RGB_IMAGE;

int CHOICE;


void myMouse_GRAY( int event, int x, int y, int flags, void *userdata )
{
     if( event == cv::EVENT_LBUTTONDOWN )
     {
         switch( (char)CHOICE )
         {
             case '1' :

				 // Line segment

				 // Question : what is the orientation of the image coordinate axes ?

				 // Question : what are the other possible arguments ?

                 cv::line( GRAY_IMAGE, cv::Point( x - 20, y - 20 ), cv::Point( x + 20, y + 20 ), cv::Scalar( 255 ) );

                 cv::imshow( "GRAY IMAGE", GRAY_IMAGE );

                 break;

             case '2' :

                 // Filled circle of radius 25

				 // Question : what are the other possible arguments ?
				 
				 cv::circle( GRAY_IMAGE, cv::Point( x, y ), 25, cv::Scalar( 255 ), cv::FILLED );

                 cv::imshow( "GRAY IMAGE", GRAY_IMAGE );

                 break;

             case '3' :

                 // Square
				 
				 // Question : what are the other possible arguments ?

                cv::rectangle( GRAY_IMAGE, cv::Point( x - 10, y - 10 ), cv::Point( x + 10, y + 10 ), cv::Scalar( 255 ), cv::FILLED );

                cv::imshow( "GRAY IMAGE", GRAY_IMAGE );

                break;
         }
     }
}


void myMouse_RGB( int event, int x, int y, int flags, void *userdata )
{
     if( event == cv::EVENT_LBUTTONDOWN )
     {
         switch( (char)CHOICE )
         {
             case '1' :

                 // Line segment

                 cv::line( RGB_IMAGE, cv::Point( x - 20, y + 20 ), cv::Point( x + 20, y - 20 ), cv::Scalar( 0, 0, 255 ) );

                 cv::imshow( "RGB IMAGE", RGB_IMAGE );

                 break;

             case '2' :

                 // Filled circle of radius 25

                 cv::circle( RGB_IMAGE, cv::Point( x, y ), 25, cv::Scalar( 255, 0, 0 ), cv::FILLED );    // B,G,R !!

                 cv::imshow( "RGB IMAGE", RGB_IMAGE );

                 break;

             case '3' :

                 // Square
				 
				 cv::rectangle( RGB_IMAGE, cv::Point( x - 10, y - 10 ), cv::Point( x + 10, y + 10 ), cv::Scalar( 0, 255, 0 ), cv::FILLED );

                 cv::imshow( "RGB IMAGE", RGB_IMAGE );

                 break;
         }
     }
}


int main( void )
{
    // Create two images with black background

	GRAY_IMAGE = cv::Mat::zeros( 512, 256, CV_8UC1 );

	RGB_IMAGE = cv::Mat::zeros( 256, 512, CV_8UC3 );

	// Display windows

    cv::namedWindow( "GRAY IMAGE", cv::WINDOW_AUTOSIZE );

	cv::namedWindow( "RGB IMAGE", cv::WINDOW_AUTOSIZE );

    // Display and print features

    cv::imshow( "GRAY IMAGE", GRAY_IMAGE );

    std::cout << "GRAY-LEVELS Image" << std::endl;

	std::cout << "Number of rows : " << GRAY_IMAGE.size().height << std::endl;

	std::cout << "Number of columns : " << GRAY_IMAGE.size().width << std::endl;

	std::cout << "Number of channels : " << GRAY_IMAGE.channels() << std::endl;

	std::cout << "Number of bytes per pixel : " << GRAY_IMAGE.elemSize() << std::endl;

	std::cout << std::endl;

	// Display and print features

	cv::imshow( "RGB IMAGE", RGB_IMAGE );

	std::cout << "RGB Image" << std::endl;

	std::cout << "Number of rows : " << RGB_IMAGE.size().height << std::endl;

	std::cout << "Number of columns : " << RGB_IMAGE.size().width << std::endl;

	std::cout << "Number of channels : " << RGB_IMAGE.channels() << std::endl;

	std::cout << "Number of bytes per pixel : " << RGB_IMAGE.elemSize() << std::endl;

	std::cout << std::endl;

	// Registering the mouse callback functions

    cv::setMouseCallback( "GRAY IMAGE", myMouse_GRAY );

    cv::setMouseCallback( "RGB IMAGE", myMouse_RGB );

    // Processing keyboard events

    for( ; ; )
    {
		std::cout << std::endl;

		std::cout << "1 --- Line Segment" << std::endl;

		std::cout << "2 --- Circle" << std::endl;

		std::cout << "3 --- Square" << std::endl;

		std::cout << "Q --- Quit" << std::endl;

		std::cout << std::endl;

        CHOICE = cv::waitKey( 0 );

        if( ((char)CHOICE == 'Q') || ((char)CHOICE == 'q') )
        {
            break;
        }

        switch( (char)CHOICE )
        {
            case '1' :

				std::cout << "LINE SEGMENT : "

                     << "Select the midpoint with the mouse LEFT BUTTON"

                     << std::endl;

                break;

            case '2' :

				std::cout << "CIRCLE : Select the center with the mouse LEFT BUTTON" << std::endl;

                break;

            case '3' :

				std::cout << "SQUARE : Select the center with the mouse LEFT BUTTON" << std::endl;

                break;
        }
    }

	// Destroy the windows --- Actually not needed in such a simple program

	cv::destroyAllWindows( );

	return 0;
}
