/**
Median of Two Sorted Arrays

There are two sorted arrays A and B of size m and n respectively. 

Find the median of the two sorted arrays. 

The overall run time complexity should be O(log (m+n)).
**/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int total = m + n;
        if (total % 2 == 0) {
            return (FindKth(A, m, B, n, total/2) + FindKth(A, m, B, n, total/2+1)) / 2;
        } else {
            return FindKth(A, m, B, n, total/2 + 1);
        }
    }
    
    double FindKth(int A[], int m, int B[], int n, int k) {
        if (m > n) return FindKth(B, n, A, m, k);
        if (m == 0) return B[k-1];
        if (n == 0) return A[k-1];
        if (k == 1) return min(A[0], B[0]);
        
        int aMid = min(k/2, m);
        int bMid = k - aMid;
        if (A[aMid-1] < B[bMid-1]) {
            return FindKth(A+aMid, m-aMid, B, n, k-aMid);
        } else {
            return FindKth(A, m, B+bMid, n-bMid, k-bMid);
        }
    }
};
