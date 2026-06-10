#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;

    int f1 = 0, f2 = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {

            f1 = f1 | (1 << (s[i] - 'a'));
        }
        else if(s[i] >= 'A' && s[i] <= 'Z') {
            f2 = f2 | (1 << (s[i] - 'A'));
        }
    }

    int check = (1 << 26) - 1;
    while(check > 0) {
        if((f1 & 1) != (check & 1) || (f2 & 1) != (check & 1)) {
            cout << "Not Complete";
            return 0;
        }
        f1 = f1 >> 1;
        f2 = f2 >> 1;
        check = check >> 1;
    }
    cout << "Complete";
    return 0;
}
