#define _CRT_SECURE_NO_WARNINGS 1

#include<string.h>
#include"game.h"


//������������Ϸ

void menu()
{
	printf("  *************************\n");
	printf(" ****** 1.play  0.exit ******\n");
	printf("  *************************\n");

}



void game()
{
	char ret = 0;
	//����һ����ά������������Ϣ
	char board[ROW][COL] = { 0 };//ȫ�����ǿո�
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		Playermove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
	    ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		Aimove(board, ROW, COL);
		DisplayBoard(board, ROW, COL); 
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("���Ӯ\n");
	else if (ret == '#')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
}

void test()
{
	int input = 0;
	do
	{ 
		menu();
		srand((unsigned int)time(NULL));
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ����� ������ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}