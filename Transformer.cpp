void trans()
{
    if (yll<130)
    {
        yll+=1;
        ylu+=1;
        yln+=1;
    }
    else if(yrh>240)
    {
        yrh-=1;
        yre-=1;
        yrf-=1;
        ye-=1;
        yrnc-=1;
    }
    else if(yll<220)
    {
        yll+=1;
    }
    else if(rlh<=560)
    {
        rlh+=1;
        rrh-=1;
        rla+=0.9;
        rra-=0.9;
    }
    else if(rxa<=90)
    {
        rxa+=1;
        tz-=2;
        ty+=1.2;
    }
    else
    {
        flag=1;
        rxa=0;
        sx=1.3;
        sy=0.5;
        sz=1;
    }
}

void vehicle()
{
    glTranslatef(ftx,fty,ftz);
    glScalef(fsx,fsy,fsz);

    if(vflag==1)
    {

        //Vehicle Hood
        glColor3f(1,0.639,0.102);
        glBegin(GL_QUADS);
        glVertex3i(vtx,35,200);
        glVertex3i(vtx+60,35,200);
        glVertex3i(vtx+60,90,200);
        glVertex3i(vtx,58,200);
        glEnd();

        //Front Wheel
        glColor3f(0.2,0.2,0.2);
        glTranslatef(540,wty,200);
        glScalef(1.7,1,0.2);
        glutSolidSphere(12.5,50,50);
        glScalef(1/1.7,1,1/0.2);
        glTranslatef(-540,-wty,-200);

        //Rear Wheel
        glColor3f(0.2,0.2,0.2);
        glTranslatef(655,wty,200);
        glScalef(1.7,1,0.2);
        glutSolidSphere(12.5,50,50);
        glScalef(1/1.7,1,1/0.2);
        glTranslatef(-655,-wty,-200);
    }

    glColor3f(0.2,0.2,0.7);
    glTranslatef(600,60,200);
    glScalef(sx,sy,sz);
        glRotatef(rya,0,1,0);
    glutSolidCube(120);
        glRotatef(-rya,0,1,0);
    glScalef(1/sx,1/sy,1/sz);
    glTranslatef(-600,-60,-200);


    glScalef(1/fsx,1/fsy,1/fsz);
    glTranslatef(-ftx,-fty,-ftz);
}

void calc()
{
    if(rya<=90)
    {
        rya+=1;
        sx+=0.002;
        sz-=0.01;
    }
    else if(fsx<=2.5)
    {
        fsx+=0.05;
        fsy+=0.05;
        fsz+=0.05;
        ftx-=20;
        fty-=10;
    }
    else
    {
        vflag=1;
    }
    if(vflag==1&&vtx>=465)
    {
        vtx-=1;
    }
    else if(vtx<465&&wty>=30)
    {
        wty-=0.5;
    }
    else if(wty<30)
    {
        allover=1;
    }
    if(allover==1)
    {
        if(i<=540)
        {
            ftx-=5;
            i++;
        }
        else if(i>540)
            fflag=1;
    }
}

void display()
{
    char pr[20]="OpenGL Project:";
    char name[20]="By Mahesh Bhandari";
    char title[15]="TRANSFORMERS";
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    background();

    if(tpos>550)
    {
        tpos-=0.5;
    }
    glColor3f(0,0,0.502);
    glRasterPos2f(1000,tpos);
    for(int j=0;j<strlen(pr);j++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, pr[j]);
    }
        glRasterPos2f(1150,tpos-24);
    for(int j=0;j<strlen(name);j++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[j]);
    }
    glRasterPos2f(460,tpos-50);
    for(int j=0;j<strlen(title);j++)
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[j]);
    }

    if(flag==0)
    {
        trans();
        robot();
    }
    else if(flag==1)
    {
        calc();
        vehicle();
    }

    //Draw Trees alongside the road
    for(int c=-400;c<=1500;c+=300)
    {
        //Trees on Left Side
        glTranslatef(c,110,0);
        tree();
        glTranslatef(-c,-110,0);
    }
    glFlush();
    glutSwapBuffers();
}

void changeSize(int w, int h)
{
	if(h == 0)
		h = 1;
	float ratio = 1.0* w / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(78,ratio,1,500);
	glMatrixMode(GL_MODELVIEW);
}

void Timer(int value)
{
    if(fflag==0)
    {
        glutTimerFunc(20,Timer,0);
        glutPostRedisplay();
    }

}

void myinit()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glOrtho(0,1200,0,640,0,500);

    glutTimerFunc(2000,Timer,0);
}

int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1200,640);

    glutCreateWindow("OpenGL Project: Transformers");
    glutReshapeFunc(changeSize);
    glutDisplayFunc(display);

    myinit();
    trans();
    glutMainLoop();
}
