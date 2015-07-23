/*
 * account.c
 *
 *  Created on: 2015年6月12日
 *      Author: Administrator
*/
/*#include "Account.h"
#include "../Common/List.
#include "EntityKey.h"h"
#include "../Persistence/Account_Persist.h"*/
#include <string.h>
#include <stdlib.h>

//extern account_t gl_CurUser;
typedef enum {
	USR_ANOMY = 0,
	USR_CLERK =1,
	USR_MANG = 2,
	USR_ADMIN = 9
} account_type_t;

typedef struct {
	int  id;//用户id
	account_type_t type;//用户类型
	char username[30];//用户名
	char password[30];//用户密码
} account_t;

//双向链表
typedef struct account_node {
	account_t data;
	struct account_node *next, *prev;
} account_node_t, *account_list_t;



account_list_t Account_Srv_InitSys(){
	account_list_t p1,p2,head;
	int x;
	p2=head=(account_list_t)malloc(sizeof(account_node_t));
	printf("输入用户id   用户类型  用户名 用户密码（id为0时结束）：\n ");
	p1=(account_list_t)malloc(sizeof(account_node_t));
	scanf("%d%d%s%s",&p1->data.id,&x,p1->data.username,p1->data.password);
	p1->data.type = (account_type_t) x;
	while(p1->data.id!=0)
	{
		p2->next=p1;
		p1->prev=p2;
		p2=p1;
		p1=(account_list_t)malloc(sizeof(account_node_t));
		scanf("%d%d%s%s",&p1->data.id,&x,p1->data.username,p1->data.password);
		p1->data.type = (account_type_t) x;
	}
	free(p1);
	p1=head->next;
	p2->next=p1;
	p1->prev=p2;
	return head;

} 
inline int Account_Srv_Verify(char usrName[], char pwd[]){

	// 请补充完整
       return 1;
}



account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	// 请补充完整
       return NULL;
}


inline int Account_Srv_Add(const account_t *data){
	// 请补充完整
       return 1;
}
inline int Account_Srv_Modify(const account_t *data){
	// 请补充完整
       return 1;
}
inline int Account_Srv_DeleteByID(int usrID,account_list_t head){
	account_list_t p,p1;
	p=p1=head->next;
	if(p->data.id!=usrID)
	{	
		p1=p1->next;
		while(p1!=p)
		{
			if(p1->data.id==usrID)
			{
				p1->prev->next=p1->next;
				p1->next->prev=p1->prev;
				free(p1);
			}
			return 1;
			else return 0;
		}
	}
	else
	{			p1->prev->next=p1->next;
				p1->next->prev=p1->prev;
				free(p1);
				return 1;
	}	
}




inline int Account_Srv_FetchByID(int usrID, account_list_t head){
	int x;
	account_list_t p,p1;
	p=p1=head->next;
	if(p->data.id!=usrID)
	{	
		p1=p1->next;
		while(p1!=p)
		{
			if(p1->data.id==usrID)
			{
				printf("ID:%d\n",p1->data.id);
				printf("用户类型:");
				x=p1->data.type;
				switch(x)
				{
					case 0:printf("匿名\n");break;
					case 1:printf("销售员\n");break;
					case 2:printf("经理\n");break;
					case 9:printf("系统管理员\n");break; 
				}
				printf("用户名:%s\n",p1->data.username);
				printf("用户密码:%s\n",p1->data.password);
			}
			return 1;
			else return 0;
		}
	}
	else
	{		
				printf("ID:%d\n",p1->data.id);
				printf("用户类型:");
				x=p1->data.type;
				switch(x)
				{
					case 0:printf("匿名\n");break;
					case 1:printf("销售员\n");break;
					case 2:printf("经理\n");break;
					case 9:printf("系统管理员\n");break;
				}
				printf("用户名:%s\n",p1->data.username);
				printf("用户密码:%s\n",p1->data.password);
				return 1;
	}	
}

              

}

inline int Account_Srv_FetchByName(char usrName[], account_t *buf){
	// 请补充完整
       return 1;
}

inline int Account_Srv_FetchAll(account_list_t list){
	// 请补充完整
       return 1;
}

main()
{
	void Account_Srv_InitSys();
}

