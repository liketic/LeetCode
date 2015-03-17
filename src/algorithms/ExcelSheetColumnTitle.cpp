class Solution {
private:
	static string toStr(int n) {
		char c = 'A' + n;
		string ret = "";
		ret.push_back(c);
		return ret;
	}

public:
    string convertToTitle(int n) {
    	string ret = "";

    	while (n) {
    		n--;
    		int temp = n % 26;
    		ret = toStr(temp) + ret;
    		n /= 26;
    	}

    	return ret;
    }
};
