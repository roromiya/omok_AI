#include<stdio.h>
#include<string.h>
#include<time.h>
#include <conio.h>
#include<stdlib.h>
#define Size 19
#define LEFT   97
#define RIGHT  100
#define UP     119
#define DOWN   115
#define spacebar 32

void makeomok();
void move();
void winner();
void bak_AI();
void bak_Attack(int max);
void bak_Defence(int max);
void black_node();
void white_node();
int omokdoll[Size][Size] = {0};
int black_Q[Size][Size] = {0};
int white_Q[Size][Size] = {0};
int d = 0,b = 9,c = 9,bakga,hkga;

int main()
{
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			omokdoll[i][j] == 0;
			
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			black_Q[i][j] == 0;
			
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			white_Q[i][j] == 0;
			
	printf("아무키나 누르십시오"); 
	getch();
	system("cls");
	omokdoll[8][9] = 2;
	black_Q[8][10] += 1;
	black_Q[8][8] += 1;
	black_Q[9][9] += 1;
	black_Q[9][10] += 1;
	black_Q[9][8] += 1;
	black_Q[7][9] += 1;
	black_Q[7][10] += 1;
	black_Q[7][8] += 1;
	
	makeomok();
	move();
}

void makeomok()
{
	system("cls");
	
	printf("┌");
	
	for(int i=0; i<19; i++)
		printf("┬");
		
	printf("┐\n");
	
	for(int i = 0; i < 19; i++)
	{
		printf("├");
		for(int j = 0; j < 19; j++)
		{
			if(omokdoll[i][j] == 0)
				printf("┼");
			else if(omokdoll[i][j] == 1)
				printf("●");
			else if(omokdoll[i][j] == 2)
				printf("○");
			else if(omokdoll[i][j] == 3)
				printf("☜"); 
		}
		
		printf("┤");
		if(i == 2)
			printf(" 조작법:w,a,s,d");
		if(i == 3)
			printf(" 돌 놓기:스페이스 바"); 
		if(i == 5)
			printf(" 외각 표면은 둘수 없어요 ㅠㅠ"); 
		printf("\n");
	}
	
	printf("└");
	
	for(int i=0; i<19; i++)
		printf("┴");
		
	printf("┘");
	
	move();
}

void move()
{
	while(1)
	{
		int a = getch();
		if(a == RIGHT&&c != 0)
		{
			if(omokdoll[b][c] == 3)
				omokdoll[b][c] = 0;
			c++;
			if(omokdoll[b][c] == 0)
				omokdoll[b][c] = 3;
			makeomok();
		}
		else if(a == LEFT&&c != 19)
		{
			if(omokdoll[b][c] == 3)
				omokdoll[b][c] = 0;
			c--;
			if(omokdoll[b][c] == 0)
				omokdoll[b][c] = 3;
			makeomok();
		}
		else if(a == UP&&b != 0)
		{
			if(omokdoll[b][c] == 3)
				omokdoll[b][c] = 0;
			b--;
			if(omokdoll[b][c] == 0)
				omokdoll[b][c] = 3;
			makeomok();
		}
		else if(a == DOWN&&b != 19)
		{
			if(omokdoll[b][c] == 3)
				omokdoll[b][c] = 0;
			b++;
			if(omokdoll[b][c] == 0)
				omokdoll[b][c] = 3;
			makeomok();
		}
		else if(a == spacebar&&omokdoll[b][c] == 3)
		{
			if(d == 0)
			{
				if(omokdoll[b+1][c] == 0)
					black_Q[b+1][c] += 1;
				if(omokdoll[b][c+1] == 0)
					black_Q[b][c+1] += 1;
				if(omokdoll[b-1][c] == 0)
					black_Q[b-1][c] += 1;
				if(omokdoll[b][c-1] == 0)
					black_Q[b][c-1] += 1;
				if(omokdoll[b+1][c+1] == 0)
					black_Q[b+1][c+1] += 1;
				if(omokdoll[b-1][c-1] == 0)
					black_Q[b-1][c-1] += 1;
				if(omokdoll[b-1][c+1] == 0)
					black_Q[b-1][c+1] += 1;
				if(omokdoll[b+1][c-1] == 0)
					black_Q[b+1][c-1] += 1;
				if(omokdoll[b+1][c] == 0)
					white_Q[b+1][c] -= 1;
				if(omokdoll[b][c+1] == 0)
					white_Q[b][c+1] -= 1;
				if(omokdoll[b-1][c] == 0)
					white_Q[b-1][c] -= 1;
				if(omokdoll[b][c-1] == 0)
					white_Q[b][c-1] -= 1;
				if(omokdoll[b+1][c+1] == 0)
					white_Q[b+1][c+1] -= 1;
				if(omokdoll[b-1][c-1] == 0)
					white_Q[b-1][c-1] -= 1;
				if(omokdoll[b-1][c+1] == 0)
					white_Q[b-1][c+1] -= 1;
				if(omokdoll[b+1][c-1] == 0)
					white_Q[b+1][c-1] -= 1;
				omokdoll[b][c] = 1;
				winner();
				black_node();
				black_Q[b][c] = 0;
				white_Q[b][c] = 0;
				d = 1;
				bak_AI();
			}
		}
		break;
	}
}

