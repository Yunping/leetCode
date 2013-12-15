class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int count = num.size();
        quickSort(num, 0, count - 1);
        //std::sort(num.begin(), num.end());
        
        vector<vector<int> > ret;
        for (int i = 0; i < count-2 && num[i] <= 0; ++i) {
            int target = -num[i];
            int m = i+1;
            int n = count - 1;
            while (m < n) {
                int sum = num[m] + num[n];
                if (sum == target) {
                    int a[] = { -target, num[m], num[n] };
                    vector<int> result(a, a+3);
                    if (std::find(ret.begin(), ret.end(), result) == ret.end())
                        ret.push_back(result);
                    if (m+1 >+ n || n-1 <= m)
                        break;
                    ++m, --n;
                } else if (sum < target)
                    ++m;
                else
                    --n;
            }
        }
        
        return ret;
        
    }
    
    void quickSort(vector<int> &num, int m, int n) {
        if (m < n) {
            int q = partition(num, m, n);
            quickSort(num, m, q-1);
            quickSort(num, q+1, n);    
        }
    }
    
    int partition(vector<int> &num, int m, int n) {
        int q = num[m];
        int i = m;
        int j = m + 1;
        for (j = m+1; j <= n; ++j) {
            if (num[j] < q) {
                ++i;
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }

        num[m] = num[i];
        num[i] = q;
        
        return i;
        
    }
};