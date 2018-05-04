#ifndef KEYBOARDHANDLER_H
#define KEYBOARDHANDLER_H



#define ARROW_UP 101
#define ARROW_DOWN 103
#define ARROW_LEFT 100
#define ARROW_RIGHT 102


void keyboardCB(unsigned char key, int x, int y);
void specialFuncsCB(int key, int x, int y);

#endif