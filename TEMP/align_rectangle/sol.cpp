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

vector<pair<int, double> > alignRectangle(vector<textBox>& boxes, int pageWidth)
{
    int curHorizontalEnd = 0, n = boxes.size(), cnt = 0, lastPos = 0;
    double cur_mid = 0.0, curVerticalStart = 0.0;
    bool new_line = true;
    vector<pair<int, double> > ret(n, {0, 0});
    vector<pair<int, double> > curLine(1, {pageWidth, 0});
    vector<pair<int, double> > lastLine;

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

        curVerticalStart = lastLine[lastPos].second;
        while(lastLine[lastPos].first < w + curHorizontalEnd)
        {
            curVerticalStart = max(curVerticalStart, lastLine[lastPos].second);
            ++lastPos;
        }

        double diff = curVerticalStart - (cur_mid - (static_cast<double> (h) / 2.0));
        if(diff > 0.0)
        {
            cur_mid += diff;
        }

        curHorizontalEnd += w;
        curLine.push_back({curHorizontalEnd, 0.0});

        if((i < n - 1 && curHorizontalEnd + boxes[i + 1].getWidth() > pageWidth) || i == n - 1)
        {
            cout << "cur_mid: " << cur_mid << endl;
            int k = i - curLine.size() + 1;
            int l = 0;
            for(auto& c : curLine)
            {
                double d = static_cast<double> (boxes[k].getHeight()) / 2.0;
                c.second = cur_mid + d;
                ret[cnt++] = {l, cur_mid - d};
                l += boxes[k++].getWidth();
            }
            // compare curLine to lastLine to fix the empty pos
            if(curHorizontalEnd < pageWidth)
            {
                if(lastLine[lastPos].first == curHorizontalEnd) ++lastPos;
                while(lastPos < lastLine.size())
                {
                    curLine.push_back(lastLine[lastPos++]);
                }
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
    vector<pair<int, double> > result = alignRectangle(inputBox, pageWidth);
    printResult();
    for(auto& r : result)
    {
        cout << r.first << ", " << r.second << endl;
    }
    return 0;
}
