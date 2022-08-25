#include <stdio.h>
void getData(int,int ,int [10][10]);
void findTriplet(int , int , int[10][10]);
void showData(int , int , int[10][10]);
int  main(){
    int row,column;
    int sparce[10][10];
    printf("Enter the Row of the Matrix : ");
    scanf("%d",&row);
    printf("Enter the Column of the Matrix : ");
    scanf("%d",&column);
    getData(row,column,sparce);
    return 0 ;
}
void getData(int row,int column,int sparce[10][10]){
    printf("Enter the Sparce Matirx : \n");
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            scanf("%d",&sparce[i][j]);
    showData(row,column,sparce);
    findTriplet(row,column,sparce);
}
void findTriplet(int row , int column , int sparce[10][10]){
    int count = 0 ;
        for(int i=0;i<row;i++)
            for(int j=0;j<column;j++)
                if(sparce[i][j] != 0)
                    count++;
    int trip[count+1][10];
    int flag = 1;
    trip[0][0] = row;
    trip[0][1] = column;
    trip[0][2] = count;
    
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            if(sparce[i][j] != 0){
                trip[flag][0] = i;
                trip[flag][1] = j;
                trip[flag][2] = sparce[i][j];
                flag++;
            }
    printf("The Triplet Form is : \n");
    showData((count+1),3,trip);
}
void showData(int row,int column , int arr[10][10]){
    for(int i = 0 ;i<row ; i++){
        for(int j = 0 ;j<column;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}