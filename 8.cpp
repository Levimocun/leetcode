/*
1.忽略字符串前边的空格
2.开头有任意个正负号
3.包括除0-9之外的数字，如遇到则只取其前边的部分
4.开头除去空格之外的数字如果不是正负号或者数字那么返回0
5.溢出也返回0
*/

#include <iostream>
#include <vector>  
#include <string>
#include <algorithm>  
using namespace std;
class Solution {
private:
	string deletespace(string str);
	string deletesign(string str);
	string deleteother(string str); 
public:
    int myAtoi(string str);
};
int Solution::myAtoi(string str) {
	long long int ret;
	string result;
	//删除开头的空格
	result = deletespace(str);
	//检查是否有多余的正负号
	str = deletesign(result);
	//去掉非数字字符
	result = deleteother(str);
	ret = (str == "" ? 0 : atoll(str.c_str()));
	if(ret > INT_MAX)
		return INT_MAX;
	else if(ret < INT_MIN)
		return INT_MIN;
	else
		return ret;
}
string Solution::deletespace(string str){
	unsigned int i;
	for(i=0;i<str.size();i++){
		if(str[i] != ' ')
			break;
	}
	string ret(str,i);
	return ret;
}
string Solution::deletesign(string str){
	unsigned int i;
	for(i=0;i<str.size();i++){
		if(str[i] != '+' && str[i] != '-')
			break;
	}
	if(i==0 || i==1)
		return str;
	else
		return "";
}
string Solution::deleteother(string str){
	unsigned int i;
	for(i=0;i<str.size();i++){
		if(str[i] != '+' && str[i] != '-' && str[i] < '0' && str[i] > '9')
			break;
	}
	string ret (str,0,i);
	return ret;
}


int main(int argc, char** argv) {
	string input;
	cin >> input;
	Solution solution;
	cout << solution.myAtoi(input); 
	return 0;
}