#include "../../second/include/header.h"

vector<pair<int, int> > drawCircle1(int r)
{
    set<pair<int, int> > st;
    vector<pair<int, int> > ret;
    int x = 1;
    while(x <= r)
    {
        for(int y = 0; y <= x; ++y)
        {
            if(x * x + y * y == r * r)
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
    vector<pair<int, int> > ret;
    queue<pair<int, int> > q;
    int x = 0, y = r;
    q.push({x, y});
    st.insert({x, y});
    while(!q.empty())
    {
        pair<int, int> cur = q.front(); q.pop();
        
    }
}

int main()
{
    vector<pair<int, int> > result = drawCircle1(5);
    printResult();
    for(auto& r : result)
    {
        cout << r.first << ", " << r.second << endl;
    }
    return 0;
}
