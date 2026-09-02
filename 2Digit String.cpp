#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int k = 0; k < n; k++) {

        string a, b;
        cin >> a >> b;

        vector<int> x(a.length());
        vector<int> y(b.length());

        x[0] = a[0] - '0';
        y[0] = b[0] - '0';

        for (int i = 1; i < a.length(); i++) {
            x[i] = (x[i - 1] + (a[i] - '0')) % 10;
        }

        for (int i = 1; i < b.length(); i++) {
            y[i] = (y[i - 1] + (b[i] - '0')) % 10;
        }

        if (y[b.length() - 1] != x[a.length() - 1]) {
            cout << -1 << endl;
            continue;
        }

        vector<vector<int>> d(
            a.length() + 1,
            vector<int>(b.length() + 1, 0)
        );

        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {

                if (x[i - 1] == y[j - 1])
                    d[i][j] = 1 + d[i - 1][j - 1];

                else
                    d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }

        cout << d[a.length()][b.length()] << endl;
    }

    return 0;
}