void black_node()
{
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
		{
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==1&&omokdoll[i+5][j+5]==0)
			{
				black_Q[i][j] += 10000;
				black_Q[i+5][j+5] += 10000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&omokdoll[i-4][j+4]==1&&omokdoll[i-5][j+5]==0)
			{
				black_Q[i][j] += 1000;
				black_Q[i-5][j+5] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==1&&omokdoll[i][j+5]==0)
			{
				black_Q[i][j] += 1000;
				black_Q[i][j+5] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==1&&omokdoll[i+5][j]==0)
			{
				black_Q[i][j] += 1000;
				black_Q[i+5][j] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==1&&omokdoll[i+5][j+5]==2)
				black_Q[i][j] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&omokdoll[i-4][j+4]==1&&omokdoll[i-5][j+5]==2)
				black_Q[i][j] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==1&&omokdoll[i][j+5]==2)
				black_Q[i][j] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==1&&omokdoll[i+5][j]==2)
				black_Q[i][j] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==1&&omokdoll[i+5][j+5]==0)
				black_Q[i+5][j+5] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&omokdoll[i-4][j+4]==1&&omokdoll[i-5][j+5]==0)
				black_Q[i-5][j+5] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==1&&omokdoll[i][j+5]==0)
				black_Q[i][j+5] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==1&&omokdoll[i+5][j]==0)
				black_Q[i+5][j] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==0&&omokdoll[i][j+4]==1)
				black_Q[i][j+3] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==1)
				black_Q[i][j+1] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i+1][j]==0&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==1)
				black_Q[i+1][j] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==0&&omokdoll[i+4][j]==1)
				black_Q[i+3][j] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==0&&omokdoll[i+4][j+4]==1)
				black_Q[i+3][j+3] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==1)
				black_Q[i+1][j+1] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i+1][j-1]==0&&omokdoll[i+2][j-2]==1&&omokdoll[i+3][j-3]==1&&omokdoll[i+4][j-4]==1)
				black_Q[i+1][j-1] += 1000;
			if(omokdoll[i][j] == 1&&omokdoll[i+1][j-1]==1&&omokdoll[i+2][j-2]==1&&omokdoll[i+3][j-3]==0&&omokdoll[i+4][j-4]==1)
				black_Q[i+3][j-3] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&(omokdoll[i-1][j+1]==1||omokdoll[i-1][j+3]==1||omokdoll[i+1][j+1]==1||omokdoll[i+1][j+3]==1)&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==0)
			{
				black_Q[i][j] += 21;
				black_Q[i][j+4] += 21;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&(omokdoll[i+1][j-1]==1||omokdoll[i+3][j-1]==1||omokdoll[i+1][j+1]==1||omokdoll[i+3][j+1]==1)&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==0)
			{
				black_Q[i][j] += 21;
				black_Q[i+4][j] += 21;
			}
			if(omokdoll[i][j]==1&&omokdoll[i-1][j]==0&&omokdoll[i-2][j]==1&&omokdoll[i-1][j+1]==1&&omokdoll[i-1][j+2]==1)
				black_Q[i-1][j] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j]==0&&omokdoll[i-2][j]==1&&omokdoll[i-1][j-1]==1&&omokdoll[i-1][j-2]==1)
				black_Q[i][j+1] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==1&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+1]==1)
				black_Q[i][j+1] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==1&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+1]==1)
				black_Q[i][j+1] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j+1]==0&&omokdoll[i-2][j+2]==1&&omokdoll[i][j+2]==1&&omokdoll[i+1][j+3]==1)
				black_Q[i-1][j+1] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j+1]==0&&omokdoll[i-2][j]==1&&omokdoll[i-3][j-1]==1&&omokdoll[i-4][j-2]==1)
				black_Q[i-1][j+1] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j-1]==1)
				black_Q[i+1][j+1] += 20;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==1&&omokdoll[i][j+2]==1&&omokdoll[i-1][j+3]==1)
				black_Q[i+1][j+1] += 20;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==0)
			{
				black_Q[i][j] += 50;
				black_Q[i+4][j+4] += 50;
			}
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&omokdoll[i-4][j+4]==0)
			{
				black_Q[i][j] += 50;
				black_Q[i-4][j+4] += 50;
			}
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==0)
			{
				black_Q[i][j] += 50;
				black_Q[i][j+4] += 50;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==0)
			{
				black_Q[i][j] += 50;
				black_Q[i+4][j] += 50;
			}
			if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==0&&omokdoll[i+3][j+3]==1&&(omokdoll[i+4][j+4]==0||omokdoll[i-1][j-1]==0))
				black_Q[i+2][j+2] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&(omokdoll[i+4][j+4]==0||omokdoll[i-1][j-1]==0))
				black_Q[i+1][j+1] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==0&&omokdoll[i-3][j+3]==1&&(omokdoll[i-4][j+4]==0||omokdoll[i+1][j-1]==0))
				black_Q[i-2][j+2] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j+1]==0&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&(omokdoll[i-4][j+4]==0||omokdoll[i+1][j-1]==0))
				black_Q[i-1][j+1] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==0&&omokdoll[i][j+3]==1&&(omokdoll[i][j+4]==0&&omokdoll[i][j-1]==0))
				black_Q[i][j+2] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&(omokdoll[i][j+4]==0&&omokdoll[i][j-1]==0))
				black_Q[i][j+1] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==0&&omokdoll[i+3][j]==1&&(omokdoll[i+4][j]==0&&omokdoll[i-1][j]==0))
				black_Q[i+2][j] += 7;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j]==0&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&(omokdoll[i+4][j]==0&&omokdoll[i-1][j]==0))
				black_Q[i+1][j] += 7;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==2)
				black_Q[i][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&omokdoll[i-4][j+4]==2)
				black_Q[i][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==2)
				black_Q[i][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==2)
				black_Q[i][j] += 5;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==0)
				black_Q[i+4][j+4] += 5;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==1&&omokdoll[i-4][j+4]==0)
				black_Q[i-4][j+4] += 5;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==0)
				black_Q[i][j+4] += 5;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==0)
				black_Q[i+4][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==0)
			{
				black_Q[i][j] += 2;
				black_Q[i][j+3] += 2;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==0)
			{
				black_Q[i][j] += 2;
				black_Q[i+3][j] += 2;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==0)
			{
				black_Q[i][j] += 2;
				black_Q[i+3][j+3] += 2;
			}
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==0)
			{
				black_Q[i][j] += 2;
				black_Q[i-3][j+3] += 2;
			}
			
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==0)
				black_Q[i][j+3] += 1;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==0)
				black_Q[i+3][j] += 1;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==0)
				black_Q[i+3][j+3] += 1;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==0)
				black_Q[i-3][j+3] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==2)
				black_Q[i][j] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==2)
				black_Q[i][j] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==2)
				black_Q[i][j] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==1&&omokdoll[i-2][j+2]==1&&omokdoll[i-3][j+3]==2)
				black_Q[i][j] += 1;
		}
}

