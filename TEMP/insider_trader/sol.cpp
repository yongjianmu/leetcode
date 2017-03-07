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
    int price;
};

class cmp
{
public:
    bool operator() (const UserAction& a, const UserAction& b) const
    {
        return a.date <= b.date;
    }
};

map<int, set<string> > findInsider(set<pair<int, int> >& prices, set<UserAction, cmp>& userActions)
{
    auto iter_ua_begin = userActions.begin();
    map<int, set<string> > ret;
    for(auto& p : prices)
    {
        while(iter_ua_begin != userActions.end() && iter_ua_begin->date + 3 < p.first)
        {
            ++iter_ua_begin;
        }

        auto it = iter_ua_begin;
        while(it != userActions.end())
        {
            if(it->date >= p.first) break;
            if(!it->sell && (it->number * (p.second - it->price)) >= 500000)
            {
                ret[it->date].insert(it->name);
            }

            if(it->sell && (it->number * (it->price - p.second)) >= 500000)
            {
                ret[it->date].insert(it->name);
            }
            ++it;
        }

    }
    return ret;
}

int main()
{
    string cur;
    set<pair<int, int> > prices;
    set<UserAction, cmp> userActions;
    vector<UserAction> userVector;
    int lines = INT_MAX, cnt = 1;
    while(getline(cin, cur))
    {
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
            userVector.push_back(ua);
            ++cnt;
        }
        else if(temp.size() == 1)
        {
            lines = stoi(temp[0]);
        }
    }

    for(auto& u : userVector)
    {
        auto iter = prices.lower_bound({u.date, 0});
        if(iter == prices.end() || iter->first != u.date)
        {
            advance(iter, -1);
        }
        u.price = iter->second;
        userActions.insert(u);
    }

    map<int, set<string> > result = findInsider(prices, userActions);
    for(auto iter = result.begin(); iter != result.end(); ++iter)
    {
        for(auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            cout << iter->first << "|" << *it << endl;
        }
    }

    return 0;
}
