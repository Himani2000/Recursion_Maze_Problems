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

void MoveQueen(int chess[n][n],int r, int c, int tMoves, int cMove){
    chess[r][c]=cMove;
    if (r==n-1 && c==n-1){
        if (tMoves==cMove){
            Printchess(chess);
        }
        return;
    }

    int i,j;
    ///move right any number of columns but check
    for (i=c+1;i<n;i++){
        MoveQueen(chess,r,i,tMoves,cMove+1);
    }
    ///move bottom any number of rows but check
    for (i=r+1;i<n;i++){
        MoveQueen(chess,i,c,tMoves,cMove+1);
    }
    ///move diagonals any number of steps but check
    for (i=r+1,j=c+1;i<n && j<n;i++,j++){
        MoveQueen(chess,i,j,tMoves,cMove+1);
    }
    chess[r][c]=0;
}


int main(){
    int chess[n][n]={};
    MoveQueen(chess,0,0,3,0);

}