void winner()
{
	for(int i = 0; i < 19; i++)
	{
		for(int j = 0; j < 19; j++)
		{
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==1&&omokdoll[i][j+2]==1&&omokdoll[i][j+3]==1&&omokdoll[i][j+4]==1)
			{
				printf("백이 승리하였습니다.");
				getchar(); 
				exit(1);
			}
			else if(omokdoll[i][j]==1&&omokdoll[i+1][j]==1&&omokdoll[i+2][j]==1&&omokdoll[i+3][j]==1&&omokdoll[i+4][j]==1)
			{
				printf("백이 승리하였습니다.");
				getchar();
				exit(1);
			}
			else if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==1&&omokdoll[i+2][j+2]==1&&omokdoll[i+3][j+3]==1&&omokdoll[i+4][j+4]==1)
			{
				printf("백이 승리하였습니다.");
				getchar();
				exit(1);
			}
			else if(omokdoll[i][j]==1&&omokdoll[i+1][j-1]==1&&omokdoll[i+2][j-2]==1&&omokdoll[i+3][j-3]==1&&omokdoll[i+4][j-4]==1)
			{
				printf("백이 승리하였습니다.");
				getchar();
				exit(1);
			}
			else if(omokdoll[i][j]==2&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==2)
			{
				printf("흑이 승리하였습니다.");
				getchar();
				exit(1);
			}
			else if(omokdoll[i][j]==2&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==2)
			{
				printf("흑이 승리하였습니다.");
				getchar();
				exit(1);
			}
			else if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==2)
			{
				printf("흑이 승리하였습니다.");
				getchar();
				exit(1);
			}
			else if(omokdoll[i][j]==2&&omokdoll[i+1][j-1]==2&&omokdoll[i+2][j-2]==2&&omokdoll[i+3][j-3]==2&&omokdoll[i+4][j-4]==2)
			{
				printf("흑이 승리하였습니다.");
				getchar();
				exit(1);
			}
		}
	}
}

