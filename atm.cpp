#if defined(_WIN32) || defined(_WIN64)  //Ϊ��֧��windowsƽ̨�ϵı���
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "mysql/mysql.h"

int pass(); 					//��֤����
void work();					//ҵ������
void showMenu();				//��ʾ�˵�
double save(double d);			//���
double withdraw(double d);		//ȡ��
void updatePassword();			//��������
double getBalance();			//������
void saveBalance(double d);		//��������
void query();

struct Login
{
	char name[24];
	char password[20];
}login;

typedef struct record{
	int account; //�˺�
	char password[20]; //����
	char name[24]; //�û���
	double balance; //�˻����
	int status; //״̬
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
