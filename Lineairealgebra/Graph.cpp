#include "Graph.h"
#include "Matrix.h"
#define _USE_MATH_DEFINES
#include <math.h>


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
	for (Vector* vector : vectors)
	{
		vector->drawAsPoint(renderer);
	}
}

void Graph::addVector(Vector* vector)
{
	vectors.emplace_back(vector);
}

void Graph::drawShape(SDL_Renderer& renderer, Vector& start) const
{
	SDL_RenderDrawLine(&renderer, start.pixelX(), start.pixelY(), start.next()->pixelX(), start.next()->pixelY());

	Vector* current = start.next();

	while (current != nullptr && current != &start)
	{
		SDL_RenderDrawLine(&renderer, current->pixelX(), current->pixelY(), current->next()->pixelX(), current->next()->pixelY());

		current = current->next();
	}
}

void Graph::scale(int factorX, int factorY)
{
	Matrix scalingMatrix = Matrix{ 2, 2 };

	scalingMatrix.setValue(0, 0, factorX);
	scalingMatrix.setValue(1, 1, factorY);

	for (auto& vector : vectors)
	{
		Matrix result = scalingMatrix * *vector;
		vector->setX((*result.elems())[0][0]);
		vector->setY((*result.elems())[1][0]);
	}
}

void Graph::scaleFromPoint(int factorX, int factorY, Vector& point)
{
	translate(-point.x(), -point.y());
	scale(factorX, factorY);
	translate(point.x(), point.y());
}

void Graph::translate(int xDirection, int yDirection)
{
	Matrix translationMatrix = Matrix{ 3, 3 };

	translationMatrix.setValue(0, 0, 1);
	translationMatrix.setValue(1, 1, 1);
	translationMatrix.setValue(2, 2, 1);
	translationMatrix.setValue(2, 0, xDirection);
	translationMatrix.setValue(2, 1, yDirection);

	for (auto& vector : vectors)
	{
		Matrix vectorMatrix = Matrix{ 1, 3 };
		vectorMatrix.setValue(0, 0, vector->x());
		vectorMatrix.setValue(0, 1, vector->y());
		vectorMatrix.setValue(0, 2, 1);

		Matrix result = vectorMatrix * translationMatrix;
		vector->setX((*result.elems())[0][0]);
		vector->setY((*result.elems())[0][1]);
	}
}

void Graph::rotate(int degrees)
{
	Matrix rotationMatrix = Matrix{ 2, 2 };

	const double radians = static_cast<double>(degrees) / 180.0 * static_cast<double>(M_PI);

	rotationMatrix.setValue(0, 0, cos(radians));
	rotationMatrix.setValue(0, 1, -sin(radians));
	rotationMatrix.setValue(1, 0, sin(radians));
	rotationMatrix.setValue(1, 1, cos(radians));

	for (auto& vector : vectors)
	{
		Matrix result = rotationMatrix * *vector;
		vector->setX((*result.elems())[0][0]);
		vector->setY((*result.elems())[1][0]);
	}
}

void Graph::rotateFromPoint(int degrees, Vector& point)
{
	translate(-point.x(), -point.y());
	rotate(degrees);
	translate(point.x(), point.y());
}
