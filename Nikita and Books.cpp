#include <bits/stdc++.h>
using namespace std;

int main() {

    int y;
    cin >> y;

    for (int k = 0; k < y; k++) {

        int n;
        cin >> n;

        vector<long long> a(n);

        long long b = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int u = 0;

        for (int i = 0; i < n; i++) {

            if (a[i] >= i + 1) {
                b += a[i] - (i + 1);
            }
            else {

                if (a[i] + b >= i + 1) {
                    b -= (i + 1 - a[i]);
                }
                else {
                    cout << "NO" << endl;
                    u++;
                    break;
                }
            }
        }

        if (u == 0)
            cout << "YES" << endl;
    }

    return 0;
}
