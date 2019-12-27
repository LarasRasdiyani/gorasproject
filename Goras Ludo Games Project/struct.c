#include <stdio.h>
#include <string.h>

struct player {
	char name[10];
	int x;
	int y;
	int pa_x;
	int pa_y;
} user;

struct killerbot {
	int x;
	int y;
	int pa_x;
	int pa_y;
} kb;

struct collectorbot {
	int x;
	int y;
	int pa_x;
	int pa_y;
} cb;

struct flowbot {
	int x;
	int y;
	int pa_x;
	int pa_y;
} flow;


int main() {
	user.x = 50;
	user.y = 40;
	user.pa_x = 30;
	user.pa_y = 20;
	scanf("%s",&user.name);
	printf("%s\n",user.name);
	printf("%d\n%d\n%d\n%d",user.x,user.y,user.pa_x,user.pa_y);
}
