#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define ll long long int

const ll MOD = 1000000007;
const int MAX_N = 200005;

ll fib[MAX_N];

void solve() {
    int n;
    cin >> n;

    vector<int> b(n);
    bool allDestroyed = true;

    for(int i = 0; i < n; i++) {
        cin >> b[i];

        if(b[i] != -1) {
            allDestroyed = false;
        }
    }

    vector<int> diff(n + 1, 0);

    for(int i = 0; i < n; i++) {
        if(b[i] > 0) {
            int left = max(0, i - b[i] + 1);
            int right = min(n, i + b[i]);

            diff[left]++;
            diff[right]--;
        }
    }

    vector<bool> restricted(n, false);
    vector<bool> forced(n, false);

    int current = 0;

    for(int i = 0; i < n; i++) {
        current += diff[i];
        restricted[i] = (current > 0);
    }

    bool possible = true;

    for(int i = 0; i < n; i++) {
        if(b[i] == -1) {
            continue;
        }

        int left = i - b[i];
        int right = i + b[i];

        bool leftPossible =
            left >= 0 && !restricted[left];

        bool rightPossible =
            right < n && !restricted[right];

        int possibilities = leftPossible + rightPossible;

        if(possibilities == 0) {
            possible = false;
            break;
        }

        if(possibilities == 1 || b[i] == 0) {
            if(leftPossible) {
                forced[left] = true;
            }

            if(rightPossible) {
                forced[right] = true;
            }
        }
    }

    if(!possible) {
        cout << 0 << '\n';
        return;
    }

    vector<int> optional;

    for(int i = 0; i < n; i++) {
        if(!restricted[i] && !forced[i]) {
            optional.push_back(i);
        }
    }

    ll treasure_map_fin = 1;
    int chainLength = 1;

    for(int i = 0; i < (int)optional.size(); i++) {
        bool connected = false;

        if(i + 1 < (int)optional.size()) {
            int left = optional[i];
            int right = optional[i + 1];
            int distance = right - left;

            if(distance % 2 == 0) {
                int middle = (left + right) / 2;

                if(b[middle] == distance / 2) {
                    connected = true;
                }
            }
        }

        if(connected) {
            chainLength++;
        }
        else {
            treasure_map_fin *= fib[chainLength + 2];
            treasure_map_fin %= MOD;
            chainLength = 1;
        }
    }

    
    if(allDestroyed) {
        treasure_map_fin =
            (treasure_map_fin - 1 + MOD) % MOD;
    }

    cout << treasure_map_fin << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fib[1] = 1;
    fib[2] = 1;

    for(int i = 3; i < MAX_N; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
