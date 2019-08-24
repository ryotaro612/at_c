#include<algorithm>
#include<string>
#include<iostream>
#include<list>
#include <boost/algorithm/string.hpp>
#include "ordinary_number.h"

using namespace std;

int ordinary_number(int n, std::string arg) {

    vector<string> strs;
    boost::split(strs, arg, boost::is_space());
    vector<int> nums(n);

    for(int i=0;i<n;i++)
        nums[i] = stoi(strs.at(i));

    int peek = 1;
    int count = 0;

    while(peek < n-1) {
        if(nums.at(peek-1) < nums.at(peek) && nums.at(peek) < nums.at(peek+1)) {
            count++;
        } else if (nums.at(peek+1) < nums.at(peek) && nums.at(peek) < nums.at(peek-1)) {
            count++;
        }
        peek++;
    }
    return count;
}