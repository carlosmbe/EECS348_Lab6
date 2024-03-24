#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int** allocateMatrix(int N);
void readMatrix(int** matrix, int N, ifstream& file);
void printMatrix(int** matrix, int N);
void addMatrices(int** matrix1, int** matrix2, int** result, int N);
void multiplyMatrices(int** matrix1, int** matrix2, int** result, int N);
void subtractMatrices(int** matrix1, int** matrix2, int** result, int N);
void updateMatrixElement(int** matrix, int row, int col, int newValue, int N);
int findMaxInMatrix(int** matrix, int N);
void transposeMatrix(int** matrix, int** result, int N);


int main() {
    cout << "Hello There Wonderful TA!!" << endl;

    string path;
    cout << "Please give me your file path (EG path/matrix.txt): ";
    cin >> path;

    ifstream file(path);
    if (!file.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    int N;
    file >> N;


    int** matrix1 = allocateMatrix(N);
    int** matrix2 = allocateMatrix(N);
    int** result = allocateMatrix(N);


    readMatrix(matrix1, N, file);
    readMatrix(matrix2, N, file);
    file.close();
    int choice;
    do {
        cout << "Matrix Operations Menu:" << endl;
        cout << "1. Print Matrices" << endl;
        cout << "2. Add Matrices" << endl;
        cout << "3. Multiply Matrices" << endl;
        cout << "4. Subtract Matrices" << endl;
        cout << "5. Update A Matrix Element" << endl;
        cout << "6. Find Maximum Value in a Matrix" << endl;
        cout << "7. Transpose Matrix" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Matrix 1:" << endl;
                printMatrix(matrix1, N);
                cout << "Matrix 2:" << endl;
                printMatrix(matrix2, N);
                break;
            }
            case 2: {
                addMatrices(matrix1, matrix2, result, N);
                cout << "Added Matrices:" << endl;
                printMatrix(result, N);
                break;
            }
            case 3: {
                multiplyMatrices(matrix1, matrix2, result, N);
                cout << "Multiplied Matrices:" << endl;
                printMatrix(result, N);
                break;
            }
            case 4: {
                subtractMatrices(matrix1, matrix2, result, N);
                cout << "Subtracted Matrices (Matrix 1 - Matrix 2):" << endl;
                printMatrix(result, N);
                break;
            }
            case 5: {
                cout << "Let's Update A Matrix" << endl;
                int updateRow, updateCol, newValue;
                cout << "Enter row to update: ";
                cin >> updateRow;
                cout << "Enter column to update: ";
                cin >> updateCol;
                cout << "Enter new value: ";
                cin >> newValue;
                cout << "Updating Matrix 1 at position (" << updateRow << ", " << updateCol << ") with value " << newValue << endl;
                updateMatrixElement(matrix1, updateRow, updateCol, newValue, N);
                printMatrix(matrix1, N);
                break;
            }
            case 6: {
                int maxVal = findMaxInMatrix(matrix1, N);
                cout << "Maximum value in Matrix 1: " << maxVal << endl;
                break;
            }
            case 7: {
                transposeMatrix(matrix1, result, N);
                cout << "Transposing Matrix 1:" << endl;
                printMatrix(result, N);
                break;
            }
            case 8: {
                cout << "Good Bye! It was nice meeting you. Till next time!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
            }
        }
    } while (choice != 8);


    return 0;
}




int** allocateMatrix(int N) {
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    return matrix;
}


void readMatrix(int** matrix, int N, ifstream& file) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix[i][j];
        }
    }
}


void printMatrix(int** matrix, int N) {
 //   cout << "Printing matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void addMatrices(int** matrix1, int** matrix2, int** result, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}


void multiplyMatrices(int** matrix1, int** matrix2, int** result, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}


void subtractMatrices(int** matrix1, int** matrix2, int** result, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}


void updateMatrixElement(int** matrix, int row, int col, int newValue, int N) {
    if (row >= 0 && row < N && col >= 0 && col < N) {
        matrix[row][col] = newValue;
    } else {
        cout << "Invalid row or column index." << endl;
    }
}


int findMaxInMatrix(int** matrix, int N) {
    int max = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}


void transposeMatrix(int** matrix, int** result, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
