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

typedef struct Penilaian
{
	char judul_bk[30];
	char namap[30];
	char pekerjaan[20];

	struct menilai
	{
		int nilai;
	}menilai[10];

	int total;
	float rata;
}penilaian;

struct pertanyaan
{
	char teks[100];
};

pertanyaan jumlah[10] =
{
	{"Apakah buku ini sesuai ekspetasi anda?"},
	{"Apakah alur cerita buku ini menyenangkan?"},
	{"?"},
	{"?"},
	{"Berikan penilaian untuk tokoh dari buku tersebut?"},
	{"?"},
	{"?"},
	{"Seberapa besar pesan yang disampaikan oleh buku tersebut?"},
	{"?"},
	{"?"}
};

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
	delay = 1;
	while(delay<200000000) {
		delay++;
	}
}	

void load1()
{	
  	char load[] = {'S','T','A','R','T','>'};

	for(int i = 0; i < 6; i++) {
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
	
  	for(int i = 0; i < 25; i++)
	  cout<< (char)bar1;
	  
	cout<<"\r";
	cout<<"\t\t\t\t\t\t";

  	for(int i = 0; i < 25; i++)
  		cout<< (char)bar2, Sleep(50);

  	Sleep(0.5);	  
}

void tambahdata()
{
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

void lihatbuku()
{
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

void ubahdata() {
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char judul[50];
	system("cls");
	printf("\t\t\t\t\t\tMENU EDIT DATA\n\n");
	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");
	printf(" Masukkan Nama Buku Yang Ingin Diubah : ");
	gets(judul);
	while (fread(&d1, sizeof(databuku), 1, fp)) {
		if((strcmp (judul, d1.judul) == 0)) {
			ditemukan = 1;
			printf("\n Masukkan Data Buku Baru \n");
			printf(" Judul Buku\t\t: ");
			fflush(stdin);
			gets(d1.judul);
			printf(" Pengarang\t\t: ");
			gets(d1.pengarang);
			printf(" Genre\t\t\t: ");
			gets(d1.genre);
			printf(" Tanggal Perilisan\t: ");
			gets(d1.tanggal);
			printf(" Rating Umur\t\t: ");
			gets(d1.rating);
			printf(" Halaman Buku\t\t: ");
			gets(d1.halaman);
		}
		fwrite (&d1, sizeof (databuku), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
	if (ditemukan) {
		fp1 = fopen ("ubahdata.txt", "r");
		fp = fopen ("databuku.txt", "w");
		while (fread(&d1, sizeof(databuku), 1, fp1)) {
			fwrite (&d1, sizeof(databuku), 1, fp);
		}
		printf("\n Data Buku Telah Berhasil Diubah!\n");
		printf(" Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
		fclose(fp);
		fclose(fp1);
	} else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
	fclose(fp);
}


void hapusdata() {
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char judul[50];
	system("cls");
	printf("\t\t\t\t\t\tMENU HAPUS DATA\n\n");
	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");
	printf(" Masukkan Nama Buku Yang Ingin Dihapus : ");
	gets(judul);
	while (fread(&d1, sizeof(databuku), 1, fp)) {
		if((strcmp (judul, d1.judul) == 0)) {
			ditemukan = 1;
		} else {
			fwrite (&d1, sizeof (databuku), 1, fp1);
		}
	}
	fclose(fp);
	fclose(fp1);
	if (ditemukan) {
		fp1 = fopen ("ubahdata.txt", "r");
		fp = fopen ("databuku.txt", "w");
		while (fread(&d1, sizeof(databuku), 1, fp1)) {
			fwrite (&d1, sizeof(databuku), 1, fp);
		}
		printf("\n Data Buku Telah Dihapus!\n");
		printf(" Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
		fclose(fp);
		fclose(fp1);
	} else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
	fclose(fp);
}

void judul_asc()
{
	databuku *d, d1;
	FILE *fp;

	fp = fopen ("databuku.txt", "r");
	fseek (fp,0,SEEK_END);

	int n = ftell(fp)/sizeof(databuku);
	
	d = (databuku*) calloc (n, sizeof(databuku));
	rewind(fp);

	for (int i = 0; i < n; i++)
		fread (&d[i], sizeof(databuku), 1, fp);
	
	fp = fopen ("databuku.txt", "w");

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++)
			if((strcmp (d[i].judul, d[j].judul) > 0)) {
				d1   = d[i];
				d[i] = d[j];
				d[j] = d1;			
			}

		fwrite(&d[i],sizeof (databuku),1,fp);
	}
	fclose (fp);
}

void judul_desc()
{
	databuku *d, d1;
	FILE *fp;

	fp = fopen ("databuku.txt", "r");
	fseek (fp,0,SEEK_END);

	int n = ftell(fp)/sizeof(databuku);
	
	d = (databuku*) calloc (n, sizeof(databuku));
	rewind(fp);

	for (int i = 0; i < n; i++)
		fread (&d[i], sizeof(databuku), 1, fp);
	
	fp = fopen ("databuku.txt", "w");

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++)
			if((strcmp (d[i].judul, d[j].judul) < 0)) {
				d1   = d[i];
				d[i] = d[j];
				d[j] = d1;			
			}

		fwrite(&d[i],sizeof (databuku),1,fp);
	}
	fclose (fp);
}

void pengarang_asc()
{
	databuku *d, d1;
	FILE *fp;
	int min;

	fp = fopen ("databuku.txt", "r");
	fseek (fp,0,SEEK_END);

	int n = ftell(fp)/sizeof(databuku);
	
	d = (databuku*) calloc (n, sizeof(databuku));
	rewind(fp);
	
	for (int i = 0; i < n; i++)
		fread (&d[i], sizeof(databuku), 1, fp);
	
	fp = fopen ("databuku.txt", "w");

	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if((strcmp (d[i].pengarang, d[j].pengarang) > 0)) {
				min = j;		
			}

			d1   = d[i];
			d[i] = d[j];
			d[j] = d1;	
		}
		fwrite(&d[i],sizeof (databuku),1,fp);
	}
	fclose (fp);
}

void pengarang_desc()
{
	databuku *d, d1;
	FILE *fp;
	int min;

	fp = fopen ("databuku.txt", "r");
	fseek (fp,0,SEEK_END);

	int n = ftell(fp)/sizeof(databuku);
	
	d = (databuku*) calloc (n, sizeof(databuku));
	rewind(fp);

	for (int i = 0; i < n; i++)
		fread (&d[i], sizeof(databuku), 1, fp);
	
	fp = fopen ("databuku.txt", "w");
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if((strcmp (d[i].pengarang, d[j].pengarang) < 0)) {
				min = j;			
			}

			d1   = d[i];
			d[i] = d[j];
			d[j] = d1;
		}
		fwrite(&d[i],sizeof (databuku),1,fp);
	}
	fclose (fp);
}

