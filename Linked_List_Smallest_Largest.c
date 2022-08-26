#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data ;
    struct Node* next ;
};
void getData(struct Node* );
int giveMinimum(struct Node*);
int giveMaximum(struct Node*);
int main(){
    struct Node* head = (struct Node* )malloc(sizeof(struct Node));
    getData(head);
    int max = giveMaximum(head);
    int min = giveMinimum(head);
    printf("The Maximum Element : %d \n",max);
    printf("The Minimum Element : %d \n",min);
    return 0 ;
}
void getData(struct Node* ptr){
    int count = 0;
    char ch ;
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
            new->next = NULL;
            ptr->next = new;
            ptr = new ;
        }
        printf("Do you wish to Continue (y/n) : ");
        scanf("%c",&ch);
    }while(ch == 'y');
}
int giveMaximum(struct Node* ptr){
    int max = ptr->data;
    while(ptr != NULL){
        if(max < ptr->data)
            max = ptr->data;
        ptr = ptr->next;
    }
    return max;
}
int giveMinimum(struct Node* ptr){
    int min = ptr->data;
    while(ptr != NULL){
        if(min > ptr->data)
            min = ptr->data;
        ptr = ptr->next;
    }
    return min;
}