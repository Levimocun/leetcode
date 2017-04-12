/*
Write a function to find the longest common prefix string amongst an array of strings.
找一组字符串的最长匹配
https://leetcode.com/problems/longest-common-prefix/?tab=Description#/description
这道题就是遍历呗，基本没啥技巧，我一开始忽略了没有字符串和只有1个字符串的情况，导致无限循环超时
*/

#include <iostream>
#include <vector>  
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
        int i,j;
        string ret;
        j = 0;
        if(strs.size() == 0)
        	return "";
        else if (strs.size() == 1)
        	return strs[0];
        while(true){
        	for(i=1;i<strs.size();i++){
        		if(strs[i][j] != strs[i-1][j] || j >=  strs[i].size())
        			return ret.assign(strs[i],0,j);
			}
			j++;
		}
    }
}