#include<iostream>

using namespace std;

class Vector
{
private:
	double* cords_data = nullptr;
	int size;
public:
	Vector(int length);
	Vector(Vector& v);
	~Vector();
	double getLength();
	double& operator[](int posinion);
	friend istream& operator>>(istream& in, Vector& v);
	friend ostream& operator<<(ostream& out, const Vector& v);
	friend bool operator<(Vector& a, Vector& b);
	friend bool operator>(Vector& a, Vector& b);
	friend bool operator!=(Vector& a, double b);
};
