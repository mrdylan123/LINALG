#pragma once
#include <vector>

class Vector;

class Matrix
{
public:
	explicit Matrix(int rows, int cols = 1);

	Matrix operator+(Matrix const& other);
	Matrix operator-(Matrix const& other);
	Matrix operator*(Vector const& vector);
	Matrix operator*(Matrix const& other);

	std::vector<std::vector<int>>* elems();
	void setValue(int x, int y, int value);
private:
	int rows_;
	int cols_;
	std::vector<std::vector<int>> elems_;
};


