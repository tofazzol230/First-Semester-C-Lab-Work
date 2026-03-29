/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
topic name  : adjacency matrix representation of a graph
*/
#include<stdio.h>
int main() {
int n,m;
printf("Entter number of nodes and edges\n");
scanf("%d%d",&n,&m);
int matrix[100][100]={0};//max nodes 100
printf("Enter nodes and weight for each edges\n");
for(int i=0;i<m;i++){
    int a,b,d;
    printf("Edge %d\n",i+1);
    scanf("%d%d%d",&a,&b,&d);
    printf("Edge from %d to %d with weight %d\n",a,b,d);
    matrix[a][b]=d;
}
//show adjacency matrix
printf("Adjacency Matrix\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d ",matrix[i][j]);
    }
    printf("\n");
}
//find weight of edge
int x,y;
printf("Enter nodes to find weight\n");
scanf("%d%d",&x,&y);
if(matrix[x][y]){
    printf("Weight is %d\n",matrix[x][y]);
}else{
    printf("No edge\n");
}
    return 0;
}