void bak_AI()
{
	int whitemax,blackmax;
	char bayal[Size][Size] = {0};
	int gajungchi;
	
	srand(time(NULL));
	
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			if(blackmax < black_Q[i][j])
				blackmax = black_Q[i][j];
			
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			if(whitemax < white_Q[i][j])
				whitemax = white_Q[i][j];
			
	if(blackmax >= whitemax)
	{
		bak_Defence(blackmax);
	}
	else
	{
		bak_Attack(whitemax);
	}
	
	d = 0;
	winner();
	makeomok();
	white_node();
	move();
}

void bak_Attack(int max)
{
	int x[19] = {0};
	int y[19] = {0};
	int cnt = 0;
	
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			if(max == white_Q[i][j])
			{
				x[cnt] = i;
				y[cnt] = j;
				cnt++;
			}
			
	int randomnum = rand()%cnt;
	omokdoll[x[randomnum]][y[randomnum]] = 2;
	black_Q[x[randomnum]][y[randomnum]] = 0;
	white_Q[x[randomnum]][y[randomnum]] = 0;
	if(omokdoll[x[randomnum]+1][y[randomnum]] == 0)
		black_Q[x[randomnum]+1][y[randomnum]] -= 5;
	if(omokdoll[x[randomnum]][y[randomnum]+1] == 0)
		black_Q[x[randomnum]][y[randomnum]+1] -= 5;
	if(omokdoll[x[randomnum]-1][y[randomnum]] == 0)
		black_Q[x[randomnum]-1][y[randomnum]] -= 5;
	if(omokdoll[x[randomnum]][y[randomnum]-1] == 0)
		black_Q[x[randomnum]][y[randomnum]-1] -= 5;
	if(omokdoll[x[randomnum]+1][y[randomnum]+1] == 0)
		black_Q[x[randomnum]+1][y[randomnum]+1] -= 5;
	if(omokdoll[x[randomnum]-1][y[randomnum]-1] == 0)
		black_Q[x[randomnum]-1][y[randomnum]-1] -= 5;
	if(omokdoll[x[randomnum]-1][y[randomnum]+1] == 0)
		black_Q[x[randomnum]-1][y[randomnum]+1] -= 5;
	if(omokdoll[x[randomnum]+1][y[randomnum]-1] == 0)
		black_Q[x[randomnum]+1][y[randomnum]-1] -= 5;
	if(omokdoll[x[randomnum]+1][y[randomnum]] == 0)
		white_Q[x[randomnum]+1][y[randomnum]] += 5;
	if(omokdoll[x[randomnum]][y[randomnum]+1] == 0)
		white_Q[x[randomnum]+1][y[randomnum]+1] += 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]] == 0)
		white_Q[x[randomnum]-1][y[randomnum]] += 5;
	if(omokdoll[x[randomnum]][y[randomnum]-1] == 0)
		white_Q[x[randomnum]][y[randomnum]-1] += 5;
	if(omokdoll[x[randomnum]+1][y[randomnum]+1] == 0)
		white_Q[x[randomnum]+1][y[randomnum]+1] += 5;
	if(omokdoll[x[randomnum]-1][y[randomnum]-1] == 0)
		white_Q[x[randomnum]-1][y[randomnum]-1] += 5;
	if(omokdoll[x[randomnum]-1][y[randomnum]+1] == 0)
		white_Q[x[randomnum]-1][y[randomnum]+1] += 5;
	if(omokdoll[x[randomnum]+1][y[randomnum]-1] == 0)
		white_Q[x[randomnum]+1][y[randomnum]-1] += 5;	
}

