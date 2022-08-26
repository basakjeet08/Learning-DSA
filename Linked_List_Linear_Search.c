#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data ;
    struct Node* next;
};
void getData(struct Node*);
void searchElement(struct Node*);
int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    getData(head);
    searchElement(head);
    return 0 ;
}
void getData(struct Node* ptr){
    int count = 0;
    char ch ;
    do{
        printf("Enter the value of Node : ");
        if(!count){
            scanf("%d",&ptr->data);
            count++;
        }
        else{
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&new->data);
            ptr->next = new ;
            ptr = new;
        }
        printf("Do you wish to Continue (y/n) : ");
        getchar();
        scanf("%c",&ch);
    }while(ch == 'y');
}
void searchElement(struct Node* ptr){
    int search;
    printf("Enter the Element to be Searched : ");
    scanf("%d",&search);
    while(ptr != NULL){
        if(search == ptr->data){
            printf("Element Found !!\n");
            break;
        }
        ptr = ptr->next;
    }
    if(ptr == NULL)
        printf("No Element Found !!\n");
}