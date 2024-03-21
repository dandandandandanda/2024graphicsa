
#include <opencv/highgui.h>
int main()
{
    CvCapture * cap = cvCreateCameraCapture(0);
    while(1){
        IplImage * img = cvQueryFrame(cap);
        cvShowImage("week05 open cv", img);
        int key = cvWaitKey(33);
        if(key==27) break;
    }
    cvReleaseCapture(&cap);
}
