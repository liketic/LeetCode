// Source : https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
// Author : Ke Li
// Date   : 2016-03-27

/*************************************************************************************** 
 *
 * One way to serialize a binary tree is to use pre-order traversal. When we encounter 
 * a non-null node, we record the node's value. If it is a null node, we record using a 
 * sentinel value such as #.
 * 
 *      _9_
 *     /   \
 *    3     2
 *   / \   / \
 *  4   1  #  6
 * / \ / \   / \
 * # # # #   # #
 * 
 * For example, the above binary tree can be serialized to the string 
 * "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
 * 
 * Given a string of comma separated values, verify whether it is a correct preorder 
 * traversal serialization of a binary tree. Find an algorithm without reconstructing 
 * the tree.
 * 
 * Each comma separated value in the string must be either an integer or a character 
 * '#' representing null pointer.
 * 
 * You may assume that the input format is always valid, for example it could never 
 * contain two consecutive commas such as "1,,3".
 * 
 * Example 1:
 * "9,3,4,#,#,1,#,#,2,#,6,#,#"
 * Return true
 * Example 2:
 * "1,#"
 * Return false
 * Example 3:
 * "9,#,#,1"
 * Return false
 * 
 * Credits:Special thanks to @dietpepsi for adding this problem and creating all test 
 * cases.
 ***************************************************************************************/

#include <vector>


class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> strings = split(preorder, ',');
        int maxNull = 1;
        for (int i = 0; i < strings.size(); i++) {
            if (strings[i] == "#") {
                maxNull--;
                if (maxNull < 0) return false;
            } else {
                if (maxNull == 0) {
                    return false;
                }
                maxNull++;
            }
        }
        return maxNull == 0;
    }
    
private:
    vector<string> split(const string& source, const char& delim) {
        vector<string> array;
        int pos = 0;
        for (int i = 0; i < source.length(); i++) {
            if (source[i] == delim) {
                array.push_back(source.substr(pos, i - pos));
                pos = i + 1;
            }
        }
        array.push_back(source.substr(pos, source.length() - pos));
        return array;
    }
};

