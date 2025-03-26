#include<stdio.h>
#include<string.h>

#define MAX_MEMBERS 50

struct member{
    char name[10];
    char phone_number[20];
};

void chakan(struct member members[],int mem_num){
    int i;
    for(i=1;i<=mem_num;i++)printf("%d.name:%s,number:%s\n",i,members[i-1].name,members[i-1].phone_number);
}

void chazhao(struct member members[],int mem_num,char name[]){
    int i,flag=0;
    for(i=0;i<mem_num;i++){
        if(strcmp(members[i].name,name)==0){
            printf("%d.name:%s,number:%s\n",i+1,members[i].name,members[i].phone_number);
            flag=1;
        }
    }
    if(!flag)printf("Not found\n");
}

int main(){
    struct member members[MAX_MEMBERS];
    struct member temp;
    int stop_flag=1;
    int key,bianhao;
    int i,j;
    int mem_num=0;
    char name[10];

    while(stop_flag){
        printf("\n******请输入一个数字******\n");
        printf("1.查看联系人\n");
        printf("2.添加联系人\n");
        printf("3.查找联系人\n");
        printf("4.删除联系人\n");
        printf("5.退出\n");
        scanf("%d",&key);
        printf("\n");
        if(key == 1){
            chakan(members,mem_num);
        }
        else if(key == 2){
            if(mem_num==50)printf("联系人数量达到上限\n");
            else{
                printf("请输入名字\n");
                scanf("%s",members[mem_num].name);
                printf("请输入手机号\n");
                scanf("%s",members[mem_num].phone_number);
                mem_num++;
                for(i=0;i<mem_num;i++){
                    for(j=0;j<mem_num-1;j++){
                        if(strcmp(members[j].name,members[j+1].name)>=0){
                            temp=members[j];
                            members[j]=members[j+1];
                            members[j+1]=temp;
                        }
                    }
                }
            }
        }
        else if(key == 3){
            printf("输入要查找的人名\n");
            scanf("%s",name);
            chazhao(members,mem_num,name);
        }
        else if(key == 4){
            chakan(members,mem_num);
            printf("输入要删除对象的编号\n");
            scanf("%d",&bianhao);
            while(bianhao>mem_num){
                printf("重新输入要删除对象的编号\n");
                scanf("%d",&bianhao);
            }
            for(i=bianhao-1;i<mem_num-1;i++){
                members[i]=members[i+1];
            }
            mem_num-=1;
            printf("删除成功\n");
        }
        else{
            if(key == 5){
                stop_flag=0;
                printf("退出成功\n");
            }
            else printf("请重新输入\n");
        }
    }

    return 0;
}