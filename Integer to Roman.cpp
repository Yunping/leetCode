class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret;    
        int v[] = { 1, 5, 10, 50, 100, 500, 1000 };
        char c[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
        int count = sizeof(v)/sizeof(int);
        
        while (num > 0) {
            int i = count - 1;
            while (num < v[i]) {
	        	--i;
	        }
	        
	        if (i % 2) {
	        	// between 5 and 10
	        	int p = num / v[i-1];
	        	if (p < 9) {
	        		ret.push_back(c[i]);
	        		num = num - v[i];
	        	} else {
	        		ret.push_back(c[i-1]);
	        		ret.push_back(c[i+1]);
	        		num = num - v[i+1] + v[i-1];
	        	}
	        } else {
	        	// between 1 and 5
	        	int p = num / v[i];
	        	if (p < 4) {
	        		while (p > 0) {
	        			ret.push_back(c[i]);
	        			num -= v[i];
	        			--p;
	        		}
	        	} else {
	        		ret.push_back(c[i]);
	        		ret.push_back(c[i+1]);
	        		num = num + v[i] - v[i+1];
	        	}
	        	
	        }
        }
        
        return ret;
    }
};