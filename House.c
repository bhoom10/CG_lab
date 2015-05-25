#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<GL/glut.h>
//#define PI 3.1415
GLfloat house[3][9] ={{100,100,175,250,250,150,150,200,200},{100,300,400,300,100,100,150,150,100},{1,1,1,1,1,1,1,1,1}};
GLfloat rot_mat[3][3]={{0},{0},{0}};
GLfloat result[3][9]={{0},{0},{0}};
GLfloat h=100.0;
GLfloat k=100.0;
GLfloat theta,x;

void multiply()
{
    int i,j,l;
    for(i=0;i<3;i++)
        for(j=0;j<9;j++)
        {
                result[i][j]=0;
                for(l=0;l<3;l++)
                    result[i][j]=result[i][j]+(rot_mat[i][l]*house[l][j]);
        }

}
void rotate()
{
    GLfloat m,n;
    m=-h*(cos(theta)-1)+k*(sin(theta));
    n=-k*(cos(theta)-1)-h*(sin(theta));
    rot_mat[0][0]=cos(theta);
    rot_mat[0][1]=-sin(theta);
    rot_mat[0][2]=m;
    rot_mat[1][0]=sin(theta);
    rot_mat[1][1]=cos(theta);
    rot_mat[1][2]=n;
    rot_mat[2][0]=0;
    rot_mat[2][1]=0;
    rot_mat[2][2]=1;
    multiply();
}

void drawhouse()
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][0],house[1][0]);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][3],house[1][3]);
    glVertex2f(house[0][4],house[1][4]);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(house[0][5],house[1][5]);
    glVertex2f(house[0][6],house[1][6]);
    glVertex2f(house[0][7],house[1][7]);
    glVertex2f(house[0][8],house[1][8]);
    glEnd();

    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
  //  glVertex2f(house[0][0],house[1][0]);
    glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][2],house[1][2]);
    glVertex2f(house[0][3],house[1][3]);
    glEnd();


}


void drawrotatedhouse()
{
    glColor3f(1.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(result[0][0],result[1][0]);
    glVertex2f(result[0][1],result[1][1]);
    glVertex2f(result[0][3],result[1][3]);
    glVertex2f(result[0][4],result[1][4]);
    glEnd();

    glColor3f(1.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(result[0][5],result[1][5]);
    glVertex2f(result[0][6],result[1][6]);
    glVertex2f(result[0][7],result[1][7]);
    glVertex2f(result[0][8],result[1][8]);
    glEnd();

    glColor3f(1.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
  //  glVertex2f(house[0][0],house[1][0]);
    glVertex2f(result[0][1],result[1][1]);
    glVertex2f(result[0][2],result[1][2]);
    glVertex2f(result[0][3],result[1][3]);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawhouse();
    rotate();
    drawrotatedhouse();
    glFlush();
   /* int i;
    glClear(GL_COLOR3_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(5.0);
    if(id==2)
    if(id==3)
    glFlush();
*/

}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(1.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,499.0,0.0,499.0);
}

void main(int argc,char** argv)
{
    printf("Enter the rotation angle\n");
    scanf("%f",&x);
    theta=(22*x)/(7*180);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("rotate house");
    glutDisplayFunc(display);
     myinit();
    /*glutCreateMenu(mymenu);
    glutAddMenuEntry("Exit",1);
    glutAddMenuEntry("point",2);
    glutAddMenuEntry("line",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
*/
    glutMainLoop();

}
