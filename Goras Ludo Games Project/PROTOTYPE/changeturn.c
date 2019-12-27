#include <stdio.h>
#include <stdbool.h>

int main() {	
	bool gameOver = false;
	int lk[18];
	int i,r;
	//srand (time(NULL));
	//lk[i] = rand() % 7;
	for (i=0; i<17; i++) {
		lk[i] = 0;
	}
	
	while (!gameOver) {
		
		system("cls");
		printf("X1 = %d\n",lk[0]);
		printf("X2 = %d\n",lk[1]);
		printf("X3 = %d\n",lk[2]);
		printf("X4 = %d\n\n",lk[3]);
		
		printf("X1 = %d\n",lk[4]);
		printf("X2 = %d\n",lk[5]);
		printf("X3 = %d\n",lk[6]);
		printf("X4 = %d\n\n",lk[7]);
		
		printf("X1 = %d\n",lk[8]);
		printf("X2 = %d\n",lk[9]);
		printf("X3 = %d\n",lk[10]);
		printf("X4 = %d\n\n",lk[11]);
		
		printf("X1 = %d\n",lk[12]);
		printf("X2 = %d\n",lk[13]);
		printf("X3 = %d\n",lk[14]);
		printf("X4 = %d\n\n",lk[15]);
		gameOver = true;
	}
}
