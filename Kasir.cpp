#include <iostream>
#include <fstream>
using namespace std;

int main() {
    const int MAX_MENU = 100;

    string daftarMenu[MAX_MENU] = {"Espresso", "Cappucino", "MatchaLatte", "Croissant", "Americano"};
    int daftarHarga[MAX_MENU] = {15000, 20000, 15000, 12000, 15000};
    int jumlahMenu = 5; // jumlah menu awal

    // struk belanja
    string strukMenu[100];
    int strukJumlah[100];
    int strukSubtotal[100];
    int index = 0;
    int totalsemua = 0;

    while(true){
        cout << "\n=== KOPI SANTAI ===" << endl;
        for(int i = 0; i < jumlahMenu; i++){
            cout << i+1 << ". " << daftarMenu[i] << " - " << daftarHarga[i] << endl;
        }
        cout << jumlahMenu+1 << ". Tambah Menu Baru" << endl;
        cout << "0. Selesai" << endl;

        int pilihan;
        cout << "Pilih menu : ";
        cin >> pilihan;

        if(pilihan == 0) break;

        // Tambah menu baru
        if(pilihan == jumlahMenu + 1){
            string menuBaru;
            int hargaBaru;
            cout << "Nama menu baru (tanpa spasi): ";
            cin >> menuBaru;
            cout << "Harga : ";
            cin >> hargaBaru;

            // simpan ke array
            daftarMenu[jumlahMenu] = menuBaru;
            daftarHarga[jumlahMenu] = hargaBaru;
            jumlahMenu++;

            // simpan ke file juga
            ofstream fileTambah("menu.txt", ios::app);
            fileTambah << menuBaru << " " << hargaBaru << endl;
            fileTambah.close();

            cout << "Menu berhasil ditambahkan!\n";
            continue;
        }

        // Pilih menu dari daftar
        if(pilihan >= 1 && pilihan <= jumlahMenu){
            int jumlah;
            cout << "Jumlah : ";
            cin >> jumlah;

            int subtotal = daftarHarga[pilihan-1] * jumlah;
            totalsemua += subtotal;

            cout << "Subtotal : " << subtotal << endl;

            // simpan ke struk
            strukMenu[index] = daftarMenu[pilihan-1];
            strukJumlah[index] = jumlah;
            strukSubtotal[index] = subtotal;
            index++;
        } else {
            cout << "Menu tidak tersedia\n";
        }
    }

    // Cetak struk
    cout << "\n=== STRUK BELANJA ===" << endl;
    for(int i = 0; i < index; i++){
        cout << strukMenu[i] << " x " << strukJumlah[i] << " = " << strukSubtotal[i] << endl;
    }
    cout << "Total Belanja : " << totalsemua << endl;

    return 0;
}
