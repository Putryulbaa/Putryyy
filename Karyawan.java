import java.util.Scanner;


public class Main {

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        Karyawan karyawan = new Karyawan();

        System.out.println("===== PROGRAM PENDATAAN KARYAWAN =====");
        System.out.println("Silakan masukkan data karyawan baru.");

        System.out.print("Masukkan NIK       : ");
        String nik = input.nextLine();
        karyawan.setNik(nik);

        System.out.print("Masukkan Nama      : ");
        String nama = input.nextLine();
        karyawan.setNama(nama);

        System.out.print("Masukkan Jabatan   : ");
        String jabatan = input.nextLine();
        karyawan.setJabatan(jabatan);

        System.out.println("\nData karyawan berhasil disimpan. Berikut detailnya:");
        System.out.println("==========================");
        System.out.println("     DETAIL KARYAWAN      ");
        System.out.println("==========================");
        System.out.println("NIK      : " + karyawan.getNik() );
        System.out.println("Nama     : " + karyawan.getNama());
        System.out.println("Jabatan  : " +karyawan.getJabatan() );
        System.out.println("==========================");
        input.nextLine();
        System.out.println("1. Ya");
        System.out.println("2. Tidak");
        System.out.print("\nApakah Anda ingin mengubah jabatan? ");
        int pilihan = input.nextInt();

        input.nextLine();
        if (pilihan == 1) {
            System.out.print("Masukkan Jabatan baru: ");
            String jabatanBaru = input.nextLine();

            karyawan.setJabatan(jabatanBaru);

            System.out.println("\n>> Data jabatan berhasil diubah.");
            System.out.println("Berikut adalah data karyawan setelah diupdate:");
            System.out.println("==========================");
            System.out.println("     DETAIL KARYAWAN      ");
            System.out.println("==========================");
            System.out.println("NIK      : " + karyawan.getNik() );
            System.out.println("Nama     : " + karyawan.getNama());
            System.out.println("Jabatan  : " +karyawan.getJabatan() );
            System.out.println("==========================");
        } else {
            System.out.println("\nTidak ada data yang diubah. Program selesai.");
        }


        input.close();
    }
}
