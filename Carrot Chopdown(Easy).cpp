#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;
#define ll long long int

void solve(){
	int n,m; cin>>n>>m;
	vector<int> cnt(m+1,0);
	for(int ctr=1;ctr<=n;ctr++){
		int curr; cin>>curr;
		cnt[curr]++;
	}
	vector<int> psum(m+1,0);
	for(int i=1;i<=m;i++){
		psum[i]=psum[i-1]+cnt[i];
	}
	int ans=0;
	for(int x=1;x<=m;x++){
		int carrotcnt=psum[m]-psum[x-1];
		if(2*x<=m){
			carrotcnt+=cnt[2*x];
		}
		ans=max(ans,carrotcnt);
	}
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}