void bak_Defence(int max)
{
	int x[19] = {0};
	int y[19] = {0};
	int cnt = 0;
	
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
			if(max == black_Q[i][j])
			{
				x[cnt] = i;
				y[cnt] = j;
				cnt++;
			}
			
	int randomnum = rand()%cnt;
	omokdoll[x[randomnum]][y[randomnum]] = 2;
	black_Q[x[randomnum]][y[randomnum]] = 0;
	white_Q[x[randomnum]][y[randomnum]] = 0;
	if(omokdoll[x[randomnum]+1][y[randomnum]] == 0)
		black_Q[x[randomnum]+1][y[randomnum]] -= 1;
	if(omokdoll[x[randomnum]][y[randomnum]+1] == 0)
		black_Q[x[randomnum]][y[randomnum]+1] -= 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]] == 0)
		black_Q[x[randomnum]-1][y[randomnum]] -= 1;
	if(omokdoll[x[randomnum]][y[randomnum]-1] == 0)
		black_Q[x[randomnum]][y[randomnum]-1] -= 1;
	if(omokdoll[x[randomnum]+1][y[randomnum]+1] == 0)
		black_Q[x[randomnum]+1][y[randomnum]+1] -= 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]-1] == 0)
		black_Q[x[randomnum]-1][y[randomnum]-1] -= 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]+1] == 0)
		black_Q[x[randomnum]-1][y[randomnum]+1] -= 1;
	if(omokdoll[x[randomnum]+1][y[randomnum]-1] == 0)
		black_Q[x[randomnum]+1][y[randomnum]-1] -= 1;
	if(omokdoll[x[randomnum]+1][y[randomnum]] == 0)
		white_Q[x[randomnum]+1][y[randomnum]] += 1;
	if(omokdoll[x[randomnum]][y[randomnum]+1] == 0)
		white_Q[x[randomnum]+1][y[randomnum]+1] += 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]] == 0)
		white_Q[x[randomnum]-1][y[randomnum]] += 1;
	if(omokdoll[x[randomnum]][y[randomnum]-1] == 0)
		white_Q[x[randomnum]][y[randomnum]-1] += 1;
	if(omokdoll[x[randomnum]+1][y[randomnum]+1] == 0)
		white_Q[x[randomnum]+1][y[randomnum]+1] += 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]-1] == 0)
		white_Q[x[randomnum]-1][y[randomnum]-1] += 1;
	if(omokdoll[x[randomnum]-1][y[randomnum]+1] == 0)
		white_Q[x[randomnum]-1][y[randomnum]+1] += 1;
	if(omokdoll[x[randomnum]+1][y[randomnum]-1] == 0)
		white_Q[x[randomnum]+1][y[randomnum]-1] += 1;			
}

