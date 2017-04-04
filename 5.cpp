#include <iostream>
#include <vector>  
#include <string>
#include <algorithm>  
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
private: 
	int i,j;
	unsigned int maxright=0,pos=0;
	vector<string> result;
	vector<int> len;
	void max_run(string s){
		len.push_back(1);
        maxright = 0;
        pos = 0;
		for(i=1;i<s.size();i++){
        	//在maxright的左边 
			if(i <= maxright){
				len.push_back(len[2*pos-i] < maxright-i ? len[2*pos-i] : maxright-i+1);
   			//在maxright的右边     		
			}else{
				len.push_back(1);
			}
			while((i+len[i] < s.size()) && (i-len[i] >=0) && s[i+len[i]] == s[i-len[i]])
				len[i]++;
			if(len[i] > len[pos]){ //更新 
				maxright = i+len[i]-1;
				pos = i;
			}
		}
	}
public:
    string longestPalindrome(string s) {
    	string s0;
		for(i=0;i<s.size();i++){
			s0 += '#';
			s0 += s[i];
		}
		s0 += "#";
        max_run(s0);
        s = "";
        for(i=(pos-len[pos]+1);i<(pos+len[pos]);i++){
        	if(s0[i] != '#')
        		s += s0[i];
		}
        return s;
    }
};

int main(int argc, char** argv) {
	string input;
	cin >> input;
	Solution solution;
	cout << solution.longestPalindrome(input); 
	return 0;
}