#include <iostream>
#include <climits>
using namespace std;
int r,c;
int* fsmax(int a[][1000],int row,int c){
    int fm = INT_MIN, sm = INT_MIN;
    int idx = -1;
    int *b = new int[3];
    for(int i=0;i<c;i++){
        if(a[row][i] > fm){
            sm = fm;
            fm = a[row][i];
            idx = i;
        }
        else if(a[row][i] > sm){
            sm = a[row][i];
        }
    }
    b[0] = fm;
    b[1] = sm;
    b[2] = idx;
    return b;
}
int main() {
    cin >> r >> c;
    int a[1000][1000], dp[1000][1000];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a[i][j];
            if(i==0)
               dp[i][j] = a[i][j];
        }
    }
    for(int i=1;i<r;i++){
        int* y = fsmax(dp,i-1,c);
        for(int j=0;j<c;j++){
            dp[i][j] = a[i][j] + ((j == y[2]) ? y[1] : y[0]);
        }
    }
    cout << fsmax(dp,r-1,c)[0];

    return 0;
}








