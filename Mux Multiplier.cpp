#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long int

void solve(){
	int n;cin>>n;
	vector<int> arr(n);
	vector<int> zi;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==0) zi.push_back(i);
	}
	if(zi.size()==1){
		cout<<"NO"<<endl; return;
		
	}
	string s(n,'C');
	if(zi.size()>0){
		int fzidx=zi[0];
		s[fzidx]='B';
		for(unsigned int i=1;i<zi.size();i++){
			s[zi[i]]='A';
		}
	}
	cout<<"YES"<<endl<<s<<endl;
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
