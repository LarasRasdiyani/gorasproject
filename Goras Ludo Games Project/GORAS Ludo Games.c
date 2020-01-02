#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdbool.h>

//PROTOTYPE
void fullScreen();
void gotoxy(int x, int y);
void setcolor(unsigned short color);
void showDadu(short angka);
void header();
void intro();
void mainMenu();
void instruction();
void credits();
void pickPlayer();
void gamePlay();
void isGameOver();
void playerStartPoint();
void printMap();
void isiNama();

/* =============== STRUCT =============== */
struct player {
	char nama[10]; 	//nama player
	char *symbol; 	//symbol player X,K,Q,F
	int p_x; 		//kordinat x player
	int p_y; 		//kordinat y player
	int pa_x; 		//kordinat x homebase player
	int pa_y;		//kordinat y homebase player
	int out; 		//jumlah bidak keluar dari homebae
	int habis; 		//untuk mengecek apakah bidak dari homebase sudah habis
	int done; 		//untuk mengecek apakah bidak sudah memasuki kotak finish
	int finish;  	//jumlah bidak yang sudah berada di kotak finish
	int gameover; 	//untuk mengecek apakah player sudah gameover atau belum
}user,botq,botk,botf,B[5][5];

/*=============== Halaman Utama ===============*/
int main() {
	fullScreen(); //call fullscreen module
	header(); //header module
	intro(); //intro module
	
	system("cls"); //clear console
	header();
	mainMenu(); //main menu module
	return 0;
}

/* =============== ALL MODULE =============== */

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
		gotoxy(103,32);printf("|                       |");
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
	char wlc[50] = {"SELAMAT DATANG DI GORAS LUDO GAMES!!!"};
	char line[50] = {"======================================"};
	
	//loop
	gotoxy(62,24);
	len = strlen(line);
	for(i=0; i<len; i++) {
		putchar(line[i]);
		Sleep(30);
	}
	
	gotoxy(62,25);
	len = strlen(wlc);
	for(i=0;i<len;i++) {
		putchar(wlc[i]);
		Sleep(70); 
	}
	
	gotoxy(62,26);
	len = strlen(line);
	for(i=0; i<len; i++) {
		putchar(line[i]);
		Sleep(30);
	}
	printf("\n");
	gotoxy(65,28);system("PAUSE");
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

/*=============== Posisi Bidak Pada Homebase ===============*/
void playerStartPoint() { //menampilkan posisi awal bidak pada homebase
	gotoxy(25,12);printf("%s0",user.symbol);
	gotoxy(34,12);printf("%s1",user.symbol);
	gotoxy(25,16);printf("%s2",user.symbol);
	gotoxy(34,16);printf("%s3",user.symbol);
	
	gotoxy(25,30);printf("F0");
	gotoxy(34,30);printf("F1");
	gotoxy(25,34);printf("F2");
	gotoxy(34,34);printf("F3");
	
	gotoxy(61,12);printf("K0");
	gotoxy(70,12);printf("K1");
	gotoxy(61,16);printf("K2");
	gotoxy(70,16);printf("K3");
		
	gotoxy(61,30);printf("Q0");
	gotoxy(70,30);printf("Q1");
	gotoxy(61,34);printf("Q2");
	gotoxy(70,34);printf("Q3");
}

/*=============== Kata-Kata Menang ===============*/
void winnerWords() {
	FILE *FPRead;
	char temporary[200];
	
	//openfile
	int i = 20;
	
	FPRead=fopen("winner.txt","r");
	while(fgets(temporary,sizeof(temporary),FPRead)) {
		gotoxy(60,i);printf("%s",temporary);
		i++;
	} fclose(FPRead);
}

/*=============== Halaman Pemenang ===============*/
void winnerPage() {
	//declare
	system("cls");
	int i;
	for (i=0; i<15; i++){
		setcolor(18);winnerWords();
		Sleep(500);
		setcolor(10);winnerWords();
		Sleep(100);
	}
	gotoxy(63,30);system("pause");
	mainMenu();
}


void gameOverWords() {
	FILE *FPRead;
	char temporary[200];
	
	//openfile
	int i = 20;
	
	FPRead=fopen("loser.txt","r");
	while(fgets(temporary,sizeof(temporary),FPRead)) {
		gotoxy(60,i);printf("%s",temporary);
		i++;
	} fclose(FPRead);
}
/*=============== Check Game Over ===============*/
void gameOver() {
	//declare
	system("cls");
	int i;
	for (i=0; i<18; i++){
		setcolor(12);gameOverWords();
		Sleep(500);
		setcolor(10);gameOverWords();
		Sleep(100);
	}
	gotoxy(63,30);system("pause");
	mainMenu();
}

/*=============== MAIN MENU ===============*/
void mainMenu() { //main menu
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
	gotoxy(73,24);printf("[1] Mulai Bermain");
	gotoxy(73,25);printf("[2] Cara Bermain");
	gotoxy(73,26);printf("[3] Credits");
	gotoxy(73,27);printf("[4] Keluar Permainan");
	while (!go) {
		gotoxy(65,34);printf("Masukkan angka yang akan anda tuju = ");scanf("%d", &input);
		if (input>4 || input<1 || input == 0 || !input) {
			gotoxy(100,34);printf("                                      ");
			gotoxy(76,35);printf("Angka yang anda masukan salah!");
		} else {
			if (input==1 || input==2 || input==3 || input==4 || input==5) {
				if (input==1) {
					system("CLS");
					pickPlayer();
					go = true;
				}
				if (input==2) {
					system("CLS");
					instruction();
					go = true;
				}
				if (input==3) {
					system("CLS");
					credits();
					go = true;
				}
				if (input==4) {
					go = true;
					exit(1);
				}
			}
		}

	}
} //end main menu

