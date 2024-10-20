#pragma once

class A {
private:
    int value;

public:
    A(int v = 0);
    A(const A& other);
    A& operator=(const A& other);
    bool operator>(const A& other) const;
    bool operator<(const A& other) const;
    A operator+(const A& other);
    A operator-(const A& other);
    A operator*(const A& other);
    A operator/(const A& other);
    friend std::ostream& operator<<(std::ostream& out, const A& obj);
};
