#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> answer;
        answer.reserve(2);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                    return answer;
                }
            }
        }
        return answer;
    }
};

int main()
{


	return 0;
}