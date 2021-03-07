#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "mydrawing.h"
#include "myDisplay.h"
#include "movement.h"

//#define PI 3.1416







int main()
{
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1100, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Rockport City");
	init();
	glutDisplayFunc(display);//up,down,left......
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}

