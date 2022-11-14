#include <iostream>
#include <cstring>
#include <compare>

using namespace std;

//벡터 클래스
class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}
	//단항연산자 + 
	Vector operator+() const
	{
		return Vector{ +x, +y, +z };
	}

	//단항연산자 - 
	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}

	//이항연산자 +
	Vector operator+(const Vector& v)const
	{
		return Vector{ x + v.x,y + v.y, z + v.z };
	}

	//이항연산자 -
	Vector operator-(const Vector& v)const
	{
		return Vector{ x - v.x,y - v.y, z - v.z };
	}

	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}

	//이항 연산자 *
	//1. 벡터 내적
	float operator*(const Vector& v)const
	{
		float vec = (x * v.x) + (y * v.y) + (z * v.z);
		return vec;
	}
	//2. 벡터와 상수 곱셈
	Vector operator*(float n)const
	{
		return Vector{ x * n, y * n, z * n };
	}

	//이항연산자 / 
	Vector operator/(float n)const
	{
		return Vector{ x / n, y / n, z / n };
	}

	//전위 연산자++
	Vector& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}

	//후위 연산자++
	//int는 전위와 후위를 구분하기 위해 파라미터에 써준 것
	Vector& operator++(int)
	{
		Vector temp = *this;
		++(*this);
		return temp;
	}
};



class Box {
private:
	double length;
	double width;
	double height;

public:
	Box(int l = 0, int w = 0, int h = 0) : length(l), width(w), height(h) {}
	double getVolume(void) {
		return length * width * height;
	}
};



int main()
{
	Vector v0{ 0,1,2 };
	Vector v1{ 1,2,3 };

	Vector v2 = v0 + v1; //이항연산자 +

	v2.print();

	Vector v3 = -v1; //단항연산자 - 

	v3.print();

	//이항연산자 *
	//벡터연산, 내적계산
	float v4 = v0 * v1;
	cout << v4 << endl;

	//벡터*실수값 -> 벡터
	Vector v5 = v1 * 3.0f;
	v5.print();

	//전위증감연산자 ++v1
	//후위증감연산자 v1++
	Vector v6 = ++v1;
	Vector v7 = v1++;

	v6.print();
	v7.print();
	v1.print();

	return 0;
}