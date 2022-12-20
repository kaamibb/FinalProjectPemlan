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

void garis(int x) {
	int z;
	for(z = 0; z < x; z++) {
		printf("=");
	}
	printf("\n");
}

void delay() {
	int delay;
	delay=1;
	while(delay<1000000000) {
		delay++;
	}
}	

void load1()
{	
  	char load[] = {'S','T','A','R','T','>'};
	for(int i=0; i<6; i++) {
		printf("%c\t", load[i]);
		delay();
	}
	Sleep(2);
}

void load2()
{
	system("cls");
	gotoxy(43, 8); cout<<"Final Project Pemrograman Lanjut E081";
	gotoxy(51, 9); cout<<"Program Penilaian Buku";
	gotoxy(53, 11); cout<<"Anggota Kelompok 3:";
	gotoxy(39, 12); cout<<"1. Hamida Wefi Niamaputri\t(21081010080)";
	gotoxy(39, 13); cout<<"2. Bima Arya Kurniawan\t\t(21081010081)";
	gotoxy(39, 14); cout<<"3. Masyura Fanni Ramadhan\t(21081010103)";
	gotoxy(39, 15); cout<<"4. Mochammad Yazid Farhani\t(21081010137)";
	gotoxy(39, 16); cout<<"5. Muhammad Ariq Hawari Adiputra\t(21081010149)";
	printf("\n\n\t\t\t\t\t  ");
	system("pause");
	system("cls");
}

void loadbar()
{
	int i, bar1 = 177, bar2 = 219;
	
	cout<<"Loading...\n";
  	cout<<"\n\t\t\t\t\t\t";
	
  	for(int i=0; i<25; i++)
	  cout<< (char)bar1;
	  
	cout<<"\r";
	cout<<"\t\t\t\t\t\t";

  	for(int i=0; i<25; i++)
  		cout<< (char)bar2, Sleep(50);
  	Sleep(0.5);	
		  
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
	int i;
	gotoxy(32,13);
	system("color 0d");
	load1();
	load2();
  	gotoxy(48,12); loadbar();
	system("cls");

	//code
	int pilih;

	do
	{
		system("color 06");
		system("cls");
		garis(120);
		printf("\t\t\t\t\t Final Project Pemrograman Lanjut E081\n");
		printf("\t\t\t\t\t\t Program Penilaian Buku\n");
		garis(120);
		printf("\t\t\t\t\t\t\tMENU UTAMA\n");
	    puts("\n Pilih Menu dibawah ini untuk menjalankan aplikasi");
	    puts("  1.  Tambah Buku");
	    puts("  2.  Tampilkan Buku");
	    puts("  3.  Ubah Buku");
	    puts("  4.  Hapus Buku");
	    puts("  5.  Urutkan Buku");
	    puts("  6.  Cari Buku");
	    puts("  7.  Penilaian Buku");
	    puts(" Esc. Exit\n");

		switch (getch())
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
		case 7: // Penilaian Buku
			/* code */
			break;
		}
		
	} while (getch()!= 27);
}
