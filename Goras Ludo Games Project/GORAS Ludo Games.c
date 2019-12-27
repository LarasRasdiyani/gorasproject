#include <stdio.h>
#include <windows.h>

//PROTOTYPE
void fullScreen();
void gotoxy();
void gamePlay();
void pickPlayer();
void instruction();
void credits();
void header();
void intro();
void mainMenu();
void isGameOver();

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

/*=============== KOCOK DADU ===============*/
void showDadu(short angka) {
		switch(angka) {
		case 0 :
		gotoxy(40,19);printf(" _______________________");
		gotoxy(40,20);printf("|                       |");
		gotoxy(40,21);printf("|                       |");
		gotoxy(40,22);printf("|                       |");
		gotoxy(40,23);printf("|                       |");
		gotoxy(40,24);printf("|                       |");
		gotoxy(40,25);printf("|                       |");
		gotoxy(40,26);printf("|                       |");
		gotoxy(40,27);printf("|                       |");
		gotoxy(40,28);printf("|_______________________|");
		break;
		case 1 :
		gotoxy(40,19);printf(" _______________________");
		gotoxy(40,20);printf("|                       |");
		gotoxy(40,21);printf("|                       |");
		gotoxy(40,22);printf("|                       |");
		gotoxy(40,23);printf("|                       |");
		gotoxy(40,24);printf("|           O           |");
		gotoxy(40,25);printf("|                       |");
		gotoxy(40,26);printf("|                       |");
		gotoxy(40,27);printf("|                       |");
		gotoxy(40,28);printf("|_______________________|");
		break;
		case 2 :
		gotoxy(40,19);printf(" _______________________");
		gotoxy(40,20);printf("|                       |");
		gotoxy(40,21);printf("|                       |");
		gotoxy(40,22);printf("|                O      |");
		gotoxy(40,23);printf("|                       |");
		gotoxy(40,24);printf("|                       |");
		gotoxy(40,25);printf("|                       |");
		gotoxy(40,26);printf("|      O                |");
		gotoxy(40,27);printf("|                       |");
		gotoxy(40,28);printf("|_______________________|");
		break;
		case 3 :
		gotoxy(40,19);printf(" _______________________");
		gotoxy(40,20);printf("|                       |");
		gotoxy(40,21);printf("|                       |");
		gotoxy(40,22);printf("|      O                |");
		gotoxy(40,23);printf("|                       |");
		gotoxy(40,24);printf("|           O           |");
		gotoxy(40,25);printf("|                       |");
		gotoxy(40,26);printf("|                O      |");
		gotoxy(40,27);printf("|                       |");
		gotoxy(40,28);printf("|_______________________|");
		break;
		case 4 :
		gotoxy(40,19);printf(" _______________________");
		gotoxy(40,20);printf("|                       |");
		gotoxy(40,21);printf("|                       |");
		gotoxy(40,22);printf("|      O         O      |");
		gotoxy(40,23);printf("|                       |");
		gotoxy(40,24);printf("|                       |");
		gotoxy(40,25);printf("|                       |");
		gotoxy(40,26);printf("|      O         O      |");
		gotoxy(40,27);printf("|                       |");
		gotoxy(40,28);printf("|_______________________|");
		break;
		case 5 :
		gotoxy(40,19);printf(" _______________________");
		gotoxy(40,20);printf("|                       |");
		gotoxy(40,21);printf("|                       |");
		gotoxy(40,22);printf("|      O         O      |");
		gotoxy(40,23);printf("|                       |");
		gotoxy(40,24);printf("|           O           |");
		gotoxy(40,25);printf("|                       |");
		gotoxy(40,26);printf("|      O         O      |");
		gotoxy(40,27);printf("|                       |");
		gotoxy(40,28);printf("|_______________________|");
		break;
		case 6 :
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
		break;
	}
} //end kocokdadu

/*=============== Header Goras ===============*/
void header() { //show the big text of GORAS
	system("cls");
	//declare
	FILE *FPread;
	char temp[200];
	
	//openfile
	FPread=fopen("header.dat","r");
	while(fgets(temp,sizeof(temp),FPread)) {
		printf("%s",temp);
	}fclose(FPread);
} //end header

