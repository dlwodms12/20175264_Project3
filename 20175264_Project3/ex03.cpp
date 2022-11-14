#include <iostream>
#include <cstring>
#include <compare>

using namespace std;

class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}

	friend ostream& operator<<(ostream& os, Vector v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}

	friend istream& operator>>(istream& is, Vector& v)
	{
		is >> v.x >> v.y >> v.z;
		return is;
	}

	float& operator[](int index)
	{
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		return z;
	}
	/*
	const float& operator[](int index)const
	{
		if (index < 1)
			return x;
		if (index == 1)
			return y;
		return z;
	}
	*/

	Vector& operator= (Vector& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}
};

int main()
{
	Vector v0{ 1,2,3 };
	cout << v0 <<endl;

	Vector v1;
	cin >> v1;

	cout << v1 << endl;

	Vector v2{ 4,5,6 };
	cout << v2[0] << endl; //x = 4
	cout << v2[1] << endl; //y = 5
	cout << v2[2] << endl; //z = 6

	int a = 1;
	int b = a; //복사
	int c;
	c = a; //대입

	Vector v3{ 1,2,3 };
	Vector v4 = v3; //복사
	Vector v5;
	v5 = v3; //대입

	cout << v3 << endl;
	cout << v4 << endl;
	cout << v5 << endl;
}