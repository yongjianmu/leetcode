#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class compare_1 { // simple comparison function
   public:
      bool operator()(const int x,const int y) { return (x-y)>0; } // returns x>y
};


int main()
{
   vector<int> v;	
			
   sort(v.begin(), v.end(), compare_1()); // ok
	
   map<int,int,compare_1> mymap1; // ok
	
   return 0;
}
