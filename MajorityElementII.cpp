#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int t1,t2,n1=0,n2=0;  //numbers t1 and t2,votes' numbers n1,and n2.
        for(int i=0;i<nums.size();++i)
        {
            if(n1!=0&&t1==nums[i]){++n1;continue;}
            if(n2!=0&&t2==nums[i]){++n2;continue;}
            if(n1==0){ t1=nums[i];++n1;continue;}
            if(n2==0){ t2=nums[i];++n2;continue;}
            --n1;--n2;
        }
        int z1=0,z2=0;
        for(int i=0;i<nums.size();++i)
        {
            if(n1>0){ if(nums[i]==t1) ++z1;}
            if(n2>0) {if(nums[i]==t2) ++z2;}
        }
        vector<int> ret;
         //check t1 and t2.
        if(z1>nums.size()/3) ret.push_back(t1);
        if(z2>nums.size()/3) ret.push_back(t2);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution solution;
	return 0;
}