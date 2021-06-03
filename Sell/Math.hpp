#pragma once

#include <iostream>

struct Vector2 {
	Vector2() : x(0.0f), y(0.0f) {}; // Vector2 Constructor without starting variables
	Vector2(float p_x, float p_y) : x(p_x), y(p_y) {}; // Vector2 Constructor with starting values
	
	void print() { std::cout << x << ", " << y << std::endl; } // Function to print Vector2 x and y

	float x, y;
};