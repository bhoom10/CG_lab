#include <stdio.h>
#include <stdlib.h>
#include<GL/glut.h>

double xmin=50,ymin=50, xmax=100, ymax=100, xvmin=200, yvmin=200, xvmax=300, yvmax=300, vx0, vx1, vy0, vy1, x0, y0, x1, y1;

int cliptest(double p, double q, double *t1, double *t2)
{
    double t=p/q;
    if(p<0.0)
    {
        if(t>*t1)
            *t1=t;
        if(t<*t2)
            return 0;
    }
    if(p>0.0)
    {
        if(t<*t2)
            *t2=t;
        if(t>*t1)
            return 0;
    }
    else
    {
        if(p==0.0)
        {
            if(q<0.0)
                return 0;
        }
    }
    return 1;
}

void liang()
{
double dx=x1-x0, dy= y1-y0, te=0, tl=1;
if(cliptest(-dx,x0-xmin, &te, &tl))
if(cliptest(dx,xmax-x0, &te, &tl))
if(cliptest(-dy,y0-ymin, &te, &tl))
if(cliptest(dy,ymax-y0, &te, &tl))
{
    if(tl<1.0)
    {
        x1= x0 + tl*dx;
        y1= y0 + tl*dy;
    }
    if(te<0.0)
    {
        x0= x0 + te*dx;
        y0= y0 + te*dy;
    }

    double sx = (xvmax-xvmin)/(xmax-xmin);
    double sy = (yvmax-yvmin)/(ymax-ymin);
    vx0 =  xvmin + (x0-xmin)*sx;
    vy0 =  yvmin + (y0-ymin)*sy;
    vx1 =  xvmin + (x1-xmin)*sx;
    vy1 =  yvmin + (y1-ymin)*sy;

    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(x0,y0);
    glVertex2f(x1,y1);
    glEnd();


    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin,ymin);
    glVertex2f(xmax,ymin);
    glVertex2f(xmax,ymax);
    glVertex2f(xmin,ymax);
    glEnd();
    glFlush();

    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xvmin,yvmin);
    glVertex2f(xvmax,yvmin);
    glVertex2f(xvmax,yvmax);
    glVertex2f(xvmin,yvmax);
    glEnd();
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINES);
    glVertex2f(vx0, vy0);
    glVertex2f(vx1, vy1);
    glEnd();
    glFlush();
}

void myinit()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{

   printf("Enter the line endpoints x0 y0 x1 y1: ");
   scanf("%lf%lf%lf%lf",&x0, &y0, &x1, &y1);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //glEnable(GL_DEPTH_TEST);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Liang Barsky clipping");
    myinit();
    liang();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
