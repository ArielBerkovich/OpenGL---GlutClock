#include "Displayer.h"
#include "Clock2D.h"
#include <stdio.h>




#define LEFT -4.0
#define RIGHT 4.0
#define BOTTOM -4.0
#define TOP 4.0

//-----------------------------------------------------------------------
void drawingCB() // use as a callback to display
{
	int n;
	GLenum er;


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.2f, 0.8f, 0.69f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	drawClock(17, 25, -2, -2);
	drawClock(18, 35, 2, -2);
	drawClock(15, 5, 2, 2);
	drawClock(16, 15, -2, 2);

	glFlush();

	er = glGetError();  //get errors. 0 for no error, find the error codes in: https://www.opengl.org/wiki/OpenGL_Error
	if (er) printf("error: %d\n", er);
}
//---------------------------------------------------------------
void reshapeFuncCB(int width, int height)
{
	//vars:
	float AR;
	double left = LEFT, right = RIGHT, bottom = BOTTOM, top = TOP;

	//init:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);

	//reshaping:
	AR = (float)width / height;
	if (AR >= 1) { left *= AR; right *= AR; }
	else { top /= AR; bottom /= AR; }
	gluOrtho2D(left, right, bottom, top);
}
//-----------------------------------------------------------------
