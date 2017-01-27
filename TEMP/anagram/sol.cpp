vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if(s.empty()) return ret;
        vector<int> dict(256, 0);
        for(char c : p) ++dict[c];
        int left = 0, right = 0, cnt = p.length(), s_len = s.length(), p_len = p.length();
        while(right < s_len)
        {
            if(dict[s[right++]]-- > 0) --cnt;
            if(0 == cnt) ret.push_back(left);
            if(right - left == p_len && dict[s[left++]]++ >= 0) ++cnt;
        }
        return ret;
    }
