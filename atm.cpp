//#if defined(_WIN32) || defined(_WIN64)  //为了支持windows平台上的编译
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "mysql/mysql.h"

int i = 1;//循环全局变量

void work();					//业务驱动
void showMenu();				//显示菜单
void save();					//存款
void withdraw();				//取款
void updatePassword();			//更改密码
void getBalance();				//获得余额
void saveBalance(double d);		//保存数据
void delay();
void query();

typedef struct Login
{
	char name[24];
	char password[20];
}login;//登陆时验证用的用户 

typedef struct record{
	int account; //账号
	char password[20]; //密码
	char name[24]; //用户名
	double balance; //账户余额
	int status; //状态
}Account;//数据库查询出的 

Account currentUser ={123,"12345","12345",1000.50,123};

//存 
void save(){
	puts("\n\n---------------存款ing--------------\n");
	
	puts("\n\n---------------请将钞票叠整齐后放入存钞口(50的整数倍)--------------\n");
	
	int saveNum=0;
	scanf("%d",&saveNum);
	
	//更新数据库 
	
	//puts("\n\n----存入%d元成功，当前余额为%.2lf元. \n\n\n",saveNum,currentUser.balance);
} 


//查余额 
void getBalance(){
	puts("\n\n---------------查询余额ing--------------\n");
	printf("您当前的余额为%.2lf元. \n\n\n",currentUser.balance);
}

//取 
void withdraw(){
	puts("\n\n---------------取款ing--------------\n");
	
	puts("\n\n---------------请输入取款金额(50的整数倍)--------------\n");
	
	int withdrawNum=0;
	scanf("%d",&withdrawNum);
	
	//查询数据库
	
	if(currentUser.balance>=withdrawNum){
		//数据库更新，更新成功后： 
		//puts("\n\n----取%d元成功，当前余额为%.2lf元. \n\n\n",withdrawNum,currentUser.balance);
	}
	else{
		puts("\n\n---------------取款失败，余额不足--------------\n");
	} 
	
	
} 

//改密码
void updatePassword(){
	puts("\n\n---------------改密码ing--------------\n");
	
	puts("\n---------------请输入新密码(不超过20位)--------------\n");//请输入新密码 
	char newPWD[20];
	scanf("%s",newPWD);
	puts("\n---------------请输入新密码(不超过20位)--------------\n");//请输入新密码 
	char newPWD2[20];
	scanf("%s",newPWD2);
	
	if(strcmp(newPWD,newPWD2)==0){
		
		//更新新密码。   update数据库 
		
		
		puts("\n\n---------------改密码成功，请牢记新密码--------------\n"); 
		
	}else{
		puts("\n\n---------------改密码失败，两次输入不一致--------------\n");
	}
	
	
} 

 
void showMenu(){
	while(i)
	{
		int choice;
		 
		puts("/*-------------------请选取服务------------------*/");
		puts("/*                                            */");
		puts("/*---------------1.查询余额--------------*/");
		puts("/*---------------2.存款--------------*/");
		puts("/*---------------3.取款--------------*/");
		puts("/*---------------4.改密码--------------*/");
		puts("/*---------------5.转账--------------*/");
		puts("/*---------------0.退出--------------*/");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				getBalance();
				delay();
				break;
			case 2:
				save();delay();
				break;
			case 3:
				withdraw();delay();
				break;
			case 4:
				updatePassword();delay();
				break;
			case 5:
				
				puts("\n\n\n---------------本ATM不支持 转账 --------------*/\n\n");
				break;	
			case 0:
				puts("!!! 感谢使用 !!! ");//退出系统
				delay();
				i = 0;
				break;
			default :
				puts("!!! 请输入正确选项 !!! ");
				while ((getchar()) != '\n');
				getchar();
				break;
		}
	}
}

//延时函数
void delay()
{
	long int bl1; 
	int bl2;
	for(bl1=600000;bl1>0;bl1--)
	{
		for(bl2=300;bl2>0;bl2--);
	}
}

//     strcmp

//设这两个字符串为str1，str2，
//若str1=str2，则返回零；
//若str1<str2，则返回负数；
//若str1>str2，则返回正数。

//ATM账号输入函数 
int loginATM()
{
	delay();
	system("cls");
	

	printf("*          请输入用户名         *\n");
	
	login inputUser;
	//int user;
	scanf("%s",inputUser.name);
		printf("        _%s_      \n",inputUser.name);
	if(strcmp(inputUser.name,"")==0)
	{
		printf("*        账号为空       *\n");
	}else if(strlen(inputUser.name)>24){
		printf("*        账号超长       *\n");
	} 
	else {	
			//数据库查询，依靠“账户名” 查询 ,, 此处构造测试数据为 12345 
			//currentUser={123,"12345","12345",1000.50,123};
			
			printf("        _%s_       \n",currentUser.password);
			//三次机会输入密码 
			printf("*          请输入密码          *\n");
			for(int lockCount=0;lockCount<3;lockCount++){
				printf("*        您还有 %d 次机会 \n",3-lockCount);
				scanf("%s",inputUser.password);
					printf("        _%s_       \n",inputUser.password);
				if(strcmp(inputUser.password,currentUser.password)==0){
					printf("  密码正确，登陆成功 ");
					return 1;
				}
			}
			
			//登陆失败，账号锁定    update  user.status = locked 
			return 0;
	}	

}
 


int main(int argc, char const *argv[])
{
	
	printf("*******************************\n");
	printf("*     欢迎使用 ATM 柜台机     *\n");
	printf("*                             *\n");
	printf("*******************************\n");
	delay(); 
	
	if(loginATM()){//如果登录成功 
		
			system("cls");
			showMenu();	
		
	}
	return 0;
}
