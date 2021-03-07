#ifndef MYDRAWING_H_INCLUDED
#define MYDRAWING_H_INCLUDED




static GLfloat spin = 0.0;
static float	x	=  -20.0;
static float	tp	=  0;
static float	tp2	=  0;
static float	tp3	=  0;
int serial=0;

GLfloat	tx	=  10.0;
GLfloat	ty	=  10.0;
GLfloat	tx1	=  0.0;
GLfloat	ty1	=  0.0;

static void Timer(int value)
{
    serial += 1;

    glutPostRedisplay();
    // 100 milliseconds
    glutTimerFunc(1000, Timer, 0);
}

void delay(){
    for(int i=0;i<50000000;i++);
}



void circle( GLfloat rx, GLfloat ry, GLfloat x, GLfloat y)
{
    int i = 0;
float angle;
GLfloat PI = 2.0f * 3.1416;
glBegin(GL_TRIANGLE_FAN);
glVertex2f(x,y);

for(i=0; i<100; i++)
{
    angle = 2 * PI * i / 100;
    glVertex2f(x+(cos(angle)*rx), y+(sin(angle)*ry));
}

glEnd();
}

void MyRect(/* GLfloat aa, GLfloat bb, GLfloat cc, GLfloat dd */)
{

glBegin(GL_QUADS);

glVertex2d(-12.0, 8.0);
glVertex2d(-12.0, -6.0);
glVertex2d(10.0, -6.0);
glVertex2d(10.0, 8.0);

glEnd();
}

void triFront(/* GLfloat aa, GLfloat bb, GLfloat cc, GLfloat dd */)
{

glBegin(GL_TRIANGLES);

glVertex2d(-12.0, 3.0);
glVertex2d(-9.0, 3.0);
glVertex2d(-9, 6.0);

glEnd();
}


void cloud(int x, int y)
{
     glColor3f (1, 1,1);
     circle(4,5,x-3, y);
     circle(3,6,x, y-1);
     circle(3,6,x+2, y);
     circle(3,5,x-2, y+2);
     circle(3,5,x-3, y);
     circle(3,5,x+2, y+2);
     circle(3,5,x+3, y);
     circle(2,7,x, y+1);

}

   void cloud_move_right(){
    tp3=tp3+0.3;
    if(tp3>0)
        tp3 = -35;
    glutPostRedisplay();
}
    //river start
