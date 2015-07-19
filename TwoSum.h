/*
 Problem: Two Sum
 
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 
 =============================================================================
 
 Author: Yunping, qufang83@gmail.com
 Date: 12/21/2014
 Difficulty: **
 Solution: ...
 */
class Solution {
private:
    struct Value {
        int value;
        int index;
        Value(int v, int i) : value(v), index(i) {}
    };
    
    struct ValueCmp {
        bool operator() (const Value& v1, const Value& v2) const {
            return v1.value < v2.value;
        }
    } valueCmp;
    
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> ret(2, 0);
        vector<Value> values;
        for (int i = 0; i < numbers.size(); ++i)
            values.push_back(Value(numbers[i], i+1));
        
        std::sort(values.begin(), values.end(), valueCmp);
        
        for (int i = 0, j = values.size()-1; i < j;) {
            int s = values[i].value + values[j].value;
            if (s == target) {
                ret[0] = min(values[i].index, values[j].index);
                ret[1] = max(values[i].index, values[j].index);
                break;
            }
            
            if (s < target)
                ++i;
            else
                --j;
        }
        
        return ret;
    }
    
};