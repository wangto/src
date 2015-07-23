/*************************************************************************
	> File Name: Play.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sun 28 Jun 2015 10:27:45 AM EDT
 ************************************************************************/

#ifndef _PLAY_H
#define _PLAY_H
#define p py
typedef enum{
            PLAY_TYPE_FILE = 1,
            PLAY_TYPE_OPEAR = 2,
            PLAY_TYPE_CINCERT = 3,
}play_type_t;

typedef enum{
            PLAY_RATE_CHILD = 1,
            PLAY_RATE_TEENAGE = 2,
            PLAY_RATE_ADULT = 3,
}play_rating_t;

typedef struct{
                int year;
                int month;
                int day;
}user_date_t;

typedef struct{
                int id;
                char name[31];
                play_type_t type;
                char area[9];
                play_rating_t rating;
                int duration;
                user_date_t start_date;
                user_date_t end_date;
                int price;
}play_t;

typedef struct play_node{
                        play_t data;
                        struct play_node *next;
                        struct play_node *prev;
}play_node_t, *play_list_t;


void initiatef(void);
void Play_Srv_Add(void);
void Play_Srv_DeleteByID(int id);
void interface_Play(play_list_t p1);
void Play_Srv_Modify(int id);
#endif
