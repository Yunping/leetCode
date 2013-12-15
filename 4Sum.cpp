class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(num.begin(), num.end());
        int len = num.size();
        vector<vector<int> > ret;
        
        for (int i = 0; i < len-3; ++i) {
            int target3 = target - num[i];
            for (int j = i+1; j < len-2; ++j) {
                int m = j + 1;
                int n = len - 1;
                while (m < n) {
                    int sum3 = num[j] + num[m] + num[n];
                    if (sum3 == target3) {
                        int a[] = {num[i], num[j], num[m], num[n]};
                        vector<int> v(a, a+4);
                        if (std::find(ret.begin(), ret.end(), v) == ret.end())
                            ret.push_back(v);
                        ++m;
                        --n;
                    } else if (sum3 < target3) {
                        ++m;
                    } else
                        --n;
                    }
            }
        }
        
        return ret;
    }
};

// 加上去除重复的判断
// http://www.cnblogs.com/remlostime/archive/2012/10/27/2742676.html

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::sort(num.begin(), num.end());
        int len = num.size();
        vector<vector<int> > ret;
        
        for (int i = 0; i < len-3; ++i) {
        	if (i > 0 && num[i] == num[i-1])
        		continue;
            int target3 = target - num[i];
            for (int j = i+1; j < len-2; ++j) {
            	if (j > i+1 && num[j] == num[j-1])
            		continue;
            	
                int m = j + 1;
                int n = len - 1;
                while (m < n) {
                	if (m > j+1 && num[m] == num[m-1]) {
                		++m;
                		continue;
                	}
                	if (n < len-1 && num[n] == num[n+1]) {
                		--n;
                		continue;
                	}
                    int sum3 = num[j] + num[m] + num[n];
                    if (sum3 == target3) {
                        int a[] = {num[i], num[j], num[m], num[n]};
                        vector<int> v(a, a+4);
                        ret.push_back(v);
                        ++m;
                        --n;
                    } else if (sum3 < target3) {
                        ++m;
                    } else
                        --n;
                    }
            }
        }
        
        return ret;
    }
};
