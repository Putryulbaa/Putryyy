#include <iostream>
#include <string>
using namespace std;

void inputData(string* pNama, int* pNilai, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        getline(cin, *(pNama + i));
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> *(pNilai + i);
        cin.ignore();
    }
}

double hitungRataRata(int* pNilai, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += *(pNilai + i);
    }
    return (double) total / n;
}

void tampilkanDiAtasRata(string* pNama, int* pNilai, int n, double rata_rata) {
    cout << "\nMahasiswa dengan nilai di atas rata-rata (" << rata_rata << "):\n";
    for (int i = 0; i < n; i++) {
        if (*(pNilai + i) > rata_rata) {
            cout << *(pNama + i) << " dengan nilai " << *(pNilai + i) << endl;
        }
    }
}

int main() {
    const int MAX = 100;
    int n;

    cout << "Masukkan jumlah mahasiswa (max 100): ";
    cin >> n;
    cin.ignore();

    string nama[MAX];
    int nilai[MAX];

    string* pNama = nama;
    int* pNilai = nilai;

    inputData(pNama, pNilai, n);

    double rata_rata = hitungRataRata(pNilai, n);
    cout << "\nRata-rata nilai: " << rata_rata << endl;

    tampilkanDiAtasRata(pNama, pNilai, n, rata_rata);

    return 0;
}

