#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#define outcode int

double xmax=100,ymax=100,xmin=50,ymin=50;
double xvmax=300,yvmax=300,xvmin=200,yvmin=200;

const int TOP=4;
const int BOTTOM=1;
const int RIGHT=8;
const int LEFT=2;

outcode computeoutcode(double x,double y)
{
    outcode code=0;
    if(y>ymax)
    code|=TOP;
    if(y<ymin)
    code|=BOTTOM;
    if(x>xmax)
    code|=RIGHT;
    if(x<xmin)
    code|=LEFT;
    return code;
}

void  cohen(double x0,double y0,double x1,double y1)
{
    outcode  outcode0,outcode1,outcodeout;
    int accept=0,done=0;
    outcode0=computeoutcode(x0,y0);
    outcode1=computeoutcode(x1,y1);

    do{
        if(!(outcode0|outcode1))
        {
            accept=1;
            done=1;
        }
        else if(outcode0  & outcode1)
            done=1;
        else
        {
            double x,y;
            outcodeout=outcode0?outcode0:outcode1;
            if(outcodeout & TOP)
            {
                x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
                y=ymax;
            }
            else if(outcodeout & BOTTOM)
            {
                x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
                y=ymin;
            }
            else if(outcodeout & RIGHT)
            {
                y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
                x=xmax;
            }
             else
            {
                y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
                x=xmin;
            }
            if(outcodeout==outcode0)
            {
                x0=x;
                y0=y;
                outcode0=computeoutcode(x0,y0);
            }
            else
            {
                x1=x;
                y1=y;
                outcode1=computeoutcode(x1,y1);
            }
        }
    }while(!done);


    if(accept)
    {
        double sx=(xvmax-xvmin)/(xmax-xmin);
        double sy=(yvmax-yvmin)/(ymax-ymin);
        double vx0=xvmin+(x0-xmin)*sx;
        double vy0=yvmin+(y0-ymin)*sy;
        double vx1=xvmin+(x1-xmin)*sx;
        double vy1=yvmin+(y1-ymin)*sy;
        glColor3f(1.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);
            glVertex2f(xvmin,yvmin);
            glVertex2f(xvmax,yvmin);
            glVertex2f(xvmax,yvmax);
            glVertex2f(xvmin,yvmax);
        glEnd();
        glColor3f(0.0,0.0,1.0);
        glBegin(GL_LINES);
            glVertex2d(vx0,vy0);
            glVertex2d(vx1,vy1);
        glEnd();
    }
}

void display()
{
    int n,i,x[10],y[10];
    printf("enter the no of lines\n");
    scanf("%d",&n);
    printf("enter the coordinates\n");
    for(i=0;i<(2*n);i++)
        scanf("%d%d",&x[i],&y[i]);
    glClear(GL_COLOR_BUFFER_BIT);
     for(i=0;i<(2*n);i=i+2)
     {
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2d(x[i],y[i]);
    glVertex2d(x[i+1],y[i+1]);
    glEnd();
    }
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin,ymin);
        glVertex2f(xmax,ymin);
        glVertex2f(xmax,ymax);
        glVertex2f(xmin,ymax);
    glEnd();
    for(i=0;i<(2*n);i=i+2)
        cohen(x[i],y[i],x[i+1],y[i+1]);
    glFlush();
}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,500.0,0.0,500.0);
}

int main(int argc,char**argv)
{

   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(0,0);
   glutCreateWindow("Cohen suderland  clipping");
   glutDisplayFunc(display);
   init();
   glutMainLoop();
   return 0;
}
