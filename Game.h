#pragma once

#include <GL/glew.h>
#include <iostream>
#include <SDL.h>

#define MAPEDITOR_WIND_WIDTH 1280
#define MAPEDITOR_WIND_HEIGHT 720

enum GStates
{
	GSTATE_CREATING,
	GSTATE_QUITTING
};

class Game
{
public:
	Game();
	~Game();

	void Run();

	SDL_Window* window;
private:
	void Loop();
	void InitAll();
	void Input();
	void Render();

	GLuint gState;
};

