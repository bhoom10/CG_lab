#include <stdio.h>
#include <GL/glut.h>
/*#define maxx 25
#define maxy 25
#define dx 15
#define dy 10
*/
float x[50], y[50];
int i,j,x0,y0;
int maxx, maxy,dx,dy;

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0,0.0,1.0);
//x[0]=0;
//y[0]=0;
for(i=1; i<=maxx; i++)
{
    x[i]=x[i-1] + dx;
    }
for(i=1; i<=maxy; i++)
{
        y[i]=y[i-1] + dy;
    }

for(i=0; i<=maxx-1; i++)
{
    /*glBegin(GL_POLYGON);
    glVertex2f(20,20);
    glVertex2f(40,20);
    glVertex2f(40,40);
    glVertex2f(20,40);
    glEnd();
    glFlush();
*/

    for(j=0; j<=maxy-1; j++)
    {
    glBegin(GL_LINE_LOOP);
    glVertex2f(x[i],y[j]);
    glVertex2f(x[i+1],y[j]);
    glVertex2f(x[i+1],y[j+1]);
    glVertex2f(x[i],y[j+1]);
    glEnd();
    glFlush();
    }}


}

void myinit()
{
glClearColor(0.0,1.0,1.0,1.0);
gluOrtho2D(0,499.0,0,499.0);
}

int main(int argc, char** argv)
{
printf("Enter the max value of x and y\n");
scanf("%d%d", &maxx, &maxy);
printf("Enter the value of dx and dy\n");
scanf("%d%d", &dx, &dy);
printf("Enter the value of x0 and y0\n");
scanf("%d%d", &x0, &y0);
x[0]=x0;
y[0]=y0;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("blue mesh");
myinit();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
