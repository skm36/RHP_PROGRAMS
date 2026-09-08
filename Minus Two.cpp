#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long int

void solve(){
	int n; cin>>n;
	int odd=0,eoq=0, eeq=0;
	for(int ctr=1;ctr<=n;ctr++){
		int curr; cin>>curr;
		if(curr&1) odd++;
		else{
			int q=curr/2;
			if(q&1) eoq++;
			else { eeq++;}
		}
	}
	cout<<max({odd,eoq,eeq})<<endl;
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
