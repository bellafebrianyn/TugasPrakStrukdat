#include <iostream>
#include <stdlib.h>
using namespace std;
struct q
{
	string nama;
	int harga;
};
struct q buah[10];
int main()
{
	int pilih, banyakdata, i, j, jmlbuah;
	int ketemu, total;
	char menu;
	string pilihbuah;
	do
	{
		system("cls");
		cout << "Data Nama Buah\n"
			 << "1. Input Nama Buah\n"
			 << "2. Lihat Nama Buah\n"
			 << "3. Pembelian Buah\n"
			 << "Pilih : ";
		cin >> pilih;
		if (pilih == 1)
		{
			system("cls");
			cout << "Banyak Data : ";
			cin >> banyakdata;
			cout << endl;
			for (i = 0; i < banyakdata; i++)
			{
				cin.ignore();
				cout << "Nama Buah : ";
				getline(cin, buah[i].nama);
				cout << "Harga Buah : ";
				cin >> buah[i].harga;
				cout << endl;
			}
		}
		else if (pilih == 2)
		{
			system("cls");
			cout << "OUTPUT DATA\n"
				 << "Banyak Data : " << banyakdata << endl
				 << endl;
			for (i = 0; i < banyakdata; i++)
			{
				cout << "Nama Buah : " << buah[i].nama << endl;
				cout << "Harga Buah : " << buah[i].harga << endl;
				cout << endl;
			}
		}
		else if (pilih == 3)
		{
			system("cls");
			cout << "\nData Buah\n";
			for (int i = 0; i < banyakdata; i++)
			{
				cout << "Nama Buah : " << buah[i].nama << endl;
				cout << "Harga Buah : " << buah[i].harga << endl;
				cout << endl;
			}
			cout << endl;
			cin.ignore();
			cout << "Pilih Nama Buah : ";
			getline(cin, pilihbuah);
			cout << "Banyak Buah : ";
			cin >> jmlbuah;
			j = 0;
			ketemu = 0;
			total = 0;
			do
			{
				if (buah[j].nama == pilihbuah)
				{
					ketemu = 1;
				}
				else
					j++;
			} while (ketemu == 0 && j < 10);
			if (ketemu == 1)
			{
				total = buah[j].harga * jmlbuah;
				cout << "Harga : " << total;
			}
			else
				cout << "Buah Tidak Ditemukan";
		}
		else
		{
			cout << "Pilihan Tidak Ditemukan";
		}
		cout << "\nKembali ke menu (y/n) : ";
		cin >> menu;
	} while (menu == 'y' || menu == 'Y');
}
