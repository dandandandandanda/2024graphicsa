#include <GL/glut.h>
#include <stdio.h>/// ���F printf()

float teapotX = 0, teapotY = 0;
float angle = 0;
void mouse(int button, int state, int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glPopMatrix();///��
        ///glTranslatef(teapotX, teapotY, 0);
        glRotatef(angle, 0, 0, 1);//z
        glutSolidTeapot( 0.3 );
	glutSolidTeapot(0.3);
	glutSwapBuffers();
}
void motion(int x, int y)
{
    angle = x;
    display();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");
	glutDisplayFunc(display);
	glutMouseFunc(mouse);///+
	glutMotionFunc(motion);

	glutMainLoop();
}
