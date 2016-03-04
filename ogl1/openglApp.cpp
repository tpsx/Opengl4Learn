#include "stdafx.h"
#include "openglApp.h"


openglApp::openglApp()
{
	m_windowHight = 512;
	m_windowWidth = 512;
	m_windowPositionX = 100;
	m_windowPositionY = 100;

	m_displayFunc = openglApp::defDisplay;
}


openglApp::~openglApp()
{
}


GLint openglApp::init()
{
	int arvgs = 0;
	glutInit(&arvgs,NULL);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitContextVersion(4, 2);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutInitWindowPosition(m_windowPositionX, m_windowPositionY);
	glutInitWindowSize(m_windowWidth, m_windowHight);
	glutCreateWindow("openglLearn");

	glewExperimental = GL_TRUE;

	if (glewInit())
	{
		cerr << "init glew fail" << endl;
		exit(-1);
	}


	return GLint();
}

void openglApp::defDisplay()
{

}