void hal_asc()
{
	databuku *d, d1;
	FILE *fp;

	fp = fopen ("databuku.txt", "r");
	fseek (fp,0,SEEK_END);

	int n = ftell(fp)/sizeof(databuku);
	
	d = (databuku*) calloc (n, sizeof(databuku));
	rewind(fp);

	for (int i = 0; i < n; i++)
		fread (&d[i], sizeof(databuku), 1, fp);
	
	fp = fopen ("databuku.txt", "w");

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++)
			if((strcmp (d[i].halaman, d[j].halaman) > 0)) {
				d1   = d[i];
				d[i] = d[j];
				d[j] = d1;			
			}

		fwrite(&d[i],sizeof (databuku),1,fp);
	}
	fclose (fp);
}

void hal_desc()
{
	databuku *d, d1;
	FILE *fp;

	fp = fopen ("databuku.txt", "r");
	fseek (fp,0,SEEK_END);

	int n = ftell(fp)/sizeof(databuku);
	
	d = (databuku*) calloc (n, sizeof(databuku));
	rewind(fp);

	for (int i = 0; i < n; i++)
		fread (&d[i], sizeof(databuku), 1, fp);
	
	fp = fopen ("databuku.txt", "w");

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++)
			if((strcmp (d[i].halaman, d[j].halaman) < 0)) {
				d1   = d[i];
				d[i] = d[j];
				d[j] = d1;			
			}

		fwrite(&d[i],sizeof (databuku),1,fp);
	}
	fclose (fp);
}

