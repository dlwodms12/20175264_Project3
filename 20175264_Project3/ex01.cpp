#include <iostream>
#include <cstring>
#include <compare>

using namespace std;

//���� Ŭ����
class Vector
{
private:
	float x, y, z;
public:
	Vector() {}
	Vector(float x, float y, float z) :x{ x }, y{ y }, z{ z } {}
	//���׿����� + 
	Vector operator+() const
	{
		return Vector{ +x, +y, +z };
	}

	//���׿����� - 
	Vector operator-() const
	{
		return Vector{ -x, -y, -z };
	}

	//���׿����� +
	Vector operator+(const Vector& v)const
	{
		return Vector{ x + v.x,y + v.y, z + v.z };
	}

	//���׿����� -
	Vector operator-(const Vector& v)const
	{
		return Vector{ x - v.x,y - v.y, z - v.z };
	}

	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}

	//���� ������ *
	//1. ���� ����
	float operator*(const Vector& v)const
	{
		float vec = (x * v.x) + (y * v.y) + (z * v.z);
		return vec;
	}
	//2. ���Ϳ� ��� ����
	Vector operator*(float n)const
	{
		return Vector{ x * n, y * n, z * n };
	}

	//���׿����� / 
	Vector operator/(float n)const
	{
		return Vector{ x / n, y / n, z / n };
	}

	//���� ������++
	Vector& operator++()
	{
		++x;
		++y;
		++z;
		return *this;
	}

	//���� ������++
	//int�� ������ ������ �����ϱ� ���� �Ķ���Ϳ� ���� ��
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

	Vector v2 = v0 + v1; //���׿����� +

	v2.print();

	Vector v3 = -v1; //���׿����� - 

	v3.print();

	//���׿����� *
	//���Ϳ���, �������
	float v4 = v0 * v1;
	cout << v4 << endl;

	//����*�Ǽ��� -> ����
	Vector v5 = v1 * 3.0f;
	v5.print();

	//�������������� ++v1
	//�������������� v1++
	Vector v6 = ++v1;
	Vector v7 = v1++;

	v6.print();
	v7.print();
	v1.print();

	return 0;
}