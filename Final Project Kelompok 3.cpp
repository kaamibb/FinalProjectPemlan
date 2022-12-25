#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <iostream>

using namespace std;

typedef struct databuku
{
	char judul[50];
	char pengarang[30];
	char genre[20];
	char tanggal[15];
	char rating[5];
	char halaman[100];
}databuku;

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

void tambahdata() {
	databuku *d;
	FILE *fp;
	int n, i, j;
	system("cls");
	printf("\n\t\t\t\t\t\tMENU TAMBAH DATA\n\n");
	printf (" Masukkan Jumlah Data Buku Yang Akan diinput : ");
	scanf ("%d", &n);

	d = (databuku*) calloc(n, sizeof(databuku));
	fp = fopen ("databuku.txt","a");

	for (i = 0; i < n; i++) {
		printf("\n Masukkan Data Buku ke - %d\n", i+1);
		printf(" Judul Buku\t\t: ");
		fflush(stdin);
		gets(d[i].judul);
		printf(" Pengarang\t\t: ");
		gets(d[i].pengarang);
		printf(" Genre\t\t\t: ");
		gets(d[i].genre);
		printf(" Tanggal Perilisan\t: ");
		gets(d[i].tanggal);
		printf(" Rating Umur\t\t: ");
		gets(d[i].rating);
		printf(" Halaman Buku\t\t: ");
		gets(d[i].halaman);
		fwrite(&d[i], sizeof(databuku),1,fp);
	}
	fclose (fp);
	printf(" \n\n Data Buku Telah Disimpan.\n");
	printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
}

void lihatbuku() {
	databuku d1;
	FILE *fp;
	int j = 0;
	system("cls");
	printf("\n\t\t\t\t\t\tMENU TAMPILKAN DATA\n\n");
	fp = fopen ("databuku.txt", "r");
	while (fread(&d1, sizeof(databuku),1,fp)) {
		printf(" Data Buku Ke - %i\n",j+1);
		printf(" ------------------------------------\n");
		printf(" Judul Buku\t\t: %s\n",d1.judul);
		printf(" Pengarang\t\t: %s\n",d1.pengarang);
		printf(" Genre\t\t\t: %s\n",d1.genre);
		printf(" Tanggal Perilisan\t: %s\n",d1.tanggal);
		printf(" Rating Umur\t\t: %s\n",d1.rating);
		printf(" Halaman Buku\t\t: %s\n",d1.halaman);
		printf("\n");
		j++;
	}
	fclose(fp);
	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
}


int main(int argc, char *argv[]){
	int i;
	gotoxy(32,13);
	system("color 0d");
	load1();
	load2();
  	gotoxy(48,12); loadbar();
	system("cls");
	do
	{
		system("color 0d");
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
		case '1' :// Tambah Buku
			tambahdata();
			break;
		case '2' :// Lihat Buku
			lihatbuku();
			break;
		case '3' :// Ubah Buku
	        break;
	    case '4' :// Hapus Buku
	        break;
	    case '5' :// Urutkan Buku
	        break;
	    case '6' :// Cari Buku
	        break;
	    case '7' :// Penilaian Buku
	        break;
		}
		
	} while (getch()!= 27);
}