#include "Vector.h"



Vector::Vector(int x, int y) : x_(x), y_(y)
{

}


Vector::~Vector()
{
}

void Vector::drawVector(SDL_Renderer& renderer) const
{
	SDL_RenderDrawLine(&renderer, 300, 300, 300 + x_ * 60, 300 + y_ * -60); // Window is 600x600 so multiply by 60
}

void Vector::drawAsPoint(SDL_Renderer& renderer) const
{
	SDL_SetRenderDrawColor(&renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	
	SDL_Rect rect{ pixelX() - 2, pixelY() - 2, 4, 4 };
	SDL_RenderDrawRect(&renderer, &rect);
}

void Vector::Multiply(int scale)
{
	x_ = x_ * scale;
	y_ = y_ * scale;
}

void Vector::add(Vector& vector)
{
	x_ += vector.x_;
	y_ += vector.y_;
}

void Vector::subtract(Vector& vector)
{
	x_ -= vector.x_;
	y_ -= vector.y_;
}

int Vector::x() const
{
	return x_;
}

void Vector::setX(int x)
{
	x_ = x;
}

void Vector::setY(int y)
{
	y_ = y;
}

int Vector::y() const
{
	return y_;
}

int Vector::pixelX() const
{
	return 300 + x_ * 60;
}

int Vector::pixelY() const
{
	return 300 + y_ * -60;
}

Vector* Vector::next() const
{
	return next_;
}

void Vector::setNext(Vector& next)
{
	next_ = &next;
}
