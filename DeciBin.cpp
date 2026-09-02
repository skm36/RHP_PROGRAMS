#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int minPartitions(string n)
{
    int mx = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if (mx < (n[i]))
        {
            mx = n[i];
        }
    }
    return mx - '0';
}

int main()
{
    string n;
    cin >> n;

    int mx = minPartitions(n);
    int N = n.size();

    vector<int> a(mx, 0);

    for (int i = 0; i < N; i++)
    {
        int dig = n[i] - '0';
        for (int j = 0; j < dig; j++)
        {
            int t = pow(10, N - i - 1);
            a[j] = a[j] + t;
        }
    }

    for (int i : a)
    {
        cout << i << " ";
    }

    return 0;
}
