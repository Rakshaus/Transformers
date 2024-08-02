#include<GL/glut.h>
#include<string.h>

float yll=36,ylu=130,yln=80,yrh=320,ye=328,yre=325,yrf=348,yrnc=295,rlh=492,rrh=708,rla=495,rra=705,wty=45;
float sx=1,sy=1,sz=1,fsx=1,fsy=1,fsz=1,tx=0,ty=0,tz=0;
int tpos=640,ftx=0,fty=0,ftz=0,rxa=0,rya=0,flag=0,vflag=0,fflag=0,vtx=520,allover=0,i=0;

void tree()
{
    //Trunk
    glColor3f(0.325,0.208,0.039);
    glScalef(1.5,0.3,0.3);
    glTranslatef(0,-10,0);
    glutSolidSphere(10,18,20);
    glTranslatef(0,10,0);
    glScalef(1/1.5,1/0.3,1/0.3);
    glutSolidCube(12);

    //Tree
    glColor3f(0,1,0);
    for(int c=-5;c<=10;c+=5)
    {
        glTranslatef(c,25,0);
        glScalef(1,0.8,1);
        glutSolidSphere(20,20,20);
        glScalef(1,1/0.8,1);
        glTranslatef(-c,-25,0);
    }
}

void clouds()
{
    //Clouds
    glColor3f(0.8,0.8,1);
    glTranslatef(0,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(0,0,0);

    glTranslatef(0,0,40);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(0,0,-40);

    glTranslatef(0,0,-40);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(0,0,40);

    glTranslatef(40,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(-40,0,0);

    glTranslatef(-40,0,0);
    glScalef(1.6,1,1);
    glutSolidSphere(30,25,25);
    glScalef(1/1.6,1,1);
    glTranslatef(40,0,0);
}

void background()
{
    //Floor
    glBegin(GL_QUADS);
    glColor3f(0.6,0.4,0.2);
    glVertex3i(-2400,0,0);
    glVertex3i(3600,0,0);
    glVertex3i(3600,0,500);
    glVertex3i(-2400,0,500);

    glColor3f(0.4,0.4,0.4);
    glVertex3i(-1200,120,0);
    glVertex3i(2480,120,0);
    glVertex3i(2480,160,0);
    glVertex3i(-1200,160,0);

    //Sky
    glColor3f(0.4,0.6,0.8);
    glVertex3i(-2400,0,500);
    glVertex3i(3600,0,500);
    glVertex3i(3600,1200,500);
    glVertex3i(-2400,1200,500);

    glEnd();

    for(int c=-400;c<=1500;c+=300)
    {
        //Trees on Right Side
        glTranslatef(c,170,0);
        tree();
        glTranslatef(-c,-170,0);
    }

    glTranslatef(200,560,300);
    clouds();
    glTranslatef(-200,-560,-300);

    glTranslatef(0,560,10);
    clouds();
    glTranslatef(0,-560,-10);

    glTranslatef(1200,560,50);
    clouds();
    glTranslatef(-1200,-560,-50);

    glTranslatef(600,560,400);
    clouds();
    glTranslatef(-600,-560,-400);

    glTranslatef(550,560,50);
    clouds();
    glTranslatef(-550,-560,-50);

    glTranslatef(-1000,560,500);
    clouds();
    glTranslatef(1000,-560,-500);

    glTranslatef(4000,560,1200);
    clouds();
    glTranslatef(-4000,-560,-1200);

    glTranslatef(3750,560,1200);
    clouds();
    glTranslatef(-3750,-560,-1200);

    glTranslatef(1100,480,300);
    clouds();
    glTranslatef(-1100,-480,-300);

    glTranslatef(-2800,560,800);
    clouds();
    glTranslatef(2800,-560,-800);
}








