#ifndef CLOCK2D_H
#define CLOCK2D_H

#include"GL/glut.h" 

#define Pi 3.141592654
#define POINTS_NUM 12 

typedef struct POINT
{
	GLfloat x;
	GLfloat y;
} Point;

typedef struct COLOR
{
	float r;
	float g;
	float b;
}Color;


void initClock(Color outline, Color dots, Color hands);
void drawClock(int hours,int minutes);
void drawClock(int hours, int minute, float x, float y);
void setColor(int r, int g, int b, Color* color);
void drawTimeHands(int hour, int minute);

#endif