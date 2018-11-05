#pragma once
#include <SDL2/SDL.h>

class Vector
{
public:
	Vector(int x, int y);
	~Vector();

	void drawVector(SDL_Renderer& renderer);
	void Multiply(int scale);
	void add(Vector& vector);
	void subtract(Vector& vector);

private:
	int x;
	int y;
};

