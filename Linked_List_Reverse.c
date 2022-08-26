#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data ;
    struct Node* next ;
};
void getData(struct Node* );
struct Node* reverseList(struct Node*);
void showData(struct Node* );
int main(){
    struct Node* head = (struct Node* )malloc(sizeof(struct Node));
    getData(head);
    head = reverseList(head);
    showData(head);
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
            new->next = NULL ;
            ptr->next = new ;
            ptr = new ;
        }
        printf("Do you wish to Continue (y/n) : ");
        scanf("%c",&ch);
    }while(ch == 'y');
}
struct Node* reverseList(struct Node* ptr){
    struct Node* prev = NULL;
    while(ptr->next != NULL){
        struct Node* temp = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = temp;
    }
    ptr->next = prev;
    return ptr;
}
void showData(struct Node* ptr){
    printf("The Elements in Reversed Order : \n");
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}