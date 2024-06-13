#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

GLUquadric * quad = NULL; ///todo: 要有一顆指標
int id0, id1, id2, id3; //分開貼圖
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;

    ///gluLookAt( 0, 0, 0, -2.4, 1.2, -6, 0, 1, 0);
}


#include <GL/glut.h>
#include "glm.h"
GLMmodel * Head = NULL;
GLMmodel * body = NULL;
GLMmodel * RightArm = NULL;
GLMmodel * RightHand = NULL;
GLMmodel * LeftArm = NULL;
GLMmodel * LeftHand = NULL;
GLMmodel * RightLeg = NULL;
GLMmodel * RightFoot = NULL;
GLMmodel * LeftLeg = NULL;
GLMmodel * LeftFoot = NULL;



//GLMmodel * upperA = NULL;

//GLMmodel * lowerA = NULL;
//GLMmodel * upperB = NULL;
//GLMmodel * lowerB = NULL;
GLMmodel * pmodel = NULL;

void drawHead(void)
{
    if (!Head) {
    Head = glmReadOBJ("data/Head.obj");
    if (!Head) exit(0);
    glmUnitize(Head);
    glmFacetNormals(Head);
    glmVertexNormals(Head, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id1);
    glmDraw(Head, GLM_SMOOTH | GLM_TEXTURE);
}

void drawbody(void)
{
    if (!body) {
    body = glmReadOBJ("data/body.obj");
    if (!body) exit(0);
    glmUnitize(body);
    glmFacetNormals(body);
    glmVertexNormals(body, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(body, GLM_SMOOTH | GLM_TEXTURE);
}

void drawRightArm(void)
{
    if (!RightArm) {
    RightArm = glmReadOBJ("data/RightArm.obj");
    if (!RightArm) exit(0);
    glmUnitize(RightArm);
    glmFacetNormals(RightArm);
    glmVertexNormals(RightArm, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(RightArm, GLM_SMOOTH | GLM_TEXTURE);
}

void drawRightHand(void)
{
    if (!RightHand) {
    RightHand = glmReadOBJ("data/RightHand.obj");
    if (!RightHand) exit(0);
    glmUnitize(RightHand);
    glmFacetNormals(RightHand);
    glmVertexNormals(RightHand, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(RightHand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftArm(void)
{
    if (!LeftArm) {
    LeftArm = glmReadOBJ("data/LeftArm.obj");
    if (!LeftArm) exit(0);
    glmUnitize(LeftArm);
    glmFacetNormals(LeftArm);
    glmVertexNormals(LeftArm, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(LeftArm, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftHand(void)
{
    if (!LeftHand) {
    LeftHand = glmReadOBJ("data/LeftHand.obj");
    if (!LeftHand) exit(0);
    glmUnitize(LeftHand);
    glmFacetNormals(LeftHand);
    glmVertexNormals(LeftHand, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(LeftHand, GLM_SMOOTH | GLM_TEXTURE);
}

void drawRightLeg(void)
{
    if (!RightLeg) {
    RightLeg = glmReadOBJ("data/RightLeg.obj");
    if (!RightLeg) exit(0);
    glmUnitize(RightLeg);
    glmFacetNormals(RightLeg);
    glmVertexNormals(RightLeg, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(RightLeg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawRightFoot(void)
{
    if (!RightFoot) {
    RightFoot = glmReadOBJ("data/RightFoot.obj");
    if (!RightFoot) exit(0);
    glmUnitize(RightFoot);
    glmFacetNormals(RightFoot);
    glmVertexNormals(RightFoot, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(RightFoot, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftLeg(void)
{
    if (!LeftLeg) {
    LeftLeg = glmReadOBJ("data/LeftLeg.obj");
    if (!LeftLeg) exit(0);
    glmUnitize(LeftLeg);
    glmFacetNormals(LeftLeg);
    glmVertexNormals(LeftLeg, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(LeftLeg, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLeftFoot(void)
{
    if (!LeftFoot) {
    LeftFoot = glmReadOBJ("data/LeftFoot.obj");
    if (!LeftFoot) exit(0);
    glmUnitize(LeftFoot);
    glmFacetNormals(LeftFoot);
    glmVertexNormals(LeftFoot, 90.0);
    }
    glBindTexture(GL_TEXTURE_2D, id3);
    glmDraw(LeftFoot, GLM_SMOOTH | GLM_TEXTURE);
}



float angleX[10] = {}, angleY[10] = {};
int angleID = 0;
int oldX = 0, oldY = 0;
#include <stdio.h>
FILE * fin = NULL;
FILE * fout = NULL;
float teapotX = 0, teapotY = 0;
void motion (int x, int y){
    if(0){
        teapotX += (x-oldX)/150.0;
        teapotY -= (y-oldY)/150.0;
        printf("glTranslatef(%.3f, %.3f, 0);\n", teapotX, teapotY);
    }else{
        angleX[angleID] += y - oldY;
        angleY[angleID] += x - oldX;
    }
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    oldX = x;
    oldY = y;
}
float oldAngleX[10] = {}, newAngleX[10] = {};
float oldAngleY[10] = {}, newAngleY[10] = {};
void timer(int t){
    glutTimerFunc(50, timer, t+1);
    if(t%10==0){
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<10; i++){
            oldAngleX[i] = newAngleX[i];
            oldAngleY[i] = newAngleY[i];

            fscanf(fin, "%f", & newAngleX[i] );
            fscanf(fin, "%f", & newAngleY[i] );
        }
    }
    float alpha = (t%10) / 10.0;
    for(int i=0; i<10; i++){
        angleX[i] =newAngleX[i]*alpha + oldAngleX[i]*(1-alpha);
        angleY[i] =newAngleY[i]*alpha + oldAngleY[i]*(1-alpha);
        printf("%.1f ", angleX[i]);
    }
    printf("\n");
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y){
    if(key=='p'){
        glutTimerFunc(0, timer, 0);
    }

    if(key=='r'){
        if(fin==NULL) fin = fopen("angle.txt", "r");
        for(int i=0; i<10; i++){
            fscanf(fin, "%.1f", & angleX[i] );
            fscanf(fin, "%.1f", & angleY[i] );
        }
        glutPostRedisplay();
    }else if(key=='s'){
        if(fout==NULL) fout = fopen("angle.txt", "w+");
        for(int i=0; i<10; i++){
            printf("%.1f ", angleX[i] );
            printf("%.1f ", angleY[i] );
            fprintf(fout, "%.1f ", angleX[i] );
            fprintf(fout, "%.1f ", angleY[i] );
        }
        printf("\n");
        fprintf(fout,"\n");
    }
    if(key=='0') angleID= 0;
    if(key=='1') angleID= 1;
    if(key=='2') angleID= 2;
    if(key=='3') angleID= 3;
    if(key=='4') angleID= 4;
    if(key=='5') angleID= 5;
    if(key=='6') angleID= 6;
    if(key=='7') angleID= 7;
    if(key=='8') angleID= 8;
    if(key=='9') angleID= 9;
}

float angle = 0;
void display()
{
    //angle+=da;
    //if(angle>90) da = -1;
    //if(angle<0) da = +1;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    glBindTexture(GL_TEXTURE_2D, id0);
    glDisable(GL_LIGHTING);
    glPushMatrix();
        glTranslatef(0, 1.5, -3);
        glScalef(6.0f, 5.0f, 5.0f);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 0); glVertex2f(-1, +1);
            glTexCoord2f(0, 1); glVertex2f(-1, -1);
            glTexCoord2f(1, 1); glVertex2f(+1, -1);
            glTexCoord2f(1, 0); glVertex2f(+1, +1);
        glEnd();
    glPopMatrix();

    /*glBindTexture(GL_TEXTURE_2D, id1);
    glPushMatrix();
        glRotatef(90, 1, 0, 0);
        glRotatef(angle++, 0, 0, 1);
        gluSphere(quad, 0.5, 30, 30); ///glutSolidTeapot( 0.3 );
    glPopMatrix();*/

    glEnable(GL_LIGHTING);

    glutSolidSphere(0.02,30,30);
    glPushMatrix();
        glRotatef(0, 0, 1, 0);
        glRotatef(angleX[0], -1, 0, 0);
        glRotatef(angleY[0], 0, 1, 0);
        drawbody();
        glPushMatrix();
            glTranslatef(0.060, 1.17, 0.25);
            glRotatef(angleX[1], 1, 0, 1);
            glRotatef(angleX[1], 0, 1, 0);
            glTranslatef(-0.060, -0.080, 0);
            glScalef(0.8f, 0.8f, 0.8f);
            glScalef(2.0f, 2.0f, 2.0f);
            drawHead();
        glPopMatrix();
        glPushMatrix();
            glPushMatrix();
                glTranslatef(-0.253, 0.767, 0.247);///glTranslatef(teapotX, teapotY, 0);
                //glTranslatef(-0.387, 0.647, 0.260);//glTranslatef(teapotX, teapotY, 0);
                glRotatef(angleX[2], 1, 0, 1);
                glRotatef(angleY[2], 0, 1, 0);
                glTranslatef(-0.133, -0.120, 0);
                glScalef(1.8f, 1.8f, 1.8f);
                drawLeftArm();
                glPushMatrix();
                    glTranslatef(-0.100, -0.080, 0.060);
                    glRotatef(angleX[3], 1, 0, 1);
                    glRotatef(angleY[3], 0, 1, 0);
                    glTranslatef(-0.060, -0.080, 0);
                    glScalef(0.8f, 0.8f, 0.8f);
                    drawLeftHand();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glPushMatrix();
                glTranslatef(0.387, 0.647, 0.260);//glTranslatef(teapotX, teapotY, 0);
                glRotatef(angleX[4], 0, 0, 1);
                glRotatef(angleY[4], 0, 1, 0);
                glScalef(1.8f, 1.8f, 1.8f);
                drawRightArm();
                glPushMatrix();
                    glTranslatef(0.220, -0.080, 0.060);
                    glRotatef(angleX[5], 1, 0, 1);
                    glRotatef(angleY[5], 0, 1, 0);
                    glTranslatef(-0.060, -0.080, 0);
                    glScalef(0.8f, 0.8f, 0.8f);
                    drawRightHand();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glPushMatrix();
                glTranslatef(-0.127, 0.033, 0.253);//glTranslatef(teapotX, teapotY, 0);
                glRotatef(angleX[6], 0, 0, 1);
                glRotatef(angleY[6], 0, 1, 0);
                glScalef(0.8f, 0.8f, 0.8f);

                drawLeftLeg();
                glPushMatrix();
                    glTranslatef(-0.007, -0.573, 0.047);
                    glRotatef(angleX[7], 1, 0, 1);
                    glRotatef(angleY[7], 0, 1, 0);
                    glTranslatef(-0.060, -0.080, 0);

                    glScalef(0.4f, 0.4f, 0.4f);
                    drawLeftFoot();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            glPushMatrix();
                glTranslatef(0.133, 0.033, 0.253);//glTranslatef(teapotX, teapotY, 0);
                glRotatef(angleX[8], 0, 0, 1);
                glRotatef(angleY[8], 0, 1, 0);
                glScalef(0.8f, 0.8f, 0.8f);
                drawRightLeg();
                glPushMatrix();
                    glTranslatef(0.113, -0.580, 0.047);
                    glRotatef(angleX[9], 1, 0, 1);
                    glRotatef(angleY[9], 0, 1, 0);
                    glTranslatef(-0.060, -0.080, 0);
                    glScalef(0.4f, 0.4f, 0.4f);
                    drawRightFoot();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

    /*
    glPushMatrix();
        glRotatef(angleX[0], -1, 0 ,0);
        glRotatef(angleY[111], 0, -1 ,0);
        drawbody();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1);

        glPushMatrix();
            glTranslatef(0, -0.05, 0.3);
            glRotatef(angleX[1], 1, 0, 1);
            glRotatef(angleY[11], 1, 0, 0);
            glRotatef(0, 0, 1, 0);
            glTranslatef(0, 1.17, 0);
            glScalef(2.0f, 2.0f, 2.0f);
            drawHead(); //glutSolidTeapot( 0.3 );
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.35, 0.73, -0.75);
            glRotatef(angleX[2], 1, 0, 1);
            glRotatef(angleY[12], 1, 0, 0);
            glTranslatef(0, -0.07, 1);
            glScalef(1.8f, 1.8f, 1.8f);
            drawRightArm();
            glPushMatrix();
                glTranslatef(0.16, 0.06, -0.94);
                glRotatef(angleX[3], 1, 0, 0);
                glRotatef(angleY[13], 1, 0, 0);
                glTranslatef(0, -0.21, 1);
                glScalef(0.8f, 0.8f, 0.8f);
                drawRightHand(); //glutSolidTeapot( 0.3 );
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-1.33, 0.73, 0.25);
            glRotatef(angleX[4], 1, 0, 1);
            glRotatef(angleY[14], 0, 1, 0);
            glTranslatef(1, -0.07, 0);
            glScalef(1.8f, 1.8f, 1.8f);
            drawLeftArm();
            glPushMatrix();
                glTranslatef(-1.15, -0.36, 0.05);
                glRotatef(angleX[5], 1, 0, 0);
                glRotatef(angleY[15], 1, 0, 0);
                glTranslatef(1, 0.21, 0);
                glScalef(0.8f, 0.8f, 0.8f);
                drawLeftHand(); //glutSolidTeapot( 0.3 );
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.1, 0.05, 0.25);
            glRotatef(angleX[6], 1, 0, 1);
            glRotatef(angleY[16], 0, 1, 0);
            glTranslatef(0, -0.07, 0);
            drawRightLeg();
            glPushMatrix();
                glTranslatef(-0.93, -0.58, -0.051);
                glRotatef(angleX[7], 1, 0, 0);
                glRotatef(angleY[17], 0, 1, 0);
                glTranslatef(1, -0.07, 0.1);
                glScalef(0.4f, 0.4f, 0.4f);
                drawRightFoot(); //glutSolidTeapot( 0.3 );
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(-1.1, 0.05, 0.25);
            glRotatef(angleX[8], 1, 0, 1);
            glRotatef(angleY[18], 0, 1, 0);
            glTranslatef(1, -0.07, 0);
            drawLeftLeg();
            glPushMatrix();
                glTranslatef(-1.06, -0.72, 0.04);
                glRotatef(angleX[9], 1, 0, 0);
                glRotatef(angleY[19], 0, 1, 0);
                glTranslatef(1, 0.07, 0);
                glScalef(0.4f, 0.4f, 0.4f);
                drawLeftFoot(); //glutSolidTeapot( 0.3 );
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
        */
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    float ar = w / (float) h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective( 60, ar, 0.01, 100 );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt( 0, 0, 2.5, 0, 0, 0, 0, 1, 0 );
}

///void timer(int t){
///    glutTimerFunc(1000, timer, t+1);
///    printf("現在起床:%d\n", t);
///}



int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(900,500);
	glutCreateWindow("HW");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(motion);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	///glutTimerFunc(0, timer, 0);

    id0 = myTexture("data/nightRoof.jpg");
    id1 = myTexture("data/head.jpg");
    id2 = myTexture("data/leg.jpg");
    id3 = myTexture("data/torso.jpg");

	const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);

    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);

    quad = gluNewQuadric(); ///todo:把這顆指標,指好
    gluQuadricTexture(quad, 0);///todo: 做好地球的貼圖

	glutMainLoop();
}
