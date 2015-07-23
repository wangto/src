/*************************************************************************
	> File Name: Seat.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 08:59:46 PM EDT
 ************************************************************************/

#ifndef _SEAT_H
#define _SEAT_H
#define p pi
#define studio_list_t seat_list_t
#define studio_node_t seat_node_t
typedef enum{
            SEAT_NONE = 0,
            SEAT_GOOD = 1,
            SEAT_BROKEN = 9
}seat_status_t;


typedef struct {
                int id;
                int roomID;
                int row;
                int column;
                seat_status_t status;
}seat_t;

typedef struct seat_node{
                        seat_t data;
                        struct seat_node *next;
                        struct seat_node *prev;
}seat_node_t, *seat_list_t;

/*typedef struct seat{
                    struct seat *prev;
                    struct seat *next;
                    seat_list_t seat;
}seat_seat_t，*seat_s_t;*/

void Seat_Srv_AddBatch(void);
int Seat_Srv_Modify(int id);
void Modify(studio_list_t p1);
void Seat_Srv_DeleteByID(int id);
void Seat_Srv_Add(void);


#endif

