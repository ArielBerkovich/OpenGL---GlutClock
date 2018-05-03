#include "Clock2D.h"
#include<math.h>

Color dotColor;
Color outlineCircleColor;
Color handsColor;
Point points[POINTS_NUM];
GLfloat currentModelviewMatrix[16];

#define HOUR_HAND_LENGTH 0.5f
#define MINUTE_HAND_LENGTH 0.7f

float convertDegToRadiant(float deg);
void drawCircle(float cx, float cy, float r, float num_segments);
void getPointLocationInACircle(float VecDeg, float VecSize, Point *p);
void drawDots();


//-------------------------------------------
void initClock(Color dotC, Color outlineC, Color handsC)
{
	int n;//just a stupid define because C langauge sucks.

		  //init main colors for each components:
	dotColor = dotC;
	outlineCircleColor = outlineC;
	handsColor = handsC;

	//init dots positions:
	for (n = 0; n<POINTS_NUM; n++)
	{
		getPointLocationInACircle((360 * n) / 12.0, 0.8, &points[n]);
	}

}
//-------------------------------------------
void drawClock(int hours,int minute)
{

	drawCircle(0, 0, 1, 100);//circle drawing is done be looping a large number of lines.
	drawDots(); // drawing the dots of the clock which represents hours
	drawTimeHands(hours, minute); // drawing the actual clock hands

}
//-------------------------------------------
void drawClock(int hours, int minute,float x,float y)
{
	glMatrixMode(GL_MODELVIEW); //Clarify just in cas
	
	glPushMatrix(); // save current matrix

	glTranslatef(x, y, 0); // move according to x and y coardinates given

	drawCircle(0, 0, 1, 100);//circle drawing is done be looping a large number of lines.
	drawDots(); // drawing the dots of the clock which represents hours
	drawTimeHands(hours, minute); // drawing the actual clock hands

	glPopMatrix();//restore original matrix

}
//------------------------------------------
void drawCircle(float cx, float cy, float r, float num_segments)
{
	glColor3f(outlineCircleColor.r, outlineCircleColor.g, outlineCircleColor.b);
	glBegin(GL_LINE_LOOP);

	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * Pi * i / num_segments;

		float x = r * cosf(theta);
		float y = r * sinf(theta);

		glVertex2f(x + cx, y + cy);
	}

	glEnd();
}
//----------------------------------------------------------------
void getPointLocationInACircle(float VecDeg, float VecSize, Point *p)
{
	p->x = (GLfloat)sin(convertDegToRadiant(VecDeg)) * VecSize;
	p->y = (GLfloat)cos(convertDegToRadiant(VecDeg)) * VecSize;
}
//----------------------------------------------------------------
float convertDegToRadiant(float deg)
{
	return deg * Pi / 180.0;
}
//------------------------------------------------------------------
//Draw two lines to act as hands based on the time given as input
//Input: int hour, int minute
//Action: draw two hand time
void drawTimeHands(int hour, int minute)
{

	if ((hour >24) || (hour<0))return;
	if ((minute>60) || (minute<0))return;
	float deg1, deg2;//variables to hold the rads of the vectors of the clock

	deg1 = hour % 12;
	deg1 = deg1 + (minute / 60.0f);
	deg1 = (deg1 / 12.0f) * 360;

	deg2 = minute % 60;
	deg2 = (deg2 / 60.0f) * 360;

	
	glMatrixMode(GL_MODELVIEW);

	//draw hour hand
	glColor3f(handsColor.r, handsColor.g, handsColor.b);
	glPushMatrix();
	glRotatef(-deg1, 0, 0, 1);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 0.5);
	glEnd();
	glPopMatrix();

	//draw minute hand
	glPushMatrix();
	glRotatef(-deg2, 0, 0, 1);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 0.8);
	glEnd();
	glPopMatrix();
}
//------------------------------------------------------------------
void drawDots()
{
	glColor3f(dotColor.r, dotColor.g, dotColor.b);

	int n;
	glPointSize(7.0f);
	glLineWidth(3.0f);
	glBegin(GL_POINTS);
	for (n = 0; n<POINTS_NUM; n++) {
		glVertex2f(points[n].x, points[n].y);
	}
	glVertex2f(0, 0);
	glEnd();
}
//-----------------------------------------------------------------
void setColor(int r, int g, int b, Color* color)
{
	color->r = r / 255.0f;
	color->g = g / 255.0f;
	color->b = b / 255.0f;
}
//-----------------------------------------------------------------