void tampilcari()
{
	databuku d1;
	FILE *fp;
	int j = 0;

	printf("\n\t\t\t\t\t\tHASIL PENCARIAN\n");

	fp = fopen ("ubahdata.txt", "r");

	while (fread(&d1, sizeof(databuku),1,fp)) {
		printf(" Data Buku Ke - %i\n",j+1);
		printf(" ------------------------------------\n");
		printf(" Judul Buku\t\t: %s\n",d1.judul);
		printf(" Sutradara\t\t: %s\n",d1.pengarang);
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

void carijudul()
{
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char judul[50];

	system("cls");
	printf("\t\t\t\t\t\tMENU CARI BUKU BERDASARKAN JUDUL\n\n");

	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");

	printf(" Masukkan Nama Buku Yang Ingin Dicari : ");
	gets(judul);

	while (fread(&d1, sizeof(databuku), 1, fp))
		if((strcmp (judul, d1.judul) == 0)) {
			ditemukan = 1;
			fwrite (&d1, sizeof (databuku), 1, fp1);
		}

	fclose(fp1);

	if (ditemukan)
		tampilcari();
	else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}

	fclose(fp);
}

void caripengarang()
{
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char sutra[50];

	system("cls");
	printf("\t\t\t\t\t\tMENU CARI Buku BERDASARKAN PENGARANG\n\n");

	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");

	printf(" Masukkan Nama Pengarang Buku Yang Ingin Dicari : ");
	gets(sutra);

	while (fread(&d1, sizeof(databuku), 1, fp))
		if((strcmp (sutra, d1.pengarang) == 0)) {
			ditemukan = 1;
			fwrite (&d1, sizeof (databuku), 1, fp1);
		}
	
	fclose(fp1);
	
	if (ditemukan)
		tampilcari();
	else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}

	fclose(fp);
}

void carigenre(){
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char genre[50];

	system("cls");
	printf("\t\t\t\t\t\tMENU CARI BUKU BERDASARKAN GENRE\n\n");

	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");

	printf(" Masukkan Genre Buku Yang Ingin Dicari : ");
	gets(genre);

	while (fread(&d1, sizeof(databuku), 1, fp))
		if((strcmp (genre, d1.genre) == 0)) {
			ditemukan = 1;
			fwrite (&d1, sizeof (databuku), 1, fp1);
		}
	
	fclose(fp1);

	if (ditemukan)
		tampilcari();
	else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}

	fclose(fp);
}

void caritanggal()
{
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char tanggal[20];

	system("cls");
	printf("\t\t\t\t\t\tMENU CARI BUKU BERDASARKAN TANGGAL PERILISAN\n\n");

	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");

	printf(" Masukkan Tanggal Perilisan Buku Yang Ingin Dicari : ");
	gets(tanggal);

	while (fread(&d1, sizeof(databuku), 1, fp))
		if((strcmp (tanggal, d1.tanggal) == 0)) {
			ditemukan = 1;
			fwrite (&d1, sizeof (databuku), 1, fp1);
		}
	
	fclose(fp1);

	if (ditemukan)
		tampilcari();
	else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
	
	fclose(fp);
}

