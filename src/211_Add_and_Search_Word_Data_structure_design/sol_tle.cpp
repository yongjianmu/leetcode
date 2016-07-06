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

class WordDictionary {
public:

    unordered_map<string, bool> mp;
    // Adds a word into the data structure.
    void addWord(string word) {
        mp[word] = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(mp.find(word) != mp.end())
        {
            return true;
        }

        for(auto it = mp.begin(); it != mp.end(); ++it)
        {
            if(it->first.length() == word.length())
            {
                int i = 0;
                for(i = 0; i < word.length(); ++i)
                {
                    if('.' == word[i])
                    {
                        continue;
                    }

                    if(it->first[i] != word[i])
                    {
                        break;
                    }
                }

                if(i == word.length())
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");


int main()
{
    return 0;
}
