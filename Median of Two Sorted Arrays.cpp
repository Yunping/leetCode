//The answer: http://leetcode.com/2011/03/median-of-two-sorted-arrays.html

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m == 0)
            return getMediaForSingleArray(B, n);
        if (n == 0)
            return getMediaForSingleArray(A, m);
        if (m == 1)
            return getMediaForEdgeCase1(A[0], B, n);
        if (n == 1)
            return getMediaForEdgeCase1(B[0], A, m);
        if (m == 2)
            return getMediaForEdgeCase2(A[0], A[1], B, n);
        if (n == 2)
            return getMediaForEdgeCase2(B[0], B[1], A, m);
        
        int k = 0;
        int i = m/2, j = n/2;
        if (A[i] <= B[j]) {
            if (m%2 != 0) {
                k = min(i, n-j-1);
            } else {
                k = min(i-1, n-j-1);
            }
            return findMedianSortedArrays(A+k, m-k, B, n-k);
        } else {
            if (n%2 != 0) {
                k = min(m-i-1, j);
            } else {
                k = min(m-i-1, j-1);
            }
            return findMedianSortedArrays(A, m-k, B+k, n-k);
        }
    }
    
private:
    double getMediaForSingleArray(int a[], int n) {
        if (n%2)
            return a[n/2];
        else
            return (a[n/2] +a[n/2-1])/2.0;
    }
    
    double getMediaForEdgeCase1(int elem, int a[], int n) {
        if (n == 0)
            return elem;
        if (n == 1)
            return (elem + a[0])/2.0;
    	
        if (n == 2) {
            if (elem <= a[0])
                return a[0];
            if (elem <= a[1])
                return elem;
            return a[1];
        }
        
        int left = a[n/2 - 1], middle = a[n/2], right = a[n/2 + 1];
        if (elem <= left) {
            if (n%2 != 0)
                return (left + middle)/2.0;
            else
                return left;
        }
        if (elem <= middle) {
            if (n%2 != 0)
                return (elem + middle)/2.0;
            else
                return elem;
        }
        if (elem <= right) {
            if (n%2 != 0)
                return (middle + elem)/2.0;
            else
                return middle;
        }
        
        if (n%2 != 0)
            return (middle + right)/2.0;
        else
            return middle;
        
    }
    
    double getMediaForEdgeCase2(int elem1, int elem2, int a[], int n) {
        if (n == 0)
            return (elem1 + elem2)/2.0;
        if (n == 1) {
            if (a[0] >= elem1)
                return a[0] <= elem2 ? a[0] : elem2;
            return elem1;
        }

        
        if (n%2 != 0) {
            int left = a[n/2 - 1], middle = a[n/2], right = a[n/2 + 1];
            if (elem2 <= middle)
                return elem2 > left ? elem2 : left;
            if (elem1 >= middle)
                return elem1 < right ? elem1 : right;
            return middle;
        } else {
            int left1 = n/2-2 >= 0 ? a[n/2-2] : INT_MIN;
            int left2 = a[n/2-1];
            int right1 = a[n/2];
            int right2 = n/2+1 <= n-1 ? a[n/2+1] : INT_MAX;
            if (elem2 < left1)
                return (left1 + left2)/2.0;
            if (elem2 < left2)
                return (left2 + elem2)/2.0;
            if (elem2 < right1)
                return (elem2 + max(left2, elem1))/2.0;
            if (elem2 < right2)
                return (right1 + max(elem1, left2))/2.0;
            if (elem1 < left2)
                return (left2 + right1)/2.0;
            if (elem1 < right1)
                return (elem1 + right1)/2.0;
            return (right1 + min(elem1, right2))/2.0;   
        }
    }
    
    int min(int a, int b) {
        return a <= b ? a : b;
    }
};