#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstring>  

using namespace std;

struct KTP {
    char nik[20];
    string nama;
    string tempat_tgl_lahir;
    string jenis_kelamin;
    char gol_darah;
    string alamat;
    string rt_rw;
    string kel_desa;
    string kecamatan;
    string agama;
    string status_perkawinan;
    string pekerjaan;
    string kewarganegaraan;
    string berlaku_hingga;
};

void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void inputKTP(KTP &ktp) {
    cout << "Masukkan NIK: ";
    cin >> ktp.nik;
    clearInputBuffer();

    cout << "Masukkan Nama: ";
    getline(cin, ktp.nama);
    cout << "Masukkan Tempat/Tgl Lahir: ";
    getline(cin, ktp.tempat_tgl_lahir);
    cout << "Masukkan Jenis Kelamin: ";
    getline(cin, ktp.jenis_kelamin);
    cout << "Masukkan Golongan Darah (A/B/AB/O): ";
    cin >> ktp.gol_darah;
    clearInputBuffer();

    cout << "Masukkan Alamat: ";
    getline(cin, ktp.alamat);
    cout << "Masukkan RT/RW: ";
    getline(cin, ktp.rt_rw);
    cout << "Masukkan Kelurahan/Desa: ";
    getline(cin, ktp.kel_desa);
    cout << "Masukkan Kecamatan: ";
    getline(cin, ktp.kecamatan);
    cout << "Masukkan Agama: ";
    getline(cin, ktp.agama);
    cout << "Masukkan Status Perkawinan: ";
    getline(cin, ktp.status_perkawinan);
    cout << "Masukkan Pekerjaan: ";
    getline(cin, ktp.pekerjaan);
    cout << "Masukkan Kewarganegaraan: ";
    getline(cin, ktp.kewarganegaraan);
    cout << "Masukkan Berlaku Hingga: ";
    getline(cin, ktp.berlaku_hingga);
}

void displayKTP(const KTP &ktp) {
    cout << "\n================ KTP SIMULASI ================\n";
    cout << left << setw(20) << "NIK" << ": " << ktp.nik << endl;
    cout << left << setw(20) << "Nama" << ": " << ktp.nama << endl;
    cout << left << setw(20) << "Tempat/Tgl Lahir" << ": " << ktp.tempat_tgl_lahir << endl;
    cout << left << setw(20) << "Jenis Kelamin" << ": " << ktp.jenis_kelamin << "    Gol Darah: " << ktp.gol_darah << endl;
    cout << left << setw(20) << "Alamat" << ": " << ktp.alamat << endl;
    cout << left << setw(20) << "RT/RW" << ": " << ktp.rt_rw << endl;
    cout << left << setw(20) << "Kel/Desa" << ": " << ktp.kel_desa << endl;
    cout << left << setw(20) << "Kecamatan" << ": " << ktp.kecamatan << endl;
    cout << left << setw(20) << "Agama" << ": " << ktp.agama << endl;
    cout << left << setw(20) << "Status Perkawinan" << ": " << ktp.status_perkawinan << endl;
    cout << left << setw(20) << "Pekerjaan" << ": " << ktp.pekerjaan << endl;
    cout << left << setw(20) << "Kewarganegaraan" << ": " << ktp.kewarganegaraan << endl;
    cout << left << setw(20) << "Berlaku Hingga" << ": " << ktp.berlaku_hingga << endl;
    cout << "============================================\n";
}

void bubbleSortByName(KTP arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (arr[j].nama > arr[j+1].nama) {
                KTP temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void bubbleSortByNIK(KTP arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-i-1; j++) {
            if (strcmp(arr[j].nik, arr[j+1].nik) > 0) {
                KTP temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    const int MAX = 100;
    KTP dataKTP[MAX];
    int jumlah;

    cout << "Masukkan jumlah data KTP (maksimal 100): ";
    cin >> jumlah;
    clearInputBuffer();

    if (jumlah < 1 || jumlah > MAX) {
        cout << "Jumlah data tidak valid!\n";
        return 1;
    }

    for (int i = 0; i < jumlah; i++) {
        cout << "\nInput data KTP ke-" << i+1 << ":\n";
        inputKTP(dataKTP[i]);
    }

    cout << "\nData KTP sebelum diurutkan:\n";
    for (int i=0; i<jumlah; i++) {
        displayKTP(dataKTP[i]);
    }
	
	cout << endl;
    cout << "\nMengurutkan data berdasarkan nama...\n";
    bubbleSortByName(dataKTP, jumlah);

    cout << "\nData KTP setelah diurutkan berdasarkan NAMA:\n";
    for (int i=0; i<jumlah; i++) {
        displayKTP(dataKTP[i]);
    }
	
	cout << endl;
    cout << "\nMengurutkan data berdasarkan NIK...\n";
    bubbleSortByNIK(dataKTP, jumlah);

    cout << "\nData KTP setelah diurutkan berdasarkan NIK:\n";
    for (int i=0; i<jumlah; i++) {
        displayKTP(dataKTP[i]);
    }

    return 0;
}

