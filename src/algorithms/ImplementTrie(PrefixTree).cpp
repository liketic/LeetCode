
const int INDEX_SIZE = 26;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < INDEX_SIZE; i++) {
            next[i] = NULL;
        }
        isLeaf = false;
    }
    TrieNode* next[INDEX_SIZE];
    bool isLeaf;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word[i] - 'a';
            if (temp->next[c] == NULL) {
                temp->next[c] = new TrieNode();
            }
            temp = temp->next[c];
        }
        temp->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = root;
        for (int i = 0; i < word.length(); i++) {
            int c = word[i] - 'a';
            if (temp->next[c] == NULL) {
                return false;
            }
            temp = temp->next[c];
        }
        return temp->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (int i = 0; i < prefix.length(); i++) {
            int c = prefix[i] - 'a';
            if (temp->next[c] == NULL) {
                return false;
            }
            temp = temp->next[c];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
