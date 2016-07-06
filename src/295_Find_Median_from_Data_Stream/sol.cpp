#include "../include/header.h"

/*
add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
*/

class MedianFinder {
	priority_queue<int> small, large;
public:
	// Adds a number into the data structure.
	void addNum(int num) {
		if (!large.empty() && -large.top() < num)
			large.push(-num);
		else
			small.push(num);

		if (small.size() - large.size() == 2) {
			large.push(-small.top());
			small.pop();
		}
		else if (small.size() - large.size() == -2) {
			small.push(-large.top());
			large.pop();
		}
	}

	// Returns the median of current data stream
	double findMedian() {
		if (small.size() > large.size()) return small.top();
		else if (small.size() < large.size()) return -large.top();
		return (small.top() - large.top()) / 2.0;
	}
};


// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main()
{
    MedianFinder mf;
    mf.addNum(5);
    mf.addNum(5);
    mf.addNum(6);
    cout << mf.findMedian() << endl;
    return 0;
}
