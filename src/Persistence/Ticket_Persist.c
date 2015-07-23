/*************************************************************************
	> File Name: Ticket_Persist.c
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 12:53:36 AM EDT
 ************************************************************************/

#include<stdio.h>
#include<Ticket.h>
/*
 *待完善
 */
extern Ticket_list_t p;

void Ticket_Perst_Insert(int sum)
{
    FILE *fp;
    int i = 0,id = (p->data).id;
    fp = fopen("Ticket_Data_File", "a");
    Ticket_list_t p1 = p->next;
    while(i < sum){
            fwrite(p1->data, sizeof (ticket_t), 1, fp);
            p1 = p1->next;
    }
        fclose(fp);
}


/**待完善，所有票的集合***/
void Ticket_Perst_Delete(void)
{
    FILE *fp;
    int id = (p->data).id;
    Ticket_list_t p1 = p->next;
    fp = fopen("Ticket_Data_File", "w");
    while(1){
            if((p1->data).id == id)
                break;
            fwrite(p1->data, sizeof (ticket_t), 1, fp);
            p1 = p1->next;
    }
}



void Ticket_Perst_Update(void)
{    
    
    FILE *fp;
    int id = (p->data).id;
    Ticket_list_t p1 = p->next;
    fp = fopen("Ticket_Data_File", "w");
    while(1){
            if((p1->data).id == id)
                break;
            fwrite(p1->data, sizeof (ticket_t), 1, fp);
            p1 = p1->next;
    }
}



void Ticket_Perst_FetchBySchedule(int id)
{
        
    



}

