#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int hcf(int a, int b){
	if(b==0) return a;
	return hcf(b,a%b);
}

void solve(){
	int n; cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<hcf(arr[0], arr[n-1])<<endl;
}

int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
