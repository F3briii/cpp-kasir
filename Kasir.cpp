#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    const int MAX_MENU = 100;
    string daftarMenu[MAX_MENU];
    int daftarHarga[MAX_MENU];
    int jumlahMenu = 0; 

    // struk belanja
    string strukMenu[100];
    int strukJumlah[100];
    int strukSubtotal[100];
    int index = 0;
    int totalsemua = 0;

    // diskon & pajak
    double diskon = 0.1;
    double pajak = 0.1;  
    int diskonThreshold = 100000; 

    while(true){
        cout << "\n=== KOPI SANTAI ===" << endl;

        if(jumlahMenu == 0){
            cout << "Belum ada menu. Silakan tambah menu baru dulu.\n";
        } else {
            for(int i = 0; i < jumlahMenu; i++){
                cout << i+1 << ". " << daftarMenu[i] << " - " << daftarHarga[i] << endl;
            }
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
            cout << "Nama menu baru (tanpa spasi) : ";
            cin >> menuBaru;
            cout << "Harga : ";
            cin >> hargaBaru;

            // simpan ke array
            daftarMenu[jumlahMenu] = menuBaru;
            daftarHarga[jumlahMenu] = hargaBaru;
            jumlahMenu++;

            // simpan ke file
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

    // Hitung diskon & pajak
    double totalFinal = totalsemua;
    double diskonNominal = 0;
    if(totalsemua >= diskonThreshold){
        diskonNominal = totalsemua * diskon;
        totalFinal -= diskonNominal;
    }
    double pajakNominal = totalFinal * pajak;
    totalFinal += pajakNominal;

    // Cetak struk
    cout << "\n=== STRUK BELANJA ===" << endl;
    for(int i = 0; i < index; i++){
        cout << strukMenu[i] << " x " << strukJumlah[i] << " = " << strukSubtotal[i] << endl;
    }
    cout << "Total Belanja : " << totalsemua << endl;
    if(diskonNominal > 0)
        cout << "Diskon 10% : -" << diskonNominal << endl;
    cout << "Pajak 10% : +" << pajakNominal << endl;
    cout << "Total Bayar : " << totalFinal << endl;

    return 0;
}
