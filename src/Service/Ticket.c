/*************************************************************************
	> File Name: Ticket.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sun 28 Jun 2015 10:44:50 AM EDT
 ************************************************************************/
/*
 *
 *待修改,函数完毕
 *已测试，小bug
 */
#include<stdio.h>
#include<malloc.h>
#include"Ticket.h"

studio_list_t p = NULL; //头结点

void initiate(void)
{        
    p = (studio_list_t)malloc(sizeof(studio_node_t));    
    p->next = NULL;
    p->prev = NULL;
}

int Ticket_Srv_AddBatch(void)                                                                   //待完善,根据演出计划*
{
    int i = 1, x, y;
    studio_list_t  p1, p2, p3;        
    p1 = (studio_list_t)malloc(sizeof(studio_node_t));  
    printf("请输入票的起始ID，票对应的演出计划ID，票价,以及票的个数:");
    scanf("%d%d%d%d", &(p1->data).id, &(p1->data).schedule_id, &(p1->data).price, &x);
    (p1->data).seat_id = i, (p1->data).status = 0;
    y = (p1->data).id;
    p->next = p1;
    p->prev = p1;
    p1->next = p;
    p1->prev = p;
    while(i < x){
         p3 = p->next;
         p2 = (studio_list_t)malloc(sizeof(studio_node_t));
         i++;
        (p2->data).id = y++, (p2->data).schedule_id = (p1->data).schedule_id, (p2->data).seat_id = i, (p2->data).price = (p1->data).price, (p2->data).status = 0;
         p2->next = p->next; 
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
    }   
    printf("批量生成成功\n");
}


void Ticket_Srv_DeleteBatch(int schedule_id)
{
    studio_list_t p1, p2, p3, p4 = p;
    p3 = p4;
    /*int temp = (p4->data).id, iid = 0;
    while(1){
            p3 = p4->next;
            p1 = p4->next->next;
            p2 = p4;
        if((p4->next->data).id == id ){
                p4->next = p1;
                 p1->prev = p2;
                iid = 1;
                break;
            }
            else if(temp == (p4->next->data).id)
                break;
    p4 = p4->next;
    }
    if(iid == 1){
    free(p3);*/
    int i = 0, x;
    printf("请输入要删除的票数:");
    scanf("%d", &x);
    p4 = p4->next;
    while(i < x){
        p3 = p3->next;
        p4 = p4->next;
        free(p3);
        i++;
    }
    p->next = p4;
    p4->prev = p;
    printf("删除成功\n");
}


