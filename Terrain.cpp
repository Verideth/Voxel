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
    this->GenerateTerrain();
}
void Terrain::GenerateTerrain()
{
	for (int x = 0; x < TERRAIN_CONST_SIZE; x++)
	{
		for (int z = 0; z < TERRAIN_CONST_SIZE; z++)
		{
			this->seed = std::chrono::system_clock::now().time_since_epoch().count(); 

			tArray[x][z] = this->gen.getValue(x, z, TERRAIN_CONST_SIZE, TERRAIN_CONST_SIZE);
		}

	}
}

void Terrain::Render()
{
    for (int x = 0; x < TERRAIN_CONST_SIZE; x++)
    {
        for (int z = 0; z < TERRAIN_CONST_SIZE; z++)
        {
            float cube = this->shape.CreateCube(x, tArray[x][z] - 150, z, 1.0);

            this->blocks.push_back(tArray[x][z]);
        }
    }

}