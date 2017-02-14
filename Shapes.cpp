#include <GL/glew.h>
#include <iostream>
#include <SDL.h>
#include "Game.h"
#include "Cam.h"
#include "Shapes.h"

Shapes::Shapes()
{

}

Shapes::~Shapes()
{

}

/*thanks sonar systems for the simple createcube function and help with modern opengl!! :)*/

float Shapes::CreateCube(float centerPosX, float centerPosY, float centerPosZ, float edgeLength)
{
	GLfloat halfSideLength = edgeLength * 0.5f;

	GLfloat colour[] =
	{
		255, 0.0, 0.0,
		0.0, 255, 0.0,
		0.0, 0.0, 255,

		0.0, 255, 0.0,
		255, 0.0, 255,
		0.0, 0.0, 255,

		0.0, 255, 255,
		22, 150, 215,
		255, 0.0, 255,

		0.0, 0.0, 25,
		25, 255, 64,
		243, 21, 42,

		40, 25, 255,
		21, 52, 53,
		53, 43, 65,
		
		1, 42, 52,
		43, 54, 32,
		43, 75, 76
	};

	GLfloat vertices[] =
	{
		// front face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //2 top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //0 bottom left
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //1 bottom right
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //3 top right

		// back face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //6 top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //7 top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //5 bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //4 bottom left

		// left face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //2 top left
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //6 top right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //4 bottom right
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //0 bottom left

		// right face
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //3 top left
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //1 bottom left
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //5 bottom right
		centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //7 top right

		// top face
		centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //2 top left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength, //3 bottom left
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //7 bottom right
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength, //6 top right

		// bottom face
		centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength, //0 top left
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,  //4 top right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength, //5 bottom right
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength //1 bottom left
	};



	glPolygonMode(GL_FRONT_AND_BACK, GL_TRIANGLES);
	//glColor3f( colour[0], colour[1], colour[2] );
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glColorPointer(3, GL_FLOAT, 0, colour);

	glDrawArrays(GL_QUADS, 0, 24);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	return 1.0;
}