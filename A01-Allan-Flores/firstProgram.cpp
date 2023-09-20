// Course: 		        IGME 309
// Student Name: 	    Allan Flores
// Assignment Number:   01

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif
#include <math.h>

// the window's width and height
int width, height;
float sides;

void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;

    sides = 50.0f; 
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

void drawPanda() {
    // Left Ear
    drawFilledCircle(255.0f / 255.0f, 51.0f / 255.0f, 153.0f / 255.0f, -3.0f, 7.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, -3.0f, 7.0f, 1.0f, 2.0f);
    // Right Ear
    drawFilledCircle(255.0f / 255.0f, 51.0f / 255.0f, 153.0f / 255.0f, 3.0f, 7.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 3.0f, 7.0f, 1.0f, 2.0f);

    // Chest 
    drawFilledCircle(6.0f / 255.0f, 175.0f / 255.0f, 0.0f / 255.0f, 0.0f, -1.0f, 3.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 3.0f, 2.0f);

    // Head
    drawFilledCircle(1.0f, 1.0f, 1.0f, 0.0f, 4.0f, 4.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 0.0f, 4.0f, 4.0f, 2.0f);

    // Left Arm
    drawFilledCircle(158.0f / 255.0f, 23.0f / 255.0f, 192.0f / 255.0f, -3.0f, 0.0f, 1.25f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, -3.0f, 0.0f, 1.25f, 2.0f);
    // Right Arm
    drawFilledCircle(158.0f / 255.0f, 23.0f / 255.0f, 192.0f / 255.0f, 3.0f, 0.0f, 1.25f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 1.25f, 2.0f);

    // Left Hand
    drawFilledCircle(243.0f / 255.0f, 198.0f / 255.0f, 49.0f / 255.0f, -3.0f, 0.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, -3.0f, 0.0f, 1.0f, 2.0f);
    // Right Hand
    drawFilledCircle(243.0f / 255.0f, 198.0f / 255.0f, 49.0f / 255.0f, 3.0f, 0.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 3.0f, 0.0f, 1.0f, 2.0f);

    // Left Leg 
    drawFilledCircle(59.0f / 255.0f, 255.0f / 255.0f, 53.0f / 255.0f, -3.0f, -3.0f, 1.5f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, -3.0f, -3.0f, 1.5f, 2.0f);
    // Right Leg
    drawFilledCircle(59.0f / 255.0f, 255.0f / 255.0f, 53.0f / 255.0f, 3.0f, -3.0f, 1.5f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 3.0f, -3.0f, 1.5f, 2.0f);

    // Left Foot
    drawFilledCircle(243.0f / 255.0f, 198.0f / 255.0f, 49.0f / 255.0f, -2.6f, -3.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, -2.6f, -3.0f, 1.0f, 2.0f);
    // Right Foot
    drawFilledCircle(243.0f / 255.0f, 198.0f / 255.0f, 49.0f / 255.0f, 2.6f, -3.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 2.6f, -3.0f, 1.0f, 2.0f);

    // Left Eye
    drawFilledCircle(0.0f, 0.0f, 0.0f, -2.0f, 5.0f, 1.5f);
    // Right Eye
    drawFilledCircle(0.0f, 0.0f, 0.0f, 2.0f, 5.0f, 1.5f);

    // Left Sclera
    drawFilledCircle(1.0f, 1.0f, 1.0f, -1.5f, 5.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, -1.5f, 5.0f, 1.0f, 2.0f);
    // Right Sclera
    drawFilledCircle(1.0f, 1.0f, 1.0f, 1.5f, 5.0f, 1.0f);
    drawWireframeCircle(0.0f, 0.0f, 0.0f, 1.5f, 5.0f, 1.0f, 2.0f);

    // Left Iris
    drawFilledCircle(153.0f / 255.0f, 153.0f / 255.0f, 255.0f / 255.0f, -1.5f, 5.0f, 0.75f);
    // Right Iris
    drawFilledCircle(153.0f / 255.0f, 153.0f / 255.0f, 255.0f / 255.0f, 1.5f, 5.0f, 0.75f);

    // Nose 
    drawFilledCircle(0.0f, 0.0f, 0.0f, 0.0f, 3.0f, 0.75f);

    // Mouth
    drawFilledCircle(0.0f, 0.0f, 0.0f, -1.0f, 1.5f, 0.25f);


}

// called when the GL context need to be rendered
void display(void)
{
    // clear the screen to white, which is the background color
    glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 0.0);

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

    drawPanda();

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

        // Increases the number of sides 
        case '+':
            if (sides < 100) 
                sides++;
            glutPostRedisplay();
            break;

        // Decreases the number of sides
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