#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // Input matrix dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    // Declare the matrix
    int matrix[rows][cols];

    // Input matrix elements with row and column prompts
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element for row " << i + 1 << ", column " << j + 1 << ": ";
            cin >> matrix[i][j];
        }
    }

    // Output the matrix
    cout << "\nMatrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Create a sparse matrix representation using a 2D array
    cout << "\nSparse Matrix Representation (Row, Column, Value):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                cout << i << " " << j << " " << matrix[i][j] << endl;
            }
        }
    }

    return 0;
}


