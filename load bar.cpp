#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <iostream>

using namespace std;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void loadbar()
{
	int bar1=177, bar2=219;
	cout<<"Loading...\n";
  cout<<"\n\t\t\t\t\t\t";
  for(int i=0; i<25; i++)
	  cout<< (char)bar1;
	  
	cout<<"\r";
	cout<<"\t\t\t\t\t\t";
  	for(int i=0; i<25; i++)
  	{
  		
  		cout<< (char)bar2;
		Sleep(150);	  
		  }
		  
	cout<<"\n\t\t\t\t\t\t";
	system("pause");
}
    
int main(){
  system("color 74");
  system("cls");
  gotoxy(48,11);
	loadbar();
	system("cls");
}