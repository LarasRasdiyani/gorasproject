#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

void fullScreen() { //make console fullscreen
	keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
} //this source by Raigne in This is how to get your program to fullscreen (cboard.cprogramming.com).

void gotoxy(int x, int y) { //module for change position object
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
} //source by Duthomhas in SetConsoleCursorPosition Function (cplusplus.com).

int main(){
	fullScreen();
	
	//Declare
	int input;
	bool go = false;
	
	gotoxy(100,19);printf(" _______________________");
	gotoxy(100,20);printf("|                       |");
	gotoxy(100,21);printf("|                       |");
	gotoxy(100,22);printf("|      O         O      |");
	gotoxy(100,23);printf("|                       |");
	gotoxy(100,24);printf("|      O         O      |");
	gotoxy(100,25);printf("|                       |");
	gotoxy(100,26);printf("|      O         O      |");
	gotoxy(100,27);printf("|                       |");
	gotoxy(100,28);printf("|_______________________|");
	gotoxy(40,19);printf(" _______________________");
	gotoxy(40,20);printf("|                       |");
	gotoxy(40,21);printf("|                       |");
	gotoxy(40,22);printf("|      O         O      |");
	gotoxy(40,23);printf("|                       |");
	gotoxy(40,24);printf("|      O         O      |");
	gotoxy(40,25);printf("|                       |");
	gotoxy(40,26);printf("|      O         O      |");
	gotoxy(40,27);printf("|                       |");
	gotoxy(40,28);printf("|_______________________|");
	gotoxy(73,20);printf("====================");
	gotoxy(73,21);printf("Main Menu");
	gotoxy(73,22);printf("====================");
	gotoxy(73,24);printf("(1) Start Game");
	gotoxy(73,25);printf("(2) Instruction");
	gotoxy(73,26);printf("(3) Credits");
	gotoxy(73,27);printf("(4) Exit Game");
	gotoxy(73,28);printf("(5) Lihat Map");
	while (!go) {
		gotoxy(65,34);printf("Insert number where u want to go = ");scanf("%d", &input);
		if (input>4 || input<1 || input == 0 || !input) {
			gotoxy(100,34);printf("                                      ");
			gotoxy(76,35);printf("Wrong Number");
		} else {
			if (input==1 || input==2 || input==3 || input==4 || input==5) {
				if (input==1) {
					system("CLS");
					printf("c");
					go = true;
				}
				if (input==2) {
					system("CLS");
					printf("c");
					go = true;
				}
				if (input==3) {
					system("CLS");
					printf("c");
					go = true;
				}
				if (input==4) {
					go = true;
					exit(1);
				}
				if (input==5) {
					printf("c");
				}
			}
		}

	}
	return 0;
}
