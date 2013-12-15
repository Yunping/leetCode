class Solution {
public:
    int romanToInt(string s) {
	    int len = s.length();
		int lastValue = 0;
		int ret = 0;
	    for (int i = len - 1; i >= 0; --i) {
			int cur = charToInt(s[i]);
			if (lastValue != 0 && lastValue > cur)
				ret -= cur;
			else
				ret += cur;
			lastValue = cur;
		}
	
		return ret;
	}

	int charToInt(char c) {
		switch (c) {
			case 'I':
				return 1;
			case 'V':
				return 5;
			case 'X':
				return 10;
			case 'L':
				return 50;
			case 'C':
				return 100;
			case 'D':
				return 500;
			case 'M':
				return 1000;
		}
		
		return -1;
	}
};