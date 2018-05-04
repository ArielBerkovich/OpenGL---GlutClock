#include "Displayer.h"
#include "Clock2D.h"
#include <stdio.h>

//menu constants
#define MENU_SET_1200  10
#define MENU_EXIT      20

extern int localHourAtInit;
extern int localMinAtInit;


int posX[4] = { -2,2,-2,2 };
int posY[4] = { -2,-2,2,2 };
int HourTimes[4];
int MinutesTimes[4];
int addedHoursValues[4] = { 3,1,0,2 };
int addedMinValues[4] = { 30,10,0,20 };
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



	//calculating the correct times to display for each clock:
	for (i = 0; i < 4; i++)
	{
		HourTimes[i] += user_hour_movment;
		MinutesTimes[i] += user_minute_movment;
		if (MinutesTimes[i] >= 60)
		{
			HourTimes[i] += 1;
			MinutesTimes[i] %= 60;
		}
		else if (MinutesTimes[i] < 0)
		{
			HourTimes[i] -= 1;
			MinutesTimes[i] += 60;
		}

		
		HourTimes[i] %= 24;
		
	}
	user_minute_movment = 0;
	user_hour_movment = 0;

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
void menuCB(int value)
{
	switch (value) {
	case MENU_SET_1200:
		HourTimes[2] = 12;
		MinutesTimes[2] = 0;
		glutPostRedisplay();
		break;
	case MENU_EXIT:
		exit(1);
		break;
	}
}
//------------------------------------------------------------