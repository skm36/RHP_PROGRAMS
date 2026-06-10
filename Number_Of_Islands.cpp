#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    const int diff[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    void dfs(vector<vector<char>>& grid,int r,int c,int row,int col){
        grid[row][col]='0';
        for(int i=0;i<4;i++){
            int ar=row+diff[i][0],ac=col+diff[i][1];
            if(ar>=0 && ac>=0 && ar<r && ac<c && grid[ar][ac]=='1'){
                dfs(grid,r,c,ar,ac);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size(),c=grid[0].size();
        int islands=0;
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(grid[row][col]=='1'){
                    islands++;
                    dfs(grid,r,c,row,col);
                }
            }
        }
        return islands;
    }
};
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<char>> grid(r,vector<char>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    Solution obj;
    cout<<obj.numIslands(grid);
    return 0;
}
