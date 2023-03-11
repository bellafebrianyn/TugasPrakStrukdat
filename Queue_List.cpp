#include <iostream>
using namespace std;
struct queues
{
    string nama;
    int nim;
    queues *next;
};
queues *qDepan, *qBelakang, *queueBaru, *hapus, *bantu;
int antrimax;
int banyakqueue();
bool queuekosong();
void cetakqueue();
void dequeue();
void enqueue();
int main()
{
    int pilih;
    char kembali;
    cout << endl;
    cout << "==========================\n"
         << "| DAFTAR ANTRIAN BIOSKOP |\n"
         << "==========================\n";
    cout << "Masukkan Jumlah Maximal Penonton : ";
    cin >> antrimax;
    cout << endl;
    do
    {
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
            enqueue();
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
    if (qDepan == NULL)
    {
        return 0;
    }
    else
    {
        int banyak = 0;
        bantu = qDepan;
        while (bantu != NULL)
        {
            bantu = bantu->next;
            banyak++;
        }
        return banyak;
    }
}
bool queuekosong()
{
    if (banyakqueue() == 0)
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
    if (banyakqueue() == antrimax)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void inputdepan()
{
    cout << "Nama\t : ";
    cin >> qDepan->nama;
    cout << "NIM\t : ";
    cin >> qDepan->nim;
}
void inputbaru()
{
    cout << "Nama\t : ";
    cin >> queueBaru->nama;
    cout << "NIM\t : ";
    cin >> queueBaru->nim;
}
void enqueue()
{
    if (queuepenuh())
    {
        cout << "Antrian Sudah Full" << endl;
    }
    else
    {
        if (queuekosong())
        {
            qDepan = new queues();
            inputdepan();
            qDepan->next = NULL;
            qBelakang = qDepan;
        }
        else
        {
            queueBaru = new queues();
            inputbaru();
            queueBaru->next = NULL;
            qBelakang->next = queueBaru;
            qBelakang = queueBaru;
        }
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
        bantu = qDepan;
        cout << "Antrian Atas Nama : \n\n"
             << "Nama\t : " << bantu->nama << endl
             << "NIM\t : " << bantu->nim << endl
             << "---- Dipersilahkan Masuk ---- " << endl;
        hapus = qDepan;
        qDepan = hapus->next;
        hapus->next = NULL;
        free(hapus);
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
        bantu = qDepan;
        int no = 1;
        while (no <= antrimax)
        {
            if (bantu != NULL)
            {
                cout << no << ". "
                     << "Nama\t: " << bantu->nama << endl
                     << " "
                     << "NIM\t: " << bantu->nim << endl;
                bantu = bantu->next;
            }
            else
            {
                cout << no << ". "
                     << "-" << endl;
            }
            no++;
        }
    }
}