/*=============== Pick Player ===============*/
void pickPlayer() { //how many player
	header();
	
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
	gotoxy(73,21);printf("Jumlah Pemain");
	gotoxy(73,22);printf("====================");
	gotoxy(73,24);printf("(1) 2 Pemain");
	gotoxy(73,25);printf("(2) 3 Pemain");
	gotoxy(73,26);printf("(3) 4 Pemain");
	gotoxy(73,27);printf("(4) Kembali ke menu");
	gotoxy(73,28);printf("(5) Keluar dari permainan");
	while (!go) {
		gotoxy(65,34);printf("Masukkan angka yang akan anda tuju = ");scanf("%d", &input);
		if (input>4 || input<1 || input == 0 || !input) {
			gotoxy(100,34);printf("                                      ");
			gotoxy(76,35);printf("Angka yang anda masukan salah!");
		} else {
			if (input==1 || input==2 || input==3 || input==4 || input==5) {
				if (input==1) {
					system("CLS");
					go = true;
					isiNama();
				}
				if (input==2) {
					system("CLS");
					go = true;
					isiNama();
				}
				if (input==3) {
					system("CLS");
					go = true;
					isiNama();
				}
				if (input==4) {
					system("CLS");
					go = true;
					mainMenu();
				}
				if (input==5) {
					go = true;
					system("EXIT");
					exit(1);
				}
			}
		}
	}
}

/* =========== Isi Nama User =========== */
void isiNama() {
	gotoxy(73,20);printf("Masukan Nama : ");
	gotoxy(73,22);printf("--------------------");
	gotoxy(73,21);scanf("%s",user.nama);
	system("CLS");
	gamePlay();
}

/* =========== Menetapkan Kordinat Bidak =========== */
void inisiasi(){
	//posisi awal player 1
	B[0][0].pa_x = 25;
	B[0][0].pa_y = 12;
	B[0][1].pa_x = 34;
	B[0][1].pa_y = 12;
	B[0][2].pa_x = 25;
	B[0][2].pa_y = 16;
	B[0][3].pa_x = 34;
	B[0][3].pa_y = 16;
	
	//posisi awal player 2
	B[1][0].pa_x = 61;
	B[1][0].pa_y = 12;
	B[1][1].pa_x = 70;
	B[1][1].pa_y = 12;
	B[1][2].pa_x = 61;
	B[1][2].pa_y = 16;
	B[1][3].pa_x = 70;
	B[1][3].pa_y = 16;
	
	//posisi awal player 3
	B[2][0].pa_x = 61;
	B[2][0].pa_y = 30;
	B[2][1].pa_x = 70;
	B[2][1].pa_y = 30;
	B[2][2].pa_x = 61;
	B[2][2].pa_y = 34;
	B[2][3].pa_x = 70;
	B[2][3].pa_y = 34;
	
	//posisi awal player 4
	B[3][0].pa_x = 25;
	B[3][0].pa_y = 30;
	B[3][1].pa_x = 34;
	B[3][1].pa_y = 30;
	B[3][2].pa_x = 25;
	B[3][2].pa_y = 34;
	B[3][3].pa_x = 34;
	B[3][3].pa_y = 34;
	
	//assign kordinat sebelum muncul
	int i,j;
	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			B[i][j].p_x = 0;
		}
	}
	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			B[i][j].p_y = 0;
		}
	}
	
	//menetapkan player.out menjadi 0
	user.out = 0;
	botk.out = 0;
	botq.out = 0;
	botf.out = 0;
	
	//menetapkan player.finish menjadi 0
	user.finish = 0;
	botk.finish = 0;
	botq.finish = 0;
	botf.finish = 0;
}

