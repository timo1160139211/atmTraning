//#if defined(_WIN32) || defined(_WIN64)  //Ϊ��֧��windowsƽ̨�ϵı���
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "mysql/mysql.h"

int i = 1;//ѭ��ȫ�ֱ���

void work();					//ҵ������
void showMenu();				//��ʾ�˵�
void save();					//���
void withdraw();				//ȡ��
void updatePassword();			//��������
void getBalance();				//������
void saveBalance(double d);		//��������
void delay();
void query();

typedef struct Login
{
	char name[24];
	char password[20];
}login;//��½ʱ��֤�õ��û� 

typedef struct record{
	int account; //�˺�
	char password[20]; //����
	char name[24]; //�û���
	double balance; //�˻����
	int status; //״̬
}Account;//���ݿ��ѯ���� 

Account currentUser ={123,"12345","12345",1000.50,123};

//�� 
void save(){
	puts("\n\n---------------���ing--------------\n");
	
	puts("\n\n---------------�뽫��Ʊ����������泮��(50��������)--------------\n");
	
	int saveNum=0;
	scanf("%d",&saveNum);
	
	//�������ݿ� 
	
	//puts("\n\n----����%dԪ�ɹ�����ǰ���Ϊ%.2lfԪ. \n\n\n",saveNum,currentUser.balance);
} 


//����� 
void getBalance(){
	puts("\n\n---------------��ѯ���ing--------------\n");
	printf("����ǰ�����Ϊ%.2lfԪ. \n\n\n",currentUser.balance);
}

//ȡ 
void withdraw(){
	puts("\n\n---------------ȡ��ing--------------\n");
	
	puts("\n\n---------------������ȡ����(50��������)--------------\n");
	
	int withdrawNum=0;
	scanf("%d",&withdrawNum);
	
	//��ѯ���ݿ�
	
	if(currentUser.balance>=withdrawNum){
		//���ݿ���£����³ɹ��� 
		//puts("\n\n----ȡ%dԪ�ɹ�����ǰ���Ϊ%.2lfԪ. \n\n\n",withdrawNum,currentUser.balance);
	}
	else{
		puts("\n\n---------------ȡ��ʧ�ܣ�����--------------\n");
	} 
	
	
} 

//������
void updatePassword(){
	puts("\n\n---------------������ing--------------\n");
	
	puts("\n---------------������������(������20λ)--------------\n");//������������ 
	char newPWD[20];
	scanf("%s",newPWD);
	puts("\n---------------������������(������20λ)--------------\n");//������������ 
	char newPWD2[20];
	scanf("%s",newPWD2);
	
	if(strcmp(newPWD,newPWD2)==0){
		
		//���������롣   update���ݿ� 
		
		
		puts("\n\n---------------������ɹ������μ�������--------------\n"); 
		
	}else{
		puts("\n\n---------------������ʧ�ܣ��������벻һ��--------------\n");
	}
	
	
} 

 
void showMenu(){
	while(i)
	{
		int choice;
		 
		puts("/*-------------------��ѡȡ����------------------*/");
		puts("/*                                            */");
		puts("/*---------------1.��ѯ���--------------*/");
		puts("/*---------------2.���--------------*/");
		puts("/*---------------3.ȡ��--------------*/");
		puts("/*---------------4.������--------------*/");
		puts("/*---------------5.ת��--------------*/");
		puts("/*---------------0.�˳�--------------*/");
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
				
				puts("\n\n\n---------------��ATM��֧�� ת�� --------------*/\n\n");
				break;	
			case 0:
				puts("!!! ��лʹ�� !!! ");//�˳�ϵͳ
				delay();
				i = 0;
				break;
			default :
				puts("!!! ��������ȷѡ�� !!! ");
				while ((getchar()) != '\n');
				getchar();
				break;
		}
	}
}

//��ʱ����
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

//���������ַ���Ϊstr1��str2��
//��str1=str2���򷵻��㣻
//��str1<str2���򷵻ظ�����
//��str1>str2���򷵻�������

//ATM�˺����뺯�� 
int loginATM()
{
	delay();
	system("cls");
	

	printf("*          �������û���         *\n");
	
	login inputUser;
	//int user;
	scanf("%s",inputUser.name);
		printf("        _%s_      \n",inputUser.name);
	if(strcmp(inputUser.name,"")==0)
	{
		printf("*        �˺�Ϊ��       *\n");
	}else if(strlen(inputUser.name)>24){
		printf("*        �˺ų���       *\n");
	} 
	else {	
			//���ݿ��ѯ���������˻����� ��ѯ ,, �˴������������Ϊ 12345 
			//currentUser={123,"12345","12345",1000.50,123};
			
			printf("        _%s_       \n",currentUser.password);
			//���λ����������� 
			printf("*          ����������          *\n");
			for(int lockCount=0;lockCount<3;lockCount++){
				printf("*        ������ %d �λ��� \n",3-lockCount);
				scanf("%s",inputUser.password);
					printf("        _%s_       \n",inputUser.password);
				if(strcmp(inputUser.password,currentUser.password)==0){
					printf("  ������ȷ����½�ɹ� ");
					return 1;
				}
			}
			
			//��½ʧ�ܣ��˺�����    update  user.status = locked 
			return 0;
	}	

}
 


int main(int argc, char const *argv[])
{
	
	printf("*******************************\n");
	printf("*     ��ӭʹ�� ATM ��̨��     *\n");
	printf("*                             *\n");
	printf("*******************************\n");
	delay(); 
	
	if(loginATM()){//�����¼�ɹ� 
		
			system("cls");
			showMenu();	
		
	}
	return 0;
}
