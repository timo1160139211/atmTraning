//****************模拟ATM****************
//作者:马露露
//版本:v1.0
//创建时间:2017.04.10
//主要功能:
//	1.模拟ATM(自动柜员机)主界面。
//	2.模拟ATM(自动柜员机)查询功能(Quary)。
//	3.模拟ATM(自动柜员机)存款功能(Credit)。
//	4.模拟ATM(自动柜员机)取款功能(Debit)。
//	5.退出功能(即返回主界面)。
//要求:
//  1.用文件保存用户卡号和密码，用以进行身份验证。
//  2.完成打印凭条功能。
//****************************************
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define N 200
 
void enterATM();		//ATM账号输入函数  
void inputMima();       //密码输入函数
void menu();            //基本操作界面
void Debit();           //取款函数
void success();         //操作成功函数
void delay();           //延时函数
void Quary();           //余额查询函数
void Credit();          //存款函数
void panDuan(double z); //判断取款是否合法函数
void exit();            //退出界面函数
void miMa();            //密码修改
void read();            //文件写入函数
void write();           //文件读取函数
 
typedef struct 
{
	int zhanghao;
	int mima;
	double yu_e;
}atm;
atm ATM[N];
int k;
 
//ATM账号输入函数 
void enterATM()
{
	delay();
	system("cls");
	read();
	printf("*******************************\n");
	printf("*     欢迎使用 ATM 柜台机     *\n");
	printf("*          请输入卡号         *\n");
	int user;
	scanf("%d",&user);
	if(user==0)
	{
		printf("*        账号错误       *\n");
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
	printf("*    账户不存在，请从新输入    *\n");
	enterATM();
	}
	else
	inputMima( );
}
 
//密码输入函数
void inputMima( )
{
	int code;
	int temp=3;
	read();
	system("cls");
	printf("*          请输入密码          *\n");
	scanf("%d",&code);
	while(code!=ATM[k].mima)
	{
		temp--;
		system("cls");
		printf("*     密码错误，请重新输入     *\n");
		printf("*        您还有 ");
		printf("%d",temp);
		printf(" 次机会       *\n");
		scanf("%d",&code);		
		if(temp==1)
		{
			system("cls");
			printf("*      您已经 3 次输入密码     *\n");
			printf("*         系统将退出操作       *\n");
			delay();
			enterATM();
		}
	}
	menu();
}
 
//取款函数
void Debit()
{
	double temp;
	system("cls");
	printf("     请选择您要取款的金额     \n");
	printf("        1.100    2.200        \n");
	printf("        3.500    4.800        \n");
	printf("        5.1000   6.其它       \n");
	printf("        7.返回   8.退出       \n");
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
		printf("请输入您要取款的金额:");
		scanf("%lf",&temp);
		panDuan(temp);
		break;
	case '7':menu();
		break;
	case '8':exit();
		break;
	}
}
 
//余额查询函数
void Quary()
{
	read();
	system("cls");
	printf("你的余额为：%lf\n",(ATM[k].yu_e));
	printf("1.返回      2.退出     \n");
	switch(getch())
	{
	case '1': menu();
		break;
	case '2': exit();
		break;
	}
}
 
//判断取款是否合法函数
void panDuan(double z)
{
	int beishu;
	if(z>(ATM[k].yu_e))
	{
		system("cls");
		printf("           余额不足！         \n");
		printf("          请重新操作          \n");
		printf("     1.返回       2.退出      \n");
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
		printf("  本ATM机只支持 100 的人民币  \n");
		printf("           请重新操作         \n");
		printf("                              \n");
		printf("     1.返回        2.退出     \n");
		switch(getch())
		{
		case '1': Debit();
		case '2': exit();
		}
	}
	if(z==5000.00||z>5000.00)
	{
		system("cls");
		printf("    每次取款不能超过 5000 元  \n");
		printf("           请重新操作         \n");
		printf("                              \n");
		printf("     1.返回        2.退出     \n");
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
 
//存款函数
void Credit( )
{
	double cun;
	system("cls");
	printf(" 请放入人民币:");
	scanf("%lf",&cun);
	while(cun<0)
	{
		system("cls");
		printf("            非法存款          \n");
		printf("        请重新放入人民币      \n");
		scanf("%lf",&cun);
	}
	(ATM[k].yu_e)+=cun;
	write();
	success();
}
 
//密码修改函数
void miMa()
{
	int mm1,mm2,mm3;
	int temp;
	system("cls");
	printf("旧密码:");
	scanf("%d",&mm1);
	printf("\n");
	if(mm1!=ATM[k].mima)
	{
		system("cls");
		printf("旧密码错误,请重新输入\n");
		delay();
		miMa();
	}
	printf("新密码:");
	scanf("%d",&mm2);
	if(mm2<100000||mm2>999999)
	{
		system("cls");
		printf("        密码必须等于6位数  \n");
		printf("           请重新输入！    \n");
		delay();
		miMa();
	}
	temp=mm2%111111;
	if(temp==0)
	{
		system("cls");
		printf("          密码过于简单       \n");
		printf("           请重新输入！      \n");
		delay( );
		miMa( );
	}
	printf("\n");
	printf("确认新密码:");
	scanf("%d",&mm3);
	if(mm2!=mm3)
	{
		system("cls");
		printf("确认密码不一致,请重新输入\n");
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
 
//延时函数
void delay( )
{
	long int bl1; 
	int bl2;
	for(bl1=600000;bl1>0;bl1--)
	{
		for(bl2=300;bl2>0;bl2--);
	}
}
 
//操作成功函数
void success( )
{
	system("cls");
	printf("           操作已成功         \n");
	printf("                              \n");
	printf("     1.返回        2.退出     \n");
	switch(getch())
	{
	case '1':menu();
		break;
	case '2':exit();
		break;
	}
}
 
//系统退出函数
void exit()
{
	system("cls");
	printf("*        欢迎您的再次使用      *\n");
	printf("*         系统正在退出...      *\n");
	delay();
	enterATM();
}
 
//文件读取函数
void read()
{
	int i;
	FILE *fp;
	fp=fopen("xinxi.txt","r");
	if(fp==NULL)
	{
		printf("打开文件失败\n");
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
 
//文件写入函数
void write()
{
	int i;
	FILE *fp;
	fp=fopen("xinxi.txt","w");
	if(fp==NULL)
	{
		printf("打开文件失败\n");
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
 
//主操作界面函数
void menu( )
{
	system("cls");
	printf("********************************\n");
	printf("*         请选择一下业务       *\n");
	printf("*          1.修改密码          *\n");
	printf("*          2.余额查询          *\n");
	printf("*          3.取款              *\n");
	printf("*          4.存款              *\n");
	printf("*          5.退出              *\n");
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
			printf("\a非法操作\n");
			menu();
		};
	}
}
 
//主函数
int main()
{
	enterATM();
	return 0;	 
}
 
 
 
 
 

