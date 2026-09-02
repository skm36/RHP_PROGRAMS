#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& seg, int node, int nl, int nr, int L, int R) {
    if (nr < L || nl > R) {
        return 1e9+1;
    }
    if (nl >= L && nr <= R) {
        return seg[node];
    }
    int mid = (nl + nr) / 2;
    int ltr = find(seg, node*2, nl, mid, L, R);
    int rtr = find(seg, node*2+1, mid+1, nr, L, R);
    return min(ltr, rtr);
}
int main() {
    int N, q;
    cin >> N >> q;
    int newN = 1;

    while(newN < N) {
        newN<<1;
    }   

    vector<int> seg(newN + newN, 1e9+1);
    for (int i = newN; i < newN + N; i++) {
        cin >> seg[i];
    }
    for (int i = newN - 1; i > 0; i--) {
        seg[i] = min(seg[i+i], seg[i+i+1]);
    }
    N = newN;

    while (q--){
        int L, R;
        cin >> L >> R;
        cout << find(seg, 1, 1, N, L, R) << endl;
    }
    return 0;
}
