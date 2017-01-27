#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <climits>
using namespace std;

void split(string s, vector<string>& ret, char delim){
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, delim)){
        ret.push_back(temp);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string str;
    int cnt = -1;
    int len = 0;
    vector<long long> output;
    long long ret = LONG_MIN;
    while(getline(cin, str)){
        vector<string> cur;
        split(str, cur, ' ');
        if(-1 == cnt){
            len = stoi(cur[0]);
            output.resize(len, 0);
        }
        else{
            output[stoi(cur[1]) - 1] += stoi(cur[2]);
            ret = max(ret, output[stoi(cur[1]) - 1]);
            if((stoi(cur[0]) > 1)) output[stoi(cur[0]) - 2] -= stoi(cur[2]);
        }
        ++cnt;
    }
    
    for(int i = len - 2; i >= 0; --i){
        output[i] += output[i + 1];
        ret = max(ret, output[i]);    
    }
    cout << ret << endl; 
    return 0;
}
