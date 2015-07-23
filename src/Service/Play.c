/*************************************************************************
	> File Name: Play.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Sat 27 Jun 2015 09:24:22 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>
#include"Play.h"
/*
 *已测试
 */
play_list_t p = NULL; //头结点

void initiatef(void)
{        
    p = (play_list_t)malloc(sizeof(play_node_t));    
    p->next = NULL;
    p->prev = NULL;
}

void Play_Srv_Add(void)
{
    char choice;
    int x, y, z, t;
 //   studio_t data0, *data = &data0;
    play_list_t  p1, p2, p3;        
    p1 = (play_list_t)malloc(sizeof(play_node_t));  
    printf("请输入剧目ID、剧目名称、剧目类型、剧目出品地区、剧目等级、时长、开始放映日期(年月日)、结束放映日期（年月日）、票价:");
    scanf("%d%s%d%s%d%d%d%d%d%d%d%d%d", &(p1->data).id, (p1->data).name, &x, (p1->data).area, &y, &(p1->data).duration, &(p1->data).start_date.year, &(p1->data).start_date.month, &(p1->data).start_date.day, &(p1->data).end_date.year, &(p1->data).end_date.month, &(p1->data).end_date.day, &(p1->data).price);
   /* data->id = (p1->data).id, strcpy(data->name, (p1->data).name), data->rowsCount = (p1->data).rowsCount,
    data->colsCount = (p1->data).colsCount;
    Studio_Perst_Insert(data);*/
    (p1->data).type = (play_type_t) x;
    (p1->data).rating = (play_rating_t) y;
 Play_Perst_Insert(p1->data);
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
     p2 = (play_list_t)malloc(sizeof(play_node_t));
    printf("请输入剧目ID、剧目名称、剧目类型、剧目出品地区、剧目等级、时长、开始放映日期(年月日)、结束放映日期（年月日）、票价:");
    scanf("%d%s%d%s%d%d%d%d%d%d%d%d%d", &(p2->data).id, (p2->data).name, &x, (p2->data).area, &y, &(p2->data).duration, &(p2->data).start_date.year, &(p2->data).start_date.month, &(p2->data).start_date.day, &(p2->data).end_date.year, &(p2->data).end_date.month, &(p2->data).end_date.day, &(p2->data).price);
    (p2->data).type = (play_type_t) x;
    (p2->data).rating = (play_rating_t) y;
 Play_Perst_Insert(p2->data);
         p3 = p->next;
         p2->next = p->next; 
         p->next = p2;   
         p2->prev = p;
         p3->prev = p2;
    }   
    printf("添加成功\n");
}


void Play_Srv_DeleteByID(int id)
{
    play_list_t p1, p2, p3, p4 = p;
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
 Play_Perst_Update();
    }

    if(iid == 0)
    {   
        printf("删除失败\n");
    }
}
void interface_Play(play_list_t p1)
{
    int i, y;
    printf("************************************\n");
    printf("*\t1、修改剧目ID              *\n");
    printf("*\t2、修改剧目名称            *\n");
    printf("*\t3、修改剧目类型            *\n");
    printf("*\t4、修改剧目出品地区        *\n");
    printf("*\t5、修改剧目等级            *\n");
    printf("*\t6、修改剧目时长            *\n");
    printf("*\t7、修改剧目开始放映日期    *\n");
    printf("*\t8、修改剧目放映结束日期    *\n");
    printf("*\t9、修改剧目票价            *\n");
    printf("************************************\n");
    printf("请选择1-9：");
    fflush(stdin);
    scanf("%d", &i);
    switch(i){
            case 1:
                    printf("请输入剧目ID（不为0）：");
                    scanf("%d", &(p1->data).id);
                    break;
            case 2:
                    printf("请输入剧目名称:");
                    scanf("%s", (p1->data).name);
                    break;
            case 3:
                    printf("请输入剧目类型：");
                    scanf("%d", &y);
                    (p1->data).type = (play_type_t) y;
                    break;

            case 4:
                    printf("请输入剧目出品地区：");
                    scanf("%s", (p1->data).area);
                    break;

            case 5:
                    printf("请输入剧目等级：");
                    scanf("%d", &y);
           (p1->data).rating = (play_rating_t) y;
                    break;
            case 6:
                    printf("请输入剧目时长：");
                    scanf("%d", &(p1->data).duration);
                    break;
            case 7:
                    printf("请输入剧目开始放映日期（年月日）：");
                    scanf("%d%d%d", &(p1->data).start_date.year, &(p1->data).start_date.month, &(p1->data).start_date.day);
                    break;
            case 8:
                    printf("请输入剧目放映结束日期(年月日)：");
                    scanf("%d%d%d", &(p1->data).start_date.year, &(p1->data).start_date.month, &(p1->data).start_date.day);
                    break;
            case 9:
                    printf("请输入剧目票价：");
                    scanf("%d", &(p1->data).price);
                    break;
    }
}

