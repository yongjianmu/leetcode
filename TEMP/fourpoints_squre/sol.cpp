#include "../../second/include/header.h"

bool canSquare(pair<double, double>& v1, pair<double, double>& v2, pair<double, double>& v3, pair<double, double>& v4)
{
    map<double, vector<pair<double, double> > > mp;
    double dis = pow((v2.first - v1.first), 2) + pow((v2.second - v1.second), 2);
    mp[dis].push_back(v2);
    dis = pow((v3.first - v1.first), 2) + pow((v3.second - v1.second), 2);
    mp[dis].push_back(v3);
    dis = pow((v4.first - v1.first), 2) + pow((v4.second - v1.second), 2);
    mp[dis].push_back(v4);

    if(mp.size() != 2) return false;
    auto iter1 = mp.begin();
    if(iter1->second.size() != 2) return false;
    auto iter2 = mp.begin();
    advance(iter2, 1);
    if(2.0 * iter1->first != iter2->first) return false;
    pair<double, double> cur = iter2->second[0];
    for(auto it = iter1->second.begin(); it != iter1->second.end(); ++it)
    {
        double d = pow((it->first - cur.first), 2) + pow((it->second - cur.second), 2);
        if(d != iter1->first) return false;
    }
    return true;
}

double distPtrs(pair<double, double> p, pair<double, double> q)
{
    return pow((p.first - q.first), 2) + pow((p.second - q.second), 2);
}

bool canSquare2(pair<double, double>& v1, pair<double, double>& v2, pair<double, double>& v3, pair<double, double>& v4)
{
    double d2 = distPtrs(v1, v2);  // from p1 to p2
    double d3 = distPtrs(v1, v3);  // from p1 to p3
    double d4 = distPtrs(v1, v4);  // from p1 to p4
 
    // If lengths if (p1, p2) and (p1, p3) are same, then
    // following conditions must met to form a square.
    // 1) Square of length of (p1, p4) is same as twice
    //    the square of (p1, p2)
    // 2) p4 is at same distance from p2 and p3
    if (d2 == d3 && 2.0*d2 == d4)
    {
        double d = distPtrs(v2, v4);
        return (d == distPtrs(v3, v4) && d == d2);
    }
 
    // The below two cases are similar to above case
    if (d3 == d4 && 2.0*d3 == d2)
    {
        int d = distPtrs(v2, v3);
        return (d == distPtrs(v2, v4) && d == d3);
    }
    if (d2 == d4 && 2.0*d2 == d3)
    {
        int d = distPtrs(v2, v3);
        return (d == distPtrs(v3, v4) && d == d2);
    }
 
    return false;
}

void split(string s, vector<string>& ret, char delim)
{
    stringstream ss(s);
    string str;
    while(getline(ss, str, delim))
    {
        ret.push_back(str);
    }
}

vector<pair<double, double> > getTwoPoints(pair<double, double>& v1, pair<double, double>& v2)
{
    //double dis = sqrt(pow((v2.first - v1.first), 2) + pow((v2.second - v1.second), 2));
    //double cosTheta = (v2.first - v1.first) / dis;
    //double sinTheta = (v2.second - v1.second) / dis;
    double mid_x = (v2.first + v1.first) / 2.0;
    double mid_y = (v2.second + v1.second) / 2.0;
    //double half_dis = dis / 2.0;
    //double up_x = mid_x - (half_dis * sinTheta);
    //double up_y = mid_y + (half_dis * cosTheta);
    //double dn_x = mid_x + (half_dis * sinTheta);
    //double dn_y = mid_y - (half_dis * cosTheta);
    double cosThetaV = (v2.first - v1.first) / 2.0;
    double sinThetaV = (v2.second - v1.second) / 2.0;
    double up_x = mid_x - (sinThetaV);
    double up_y = mid_y + (cosThetaV);
    double dn_x = mid_x + (sinThetaV);
    double dn_y = mid_y - (cosThetaV);
    
    vector<pair<double, double> > ret = {
        {up_x, up_y},
        {dn_x, dn_y}
    };
    return ret;
}

int numberofSquare(vector<pair<double, double> >& square)
{
    unordered_map<string, int> ump;
    int cnt = 0;
    int ret = 0;
    for(int i = 0; i < square.size(); ++i)
    {
        for(int j = i + 1; j < square.size(); ++j)
        {
            ump[to_string(square[i].first) + "," + to_string(square[i].second) + "#" + to_string(square[j].first) + "," + to_string(square[j].second)] = cnt++;
        }
    }

    for(auto iter = ump.begin(); iter != ump.end(); ++iter)
    {
        vector<string> str;
        split(iter->first, str, '#');
        vector<string> substr1;
        vector<string> substr2;
        split(str[0], substr1, ',');
        split(str[1], substr2, ',');
        pair<double, double> v1 = {stod(substr1[0]), stod(substr1[1])};
        pair<double, double> v2 = {stod(substr2[0]), stod(substr2[1])};
        vector<pair<double, double> > cur = getTwoPoints(v1, v2);
        auto it = ump.find(to_string(cur[0].first) + "," + to_string(cur[0].second) + "#" + to_string(cur[1].first) + "," + to_string(cur[1].second));
        if(it != ump.end() && it->second > iter->second) ++ret;
        it = ump.find(to_string(cur[1].first) + "," + to_string(cur[1].second) + "#" + to_string(cur[0].first) + "," + to_string(cur[0].second));
        if(it != ump.end() && it->second > iter->second) ++ret;
    }
    return ret;
}

int main()
{
    vector<pair<double, double> > input = {
        {1.0, 1.0},
        {1.0, 0.0},
        {0.0, 0.0},
        {0.0, 1.0},
        {2.0, 1.0},
        {8.0, 8.0},
        {8.0, 7.0},
        {7.0, 7.0},
        {7.0, 8.0}
    };
    bool ret = canSquare(input[0], input[1], input[2], input[3]);
    printResult();
    cout << ret << endl;

    ret = canSquare2(input[0], input[1], input[2], input[3]);
    printResult();
    cout << ret << endl;

    int result = numberofSquare(input);
    printResult();
    cout << result << endl;

    return 0;
}
