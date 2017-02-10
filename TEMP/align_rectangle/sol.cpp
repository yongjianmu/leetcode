#include "../../second/include/header.h"

class textBox
{
public:
    textBox(int w, int h) : mWidth(w), mHeight(h) {}
    int getWidth() {return mWidth;}
    int getHeight() {return mHeight;}
private:
    int mWidth;
    int mHeight;
};

vector<pair<int, int> > alignRectangle(vector<textBox>& boxes, int pageWidth)
{
    int curVerticalStart = 0, curHorizontalEnd = 0, n = boxes.size(), cnt = 0, cur_mid = 0, lastPos = 0;
    bool new_line = true;
    vector<pair<int, int> > ret(n, {0, 0});
    vector<pair<int, int> > lastLine(1, {pageWidth, 0});
    vector<pair<int, int> > curLine;

    for(int i = 0; i < n; ++i)
    {
        int w = boxes[i].getWidth();
        int h = boxes[i].getHeight();
        if(new_line)
        {
            new_line = false;
            lastPos = 0;
            if(w > pageWidth) return ret;
            lastLine.swap(curLine);
            curLine.clear();
            curHorizontalEnd = 0;
        }

        while(lastLine[lastPos].first < w + curHorizontalEnd)
        {
            curVerticalStart = max(curVerticalStart, lastLine[lastPos].second);
            ++lastPos;
        }

        int diff = curVerticalStart - (cur_mid - (h >> 1));
        if(diff > 0)
        {
            curVerticalStart += diff;
            cur_mid += diff;
        }

        curHorizontalEnd += w;
        curLine.push_back({curHorizontalEnd, 0});

        if(i < n - 1 && curHorizontalEnd + boxes[i + 1].getWidth() > pageWidth)
        {
            int k = i - curLine.size() + 1;
            int l = 0;
            for(auto& c : curLine)
            {
                int d = boxes[k++].getHeight() >> 1;
                c.second = cur_mid + d;
                ret[cnt++] = {l, cur_mid - d};
            }
            // compare curLine to lastLine to fix the empty pos
            while(lastPos < lastLine.size())
            {
            }
            new_line = true;
        }
    }
    return ret;
}

int main()
{
    vector<pair<int, int> > input = {
        {2,2},
        {2,3},
        {3,2},
        {1,4},
        {5,2},
        {1,1}
    };
    vector<textBox> inputBox;
    for(auto& i : input)
    {
        inputBox.push_back(textBox(i.first, i.second));
    }

    int pageWidth = 7;
    vector<pair<int, int> > result = alignRectangle(inputBox, pageWidth);
    printResult();
    for(auto& r : result)
    {
        cout << r.first << ", " << r.second << endl;
    }
    return 0;
}
