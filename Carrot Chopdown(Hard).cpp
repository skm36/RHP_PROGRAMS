#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long int

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> cnt(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        cnt[curr]++;
    }

    vector<int> psum(m + 1, 0);

    for (int i = 1; i <= m; i++) {
        psum[i] = psum[i - 1] + cnt[i];
    }

    ll totalSum = 0;

    for (int i = 1; i <= m; i++) {
        totalSum += 1LL * i * cnt[i];
    }

    vector<ll> answer;
    ll pieces = 2; // 2^k, initially k = 1

    while (pieces < m) {
        ll ans = 0;

        for (int x = 1; x <= m; x++) {
            ll carrotcnt = 0;

            
            ll cutPoint = min(1LL * m, pieces * 1LL * x);
            ll groups = cutPoint / x;

            for (ll q = 1; q <= groups; q++) {
                int left = q * x;

                
                int right = min(cutPoint, (q + 1) * 1LL * x - 1);

                carrotcnt += q * 1LL *
                             (psum[right] - psum[left - 1]);
            }

            
            if (cutPoint < m) {
                carrotcnt += (pieces - 1) * 1LL *
                             (psum[m] - psum[(int)cutPoint]);
            }

            ans = max(ans, carrotcnt);
        }

        answer.push_back(ans);
        pieces *= 2;
    }

    
    answer.push_back(totalSum);

    while ((int)answer.size() < m) {
        answer.push_back(totalSum);
    }

    for (int i = 0; i < m; i++) {
        cout << answer[i] << (i == m - 1 ? '\n' : ' ');
    }
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
