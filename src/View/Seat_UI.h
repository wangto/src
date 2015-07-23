/*************************************************************************
	> File Name: Seat_UI.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Thu 02 Jul 2015 11:49:04 AM EDT
 ************************************************************************/

#ifndef _SEAT_UI_H
#define _SEAT_UI_H
#include"../Persistence/Seat_Persist.h"
#include<stdlib.h>
extern studio_list_t p;


void Seat_UI_MgtEntry(void);
void Seat_UI_Add(void);
void Seat_UI_Modify(int id);
void Seat_UI_Delete(int id);
#endif
