#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;
typedef struct Date Date;
typedef struct Books Books;
typedef struct Penilaian Penilaian;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loadbar()
{
	int bar1 = 177, bar2 = 219;

	cout<<"Loading...\n";
  	cout<<"\n\t\t\t\t\t\t";

  	for(int i=0; i<25; i++)
	  cout<< (char)bar1;
	  
	cout<<"\r";
	cout<<"\t\t\t\t\t\t";

  	for(int i=0; i<25; i++)
  		cout<< (char)bar2, Sleep(50);
		  
	cout<<"\n\t\t\t\t\t\t";
	system("pause");
}

struct Date
{
	int day;
	int month;
	int year;
};

struct Penilaian{
	char judul_bk[50], nama[30], pekerjaan[50];
	float nilai;
	char pesan[100];
};

struct Books
{
	char judul[50], pengarang[30], genre[20];
	Date date;
	float rating;
	int halaman;
};
    
int main(){
  	system("color 74");
	gotoxy(45, 2); cout<<"Final Project Pemrograman Lanjut E081";
	gotoxy(52, 3); cout<<"Program Penilaian Buku";
	gotoxy(45, 5); cout<<"Anggota Kelompok 3:";
	gotoxy(45, 6); cout<<"1. Hamida Wefi Niamaputri\t\t(21081010080)";
	gotoxy(45, 7); cout<<"2. Bima Arya Kurniawan\t\t(21081010081)";
	gotoxy(45, 8); cout<<"3. Masyura Fanni Ramadhan\t\t(21081010103)";
	gotoxy(45, 9); cout<<"4. Mochammad Yazid Farhani\t\t(21081010137)";
	gotoxy(45, 10); cout<<"5. Muhammad Ariq Hawari Adiputra\t(21081010149)";
  	gotoxy(48,15); loadbar();
	system("cls");

	//code
	int pilih;

	do
	{
		system("cls");

		cout<<"Menu Program:";
		cout<<"1. Tambah Buku \n2. Lihat Buku \n3. Ubah Buku \n4. Hapus Buku \n5. Urutkan Buku"<<endl;
		cout<<"6. Cari Buku \n7. Tambah Penilaian Buku \n8. Lihat Penilaian Buku"<<endl;
		cout<<"9. Hapus Penilaian Buku \n10. Exit Program"<<endl;
		cout<<"Input: ";
		cin>>pilih;

		switch (pilih)
		{
		case 1: // Tambah Buku
			/* code */
			break;
		case 2: // Lihat Buku
			/* code */
			break;
		case 3: // Ubah Buku
			/* code */
			break;
		case 4: // Hapus Buku
			/* code */
			break;
		case 5: // Urutkan Buku
			/* code */
			break;
		case 6: // Cari Buku
			/* code */
			break;
		case 7: // Tambah Penilaian Buku
			/* code */
			break;
		case 8: // Hapus Penilaian Buku
			/* code */
			break;
		case 9: // Lihat Penilaian Buku
			/* code */
			break;
		case 10: // Exit Program
			cout<<"Program Berhenti!!!"<<endl;
			break;
		default:
			cout<<"Input salah!!!"<<endl;
			break;
		}

		getche();
	} while (pilih != 10);
}
