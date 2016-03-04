#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <map>
#include <string>
#include <iostream>
using namespace std;

#define ERRBUFSIZE (100)

class shaderBuilder
{
public:
	GLuint createShader(GLenum type, GLsizei count, const GLchar** string, const GLint* length);

	GLuint createShader(GLenum type, GLsizei count, string str, const GLint* length);
	
	static shaderBuilder*  getInstance();
	
private:
	shaderBuilder();
	~shaderBuilder();
	static shaderBuilder * pShaderBuilder;
};

