#include<stdio.h>
#include<stdlib.h>

int main(){
	int waktu = 20;
	
	while(waktu != 0){
		printf("Timer : %d", waktu);
		waktu--;
		sleep(1);
		system("CLS");	
	}
	printf("Waktu anda habis");
	
	return 0;
}