/*
    void river(int x, int y)
    {
        glColor3f(0.000, 0.749, 1.000);
                glBegin(GL_QUADS);
                    glVertex2d(x+2, y+12);
                    glVertex2d(x, y);
                    glVertex2d(x+8, y);
                    glVertex2d(x+9, y+12);
                glEnd();

                circle(2,5,x+3,y+8);

                 glBegin(GL_QUADS);
                    glVertex2d(x+10, y+20);
                    glVertex2d(x+2, y+12);
                    glVertex2d(x+9, y+12);
                    glVertex2d(x+14, y+20);
                glEnd();


                 glBegin(GL_QUADS);
                    glVertex2d(x+17, y+23);
                    glVertex2d(x+10, y+20);
                    glVertex2d(x+14, y+20);
                    glVertex2d(x+20, y+23);
                glEnd();


    }
*/
    //river end


    //railway start

        void railLine( int y)
            {
                glColor3f(0.871, 0.722, 0.529);
                int y1 = y - 5;
                glRectf(-35,y1,35,y);


                glColor3f(0.0, 0.0, 0.0);
                glRectf(-35,y-1,35,y);
                glRectf(-35,y1-1,35,y1);

                for(int i = -35; i <70; i++)
                {
                    glColor3f(0.0, 0.0, 0.0);
                    glBegin(GL_LINES);
                        glVertex2d(i+1, y);
                        glVertex2d(i, y1);
                    glEnd();
                }

                glColor3f(0.645, 0.371, 0.075);
                glRectf(-35,y1-5,35,y1-1);

                 float j = -39;
                for(int i = 0; i <380; i++)
                {
                    glColor3f(0.0, 0.0, 0.0);
                    glBegin(GL_LINES);
                        glVertex2d(j+0.7, y1-1);
                        glVertex2d(j, y1-5);
                    glEnd();
                    j = j + 0.2;
                }

            }

            void downSoil(int y1)
            {

                glColor3f(0.545, 0.271, 0.075);
                glRectf(-35,y1-5,35,y1-1);

                 float j = -39;
                for(int i = 0; i <380; i++)
                {
                    glColor3f(0.0, 0.0, 0.0);
                    glBegin(GL_LINES);
                        glVertex2d(j+0.3, y1-1);
                        glVertex2d(j, y1-5);
                    glEnd();
                    j = j + 0.2;
                }
            }



	//railway end

	    //Train start

	    void train_move_left(){
    //if(x>=0|| x<0)
    tp=tp+1;
    if(tp>70)
        tp = -70;

        glutPostRedisplay();
}

    void train_move_right(){
    //if(x>=0|| x<0)
    tp2=tp2-1;
    if(tp2<-90)
        tp2 = +90;

        glutPostRedisplay();
}

        void train( int y, int x, int num_of_bogie)
            {
                  train_move_left();

                glPushMatrix();
                glTranslatef(tp,0,0);

                int y1 = y - 7;
                int y2 = y+4;
                int y3 = y-2;

                for(int i = 0; i < num_of_bogie; i++)
                {

                int x1 = x + 8;
                int x2 = x + 1;
                int x3 = x1 + 1;
                int wx = x +1;
                int wx2 = x1 -1;

                //other wheel
                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wx2+1,y3-1);

                //side view
                glColor3f(0.545, 0.000, 0.000);
                glRectf(x,y1,x1,y);

                //roof
                glColor3f(1.000, 0.627, 0.478);
                glBegin(GL_QUADS);
                    glVertex2d(x2, y2);
                    glVertex2d(x, y);
                    glVertex2d(x1, y);
                    glVertex2d(x3, y2);
                glEnd();


                //front or back
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(x1, y);
                    glVertex2d(x1, y1);
                    glVertex2d(x3, y3);
                    glVertex2d(x3, y2);
                glEnd();


                //wheels
                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wx,y1);
                circle(1,2,wx2,y1);

                 //connection
                //glColor3f(0.0, 1.0, 0.0);
                //lRectf(x + 9, y - 5, x+23, y-2);

                x = x+9;
                }
                glPopMatrix();
            }



        void train2( int y, int x, int num_of_bogie)
            {
                  train_move_right();

                glPushMatrix();
               glTranslatef(tp2,0,0);

                int y1 = y - 7;
                int y2 = y+4;
                int y3 = y-2;

                for(int i = 0; i < num_of_bogie; i++)
                {

                int x1 = x + 8;
                int x2 = x + 1;
                int x3 = x1 + 1;
                int wx = x +1;
                int wx2 = x1 -1;

                //other wheel
                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wx2+1,y3-1);

                //side view
                glColor3f(0.545, 0.000, 0.000);
                glRectf(x,y1,x1,y);

                //roof
                glColor3f(1.000, 0.627, 0.478);
                glBegin(GL_QUADS);
                    glVertex2d(x2, y2);
                    glVertex2d(x, y);
                    glVertex2d(x1, y);
                    glVertex2d(x3, y2);
                glEnd();


                //front or back
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(x1, y);
                    glVertex2d(x1, y1);
                    glVertex2d(x3, y3);
                    glVertex2d(x3, y2);
                glEnd();


                //wheels
                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wx,y1);
                circle(1,2,wx2,y1);

                 //connection
                //glColor3f(0.0, 1.0, 0.0);
                //lRectf(x + 9, y - 5, x+23, y-2);

                x = x+9;
                }
                glPopMatrix();
            }
	//Train end

	//bogie  start

	void train_engine1(int b, int x, int c)
	{
	     train_move_left();
                glPushMatrix();
                glTranslatef(tp,0,0);


                int a = x + (c*9);
                int b1 = b - 5;
                int a1 = a + 12;
                int a2 = a + 1;
                int a3 = a1 + 1;
                int wa = a +1;
                int wa2 = a1 -1;
                int b2 = b-1;


                //other wheel
                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wa2+1,b2);

                //side view
                glColor3f(0.545, 0.000, 0.000);
                glRectf(a,b1,a1,b);

                //roof
                glColor3f(1.000, 0.627, 0.478);
                glBegin(GL_QUADS);
                    glVertex2d(a2, b+4);
                    glVertex2d(a, b);
                    glVertex2d(a1, b);
                    glVertex2d(a3, b+4);
                glEnd();

                //front or back
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(a1, b);
                    glVertex2d(a1, b1);
                    glVertex2d(a3, b);
                    glVertex2d(a3, b+4);
                glEnd();

                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wa,b1);
                circle(1,2,wa2,b1);

                                //top

                 //side view
                 int a4 = a + 6;
                 int a5 = a4 + 1;
                 int b4 = b+10;
                 int b3 = b4 + 4;
                glColor3f(0.545, 0.000, 0.000);
                glRectf(a,b,a4,b4);

                //window
                glColor3f(1.000, 0.627, 0.478);
                glRectf(a+2,b+2,a4-2,b4-2);
                glColor3f(1.000, 0.271, 0.00);
                glRectf(a+2,b+2,a4-2,b4-5);

                //roof
                glColor3f(1.000, 0.627, 0.478);
                glBegin(GL_QUADS);
                    glVertex2d(a2, b3);
                    glVertex2d(a, b4);
                    glVertex2d(a4, b4);
                    glVertex2d(a5, b3);
                glEnd();

                //front or back
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(a4, b4);
                    glVertex2d(a4, b);
                    glVertex2d(a5, b +4);
                    glVertex2d(a5, b+14);
                glEnd();

                glPopMatrix();

	}



	void train_engine2(int b, int x, int c)
	{
	     train_move_right();
                glPushMatrix();
                glTranslatef(tp2,0,0);


                int a = x - 13;
                int b1 = b - 5;
                int a1 = a + 12;
                int a2 = a + 1;
                int a3 = a1 + 1;
                int wa = a +1;
                int wa2 = a1 -1;
                int b2 = b-1;

                int a14 = a + 6;
                int a15 = a + 7;
                int a16 = a + 12;
                int a17 = a + 12;


                //other wheel
                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wa2+1,b2);

                //side view
                glColor3f(0.545, 0.000, 0.000);
                glRectf(a,b1,a1,b);

                //roof
                glColor3f(1.000, 0.627, 0.478);
                glBegin(GL_QUADS);
                    glVertex2d(a2, b+4);
                    glVertex2d(a, b);
                    glVertex2d(a1, b);
                    glVertex2d(a3, b+4);
                glEnd();

                //front or back
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(a1, b);
                    glVertex2d(a1, b1);
                    glVertex2d(a3, b);
                    glVertex2d(a3, b+4);
                glEnd();

                glColor3f(0.0, 0.0, 0.0);
                circle(1,2,wa,b1);
                circle(1,2,wa2,b1);

                                //top

                 //side view
                 int a4 = a + 6;
                 int a5 = a4 + 1;
                 int b4 = b+10;
                 int b3 = b4 + 4;
                glColor3f(0.545, 0.000, 0.000);
                glRectf(a+6,b,a1,b4);

                //window
                glColor3f(1.000, 0.627, 0.478);
                glRectf(a+8,b+2,a+10,b4-2);
                glColor3f(1.000, 0.271, 0.00);
                glRectf(a+8,b+2,a+10,b4-5);

                //roof
                glColor3f(1.000, 0.627, 0.478);
                glBegin(GL_QUADS);
                    glVertex2d(a15, b3);
                    glVertex2d(a14, b4);
                    glVertex2d(a1, b4);
                    glVertex2d(a3, b3);
                glEnd();

                //front or back
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(a1, b4);
                    glVertex2d(a1, b);
                    glVertex2d(a3, b +4);
                    glVertex2d(a3, b+14);
                glEnd();

                glPopMatrix();

	}
	//bogie end


