#include <iostream>
using namespace std;

void operasiAritmatika(int a, int b) {
    cout << "Penjumlahan: " << a << " + " << b << " = " << a + b << endl;
    cout << "Pengurangan: " << a << " - " << b << " = " << a - b << endl;
    cout << "Perkalian: " << a << " * " << b << " = " << a * b << endl;
    if (b != 0)
        cout << "Pembagian: " << a << " / " << b << " = " << (double)a / b << endl;
    else
        cout << "Pembagian: Tidak bisa dibagi dengan nol" << endl;
}

void cekGanjilGenap(int a, int b) {
    cout << a << " adalah " << (a % 2 == 0 ? "Genap" : "Ganjil") << endl;
    cout << b << " adalah " << (b % 2 == 0 ? "Genap" : "Ganjil") << endl;
}

void faktorial(int n) {
    unsigned long long hasil = 1;
    for (int i = 1; i <= n; i++) {
        hasil *= i;
    }
    cout << "Faktorial dari " << n << " adalah: " << hasil << endl;
}

void cekPrima(int n) {
    if (n <= 1) {
        cout << n << " bukan bilangan prima." << endl;
        return;
    }
    bool prima = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            prima = false;
            break;
        }
    }
    if (prima)
        cout << n << " adalah bilangan prima." << endl;
    else
        cout << n << " bukan bilangan prima." << endl;
}

int main() {
    int angka1, angka2;

    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "\n=== Operasi Aritmatika ===\n";
    operasiAritmatika(angka1, angka2);

    cout << "\n=== Cek Ganjil / Genap ===\n";
    cekGanjilGenap(angka1, angka2);

    cout << "\n=== Faktorial ===\n";
    faktorial(angka1);
    faktorial(angka2);

    cout << "\n=== Cek Bilangan Prima ===\n";
    cekPrima(angka1);
    cekPrima(angka2);

    return 0;
}

