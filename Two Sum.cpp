class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        size_t len = numbers.size();
        vector<int> ret;
        for (size_t i = 0; i < len - 1; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                if (numbers[i] + numbers[j] == target) {
                    ret.push_back(i + 1);
                    ret.push_back(j + 1);
                    break;
                }
            }
        }
        
        return ret;
    }
};



class Solution2 {
public:
    
    struct item {
        int value;
        int index;
    };
    
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret;
        vector<item> sorted;
        int len = numbers.size();
        for (int i = 0; i < len; ++i) {
			item it;
			it.value = numbers[i];
			it.index = i + 1;
            sorted.push_back(it);
		}
		
        quickSort(sorted, 0, len - 1);
        
        for (int i = 0; i < len; ++i) {
            int first = sorted[i].value;
            int second = target - first;
            int j = binarySearch(sorted, i + 1, len - 1, second);
            if (j != -1) {
                if (sorted[i].index < sorted[j].index) {
                    ret.push_back(sorted[i].index);
                    ret.push_back(sorted[j].index);
                } else {
                    ret.push_back(sorted[j].index);
                    ret.push_back(sorted[i].index);
                }
                break;
            }
        }
        
        return ret;
    }
    
private:
    int partition(vector<item>& items, int l, int r) {
        item v = items[l];
        int i = l;
        for (int j = l + 1; j <= r; ++j) {
            if (v.value > items[j].value) {
                ++i;
                item t = items[j];
                items[j] = items[i];
                items[i] = t;
            }
        }
        
        item t = items[i];
        items[i] = v;
        items[l] = t;
        
        return i;
    }
    
    void quickSort(vector<item>& items, int l, int r) {
        if (l < r) {
			int v = partition(items, l, r);
			quickSort(items, l, v - 1);
			quickSort(items, v + 1, r);
		}
    }
    
    int binarySearch(const vector<item>& items, int l, int r, int key) {
        if (l > r) return -1;
        int v = (l + r)/2;
        
        if (items[v].value == key)
            return v;
        
        if (items[v].value < key)
            return binarySearch(items, v + 1, r, key);
        
        return binarySearch(items, l, v - 1, key);
    }
    
};

class Solution3 {
public:
    struct item {
        int value;
        int index;
    };
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        size_t len = numbers.size();
        vector<item> sorted;
        for (int i = 0; i < len; ++i) {
            sorted.push_back({numbers[i], i + 1});
        }
        
        quickSort(sorted, 0, len - 1);
        
        vector<int> ret;
        int i = 0, j = len - 1;
        while(i < j) {
            int first = sorted[i].value;
            int second = sorted[j].value;
            int sum = first + second;
            if (sum == target) {
                if (sorted[i].index > sorted[j].index) {
                    ret.push_back(sorted[j].index);
                    ret.push_back(sorted[i].index);
                } else {
                    ret.push_back(sorted[i].index);
                    ret.push_back(sorted[j].index);
                }   
                break;
            }
            if (sum > target)
                --j;
            else
                ++i;
        }
        
        return ret;
        
    }
    
    int partition(vector<item>& items, int l, int r) {
        item v = items[l];
        int i = l;
        for (int j = l + 1; j <= r; ++j) {
            if (v.value > items[j].value) {
                ++i;
                item t = items[j];
                items[j] = items[i];
                items[i] = t;
            }
        }
        
        item t = items[i];
        items[i] = v;
        items[l] = t;
        
        return i;
    }
    
    void quickSort(vector<item>& items, int l, int r) {
        if (l < r) {
    		int v = partition(items, l, r);
			quickSort(items, l, v - 1);
			quickSort(items, v + 1, r);
		}
    }
};