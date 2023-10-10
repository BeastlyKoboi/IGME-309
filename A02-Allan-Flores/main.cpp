#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include <iostream>
#include "PolyObject.h"

using namespace std;

// Course: IGME 309
// Student Name: Allan Flores
// Assignment Number: 02

float canvasSize[] = { 10.0f, 10.0f };
int rasterSize[] = { 800, 600 };

// structure for storing 3 2D vertices of a triangle
int numOfVertices = 0;
float color[3];

float mousePos[2];

vector <PolyObject> shapes;

void init(void)
{
    mousePos[0] = mousePos[1] = 0.0f;
    color[0] = 1.0f;
    color[1] = color[2] = 0.0f;

    // Declare first shape and color
    shapes.push_back(PolyObject());
    shapes[0].setColor(vec3(color[0], color[1], color[2]));
}

void display(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(color);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if (shapes.size() == 1) {
        shapes[0].draw(vec2(mousePos[0], mousePos[1]));
    }
    else {
        for (int i = 0; i < shapes.size(); i++) {
            shapes[i].draw();
        }
        shapes[shapes.size() - 1].draw(vec2(mousePos[0], mousePos[1]));
    }

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    rasterSize[0] = w;
    rasterSize[1] = h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, canvasSize[0], 0.0, canvasSize[1]);
    glViewport(0, 0, rasterSize[0], rasterSize[1]);

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

        mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
        mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];

        numOfVertices++;

        shapes[shapes.size() - 1].addVertex(vec2(mousePos[0], mousePos[1]));

        glutPostRedisplay();
    }
}

void motion(int x, int y)
{
    // mouse events are handled by OS, eventually. When using mouse in the raster window, it assumes top-left is the origin.
    // Note: the raster window created by GLUT assumes bottom-left is the origin.
    mousePos[0] = (float)x / rasterSize[0] * canvasSize[0];
    mousePos[1] = (float)(rasterSize[1] - y) / rasterSize[1] * canvasSize[1];

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 13: 
        // Add new shape and set its color
        shapes.push_back(PolyObject());
        shapes[shapes.size() - 1].setColor(vec3(color[0], color[1], color[2]));
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    }
}

void menu(int value)
{
    switch (value) {
    case 0: // clear
        numOfVertices = 0;
        shapes.clear();
        // Add new shape and set its color
        shapes.push_back(PolyObject());
        shapes[0].setColor(vec3(color[0], color[1], color[2]));
        glutPostRedisplay();
        break;
    case 1: //exit
        exit(0);
    case 2: // red
        color[0] = 1.0f;
        color[1] = 0.0f;
        color[2] = 0.0f;
        shapes[shapes.size() - 1].setColor(vec3(color[0], color[1], color[2]));
        glutPostRedisplay();
        break;
    case 3: // green
        color[0] = 0.0f;
        color[1] = 1.0f;
        color[2] = 0.0f;
        shapes[shapes.size() - 1].setColor(vec3(color[0], color[1], color[2]));
        glutPostRedisplay();
        break;
    case 4: // blue
        color[0] = 0.0f;
        color[1] = 0.0f;
        color[2] = 1.0f;
        shapes[shapes.size() - 1].setColor(vec3(color[0], color[1], color[2]));
        glutPostRedisplay();
        break;
    case 5: // black
        color[0] = 0.0f;
        color[1] = 0.0f;
        color[2] = 0.0f;
        shapes[shapes.size() - 1].setColor(vec3(color[0], color[1], color[2]));
        glutPostRedisplay();
        break;
    default:
        break;
    }
}
void createMenu()
{
    int colorMenu = glutCreateMenu(menu);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("Green", 3);
    glutAddMenuEntry("Blue", 4);
    glutAddMenuEntry("Black", 5);

    glutCreateMenu(menu);
    glutAddMenuEntry("Clear", 0);
    glutAddSubMenu("Colors", colorMenu);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char* argv[])
{
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(rasterSize[0], rasterSize[1]);
    glutCreateWindow("Mouse Event - draw a triangle");

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutPassiveMotionFunc(motion);
    createMenu();
    glutMainLoop();
    return 0;
}