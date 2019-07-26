/************************************************************************
* @ Creator:OYXL
* @ Project Creation time:2018/5/24
* @ Function:OpenCV录制视频
* @	Attention:需要按ESC才能完整录制视频，直接停止调试录制的视频是没有时间的
************************************************************************/
#include "opencv2/opencv.hpp"

#define WINDOW_NAME "录制视频"

int main()
{
	//VideoCapture类对象，用于打开视频和摄像头
	cv::VideoCapture capture;	
	//VideoWriter类对象，用于录像
	cv::VideoWriter recordVideo;
	cv::namedWindow(WINDOW_NAME,cv::WINDOW_AUTOSIZE);
	capture.open(0);
	recordVideo.open("boy.avi", CV_FOURCC('M', 'J', 'P', 'G'), 25.0, cv::Size(640, 480), true);
	cv::Mat frame;

	while (capture.isOpened())
	{
		capture >> frame;
		recordVideo << frame;
		imshow(WINDOW_NAME, frame);
		if (cv::waitKey(25)==27)
		{
			//ESC退出
			break;
		}
		else if (char(cv::waitKey(25)) == 'q')
		{
			//按q退出
			break;
		}
	}
	capture.release();
	//需要释放
	recordVideo.release();
	//销毁所有窗口
	cv::destroyAllWindows();
	return 0;
}