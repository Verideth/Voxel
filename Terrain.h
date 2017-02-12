#pragma once

#include <iostream>
#include <vector>
#include "NoiseGen.h"

#define TERRAIN_CONST_SIZE 16

class Terrain
{
public:
	Terrain();
	~Terrain();

	void Render();
	void Init();
	
private:
	void GenerateTerrain();

	int xWidth = 0.01;
	int yHeight;
	int seed;
	
	Noise::Generator gen;
	
	Shapes shape;
	
	std::vector<GLuint> blocks;
};

