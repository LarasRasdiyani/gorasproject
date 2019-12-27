#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

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
	int i = 0;
	while (i == 0) {
	gotoxy(1,1);setcolor(12);printf("GAME OVER");
	Sleep(500);
	gotoxy(1,1);setcolor(10);printf("GAME OVER");
	Sleep(500);	
	gotoxy(1,1);setcolor(9);printf("GAME OVER");
	Sleep(500);	
	gotoxy(1,1);setcolor(14);printf("GAME OVER");
	Sleep(500);	
	}
	return 0;
}
