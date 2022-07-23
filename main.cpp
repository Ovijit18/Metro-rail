#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glOrtho(-50,50,-40,40,-15,5);
}
void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=360; i>=0; i--)
    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();

}

static float m = -20, ty = 0, n = -20, car1 = -20, car2 = -20;

void metroMove()
{
    m += .2;
    if(m > 200)
    {
        m = -1;
    }
    glutPostRedisplay();
}

void cMove()
{
    car1 += .1;
    if(car1 > 200)
    {
        car1 = -1;
    }
    glutPostRedisplay();
}

void reverseCarMove()
{
    car2 += .1;
    if(car2 > 200)
    {
        car2 = -1;
    }
    glutPostRedisplay();
}

void reverseCar()
{
    float q = 100;
    //reverseCarMove();
    glPushMatrix();

    glTranslatef(-car2,0,0);

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(q-3, -28);
    glVertex2f(q+15, -28);
    glVertex2f(q+16, -24);
    glVertex2f(q-2.8, -24);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(q-1, -24);
    glVertex2f(q+14.5, -24);
    glVertex2f(q+12, -20);
    glVertex2f(q+1, -20);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q, -25);
    glVertex2f(q+13, -25);
    glVertex2f(q+12.4, -21);
    glVertex2f(q+1.5, -21);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(q+6, -28);
    glVertex2f(q+7.5, -28);
    glVertex2f(q+7.5, -20);
    glVertex2f(q+6, -20);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    circle(2,2,109.5,-28.5);
    circle(2,2,101.5,-28.5);

    glColor3ub(247, 244, 245);
    circle(1,1,109.5,-28.5);
    circle(1,1,101.5,-28.5);

    glPopMatrix();
}

void carMove()
{
    float q = -100;
    //cMove();
    glPushMatrix();

    glTranslatef(car1,0,0);
    //car1
    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(q+1, -36);
    glVertex2f(q+15, -36);
    glVertex2f(q+15, -32);
    glVertex2f(q, -32);
    glEnd();

    glColor3ub(255, 0, 0);
    circle(2,2.1,-85.3,-34);

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(q+1, -32);
    glVertex2f(q+14.5, -32);
    glVertex2f(q+12, -28);
    glVertex2f(q+2, -28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+2, -33);
    glVertex2f(q+14, -33);
    glVertex2f(q+12, -29);
    glVertex2f(q+2.5, -29);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 0);
    glVertex2f(q+7, -36);
    glVertex2f(q+8, -36);
    glVertex2f(q+8, -28);
    glVertex2f(q+7, -28);
    glEnd();

    glColor3f(0.0f,0.0f,0.0f);
    circle(2,2,-96.5,-36.5);
    circle(2,2,-89.5,-36.5);

    glColor3ub(247, 244, 245);
    circle(1,1,-96.5,-36.5);
    circle(1,1,-89.5,-36.5);


    glPopMatrix();
}

void moving()
{
    float q = -100;
    //metroMove();

    glPushMatrix();

    glTranslatef(m,0,0);

    //connector
    glBegin(GL_QUADS);
    glColor3ub(229, 231, 233);
    glVertex2f(q+25, 17);
    glVertex2f(q+25.3, 17);
    glVertex2f(q+25.3, 25);
    glVertex2f(q+25, 25);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(231, 76, 60);
    glVertex2f(q+24, 24.5);
    glVertex2f(q+26, 24.5);
    glVertex2f(q+26, 26);
    glVertex2f(q+24, 26);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(52, 73, 94);
    glVertex2f(q+23, 17);
    glVertex2f(q+27, 17);
    glVertex2f(q+27, 18);
    glVertex2f(q+23, 18);
    glEnd();

    //Metro Rail
    glBegin(GL_QUADS);
    glColor3ub(247, 220, 111);
    glVertex2f(q, 7);
    glVertex2f(q+45,7);
    glVertex2f(q+40, 17);
    glVertex2f(q+5,17);
    glEnd();

    //Top glass
    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+5, 15.8);
    glVertex2f(q+40,15.8);
    glVertex2f(q+39, 16.5);
    glVertex2f(q+5.5,16.5);
    glEnd();

    //Driver panel
    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+40, 11);
    glVertex2f(q+43,11);
    glVertex2f(q+41.5, 15);
    glVertex2f(q+38,15);
    glEnd();

    //First window
    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+30, 11);
    glVertex2f(q+39,11);
    glVertex2f(q+37, 15);
    glVertex2f(q+30,15);
    glEnd();

    //First Gate
    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+26, 7);
    glVertex2f(q+29,7);
    glVertex2f(q+29, 15);
    glVertex2f(q+26,15);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+15, 11);
    glVertex2f(q+25,11);
    glVertex2f(q+25, 15);
    glVertex2f(q+15,15);
    glEnd();


    //Second gate
    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+11, 7);
    glVertex2f(q+14,7);
    glVertex2f(q+14, 15);
    glVertex2f(q+11,15);
    glEnd();

    //Last window
    glBegin(GL_QUADS);
    glColor3ub(88, 183, 241);
    glVertex2f(q+2, 11);
    glVertex2f(q+10,11);
    glVertex2f(q+10, 15);
    glVertex2f(q+3.6,15);
    glEnd();

    circle(2,2,-47,-38);

    glPopMatrix();
}


