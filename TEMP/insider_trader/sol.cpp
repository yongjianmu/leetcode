#include "../../second/include/header.h"

void split(string s, vector<string>& ret, char delim)
{
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, delim))
    {
        ret.push_back(temp);
    }
}

struct UserAction
{
    int date;
    string name;
    bool sell;
    int number;
};

class cmp
{
public:
    bool operator() (const UserAction& a, const UserAction& b) const
    {
        return a.date <= b.date;
    }
};

unordered_map<int, set<string> > findInsider(set<pair<int, int> >& prices, set<UserAction, cmp>& userActions)
{
    list<pair<int, int> > window;
    auto iter_ua_begin = userActions.begin();
    unordered_map<int, set<string> > ret;
    for(auto& p : prices)
    {
        for(auto iter = window.begin(); iter != window.end(); ++iter)
        {
            if(iter->first + 3 < p.first)
            {
                window.erase(iter);
            }
            else
            {
                auto it = iter_ua_begin;
                while(it != userActions.end())
                {
                    if(it->date >= p.first) break;
                    if(iter->second < p.second) // price increased, check buy
                    {
                        if(it->sell) break; // sell, ignore
                        if((it->number * (p.second - iter->second)) >= 500000)
                        {
                            ret[it->date].insert(it->name);
                        }
                    }
                    else if(iter->second > p.second) // price decrease, check sell
                    {
                        if(!it->sell) break; // sell, ignore
                        if((it->number * (iter->second - p.second)) >= 500000)
                        {
                            ret[it->date].insert(it->name);
                        }
                    }
                    ++it;
                }
            }
        }
        window.push_back(p);
        while(iter_ua_begin != userActions.end() && iter_ua_begin->date < window.begin()->first)
        {
            ++iter_ua_begin;
        }
    }
    return ret;
}

int main()
{
    string cur;
    set<pair<int, int> > prices;
    set<UserAction, cmp> userActions;
    int lines = INT_MAX, cnt = 0;
    while(getline(cin, cur))
    {
        cout << cur << endl;
        if(cur.length() == 0 || cnt >= lines) break;
        vector<string> temp;
        split(cur, temp, '|');
        if(temp.size() == 2)
        {
            prices.insert({stoi(temp[0]), stoi(temp[1])});
            ++cnt;
        }
        else if(temp.size() == 4)
        {
            UserAction ua;
            ua.date = stoi(temp[0]);
            ua.name = temp[1];
            ua.sell = temp[2] == "SELL";
            ua.number = stoi(temp[3]);
            userActions.insert(ua);
            ++cnt;
        }
        else if(temp.size() == 1)
        {
            lines = stoi(temp[0]);
        }
    }

    cout << "finish cin parse" << endl;
    unordered_map<int, set<string> > result = findInsider(prices, userActions);
    cout << "finish find parse" << endl;
    for(auto iter = result.begin(); iter != result.end(); ++iter)
    {
        for(auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            cout << iter->first << "|" << *it << endl;
        }
    }

    return 0;
}
