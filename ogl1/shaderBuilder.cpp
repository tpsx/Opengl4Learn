#include "stdafx.h"
#include "shaderBuilder.h"


shaderBuilder::shaderBuilder()
{
}


shaderBuilder::~shaderBuilder()
{
}

shaderBuilder* shaderBuilder::pShaderBuilder = NULL;

shaderBuilder* shaderBuilder::getInstance()
{
	if (!pShaderBuilder)
	{
		pShaderBuilder = new shaderBuilder();
	}
	return pShaderBuilder;
}

GLuint shaderBuilder::createShader(GLenum type, GLsizei count, const GLchar** str, const GLint* length)
{
	GLchar errorBuffer[ERRBUFSIZE];
	GLsizei errLength = 0;
	GLuint shader = glCreateShader(type);
	if (!shader)
	{
		cerr << "create shader fail" << endl;
		return 0;
	}

	glShaderSource(shader, count, str, length);
	glCompileShader(shader);
	glGetShaderInfoLog(shader, ERRBUFSIZE, &errLength, errorBuffer);
	if (errLength)
	{
		cerr << "Compile Shader Fail With:"<<errorBuffer << endl;
		return 0;
	}
	return shader;
}

GLuint shaderBuilder::createShader(GLenum type, GLsizei count, string str, const GLint* length)
{
	return 0;
}