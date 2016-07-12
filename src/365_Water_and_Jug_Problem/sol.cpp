#include "../include/header.h"

/*
题目可以表示为如下等式:
•mx + ny = z
•若m, n>0说明往里面加水，若m, n <0则说明清空

如x = 3，y = 5 可以有  3 x + (-1)y = 4 即 m = 3, n = -1 ，也就是说我们需要往3这个杯子装满3次，5这个杯子倒掉1次
•首先往3的杯子注满水，然后倒入倒入5    杯子情况为： 0，3
•接着把3的杯子注满水，在倒入5 ，杯子情况为  1，5
•接着把5的杯子倒掉， 把3的杯子装入5， 这样为 0，1
•接着把3的杯子注满水，倒入5， 这样0，4

可以参考  ： http ://www.math.tamu.edu/~dallen/hollywood/diehard/diehard.htm

本题中，若mx + ny = z 有解，则一定有z为GCD(x, y) 的整数倍，否则无解。

且需要满足条件 x + y >= z
*/

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return x + y == z || (x + y > z) && z % gcd(x, y) == 0;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }
};

