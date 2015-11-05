
struct TrieNode {
    TrieNode* next[26];
    bool isLeaf;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        isLeaf = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        tn = new TrieNode();
    }

    int idx(char c) {
        return (c - 'a');
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* t = tn;
        int len = word.length();
        for (int i = 0; i < len; i++) {
            int c = idx(word[i]);
            if (t->next[c] == NULL) {
                t->next[c] = new TrieNode();
            }
            t = t->next[c];
        }
        t->isLeaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.length() == 0) return false;
        return searchSuffix(word, 0, tn);
    }

    bool contains(TrieNode* t, char c) {
        return (c == '.' || t->next[idx(c)] != NULL);
    }

    bool searchSuffix(const string& w, int st, TrieNode* t) {
        if (t == NULL) return false;
        int len = w.length();
        if (st == len) {
            return t->isLeaf;
        }
        if (w[st] == '.') {
            for (int i = 0; i < 26; i++) {
                if (searchSuffix(w, st + 1, t->next[i])) {
                    return true;
                }
            }
            return false;
        } else {
            return searchSuffix(w, st + 1, t->next[idx(w[st])]);
        }
    }

private:
    TrieNode* tn;
};


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
