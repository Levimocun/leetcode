/*
Given a string, find the length of the longest substring without repeating characters.
Examples:
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <vector>  
#include <algorithm>  
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
private:
	int maxlen=0,i,start=-1;
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256,-1);
		for(i=0;i<s.length();i++){
        	if(dict[s[i]] > start)//字符重复出现 
        		start = dict[s[i]];//记录上次出现位置 
        	dict[s[i]] = i;//修正字符最新出现位置 
			maxlen = max(maxlen,i-start);//将之前的最大值和重复字符之间的距离进行比较，选择最大的	
		}
		return maxlen;
    }
};

int main(int argc, char** argv) {
	Solution solution;
	int ret;
	string a = "aaaa";
	ret = solution.lengthOfLongestSubstring(a);
	cout << ret;
	return 0;
}