/* =========== GAMEPLAY  =========== */
void gamePlay() {
	user.symbol = "X";
	setcolor(10); //mengganti warna
	printMap(); //map
	gotoxy(37,2);printf("GORAS 2019 - Gopel & Laras"); //text atas goras
	playerStartPoint();// menampilkan bidak pada homebase
	
	setcolor(9); //mengganti warna
	
	//playername
	gotoxy(25,9);printf("%s",user.nama);
	gotoxy(61,9);printf("KILLER-BOT");
	gotoxy(25,38);printf("FLOW-BOT");
	gotoxy(61,38);printf("QUICK-BOT");
	
	//dadu
	gotoxy(102,25);printf("TEKAN ENTER UNTUK MERANDOM");
	gotoxy(102,26);printf("--------------------------");
	
	/* =========== Deklarasi ===========*/
	srand (time(NULL)); // untuk random dadu
	int r,i,j; // r = angka dadu
	int gx; // garis x
	int gy; // garis y
	bool gameIsOver = false;
	int turn=1;
	int six=0;
	int player; //player
	int nobidak=0;
	int bidakhb[5];
	int ranChoice;
	int mp,mb;
	int bidakmax,bidakmax1,bidakmax2;
	int l,g;
	int randead;
	int dead;
	
	//menetapkan struct
	botq.symbol = "Q";
	botk.symbol = "K";
	botf.symbol = "F";
	
	//menetapkan player.habis menjadi 0
	user.habis = 0;
	botk.habis = 0;
	botq.habis = 0;
	botf.habis = 0;
	
	//menetapkan player.gameover menjadi 0
	user.gameover = 0;
	botk.gameover = 0;
	botq.gameover = 0;
	botf.gameover = 0;
	
	//menetapkan B[][].done menjadi 0
	for (i=0; i<4; i++) {
		for (j=0; j<4; j++) {
			B[i][j].done = 0;
		}
	}
	
	/*  =========== KORDINAT PLAYER =========== */	
	inisiasi();
	char whos[10];
	char *bidak;
	bool bidakSudahKeluar = false;
	
	
	/* =========== gamePlay =========== */
	while (!gameIsOver) { //selama permainan belum berakhir
		bidakSudahKeluar = false;
		/* =========== Pengaturan Turn (giliran) =========== */
		if (turn==1) {
			bidak = user.symbol;
			player = 0;
			strcpy(whos, user.nama);
			gx = B[player][0].p_x;
			gy = B[player][0].p_y;
			bidakhb[1] = user.out;
			setcolor(15);
			gotoxy(25,9);printf("%s",user.nama);
			setcolor(9);
			gotoxy(61,9);printf("KILLER-BOT");
			gotoxy(61,38);printf("QUICK-BOT");
			gotoxy(25,38);printf("FLOW-BOT");
		}
		if (turn==2) {
			bidak = botk.symbol;
			player = 1;
			strcpy(whos, "KILLER-BOT"); //mengisi
			gx = B[player][0].p_x;
			gy = B[player][0].p_y;
			bidakhb[2] = botk.out;
			setcolor(15);
			gotoxy(61,9);printf("KILLER-BOT");
			setcolor(9);
			gotoxy(25,9);printf("%s",user.nama);
			gotoxy(61,38);printf("QUICK-BOT");
			gotoxy(25,38);printf("FLOW-BOT");
		}
		if (turn==3) {
			bidak = botq.symbol;
			player = 2;
			strcpy(whos, "QUICK-BOT");
			gx = B[player][0].p_x;
			gy = B[player][0].p_y;
			bidakhb[3] = botq.out;
			setcolor(15);
			gotoxy(61,38);printf("QUICK-BOT");
			setcolor(9);
			gotoxy(61,9);printf("KILLER-BOT");
			gotoxy(25,9);printf("%s",user.nama);
			gotoxy(25,38);printf("FLOW-BOT");
		}
		if (turn==4) {
			bidak = botf.symbol;
			player = 3;
			strcpy(whos, "FLOW-BOT");
			gx = B[player][0].p_x;
			gy = B[player][0].p_y;
			bidakhb[4] = botf.out;
			setcolor(15);
			gotoxy(25,38);printf("FLOW-BOT");
			setcolor(9);
			gotoxy(61,9);printf("KILLER-BOT");
			gotoxy(61,38);printf("QUICK-BOT");
			gotoxy(25,9);printf("%s",user.nama);
		}
		bool udah = false; //belum melakukan langkah
		
		//Cek jika ke 4 bidak sudah masuk ke kotak finish player tidak akan melakukan turn (giliran)
		if (turn==1 && user.finish==4) {
			udah = true;
		}
		if (turn==2 && botk.finish==4) {
			udah = true;
		}
		if (turn==3 && botq.finish==4) {
			udah = true;
		}
		if (turn==4 && botf.finish==4) {
			udah = true;
		}
		
		//header
		if (!udah) {
			gotoxy(43,4);printf("================");
			gotoxy(43,5);printf("                           ");
			setcolor(15);
			gotoxy(43,5);printf("%s TURN",whos);
			setcolor(9);
			gotoxy(43,6);printf("================");
			
			/* =========== Random Dadu =========== */
			if (turn == 1) {
				gotoxy(102,25);printf("TEKAN ENTER UNTUK MERANDOM");
				gotoxy(128,25);getch();
				for (i=0; i<10; i++) {
					gotoxy(102,25);printf("      MENGOCOK DADU !       ");
					r = rand() % 7;
					if (r == 0) {
						r = 6;
					}
					showDadu(r);
//					gotoxy(115,37);printf("%d",r);
					Sleep(200);
				}
				for (i=0; i<10; i++) {
					setcolor(15);gotoxy(104,37);printf("KAMU MENDAPATKAN ANGKA %d ",r);
					Sleep(100);
					setcolor(9);gotoxy(104,37);printf("KAMU MENDAPATKAN ANGKA %d ",r);
					Sleep(100);
				}
			}
			if (turn==2 || turn==3 || turn==4) {
				for (i=0; i<10; i++) {
					gotoxy(102,25);printf("      MENGOCOK DADU !       ");
					r = rand() % 7;
					if (r == 0) {
						r = 6;
					}
					showDadu(r);
//					gotoxy(115,37);printf("%d",r);
					Sleep(200);
				}
				for (i=0; i<10; i++) {
					setcolor(15);gotoxy(104,37);printf("BOT MENDAPATKAN ANGKA %d ",r);
					Sleep(100);
					setcolor(9);gotoxy(104,37);printf("BOT MENDAPATKAN ANGKA %d ",r);
					Sleep(100);
				}
			}
		}
		
		//CEK APAKAH SUDAH ADA BIDAK YANG KELUAR?
		if (turn==1 && user.out>0) {
			bidakSudahKeluar = true;
		}
		if (turn==2 && botk.out>0) {
			bidakSudahKeluar = true;
		}
		if (turn==3 && botq.out>0) {
			bidakSudahKeluar = true;
		}
		if (turn==4 && botf.out>0) {
			bidakSudahKeluar = true;
		}
		
		/* =========== Mengeluarkan Bidak =========== */
		if (turn==1 && user.out==0 && !bidakSudahKeluar) { //pertama kali
			if (r==6) {
				bidakSudahKeluar = true;
				gotoxy(B[0][0].pa_x,B[0][0].pa_y);printf("  ");
				B[0][user.out].p_x = 29;
				B[0][user.out].p_y = 21;
				gotoxy(B[0][0].p_x,B[0][0].p_y);printf("X0");
				Sleep(500);
				gx = B[0][0].p_x;
				gy = B[0][0].p_y;
				user.out = 1;
				udah = true;
			} else {
				bidakSudahKeluar = false;
			}
		}
		
		if (turn==2 && botk.out==0 && !bidakSudahKeluar) {
			if (r==6) {
				bidakSudahKeluar = true;
				gotoxy(B[1][0].pa_x,B[1][0].pa_y);printf("  ");
				B[1][botk.out].p_x = 53;
				B[1][botk.out].p_y = 13;
				gotoxy(B[1][0].p_x,B[1][0].p_y);printf("K0");
				Sleep(500);
				gx = B[1][0].p_x;
				gy = B[1][0].p_y;
				botk.out = 1;
				udah = true;
			} else {
				bidakSudahKeluar = false;
			}
		}
		if (turn==3 && botq.out==0 && !bidakSudahKeluar) {
			if (r==6) {
				bidakSudahKeluar = true;
				gotoxy(B[2][0].pa_x,B[2][0].pa_y);printf("  ");
				B[2][botq.out].p_x = 69;
				B[2][botq.out].p_y = 25;
				gotoxy(B[2][0].p_x,B[2][0].p_y);printf("Q0");
				Sleep(500);
				gx = B[2][0].p_x;
				gy = B[2][0].p_y;
				botq.out = 1;
				udah = true;
			} else {
				bidakSudahKeluar = false;
			}
		}
		if (turn==4 && botf.out==0 && !bidakSudahKeluar) {
			if (r==6) {
				bidakSudahKeluar = true;
				gotoxy(B[3][0].pa_x,B[3][0].pa_y);printf("  ");
				B[3][botf.out].p_x = 45;
				B[3][botf.out].p_y = 33;
				gotoxy(B[3][0].p_x,B[3][0].p_y);printf("F0");
				Sleep(500);
				gx = B[3][0].p_x;
				gy = B[3][0].p_y;
				botf.out = 1;
				udah = true;
			} else {
				bidakSudahKeluar = false;
			}
		}
		
		/* =========== Mengeluarkan Bidak =========== */
		char answer = 'c';
		if (turn==1 && user.out>0 && user.out<5 && r==6 && !udah && user.habis != 1) { // USER
			gotoxy(90,21);printf("keluarin pion? (y/n)");
			answer = getche();
			if (answer == 'y' || answer == 'Y') {
				gotoxy(B[0][user.out].pa_x,B[0][user.out].pa_y);printf("  ");
				B[0][user.out].p_x = 29;
				B[0][user.out].p_y = 21;
				gotoxy(B[0][user.out].p_x,B[0][user.out].p_y);printf("X%d",user.out);
				Sleep(1000);
				gx = B[0][user.out].p_x;
				gy = B[0][user.out].p_y;
				gotoxy(90,21);printf("                       ");
				if (user.out != 4) {
					user.out= user.out + 1;
				}
				if (user.out == 4) {
					user.habis = 1;
				}
				udah = true;
			}
			if (answer == 'n' || answer == 'N') {
				gotoxy(90,21);printf("                         ");
				udah = false;
			}
		}
		
		if (turn==2 && botk.out>0 && botk.out<5 && r==6 && !udah && botk.habis != 1) { // BOTK
			ranChoice = rand() % 1;
			switch(ranChoice) {
				case 0 :
					gotoxy(B[1][botk.out].pa_x,B[1][botk.out].pa_y);printf("  ");
					B[1][botk.out].p_x = 53;
					B[1][botk.out].p_y = 13;
					gotoxy(B[1][botk.out].p_x,B[1][botk.out].p_y);printf("K%d",botk.out);
					Sleep(1000);
					gx = B[1][botk.out].p_x;
					gy = B[1][botk.out].p_y;
					gotoxy(90,21);printf("                       ");
					if (botk.out != 4) {
						botk.out = botk.out + 1;
					}
					if (botk.out == 4) {
						botk.habis = 1;
					}
					udah = true;break;
					
				case 1 : udah = false;break;
				}
		}
		
		if (turn==3 && botq.out>0 && botq.out<5 && r==6 && !udah && botq.habis != 1) { // BOTQUICK
			ranChoice = rand() % 1;
			switch(ranChoice) {
				case 0 :
					gotoxy(B[2][botq.out].pa_x,B[2][botq.out].pa_y);printf("  ");
					B[2][botq.out].p_x = 69;
					B[2][botq.out].p_y = 25;
					gotoxy(B[2][botq.out].p_x,B[2][botq.out].p_y);printf("Q%d",botq.out);
					Sleep(1000);
					gx = B[2][botq.out].p_x;
					gy = B[2][botq.out].p_y;
					gotoxy(90,21);printf("                       ");
					if (botq.out != 4) {
						botq.out = botq.out + 1;
					}
					if (botq.out == 4) {
						botq.habis = 1;
					}
					udah = true;break;
				
				case 1 : udah = false;break;
			}
		}
		
		if (turn==4 && botf.out>0 && botf.out<5 && r==6 && !udah && botf.habis != 1) { // BOTQUICK
			ranChoice = rand() % 1;
			switch(ranChoice) {
				case 0 : 
					gotoxy(B[3][botf.out].pa_x,B[3][botf.out].pa_y);printf("  ");
					B[3][botf.out].p_x = 45;
					B[3][botf.out].p_y = 33;
					gotoxy(B[3][botf.out].p_x,B[3][botf.out].p_y);printf("F%d",botf.out);
					Sleep(1000);
					gx = B[3][botf.out].p_x;
					gy = B[3][botf.out].p_y;
					gotoxy(90,21);printf("                       ");
					if (botf.out != 4) {
						botf.out= botf.out + 1;
					}
					if (botf.out == 4) {
						botf.habis = 1;
					}
					udah = true;break;
				
				case 1 : udah = false;break;
			}
		}
		
		/* =========== Memilih Bidak =========== */
		answer = 'c';
		if (turn==1 && user.out>1 && user.finish<4 && !udah) { // USER
			gotoxy(90,21);printf("pilih bidak keberapa yang akan maju: ");
			answer = getche();
			if (answer=='0') {
				if (B[0][0].done == 1) {
					gotoxy(90,23);printf("bidak ke-0 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                         ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[0][0].p_x;
					gy = B[0][0].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=0;
				}
			}
			if (answer=='1') {
				if (B[0][1].done == 1) {
					gotoxy(90,23);printf("bidak ke-1 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                         ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[0][1].p_x;
					gy = B[0][1].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=1;
				}
			}
			if (answer=='2') {
				if (B[0][2].done == 1) {
					gotoxy(90,23);printf("bidak ke-2 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                         ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[0][2].p_x;
					gy = B[0][2].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=2;
				}
			}
			if (answer=='3') {
				if (B[0][3].done == 1) {
					gotoxy(90,23);printf("bidak ke-3 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                         ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[0][3].p_x;
					gy = B[0][3].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=3;
				}
			}
		}
		
		if (turn==2 && botk.out>1 && botk.finish<4 && !udah) { //BOTKILLER
			if (botk.out==1) {
				ranChoice = 0;
			}
			if (botk.out==2) {
				ranChoice = rand() % 1;
			}
			if (botk.out==3) {
				ranChoice = rand() % 2;
			}
			if (botk.out==4) {
				ranChoice = rand() % 3;
			}
			switch(ranChoice) {
				case 0 : 
				if (B[1][0].done == 1) {
					gotoxy(90,23);printf("bidak ke-0 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[1][0].p_x;
					gy = B[1][0].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=0;
				}break;
				
				case 1 : 
				if (B[1][1].done == 1) {
					gotoxy(90,23);printf("bidak ke-1 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[1][1].p_x;
					gy = B[1][1].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=1;
				}break;
					
				case 2 :
				if (B[1][2].done == 1) {
					gotoxy(90,23);printf("bidak ke-2 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[1][2].p_x;
					gy = B[1][2].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=2;
				}break;
				
				case 3 : 
				if (B[1][3].done == 1) {
					gotoxy(90,23);printf("bidak ke-3 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[1][3].p_x;
					gy = B[1][3].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=3;
				}break;
			}
		}
		
		if (turn==3 && botq.out>1 && botq.finish<4 && !udah) { //BOTQUICK
			if (botq.out==1) {
				ranChoice = 0;
			}
			if (botq.out==2) {
				ranChoice = rand() % 1;
			}
			if (botq.out==3) {
				ranChoice = rand() % 2;
			}
			if (botq.out==4) {
				ranChoice = rand() % 3;
			}
			switch(ranChoice) {
				case 0 : 
				if (B[2][0].done == 1) {
					gotoxy(90,23);printf("bidak ke-0 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[2][0].p_x;
					gy = B[2][0].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=0;
				}break;
				
				case 1 : 
				if (B[2][1].done == 1) {
					gotoxy(90,23);printf("bidak ke-1 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[2][1].p_x;
					gy = B[2][1].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=1;
				}break;
					
				case 2 :
				if (B[2][2].done == 1) {
					gotoxy(90,23);printf("bidak ke-2 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[2][2].p_x;
					gy = B[2][2].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=2;
				}break;
				
				case 3 : 
				if (B[2][3].done == 1) {
					gotoxy(90,23);printf("bidak ke-3 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[2][3].p_x;
					gy = B[2][3].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=3;
				}break;
			}
		}
		
		if (turn==4 && botf.out>1 && botf.finish<4 && !udah) { //BOTFLOW
			if (botf.out==1) {
				ranChoice = 0;
			}
			if (botf.out==2) {
				ranChoice = rand() % 1;
			}
			if (botf.out==3) {
				ranChoice = rand() % 2;
			}
			if (botf.out==4) {
				ranChoice = rand() % 3;
			}
			switch(ranChoice) {
				case 0 : 
				if (B[3][0].done == 1) {
					gotoxy(90,23);printf("bidak ke-0 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[3][0].p_x;
					gy = B[3][0].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=0;
				}break;
				
				case 1 : 
				if (B[3][1].done == 1) {
					gotoxy(90,23);printf("bidak ke-1 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[3][1].p_x;
					gy = B[3][1].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=1;
				}break;
					
				case 2 :
				if (B[3][2].done == 1) {
					gotoxy(90,23);printf("bidak ke-2 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[3][2].p_x;
					gy = B[3][2].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=2;
				}break;
				
				case 3 :
				if (B[3][3].done == 1) {
					gotoxy(90,23);printf("bidak ke-3 sudah ada di finish.");
					Sleep(1000);
					gotoxy(90,23);printf("                                       ");
					gotoxy(90,21);printf("                                       ");
					udah = true;
				} else {
					gx = B[3][3].p_x;
					gy = B[3][3].p_y;
					gotoxy(90,21);printf("                                       ");
					nobidak=3;
				}break;
			}
		}
		
		/* =========== movingPion (pergerakan pion/bidak) =========== */
		if (bidakSudahKeluar && !udah) { //bidak sudah keluar & belum berpindah kotak
			for (i=0; i<r; i++) { //DONE
				udah = false;
				gotoxy(gx,gy);printf("  ");
				
				//loop ini berfungsi untuk mengeprint ulang symbol bidak yang terhapus saat bidak lain melewatinya
				for (mp=0; mp<4; mp++) {
					for (mb=0; mb<4; mb++) {
						if (mp != turn-1) {
							if (gx==B[mp][mb].p_x && gy==B[mp][mb].p_y) {
								if (mp == 0) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("X%d",mb);
								}
								if (mp == 1) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("K%d",mb);
								}
								if (mp == 2) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("Q%d",mb);
								}
								if (mp == 3) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("F%d",mb);
								}
							}
						}
						if (mp == turn-1 && mb != nobidak) {
							if (gx==B[mp][mb].p_x && gy==B[mp][mb].p_y) {
								if (mp == 0) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("X%d",mb);
								}
								if (mp == 1) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("K%d",mb);
								}
								if (mp == 2) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("Q%d",mb);
								}
								if (mp == 3) {
									gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("F%d",mb);
								}
							}
						}
					}
				} //end loop
				
				//Jalur Istimewa
				if (turn==1 && gx==25 && gy==23 && !udah) {
					gx = gx + 4;
					udah = true;
				}
				if (turn==1 && gx<45 && gy==23 && !udah) {
					gx = gx + 4;
					udah = true;
				}
				if (turn==1 && gx==45 && gy==23 && !udah && i!=r-1 && B[0][nobidak].done!=1) { //balik lagi jika angka dadu tidak pas
					for (i=i; i<r; i++) {
						gotoxy(gx,gy);printf("  ");
						gx = gx - 4;
						gotoxy(gx,gy);printf("X%d",nobidak);
						Sleep(500);
					}
					i = r-1;
					udah = true;
				}
				if (turn==1 && gx==45 && gy==23 && !udah && i==r-1 && B[0][nobidak].done!=1) { 
					user.finish += 1;
					B[0][nobidak].done = 1;
					udah = true;
				} //Sudah di jalur finish
				
				if (gy==21 && gx<41 && !udah) {
					gx = gx + 4;
					udah = true;
				}
				if (gx==41 && gy==21 && !udah) {
					gx = gx + 4;
					gy = gy-2;
					udah = true;
				}
				if (gx==45 && gy>9 && gy<=21 && !udah) {
					gy = gy-2;
					udah = true;
				}
				if (gx<53 && gy==9 && !udah) {
					gx = gx + 4;
					udah = true;
				}
				
				//Jalur Istimewa
				if (turn==2 && gx==49 && gy==9 && !udah) {
					gy = gy + 2;
					udah = true;
				}
				if (turn==2 && gx==49 && gy<21 && !udah) {
					gy = gy + 2;
					udah = true;
				}
				if (turn==2 && gx==49 && gy==21 && !udah && i!=r-1 && B[1][nobidak].done!=1) { //balik lagi jika angka dadu tidak pas
					for (i=i; i<r; i++) {
						gotoxy(gx,gy);printf("  ");
						gy = gy - 2;
						gotoxy(gx,gy);printf("K%d",nobidak);
						Sleep(500);
					}
					i = r-1;
					udah = true;
				}
				if (turn==2 && gx==49 && gy==21 && !udah && i==r-1 && B[1][nobidak].done!=1) { // Sudah di jalur finish
					botk.finish += 1;
					B[1][nobidak].done = 1;
					udah = true;
				} //Sudah di jalur finish
				
				if (gx==53 && gy<19 && !udah) {
					gy = gy + 2;
					udah = true;
				}
				if (gx==53 && gy==19 && !udah) {
					gy = gy + 2;
					gx = 53 + 4;
					udah = true;
				}
				if (gx<77 && gy==21 && !udah) {
					gx = gx + 4;
					udah = true;
				}
				if (gx==77 && gy<25 && !udah) {
					gy = gy + 2;
					udah = true;
				}
				
				//Jalur Istimewa
				if (turn==3 && gx==77 && gy==23 && !udah) {
					gx = gx - 4;
					udah = true;
				}
				if (turn==3 && gx>53 && gy==23 && !udah) {
					gx = gx - 4;
					udah = true;
				}
				if (turn==3 && gx==53 && gy==23 && !udah && i!=r-1 && B[2][nobidak].done!=1) { //balik lagi jika angka dadu tidak pas
					for (i=i; i<r; i++) {
						gotoxy(gx,gy);printf("  ");
						gx = gx + 4;
						gotoxy(gx,gy);printf("Q%d",nobidak);
						Sleep(500);
					}
					i = r-1;
					udah = true;
				}
				if (turn==3 && gx==53 && gy==23 && !udah && i==r-1 && B[2][nobidak].done!=1) { 
					botq.finish += 1;
					B[2][nobidak].done = 1;
					udah = true;
				} //Sudah di jalur finish
				
				if (gx>57 && gy==25 && !udah) {
					gx = gx - 4;
					udah = true;
				}
				if (gx==57 && gy==25 && !udah) {
					gx = gx - 4;
					gy = gy + 2;
					udah = true;
				}
				if (gx==53 && gy<37 && !udah) {
					gy = gy+2;
					udah = true;
				}
				if (gx>45 && gy==37 && !udah) {
					gx = gx-4;
					udah = true;
				}
				
				//Jalur Istimewa
				if (turn==4 && gx==49 && gy==37 && !udah) {
					gy = gy - 2;
					udah = true;
				}
				if (turn==4 && gx==49 && gy>25 && !udah) {
					gy = gy - 2;
					udah = true;
				}
				if (turn==4 && gx==49 && gy==25 && !udah && i!=r-1 && B[3][nobidak].done!=1) { //balik lagi jika angka dadu tidak pas
					for (i=i; i<r; i++) {
						gotoxy(gx,gy);printf("  ");
						gy = gy + 2;
						gotoxy(gx,gy);printf("F%d",nobidak);
						Sleep(500);
					}
					i = r-1;
					udah = true;
				}
				if (turn==4 && gx==49 && gy==25 && !udah && i==r-1 && B[3][nobidak].done!=1) {
					botf.finish += 1;
					B[3][nobidak].done = 1;
					udah = true;
				} //Sudah di jalur finish
				
				if (gx==45 && gy>27 && !udah) {
					gy = gy - 2;
					udah = true;
				}
				if (gx==45 && gy==27 && !udah) {
					gy = gy - 2;
					gx = gx - 4;
					udah = true;
				}
				if (gx>21 && gy==25 && !udah) {
					gx = gx - 4;
					udah = true;
				}
				if (gx==21 && gy>21 && !udah) {
					gy = gy-2;
					udah = true;
				}
				if (gx<33 && gy==21 && !udah) {
					gx = gx + 4;
					udah = true;
				}
				gotoxy(gx,gy);printf("%s%d",bidak,nobidak);
				Sleep(500);
		
		/* =========== Membunuh Bidak Lawan =========== */
		if (i==r-1) { //untuk mengembalikan bidak ke posisi pertama keluar
			for (mp=0; mp<4; mp++) {
				for (mb=0; mb<4; mb++) {
					if (mp != turn-1) {
						if (gx==B[mp][mb].p_x && gy==B[mp][mb].p_y) {
							if (mp == 0) {
								B[mp][mb].p_x = 29;
								B[mp][mb].p_y = 21;
								gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("X%d",mb);
								gotoxy(90,21);printf("bidak X%d telah dibunuh, bidak kembali ke posisi awal.");
								Sleep(4000);
								gotoxy(90,21);printf("                                                       ");
							}
							if (mp == 1) {
								B[mp][mb].p_x = 53;
								B[mp][mb].p_y = 13;
								gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("K%d",mb);
								gotoxy(90,21);printf("bidak K%d telah dibunuh, bidak kembali ke posisi awal.");
								Sleep(4000);
								gotoxy(90,21);printf("                                                       ");
							}
							if (mp == 2) {
								B[mp][mb].p_x = 69;
								B[mp][mb].p_y = 25;
								gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("Q%d",mb);
								gotoxy(90,21);printf("bidak Q%d telah dibunuh, bidak kembali ke posisi awal.");
								Sleep(2000);
								gotoxy(90,21);printf("                                                       ");
							}
							if (mp == 3) {
								B[mp][mb].p_x = 45;
								B[mp][mb].p_y = 33;
								gotoxy(B[mp][mb].p_x,B[mp][mb].p_y);printf("F%d",mb);
								gotoxy(90,21);printf("bidak F%d telah dibunuh, bidak kembali ke posisi awal.");
								Sleep(4000);
								gotoxy(90,21);printf("                                                       ");
							}
						}
					}
				}
			} //end loop
		}
				if (turn==1) {
					B[0][nobidak].p_x = gx;
					B[0][nobidak].p_y = gy;
				}
				if (turn==2) {
					B[1][nobidak].p_x = gx;
					B[1][nobidak].p_y = gy;
				}
				if (turn==3) {
					B[2][nobidak].p_x = gx;
					B[2][nobidak].p_y = gy;
				}
				if (turn==4) {
					B[3][nobidak].p_x = gx;
					B[3][nobidak].p_y = gy;
				}
				gotoxy(130,4);printf("%s Finish = %d",user.nama,user.finish);
				gotoxy(130,5);printf("KillerBot Finish = %d",botk.finish);
				gotoxy(130,6);printf("QuickBot Finish = %d",botq.finish);
				gotoxy(130,7);printf("FlowBot Finish = %d",botf.finish);
			}
		}
		
		/* =========== cekPemenang =========== */
		//mencari bidak yang paling banyak berada di homebase
		if (user.out > botk.out) {
			bidakmax1 = user.out;
		} else {
			bidakmax1 = botk.out;
		}
		if (botq.out > botf.out) {
			bidakmax2 = botq.out;
		} else {
			bidakmax2 = botf.out;
		}
		if (bidakmax1 > bidakmax2) {
			bidakmax = bidakmax1;
		} else {
			bidakmax = bidakmax2;
		}
		if (bidakmax1 == bidakmax2) { //jika ada 2 player yang memiliki jumlah bidak sama, maka akan dirandom
			randead = rand() % 1;
			if (randead==0) {
				bidakmax = bidakmax1;
			} else {
				bidakmax = bidakmax2;
			}
		}
		//cek jika salah satu player menang, 1 player yang bidak pada homebasenya masih banyak, maka akan kalah
		if (turn==1 && user.finish==4) {
			for (l=0; l<7; l++) {
				setcolor(15);
				gotoxy(25,12);printf("                 ");
				gotoxy(25,13+l);printf(" YOU WIN YOU WIN ");
				setcolor(9);
			}
			if (bidakmax==botk.out) {
				botk.gameover = 1;
				dead += 1;
			}
			if (bidakmax==botq.out) {
				botq.gameover = 1;
				dead += 1;
			}
			if (bidakmax==botf.out) {
				botf.gameover = 1;
				dead += 1;
			}
		}
		if (turn==2 && botk.finish==4) {
			for (l=0; l<7; l++) {
				setcolor(15);
				gotoxy(61,12);printf("                 ");
				gotoxy(61,13+l);printf(" YOU WIN YOU WIN ");
				setcolor(9);
			}
			if (bidakmax==user.out) {
				user.gameover = 1;
				dead += 1;
			}
			if (bidakmax==botq.out) {
				botq.gameover = 1;
				dead += 1;
			}
			if (bidakmax==botf.out) {
				botf.gameover = 1;
				dead += 1;
			}
		}
		if (turn==3 && botq.finish==4) {
			for (l=0; l<7; l++) {
				setcolor(15);
				gotoxy(61,30);printf("                 ");
				gotoxy(61,31+l);printf(" YOU WIN YOU WIN ");
				setcolor(9);
			}
			if (bidakmax==botk.out) {
				botk.gameover = 1;
				dead += 1;
			}
			if (bidakmax==user.out) {
				user.gameover = 1;
				dead += 1;
			}
			if (bidakmax==botf.out) {
				botf.gameover = 1;
				dead += 1;
			}
		}
		if (turn==4 && botf.finish==4) {
			for (l=0; l<7; l++) {
				setcolor(15);
				gotoxy(25,30);printf("                 ");
				gotoxy(25,31+l);printf(" YOU WIN YOU WIN ");
				setcolor(9);
			}
			if (bidakmax==botk.out) {
				botk.gameover = 1;
				dead += 1;
			}
			if (bidakmax==botq.out) {
				botq.gameover = 1;
				dead += 1;
			}
			if (bidakmax==user.out) {
				user.gameover = 1;
				dead += 1;
			}
		}
		
		//cek apakah user kalah/menang.
		if (user.gameover==1) {
			gameOverWord();
		}
		if (user.finish==4) {
			winnerPage();
		}
		
		/* =========== Pergantian Turn (giliran) =========== */
		if (r==6) { //jika mendapatkan angka 6, maka mendapat kan giliran <= 3x
			turn-=1;
			six+=1;
		}
		if (r==6 && six==3) { //jika sudah mendapatkan 3 kali giliran, maka dilanjutkan ke giliran selanjutnya
			turn+=1;
			six=0;
		}
		
		turn+=1;
		if(turn == 5){ //jika giliran sudah pada angka 5, maka giliran kembali ke angka 1
			turn = 1;
		}
	}
}

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
	system("CLS");
	header(); 
	FILE *FPRead;
	char Temporary[100];
	short i=17;
	FPRead=fopen("credits.txt","r");
	while(fgets(Temporary,sizeof(Temporary),FPRead)){
		gotoxy(38,i);
		printf("%s",Temporary);
		i++;
	}
	fclose(FPRead);
	
	gotoxy(38,40);
	system("PAUSE");
	system("CLS");
	header();
	mainMenu();
}
