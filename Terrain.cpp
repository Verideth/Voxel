#include <GL/glew.h>
#include <iostream>
#include <SDL.h>
#include "Game.h"
#include "Cam.h"
#include "Shapes.h"
#include "NoiseGen.h"
#include "Terrain.h"
#include <chrono>

Terrain::Terrain()
{

}

Terrain::~Terrain()
{

}

void Terrain::Init()
{
	this->gen.setSeed(this->seed);
}

void Terrain::GenerateTerrain()
{
	for (int x = 0; x < TERRAIN_CONST_SIZE * 7; x++)
	{
		for (int z = 0; z < TERRAIN_CONST_SIZE * 7; z++)
		{
			this->seed = std::chrono::system_clock::now().time_since_epoch().count(); 

			float value = this->gen.getValue(x, z, TERRAIN_CONST_SIZE, TERRAIN_CONST_SIZE);

			float cube = this->shape.CreateCube(x, value, z, 1.0);

			this->blocks.push_back(value);
		}

	}
}

void Terrain::Render()
{
	this->GenerateTerrain();
}