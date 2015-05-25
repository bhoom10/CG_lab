#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
GLfloat h,k;
void draw_pixel(GLfloat x, GLfloat y)
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}
void plotpixel(GLfloat h,GLfloat k,GLfloat x,GLfloat y)
{
    draw_pixel(x+h,y+k);
    draw_pixel(-x+h,y+k);
    draw_pixel(x+h,-y+k);
    draw_pixel(-x+h,-y+k);
    draw_pixel(y+h,x+k);
    draw_pixel(-y+h,x+k);
    draw_pixel(y+h,-x+k);
    draw_pixel(-y+h,-x+k);
}
void draw_circle(GLfloat h,GLfloat k,GLfloat r)
{
    GLfloat x = 0,y = r,d = 1-r;
    while(y>x)
    {
        plotpixel(h,k,x,y);
        if(d<0)
        {
            d=2*x+3;
        }
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixel(h,k,x,y);
}
void draw_cylinder()
{
    GLfloat x=100,y=100,r=50,n=50,i;
    for(i=0;i<n;i+=3)
    draw_circle(x,y+i,r);
}
void para(int x1,int y1,int x2,int y2)
{
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);

    glEnd();
}
void p_draw()
{
    GLfloat x1=200,y1=300,x2=300,y2=200;
    int i;
    for(i=0;i<40;i+=2)
        para(x1+i,y1+i,x2+i,y2+i);
}
void myinit()
{
    glClearColor(0.0,1.0,1.0,1.0);
    glPointSize(2.0);
    gluOrtho2D(0.0,499.0,0.0,499.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw_cylinder();
    p_draw();
    glFlush();
}
int main(int argc,char **argv)
{
    printf("Enter the value of the centre of the circle");
    scanf("%d%d",&h,&k);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("cylinder");
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    return 0;
}
