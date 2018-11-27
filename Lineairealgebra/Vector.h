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

	double x() const;
	void setX(double x);
	double y() const;
	void setY(double y);
	double pixelX() const;
	double pixelY() const;

	Vector* next() const;
	void setNext(Vector& next);

private:
	double x_;
	double y_;

	Vector* next_;
};

