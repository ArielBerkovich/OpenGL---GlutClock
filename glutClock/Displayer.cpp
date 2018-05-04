#include "Displayer.h"
#include "Clock2D.h"
#include <stdio.h>



extern int localHourAtInit;
extern int localMinAtInit;


int user_hour_movment = 0; 
int user_minute_movment = 0;


#define LEFT -4.0
#define RIGHT 4.0
#define BOTTOM -4.0
#define TOP 4.0

//-----------------------------------------------------------------------
void drawingCB() // use as a callback to display
{
	int n;
	int i;
	GLenum er;

	int HourTimes[4];
	int MinutesTimes[4];
	int addedHoursValues[4] = { 3,1,0,2 };
	int addedMinValues[4] = { 30,10,0,20 };
	int posX[4] = { -2,2,-2,2 };
	int posY[4] = { -2,-2,2,2 };

	//calculating the correct times to display for each clock:
	for (i = 0; i < 4; i++)
	{
		HourTimes[i] = localHourAtInit + user_hour_movment + addedHoursValues[i];
		MinutesTimes[i] = localMinAtInit + user_minute_movment + addedMinValues[i];
		if (MinutesTimes[i] >= 60) HourTimes[i] += MinutesTimes[i] / 60;
	}


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.2f, 0.8f, 0.69f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//drawing clocks:
	for (i = 0; i < 4; i++)
	{
		drawClock(HourTimes[i], MinutesTimes[i], posX[i], posY[i]);
	}
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
