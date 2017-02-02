#include "../../second/include/header.h"

vector<pair<int, int> > drawCircle1(int r)
{
    set<pair<int, int> > st;
    vector<pair<int, int> > ret;
    int x = 1, r2 = r * r;
    while(x <= r)
    {
        for(int y = 0; y <= x; ++y)
        {
            if(x * x + y * y == r2)
            {
                cout << x << ", " << y << endl;
                st.insert({x, y});
                st.insert({x, -y});
                st.insert({-x, y});
                st.insert({-x, -y});
                st.insert({y, x});
                st.insert({y, -x});
                st.insert({-y, x});
                st.insert({-y, -x});
            }
        }
        ++x;
    }

    for(auto iter = st.begin(); iter != st.end(); ++iter)
    {
        ret.push_back({iter->first, iter->second});
    }
    return ret;
}

vector<pair<int, int> > drawCircle2(int r)
{
    set<pair<int, int> > st;
    unordered_set<string> vis;
    vector<pair<int, int> > ret;
    queue<pair<int, int> > q;
    int x = 0, y = r, r2 = r * r;
    q.push({x, y});
    vis.insert(to_string(x) + "#" + to_string(y));
    while(!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        cout << cur.first << ", " << cur.second << endl;
        int pro = cur.first * cur.first + cur.second * cur.second;
        if(pro == r2)
        {
            st.insert(cur);
            st.insert({cur.first, -cur.second});
            st.insert({-cur.first, cur.second});
            st.insert({-cur.first, -cur.second});
            st.insert({cur.second, cur.first});
            st.insert({cur.second, -cur.first});
            st.insert({-cur.second, cur.first});
            st.insert({-cur.second, -cur.first});
            if((cur.first + 1 < r) && (cur.first + 1 <= cur.second) && (vis.find(to_string(cur.first + 1) + "#" + to_string(cur.second)) == vis.end()))
            {
                q.push({cur.first + 1, cur.second});
                vis.insert(to_string(cur.first + 1) + "#" + to_string(cur.second));
            }
            if((cur.second - 1 > 0) && (cur.second - 1 >= cur.first) && (vis.find(to_string(cur.first) + "#" + to_string(cur.second - 1)) == vis.end()))
            {
                q.push({cur.first, cur.second - 1});
                vis.insert(to_string(cur.first) + "#" + to_string(cur.second - 1));
            }
        }
        else if((pro < r2) && (cur.first + 1 <= cur.second) && (cur.first + 1 < r) && (vis.find(to_string(cur.first + 1) + "#" + to_string(cur.second)) == vis.end()))
        {
            q.push({cur.first + 1, cur.second});
            vis.insert(to_string(cur.first + 1) + "#" + to_string(cur.second));
        }
        else if((cur.second - 1 > 0) && (cur.second - 1 >= cur.first) && (vis.find(to_string(cur.first) + "#" + to_string(cur.second - 1)) == vis.end()))
        {
            q.push({cur.first, cur.second - 1});
            vis.insert(to_string(cur.first) + "#" + to_string(cur.second - 1));
        }
    }

    for(auto iter = st.begin(); iter != st.end(); ++iter)
    {
        ret.push_back({iter->first, iter->second});
    }
    return ret;
}

int main()
{
    cout << "Method1" << endl;
    vector<pair<int, int> > result1 = drawCircle1(5);
    printResult();
    for(auto& r : result1)
    {
        cout << r.first << ", " << r.second << endl;
    }

    cout << "Method2" << endl;
    vector<pair<int, int> > result2 = drawCircle2(5);
    printResult();
    for(auto& r : result2)
    {
        cout << r.first << ", " << r.second << endl;
    }
    return 0;
}
