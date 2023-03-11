#include <iostream>
#include <stdio.h>
#define antrimax 10
using namespace std;
struct mhs
{
    char nama[25];
    int nim;
};
struct antrian
{
    int belakang;
    mhs elemen[antrimax];
};
struct antrian queue;
int banyakqueue();
bool queuekosong();
bool queuepenuh();
void cetakqueue();
void dequeue();
void enqueue(mhs IB);
int main()
{
    int pilih;
    char kembali;
    do
    {
        cout << endl;
        cout << "==========================\n"
             << "| DAFTAR ANTRIAN BIOSKOP |\n"
             << "==========================\n";
        cout << "Menu :\n"
             << " \n"
             << "1. Input Data Penonton\n"
             << "2. Daftar Antrian\n"
             << "3. Masuk Ruangan\n"
             << "4. Exit\n"
             << "Pilih : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            cout << "=======================\n"
                 << "| Input Data Penonton |\n"
                 << "=======================" << endl;
            mhs IB;
            cout << "Nama\t:";
            cin.ignore();
            cin.getline(IB.nama, 25);
            cout << "NIM\t:";
            cin >> IB.nim;
            enqueue(IB);
            break;
        case 2:
            cout << "======================\n"
                 << "| Daftar Antrian |\n"
                 << "======================" << endl;
            cetakqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            exit(1);
            break;
        default:
            break;
        }
        cout << endl;
        cout << "Kembali ke Menu ? (y/n) : ";
        cin >> kembali;
        system("cls");
    } while (kembali == 'y' || kembali == 'Y');
}
int banyakqueue()
{
    if (queuekosong())
    {
        return 0;
    }
    else if (queuepenuh())
    {
        return antrimax;
    }
    else
    {
        return queue.belakang;
    }
}
bool queuekosong()
{
    if (queue.belakang == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool queuepenuh()
{
    if (queue.belakang == antrimax)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void enqueue(mhs IB)
{
    if (queuepenuh())
    {
        cout << "Antrian Sudah Full" << endl;
    }
    else
    {
        queue.belakang++;
        queue.elemen[queue.belakang] = IB;
    }
}
void dequeue()
{
    if (queuekosong())
    {
        cout << "Antrian Masih Kosong!" << endl;
    }
    else
    {
        for (int i = 0; i < queue.belakang; i++)
        {
            queue.elemen[i] = queue.elemen[i + 1];
        }
        cout << "Antrian Atas Nama : \n\n"
             << "Nama\t : " << queue.elemen->nama << endl
             << "NIM\t : " << queue.elemen->nim << endl
             << "---- Dipersilahkan Masuk ---- " << endl;
        queue.belakang--;
    }
}
void cetakqueue()
{
    if (queuekosong())
    {
        cout << "Antrian Masih Kosong. Silahkan Isi Data Terlebih Dahulu :)" << endl;
    }
    else
    {
        cout << "Banyak Antrian : " << banyakqueue() << endl;
        int no = 1;
        while (no <= queue.belakang)
        {
            cout << no << ". "
                 << "Nama\t: " << queue.elemen[no].nama << endl
                 << " "
                 << "NIM\t: " << queue.elemen[no].nim << endl;
            no++;
        }
    }
    cout << endl
         << endl;
}
