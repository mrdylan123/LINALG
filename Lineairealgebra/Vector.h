#pragma once
#include <SDL2/SDL.h>

class Vector
{
public:
	Vector(int x, int y);
	~Vector();

	void drawVector(SDL_Renderer& renderer) const;
	void drawAsPoint(SDL_Renderer& renderer) const;

	void Multiply(int scale);
	void add(Vector& vector);
	void subtract(Vector& vector);

	int x() const;
	void setX(int x);
	int y() const;
	void setY(int y);
	int pixelX() const;
	int pixelY() const;

	Vector* next() const;
	void setNext(Vector& next);

private:
	int x_;
	int y_;

	Vector* next_;
};

