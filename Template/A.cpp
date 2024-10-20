#include "A.h"
#include <iostream>
using namespace std;

A::A(int v) : value(v) {}

A::A(const A& other) : value(other.value) {}

A& A::operator=(const A& other) {
    if (this != &other) {
        value = other.value;
    }
    return *this;
}

bool A::operator>(const A& other) const {
    return value > other.value;
}

bool A::operator<(const A& other) const {
    return value < other.value;
}

A A::operator+(const A& other) {
    return A(value + other.value);
}

A A::operator-(const A& other) {
    return A(value - other.value);
}

A A::operator*(const A& other) {
    return A(value * other.value);
}

A A::operator/(const A& other) {
    return A(value / other.value);
}

ostream& operator<<(ostream& out, const A& obj) {
    out << obj.value;
    return out;
}