void white_node()
{
	for(int i = 0; i < 19; i++)
		for(int j = 0; j < 19; j++)
		{
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==2&&omokdoll[i+5][j+5]==0)
			{
				white_Q[i][j] += 1000;
				white_Q[i+5][j+5] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&omokdoll[i-4][j+4]==2&&omokdoll[i-5][j+5]==0)
			{
				white_Q[i][j] += 1000;
				white_Q[i-5][j+5] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==2&&omokdoll[i][j+5]==0)
			{
				white_Q[i][j] += 1000;
				white_Q[i][j+5] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==2&&omokdoll[i+5][j]==0)
			{
				white_Q[i][j] += 1000;
				white_Q[i+5][j] += 1000;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==2&&omokdoll[i+5][j+5]==2)
				white_Q[i][j] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&omokdoll[i-4][j+4]==2&&omokdoll[i-5][j+5]==2)
				white_Q[i][j] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==2&&omokdoll[i][j+5]==2)
				white_Q[i][j] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==2&&omokdoll[i+5][j]==2)
				white_Q[i][j] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==2&&omokdoll[i+5][j+5]==0)
				white_Q[i+5][j+5] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&omokdoll[i-4][j+4]==2&&omokdoll[i-5][j+5]==0)
				white_Q[i-5][j+5] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==2&&omokdoll[i][j+5]==0)
				white_Q[i][j+5] += 1000;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==2&&omokdoll[i+5][j]==0)
				white_Q[i+5][j] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==0&&omokdoll[i][j+4]==2)
				white_Q[i][j+3] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==2)
				white_Q[i][j+1] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i+1][j]==0&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==2)
				white_Q[i+1][j] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==0&&omokdoll[i+4][j]==2)
				white_Q[i+3][j] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==0&&omokdoll[i+4][j+4]==2)
				white_Q[i+3][j+3] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==2)
				white_Q[i+1][j+1] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i+1][j-1]==0&&omokdoll[i+2][j-2]==2&&omokdoll[i+3][j-3]==2&&omokdoll[i+4][j-4]==2)
				white_Q[i+1][j-1] += 1000;
			if(omokdoll[i][j] == 2&&omokdoll[i+1][j-1]==2&&omokdoll[i+2][j-2]==2&&omokdoll[i+3][j-3]==0&&omokdoll[i+4][j-4]==2)
				white_Q[i+3][j-3] += 1000;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&(omokdoll[i-1][j+1]==2||omokdoll[i-1][j+3]==2||omokdoll[i+1][j+1]==2||omokdoll[i+1][j+3]==2)&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==0)
			{
				white_Q[i][j] += 21;
				white_Q[i][j+4] += 21;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&(omokdoll[i+1][j-1]==2||omokdoll[i+3][j-1]==2||omokdoll[i+1][j+1]==2||omokdoll[i+3][j+1]==2)&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==0)
			{
				white_Q[i][j] += 21;
				white_Q[i+4][j] += 21;
			}
			if(omokdoll[i][j]==2&&omokdoll[i-1][j]==0&&omokdoll[i-2][j]==2&&omokdoll[i-1][j+1]==2&&omokdoll[i-1][j+2]==2)
				white_Q[i-1][j] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j]==0&&omokdoll[i-2][j]==2&&omokdoll[i-1][j-1]==2&&omokdoll[i-1][j-2]==2)
				white_Q[i][j+1] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==2&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+1]==2)
				white_Q[i][j+1] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==2&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+1]==2)
				white_Q[i][j+1] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==0&&omokdoll[i-2][j+2]==2&&omokdoll[i][j+2]==2&&omokdoll[i+1][j+3]==2)
				white_Q[i-1][j+1] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==0&&omokdoll[i-2][j]==2&&omokdoll[i-3][j-1]==2&&omokdoll[i-4][j-2]==2)
				white_Q[i-1][j+1] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j-1]==2)
				white_Q[i+1][j+1] += 20;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==2&&omokdoll[i][j+2]==2&&omokdoll[i-1][j+3]==2)
				white_Q[i+1][j+1] += 20;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==0)
			{
				white_Q[i][j] += 50;
				white_Q[i+4][j+4] += 50;
			}
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&omokdoll[i-4][j+4]==0)
			{
				white_Q[i][j] += 50;
				white_Q[i-4][j+4] += 50;
			}
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==0)
			{
				white_Q[i][j] += 50;
				white_Q[i][j+4] += 50;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==0)
			{
				white_Q[i][j] += 50;
				white_Q[i+4][j] += 50;
			}
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==0&&omokdoll[i+3][j+3]==2&&(omokdoll[i+4][j+4]==0||omokdoll[i-1][j-1]==0))
				white_Q[i+2][j+2] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j+1]==0&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&(omokdoll[i+4][j+4]==0||omokdoll[i-1][j-1]==0))
				white_Q[i+1][j+1] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==0&&omokdoll[i-3][j+3]==2&&(omokdoll[i-4][j+4]==0||omokdoll[i+1][j-1]==0))
				white_Q[i-2][j+2] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i-1][j+1]==0&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&(omokdoll[i-4][j+4]==0||omokdoll[i+1][j-1]==0))
				white_Q[i-1][j+1] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==0&&omokdoll[i][j+3]==2&&(omokdoll[i][j+4]==0&&omokdoll[i][j-1]==0))
				white_Q[i][j+2] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i][j+1]==0&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&(omokdoll[i][j+4]==0&&omokdoll[i][j-1]==0))
				white_Q[i][j+1] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==0&&omokdoll[i+3][j]==2&&(omokdoll[i+4][j]==0&&omokdoll[i-1][j]==0))
				white_Q[i+2][j] += 7;
			if(omokdoll[i][j]==2&&omokdoll[i+1][j]==0&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&(omokdoll[i+4][j]==0&&omokdoll[i-1][j]==0))
				white_Q[i+1][j] += 7;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==1)
				white_Q[i][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&omokdoll[i-4][j+4]==1)
				white_Q[i][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==1)
				white_Q[i][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==1)
				white_Q[i][j] += 5;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==2&&omokdoll[i+4][j+4]==0)
				white_Q[i+4][j+4] += 5;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==2&&omokdoll[i-4][j+4]==0)
				white_Q[i-4][j+4] += 5;
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==2&&omokdoll[i][j+4]==0)
				white_Q[i][j+4] += 5;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==2&&omokdoll[i+4][j]==0)
				white_Q[i+4][j] += 5;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==0)
			{
				white_Q[i][j] += 2;
				white_Q[i][j+3] += 2;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==0)
			{
				white_Q[i][j] += 2;
				white_Q[i+3][j] += 2;
			}
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==0)
			{
				white_Q[i][j] += 2;
				white_Q[i+3][j+3] += 2;
			}
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==0)
			{
				white_Q[i][j] += 2;
				white_Q[i-3][j+3] += 2;
			}
			
			if(omokdoll[i][j]==1&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==0)
				white_Q[i][j+3] += 1;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==0)
				white_Q[i+3][j] += 1;
			if(omokdoll[i][j]==1&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==0)
				white_Q[i+3][j+3] += 1;
			if(omokdoll[i][j]==1&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==0)
				white_Q[i-3][j+3] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i][j+1]==2&&omokdoll[i][j+2]==2&&omokdoll[i][j+3]==1)
				white_Q[i][j] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j]==2&&omokdoll[i+2][j]==2&&omokdoll[i+3][j]==1)
				white_Q[i][j] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i+1][j+1]==2&&omokdoll[i+2][j+2]==2&&omokdoll[i+3][j+3]==1)
				white_Q[i][j] += 1;
			if(omokdoll[i][j]==0&&omokdoll[i-1][j+1]==2&&omokdoll[i-2][j+2]==2&&omokdoll[i-3][j+3]==1)
				white_Q[i][j] += 1;
		}
}
