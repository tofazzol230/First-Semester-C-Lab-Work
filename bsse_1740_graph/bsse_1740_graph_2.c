/*
Name        : Md.Tofazzol Alam Rahat
Roll        : BSSE-1740
Section     : B
Course      : Structured Programming Lab
Topic name  : adjacency list representation of a graph
*/
#include<stdio.h>
int main() {
int n,m;
printf("Entter number of nodes and edges\n");
scanf("%d%d",&n,&m);

int to[100][100],weight[100][100],count[100]={0};//max nodes 100
printf("Enter nodes and weight for each edges\n");
for(int i=0;i<m;i++){
    int a,b,d;
    printf("Edge %d\n",i+1);
    scanf("%d%d%d",&a,&b,&d);
    to[a][count[a]++]=b;
    weight[a][b]=d;
}
//show adjacency list
printf("Adjacency List\n");
for(int i=0;i<n;i++){
    printf("Node %d:",i);
    for(int j=0;j<count[i];j++){
        printf(" %d(weight %d)",to[i][j],weight[i][to[i][j]]);
    }
    printf("\n");
}
//find weight of edge
int x,y;
printf("Enter nodes to check connection\n");
scanf("%d%d",&x,&y);
int found=0,i=0;
while(i<count[x]){
    if(to[x][i]==y){
        printf("Weight is %d\n",weight[x][y]);
        found=1;
        break;
    }
    i++;
}

if(!found){
    printf("No edge\n");
}
    return 0;
}