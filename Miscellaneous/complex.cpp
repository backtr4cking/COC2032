#include <iostream>
#include <cmath>
#include <string>
#include <utility>

using namespace std;

class Complex {
private:
    double r;
    double i;

public:
    Complex(double real = 0.0, double imag = 0.0) : r(real), i(imag) {}

    // readable string format for when we print the object
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.r;
        if (c.i >= 0) {
            os << " + " << c.i << "i";
        } else {
            os << " - " << -c.i << "i";
        }
        return os;
    }

    double modulus() const {
        return sqrt(r * r + i * i);
    }

    Complex conjugate() const {
        return Complex(r, -i);
    }

    Complex operator+(const Complex& other) const {
        return Complex(r + other.r, i + other.i);
    }

    Complex operator-(const Complex& other) const {
        return Complex(r - other.r, i - other.i);
    }

    // (a+bi)(c+di) = ac - bd + i(ad + bc)
    Complex operator*(const Complex& other) const {
        return Complex(r * other.r - i * other.i, r * other.i + i * other.r);
    }

    // z1 / z2 == (z1*(conjugate(z2)))/square of modulus(z2)
    Complex operator/(const Complex& other) const {
        double mod_squared = other.r * other.r + other.i * other.i;
        Complex res = *this * other.conjugate();
        return Complex(res.r / mod_squared, res.i / mod_squared);
    }

    bool operator==(const Complex& other) const {
        return (r == other.r && i == other.i);
    }

    // returns argument in radians
    double argument() const {
        return atan2(i, r);
    }

    // returns argument in degrees
    double argument_deg() const {
        return argument() * 180.0 / acos(-1.0);
    }

    pair<double, double> polar_form() const {
        return make_pair(modulus(), argument_deg());
    }

    string trig_form() const {
        double rad = modulus();
        double theta = argument_deg();
        return to_string(rad) + "(cos(" + to_string(theta) + ") + isin(" + to_string(theta) + "))";
    }

    static Complex from_polar(double rad, double theta) {
        return Complex(rad * cos(theta), rad * sin(theta));
    }
};