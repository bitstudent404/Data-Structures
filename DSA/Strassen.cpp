#include <iostream>
using namespace std;

void strassen(){
    int n;
    cout << "Enter even n order of square matrix:";
    cin >> n;
    if (n%2!=0){
        cout << "Please Enter even n order of square matrix !!";
    }
    if n=2{
    int A[2][2];
    int B[2][2];
    int S1 = B[1][2]-B[2][2];
    int S2 = A[1][1]+A[1][2];
    int S3 = A[2][1]+A[2][2];
    int S4 = B[2][1]-B[1][1];
    int S5 = A[1][1]+A[2][2];
    int S6 = B[1][1]+B[2][2];
    int S7 = A[1][2]-A[2][2];
    int S8 = B[2][1]+B[2][2];
    int S9 = A[1][1]-A[2][1];
    int S10 = B[1][1]+B[1][2];

    int P1 = A[1][1].S1;
    int P2 = S2*B[2][2];
    int P3 = S3*B[1][1];
    int P4 = A[2][2]*S4;
    int P5 = S5*S6;
    int P6 = S7*S8;
    int P7 = S9*S10;if n=2{
    int A[2][2];
    int B[2][2];
    int S1 = B[1][2]-B[2][2];
    int S2 = A[1][1]+A[1][2];
    int S3 = A[2][1]+A[2][2];
    int S4 = B[2][1]-B[1][1];
    int S5 = A[1][1]+A[2][2];
    int S6 = B[1][1]+B[2][2];
    int S7 = A[1][2]-A[2][2];
    int S8 = B[2][1]+B[2][2];
    int S9 = A[1][1]-A[2][1];
    int S10 = B[1][1]+B[1][2];

    int P1 = A[1][1].S1;
    int P2 = S2*B[2][2];
    int P3 = S3*B[1][1];
    int P4 = A[2][2]*S4;
    int P5 = S5*S6;
    int P6 = S7*S8;
    int P7 = S9*S10;

    int C11 = P5+P4-P2
    }
    }}
void minput(){
int r1, c1, r2, c2;

    // Input size of first matrix
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;

    int A[r1][c1];

    // Input first matrix
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    // Input size of second matrix
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;

    int B[r2][c2];

    // Input second matrix
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    // Display first matrix
    cout << "\nFirst Matrix:\n";
    for (int i = 0; i < r1; i++){
        for (int j=i; j< c1;)
        cout << A[i][]
    }
    }


    i