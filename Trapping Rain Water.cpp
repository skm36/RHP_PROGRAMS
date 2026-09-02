#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class TrappingRainWater {

public:
    static int trap(vector<int>& height) {

        if (height.empty() || height.size() < 3) {
            return 0;
        }

        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        rightMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int water = 0;

        for (int i = 1; i < n - 1; i++) {
            water += min(leftMax[i], rightMax[i]) - height[i];
        }

        return water;
    }
};

int main() {

    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    cout << TrappingRainWater::trap(height) << endl;

    return 0;
}
