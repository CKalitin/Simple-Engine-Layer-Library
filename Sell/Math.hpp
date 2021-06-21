#pragma once

#include <iostream>

struct Vector2 {
	float x, y;

	Vector2() : x(0.0f), y(0.0f) {}; // Vector2 Constructor without starting variables
	Vector2(float _x, float _y) : x(_x), y(_y) {}; // Vector2 Constructor with starting values
	
	Vector2& add(const Vector2& other) { // Add both values other Vector2 to this
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2& subtract(const Vector2& other) { // Subtract both values other Vector2 to this
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector2& multiply(const Vector2& other) { // Multiply both values of this by other Vector2
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vector2& divide(const Vector2& other) { // Divide both values of this by other Vector2
		x /= other.x;
		y /= other.y;

		return *this;
	}

	// All the left Vector2's here should probably be references
	friend Vector2 operator+(Vector2 left, Vector2 right) { // How to handle + operator
		return left.add(right);
	}

	friend Vector2 operator-(Vector2 left, Vector2 right) { // How to handle - operator
		return left.subtract(right);
	}

	friend Vector2 operator*(Vector2 left, Vector2 right) { // How to handle * operator
		return left.multiply(right);
	}

	friend Vector2 operator/(Vector2 left, Vector2 right) { // How to handle / operator
		return left.divide(right);
	}

	friend Vector2 operator+(Vector2 left, float right) { // How to handle + operator
		return left.add(Vector2(right, right));
	}

	friend Vector2 operator-(Vector2 left, float right) { // How to handle - operator
		return left.subtract(Vector2(right, right));
	}

	friend Vector2 operator*(Vector2 left, float right) { // How to handle * operator
		return left.multiply(Vector2(right, right));
	}

	friend Vector2 operator/(Vector2 left, float right) { // How to handle / operator
		return left.divide(Vector2(right, right));
	}

	friend Vector2 operator+(Vector2 left, int right) { // How to handle + operator
		return left.add(Vector2((float)right, (float)right));
	}

	friend Vector2 operator-(Vector2 left, int right) { // How to handle - operator
		return left.subtract(Vector2((float)right, (float)right));
	}

	friend Vector2 operator*(Vector2 left, int right) { // How to handle * operator
		return left.multiply(Vector2((float)right, (float)right));
	}

	friend Vector2 operator/(Vector2 left, int right) { // How to handle / operator
		return left.divide(Vector2((float)right, (float)right));
	}

	Vector2& operator+=(const Vector2& other) { // How to handle += operator
		return add(other);
	}

	Vector2& operator-=(const Vector2& other) { // How to handle -= operator
		return subtract(other);
	}

	Vector2& operator*=(const Vector2& other) { // How to handle *= operator
		return multiply(other);
	}

	Vector2& operator/=(const Vector2& other) { // How to handle /= operator
		return divide(other);
	}

	bool operator==(const Vector2& other) { // How to handle == operator
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) { // How to handle != operator
		return x != other.x && y != other.y;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector) {  // How to handle << operator
		stream << "(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
};

struct Vector2Int {
	int x, y;

	Vector2Int() : x(0), y(0) {}; // Vector2Int Constructor without starting variables
	Vector2Int(int _x, int _y) : x(_x), y(_y) {}; // Vector2Int Constructor with starting values
	
	Vector2Int& add(const Vector2Int& other) { // Add both values other Vector2Int to this
		x += other.x;
		y += other.y;

		return *this;
	}

	Vector2Int& subtract(const Vector2Int& other) { // Subtract both values other Vector2Int to this
		x -= other.x;
		y -= other.y;

		return *this;
	}

	Vector2Int& multiply(const Vector2Int& other) { // Multiply both values of this by other Vector2Int
		x *= other.x;
		y *= other.y;

		return *this;
	}

	Vector2Int& divide(const Vector2Int& other) { // Divide both values of this by other Vector2Int
		x /= other.x;
		y /= other.y;

		return *this;
	}

	// All the left Vector2Int's here should probably be references
	friend Vector2Int operator+(Vector2Int left, Vector2Int right) { // How to handle + operator
		return left.add(right);
	}

	friend Vector2Int operator-(Vector2Int left, Vector2Int right) { // How to handle - operator
		return left.subtract(right);
	}

	friend Vector2Int operator*(Vector2Int left, Vector2Int right) { // How to handle * operator
		return left.multiply(right);
	}

	friend Vector2Int operator/(Vector2Int left, Vector2Int right) { // How to handle / operator
		return left.divide(right);
	}

	friend Vector2Int operator+(Vector2Int left, float right) { // How to handle + operator
		return left.add(Vector2Int((int)right, (int)right));
	}

	friend Vector2Int operator-(Vector2Int left, float right) { // How to handle - operator
		return left.subtract(Vector2Int((int)right, (int)right));
	}

	friend Vector2Int operator*(Vector2Int left, float right) { // How to handle * operator
		return left.multiply(Vector2Int((int)right, (int)right));
	}

	friend Vector2Int operator/(Vector2Int left, float right) { // How to handle / operator
		return left.divide(Vector2Int((int)right, (int)right));
	}

	friend Vector2Int operator+(Vector2Int left, int right) { // How to handle + operator
		return left.add(Vector2Int(right, right));
	}

	friend Vector2Int operator-(Vector2Int left, int right) { // How to handle - operator
		return left.subtract(Vector2Int(right, right));
	}

	friend Vector2Int operator*(Vector2Int left, int right) { // How to handle * operator
		return left.multiply(Vector2Int(right, right));
	}

	friend Vector2Int operator/(Vector2Int left, int right) { // How to handle / operator
		return left.divide(Vector2Int(right, right));
	}

	Vector2Int& operator+=(const Vector2Int other) { // How to handle += operator
		return add(other);
	}

	Vector2Int& operator-=(const Vector2Int other) { // How to handle -= operator
		return subtract(other);
	}

	Vector2Int& operator*=(const Vector2Int other) { // How to handle *= operator
		return multiply(other);
	}

	Vector2Int& operator/=(const Vector2Int& other) { // How to handle /= operator
		return divide(other);
	}

	bool operator==(const Vector2Int& other) { // How to handle == operator
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2Int& other) { // How to handle != operator
		return x != other.x && y != other.y;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Vector2Int& vector) {  // How to handle << operator
		stream << "(" << vector.x << ", " << vector.y << ")";
		return stream;
	}
};