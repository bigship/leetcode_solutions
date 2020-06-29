#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> mountArr = {1, 2, 3, 5, 3};

int findPeakIndex(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
        int m = l + (r - l) /2;
        if (nums[m] > nums[m+1]) r = m;
        else l = m + 1;
    }
    return l;
}

int findTargetFirstHalf(int target, int peak, vector<int>& nums) {
    int l = 0;
    int r = peak;
    while (l <= r) {
        int m = (r - l ) / 2 + l;
        if (nums[m] == target) return m;
        else if (nums[m] > target) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int findTargetSecondHalf(int target, int peak, vector<int>& nums) {
    int l = peak;
    int r = nums.size() - 1;
    while (l <= r) {
        int m = (r - l ) / 2 + l;
        if (nums[m] == target) return m;
        else if (nums[m] > target)  l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    int target = 0;
    int peak = findPeakIndex(mountArr);
    cout << "peak index: " << peak << endl;
    int l = findTargetFirstHalf(target, peak, mountArr);
    int r = findTargetSecondHalf(target, peak, mountArr);
    cout << "left: " << l << ", right = " << r << endl;

    int ans = -1;
    if (l != -1 && r != -1) ans = min(l, r);
    if (l != -1 && r == -1) ans = l;
    if (l == -1 && r != -1) ans = r;

    cout << "ans = " << ans << endl;
    return 0;
}

