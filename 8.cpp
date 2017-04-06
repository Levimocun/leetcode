/*
1.�����ַ���ǰ�ߵĿո�
2.��ͷ�������������
3.������0-9֮������֣���������ֻȡ��ǰ�ߵĲ���
4.��ͷ��ȥ�ո�֮�������������������Ż���������ô����0
5.���Ҳ����0
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
	//ɾ����ͷ�Ŀո�
	result = deletespace(str);
	//����Ƿ��ж����������
	str = deletesign(result);
	//ȥ���������ַ�
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