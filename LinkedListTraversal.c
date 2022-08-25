#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* Next ;
};
int main(){
    struct Node* start = (struct Node*)malloc(sizeof(struct Node));
    int num = 0;
    do{
        printf("Enter the Data : ");
        scanf("%d",&num);
        if(num != 0){
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            start->Next = node;
            node->data = num ; 
            node->Next = NULL;
        }
    }while(num != 0);
    return 0;
}