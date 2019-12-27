#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void showDadu (short angka);
void setcolor(unsigned short color)
{
HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(hCon,color);

}
void gotoxy(int x, int y){
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
} //source by Duthomhas in SetConsoleCursorPosition Function (cplusplus.com)

int main() {
	FILE *FPRead;
	system("cls");
	char temporary[200];
	FPRead=fopen("MAP.txt","r");
	while(fgets(temporary,sizeof(temporary),FPRead)) {
		printf("%s",temporary);
	} fclose(FPRead);
	int i=33,j=3,k;
	bool win = 0;
	while(!win) {
		
		for (k=0;k<20;k++) {
			if(i==33) {
				j+=2;
				gotoxy(i,j);printf("X1");
				Sleep(800);
			}
			if(k != 3) {
				gotoxy(i,j);printf("  ");
			}
			if (i==34 && j==5) {
				gotoxy(25,25);printf("GAME OVER");
			}
		}
	}
	gotoxy(20,35);system("pause");
	return 0;
}
