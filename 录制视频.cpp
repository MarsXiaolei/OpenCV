/************************************************************************
* @ Creator:OYXL
* @ Project Creation time:2018/5/24
* @ Function:OpenCV¼����Ƶ
* @	Attention:��Ҫ��ESC��������¼����Ƶ��ֱ��ֹͣ����¼�Ƶ���Ƶ��û��ʱ���
************************************************************************/
#include "opencv2/opencv.hpp"

#define WINDOW_NAME "¼����Ƶ"

int main()
{
	//VideoCapture��������ڴ���Ƶ������ͷ
	cv::VideoCapture capture;	
	//VideoWriter���������¼��
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
			//ESC�˳�
			break;
		}
		else if (char(cv::waitKey(25)) == 'q')
		{
			//��q�˳�
			break;
		}
	}
	capture.release();
	//��Ҫ�ͷ�
	recordVideo.release();
	//�������д���
	cv::destroyAllWindows();
	return 0;
}