void carihalaman()
{
	databuku d1;
	FILE *fp, *fp1;
	int ditemukan = 0;
	char halaman[50];

	system("cls");
	printf("\t\t\t\t\t\tMENU CARI BUKU BERDASARKAN HALAMANNYA\n\n");

	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("ubahdata.txt", "w");

	printf(" Masukkan Halaman Buku Yang Ingin Dicari : ");
	gets(halaman);

	while (fread(&d1, sizeof(databuku), 1, fp))
		if((strcmp (halaman, d1.halaman) == 0)) {
			ditemukan = 1;
			fwrite (&d1, sizeof (databuku), 1, fp1);
		}
	
	fclose(fp1);

	if (ditemukan)
		tampilcari();
	else {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}

	fclose(fp);
}

void menucari()
{
	do {
		system("cls");
		printf("\t\t\t\t\t\tMENU SEARCHING DATA\n\n");
		puts("\n  Pilih Menu Dibawah Ini Untuk Menentukan Metode Pencarian");
		puts("   1.  Cari Berdasarkan Judul Buku");
	    puts("   2.  Cari Berdasarkan Nama Pengarang");
	    puts("   3.  Cari Berdasarkan Genre Buku");
	    puts("   4.  Cari Berdasarkan Tanggal Perilisan");
	    puts("   5.  Cari Berdasarkan Halaman Buku");
	    puts("   0.  Kembali Ke Menu Awal");

		switch(getch()){
			case '1' : carijudul();
	        	break;
	        case '2' : caripengarang();
	        	break;
	        case '3' : carigenre();
	        	break;
	        case '4' : caritanggal();
	        	break;
	        case '5' : carihalaman();
	        	break;
	        case '0' : goto awal;
	        	break;
		}	
	}
	while(getch()!=27);
	awal:;
}

void menuurut()
{
	system("cls");
	printf("\t\t\t\t\t\tMENU URUT DATA\n");
	puts("\n Pilih Menu Dibawah Ini Untuk Menentukan Metode Pengurutan");
	puts("  a.  Urut Berdasarkan Judul Buku (Ascending)");
    puts("  b.  Urut Berdasarkan Judul Buku (Descending)");
    puts("  c.  Urut Berdasarkan Nama pengarangdara (Ascending)");
    puts("  d.  Urut Berdasarkan Nama Pengarang (Descending)");
    puts("  e.  Urut Berdasarkan halaman Buku (Ascending)");
    puts("  f.  Urut Berdasarkan Halaman Buku (Descending)");
    garis(120);

    switch(getch()){
		case 'a' :
			judul_asc();
			printf(" Menu Pilihan  : Urut Berdasarkan Judul Buku (Ascending)");
        	printf("\n Data Telah Berhasil Diurutkan!");
        	printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        	printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        	break;
        case 'b' :
			judul_desc();
        	printf(" Menu Pilihan  : Urut Berdasarkan Judul Buku (Descending)");
        	printf("\n Data Telah Berhasil Diurutkan!");
        	printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        	printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        	break;
        case 'c' :
			pengarang_asc();
        	printf(" Menu Pilihan  : Urut Berdasarkan Nama Pengarang (Ascending)");
        	printf("\n Data Telah Berhasil Diurutkan!");
        	printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        	printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        	break;
        case 'd' :
			pengarang_desc();
        	printf(" Menu Pilihan  : Urut Berdasarkan Nama Pengarang (Descending)");
        	printf("\n Data Telah Berhasil Diurutkan!");
        	printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        	printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        	break;
        case 'e' :
			hal_asc();
        	printf(" Menu Pilihan  : Urut Berdasarkan Halaman Buku (Ascending)");
        	printf("\n Data Telah Berhasil Diurutkan!");
        	printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        	printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        	break;
        case 'f' :
			hal_desc();
        	printf(" Menu Pilihan  : Urut Berdasarkan Halaman Buku (Descending)");
        	printf("\n Data Telah Berhasil Diurutkan!");
        	printf("\n Silahkan Klik Menu Tampilkan Data Untuk Melihat Hasilnya.");
        	printf("\n Tekan ENTER untuk kembali ke Menu Utama.");
        	break;
    }
}

