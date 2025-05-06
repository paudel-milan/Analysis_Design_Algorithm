#include<stdio.h>

int find(int v, int parent[10]){
    while(parent[v]!=v){
        v=parent[v];
    }
    return v;
}

void union1(int i,int j,int parent[10]){
    if(i<j){
        parent[j]=i;
    }else{
        parent[i]=j;
    }
}

void krushkal(int n,int a[10][10]){
    int count,k,sum,min,t[10][10],parent[10],u,v,i,j;
    count=0;
    k=0;
    sum=0;

    for (i = 0; i < n; i++) {
        parent[i] = i;
    }

    while(count!=n-1){
        min=9999;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][j]<min && a[i][j]!=0){
                    min=a[i][j];
                    u=i;
                    v=j;
                }
            }
        }

        i=find(u,parent);
        j=find(v,parent);
        if(i!=j){
            union1(i,j,parent);
            t[k][0]=u;
            t[k][1]=v;
            k++;count++;
            sum=sum+a[u][v];
        }

        a[u][v]=a[v][u]=9999;
    }

    if(count==n-1){
        printf("Minimum Spanning Tree is:\n");
        for(i=0;i<n-1;i++){
            printf("%d %d\n",t[i][0],t[i][1]);
        }
        printf("Min Spanning Tree Cost is %d\n",sum);
    }
    else{
        printf("No Minimum Spanning Tree exists\n");
    }
}

int main(){
    int n,i,j,a[10][10];
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    krushkal(n,a);
    return 0;
}
