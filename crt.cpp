#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the modular inverse of 'a' with respect to 'm'
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// Function to calculate the solution using Chinese Remainder Theorem
int chineseRemainderTheorem(const vector<int>& a, const vector<int>& m) {
    int n = a.size();
    if (n != m.size()) {
        cout << "Error: Number of ai and mi values must be the same." << endl;
        return -1;
    }

    int M = 1;
    for (int i = 0; i < n; i++) {
        if (m[i] <= 0) {
            cout << "Error: All mi values must be positive integers." << endl;
            return -1;
        }
        M *= m[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int Mi = M / m[i];
        result += a[i] * Mi * modInverse(Mi, m[i]);
        result %= M;
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of congruences: ";
    cin >> n;

    vector<int> a(n), m(n);
    cout << "Enter the values of ai and mi for each congruence:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "a" << i + 1 << ": ";
        cin >> a[i];
        cout << "m" << i + 1 << ": ";
        cin >> m[i];
    }

    int solution = chineseRemainderTheorem(a, m);

    if (solution != -1) {
        cout << "The solution of the system of congruences is: " << solution << endl;
    }

    return 0;
}