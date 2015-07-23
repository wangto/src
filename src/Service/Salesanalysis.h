/*************************************************************************
	> File Name: Salesanalysis.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Fri 26 Jun 2015 08:51:31 PM EDT
 ************************************************************************/

#ifndef _SALESANALYSIS_H
#define _SALESANALYSIS_H
#define p pr

typedef struct{
                int play_id;
                char name[31];
                char area[9];
                int duration;
                long totaltickets;
                long sales;
                int price;
                user_date_t start_date;
                user_date_t end_date;
}salesanalysis_t;

typedef struct salesanalysis_node{
                                salesanalysis_t data;
                                struct salesanalysis_node *next;
                                struct salesanalysis_node *prev;
}salesanalysis_node_t, *salesanalysis_list_t;




#endif
