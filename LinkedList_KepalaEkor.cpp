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
} *kepala, *ekor, *hapus;
bool isEmpty();
void init();
void sisipBuah(q infoBaru);
void hapusBuah(string namaBuah);
void bacadaridepan();
void bacadaribelakang();
int readLength();
int main()
{
	init();
	q temp;
	int pilih, banyakdata;
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
			for (int i = 0; i < banyakdata; i++)
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
void init()
{
	kepala = (Node *)malloc(sizeof(Node));
	ekor = (Node *)malloc(sizeof(Node));
	kepala->infoBuah.harga = -9999;
	kepala->next = ekor;
	ekor->infoBuah.harga = 9999;
	ekor->next = NULL;
}
bool isEmpty()
{
	if (kepala->next == ekor)
		return (true);
	else
		return (false);
}
void sisipBuah(q infoBaru)
{
	Node *newNode, *bantu;
	newNode = new Node;
	newNode->infoBuah = infoBaru;
	bantu = kepala;
	while (infoBaru.harga > bantu->next->infoBuah.harga)
		bantu = bantu->next;
	newNode->next = bantu->next;
	bantu->next = newNode;
}
void hapusBuah(string namaBuah)
{
	Node *hapus, *bantu;
	if (isEmpty())
		cout << "Belum Ada Data Buah\n";
	else
	{
		bantu = kepala;
		while (bantu->next != ekor && namaBuah != bantu->next->infoBuah.nama)
			bantu = bantu->next;
		if (namaBuah == bantu->next->infoBuah.nama)
		{
			hapus = bantu->next;
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
		bantu = kepala->next;
		while (bantu != ekor)
		{
			cout << "Nama Buah : " << bantu->infoBuah.nama
				 << endl;
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
		depan = kepala;
		kepala = ekor;
		do
		{
			bantu = depan;
			while (bantu->next != ekor)
				bantu = bantu->next;
			ekor->next = bantu;
			ekor = bantu;
		} while (ekor != depan);
		ekor->next = NULL;
		bantu = kepala->next;
		while (bantu != ekor)
		{
			cout << "Nama Buah : " << bantu->infoBuah.nama << endl;
			cout << "Harga Buah : " << bantu->infoBuah.harga << endl;
			cout << endl;
			bantu = bantu->next;
		}
	}
	cout << endl;
}
