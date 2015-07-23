#include<stdio.h>
#include"Play_UI.h"
void Play_UI_MgtEntry(void)
{
    int choice;
 initiatef();
    while(1){
    printf("***************************\n");
    printf("*\t1、添加新剧目     *\n");
    printf("*\t2、修改剧目       *\n");
    printf("*\t3、删除剧目       *\n");
    printf("*\t4、查询剧目       *\n");
    printf("*\t5、返回上一级     *\n");
    printf("***************************\n");
    printf("请选择:");
    scanf("%d", &choice);
     switch(choice) {
                      case 1:
                                Play_UI_Add();
                                break;
                      case 2:
                                printf("请输入剧目ID：");
                                scanf("%d", &choice);
                                Play_UI_Modify(choice);
                                break;
                        case 3:
                                printf("请输入剧目ID：");
                                scanf("%d", &choice);
                                Play_UI_Delete(choice);
                                break;
                        case 4:
                                printf("请输入剧目ID:");
                                scanf("%d", &choice);
                                Play_UI_Query(choice);
                                break;
                        case 5:
                                return;
     }

    }
}

void Play_UI_Add(void)
{
    

 Play_Srv_Add();

}

void Play_UI_Modify(int choice)
{
    
    Play_Srv_Modify(choice);

}

void Play_UI_Query(int choice)
{
    

 Play_Srv_FetchByID(choice);
}

void Play_UI_Delete(int choice)
{
    
 Play_Srv_DeleteByID(choice);


}

/*int main()
{
    
 Play_UI_Mgtentry();

}*/
