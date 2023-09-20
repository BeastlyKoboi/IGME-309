// Course: 		    IGME 309
// Student Name: 	Allan Flores
// Friday Exercise: 02

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif
#include <math.h>
#include <cmath>
#define _USE_MATH_DEFINES 
#include <numbers>

// the window's width and height
int width, height;
float sides;

void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;

    sides = 10.0f; 
}

void drawFilledCircle(float red, float green, float blue, float center_x, float center_y, float radius) 
{
    double pi = 2 * acos(0.0);

    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);

    for (int currVert = sides; currVert > 0; currVert--) {
        glVertex2f(center_x + radius * cos(2 * pi / sides * currVert), center_y + radius * sin(2 * pi / sides * currVert));
    }

    glEnd();
}

void drawWireframeCircle(float red, float green, float blue, float center_x, float center_y, float radius, float lineWidth) 
{
    double pi = 2 * acos(0.0);

    glColor3f(red, green, blue);
    glPointSize(lineWidth);
    glBegin(GL_LINE_LOOP);

    for (int currVert = sides; currVert > 0; currVert--) {
        glVertex2f(center_x + radius * cos(2 * pi / sides * currVert), center_y + radius * sin(2 * pi / sides * currVert));
    }

    glEnd();
}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // clear the buffer stored for drawing
    glClear(GL_COLOR_BUFFER_BIT);


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // specify the color for drawing
    glColor3f(1.0, 0.0, 0.0);

    // this is immedidate mode of OpenGL usded prior to OpenGL 3.0
    //DrawTank();

    // specify the color for new drawing
    glColor3f(0.0, 0.0, 1.0);

    drawFilledCircle(1.0f, 1.0f, 1.0f, 0.0f, 4.0f, 4.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 0.0f, 4.0f, 4.0f, 2.0f);


    //drawWireframeCircle(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 5.0f, 1.0f);
    glPointSize(1.0f);


    glutSwapBuffers();
}

// called when window is first created or when window is resized
void reshape(int w, int h)
{
    // update thescreen dimensions
    width = w;
    height = h;

    //do an orthographic parallel projection, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
    //gluOrtho2D(-5.0, 5.0, -5.0, 5.0);

    /* tell OpenGL to use the whole window for drawing */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    //glViewport((GLsizei) width/2, (GLsizei) height/2, (GLsizei) width, (GLsizei) height);

    glutPostRedisplay();
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        case '+':
            if (sides < 100) 
                sides++;
            glutPostRedisplay();
            break;
        case '-':
            if (sides > 3) 
                sides--;
            glutPostRedisplay();
            break;
    }
}

int main(int argc, char* argv[])
{
    // before create a glut window,
    // initialize stuff not opengl/glut dependent
    init();

    //initialize GLUT, let it extract command-line GLUT options that you may provide
    //NOTE that the '&' before argc
    glutInit(&argc, argv);

    // specify as double bufferred can make the display faster
    // Color is speicfied to RGBA, four color channels with Red, Green, Blue and Alpha(depth)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    //set the initial window size */
    glutInitWindowSize((int)width, (int)height);

    // create the window with a title
    glutCreateWindow("First OpenGL Program");

    /* --- register callbacks with GLUT --- */

    //register function to handle window resizes
    glutReshapeFunc(reshape);

    //register function that draws in the window
    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    //start the glut main loop
    glutMainLoop();

    return 0;
}