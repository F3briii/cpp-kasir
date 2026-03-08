#include <iostream>
using namespace std;

int main(){

    int pilihan;
    int harga;
    int jumlah;
    int subtotal;
    int totalsemua = 0;
    string menu;

    //struk menu
    string strukMenu[100];
    int strukJumlah[100];
    int strukSubtotal[100];
    int index = 0;

    while(true){

        cout << "\n=== KOPI SANTAI ===" << endl;
        cout << "1. Espresso - 15000" << endl;
        cout << "2. Cappucino - 20000" << endl;
        cout << "3. Matcha Latte - 15000" << endl;
        cout << "4. Croissant - 12000" << endl;
        cout << "5. Americano - 15000" << endl;
        cout << "0. Selesai" << endl;

        cout << "Pilih menu : ";
        cin >> pilihan;

        if(pilihan == 0){
            break;
        }

        switch(pilihan){
            case 1: harga = 15000; menu = "Espresso"; break;
            case 2: harga = 20000; menu = "Cappucino"; break;
            case 3: harga = 15000; menu = "Matcha Latte"; break;
            case 4: harga = 12000; menu = "Croissant"; break;
            case 5: harga = 15000; menu = "Americano"; break;

            default:
                cout << "Menu tidak tersedia\n";
                continue;
        }

        cout << "Jumlah : ";
        cin >> jumlah;

        subtotal = harga * jumlah;
        totalsemua += subtotal;

        cout << "Subtotal : " << subtotal << endl;

        // simpan transaksi ke struk
        strukMenu[index] = menu;
        strukJumlah[index] = jumlah;
        strukSubtotal[index] = subtotal;
        index++;
    }

    cout << "\nTotal Belanja : " << totalsemua << endl;
    cout << " " << endl;

    cout << "=== STRUK BELANJA ===" << endl;
    for(int i = 0; i < index; i++){
        cout << strukMenu[i] << " x " << strukJumlah[i] 
             << " = " << strukSubtotal[i] << endl;
    }

    cout << " " << endl;
    cout << "Total Belanja : " << totalsemua << endl;

    return 0;
}
