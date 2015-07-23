/*************************************************************************
	> File Name: Ticket.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 08:32:55 PM EDT
 ************************************************************************/

#ifndef _TICKET_H
#define _TICKET_H
#define studio_list_t ticket_list_t
#define studio_node_t ticket_node_t
#define p pq;
typedef struct{
                int id;
                int schedule_id;
                int seat_id;
                int price;
                int status;
}ticket_t;

typedef struct ticket_node{
                            ticket_t data;
                            struct ticket_node *next;
                            struct ticket_node *prev;
}ticket_node_t, *ticket_list_t;
void Ticket_Srv_DeleteBatch(int schedule_id);
int Ticket_Srv_AddBatch(void);                                    
void initiate(void);


#endif
