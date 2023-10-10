#pragma once
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/constants.hpp>
#include "PolyObject.h"
using namespace glm;
using namespace std;

PolyObject::PolyObject() 
{

}
PolyObject::~PolyObject()
{

}

// add vertex at the end of the vertex list
void PolyObject::addVertex(vec2 p_vert)
{
	vertices.push_back(p_vert);
}

// set the color of this polygon
void PolyObject::setColor(vec3 p_color)
{
	color = p_color;
}

// return the number of vertices
unsigned int PolyObject::getVertNum()
{
	return vertices.size();
}
	
// draw the polygon if it’s completed
void PolyObject::draw()
{
	if (vertices.size() == 0) return;

	glColor3f(color.r, color.g, color.b);

	if (vertices.size() == 1)
		glBegin(GL_POINTS);
	else if (vertices.size() == 2)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);

	for (int i = 0; i < vertices.size(); i++)
		glVertex2f(vertices[i].x, vertices[i].y);
	glEnd();
}

// draw the polygon if it’s being created
void PolyObject::draw(vec2 p_mousePos) 
{
	if (vertices.size() == 0) return;

	glColor3f(color.r, color.g, color.b);

	if (vertices.size() == 1)
		glBegin(GL_LINES);
	else
		glBegin(GL_POLYGON);

	for (int i = 0; i < vertices.size(); i++)
		glVertex2f(vertices[i].x, vertices[i].y);
	glVertex2f(p_mousePos.x, p_mousePos.y);
	glEnd();
}