// Source : https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author : Ke Li
// Date   : 2016-03-12

/***************************************************************************************
 *
 * Design a data structure that supports the following two operations:
 *
 * void addWord(word)
 * bool search(word)
 *
 * search(word) can search a literal word or a regular expression string containing
 * only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:
 *
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 *
 * Note:
 * You may assume that all words are consist of lowercase letters a-z.
 *
 * click to show hint.
 *
 * You should be familiar with how a Trie works. If not, please work on this problem:
 * Implement Trie (Prefix Tree) first.
 ***************************************************************************************/

#include<iostream>
using namespace std;

// max index
const int TRIE_SIZE = 26;

struct TrieNode {
    TrieNode* next[TRIE_SIZE];
    bool isLeaf;
    
    TrieNode() {
        for (int i = 0; i < TRIE_SIZE; i++) {
            next[i] = NULL;
        }
        isLeaf = false;
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* t = root;
        for (int i = 0; i < word.length(); i++) {
            int c = idx(word[i]);
            if (!t->next[c]) {
                t->next[c] = new TrieNode();
            }
            t = t->next[c];
        }
        t->isLeaf = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return word.length() > 0 && find(word, 0, root);
    }
    
private:
    TrieNode* root; // store all words using trie
    
    bool contains(TrieNode* node, char c) {
        return (c == '.' || node->next[idx(c)]);
    }
    
    // calculate index of a char in trie
    int idx(char c) {
        return (c - 'a');
    }
    
    // find a word in trie tree
    bool find(const string& word, int pos, TrieNode* node) {
        if (!node) return false;
        if (pos == word.length()) {
            return node->isLeaf;
        }
        if (word[pos] == '.') {
            for (int i = 0; i < TRIE_SIZE; i++) {
                if (find(word, pos + 1, node->next[i])) {
                    return true;
                }
            }
            return false;
        }
        return find(word, pos + 1, node->next[idx(word[pos])]);
    }
};
