#include <iostream>
using namespace std;


int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int main() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    // Euclidean GCD
    int gcd = euclideanGCD(a, b);
    cout << "GCD using Euclidean algorithm: " << gcd << endl;

    // Extended Euclidean GCD
    int x, y;
    int extendedGCD = extendedEuclidean(a, b, x, y);
    cout << "GCD using Extended Euclidean algorithm: " << extendedGCD << endl;
    cout << "Coefficients x and y: " << x << ", " << y << endl;

    return 0;
}