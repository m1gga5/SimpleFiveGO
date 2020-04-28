//┌┬┐├┼┤└┴┘│─●○
#include<stdio.h>
#include<stdlib.h>
#define Row 19
#define Col 19
void DrawQiZi(int x,char *p)
//据棋盘单元格子当前的类型，和对应的特殊表格符，进行棋子或者 给定表格符的绘制 
{
	if (x==0)
		printf("●");
	if (x==1)
		printf("○");
	if (x==2)
		printf("%s",p);
}
void DrawQiPan(int qizi[Row][Col])
//据当前的棋局数组，绘制相应的棋盘。第一行、最后一行、中间行， 分别绘制
{
	int i,j;
	for (i=0;i<Row;i++)
	{
		if (i==0)
		{
			for (j=0;j<Col;j++)
			{
				if (j==0)
					DrawQiZi(qizi[i][j],"┌");
				if (j>0&&j<Col-1)
					DrawQiZi(qizi[i][j],"┬");
				if (j==Col-1)
					DrawQiZi(qizi[i][j],"┐");
			}
			printf("\n");
		}
		if (i>0&&i<Row-1)
		{
			for (j=0;j<Col;j++)
			{
				if (j==0)
					DrawQiZi(qizi[i][j],"├");
				if (j>0&&j<Col-1)
					DrawQiZi(qizi[i][j],"┼");
				if (j==Col-1)
					DrawQiZi(qizi[i][j],"┤");
			}
			printf("\n");
		}
		if (i==Row-1)
		{
			for (j=0;j<Col;j++)
			{
				if (j==0)
					DrawQiZi(qizi[i][j],"└");
				if (j>0&&j<Col-1)
					DrawQiZi(qizi[i][j],"┴");
				if (j==Col-1)
					DrawQiZi(qizi[i][j],"┘");
			}
			printf("\n");
		}
	}
}
void RandomCreateXY(int *P1,int *P2)
//通过 rand 函数生成随机数，产生棋子坐标，并通过指针修改主调函 数的 x，y
{
	*P1=rand()%Row-1;
	*P2=rand()%Col-1;
}
int IsFull(int qizi[Row][Col])
//判断棋盘是否满，如果 QiPan 二维数组中任一单元的值=2，则棋盘不满 
{
	int a,b,count=0;;
	for (a=0;a<Row;a++)
		for (b=0;b<Col;b++)
		{
			if (qizi[a][b]==2)
				count++;
		}
		if (count==0)
			return 1;
		if (count!=0)
			return 0;
}
int IsWin(int qizi[Row][Col])
//判断棋局黑赢还是白赢 
{
	int i,j;
	for (i=0;i<Row;i++)
		for (j=0;j<Col;j++)
		{
			if ((qizi[i][j]==0&&qizi[i-1][j-1]==0&&qizi[i-2][j-2]==0&&qizi[i-3][j-3]==0&&qizi[i-4][j-4]==0)||
				(qizi[i][j]==0&&qizi[i-1][j]==0&&qizi[i-2][j]==0&&qizi[i-3][j]==0&&qizi[i-4][j]==0)||
				(qizi[i][j]==0&&qizi[i][j-1]==0&&qizi[i][j-2]==0&&qizi[i][j-3]==0&&qizi[i][j-4]==0))
				return 1;
			if ((qizi[i][j]==1&&qizi[i-1][j-1]==1&&qizi[i-2][j-2]==1&&qizi[i-3][j-3]==1&&qizi[i-4][j-4]==1)||
				(qizi[i][j]==1&&qizi[i-1][j]==1&&qizi[i-2][j]==1&&qizi[i-3][j]==1&&qizi[i-4][j]==1)||
				(qizi[i][j]==1&&qizi[i][j-1]==1&&qizi[i][j-2]==1&&qizi[i][j-3]==1&&qizi[i][j-4]==1))
				return 2;
		}
}
void Person_Computer_Random(int qizi[Row][Col])
/*
人-机大战（随机算法）
1.初始化 QiPan 二维数组， QiPan[i][j]=2     
2.判断是否棋盘满 IsFull，是否已赢棋 IsWin      
3.画棋盘 DrawQiPan      
4.人下棋：输入棋子坐标，更新棋盘单元值 QiPan[x][y]=0，画棋盘 DrawQiPan     
5.电脑随机下棋 RandomCreateXY，更新棋盘单元值 QiPan[x][y]=1， 画棋盘 DrawQiPan     
6.重复 1~5
*/ 
{
	int x,y;
	DrawQiPan(qizi);
	while(IsFull(qizi)!=1&&IsWin(qizi)!=1&&IsWin(qizi)!=2)
	{		
		printf("请输入行数：");
		scanf("%d",&x);
		printf("请输入列数：");
		scanf("%d",&y);	
		while(qizi[x][y]!=2)
		{
			printf("此处已有棋子！\n");
			printf("请重新输入行数：");
			scanf("%d",&x);
			printf("请重新输入列数：");
			scanf("%d",&y);
		}
		qizi[x][y]=1;
		RandomCreateXY(&x,&y);
		while(qizi[x][y]!=2)
		{
			RandomCreateXY(&x,&y);
		}
		qizi[x][y]=0;
		DrawQiPan(qizi);
	}
	if (IsFull(qizi)==1)
		printf("平局！\n");
	if (IsWin(qizi)==1)
		printf("黑子赢了！\n");
	if (IsWin(qizi)==2)
		printf("白子赢了！\n");
}
void Person_Person(int qizi[Row][Col])
//人人控制对战
{
	int x,y;
	DrawQiPan(qizi);
	while(IsFull(qizi)!=1&&IsWin(qizi)!=1&&IsWin(qizi)!=2)
	{
		printf("请玩家1输入行数：");
		scanf("%d",&x);
		printf("请玩家1输入列数：");
		scanf("%d",&y);
		while(qizi[x][y]!=2)
		{
			printf("此处已有棋子！\n");
			printf("请重新输入行数：");
			scanf("%d",&x);
			printf("请重新输入列数：");
			scanf("%d",&y);
		}
		qizi[x][y]=1;
		DrawQiPan(qizi);
		printf("请玩家2输入行数：");
		scanf("%d",&x);
		printf("请玩家2输入列数：");
		scanf("%d",&y);
		while(qizi[x][y]!=2)
		{
			printf("此处已有棋子！\n");
			printf("请重新输入行数：");
			scanf("%d",&x);
			printf("请重新输入列数：");
			scanf("%d",&y);
		}
		qizi[x][y]=0;
		DrawQiPan(qizi);
	}
	if (IsFull(qizi)==1)
		printf("平局！\n");
	if (IsWin(qizi)==1)
		printf("黑子赢了！\n");
	if (IsWin(qizi)==2)
		printf("白子赢了！\n");
}

void Menu(int qizi[Row][Col])
//打印系统主菜单 
{
	int model;
	printf("FiveGo\n");
	printf("制作者：刘子壮\n");
	printf("请选择模式：\n");
	printf("1.人-人对战\n");
	printf("2.人-机对战（简易）\n");
	printf("3.人-机对战（AI）\n");
	printf("4.退出\n");
	scanf("%d",&model);
	if (model==1)
	{
		Person_Person(qizi);
	}
	if (model==2)
	{
		Person_Computer_Random(qizi);
	}
	if (model==3)
	{
	
	}
	if (model==4)
		return;
}
int main()
//系统入口函数 
{
	int n,i,j;
	int qizi[Row][Col];
	for (i=0;i<Row;i++)
		for (j=0;j<Col;j++)
			qizi[i][j]=2;
		Menu(qizi);
}