/*=============== INTRO ===============*/
void intro() { //showing the welcome words
	//Declare
	int i,j;
	int len;
	char wlc[50] = {"WELCOME TO GORAS LUDO GAMES!!!"};
	char line[50] = {"=============================="};
	
	//loop
	gotoxy(68,24);
	len = strlen(line);
	for(i=0; i<len; i++) {
		putchar(line[i]);
		Sleep(30);
	}
	
	gotoxy(68,25);
	len = strlen(wlc);
	for(i=0;i<len;i++) {
		putchar(wlc[i]);
		Sleep(70); 
	}
	
	gotoxy(68,26);
	len = strlen(line);
	for(i=0; i<len; i++) {
		putchar(line[i]);
		Sleep(30);
	}
	printf("\n");
	gotoxy(68,28);system("PAUSE");
} //end intro

/*=============== MAP =============== */
void mapBesar() { //show the map
	system("cls");
	FILE *FPRead;
	char temporary[200];
	FPRead=fopen("MAP.txt","r");
	while(fgets(temporary,sizeof(temporary),FPRead)) {
		printf("%s",temporary);
	} fclose(FPRead);	
	gotoxy(20,30);system("pause");
	system("exit");
}

/*================ Check Game Over ================*/
void isGameOver() {
	int i = 0;
	while (i == 0) {
		
		gotoxy(4,6);setcolor(12);printf("    GAME OVER   ");
		Sleep(500);
		gotoxy(4,6);setcolor(10);printf("    GAME OVER   ");
		Sleep(500);	
		gotoxy(4,6);setcolor(9);printf("    GAME OVER   ");
		Sleep(500);	
		gotoxy(4,6);setcolor(14);printf("    GAME OVER   ");
		Sleep(500);	
	}
}

/*=============== MAIN MENU ===============*/
void mainMenu() { //main menu
	//Declare
	int input;
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
	gotoxy(65,34);printf("Insert number where u want to go = ");scanf("%d", &input);
	if (input==1 || input==2 || input==3 || input==4 || input==5) {
		if (input==1) {
			system("CLS");
			pickPlayer();
		}
		if (input==2) {
			system("CLS");
			instruction();
		}
		if (input==3) {
			system("CLS");
			credits();
		}
		if (input==4) {
			exit(1);
		}
		if (input==5) {
			mapBesar();
		}
	}
} //end main menu

/*=============== Pick Player ===============*/
void pickPlayer() { //how many player
	header();
	
	int input;
	
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
	gotoxy(73,21);printf("Jumlah Pemain");
	gotoxy(73,22);printf("====================");
	gotoxy(73,24);printf("(1) 2 Pemain");
	gotoxy(73,25);printf("(2) 3 Pemain");
	gotoxy(73,26);printf("(3) 4 Pemain");
	gotoxy(73,27);printf("(4) Kembali ke menu");
	gotoxy(73,28);printf("(5) Keluar dari permainan");
	gotoxy(65,33);printf("Masukan angka yang ingin dituju = ");scanf("%d", &input);
	if (input==1 || input==2 || input==3 || input==4 || input==5) {
		if (input==1) {
			system("CLS");
			gamePlay();
		}
		if (input==2) {
			system("CLS");
			instruction();
		}
		if (input==3) {
			system("CLS");
			credits();
		}
		if (input==4) {
			system("CLS");
			header();
			mainMenu();
		}
		if (input==5) {
			system("exit");
		}
	}

}

/*=============== in Game ===============*/
void gamePlay() { //main game
	header();
	gotoxy(20,20);printf("kaleum acan");
} //end inGame

/*=============== Instruction ===============*/
void instruction() { //instruction page
	system("CLS");
	header(); 
	FILE *FPRead;
	char Temporary[200];
	short i=16;
	FPRead=fopen("instruction.txt","r");
	while(fgets(Temporary,sizeof(Temporary),FPRead)){
		gotoxy(1,i);
		printf("%s",Temporary);
		i++;
	}
	fclose(FPRead);
	
	system("pause");
	system("cls");
	header();
	mainMenu();
} //end instruction

/*=============== Credits ===============*/
void credits() { //credits main
	printf("credits");
}

/*=============== Main Control Page ===============*/
int main() {
	fullScreen(); //call fullscreen module
	header(); //header module
	intro(); //intro module
	
	system("cls"); //clear console
	header();
	mainMenu(); //main menu module
	return 0;
}
//ENDDDD
