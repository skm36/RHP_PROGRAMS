#include <iostream>
using namespace std;
int r,c;
int* fsmax(int a[][1000],int c,int r){
    int fm=0,sm=0;
    int *b = new int[2];
    for(int i=0;i<r;i++){
        if(a[i][c]>fm){
                sm = fm;
                fm  = a[i][c];
            }else if(a[i][c]>sm)
            sm=a[i][c];
    }
    b[0]=fm;
    b[1]=sm;
    return b;
}
int main() {
    cin>>r>>c;
    int a[r][c],dp[1000][1000];
    int fm=0,sm=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            if(j==0)
            dp[i][j]=a[i][j];
        }
    }
    for(int i=1;i<c;i++){
        int* y = fsmax(dp,i-1,r);
        for(int j=0;j<r;j++){
           dp[j][i] = a[j][i] +((dp[j][i-1] ==y[0])?y[1]:y[0]);
        }
    }
    cout<<fsmax(dp,c-1,r)[0];

    return 0;
}
