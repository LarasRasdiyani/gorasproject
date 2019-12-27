#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void showDadu (short angka);

void fullScreen() { //make console fullscreen
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
} //this source by Raigne in This is how to get your program to fullscreen (cboard.cprogramming.com).

void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
} //source by Duthomhas in SetConsoleCursorPosition Function (cplusplus.com)

void showDadu(short angka) {
		switch(angka) {
		case 0 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|                       |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|           O           |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|                       |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
		case 1 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|                       |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|           O           |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|                       |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
		case 2 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|                O      |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|                       |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|      O                |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
		case 3 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|      O                |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|           O           |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|                O      |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
		case 4 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|      O         O      |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|                       |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|      O         O      |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
		case 5 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|      O         O      |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|           O           |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|      O         O      |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
		case 6 :
		gotoxy(103,27);printf(" _______________________");
		gotoxy(103,28);printf("|                       |");
		gotoxy(103,29);printf("|                       |");
		gotoxy(103,30);printf("|      O         O      |");
		gotoxy(103,31);printf("|                       |");
		gotoxy(103,32);printf("|      O         O      |");
		gotoxy(103,33);printf("|                       |");
		gotoxy(103,34);printf("|      O         O      |");
		gotoxy(103,35);printf("|                       |");
		gotoxy(103,36);printf("|_______________________|");
		break;
	}
}

int main() {
	fullScreen();
	srand (time(NULL));
	int r;
	int i;
	
	for (i=0; i<15; i++) {
		getch();
		for (i=0; i<11; i++) {
			r = rand() % 7;
			showDadu(r);
			gotoxy(0,0);
			printf("%d",r);
			Sleep(300);
		}
	}

	system("pause");
    return 0;
}
