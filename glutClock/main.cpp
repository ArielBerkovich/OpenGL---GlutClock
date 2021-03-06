#include<stdio.h>
#include<math.h>


#include "GL/glut.h" 
#include "Clock2D.h"
#include "Displayer.h"
#include "KeyboardHandler.h"
#include "mouseHandler.h"



//menu constants
#define MENU_SET_1200  10
#define MENU_EXIT      20

void initializeClock();
void initGlutWindow(int argc, char *argv[]);
void registerCallbacks();

//================================================================
int main(int argc, char *argv[])
{
	initializeClock();
	initGlutWindow(argc, argv);
	registerCallbacks();
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
void registerCallbacks()
{
	//Screen:
	glutReshapeFunc(reshapeFuncCB);
	glutDisplayFunc(drawingCB);
	
	//Keyboard:
	glutKeyboardFunc(keyboardCB);
	glutSpecialFunc(specialFuncsCB);

	//Mouse:
	glutMouseFunc(mouseClickingCB);
	glutMotionFunc(mouseMotionCB);

	//registering and creating menu
	glutCreateMenu(menuCB);
	glutAddMenuEntry("Set clock to 12:00", MENU_SET_1200);
	glutAddMenuEntry("Exit", MENU_EXIT);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}