#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

void gotoxy();

void gotoxy(int x, int y){ //module for change position object
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
} //source by Duthomhas in SetConsoleCursorPosition Function (cplusplus.com)

int main() {
	//deklarasi
	int j,i,k;
	int jalan[100];
	int rute;
	
	gotoxy(0,0);printf(" ___________ ");
	gotoxy(0,1);printf("|   |   |   |");
	gotoxy(0,2);printf("|___|___|___|");
	gotoxy(0,3);printf("|   |   |   |");
	gotoxy(0,4);printf("|___|___|___|");
	gotoxy(0,5);printf("|   |   |   |");
	gotoxy(0,6);printf("|___|___|___|");
	gotoxy(0,7);printf("|   |   |   |");
	gotoxy(0,8);printf("|___|___|___|");
	gotoxy(0,9);printf("|   |   |   |");
	gotoxy(0,10);printf("|___|___|___|");
	
	//masukan array
	for(i = 0; i < 100; i++) {
		jalan[i] = i;
		}
	
	
	
	// TOS JADIIIII!
	/*j = 1;
	k = 1;
	for (i = 0; i <= 4-1; i++) {
		j = j + 2;
		gotoxy(2,j-2);printf(" ");
		Sleep(50);
		gotoxy(2,j);printf("X");
		Sleep(450);
	}
	gotoxy(15,15);printf("pressshit\n");
	system("PAUSE");*/
	
	/*for (i = 0; i < 10; i++) {
		gotoxy(1,i-1);printf(" ");
		gotoxy(1,i);printf("X");
		Sleep(250);
	}*/
	
	return 0;
}

