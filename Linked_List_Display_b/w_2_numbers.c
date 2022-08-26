#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next ;
};
void getData(struct Node* );
void showData(struct Node*);
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    getData(head);
    showData(head);
    return 0;
}
void getData(struct Node* ptr){
    int count = 0;
    char ch;
    do{
        printf("Enter the Value of Node : ");
        if(!count){
            scanf("%d",&ptr->data);
            getchar();
            count++;
        }
        else{
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&new->data);
            getchar();
            new->next = NULL ;
            ptr->next = new ;
            ptr = new ;
        }
        printf("Do you wish to Continue (y/n) : ");
        scanf("%c",&ch);
    }while(ch == 'y');
}
void showData(struct Node* ptr){
    int start,end;
    int flag = 0;
    printf("Enter the Starting Element : ");
    scanf("%d",&start);
    printf("Enter the Ending Element : ");
    scanf("%d",&end);
    printf("The Elements Are : \n");
    while(ptr != NULL){
        if((ptr->data == start) && (!flag))
            flag = 1;
        else if((ptr->data == end) && (flag)){
            printf("%d\n",ptr->data);
            flag = 0;
            break;
        }
        if(flag)
            printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}