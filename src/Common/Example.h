/*
 * Example.h
 *
 *  Created on: 2015��6��25��
 *      Author: edu
 */

#ifndef SRC_COMMON_EXAMPLE_H_
#define SRC_COMMON_EXAMPLE_H_
#include "list.h"


typedef struct{
	int ID;
	char name[20];
	int score;
}student_t;

typedef struct student_node{
	student_t data;
	struct student_node *prev;
	struct student_node *next;
}student_node_t, *student_list_t;

//����ʹ��ʾ��
void Example_List(void);


//��������ʾ��
void Example_EntKeySrv(void);


#endif /* SRC_COMMON_EXAMPLE_H_ */
