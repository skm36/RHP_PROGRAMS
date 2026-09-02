#include<iostream>
#include<vector>
using namespace std;
int find(vector<int> &ldr,int n){
    if(ldr[n]!=n){
        ldr[n] = find(ldr,ldr[n]);
    }
    return ldr[n];
}
void join(vector<int> &ldr,int l,int r){
    ldr[find(ldr,r)] = find(ldr,l);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> ldr(n+1);
    for(int i=1;i<=n;i++)
    ldr[i]=i;
    vector<int> a(m);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[i]=x;
        join(ldr,x,y);
    }
    vector<int> g(n+1,0);
    vector<int> e(n+1,0);
   // int g[n+1]={0},e[n+1]={0};
    for(int i=1;i<=n;i++){
        g[find(ldr,i)]++;
    }
    for(int i=0;i<m;i++){
        e[find(ldr,a[i])]++;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=((1ll*(1ll*g[i]*(g[i]-1))/2)-e[i]);
    }
    cout<<ans;
    
}
