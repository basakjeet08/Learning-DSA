#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void getData(struct Node* );
void showData(struct Node*);
int main(){
    struct Node* head= (struct Node*)malloc(sizeof(struct Node));
    getData(head);
    showData(head);
    return 0 ;
}
void getData(struct Node* ptr){
    char ch;
    int count = 0;
    do{
        printf("Enter the Value of Node : ");
        if(!count){
            scanf("%d",&ptr->data);
            count++;
        }
        else{
            struct Node* new = (struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&new->data);
            ptr->next = new;
            ptr = new;
        }
        printf("Do u wish to Continue(y/n) : ");
        getchar();
        scanf("%c",&ch);
    }while(ch == 'y');
}
void showData(struct Node* ptr){
    printf("The Values of Linked List : \n");
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}