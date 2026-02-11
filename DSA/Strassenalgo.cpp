#include <iostream>
#include <vector>
using namespace std;


long long comparisons = 0;


vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            comparisons++;
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}


vector<vector<int>> subtractMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            comparisons++;
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}


vector<vector<int>> baseCaseMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                comparisons++;  // Count each scalar multiplication
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}


vector<vector<int>> strassenMultiply(vector<vector<int>> A, vector<vector<int>> B) {
    comparisons++;  // Recursive call count
   
    int n = A.size();
    if (n <= 8) {
        return baseCaseMultiply(A, B);
    }


    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize));
    vector<vector<int>> A12(newSize, vector<int>(newSize));
    vector<vector<int>> A21(newSize, vector<int>(newSize));
    vector<vector<int>> A22(newSize, vector<int>(newSize));
    vector<vector<int>> B11(newSize, vector<int>(newSize));
    vector<vector<int>> B12(newSize, vector<int>(newSize));
    vector<vector<int>> B21(newSize, vector<int>(newSize));
    vector<vector<int>> B22(newSize, vector<int>(newSize));


    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }


    auto P1 = strassenMultiply(A11, subtractMatrices(B12, B22));
    auto P2 = strassenMultiply(addMatrices(A11, A12), B22);
    auto P3 = strassenMultiply(addMatrices(A21, A22), B11);
    auto P4 = strassenMultiply(A22, subtractMatrices(B21, B11));
    auto P5 = strassenMultiply(addMatrices(A11, A22), addMatrices(B11, B22));
    auto P6 = strassenMultiply(subtractMatrices(A12, A22), addMatrices(B21, B22));
    auto P7 = strassenMultiply(subtractMatrices(A11, A21), addMatrices(B11, B12));


    auto C11 = addMatrices(subtractMatrices(addMatrices(P5, P4), P2), P6);
    auto C12 = addMatrices(P1, P2);
    auto C21 = addMatrices(P3, P4);
    auto C22 = subtractMatrices(subtractMatrices(addMatrices(P5, P1), P3), P7);


    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
    return C;
}


int main() {
    int n;
    cout << "Enter n (power of 2 <=32): ";
    cin >> n;
   
    if (n > 32 || n < 1 || (n & (n-1)) != 0) {
        cout << "Error: Use 1,2,4,8,16,32 only!" << endl;
        return 1;
    }
   
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
   
    cout << "Enter Matrix A row-wise:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
   
    cout << "Enter Matrix B row-wise:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];
   
    comparisons = 0;
    auto C = strassenMultiply(A, B);
   
    cout << "\nA:" << endl;
    for (auto& row : A) { for (int x : row) cout << x << " "; cout << endl; }
    cout << "\nB:" << endl;
    for (auto& row : B) { for (int x : row) cout << x << " "; cout << endl; }
   
    cout << "\nC = A × B:" << endl;
    for (auto& row : C) { for (int x : row) cout << x << " "; cout << endl; }
   
    cout << "\nTotal comparisons: " << comparisons << endl;
    return 0;
}
