#include <opencv/highgui.h>
int main()
{
    CvCapture * cap = cvCreateCameraCapture(0);
    CvCapture * cap = cvCreateCameraCapture(1);
    CvCapture * cap = cvCreateCameraCapture(2);
    while(1){
        IplImage * img = cvQueryFrame(cap);
        cvShowImage("week05 open cv", img);
        IplImage * img = cvQueryFrame(cap2);
        cvShowImage("week05 open cv", img2);
        IplImage * img = cvQueryFrame(cap3);
        cvShowImage("week05 open cv", img3);
        int key = cvWaitKey(33);
        if(key==27) break;
    }
    cvReleaseCapture(&cap);
    cvReleaseCapture(&cap2);
    cvReleaseCapture(&cap3);
}
