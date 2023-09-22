#include <iostream>
#include <vector>
using namespace std;


void findPrimeFactors(int num) {
    vector<int> primeFactors;

    
    while (num % 2 == 0) {
        primeFactors.push_back(2);
        num /= 2;
    }

    
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            primeFactors.push_back(i);
            num /= i;
        }
    }

    
    if (num > 2) {
        primeFactors.push_back(num);
    }

    
    cout << "Prime factors of the number: ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    findPrimeFactors(num);

    return 0;
}