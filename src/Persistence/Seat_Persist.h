/*************************************************************************
	> File Name: Seat_Persist.h
	> Author: WT
	> Mail: wangtong19951128@qq.com 
	> Created Time: Wed 01 Jul 2015 02:39:54 AM EDT
 ************************************************************************/

#ifndef _SEAT_PERSIST_H
#define _SEAT_PERSIST_H
#include"../Service/Seat.h"
//#define p pw

void Seat_Perst_Insert(seat_t data);
void Seat_Perst_InsertBatch(void);
void Seat_Perst_Update(void);
void Seat_Perst_DeleteAllByRoomID(int id);
void Seat_Perst_DeleteByID(void);
void Seat_Perst_SelectByRoomID(int id);
void Seat_Perst_SelectByID(int id);
void Seat_Perst_SelectAll(void);

#endif
