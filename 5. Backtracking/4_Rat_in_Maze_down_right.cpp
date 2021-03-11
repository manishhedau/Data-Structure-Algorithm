#include<iostream>
using namespace std;

int totalPaths = 0;
void ratInMaze(char maze[][10], int visited[][10], int n, int m, int i, int j){
    // base case
    if(i==n-1 && j==m-1){
        visited[i][j] = 1;
        for(int a = 0; a<n; a++){
            for(int b = 0; b<m; b++){
                cout<<visited[a][b]<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
        visited[i][j] = 0;
        totalPaths++;
        return;
    }
    // rat should be inside the grid
    if(i>n || j>m){
        return;
    }

    if(maze[i][j]=='X'){
        return;
    }

    // cout<<"Inside the function "<<endl;
    visited[i][j] = 1;

     // up
    /*
    if(maze[i-1][j]=='0' && (i-1)>=0){
        ratInMaze(maze, visited, n, m, i-1, j);
    }
    // left
    if(maze[i][j-1]=='0' && (j-1)>=0){
        ratInMaze(maze, visited, n, m, i, j-1);
    }
    */

    // down
    if(maze[i+1][j]=='0' && (i+1)<n){
        ratInMaze(maze, visited, n, m, i+1, j);
    }

    // right
    if(maze[i][j+1]=='0' && (j+1)<m){
        ratInMaze(maze, visited, n, m, i, j+1);
    }

    visited[i][j] = 0;
    return;
}
int main(){
    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00"
                        };

    int visited[10][10] = {0};
    ratInMaze(maze, visited, 4, 4, 0, 0);
    cout<<"The total paths are : "<<totalPaths<<endl;
    return 0;
}

/*
output :-
1 0 0 0
1 0 0 0
1 1 1 0
0 0 1 1

1 0 0 0
1 1 0 0
0 1 1 0
0 0 1 1

1 1 0 0
0 1 0 0
0 1 1 0
0 0 1 1

The total paths are : 3
*/
