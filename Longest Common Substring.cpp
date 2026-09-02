#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int dp[a.length() + 1][b.length() + 1];
    int m = 0;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (m < dp[i][j])
                    m = dp[i][j];
            }
        }
    }
    cout << m << endl;
    return 0;
}
