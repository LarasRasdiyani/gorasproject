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
	setcolor(10);
	printMap();
	//goras
	gotoxy(37,40);printf("GORAS 2019 - Gopel & Laras");
	
	//show player pion at homebase
	playerStartPoint();
	
	setcolor(9);
	gotoxy(43,4);printf("================");
	gotoxy(43,5);printf("%s TURN",user.nama);
	gotoxy(43,6);printf("================");
	
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
	
	/* =========== GAMEPLAY ===========*/
	srand (time(NULL));
	int r,i;
	int gp,gb,ta,tg;
	bool gameIsOver = false;
	ta = 29;
	gb = 21;
	
	while (!gameIsOver) {
		/*giliran = cek_player();
		while (!giliranUdah) {
			giliran = true;
		}*/
		int angkaDadu = 0;
		angkaDadu = randomDadu();
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
			gotoxy(ta,gb);printf("%s1",user.symbol);
			Sleep(800);
			gotoxy(130,4);printf("X = %d",ta);
			gotoxy(130,5);printf("Y = %d",gb);
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
