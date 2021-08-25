// 1865. Finding Pairs With a Certain Sum
/*
 * You are given two integer arrays nums1 and nums2.
 * You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.

*/

class FindSumPairs {
public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    arr1 = &nums1;
    arr2 = &nums2;
    for (auto val : nums2) {
      cntmap[val]++;
    }
  }

  void add(int index, int val) {
    int old = (*arr2)[index];
    (*arr2)[index] += val;
    cntmap[old]--;
    if (cntmap[old] == 0) {
      cntmap.erase(old);
    }
    cntmap[(*arr2)[index]]++;
  }

  int count(int target) {
    int n = (*arr1).size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int val = target - (*arr1)[i];
      if (cntmap.find(val) != cntmap.end()) {
        cnt += cntmap[val];
      }
    }
    return cnt;
  }
private:
  vector<int> *arr1;
  vector<int> *arr2;
  std::unordered_map<int, int> cntmap;
};

