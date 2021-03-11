#include<iostream>
#include<vector>
using namespace std;

int res = 0;

bool isValid(vector<vector<int>> &grid, vector<vector<int>> &visied, int n, int i, int j){
    return i>=0 && i<n && j>=0 && j<n && grid[i][j]==0 && visied[i][j]==0;
}
void ratInMaze(vector<vector<int>> &grid, vector<vector<int>> &visied, int n, int i, int j){
    // base case
    if(i==n-1 && j==n-1){
        visied[i][j] = 1;
        for(int a = 0; a<n; a++){
            for(int b = 0; b<n; b++){
                cout<<visied[a][b]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        visied[i][j] = 0;
        res++;
        return ;
    }

    if(i>n || j>n) return;

    if(grid[i][j]==1) return;

    visied[i][j] = 1;
    // up
    if(isValid(grid, visied, n, i-1, j)){
        ratInMaze(grid, visied, n, i-1, j);
    }// down
    if(isValid(grid, visied, n, i+1, j)){
        ratInMaze(grid, visied, n, i+1, j);
    }// left
    if(isValid(grid, visied, n, i, j-1)){
        ratInMaze(grid, visied, n, i, j-1);
    }// right
    if(isValid(grid, visied, n, i, j+1)){
        ratInMaze(grid, visied, n, i, j+1);
    }
    visied[i][j] = 0;
    return;
}
int main() {
    int n;
    cin>>n;

    vector<vector<int>> grid(n, vector<int> (n, 0));
    vector<vector<int>> visied(n, vector<int> (n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
        }
    }

    ratInMaze(grid, visied, n, 0, 0);
    cout<<"Total paths : "<<res<<endl;
    return 0;
}

/*
Input :-
7
0 0 1 0 0 1 0
1 0 1 1 0 0 0
0 0 0 0 1 0 1
1 0 1 0 0 0 0 
1 0 1 1 0 1 0
1 0 0 0 0 1 0
1 1 1 1 0 0 0

Output :-
1 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 0 0 1 1 1 
0 1 0 0 1 0 1 
0 1 1 1 1 0 1 
0 0 0 0 0 0 1 

1 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 1 1 1 0 0 
0 0 0 0 1 1 1 

1 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 1 1 0 0 0 
0 0 0 1 1 0 0 
0 0 0 0 1 0 0 
0 0 0 0 1 0 0 
0 0 0 0 1 1 1 

1 1 0 0 0 0 0 
0 1 0 0 0 0 0 
0 1 1 1 0 0 0 
0 0 0 1 1 1 1 
0 0 0 0 0 0 1 
0 0 0 0 0 0 1 
0 0 0 0 0 0 1 

Total paths : 4
*/