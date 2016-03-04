// ogl1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <GL\glew.h>
#include <GL\freeglut.h>

#include <iostream>

using namespace std;

#include "LoadShader.h"

enum VAO_IDs{Triangles,NumVAOs};
enum Buffer_IDs{ArrayBuffer, NumBuffers};
enum Attrib_IDs{vPosition = 0};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

void init(void)
{
	glGenVertexArrays(NumVAOs, VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat vertices[NumVertices][2] = {
		{-0.9,-0.9},
		{0.85,-0.9},
		{-0.9,0.85},
		{0.90,-0.85},
		{0.9,0.9},
		{-0.85,0.9}
	};

	glGenBuffers(NumBuffers, Buffers);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices),
		vertices, GL_STATIC_DRAW);

	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER,"triangles.vert"},
		{GL_FRAGMENT_SHADER,"triangles.frag"},
		{GL_NONE,NULL}
	};

	GLuint program = LoadShaders(shaders);
	glUseProgram(program);

	glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glEnableVertexAttribArray(vPosition);


}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES, 0, NumVertices);
	glFlush();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutInitContextVersion(4, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("First_GL!");
	glewExperimental = GL_TRUE;
	if ( glewInit())
	{
		cerr << "Unable to init with :"<< endl;
		exit(EXIT_FAILURE);
	}
	init();
	
	glutDisplayFunc(myDisplay);
	glutMainLoop();
}