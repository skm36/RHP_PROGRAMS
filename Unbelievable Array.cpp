#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find(vector<int> &ldr, int node)
{
    if (ldr[node] != node)
    {
        ldr[node] = find(ldr, ldr[node]);
    }
    return ldr[node];
}

void join(vector<int> &ldr, int lt, int rt)
{
    ldr[find(ldr, lt)] = find(ldr, rt);
}

void solve()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> a(N + 1), ldr(N + 1);
    map<int, int> vlm, lvm;

    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        if (vlm.find(a[i]) == vlm.end())
        {
            vlm[a[i]] = i;
            lvm[i] = a[i];
        }
        ldr[i] = vlm[a[i]];
    }

    while (Q--)
    {
        int c, x, y, idx;
        cin >> c;
        if (c == 1)
        {
            cin >> x >> y;
            if (x == y)
                continue;
            if (vlm.find(x) == vlm.end())
                continue;
            if (vlm.find(y) != vlm.end())
            {
                // Both x and y are there. So join (merge)
                join(ldr, vlm[x], vlm[y]);
                lvm.erase(vlm[x]);
                vlm.erase(x);
            }
            else
            {
                // Only x is there
                int xldr = vlm[x];
                lvm[xldr] = y;
                vlm.erase(x);
                vlm[y] = xldr;
            }
        }
        else
        {
            cin >> idx;
            int uldr = find(ldr, ldr[idx]);
            cout << lvm[uldr] << endl;
        }
    }
}

int main()
{
    int T, c = 1;
    cin >> T;

    while (T--)
    {
        cout << "Case " << c++ << ":" << endl;
        solve();
    }

    return 0;
}
