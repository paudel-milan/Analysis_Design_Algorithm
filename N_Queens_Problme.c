#include<stdio.h>
#include<stdbool.h>

#define n 4
int board[n];

void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i]==j){
                printf(" Q ");
            }else{
                printf(" . ");  
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int r, int c){
    for(int i=0;i<r;i++){
        if(board[i]==c || board[i]-i==c-r || board[i]+i==c+r){
            return false;
        }
    }
    return true;
}

void solveNQueens(int r){
    if(r==n){
        print();
        return;
    }
    for(int c=0;c<n;c++){
        if(isSafe(r,c)){
            board[r]=c;
            solveNQueens(r+1);
        }
    }
}

int main() {
    solveNQueens(0);
    return 0;
}
