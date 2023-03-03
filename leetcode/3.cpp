#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
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

int main()
{
    Solution s;
    vector<int> a = s.getRow(2);

    for(int i=0; i<a.size();i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}