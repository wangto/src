/*
 ============================================================================
 Name        : TTMS.c
 Author      : shu xinfeng
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./Common/Example.h"
//#include "./View/Account_UI.h"


//����ȫ�ֱ��������ڴ洢��½�û���Ϣ
//account_t gl_CurUser={0, USR_ANOMY, "Anonymous",""};

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Welcome to TTMS����\n");
	//����ʾ��
	printf("Press [Enter] key to run example for list\n");
	fflush(stdin);
	getchar();
	Example_List();

	printf("Press [Enter] key to run example for entity key service\n");
	fflush(stdin);
	getchar();
	Example_EntKeySrv();

	//��������ʾ��
	return EXIT_SUCCESS;
}
