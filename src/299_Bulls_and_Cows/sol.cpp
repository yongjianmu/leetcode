#include "../include/header.h"

/*
Secret number : "1807"
Friend's guess: "7810"
Hint : 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)

Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B". 
Please note that both secret number and friend's guess may contain duplicate digits, for example: 
Secret number : "1123"
Friend's guess: "0111"
In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B". 
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, bool> mp1;
        unordered_map<char, bool> mp2; // cow map
        int bull = 0, cow = 0;
        int len = secret.length();

        for (int i = 0; i < len; i++)
        {
            mp1[secret[i]] = true;
        }

        for (int i = 0; i < len; ++i)
        {
            if (secret[i] == guess[i])
            {
                ++bull;
            }
            else
            {
                if (mp2.find(guess[i]) == mp2.end() && mp1.find(guess[i]) != mp1.end())
                {
                    ++cow;
                    mp2[guess[i]] = true;
                }
            }
        }

        string ret;
        stringstream ss;
        ss << bull;
        ss << 'A';
        ss << cow;
        ss << 'B';
        ss >> ret;
        return ret;
    }
};

int main()
{
    string secret = "1807";
    string guess = "7810";
    Solution sol;
    string result = sol.getHint(secret, guess);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}