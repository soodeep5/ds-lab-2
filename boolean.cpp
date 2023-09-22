#include <iostream>
#include <vector>
using namespace std;


vector<vector<bool>> booleanMatrixJoin(const vector<vector<bool>>& A, const vector<vector<bool>>& B) {
    int rows = A.size();
    int cols = A[0].size();

    vector<vector<bool>> result(rows, vector<bool>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] || B[i][j];
        }
    }

    return result;
}


vector<vector<bool>> booleanMatrixProduct(const vector<vector<bool>>& A, const vector<vector<bool>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    vector<vector<bool>> result(rowsA, vector<bool>(colsB, false));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]);
            }
        }
    }

    return result;
}


vector<vector<bool>> booleanMatrixBooleanProduct(const vector<vector<bool>>& A, const vector<vector<bool>>& B) {
    int rows = A.size();
    int cols = A[0].size();

    vector<vector<bool>> result(rows, vector<bool>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] ^ B[i][j];
        }
    }

    return result;
}


void displayMatrix(const vector<vector<bool>>& matrix) {
    for (const auto& row : matrix) {
        for (bool element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<bool>> A = {
        {1, 0, 1},
        {0, 1, 1},
        {1, 1, 1}
    };

    vector<vector<bool>> B = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    cout << "Matrix A:" << endl;
    displayMatrix(A);

    cout << "Matrix B:" << endl;
    displayMatrix(B);

    
    cout << "Boolean Matrix Join (OR operation):" << endl;
    vector<vector<bool>> joinResult = booleanMatrixJoin(A, B);
    displayMatrix(joinResult);

    
    cout << "Boolean Matrix Product (AND operation):" << endl;
    vector<vector<bool>> productResult = booleanMatrixProduct(A, B);
    displayMatrix(productResult);

    
    cout << "Boolean Matrix Boolean Product (XOR operation):" << endl;
    vector<vector<bool>> booleanProductResult = booleanMatrixBooleanProduct(A, B);
    displayMatrix(booleanProductResult);

    return 0;
}