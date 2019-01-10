//****************ģ��ATM****************
//����:��¶¶
//�汾:v1.0
//����ʱ��:2017.04.10
//��Ҫ����:
//	1.ģ��ATM(�Զ���Ա��)�����档
//	2.ģ��ATM(�Զ���Ա��)��ѯ����(Quary)��
//	3.ģ��ATM(�Զ���Ա��)����(Credit)��
//	4.ģ��ATM(�Զ���Ա��)ȡ���(Debit)��
//	5.�˳�����(������������)��
//Ҫ��:
//  1.���ļ������û����ź����룬���Խ���������֤��
//  2.��ɴ�ӡƾ�����ܡ�
//****************************************
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 200
 
void enterATM();		//ATM�˺����뺯��  
void inputMima();       //�������뺯��
void menu();            //������������
void Debit();           //ȡ���
void success();         //�����ɹ�����
void delay();           //��ʱ����
void Quary();           //����ѯ����
void Credit();          //����
void panDuan(double z); //�ж�ȡ���Ƿ�Ϸ�����
void exit();            //�˳����溯��
void miMa();            //�����޸�
void read();            //�ļ�д�뺯��
void write();           //�ļ���ȡ����
 
typedef struct 
{
	int zhanghao;
	int mima;
	double yu_e;
}atm;
atm ATM[N];
int k;
 
//ATM�˺����뺯�� 
void enterATM()
{
	delay();
	system("cls");
	read();
	printf("*******************************\n");
	printf("*     ��ӭʹ�� ATM ��̨��     *\n");
	printf("*          �����뿨��         *\n");
	int user;
	scanf("%d",&user);
	if(user==0)
	{
		printf("*        �˺Ŵ���       *\n");
		enterATM();
	}
	else if(user!=(ATM[k].zhanghao)) 
	{
	for(k=1;k<N;k++)
	{
	if(user==(ATM[k].zhanghao)) 
		inputMima( );
	}
	system("cls");
	printf("*    �˻������ڣ����������    *\n");
	enterATM();
	}
	else
	inputMima( );
}
 
//�������뺯��
void inputMima( )
{
	int code;
	int temp=3;
	read();
	system("cls");
	printf("*          ����������          *\n");
	scanf("%d",&code);
	while(code!=ATM[k].mima)
	{
		temp--;
		system("cls");
		printf("*     �����������������     *\n");
		printf("*        ������ ");
		printf("%d",temp);
		printf(" �λ���       *\n");
		scanf("%d",&code);		
		if(temp==1)
		{
			system("cls");
			printf("*      ���Ѿ� 3 ����������     *\n");
			printf("*         ϵͳ���˳�����       *\n");
			delay();
			enterATM();
		}
	}
	menu();
}
 
//ȡ���
void Debit()
{
	double temp;
	system("cls");
	printf("     ��ѡ����Ҫȡ��Ľ��     \n");
	printf("        1.100    2.200        \n");
	printf("        3.500    4.800        \n");
	printf("        5.1000   6.����       \n");
	printf("        7.����   8.�˳�       \n");
	switch(getch())
	{
	case '1': panDuan(100);
		break;
	case '2': panDuan(200);
		break;
	case '3': panDuan(500);
		break;
	case '4': panDuan(800);
		break;
	case '5': panDuan(1000);
		break;
	case '6':
		system("cls");
		printf("��������Ҫȡ��Ľ��:");
		scanf("%lf",&temp);
		panDuan(temp);
		break;
	case '7':menu();
		break;
	case '8':exit();
		break;
	}
}
 
//����ѯ����
void Quary()
{
	read();
	system("cls");
	printf("������Ϊ��%lf\n",(ATM[k].yu_e));
	printf("1.����      2.�˳�     \n");
	switch(getch())
	{
	case '1': menu();
		break;
	case '2': exit();
		break;
	}
}
 
//�ж�ȡ���Ƿ�Ϸ�����
void panDuan(double z)
{
	int beishu;
	if(z>(ATM[k].yu_e))
	{
		system("cls");
		printf("           ���㣡         \n");
		printf("          �����²���          \n");
		printf("     1.����       2.�˳�      \n");
		switch(getch())
		{
		case '1': Debit();
		case '2': exit();
		}
	}
	beishu=(int)z%100;
	if(beishu!=0)
	{
		system("cls");
		delay( );
		printf("  ��ATM��ֻ֧�� 100 �������  \n");
		printf("           �����²���         \n");
		printf("                              \n");
		printf("     1.����        2.�˳�     \n");
		switch(getch())
		{
		case '1': Debit();
		case '2': exit();
		}
	}
	if(z==5000.00||z>5000.00)
	{
		system("cls");
		printf("    ÿ��ȡ��ܳ��� 5000 Ԫ  \n");
		printf("           �����²���         \n");
		printf("                              \n");
		printf("     1.����        2.�˳�     \n");
		switch(getch())
		{
		case '1': Debit();
		case '2': exit();
		}
	}
	(ATM[k].yu_e)-=z;
	write();
	success();
}
 
