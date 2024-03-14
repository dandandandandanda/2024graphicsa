#include <GL/glut.h>
#include <stdio.h>
float angle =0, oldX =0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glClearColor( 0.0, 1.0, 0.9, 1.0);
        glColor3f(1, 0, 0);
        glTranslatef(0.8, 0, 0);
        glRotatef(angle++, 0, 0, 1);
        glScalef(0.3, 0.3, 0.3);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}


int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 keyboard mouse motion");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    glutMainLoop();
}
