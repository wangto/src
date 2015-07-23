/*
 * Example.c
 *
 *  Created on: 2015��6��25��
 *      Author: edu
 */
#include "Example.h"
#include "../Service/EntityKey.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�����ҳ���
static void Example_List_PgShow(student_list_t list, int listSize) {
	int pageSize, i;
	Pagination_t paging;
	student_node_t *p;
	char choice;

	printf("Input page size:");
	scanf("%d", &pageSize);

	paging.pageSize = pageSize;

	paging.totalRecords = listSize;
	Paging_Locate_FirstPage(list, paging);

	do {
		printf("============= Student List =================\n");
		printf("%5s%20s%8s\n", "ID", "Name", "Score");
		printf("--------------------------------------------\n");
		for (i = 0, p = (student_node_t *) (paging.curPos);
				p != list && i < paging.pageSize; i++) {
			printf("%5d%20s%8d\n", p->data.ID, p->data.name, p->data.score);
			p=p->next;
		}
		printf("--Total Records:%2d --------- Page %2d/%2d --\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
		printf("[P]revPage | [N]extPage | [R]eturn\n");
		printf("============================================\n");
		printf("Your Choice:");
		fflush(stdin);
		scanf("%c", &choice);

		switch (choice) {
		case 'p':
		case 'P':
			if (1 < Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(list, paging, -1, student_node_t);
			}
			break;
		case 'n':
		case 'N':
			if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
				Paging_Locate_OffsetPage(list, paging, 1, student_node_t);
			}
			break;
		}
	} while (choice != 'r' && choice != 'R');

}

static void Example_List_Show(student_list_t list) {

	student_node_t *p;
	printf("============= Student List =================\n");
	printf("%5s%20s%8s\n", "ID", "Name", "Score");
	printf("--------------------------------------------\n");
	List_ForEach(list, p)
	{
		printf("%5d%20s%8d\n", p->data.ID, p->data.name, p->data.score);
	}
	printf("============================================\n");

}

//����ʹ��ʾ��
void Example_List() {
	student_list_t list;   //����ͷָ�����
	student_node_t *p, *pNew;
	int i;

//��ʼ������
	List_Init(list, student_node_t);

//ͷ�巨����10���ڵ�
	for (i = 0; i < 10; i++) {
		p = (student_node_t *) malloc(sizeof(student_node_t));
		p->data.ID = i;
		p->data.score = i * 10;
		sprintf(p->data.name, "%s%d", "Student-", i);
		List_AddHead(list, p);
	}

	//����ͨģʽ�������
	Example_List_Show(list);


	if(List_IsEmpty(list))
		printf("List is empty!\n");
	else
		printf("List is not empty!\n");

	pNew = (student_node_t *) malloc(sizeof(student_node_t));
	pNew->data.ID = 100;
	pNew->data.score = 1000;
	sprintf(pNew->data.name, "%s%d", "Student-", 1000);

	//InsertBefore
	List_InsertBefore(list->next, pNew);

	//����ͨģʽ�������
	Example_List_Show(list);


	//ɾ���ڵ�pNew
	List_DelNode(pNew);
	//����ͨģʽ�������
	Example_List_Show(list);

	//InsertAfter
	List_InsertAfter(list->next, pNew);
	//����ͨģʽ�������
	Example_List_Show(list);
	//�ͷŽڵ�pNew
	List_FreeNode(pNew);

//�����������
	List_Free(list, student_node_t);

//��β�巨����10���ڵ�
	for (i = 0; i < 10; i++) {
		p = (student_node_t *) malloc(sizeof(student_node_t));
		p->data.ID = i;
		p->data.score = i * 10;
		sprintf(p->data.name, "%s%d", "Student-", i);
		List_AddTail(list, p);
	}

//�Է�ҳ��ʽ�������
	Example_List_PgShow(list, 10);

//��������
	List_Destroy(list, student_node_t);

}

//��������ʾ��
void Example_EntKeySrv() {

	long key;
	int count;

	//��ȡ����
	key=EntKey_Srv_CompNewKey("student");

	//�������
	printf("Entity Key:%ld\n", key);

	//������ȡ����
	printf("Input key count:");
	scanf("%d", &count);
	key=EntKey_Srv_CompNewKeys("student", count);

	//�������
	printf("Start Entity Key:%ld\n", key);

	//�ٴλ�ȡ������
	key=EntKey_Srv_CompNewKey("student");
	//�������
	printf("Entity Key:%ld\n", key);

}

