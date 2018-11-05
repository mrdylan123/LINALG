#include "Vector.h"



Vector::Vector(int x, int y) : x(x), y(y)
{

}


Vector::~Vector()
{
}

void Vector::drawVector(SDL_Renderer& renderer)
{
	SDL_RenderDrawLine(&renderer, 300, 300, 300 + x * 60, 300 + y * -60); // Window is 600x600 so multiply by 60
}

void Vector::Multiply(int scale)
{
	x = x * scale;
	y = y * scale;
}

void Vector::add(Vector& vector)
{
	x += vector.x;
	y += vector.y;
}

void Vector::subtract(Vector& vector)
{
	x -= vector.x;
	y -= vector.y;
}
