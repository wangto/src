/*************************************************************************
	> File Name: Schedule.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sun 28 Jun 2015 06:02:51 PM EDT
 ************************************************************************/
/*
 *已测试
 */
#include<stdio.h>
#include"Schedule.h"
#include<malloc.h>

studio_list_t p = NULL; //头结点

void initiateq(void)
{        
    p = (studio_list_t)malloc(sizeof(studio_node_t));    
    p->next = NULL;
    p->prev = NULL;
}

void Schedule_Srv_Add(void)
{
    char choice;
    int x, y;
    studio_list_t  p1, p2, p3;        
    p1 = (studio_list_t)malloc(sizeof(studio_node_t));  
    printf("请输入演出计划ID，上演剧目ID，演出厅ID，放映日期(年、月、日)，放映时间（时、分、秒），座位数：");
    scanf("%d%d%d%d%d%d%d%d%d%d", &(p1->data).id, &(p1->data).play_id, &(p1->data).studio_id, &(p1->data).date.year, &(p1->data).date.month, &(p1->data).date.day, &(p1->data).time.hour, &(p1->data).time.minute, &(p1->data).time.second, &(p1->data).seat_count);
    Schedule_Perst_Insert(p1->data);
    p->next = p1;
    p->prev = p1;
    p1->next = p;
    p1->prev = p;
    while(1){
            getchar();
            printf("是否继续添加：（y/n?）");
            choice = getchar();
            if(choice == 'n')
                break;
         p3 = p->next;
         p2 = (studio_list_t)malloc(sizeof(studio_node_t));
         p2->next = p->next; 
    printf("请输入演出计划ID，上演剧目ID，演出厅ID，放映日期(年、月、日)，放映时间（时、分、秒），座位数：");
    scanf("%d%d%d%d%d%d%d%d%d%d", &(p2->data).id, &(p2->data).play_id, &(p2->data).studio_id, &(p2->data).date.year, &(p2->data).date.month, &(p2->data).date.day, &(p2->data).time.hour, &(p2->data).time.minute, &(p2->data).time.second, &(p2->data).seat_count);    
        Schedule_Perst_Insert(p2->data);
        p3 = p->next;
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
    }   
    printf("添加成功\n");
}

void Schedule_Srv_Modify(int id)
{
    studio_list_t p1 = p->next;
    int temp = (p->data).id;                                    //座位
    while(1){
        if((p1->data).id == id){
         printf("演出服务存在，请修改演出服务:\n");
         printf("请输入演出计划ID，上演剧目ID，演出厅ID，放映日期(年、月、日)，放映时间（时、分、秒)，座位数：");
         scanf("%d%d%d%d%d%d%d%d%d%d", &(p1->data).id, &(p1->data).play_id, &(p1->data).studio_id, &(p1->data).date.year, &(p1->data).date.month, &(p1->data).date.day, &(p1->data).time.hour, &(p1->data).time.minute, &(p1->data).time.second, &(p1->data).seat_count);
           Schedule_Perst_Update();
            printf("修改成功\n");
            break;
        }
        p1 = p1->next;
        if((p1->data).id == temp){
            printf("该演出计划不存在\n");
            break;
        }
    }
}


int Schedule_Srv_DeleteByID(int id)
{
    studio_list_t p1, p2, p3, p4 = p;
    int temp = (p4->data).id, iid = 0;
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
         free(p3);
    printf("删除成功\n");
    Schedule_Perst_Update();
    }

    if(iid == 0)
    {
        printf("删除失败，此演出计划不存在\n");
    }
}


void Schedule_Srv_FetchByID(int id)
{
    schedule_list_t p1 = p->next; 
    int temp = (p->data).id;
    while(1){
        if((p1->data).id == id){
            printf("演出计划ID：%d\n上映剧目ID：%d\n演出厅ID:%d\n放映日期(年、月、日)：%d %d %d\n放映时间(时、分、秒)：%d %d %d\n座位数:%d\n",(p1->data).id, (p1->data).play_id, (p1->data).studio_id, (p1->data).date.year, (p1->data).date.month, (p1->data).date.day, (p1->data).time.hour, (p1->data).time.minute, (p1->data).time.second, (p1->data).seat_count);
            break;
        }
        if((p1->data).id == temp){
            break;
        }
        p1 = p1->next;
    }
}


void Schedule_Srv_FetchAll(void)
{
    schedule_list_t p1 = p->next; 
    int temp = (p->data).id;
    while(1){
        if((p1->data).id == temp){
            break;
        }
            printf("演出计划ID：%d\n上映剧目ID：%d\n演出厅ID:%d\n放映日期(年、月、日)：%d %d %d\n放映时间(时、分、秒)：%d %d %d\n座位数:%d\n",(p1->data).id, (p1->data).play_id, (p1->data).studio_id, (p1->data).date.year, (p1->data).date.month, (p1->data).date.day, (p1->data).time.hour, (p1->data).time.minute, (p1->data).time.second, (p1->data).seat_count);
        p1 = p1->next;
    }
}