void tambahnilai() {
	databuku d1;
	penilaian n1;
	FILE *fp, *fp1;
	int i, j, ditemukan = 0;
	system("cls");
	printf("\t\t\t\t\t\tMENU TAMBAH PENILAIAN\n\n");
	fp = fopen ("databuku.txt", "r");
	fp1 = fopen ("datapenilaian.txt", "a");
	fflush(stdin);
	printf(" Masukkan Nama Buku Yang Ingin Dinilai : ");
	gets(n1.judul_bk);

	while (fread(&d1, sizeof(databuku), 1, fp)) {
		if((strcmp (n1.judul_bk, d1.judul) == 0)) {
			n1.total = 0;
			n1.rata = 0;
			ditemukan = 1;
			printf("\n Nama Penilai\t\t: ");
			fflush(stdin);
			gets(n1.namap);
			printf(" Pekerjaan\t\t: ");
			gets(n1.pekerjaan);
			printf("\n Berikan Nilai Dengan Skala 1-10!\n\n");
			for (j = 0; j < 10; j++) {
				printf (" %s\n", jumlah[j].teks);
				printf(" Jawaban Anda : ");
				fflush(stdin);
				scanf ("%i", &n1.menilai[j].nilai);
				n1.total += n1.menilai[j].nilai;
			}
			n1.rata = n1.total / 10.0;
			fwrite (&n1, sizeof (penilaian), 1, fp1);
		}	
	}
	if (!ditemukan) {
		printf("\n Data Buku Tidak Ditemukan!\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	} else {
		printf(" \n\n Data Buku Telah Disimpan.\n");
		printf(" Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
	fclose(fp);
	fclose (fp1);
}

void tampilnilai() {
	penilaian n1;
	FILE *fp;
	int j = 0;
	system("cls");
	printf("\t\t\t\t\t\tMENU TAMPILKAN PENILAIAN\n\n");
	fp = fopen ("datapenilaian.txt", "r");
	while (fread(&n1, sizeof(penilaian),1,fp)) {
		printf(" Data Penilaian Ke - %i\n",j+1);
		printf(" ------------------------------------\n");
		printf(" Buku Yang Dinilai\t: %s\n",n1.judul_bk);
		printf(" Nama Penilai\t\t: %s\n",n1.namap);
		printf(" Pekerjaan\t\t: %s\n",n1.pekerjaan);
		printf(" Nilai\t\t\t: %.2f\n",n1.rata);
		printf("\n");
		j++;
	}
	fclose(fp);
	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
}

void menunilai() {
	do {
		system("cls");
		printf("\t\t\t\t\t\tMENU PENILAIAN PENGGUNA\n\n");
		puts("\n  Pilih Menu Dibawah Ini Untuk Melakukan Penilaian");
		puts("   1.  Tambahkan Penilaian");
	    puts("   2.  Tampilkan Penilaian");
	    puts("   3.  Hapus Penilaian");
	    puts("  00.  Kembali Ke Menu Awal");
		switch(getch()){
			case '1' : tambahnilai();
	        break;
	        case '2' : tampilnilai();
	        break;
	        case '3' : 
	        break;
	        case '0' : goto awal;
	        break;
		}	
	}
	while(getch()!=27);
	awal:;
}

int main(int argc, char *argv[]){
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

		switch (getch()){
			case '1' :// Tambah Buku
				tambahdata();
				break;
			case '2' :// Lihat Buku
				lihatbuku();
				break;
			case '3' :// Ubah Buku
				ubahdata();
				break;
			case '4' :// Hapus Buku
				hapusdata();
				break;
			case '5' :// Urutkan Buku
				menuurut();
				break;
			case '6' :// Cari Buku
				menucari();
				break;
			case '7' :// Penilaian Buku
				menunilai();
				break;
		}
	} while (getch()!= 27);
}
