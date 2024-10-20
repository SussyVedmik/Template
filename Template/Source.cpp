#include "Array.h"
#include "A.h"
#include <iostream>
using namespace std;

int main() {
    Array<int> intMatrix(2, 2);
    intMatrix.fillRandom();
    cout << "Int Matrix:" << endl;
    intMatrix.display();

    Array<A> aMatrix(2, 2);
    A a1(1), a2(2), a3(3), a4(4);
    aMatrix(0, 0) = a1;
    aMatrix(0, 1) = a2;
    aMatrix(1, 0) = a3;
    aMatrix(1, 1) = a4;
    cout << "A Matrix:" << endl;
    aMatrix.display();

    cout << "Max in int matrix: " << intMatrix.maxElement() << endl;
    cout << "Min in int matrix: " << intMatrix.minElement() << endl;

    Array<int> resultMatrix = intMatrix + intMatrix;
    cout << "Result of addition:" << endl;
    resultMatrix.display();

    return 0;
}
