#include "KeyboardHandler.h"
#include "Clock2D.h"
#include "Displayer.h"
#include <stdio.h>



extern int user_hour_movment;
extern int user_minute_movment;

//-------------------------------------------------
void keyboardCB(unsigned char key, int x, int y)
{

	switch (key)
	{



	default: break;

	}
}
void specialFuncsCB(int key, int x, int y)
{
	switch (key)//Pressing the arrow keys changes the time to display
	{
		case ARROW_RIGHT:
						user_hour_movment++; 
						user_hour_movment %= 24;
			          break;
		case ARROW_LEFT:
				     	user_hour_movment--;
						user_hour_movment %= 24;
					  break;
		case ARROW_UP:
			            user_minute_movment++;
				      break;
		case ARROW_DOWN:
						user_minute_movment--;
						
				      break;


		default: break;

	}
	glutPostRedisplay();
}
//-------------------------------------------------

