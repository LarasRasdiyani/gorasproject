#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

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
void printMap() {
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
}

/*=============== START POINT ===============*/
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

/*=============== Check Game Over ===============*/
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
	printf("program : goras.exe; description : ludo games; author :  mochamad nauval dwisatya & laras; version/date : 1 / 22.12.2019; compiler : dev c++; jtk polban 2019.\n  ");
	
	setcolor(10);
	printMap();
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
	
	/* =========== GAMEPLAY ===========*/
	srand (time(NULL));
	int r,i;
	int gp,gb,ta,tg;
	bool gameIsNotOver = false;
	ta = 29;
	gb = 21;
	
	while (!gameIsNotOver) {
		gotoxy(108,25);printf("Roll The Dice!");
		gotoxy(122,25);getch();
		for (i=0; i<10; i++) {
			gotoxy(108,25);printf("Dice Rolling! ");
			r = rand() % 7;
			showDadu(r);
			gotoxy(115,37);printf("%d",r);
			Sleep(300);
		}
		for (i=0; i<10; i++) {
			setcolor(15);gotoxy(107,38);printf("YOU GOT %d",r);
			Sleep(100);
			setcolor(9);gotoxy(107,38);printf("YOU GOT %d",r);
			Sleep(100);
		}
		//gotoxy(122,25);getch();
		//r = 50;
		Sleep(1000);
		int btsB,btsP;
		btsB = 21;
		btsP = 29;
		for (i=0; i<r; i++) { //DONE
			bool udah = false;
			gotoxy(ta,gb);printf("  ");
			if (gb==21 && ta<41 && !udah) {
				ta = ta + 4;
				udah = true;
			}
			if (ta==41 && gb==21 && !udah) {
				ta = ta+4;
				gb = gb-2;
				udah = true;
			}
			if (ta==45 && gb>9 && gb<=21 && !udah) {
				gb = gb-2;
				udah = true;
			}
			if(ta<53 && gb==9 && !udah) {
				ta = ta + 4;
				udah = true;
			}
			if(ta==53 && gb<19 && !udah) {
				gb = gb + 2;
				udah = true;
			}
			if(ta==53 && gb==19 && !udah) {
				gb = gb + 2;
				ta = 53 + 4;
				udah = true;
			}
			if(ta<77 && gb==21 && !udah) {
				ta = ta + 4;
				udah = true;
			}
			if(ta==77 && gb<25 && !udah) {
				gb = gb + 2;
				udah = true;
			}
			if(ta>57 && gb==25 && !udah) {
				ta = ta - 4;
				udah = true;
			}
			if(ta==57 && gb==25 && !udah) {
				ta = ta - 4;
				gb = gb + 2;
				udah = true;
			}
			if(ta==53 && gb<37 && !udah) {
				gb = gb+2;
				udah = true;
			}
			if(ta>45 && gb==37 && !udah) {
				ta = ta-4;
				udah = true;
			}
			if(ta==45 && gb>27 && !udah) {
				gb = gb - 2;
				udah = true;
			}
			if(ta==45 && gb==27 && !udah) {
				gb = gb - 2;
				ta = ta - 4;
				udah = true;
			}
			if(ta>21 && gb==25 && !udah) {
				ta = ta - 4;
				udah = true;
			}
			if(ta==21 && gb>21 && !udah) {
				gb = gb-2;
				udah = true;
			}
			if(ta<33 && gb==21 && !udah) {
				ta = ta + 4;
				udah = true;
			}
			gotoxy(ta,gb);printf("X1");
			Sleep(800);
			gotoxy(130,4);printf("X = %d",ta);
			gotoxy(130,5);printf("Y = %d",gb);
		}
	}
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
