/*************************************************************************
	> File Name: Sale.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sun 28 Jun 2015 08:49:14 PM EDT
 ************************************************************************/

#ifndef _SALE_H
#define _SALE_H
#define studio_node_t sale_node_t
#define studio_list_t sale_list_t
#define p pt
//#include"../Persistence/Sale_Persist.h"
typedef enum{
    SALE_SELL = 1,
    SALE_RETURN = -1,
}sale_type_t;

typedef struct{
                int year;
                int month;
                int day;
}user_date_t;

typedef struct{
                int hour;
                int minute;
                int second;
}user_time_t;

typedef struct{
                long id;
                int user_id;
                int ticket_id;
                user_date_t date;
                user_time_t time;
                int value;
                sale_type_t type;
}sale_t;

typedef struct sale_node{
                        sale_t data;
                        struct sale_node *next;
                        struct sale_node *prev;
}sale_node_t, *sale_list_t;

void Sale_Srv_Add(void);
void Sale_Srv_DeleteByID(int id);

#endif
