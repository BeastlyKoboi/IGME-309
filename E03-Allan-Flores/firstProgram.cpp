// Course: 		    IGME 309
// Student Name: 	Allan Flores
// Friday Exercise: 03

#ifdef __APPLE__
#include <GLUT/glut.h> // include glut for Mac
#else
#include <GL/freeglut.h> //include glut for Windows
#endif


// the window's width and height
int width, height;

void init(void)
{
    // initialize the size of the window
    width = 600;
    height = 600;
}

void DrawChristmasTree() {
    
    // Draw Trunk 
    glColor3f(139.0f/255.0f, 69.0f/255.0f, 19.0f/255.0f);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5f, -4.0f);
    glVertex2f(0.5f, -4.0f);
    glVertex2f(1.0f, -9.0f);
    glVertex2f(-1.0f, -9.0f);
    glEnd();

    // 1st Bottommost Triangle
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -3.0f);
    glVertex2f(6.0f, -5.0f);
    glVertex2f(-6.0f, -5.0f);
    glEnd();

    // Small trunk piece
    glColor3f(139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f);
    glPointSize(30.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, -3.0f);
    glEnd();
    glPointSize(1.0f);

    // 2nd Bottommost Triangle
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, -1.0f);
    glVertex2f(5.0f, -3.0f);
    glVertex2f(-5.0f, -3.0f);
    glEnd();

    // Small trunk piece
    glColor3f(139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f);
    glPointSize(25.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, -1.0f);
    glEnd();
    glPointSize(1.0f);

    // 3rd Bottommost Triangle
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(4.0f, -1.0f);
    glVertex2f(-4.0f, -1.0f);
    glEnd();

    // Small trunk piece
    glColor3f(139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f);
    glPointSize(20.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 1.0f);
    glEnd();
    glPointSize(1.0f);

    // 4th Bottommost Triangle
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 3.0f);
    glVertex2f(3.0f, 1.0f);
    glVertex2f(-3.0f, 1.0f);
    glEnd();

    // Small trunk piece
    glColor3f(139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f);
    glPointSize(15.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 3.0f);
    glEnd();
    glPointSize(1.0f);

    // 5th Bottommost Triangle
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 6.0f);
    glVertex2f(2.0f, 3.0f);
    glVertex2f(-2.0f, 3.0f);
    glEnd();

    // Small trunk piece
    glColor3f(139.0f / 255.0f, 69.0f / 255.0f, 19.0f / 255.0f);
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 6.0f);
    glEnd();
    glPointSize(1.0f);

    // Top Triangle
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 9.5f);
    glVertex2f(1.0f, 6.0f);
    glVertex2f(-1.0f, 6.0f);
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
    // DrawTank();
    DrawChristmasTree();

    // specify the color for new drawing
    glColor3f(0.0, 0.0, 1.0);

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

    //start the glut main loop
    glutMainLoop();

    return 0;
}