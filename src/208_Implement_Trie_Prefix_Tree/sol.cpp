#include "../include/header.h"

class TrieNode {
public:
    // Initialize your data structure here.
    static const int c_size = 26;
    bool end;
    TrieNode* child[26];

    TrieNode() {
        end = false;
        for(int i = 0; i < c_size; ++i)
        {
            child[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    inline int index(const char& c)
    {
        return c - 'a';
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); ++i)
        {
            int id = index(word[i]);
            if(NULL == p->child[id])
            {
                TrieNode* t = new TrieNode();
                p->child[id] = t;
            }
            p = p->child[id];
        }
        p->end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = match_word(word);
        return (NULL != p && p->end);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        return match_word(prefix);
    }

    ~Trie()
    {
        if(NULL != root)
        {
            delete root;
        }
    }

private:
    TrieNode* root;

    TrieNode* match_word(const string& word)
    {
        TrieNode* p = root;
        for(int i = 0; i < word.length(); ++i)
        {
            int id = index(word[i]);
            if(NULL == p->child[id])
            {
                return NULL;
            }
            p = p->child[id];
        }
        return p;
    }
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


int main()
{
    return 0;
}