//����
void Credit( )
{
	double cun;
	system("cls");
	printf(" ����������:");
	scanf("%lf",&cun);
	while(cun<0)
	{
		system("cls");
		printf("            �Ƿ����          \n");
		printf("        �����·��������      \n");
		scanf("%lf",&cun);
	}
	(ATM[k].yu_e)+=cun;
	write();
	success();
}
 
//�����޸ĺ���
void miMa()
{
	int mm1,mm2,mm3;
	int temp;
	system("cls");
	printf("������:");
	scanf("%d",&mm1);
	printf("\n");
	if(mm1!=ATM[k].mima)
	{
		system("cls");
		printf("���������,����������\n");
		delay();
		miMa();
	}
	printf("������:");
	scanf("%d",&mm2);
	if(mm2<100000||mm2>999999)
	{
		system("cls");
		printf("        ����������6λ��  \n");
		printf("           ���������룡    \n");
		delay();
		miMa();
	}
	temp=mm2%111111;
	if(temp==0)
	{
		system("cls");
		printf("          ������ڼ�       \n");
		printf("           ���������룡      \n");
		delay( );
		miMa( );
	}
	printf("\n");
	printf("ȷ��������:");
	scanf("%d",&mm3);
	if(mm2!=mm3)
	{
		system("cls");
		printf("ȷ�����벻һ��,����������\n");
		delay( );
		miMa();
	}	
	if(mm3=mm2)
	{
		ATM[k].mima=mm3;
		write();
		success();
	}
}
 
//��ʱ����
void delay( )
{
	long int bl1; 
	int bl2;
	for(bl1=600000;bl1>0;bl1--)
	{
		for(bl2=300;bl2>0;bl2--);
	}
}
 
//�����ɹ�����
void success( )
{
	system("cls");
	printf("           �����ѳɹ�         \n");
	printf("                              \n");
	printf("     1.����        2.�˳�     \n");
	switch(getch())
	{
	case '1':menu();
		break;
	case '2':exit();
		break;
	}
}
 
//ϵͳ�˳�����
void exit()
{
	system("cls");
	printf("*        ��ӭ�����ٴ�ʹ��      *\n");
	printf("*         ϵͳ�����˳�...      *\n");
	delay();
	enterATM();
}
 
//�ļ���ȡ����
void read()
{
	int i;
	FILE *fp;
	fp=fopen("xinxi.txt","r");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	for(i=0;i<N;i++)
	{
		
		fscanf(fp,"%d",&(ATM[i].zhanghao));
		fscanf(fp,"%d",&(ATM[i].mima));
		fscanf(fp,"%lf\n",&(ATM[i].yu_e));
	}
	fclose(fp);
}
 
//�ļ�д�뺯��
void write()
{
	int i;
	FILE *fp;
	fp=fopen("xinxi.txt","w");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��\n");
		return;
	}
	for(i=0;i<N;i++)
	{
		fprintf(fp,"%d",ATM[i].zhanghao);
		fprintf(fp,"%d",ATM[i].mima);
		fprintf(fp,"%lf\n",ATM[i].yu_e);
	}
	fclose(fp);
}
 
//���������溯��
void menu( )
{
	system("cls");
	printf("********************************\n");
	printf("*         ��ѡ��һ��ҵ��       *\n");
	printf("*          1.�޸�����          *\n");
	printf("*          2.����ѯ          *\n");
	printf("*          3.ȡ��              *\n");
	printf("*          4.���              *\n");
	printf("*          5.�˳�              *\n");
	printf("********************************\n");
	switch(getch())
	{
	case '1': miMa();
		break;
	case '2': Quary();
		break;
	case '3': Debit();
		break;
	case '4': Credit();
		break;
	case '5': exit();
		break;
	default:
		{
			printf("\a�Ƿ�����\n");
			menu();
		};
	}
}
 
//������
int main()
{
	enterATM();
	return 0;	 
}
 
 
 
 
 
