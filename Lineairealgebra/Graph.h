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
	void drawShape(SDL_Renderer& renderer, Vector& start) const;
	void scale(int factorX, int factorY);
	void scaleFromPoint(int factorX, int factorY, Vector& point);
	void translate(int xDirection, int yDirection);

private:
	std::vector<Vector*> vectors;
};

