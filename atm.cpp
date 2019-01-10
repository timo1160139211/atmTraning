#if defined(_WIN32) || defined(_WIN64)  //为了支持windows平台上的编译
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "mysql/mysql.h"

int pass(); 					//验证密码
void work();					//业务驱动
void showMenu();				//显示菜单
double save(double d);			//存款
double withdraw(double d);		//取款
void updatePassword();			//更改密码
double getBalance();			//获得余额
void saveBalance(double d);		//保存数据
void query();

struct Login
{
	char name[24];
	char password[20];
}login;

typedef struct record{
	int account; //账号
	char password[20]; //密码
	char name[24]; //用户名
	double balance; //账户余额
	int status; //状态
} Account;

void pass()
{
	
}

void showMenu(){

}

int main(int argc, char const *argv[])
{
	
	return 0;
}