void ree2(int x, int y)
{
    int y2;
    int v = x%2;
    if(v==0)
    {
       y2 = y;
    }
    else{
        y2 = y - 1;
    }

    glColor3f(0.722, 0.525, 0.043);

        glBegin(GL_TRIANGLES);

glVertex2d(x, y2+1);
glVertex2d(x-1, y2-4);
glVertex2d(x+1, y2-4);

glEnd();

    glRectf(x-0.1,y2-6,x+0.1,y2);

}


void sunflower(int x, int y)
{
    int y2 = y;
    int v = x%2;


    if(v==0)
    {
       y2 = y;
    }
    else{
        y2 = y - 1;
    }


    glColor3f(0.502, 0.000, 0.000);
    glRectf(x-0.1,y2-3,x+0.05,y2);
    glColor3f(1.000, 1.000, 0.000);
    circle(0.5,1,x, y2);
    glColor3f(1, 0.000, 0.000);
    circle(0.3,0.3,x, y2);

}



void stationHouse(int x, int y)
{


    glColor3f(0.502, 0.000, 0.502);
    glBegin(GL_QUADS);
        glVertex2d(x-8, y-4);
        glVertex2d(x-9, y-8);
        glVertex2d(x+4, y-8);
        glVertex2d(x+5, y-4);
    glEnd();

    glColor3f(0.000, 1.000, 1.000);
    glRectf(x-9,y-18,x+4,y-8);

    glColor3f(0.098, 0.098, 0.439);
    glRectf(x-4,y-18,x,y-9);
    glRectf(x-8,y-14,x-5,y-10);
    glRectf(x+2,y-14,x+5,y-10);

    /*

    glColor3f(1, 1.000, 1.000);
    glBegin(GL_TRIANGLES);
        glVertex2d(x, y);
        glVertex2d(x-4, y-8);
        glVertex2d(x+4, y-8);
    glEnd();

    glColor3f(0.502, 0.000, 0.502);
    glBegin(GL_TRIANGLES);
    glVertex2d(x, y-0.3);
    glVertex2d(x-3.7, y-7.7);
    glVertex2d(x+3.7, y-7.7);
    glEnd();


    glColor3f(1, 1.000, 1.000);
    glBegin(GL_TRIANGLES);
        glVertex2d(x-7, y-2);
        glVertex2d(x-10, y-10);
        glVertex2d(x-4, y-10);
    glEnd();

    glColor3f(0.502, 0.000, 0.502);
    glBegin(GL_TRIANGLES);
        glVertex2d(x-7, y-2.7);
        glVertex2d(x-9.7, y-9.7);
        glVertex2d(x-4.3, y-9.7);
    glEnd();
    */

    //platform
     //platform side view
                glColor3f(0.804, 0.361, 0.361);
                glRectf(x-15,y-24,x+4,y-22);

                //flor
                glColor3f(1, 1, 1);
                glBegin(GL_QUADS);
                    glVertex2d(x-14, y-18);
                    glVertex2d(x-15, y-22);
                    glVertex2d(x+4, y-22);
                    glVertex2d(x+5, y-18);
                glEnd();

                //platform right side
                glColor3f(0.804, 0.361, 0.361);
                glBegin(GL_QUADS);
                    glVertex2d(x+4, y-22);
                    glVertex2d(x+4, y-24);
                    glVertex2d(x+5, y-20);
                    glVertex2d(x+5, y-18);
                glEnd();

            //platform end
}

            void windMill(int x, int y)
            {
                glColor3f(1, 1, 1);
                glRectf(x-0.5,y-20,x+0.5,y);

                //glColor3f(0.545, 0.271, 0.075);
                glBegin(GL_QUADS);
                    glVertex2d(x-0.6, y-20);
                    glVertex2d(x-1, y-21.5);
                    glVertex2d(x+1, y-21.5);
                    glVertex2d(x+0.6, y-20);
                glEnd();

                glPushMatrix();
                glTranslatef(x,y,0.0);
                glRotatef(spin, 0.0, 0.0, 1.0);
                glTranslatef(-x,-y,0.0);

                glColor3f(0.647, 0.165, 0.165);
                glBegin(GL_QUADS);
                    glVertex2d(x, y);
                    glVertex2d(x+1, y+6);
                    glVertex2d(x, y+9);
                    glVertex2d(x-1, y+6);
                glEnd();



                glBegin(GL_QUADS);
                    glVertex2d(x, y);
                    glVertex2d(x+1, y-6);
                    glVertex2d(x, y-9);
                    glVertex2d(x-1, y-6);
                glEnd();


                glBegin(GL_QUADS);
                    glVertex2d(x, y);
                    glVertex2d(x+6, y-1);
                    glVertex2d(x+9, y);
                    glVertex2d(x+6, y+1);
                glEnd();

                glBegin(GL_QUADS);
                    glVertex2d(x, y);
                    glVertex2d(x-6, y-1);
                    glVertex2d(x-9, y);
                    glVertex2d(x-6, y+1);
                glEnd();


                circle(2,2,x,y);

                glPopMatrix();
                //circle(2,2,x,y);
            }

void spinDisplay(void)
{
   spin = spin - 10;
   if (spin > 360.0)
      spin = spin - 360.0;
   glutPostRedisplay();
}


#endif // MYDRAWING_H_INCLUDED
