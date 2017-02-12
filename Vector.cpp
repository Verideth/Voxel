#include <GL/glew.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <SDL.h>

#include "Vector.h"

Vec3::Vec3()
{
	x = y = z = 0;
}

Vec3::Vec3(float xPos, float yPos, float zPos)
{
	x = xPos;
	y = yPos;
	z = zPos;
}

Vec3::Vec3(float xPos, float yPos)
{
	x = xPos;
	y = yPos;

	z = NULL;
}

float Vec3::DotProduct(const Vec3& vec2)
{
	return (x * vec2.x + y * vec2.y + z * vec2.z);
}

Vec3 Vec3::CrossProduct(const Vec3& vec2)
{
	return Vec3();
}

float Vec3::Length()
{
	return sqrt(x * x + y * y + z * z);
}

void Vec3::Normalize()
{
	float len = Length();

	if (len != 0)
	{
		x /= len;
		y /= len;
		z /= len;
	}
}

void Vec3::Change(float xPos, float yPos, float zPos)
{
	x = xPos;
	y = yPos;
	z = zPos;
}

void Vec3::Change(Vec3& vec2)
{
	x = vec2.x;
	y = vec2.y;
	z = vec2.z;
}

void Vec3::Change(Vec3 vec2)
{
	x = vec2.x;
	y = vec2.y;
	z = vec2.z;
}

void Vec3::ChangeX(float xPos)
{
	x = xPos;
}

void Vec3::ChangeY(float yPos)
{
	x = yPos;
}

void Vec3::ChangeZ(float zPos)
{
	x = zPos;
}

Vec3 Vec3::operator+(const Vec3& vec2)
{
	return Vec3(x + vec2.x, y + vec2.y, z + vec2.z);
}

Vec3 Vec3::operator-(const Vec3& vec2)
{
	return Vec3(x - vec2.x, y - vec2.y, z - vec2.z);
}

Vec3 Vec3::operator*(float num)
{
	return Vec3(x * num, y * num, z * num);
}

Vec3 Vec3::operator/(float num)
{
	if (num != 0)
	{
		return Vec3(x / num, y / num, z / num);
	}
	else
	{
		return Vec3();
	}
}

Vec3 Vec3::operator+=(const Vec3& vec2)
{
	x += vec2.x;
	y += vec2.y;
	z += vec2.z;

	return *this;
}

Vec3 Vec3::operator-=(const Vec3& vec2)
{
	x -= vec2.x;
	y -= vec2.y;
	z -= vec2.z;

	return *this;
}

Vec3 Vec3::operator*=(float num)
{
	x *= num;
	y *= num;
	z *= num;

	return *this;
}

Vec3 Vec3::operator/=(float num)
{
	if (num != 0)
	{
		x /= num;
		y /= num;
		z /= num;
	}

	return *this;
}

bool Vec3::operator==(const Vec3 vec2)
{
	return (x == vec2.x && y == vec2.y && z == vec2.z);
}

bool Vec3::operator!=(const Vec3 vec2)
{
	return !(*this == vec2);
}