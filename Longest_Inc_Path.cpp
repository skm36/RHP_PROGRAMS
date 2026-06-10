#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;  

class Solution {
public:
    const int diff[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
    int dfs (vector<vector<int>>& matrix, vector<vector<int>>& dp, int r, int c, int row, int col){
        if(dp[row][col]!=0){
            return dp[row][col];
        } //Base condition or Gauge or Exit Condition

        int maxadj=0;
        for(int i=0;i<4;i++){
            int ar=row+diff[i][0],ac=col+diff[i][1];
            if(ar>=0 && ac>=0 && ar<r && ac<c && matrix[ar][ac]>matrix[row][col]){
                maxadj=max(maxadj,dfs(matrix,dp,r,c,ar,ac));
            }
        }
        dp[row][col]=1+maxadj;
        return 1+maxadj;

}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        int maxseq=1;
        for(int row=0;row<r;row++){
            for(int col=0;col<c;col++){
                if(dp[row][col]==0){
                    maxseq=max(maxseq,dfs(matrix,dp,r,c,row,col));
                }
            }
        }
        return maxseq;
    }
};
