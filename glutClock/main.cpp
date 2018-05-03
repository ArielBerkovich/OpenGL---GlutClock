#include<stdio.h>
#include<math.h>


#include "GL/glut.h" 
#include "Clock2D.h"
#include "Displayer.h"
#include "KeyboardHandler.h"




void initializeClock();
void initGlutWindow(int argc, char *argv[]);
void assignCallbacks();

//================================================================
int main(int argc, char *argv[])
{

	initializeClock();
	initGlutWindow(argc, argv);
	assignCallbacks();
	glutMainLoop();
}
//-----------------------------------------------
void initializeClock()
{
	Color color1;
	Color color2;
	Color color3;

	setColor(255, 255, 0, &color1);
	setColor(0, 0, 0, &color2);
	setColor(0, 0, 255, &color3);


	initClock(color1, color2, color3);
}
//----------------------------------------------
void initGlutWindow(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(20, 20);
	glutInitWindowSize(200, 200);
	glutInitDisplayMode(GLUT_RGB);
	glutCreateWindow("Clock");
}
//----------------------------------------------
void assignCallbacks()
{
	glutReshapeFunc(reshapeFuncCB);
	glutDisplayFunc(drawingCB);
	glutKeyboardFunc(keyboardCB);
}