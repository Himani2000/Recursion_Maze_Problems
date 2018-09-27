#include<iostream>
using namespace std;
#define n 4

void Printchess(int chess[n][n]){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<chess[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool IsSafe(int chess[n][n],int row, int col){
    int i,j;
    ///check in the same row
    for (i=0;i<col;i++){
        if (chess[row][i]==1) return false;
    }
    ///checking for diagonal1 (upward)
    for (i=row,j=col;i>=0 && j>=0;i--,j--){
        if (chess[i][j]==1) return false;
    }
    ///checking for diagonal2 (downward)
    for (i=row,j=col;i<n && j>=0;i++,j--){
        if (chess[i][j]==1) return false;
    }
    return true;
}

void NQueens (int chess[n][n],int col, int &cnt){
    if (col>=n){
        cnt++;
        Printchess(chess);
        return;
    }
    for (int i=0;i<n;i++){
        if (IsSafe(chess,i,col)){
            chess[i][col]=1;
            NQueens(chess,col+1,cnt);
            chess[i][col]=0;
        }
    }

}


int main(){
    int chess[n][n]={};

    int cnt=0;
    NQueens(chess,0,cnt);
    cout<<cnt;
}
