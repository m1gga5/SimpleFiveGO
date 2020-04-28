//���Щ�����ȩ��ة��������
#include<stdio.h>
#include<stdlib.h>
#define Row 19
#define Col 19
void DrawQiZi(int x,char *p)
//�����̵�Ԫ���ӵ�ǰ�����ͣ��Ͷ�Ӧ������������������ӻ��� ���������Ļ��� 
{
	if (x==0)
		printf("��");
	if (x==1)
		printf("��");
	if (x==2)
		printf("%s",p);
}
void DrawQiPan(int qizi[Row][Col])
//�ݵ�ǰ��������飬������Ӧ�����̡���һ�С����һ�С��м��У� �ֱ����
{
	int i,j;
	for (i=0;i<Row;i++)
	{
		if (i==0)
		{
			for (j=0;j<Col;j++)
			{
				if (j==0)
					DrawQiZi(qizi[i][j],"��");
				if (j>0&&j<Col-1)
					DrawQiZi(qizi[i][j],"��");
				if (j==Col-1)
					DrawQiZi(qizi[i][j],"��");
			}
			printf("\n");
		}
		if (i>0&&i<Row-1)
		{
			for (j=0;j<Col;j++)
			{
				if (j==0)
					DrawQiZi(qizi[i][j],"��");
				if (j>0&&j<Col-1)
					DrawQiZi(qizi[i][j],"��");
				if (j==Col-1)
					DrawQiZi(qizi[i][j],"��");
			}
			printf("\n");
		}
		if (i==Row-1)
		{
			for (j=0;j<Col;j++)
			{
				if (j==0)
					DrawQiZi(qizi[i][j],"��");
				if (j>0&&j<Col-1)
					DrawQiZi(qizi[i][j],"��");
				if (j==Col-1)
					DrawQiZi(qizi[i][j],"��");
			}
			printf("\n");
		}
	}
}
void RandomCreateXY(int *P1,int *P2)
//ͨ�� rand ��������������������������꣬��ͨ��ָ���޸������� ���� x��y
{
	*P1=rand()%Row-1;
	*P2=rand()%Col-1;
}
int IsFull(int qizi[Row][Col])
//�ж������Ƿ�������� QiPan ��ά��������һ��Ԫ��ֵ=2�������̲��� 
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
//�ж���ֺ�Ӯ���ǰ�Ӯ 
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
��-����ս������㷨��
1.��ʼ�� QiPan ��ά���飬 QiPan[i][j]=2     
2.�ж��Ƿ������� IsFull���Ƿ���Ӯ�� IsWin      
3.������ DrawQiPan      
4.�����壺�����������꣬�������̵�Ԫֵ QiPan[x][y]=0�������� DrawQiPan     
5.����������� RandomCreateXY���������̵�Ԫֵ QiPan[x][y]=1�� ������ DrawQiPan     
6.�ظ� 1~5
*/ 
{
	int x,y;
	DrawQiPan(qizi);
	while(IsFull(qizi)!=1&&IsWin(qizi)!=1&&IsWin(qizi)!=2)
	{		
		printf("������������");
		scanf("%d",&x);
		printf("������������");
		scanf("%d",&y);	
		while(qizi[x][y]!=2)
		{
			printf("�˴��������ӣ�\n");
			printf("����������������");
			scanf("%d",&x);
			printf("����������������");
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
		printf("ƽ�֣�\n");
	if (IsWin(qizi)==1)
		printf("����Ӯ�ˣ�\n");
	if (IsWin(qizi)==2)
		printf("����Ӯ�ˣ�\n");
}
void Person_Person(int qizi[Row][Col])
//���˿��ƶ�ս
{
	int x,y;
	DrawQiPan(qizi);
	while(IsFull(qizi)!=1&&IsWin(qizi)!=1&&IsWin(qizi)!=2)
	{
		printf("�����1����������");
		scanf("%d",&x);
		printf("�����1����������");
		scanf("%d",&y);
		while(qizi[x][y]!=2)
		{
			printf("�˴��������ӣ�\n");
			printf("����������������");
			scanf("%d",&x);
			printf("����������������");
			scanf("%d",&y);
		}
		qizi[x][y]=1;
		DrawQiPan(qizi);
		printf("�����2����������");
		scanf("%d",&x);
		printf("�����2����������");
		scanf("%d",&y);
		while(qizi[x][y]!=2)
		{
			printf("�˴��������ӣ�\n");
			printf("����������������");
			scanf("%d",&x);
			printf("����������������");
			scanf("%d",&y);
		}
		qizi[x][y]=0;
		DrawQiPan(qizi);
	}
	if (IsFull(qizi)==1)
		printf("ƽ�֣�\n");
	if (IsWin(qizi)==1)
		printf("����Ӯ�ˣ�\n");
	if (IsWin(qizi)==2)
		printf("����Ӯ�ˣ�\n");
}

void Menu(int qizi[Row][Col])
//��ӡϵͳ���˵� 
{
	int model;
	printf("FiveGo\n");
	printf("�����ߣ�����׳\n");
	printf("��ѡ��ģʽ��\n");
	printf("1.��-�˶�ս\n");
	printf("2.��-����ս�����ף�\n");
	printf("3.��-����ս��AI��\n");
	printf("4.�˳�\n");
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
//ϵͳ��ں��� 
{
	int n,i,j;
	int qizi[Row][Col];
	for (i=0;i<Row;i++)
		for (j=0;j<Col;j++)
			qizi[i][j]=2;
		Menu(qizi);
}