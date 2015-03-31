class Solution {
private:
	bool isVaild(char c) {
		return (c != ' ');
	}
public:
	void reverseWords(string &s) {
		int n = s.size();

		for (int i = 0, j = n - 1; i < j; i++, j--) {
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
		int p = -1;
		for (int i = 0; i <= n; i++) {
			if (i < n && this->isVaild(s[i])) {
				if (p == -1) {
					p = i;
				}
			} else {
				if ((i == n || !this->isVaild(s[i])) && p != -1) {
					for (int j = i - 1; j > p; j--, p++) {
						char c = s[j];
						s[j] = s[p];
						s[p] = c;
					}
					p = -1;
				}
			}
		}
		bool prevIsBlank = false;
		bool isFirst = true;
		int j = 0;
		//cout << s << endl;
		for (int i = 0; i < n; i++) {
			if (this->isVaild(s[i])) {
				if (prevIsBlank && !isFirst) {
					s[j++] = s[i - 1];
				}
				s[j++] = s[i];
				isFirst = prevIsBlank = false;
			} else {
				prevIsBlank = true;
			}
		}
		//cout << j << endl;
		s = s.substr(0, j);
	}
};

