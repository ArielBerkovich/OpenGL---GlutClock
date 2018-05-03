#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H


void mouseClickingCB(int button, int state,int x, int y);
void mouseMotionCB(int x, int y); // this one is only called if the mouse is clicked
#endif