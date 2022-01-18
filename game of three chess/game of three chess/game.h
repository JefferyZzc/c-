#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<time.h>


//声明函数
void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void Playermove(char board[ROW][COL], int row, int col);

void Aimove(char board[ROW][COL], int row, int col);

//返回四种状态 
//玩家赢  *
//电脑赢  # 
//平局   Q
//继续   C
char Iswin(char board[ROW][COL], int row, int col);
