#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long int N, q;
    cin >> N >> q;

    vector<long long int> arr(N+1, 0);
    for (long long int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }

    while (q--) {
        long long int L, R;
        cin >> L >> R;
        cout << arr[R] - arr[L-1] << endl;
    }

    return 0;
}
