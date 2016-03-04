#pragma once

#include <iostream>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include "shaderBuilder.h"

typedef  void (*displayFunc)(void) ;


class openglApp
{
public:
	openglApp();
	virtual ~openglApp();
	GLint init();
	static void defDisplay();
private:
	int m_windowWidth;
	int m_windowHight;

	int m_windowPositionX;
	int m_windowPositionY;

	displayFunc m_displayFunc;

};

