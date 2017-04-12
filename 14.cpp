/*
Write a function to find the longest common prefix string amongst an array of strings.
��һ���ַ������ƥ��
https://leetcode.com/problems/longest-common-prefix/?tab=Description#/description
�������Ǳ����£�����ûɶ���ɣ���һ��ʼ������û���ַ�����ֻ��1���ַ������������������ѭ����ʱ
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