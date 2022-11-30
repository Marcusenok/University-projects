#include <iostream>
#include "Vector.h"


Vector::Vector(int length) 
{
    if (length > 1)
    {
        size = length;
        cords_data = new double[size];
        cout << "Constructor\n";
    }
    else cout << "Bad vector size\n";
}

Vector::Vector(Vector& v) 
{
    size = v.size;
    cords_data = new double[size];
    for (int i = 0; i < size; i++) cords_data[i] = v.cords_data[i];
    cout << "Constructor copy\n";
}

Vector::~Vector()
{
    delete cords_data;
    cords_data = nullptr;
    size = 0;
    cout << "Destructor\n";
}

double Vector::getLength()
{
    double temp = 0;
    for (int i = 0; i < size; i++) temp += (cords_data[i] * cords_data[i]);
    return sqrt(temp);
}

double& Vector::operator[](int posinion)
{
    if (posinion >= 0 and posinion <= size) return cords_data[posinion];
}

istream& operator>>(istream& in, Vector& v)
{
    for (int i = 0; i < v.size; i++)
    {
        cout << i + 1 << " number vector ";
        in >> v.cords_data[i];
    }
    return in;
}

ostream& operator<<(ostream& out, const Vector& v)
{
    for (int i = 0; i < v.size; i++) out << v.cords_data[i] << " ";
    return out << "\n";
}

bool operator<(Vector& a, Vector& b)
{
    if (a.getLength() < b.getLength()) return true;
    else return false;
}

bool operator>(Vector& a, Vector& b)
{
    if (a.getLength() > b.getLength()) return true;
    else return false;
}

bool operator!=(Vector& a, double b)
{
   if (a.getLength() != b) return true;
   else return false;
}