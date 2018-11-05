#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include "Vector.h"

class Graph
{
public:
	Graph();
	~Graph();

	void draw(SDL_Renderer& renderer);
	void addVector(Vector* vector);

private:
	std::vector<Vector*> vectors;
};

