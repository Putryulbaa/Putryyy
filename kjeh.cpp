#include <iostream>
#include <algorithm> 

using namespace std;

class MatrixSorter {
private:
    int matrix[3][3];
    int unsorted_1d[9];

public:
    friend istream& operator>>(istream& in, MatrixSorter& m) {
        cout << "Masukkan elemen matriks 3x3:\n";
        int index = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << "Elemen [" << i << "][" << j << "]: ";
                in >> m.matrix[i][j];
                m.unsorted_1d[index++] = m.matrix[i][j]; 
            }
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const MatrixSorter& m) {
        out << "Matriks:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j)
                out << m.matrix[i][j] << "\t";
            out << endl;
        }
        return out;
    }

    void displayUnsorted1D() const {
        cout << "Array 1 dimensi sebelum diurutkan:\n";
        for (int i = 0; i < 9; ++i) {
            cout << unsorted_1d[i] << (i == 8 ? "" : ", ");
        }
        cout << endl;
    }

    void displaySorted1D() const {
        cout << "Array 1 dimensi setelah diurutkan (descending):\n";
        int temp_1d[9];
        int index = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp_1d[index++] = matrix[i][j]; 
            }
        }

        for (int i = 0; i < 9; ++i) {
            cout << temp_1d[i] << (i == 8 ? "" : ", ");
        }
        cout << endl;
    }

    void sortMatrixDescending() {
        int temp[9];
        int index = 0;

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                temp[index++] = matrix[i][j];

        std::sort(temp, temp + 9);

        std::reverse(temp, temp + 9);

        index = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                matrix[i][j] = temp[index++];
    }
};

int main() {
    MatrixSorter m;

    cin >> m;

    cout << "\nMatriks sebelum diurutkan:\n" << m;
    m.displayUnsorted1D();

    m.sortMatrixDescending();

    cout << "\nMatriks setelah diurutkan (descending):\n" << m;
    m.displaySorted1D(); 

    return 0;
}
