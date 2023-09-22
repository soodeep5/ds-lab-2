#include <iostream>
using namespace std;


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


int linearCongruence(int a, int b, int m) {
    int x, y;
    int gcd = extendedEuclidean(a, m, x, y);

    if (b % gcd != 0) {
        return -1; 
    }

    int x0 = (x * (b / gcd)) % m;
    if (x0 < 0) {
        x0 += m; 
    }
    return x0;
}

int main() {
    int a, b, m;
    cout << "Enter the coefficients (a, b, and m) for the linear congruence: ";
    cin >> a >> b >> m;

    if (a == 0) {
        cout << "Invalid value of 'a'. 'a' must be non-zero." << endl;
        return 1;
    }

    int solution = linearCongruence(a, b, m);

    if (solution != -1) {
        cout << "The solution of the linear congruence is: " << solution << endl;
    } else {
        cout << "No solution exists for the linear congruence." << endl;
    }

    return 0;
}