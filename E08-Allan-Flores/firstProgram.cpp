#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

#include <ctime>
#include <cmath>

using namespace std;

float canvasSize[] = { 20.0f, 20.0f };
int rasterSize[] = { 600, 600 };

// tracking the game time - millisecond 
unsigned int curTime = 0;
unsigned int preTime = 0;
float deltaTime = 0;

float rotationAngle = 0.0f;
float rotateSpeed = 90.0f;

int circRad = 1;
int circVertsNum = 20;

void display(void)
{
	glClearColor(0.9f, 0.9f, 0.7f, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	/*****************************/
	// write your code below

	glTranslatef(10.0f, 15.0f, 0.0f);

	// Anchor
	glPointSize(10.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex2f(0, 0);
	glEnd();

	glRotatef(rotationAngle, 0, 0, 1);
	
	// Pendulum
	// draw the cicle
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circVertsNum; ++i) {
		float t = (float)i / circVertsNum * 2.0f * 3.14f;
		glVertex2f(circRad * cos(t), -10 + circRad * sin(t));
	}
	glEnd();

	// String
	glLineWidth(2.0f);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, -10);
	glEnd();

	// write your code above
	/*****************************/

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	rasterSize[0] = w;
	rasterSize[1] = h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, canvasSize[0], 0, canvasSize[1]);
	glViewport(0, 0, rasterSize[0], rasterSize[1]);

	glutPostRedisplay();
}


void update() {
	curTime = glutGet(GLUT_ELAPSED_TIME);
	deltaTime = (float)(curTime - preTime) / 1000.0f;


	if (rotationAngle > 45.0f) {
		rotateSpeed = -abs(rotateSpeed);
	}
	else if (rotationAngle < -45.0f) {
		rotateSpeed = abs(rotateSpeed);
	}
	rotationAngle += deltaTime * rotateSpeed;

	preTime = curTime;
	glutPostRedisplay();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(rasterSize[0], rasterSize[1]);
	glutCreateWindow("Simple Pendulum");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutIdleFunc(update);

	preTime = glutGet(GLUT_ELAPSED_TIME);
	glutMainLoop();
	return 0;
}