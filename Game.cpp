#include <GL/glew.h>
#include <iostream>
#include <SDL.h>
#include "Game.h"
#include "Cam.h"
#include "Shapes.h"
#include "NoiseGen.h"
#include "Terrain.h"

Camera cam;
Shapes shape;
Terrain ter;

Game::Game()
{
	this->window = nullptr;
	this->gState = GStates::GSTATE_CREATING;
}

Game::~Game()
{

}

void Game::Run()
{
	this->InitAll();
	this->Loop();
}

void Game::Loop()
{
	while (gState == GStates::GSTATE_CREATING)
	{
		this->Input();
		this->Render();
	}
}

void Game::Input()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			this->gState = GStates::GSTATE_QUITTING;	
			break;
		case SDL_MOUSEMOTION:

			break;
		case SDL_KEYDOWN:
			if (evnt.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				this->gState = GStates::GSTATE_QUITTING;
				SDL_Quit();
			}
		}
	}
}

void Game::InitAll()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	this->window = SDL_CreateWindow("Voxels by Verideth", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, MAPEDITOR_WIND_WIDTH, MAPEDITOR_WIND_HEIGHT, SDL_WINDOW_OPENGL);

	if (this->window != nullptr)
	{
		SDL_GLContext context = SDL_GL_CreateContext(this->window);

		glewExperimental = true;
		glewInit();

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		glClearColor(0, 0, 0, 1);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(50, 640.0 / 480.0, 1, 1000);
		glMatrixMode(GL_MODELVIEW);

		ter.Init();
	}
	else
	{
		std::cout << "Window was nullptr!" << std::endl;
	}
}

void Game::Render()
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	cam.Control(2.0, 0.2, true);
	cam.UpdateCamera();

	ter.Render();

	SDL_GL_SwapWindow(this->window);
}	

