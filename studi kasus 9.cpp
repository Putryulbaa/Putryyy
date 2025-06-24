#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Mahasiswa {
private:
    string nim;
    string nama;
    string prodi;
    string noTelp;

public:
    Mahasiswa(string n, string nm, string p, string t) {
        nim = n;
        nama = nm;
        prodi = p;
        noTelp = t;
    }

    string getNIM() const {
        return nim;
    }

    void tampilkan() const {
        cout << "NIM      : " << nim << endl;
        cout << "Nama     : " << nama << endl;
        cout << "Prodi    : " << prodi << endl;
        cout << "No Telp  : " << noTelp << endl;
        cout << "--------------------------" << endl;
    }
};

bool bandingkanAscending(const Mahasiswa& a, const Mahasiswa& b) {
    return a.getNIM() < b.getNIM();
}

bool bandingkanDescending(const Mahasiswa& a, const Mahasiswa& b) {
    return a.getNIM() > b.getNIM();
}

void cariMahasiswa(const vector<Mahasiswa>& data, const string& nimCari) {
    bool ditemukan = false;
    for (size_t i = 0; i < data.size(); i++) {
        if (data[i].getNIM() == nimCari) {
            cout << "\nData Mahasiswa Ditemukan:\n";
            data[i].tampilkan();
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "\nData dengan NIM " << nimCari << " tidak ditemukan.\n";
    }
}

void tampilkanSemua(const vector<Mahasiswa>& data) {
    if (data.empty()) {
        cout << "\nTidak ada data mahasiswa.\n";
        return;
    }
    for (size_t i = 0; i < data.size(); i++) {
        data[i].tampilkan();
    }
}

void inputData(vector<Mahasiswa>& daftar) {
    if (daftar.size() >= 3) {
        cout << "\nData sudah mencapai batas maksimal (3 mahasiswa).\n";
        return;
    }

    string nim, nama, prodi, noTelp;
    cout << "\nInput Data Mahasiswa ke-" << daftar.size() + 1 << ":\n";
    cout << "Masukkan NIM     : ";
    cin >> nim;
    cout << "Masukkan Nama    : ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan Prodi   : ";
    getline(cin, prodi);
    cout << "Masukkan No Telp : ";
    getline(cin, noTelp);

    daftar.push_back(Mahasiswa(nim, nama, prodi, noTelp));
    cout << "\nData berhasil ditambahkan.\n";
}

int main() {
    vector<Mahasiswa> daftar;
    int pilihan;
    string nimCari;

    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Input Data Mahasiswa (max 3)\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa (berdasarkan NIM)\n";
        cout << "4. Urutkan Data (Ascending NIM)\n";
        cout << "5. Urutkan Data (Descending NIM)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputData(daftar);
                break;
            case 2:
                tampilkanSemua(daftar);
                break;
            case 3:
                cout << "\nMasukkan NIM yang ingin dicari: ";
                cin >> nimCari;
                cariMahasiswa(daftar, nimCari);
                break;
            case 4:
                sort(daftar.begin(), daftar.end(), bandingkanAscending);
                cout << "\nData telah diurutkan secara ASCENDING.\n";
                tampilkanSemua(daftar);
                break;
            case 5:
                sort(daftar.begin(), daftar.end(), bandingkanDescending);
                cout << "\nData telah diurutkan secara DESCENDING.\n";
                tampilkanSemua(daftar);
                break;
            case 6:
                cout << "\nTerima kasih! Keluar dari program.\n";
                break;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
        }

    } while (pilihan != 6);

    return 0;
}

