#include<iostream>
#include <cmath>
using namespace std;
class vector{
    int i,j,k;
public:
    vector(int x = 0, int y = 0, int z = 0){
        i = x;
        j = y;
        k = z;
    }
    double magnitude() const{
        return sqrt(static_cast<double>(i) * i + static_cast<double>(j) * j + static_cast<double>(k) * k);
    }

    friend ostream& operator<<(ostream &os, const vector& v){
        os << '[' << v.i << ", " << v.j << ", " << v.k << ']' << '\n';
        return os;
    }

    vector operator+(const vector& v) const{
        return vector(i + v.i,j + v.j, k + v.k);
    }
    vector operator-(const vector& v) const{
        return vector(i - v.i,j - v.j, k - v.k);
    }
    //vector dot product
    int operator*(const vector& v) const{
        return i*v.i + j*v.j + k*v.k;
    }
    //scalar multiplication with k, works when we put vector*scalar, not for scalar*vector
    vector operator*(const int c) const{
        return vector(c*i, c*j, c*k);
    }
    //vector product
    vector vector_product(const vector v) const{
        int x = j*v.k - k*v.j;
        int y = k*v.i - i*v.k;
        int z = i*v.j - j*v.i;
        return vector(x,y,z);
    }
    double angleWith(const vector &v) const{
        double magThis = magnitude();
        double magV = v.magnitude();
        if(magThis == 0 || magV == 0)
            return 0.0;
        //finding the dot product of the two vectors
        int dot = *this * v;
        //angle = arccos(dot/mag(a)*mag(b));
        return acos(static_cast<double>(dot)/magThis*magV);
    }
};
vector operator*(int c, const vector& v) {
    return v * c;
}