void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Moon
    glColor3ub(247, 244, 245);
    circle(4,4,35,32);
    glColor3ub(0, 0, 0 );
    circle(4,4,36,33);

    //star
    glColor3ub(247, 244, 245);
    circle(.2,.2,0,37);
    circle(.2,.2,-10,39);
    circle(.2,.2,-13,35);
    circle(.2,.2,-15,38);
    circle(.2,.2,-18,36);
    circle(.2,.2,-25,39);
    circle(.2,.2,-27,36);
    circle(.2,.2,-27.5,38);
    circle(.2,.2,-29,39);
    circle(.2,.2,-31,36);
    circle(.2,.2,-37,38);
    circle(.2,.2,-39,36);
    circle(.2,.2,-40,38);
    circle(.2,.2,-42.5,39);
    circle(.2,.2,-45.5,36);
    circle(.2,.2,-24,38.5);
    circle(.2,.2,1,37.5);
    circle(.2,.2,-2,38.5);
    circle(.2,.2,-5,39.5);
    circle(.2,.2,7.5,36);
    circle(.2,.2,0,30);
    circle(.2,.2,8,39);
    circle(.2,.2,15,30);
    circle(.2,.2,18,31);
    circle(.2,.2,20,35);
    circle(.2,.2,25,33);
    circle(.2,.2,29,29);
    circle(.2,.2,28.5,27);
    circle(.2,.2,31,38);
    circle(.2,.2,36,33);
    circle(.2,.2,35,37);
    circle(.2,.2,47,35);
    circle(.2,.2,49,31);
    circle(.2,.2,37,30);
    circle(.2,.2,37,20);
    circle(.2,.2,39,14);

    //1st Building
    glColor3ub(10, 252, 227);
    glRectf(-50, -10, -35, 30);
    glRectd(-50, 30, -45, 35);
    glRectd(-45, 30, -40, 32.5);

    //building window
    glColor3ub(32, 73, 229);
    glRectf(-48, 29.5, -44, 32);
    glRectf(-48, 25, -33, 28);
    glRectf(-48, 19, -33, 22);
    glRectf(-48, 13, -33, 16);
    glRectf(-48, 7, -33, 10);
    glRectf(-48, 1, -33, 4);
    glRectf(-48, -5, -33, -2);
    glColor3ub(10, 252, 227);
    glRectf(-44, -10, -41, 30);

    //3rd building
    glColor3ub(0, 164, 247);
    glRectf(-23, -10, -8, 32);

    glColor3ub(32, 73, 229);
    glRectf(-23, 29, -8, 31);
    glRectf(-23, 26, -8, 28);
    glRectf(-23, 23, -8, 25);
    glRectf(-23, 20, -8, 22);
    glRectf(-23, 17, -8, 19);
    glRectf(-23, 14, -8, 16);
    glRectf(-23, 11, -8, 13);
    glRectf(-23, 8, -8, 10);
    glRectf(-23, -6, -8, -4);
    glRectf(-23, -3, -8, -1);
    glColor3ub(0, 164, 247);
    glRectf(-20, -10, -19, 32);
    glRectf(-14, -10, -13, 32);

    //2nd Building
    glColor3ub(255, 129, 3);
    glRectf(-37, -10, -22, 35);


    glColor3ub(32, 73, 229);
    glRectf(-37, 32, -22, 33);
    glRectf(-37, 29, -22, 30);
    glRectf(-37, 26, -22, 27);
    glRectf(-37, 23, -22, 24);
    glRectf(-37, 20, -22, 21);
    glRectf(-37, 17, -22, 18);
    glRectf(-37, 14, -22, 15);
    glRectf(-37, 11, -22, 12);
    glRectf(-37, 5, -22, 6);
    glRectf(-37, 2, -22, 3);
    glRectf(-37, -1, -22, 0);
    glRectf(-37, -4, -22, -3);

    //5th building

    glBegin(GL_QUADS);
    glColor3ub(236, 65, 205);
    glVertex2f(5, -10);
    glVertex2f(19, -10);
    glVertex2f(19, 30);
    glVertex2f(5, 35);
    glEnd();

    glColor3ub(32, 73, 229);
    glRectf(7, 30, 10, 32);
    glRectf(7, 26, 10, 28);
    glRectf(13, 26, 16, 28);
    glRectf(13, 22, 16, 24);
    glRectf(13, 18, 16, 20);
    glRectf(13, 14, 16, 16);
    glRectf(13, 10, 16, 12);
    glRectf(13, 6, 16, 8);

    //4th building
    glColor3ub(192, 192, 192);
    circle(4, 4, 1, 25);

    glColor3ub(229, 224, 219);
    glRectf(-8, -10, 10, 25);
    glColor3ub(32, 73, 229);
    glRectf(-6, -8, 8, 23);


    //wire
    glColor3ub(52, 73, 94);
    glRectf(-50, 25, 50, 25.5);

    //Road upper top
    glColor3ub(91, 109, 25);
    circle(4, 4, -48, -10);
    circle(3, 3, -43, -8);
    circle(4, 4, -38, -9);
    circle(3, 3, -34, -10);
    circle(4, 4, -29, -8);
    circle(3, 3, -26, -8);
    circle(4, 4, -21, -9);
    circle(4, 4, -17, -8);
    circle(3, 3, -14, -9);
    circle(3, 3, -11, -10);
    circle(4, 4, -7, -9);
    circle(3, 3, -4, -7);
    circle(4, 4, 0, -9);

    circle(4, 4, 48, -10);
    circle(3, 3, 43, -8);
    circle(4, 4, 38, -9);
    circle(3, 3, 34, -10);
    circle(4, 4, 29, -8);
    circle(3, 3, 26, -8);
    circle(4, 4, 21, -9);
    circle(4, 4, 17, -8);
    circle(3, 3, 14, -9);
    circle(3, 3, 11, -10);
    circle(4, 4, 7, -9);
    circle(3, 3, 4, -7);

    glColor3ub(200, 203, 73);
    glRectf(-50,-18, 50, -10);

    moving();
    metroMove();

    //Path
    glColor3f(0.9, 1, 1);
    glRectf(-50,10,50, 11);

    glRectf(-48,8,-47.5, 11);
    glRectf(-41,8,-40.5, 11);
    glRectf(-31,8,-30.5, 11);
    glRectf(-21,8,-20.5, 11);
    glRectf(-11,8,-10.5, 11);
    glRectf(-1,8,-0.5, 11);
    glRectf(9.5,8,10, 11);
    glRectf(19.5,8,20, 11);
    glRectf(29.5,8,30, 11);
    glRectf(39.5,8,40, 11);
    glRectf(47.5,8,48, 11);

    glColor3f(0.7,0.7,0.8);
    glRectf(-50,0,50, 8);

    glColor3f(1, 1, 1);
    glRectf(-50,1,50, 1.5);


    //Pilar
    glColor3f(0.1,0.2,0.4);
    glRectf(-50,-25,-42, 0);

    glColor3f(0.1,0.3,0.4);
    glRectf(-42,-25,-40, 0);

    glColor3f(1,1,1);
    glRectf(-50,-6,-40, -5);

    glColor3f(0.1,0.2,0.4);
    glRectf(50,-25,42, 0);

    glColor3f(0.1,0.3,0.4);
    glRectf(42,-25,40, 0);

    glColor3f(1,1,1);
    glRectf(50,-6,40, -5);

    //Road upper side
    glColor3ub(173, 190, 88);
    glRectf(-50,-25, 50, -18);

    glColor3ub(91, 109, 25);
    circle(4, 4, -48, -20);
    circle(3, 3, -43, -18);
    circle(4, 4, -38, -19);
    circle(3, 3, -34, -20);
    circle(4, 4, -29, -18);
    circle(3, 3, -26, -18);
    circle(4, 4, -21, -19);
    circle(4, 4, -17, -18);
    circle(3, 3, -14, -19);
    circle(3, 3, -11, -20);
    circle(4, 4, -7, -19);
    circle(3, 3, -4, -17);
    circle(4, 4, 0, -19);

    circle(4, 4, 48, -20);
    circle(3, 3, 43, -18);
    circle(4, 4, 38, -19);
    circle(3, 3, 34, -20);
    circle(4, 4, 29, -18);
    circle(3, 3, 26, -18);
    circle(4, 4, 21, -19);
    circle(4, 4, 17, -18);
    circle(3, 3, 14, -19);
    circle(3, 3, 11, -20);
    circle(4, 4, 7, -19);
    circle(3, 3, 4, -17);

    //Road
    glColor3ub(83, 84, 80 );
    glRectf(-50,-40,50, -25);

    glColor3ub(242, 243, 243);
    glRectf(-50,-33.5,-45, -32);
    glRectf(-40,-33.5,-35, -32);
    glRectf(-30,-33.5,-25, -32);
    glRectf(-20,-33.5,-15, -32);
    glRectf(-10,-33.5,-5, -32);
    glRectf(0,-33.5,5, -32);
    glRectf(10,-33.5,15, -32);
    glRectf(20,-33.5,25, -32);
    glRectf(30,-33.5,35, -32);
    glRectf(40,-33.5,45, -32);


    reverseCar();
    reverseCarMove();

    carMove();
    cMove();

    glutPostRedisplay();
    glutSwapBuffers();

    glFlush();
}


int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1050, 800);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Final Project");
    init();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
    return 0;
}
