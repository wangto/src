/*************************************************************************
	> File Name: Studio.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 05:34:49 PM EDT
 ************************************************************************/

#ifndef _STUDIO_H
#define _STUDIO_H
#define p pw

typedef struct{
                int id;
                char name[30];
                int rowsCount;
                int colsCount;
}studio_t;

typedef struct studio_node{
                            studio_t data;
                            struct studio_node *next;
                            struct studio_node *prev;
}studio_node_t, *studio_list_t;



int Studio_Srv_Add(void);
void initiate(void);
int Studio_Srv_DeleteByID(int id);
int Studio_Srv_Modify(int id);

#endif
