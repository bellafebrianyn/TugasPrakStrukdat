#include <iostream>
#include <stdlib.h>
using namespace std;
struct q
{
	string nama;
	int harga;
};
struct Node
{
	q infoBuah;
	Node *next;
} *awal, *akhir, *hapus;
bool isEmpty();
void init();
void sisipBuah(q infoBaru);
void hapusBuah(string namaBuah);
void bacadaridepan();
void bacadaribelakang();
int readLength();
int main()
{
	q temp;
	int pilih, banyakdata, i;
	char menu;
	string pilihbuah;
	do
	{
		system("cls");
		cout << "Data Nama Buah\n"
			 << "1. Input Nama Buah\n"
			 << "2. Lihat Nama Buah\n"
			 << "3. Hapus Buah\n"
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
				getline(cin, temp.nama);
				cout << "Harga Buah : ";
				cin >> temp.harga;
				cout << endl;
				sisipBuah(temp);
			}
		}
		else if (pilih == 2)
		{
			system("cls");
			char pilihanTipe;
			cout << "1. Baca Dari Depan \n"
				 << "2. Baca Dari Belakang \n"
				 << "3. Kembali \n"
				 << "Pilih : ";
			cin >> pilihanTipe;
			cout << "\n";
			switch (pilihanTipe)
			{
			case '1':
				bacadaridepan();
				break;
			case '2':
				bacadaribelakang();
				break;
			default:
				break;
			}
		}
		else if (pilih == 3)
		{
			system("cls");
			string inputHapusBuah;
			bacadaridepan();
			if (!isEmpty())
			{
				cin.ignore();
				cout << "Masukkan nama buah yang ingin dihapus : ";
				getline(cin, inputHapusBuah);
				hapusBuah(inputHapusBuah);
			}
		}
		cout << "\nKembali ke Menu (y/n) : ";
		cin >> menu;
	} while (menu == 'y' || menu == 'Y');
}
bool isEmpty() { return awal == NULL; }
void init()
{
	awal = NULL;
	akhir = NULL;
}
void sisipBuah(q infoBaru)
{
	Node *newNode, *bantu;
	newNode = new Node;
	newNode->infoBuah = infoBaru;
	newNode->next = NULL;
	if (isEmpty())
	{
		awal = newNode;
		akhir = newNode;
	}
	else if (infoBaru.harga <= awal->infoBuah.harga)
	{
		newNode->next = awal;
		awal = newNode;
	}
	else
	{
		bantu = awal;
		while (bantu->next != NULL && newNode->infoBuah.harga > bantu->next->infoBuah.harga)
			bantu = bantu->next;
		newNode->next = bantu->next;
		bantu->next = newNode;
		if (infoBaru.harga > akhir->infoBuah.harga)
			akhir = newNode;
	}
}
void hapusBuah(string namaBuah)
{
	Node *hapus, *bantu;
	if (isEmpty())
		cout << "Belum Ada Data Buah\n";
	else if (awal->next == NULL)
	{
		if (awal->infoBuah.nama == namaBuah)
		{
			hapus = awal;
			awal = hapus->next;
			delete hapus;
			cout << "Data " << namaBuah << " Berhasil Dihapus " << endl;
		}
		else
		{
			cout << "Data Buah Tidak Ditemukan" << endl;
		}
	}
	else
	{
		bantu = awal;
		while (bantu->next->next != NULL && namaBuah != bantu->next->infoBuah.nama)
			bantu = bantu->next;
		if (namaBuah == bantu->next->infoBuah.nama)
		{
			hapus = bantu->next;
			if (hapus == akhir)
			{
				akhir = bantu;
				akhir->next = NULL;
			}
			else
				bantu->next = hapus->next;
			delete hapus;
			cout << "Data " << namaBuah << " Berhasil Dihapus " << endl;
		}
		else
			cout << "Data Tidak Ditemukan" << endl;
	}
}
void bacadaridepan()
{
	if (isEmpty())
	{
		cout << "Data Tidak Ada\n";
	}
	else
	{
		Node *bantu;
		bantu = awal;
		while (bantu != NULL)
		{
			cout << "Nama Buah : " << bantu->infoBuah.nama << endl;
			cout << "Harga Buah : " << bantu->infoBuah.harga << endl;
			cout << endl;
			bantu = bantu->next;
		}
	}
	cout << endl;
}
void bacadaribelakang()
{
	if (isEmpty())
	{
		cout << "Data Tidak Ada\n";
	}
	else
	{
		Node *depan, *bantu;
		depan = awal;
		awal = akhir;
		do
		{
			bantu = depan;
			while (bantu->next != akhir)
				bantu = bantu->next;
			akhir->next = bantu;
			akhir = bantu;
		} while (akhir != depan);
		akhir->next = NULL;
		bantu = awal;
		while (bantu != NULL)
		{
			cout << "Nama Buah : " << bantu->infoBuah.nama << endl;
			cout << "Harga Buah : " << bantu->infoBuah.harga << endl;
			cout << endl;
			bantu = bantu->next;
		}
	}
	cout << endl;
}
