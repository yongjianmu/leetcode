#include "../include/header.h"

class TrieNode {
public:
    bool isWord;
    TrieNode* child[26];
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        for(auto& c : child)
        {
            c = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(char c : word)
        {
            int a = c - 'a';
            if(NULL == p->child[a])
            {
                p->child[a] = new TrieNode();
            }
            p = p->child[a];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for(char c : word)
        {
            int a = c - 'a';
            if(NULL == p->child[a])
            {
                return false;
            }
            p = p->child[a];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(char c : prefix)
        {
            int a = c - 'a';
            if(NULL == p->child[a])
            {
                return false;
            }
            p = p->child[a];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    string input = "aaaaaaaaaaaaaaaaaaaaaaaaa";
    Trie sol;
    sol.insert(input);
    cout << "input ok" << endl;
    bool result = sol.startsWith("a");
    printResult();
    cout << result << endl;

    return 0;
}
