#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include"game.h"


//测试三子棋游戏

void menu()
{
	printf("  *************************\n");
	printf(" ****** 1.play  0.exit ******\n");
	printf("  *************************\n");

}



void game()
{
	char ret = 0;
	//创建一个二维数组存放棋盘信息
	char board[ROW][COL] = { 0 };//全部都是空格
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
	    ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		Aimove(board, ROW, COL);
		DisplayBoard(board, ROW, COL); 
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}

void test()
{
	int input = 0;
	do
	{ 
		menu();
		srand((unsigned int)time(NULL));
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误 请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}