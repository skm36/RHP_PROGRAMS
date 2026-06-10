#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int lower = 0, upper = 0, digit = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= 'a' && s[i] <= 'z')
            lower = lower | (1 << (s[i] - 'a'));
        else if(s[i] >= 'A' && s[i] <= 'Z')
            upper = upper | (1 << (s[i] - 'A'));
        else if(s[i] >= '0' && s[i] <= '9')
            digit = digit | (1 << (s[i] - '0'));
    }
    if(lower == (1 << 26) - 1 &&
       upper == (1 << 26) - 1 &&
       digit == (1 << 10) - 1)
        cout << "Complete";
    else
        cout << "Not Complete";
    return 0;
}
