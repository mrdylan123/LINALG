#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}

void Graph::draw(SDL_Renderer& renderer)
{
	SDL_SetRenderDrawColor(&renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(&renderer, 0, 300, 600, 300); // X-axis
	SDL_RenderDrawLine(&renderer, 300, 0, 300, 600); // Y-axis

	// Get all vectors and draw them aswell
	for(Vector* vector : vectors)
	{
		vector->drawVector(renderer);
	}
}

void Graph::addVector(Vector* vector)
{
	vectors.emplace_back(vector);
}
