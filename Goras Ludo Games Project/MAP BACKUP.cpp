#include <stdio.h>
#include <windows.h>

//prototype
void fullScreen();
void gotoxy(int x, int y);
void setcolor(unsigned short color);

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

void setcolor(unsigned short color) { 
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
} // Merubah Warna Teks Pada C++ https://49012032sehatsempurna.wordpress.com/2012/04/06/merubah-warna-teks-pada-c/

void playerStartPoint() {//player-start point
	gotoxy(25,12);printf("X1");
	gotoxy(34,12);printf("X2");
	gotoxy(25,16);printf("X3");
	gotoxy(34,16);printf("X4");
	
	gotoxy(25,30);printf("C1");
	gotoxy(34,30);printf("C2");
	gotoxy(25,34);printf("C3");
	gotoxy(34,34);printf("C4");
	
	gotoxy(61,12);printf("K1");
	gotoxy(70,12);printf("K2");
	gotoxy(61,16);printf("K3");
	gotoxy(70,16);printf("K4");
		
	gotoxy(61,30);printf("F1");
	gotoxy(70,30);printf("F2");
	gotoxy(61,34);printf("F3");
	gotoxy(70,34);printf("F4");
}

void gamePlay() {
	printf("program : goras.exe; description : ludo games; author :  mochamad nauval dwisatya & laras; version/date : 1 / 22.12.2019; compiler : dev c++; jtk polban 2019.\n  ");
	
	setcolor(10);
	/* ========= MAP BESAR ========= */
	//declare
	FILE *FPRead;
	char temporary[200];
	
	//openfile
	int i = 8;
	
	FPRead=fopen("MAPexp.txt","r");
	while(fgets(temporary,sizeof(temporary),FPRead)) {
		gotoxy(20,i);printf("%s",temporary);
		i++;
	} fclose(FPRead);
	
	//goras
	gotoxy(37,40);printf("GORAS 2019 - Gopel & Laras");
	
	//show player pion at homebase
	playerStartPoint();
	
	setcolor(9);
	gotoxy(43,4);printf("================");
	gotoxy(43,5);printf("LARAS TURN");
	gotoxy(43,6);printf("================");
	
	//playername
	gotoxy(25,9);printf("USER");
	gotoxy(61,9);printf("KILLER-BOT");
	gotoxy(25,38);printf("COLLECTOR-BOT");
	gotoxy(61,38);printf("FLOW-BOT");
	
	//firstbox
	gotoxy(29,21);printf("X1");
	gotoxy(53,13);printf("K1");
	gotoxy(69,25);printf("C1");
	gotoxy(45,33);printf("F1");
	
	//finish
	gotoxy(49,26);printf("X X");
	gotoxy(49,25);printf("X X");
	
	//dadu
	gotoxy(108,25);printf("Roll The Dice!");
	gotoxy(107,26);printf("----------------");
	//gotoxy(122,25);getche();
	gotoxy(103,27);printf(" _______________________");
	gotoxy(103,28);printf("|                       |");
	gotoxy(103,29);printf("|                       |");
	gotoxy(103,30);printf("|                       |");
	gotoxy(103,31);printf("|                       |");
	gotoxy(103,32);printf("|                       |");
	gotoxy(103,33);printf("|                       |");
	gotoxy(103,34);printf("|                       |");
	gotoxy(103,35);printf("|                       |");
	gotoxy(103,36);printf("|_______________________|");
}

int main() {
	fullScreen();
	gamePlay();
	getch();
	system("exit");
}
