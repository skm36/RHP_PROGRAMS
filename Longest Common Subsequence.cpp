#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a;
    cin >> b;

    vector<vector<int>> dp(a.length() + 1,
                           vector<int>(b.length() + 1, 0));

    int m = 0;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {

            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string t = "";
    int i = a.length();
    int j = b.length();

    while (i > 0 && j > 0) {

        if (a[i - 1] == b[j - 1]) {
            t += a[i - 1];
            i--;
            j--;
        }
        else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    cout << "Length " << dp[a.length()][b.length()] << endl;
    reverse(t.begin(), t.end());
    cout << "Longest Subsequence " << t << endl;

    return 0;
}
