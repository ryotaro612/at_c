#include<string>
#include "divide_the_problem.h"
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm.hpp>

using namespace std;

int solve_divide_the_problem(int n, std::string elms) {

    vector<string> strs;
    boost::split(strs, elms, boost::is_space());
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        nums[i] = stoi(strs.at(i));

    boost::sort(nums);

    int mid = (n/2) -1;

    if(nums.at(mid) == nums.at(mid+1)) {
        return 0;
    }

    return nums.at(mid+1) - nums.at(mid);

}