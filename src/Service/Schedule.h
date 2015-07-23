/*************************************************************************
	> File Name: Schedule.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 08:26:47 PM EDT
 ************************************************************************/

#ifndef _SCHEDULE_H
#define _SCHEDULE_H
#define studio_list_t schedule_list_t
#define studio_node_t schedule_node_t
#define p pe
typedef struct{
                int year;
                int month;
                int day;
             }user_date_t;

typedef struct{
                int hour;
                int minute;
                int second;
}user_mytime_t;


typedef struct{
                int id;
                int play_id;
                int studio_id;
                user_date_t date;
                user_mytime_t time;
                int seat_count;
}schedule_t;

typedef struct Schedule_node{
                            schedule_t data;
                            struct Schedule_node *next;
                            struct Schedule_node *prev;
}schedule_node_t, *schedule_list_t;

void Schedule_Srv_Add(void);
void Schedule_Srv_FetchAll(void);
void Schedule_Srv_FetchByID(int id);
int Schedule_Srv_DeleteByID(int id);
void Schedule_Srv_Modify(int id);
void initiate(void);






#endif
