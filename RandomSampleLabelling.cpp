// RandomSampleLabelling.cpp : Defines the entry point for the application.
//

#include <iostream>

#include <filesystem>
#include <fstream>
#include <chrono> 

#include <opencv2/opencv.hpp>

namespace fs = std::filesystem;

// data path
const std::string dataPath = "D:\\datasets\\ngantuk\\data";
// output path
const std::string outPath = "D:\\datasets\\ngantuk\\random_sample";

int main()
{
	std::string folder = "01";

	int SAMPLE_PER_CLASS = 50;
	int sampleCounter = 0;
	int videoCounter = 0;

	for (const auto& entry : fs::directory_iterator(dataPath + "\\" + folder)) {

		// get file name (class)
		std::string classNumber = entry.path().stem().string();
		std::cout << "====== class " << classNumber << " ======" << std::endl;

		// Create a VideoCapture object and open the input file
		cv::VideoCapture cap(entry.path().string());

		if (!cap.isOpened())  // isOpened() returns true if capturing has been initialized.
		{
			std::cout << "Cannot open the video file. \n";
			return -1;
		}

		// current frame container
		cv::Mat currentFrame;

		// variable for storing video information
		float frameCounter = 1;

		// get frames from camera
		while (1) {

			// read current frame
			cap.read(currentFrame);

			// check if the video has finished
			if (currentFrame.empty()) 
				break;

			// Display current frame
			cv::imshow("Frame", currentFrame);

			char c = (char)cv::waitKey(0);
			switch (c) {
			case 49: //1
				sampleCounter++;
				std::cout << "sample " << sampleCounter << "=> frame: " << frameCounter << " both open" << std::endl;
				break; 
			case 50: //2
				sampleCounter++;
				std::cout << "sample " << sampleCounter << "=> frame: " << frameCounter << " eye close mouth open" << std::endl;
				break;
			case 51: //3
				sampleCounter++;
				std::cout << "sample " << sampleCounter << "=> frame: " << frameCounter << " eye open mouth close" << std::endl;
				break;
			case 52: //4
				sampleCounter++;
				std::cout << "sample " << sampleCounter << "=> frame: " << frameCounter << " both close" << std::endl;
				break;
			default:
				break;
			};
			if (c == 27) //Esc
				break;

			// limit sample per class
			if (sampleCounter == SAMPLE_PER_CLASS + (SAMPLE_PER_CLASS * videoCounter))
				break;

			// increase frame counter
			frameCounter++;
		}

		// When everything done, release the video capture object
		cap.release();

		videoCounter++;
	}

	// closes all the frames
	cv::destroyAllWindows();

	return 0;
}
