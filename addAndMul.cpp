#include <iostream>
#include <string>
using namespace std;

// function to perform addition
string binaryAddition(string a, string b) {
    int carry = 0;
    string result = "";

    int len_a = a.length();
    int len_b = b.length();
    int max_len = max(len_a, len_b);

    while (len_a < max_len) {
        a = '0' + a;
        len_a++;
    }

    while (len_b < max_len) {
        b = '0' + b;
        len_b++;
    }

    for (int i = max_len - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }

    if (carry)
        result = '1' + result;

    return result;
}

// Function to perform multiplication
string binaryMultiplication(string a, string b) {
    string result = "0";

    for (int i = b.length() - 1; i >= 0; i--) {
        if (b[i] == '1') {
            result = binaryAddition(result, a);
        }
        a = a + '0'; 
    }

    return result;
}

int main() {
    string a, b;
    cout << "Enter two binary numbers: ";
    cin >> a >> b;

    // Binary Addition
    string additionResult = binaryAddition(a, b);
    cout << "Binary Addition: " << additionResult << endl;

    // Binary Multiplication
    string multiplicationResult = binaryMultiplication(a, b);
    cout << "Binary Multiplication: " << multiplicationResult << endl;

    return 0;
}