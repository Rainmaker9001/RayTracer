// main.cpp

// Includes
#include "st.h"
#include "stgl.h"
#include "stglut.h"
#include "Scene.h"

#include <iostream> 
#include <stdio.h>
using namespace std;

#define WIN_WIDTH 512
#define WIN_HEIGHT 512

//globals
Scene* scene;


void DisplayCallback()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Clear the window.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	scene->Draw();
    glutSwapBuffers();
}

// Reshape the window
void ReshapeCallback(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho(0, w, 0, h, -1., 1.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    scene = new Scene(argv[1]);
	
	// Initialize GLUT.
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowPosition(20, 20);
    glutInitWindowSize(
        WIN_WIDTH, WIN_HEIGHT);
    glutCreateWindow("CS148 Assignment 6");


    // Register GLUT callbacks and enter main loop.
    glutDisplayFunc(DisplayCallback);
    glutReshapeFunc(ReshapeCallback);

    glutMainLoop();
    return 0;
}
