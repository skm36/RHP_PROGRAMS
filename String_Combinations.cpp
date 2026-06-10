#include <iostream>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 1; i < (1 << n); i++) {
        for(int pos = 0; pos < n; pos++) {
            int val = (i >> pos) & 1;
            if(val) {
                cout << s[pos];
            }
        }
        cout << endl;
    }
    return 0;
}
