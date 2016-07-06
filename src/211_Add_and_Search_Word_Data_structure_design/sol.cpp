#include "../include/header.h"

/*
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
*/

class TrieNode {
public:
	static const int c_size = 26;
	bool end;
	TrieNode *child[26];
	// Initialize your data structure here.
	TrieNode() {
		end = false;
		for (int i = 0; i < c_size; i++) child[i] = NULL;
	}
};
 
class WordDictionary {
public:
	WordDictionary() {
		root = new TrieNode();
	}
 
	inline int index(const char &c){
		return c - 'a';
	}
 
	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.length(); i++){
			int id = index(word[i]);
			if (!p->child[id]){
				TrieNode *t = new TrieNode();
				p->child[id] = t;
			}
			p = p->child[id];
		}
		p->end = true;
	}
 
	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return match_word(root,0,word);
	}
 
	~WordDictionary() {
		deleteNode(root);
	}
 
	void deleteNode(TrieNode *root){
		if (!root) return;
		for (int i = 0; i < TrieNode::c_size; i++){
			deleteNode(root->child[i]);
		}
		delete root;
	}
 
private:
	TrieNode* root;
	bool match_word(TrieNode *p ,int k,const string &word){
		if (!p || k > word.length()) return false;
		if (k == word.length() && p->end) return true;
		for (; k < word.length(); k++){
			if (word[k] == '.') {
				for (int j = 0; j < TrieNode::c_size; j++){
					if (match_word(p->child[j], k + 1, word))
						return true;
				}
				return false;
			}
			else{
				int id = index(word[k]);
				if (!p->child[id])	return false;
				p = p->child[id];
			}
		}
		return p->end;
	}
};
