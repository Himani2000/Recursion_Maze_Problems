#include<iostream>
using namespace std;
#define m 5
#define n 4
void PrintMaze(char maze[m][n]){
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void RatinMaze(char maze[m][n],int r, int c, int &cnt){
    if (r>=m || c>=n) return;
    maze[r][c]='y';
    if (r==m-1 && c==n-1){
        cnt++;
        PrintMaze(maze);
        return;
    }
    ///lets move rat to bottom
    if ((r+1)<m && maze[r+1][c]!='x'){
        RatinMaze (maze,r+1,c,cnt);
    }
    ///lets move rat to right
    if ((c+1)<n && maze[r][c+1]!='x'){
        RatinMaze (maze,r,c+1,cnt);
    }
    maze[r][c]='.';
}


int main(){
    char maze[m][n]={{'.','.','x','.'},
                     {'.','.','.','.'},
                     {'.','x','.','x'},
                     {'.','.','.','.'},
                     {'.','x','x','.'}};

    int cnt=0;
    RatinMaze(maze,0,0,cnt);
    cout<<cnt;
}
