/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

//这是多开，双数组，一个用来保存，一个用来计算，和他妈的双指针一样
//这里要提前开一个1，并且从1开始

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret { 1 }, cur { 1 };

        for (int i = 1; i <= rowIndex; i++) 
        {
            ret.push_back(1);

            for (int j = 1; j < i; j++) 
            {
                ret[j] = cur[j] + cur[j - 1];
            }
            cur = ret;
        }
	return ret;
    }
};
// @lc code=end

