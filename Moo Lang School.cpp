#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long int

void solve(){
	int n,k; cin>>n>>k;
	string s; cin>>s;
	int f=n/k;
	vector<bool> own(f, false);
	for(unsigned int i=0;i<s.size();i++){
		if(s[i]=='0'){
			int farmidx=i/k;
			own[farmidx]=true;
		}
	}
	int count=0;
	for(int fm=0; fm<f;fm++){
		if(!own[fm]){
			count++;
		}
	}
	cout<<count<<endl;
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