void Play_Srv_Modify(int id)
{
    play_list_t p1 = p->next;
    int temp = (p->data).id;                                    
    while(1){
        if((p1->data).id == id){
            printf("剧目已存在,请输入剧目信息:\n");
            interface_Play(p1);
            break;
        }

        p1 = p1->next;
        if((p1->data).id == temp){
            printf("剧目不存在\n");
            break;
        }
    }
}


void switchh(int i)
{
    switch(i){
        case 1:
            printf("剧目类型:PLAY_TYPE_FILE \n");
            break;
        case 2:
            printf("剧目类型:PLAY_TYPE_OPEAR \n");
            break;
        case 3:
            printf("剧目类型:PLAY_TYPE_CINCERT \n");
            break;
    }
}


void switchhh(int i)
{
    switch(i){
        case 1:
            printf("剧目等级:PLAY_RATE_CHILD \n");
            break;
        case 2:
            printf("剧目等级:PLAY_RATE_TEENAGE \n");
            break;
        case 3:
            printf("剧目等级:PLAY_RATE_ADULT \n");
            break;
    }
}

void Play_Srv_FetchByID(int id)
{
    int iid = (p->data).id;
     play_list_t p1 = p->next;
     while(1){
            if((p1->data).id == iid)
                break;
            if((p1->data).id == id) {
                printf("剧目ID：%d\n剧目名称:%s\n", (p1->data).id, (p1->data).name);
                switchh((p1->data).type);
                printf("剧目出品地区:%s\n", (p1->data).area);
                switchh((p1->data).rating);
                printf("剧目时长：%d", (p1->data).duration);
                    printf("开始放映日期:%d年%d月%d日\n放映结束日期:%d年%d月%d日\n票价:%d\n", (p1->data).start_date.year, (p1->data).start_date.month, (p1->data).start_date.day, (p1->data).end_date.year, (p1->data).end_date.month, (p1->data).end_date.day, (p1->data).price);
            }
         p1 = p1->next;
            }
}


void Play_Srv_FetchByAll(void)
{
    int iid = (p->data).id;
    printf("*****************************************\n");
     play_list_t p1 = p->next;
     while(1){
                if(iid == (p1->data).id)
                    break;
                printf("剧目ID：%d\n剧目名称:%s\n", (p1->data).id, (p1->data).name);
                switchh((p1->data).type);
                printf("剧目出品地区:%s\n", (p1->data).area);
                switchh((p1->data).rating);
                printf("剧目时长：%d\n", (p1->data).duration);
                printf("开始放映日期:%d年%d月%d日\n放映结束日期:%d年%d月%d日\n票价:%d\n", (p1->data).start_date.year, (p1->data).start_date.month, (p1->data).start_date.day, (p1->data).end_date.year, (p1->data).end_date.month, (p1->data).end_date.day, (p1->data).price);
               p1 = p1->next;
                 printf("****************************************\n");
            }
}


    struct movie{
                int schedule_id;
                int score;
    }movies_score;
/*struct movie  SalesAnalysis_Srv_StaticSale(void)
{
extern ticket_list_t *p    //票||包含头文件
    
    int score = 0;
    movies_score.schedule_id = p->schedule_id;
    ticket_list_t p1 = p;    
    ticket_list_t p1, p2, p3, p4 = p->next;
    int temp = (p1->data).id, iid = 0;
    while(1){
                if((p4->data).status == 1)
                    score += (p4->data).price;
                if((p4->data).id == temp )
                    break;
                p4 = p4->next;            
    }
    movies_score.score = score;
       return movies_score;
}*/

void SalesAnalysis_Srv_SortBySale(void)
{
    

}
