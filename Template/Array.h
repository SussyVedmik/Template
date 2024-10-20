#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class Array {
private:
    int rows;
    int cols;
    T** matrix;
    void allocateMemory();
    void clearMemory();

public:
    Array(int r, int c);
    Array(const Array<T>& other);
    Array(Array<T>&& other) noexcept;
    ~Array();

    Array<T>& operator=(const Array<T>& other);
    Array<T>& operator=(Array<T>&& other) noexcept;
    Array<T> operator+(const Array<T>& other);
    Array<T> operator-(const Array<T>& other);
    Array<T> operator*(const Array<T>& other);
    Array<T> operator/(const Array<T>& other);
    T& operator()(int r, int c);

    void fillRandom();
    void display() const;
    T maxElement() const;
    T minElement() const;
};

template <typename T>
void Array<T>::allocateMemory() {
    matrix = new T * [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new T[cols];
    }
}

template <typename T>
void Array<T>::clearMemory() {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
Array<T>::Array(int r, int c) : rows(r), cols(c) {
    allocateMemory();
}

template <typename T>
Array<T>::Array(const Array<T>& other) : rows(other.rows), cols(other.cols) {
    allocateMemory();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

template <typename T>
Array<T>::Array(Array<T>&& other) noexcept : rows(other.rows), cols(other.cols), matrix(other.matrix) {
    other.matrix = nullptr;
    other.rows = 0;
    other.cols = 0;
}

template <typename T>
Array<T>::~Array() {
    clearMemory();
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        clearMemory();
        rows = other.rows;
        cols = other.cols;
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& other) noexcept {
    if (this != &other) {
        clearMemory();
        rows = other.rows;
        cols = other.cols;
        matrix = other.matrix;
        other.matrix = nullptr;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

template <typename T>
Array<T> Array<T>::operator+(const Array<T>& other) {
    Array<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Array<T> Array<T>::operator-(const Array<T>& other) {
    Array<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Array<T> Array<T>::operator*(const Array<T>& other) {
    Array<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = matrix[i][j] * other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
Array<T> Array<T>::operator/(const Array<T>& other) {
    Array<T> result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result(i, j) = matrix[i][j] / other.matrix[i][j];
        }
    }
    return result;
}

template <typename T>
T& Array<T>::operator()(int r, int c) {
    return matrix[r][c];
}

template <typename T>
void Array<T>::fillRandom() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

template <typename T>
void Array<T>::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
T Array<T>::maxElement() const {
    T max = matrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

template <typename T>
T Array<T>::minElement() const {
    T min = matrix[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}


