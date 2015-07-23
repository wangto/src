/*************************************************************************
	> File Name: Account.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 08:43:43 PM EDT
 ************************************************************************/

#ifndef _ACCOUNT_H
#define _ACCOUNT_H

typedef enum{
            USR_ANOMY = 0;
            USR_CLERK = 1;
            USR_MANG = 2;
            USR_ADMIN = 9;
}account_type_t;

typedef struct{
                int id;
                account_type_t type;
                char username[30];
                char password[30];
}account_t;

typedef struct account_node{
                            account_t data;
                            struct account_node *prev;
                            struct account_node *next;
}account_node_t, *account_list_t;
void initiate(void);
int Studio_Srv_Add(void);
int Studio_Srv_Modify(int id);
int Studio_Srv_DeleteByID(int id);

#endif
