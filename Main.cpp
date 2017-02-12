#include <GL/glew.h>
#include <iostream>
#include <SDL.h>
#include "Game.h"

#undef main

int main(int argc, char* argv[])
{
	Game game;
	game.Run();

	return 0;
}