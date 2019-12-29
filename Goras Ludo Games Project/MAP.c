#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

//prototype
void fullScreen();
void gotoxy(int x, int y);
void setcolor(unsigned short color);
void showDadu(short angka);

//struct
struct player {
	char nama[10];
	int p_x;
	int p_y;
	int pa_x;
	int pa_y;
	char *symbol;
}user,botq,botk,botf;

/* ============= VARIABLE GLOBAL =============*/


/* ============= MODULE =============*/
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

void playerStartPoint() {//player-start point
	gotoxy(25,12);printf("%s1",user.symbol);
	gotoxy(34,12);printf("%s2",user.symbol);
	gotoxy(25,16);printf("%s3",user.symbol);
	gotoxy(34,16);printf("%s4",user.symbol);
	
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

void printMap() {
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
}

/*=============== Random Dadu ===============*/
int randomDadu(){
	int angkaDadu,i;
	srand(time(NULL));
	
	gotoxy(127,25);printf("TEKAN ENTER UNTUK MERANDOM");
	gotoxy(127,26);printf("----------------------------");
	gotoxy(140,25);getch();
	for(i=0;i<10;i++){
		gotoxy(127,25);printf("DADU KAMU SEDANG DI RANDOM");
		gotoxy(127,26);printf("----------------------------");
		angkaDadu = (rand()%6)+1;
		showDadu(angkaDadu);Sleep(200);
	}
	for(i=0; i<10; i++){
		setcolor(15);gotoxy(128,38);printf("KAMU MENDAPAT ANGKA DADU %d",angkaDadu);Sleep(100);
		setcolor(9);gotoxy(128,38);printf("KAMU MENDAPAT ANGKA DADU %d",angkaDadu);Sleep(100);
	}
	return (angkaDadu);
}

void gamePlay() {
	printf("program : goras.exe; description : ludo games; author :  mochamad nauval dwisatya & laras; version/date : 1 / 22.12.2019; compiler : dev c++; jtk polban 2019.\n  ");
	user.symbol = "X";
	botq.namabot = "QuickBot";
	botk.namabot = "KillerBot";
	botf.namabot = "FlowBot";
	setcolor(10);
	printMap();
	//goras
	gotoxy(37,40);printf("GORAS 2019 - Gopel & Laras");
	
	//show player pion at homebase
	playerStartPoint();
	
	setcolor(9);
	
	//playername
	gotoxy(25,9);printf("%s",user.nama);
	gotoxy(61,9);printf("KILLER-BOT");
	gotoxy(25,38);printf("COLLECTOR-BOT");
	gotoxy(61,38);printf("FLOW-BOT");
	
	//firstbox
	gotoxy(29,21);printf("%s1",user.symbol);
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
	bool gameIsOver = false;
	ta = 29;
	gb = 21;
	int turn=1;
	botq.symbol = "Q";
	botk.symbol = "K";
	botf.symbol = "F";
	user.p_x = 29;
	user.p_y = 21;
	botk.p_x = 53;
	botk.p_y = 13;
	botq.p_x = 69;
	botq.p_y = 25;
	botf.p_x = 45;
	botf.p_y = 33;
	char *bidak;
	char *whos;
		
	while (!gameIsOver) {
		if (turn==1) {
			bidak = user.symbol;
			whos = user.nama;
			ta = user.p_x;
			gb = user.p_y;
		}
		if (turn==2) {
			bidak = botk.symbol;
			whos = botk.nama;
			ta = botk.p_x;
			gb = botk.p_y;
		}
		if (turn==3) {
			bidak = botq.symbol;
			whos = botq.nama;
			ta = botq.p_x;
			gb = botq.p_y;
		}
		if (turn==4) {
			bidak = botf.symbol;
			whos = botf.nama;
			ta = botf.p_x;
			gb = botf.p_y;
		}	
		gotoxy(43,4);printf("================");
		gotoxy(43,5);printf("%s TURN",whos);
		gotoxy(43,6);printf("================");
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
			gotoxy(ta,gb);printf("%s1",bidak);
			Sleep(800);
			if (turn==1) {
				user.p_x = ta;
				user.p_y = gb;
			}
			if (turn==2) {
				botk.p_x = ta;
				botk.p_y = gb;
			}
			if (turn==3) {
				botq.p_x = ta;
				botq.p_y = gb;
			}
			if (turn==4) {
				botf.p_x = ta;
				botf.p_y = gb;
			}
			gotoxy(130,4);printf("X = %d",ta);
			gotoxy(130,5);printf("Y = %d",gb);
		}
		turn+=1;
		if(turn == 5){
			turn = 1;
		}
	}
}

int main() {
	fullScreen();
	printf("your name : ");
	scanf("%s",&user.nama);
	system("cls");
	gamePlay();
	system("exit");
}
