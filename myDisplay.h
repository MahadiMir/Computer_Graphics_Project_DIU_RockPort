#ifndef MYDISPLAY_H_INCLUDED
#define MYDISPLAY_H_INCLUDED


void display(void)
{

    delay();
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

        //sun
     glColor3f(1.000, 1.000, 0.000);
     circle(3,5,28,28);

    //clouds
    glPushMatrix();
    glTranslatef(tp3,0,0);
    cloud(-33,26);
    cloud(-13,27);
    cloud(9,32);
    glPopMatrix();




    cloud_move_right();
    //background hills

     glColor3f(0.000, 0.392, 0.000);
     circle(16,20, -34, -2);
     circle(13,24, -24, 0);
     circle(17,23, -0, -2);
     circle(16,23, 24, -2);
     circle(12,17, 34, -2);



    //field start
    glColor3f(0.180, 0.545, 0.341);
	glRectf(-35,-35,35,12);
	//field end

	//small tree fench start

	//small tree fench end

	//flower fild start

    for(int i =-45; i<100; i++)
    {
        sunflower(i, 10);
	}
	for(int i =-45; i<100; i++)
    {
        sunflower(i+2, 7);
	}

	for(int i =-45; i<100; i++)
    {
        sunflower(i, 4);
	}

	for(int i =-45; i<100; i++)
    {
        sunflower(i, 1);
	}

	for(int i =-45; i<100; i++)
    {
        sunflower(i, -2);
	}

	for(int i =-45; i<100; i++)
    {
        sunflower(i+2, -5);
	}

	for(int i =-45; i<100; i++)
    {
        sunflower(i, -8);
	}

	windMill(-25,20);

	windMill(-15,10);

	windMill(-2,20);

	windMill(10,10);

	windMill(20,20);

	spinDisplay();

   // river(-10, -12);
	//flower fild end

	//station house start

    stationHouse(32,12);
	//station house end

       // lineside(-39,-18, 35);
        //lineside(3,-18, 35);
        railLine(-12);
        train(-9, -23, 4);
        train_engine1(-11, -23, 4);


        railLine(-21);
        train2(-18, 23, 4);
        train_engine2(-20, 23, 4);

        downSoil(-30);


      /*  // river bottom part start
          glColor3f(0.000, 0.749, 1.000);
                glBegin(GL_QUADS);
                    glVertex2d(-10, -27);
                    glVertex2d(-11, -35);
                    glVertex2d(-1, -35);
                    glVertex2d(0, -27);
                glEnd();
*/

        // river bottom part end



    //circle(2,2,0,10);

	glFlush();
}



void init(void)
{
	glClearColor (0.529, 0.808, 0.980, 0.0);
	glOrtho(-35.0, 35.0, -35.0, 35.0, -35.0, 35.0);
}



#endif // MYDISPLAY_H_INCLUDED
