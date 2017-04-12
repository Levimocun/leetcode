/*
Integer to Roman 阿拉伯数字转换为罗马数字
   1    2     3     4    5    6    7      8      9
   I   II    III   IV    V   VI    VII   VIII    IX
10 11  12    13    14   15   16    17     18     19
X  XI  XII  XIII  XIV   XV   XVI  XVII   XVIII   XIX
20  30    40   50   60    70    80     90   100    110
XX  XXX   XL    L   LX    LXX   LXXX   XC    C      CX
(1)阿拉伯数字转换为罗马数字思路：
将1-9，10，20，30，40，50，60，70，80，90，100，200，300，400，500，600，700，800，900，1000列出来，
每个数字将其转化为a*1000+b*100+c*10+d,然后将a,b,c,d按照表转化，这样拼接起来就是罗马数字。 
(2)罗马数字转换为阿拉伯数字思路：
从左到右依次读取罗马数字，如果其比前一个数字小，则加上，反之加上并且减去前一个数字的二倍
https://leetcode.com/problems/roman-to-integer/?tab=Description#/description 
*/ 
#include <iostream>
#include <vector>  
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
    	vector<string> I = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    	vector<string> X = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    	vector<string> D = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    	vector<string> M = {"","M","MM","MMM"};
    	return M[num/1000]+D[(num%1000)/100]+X[(num%100)/10]+I[num%10];
    }
   int romanToInt(string roman){
    	map<char,int> dict;
    	int prenum=0,total=0,i;
		dict.insert(pair <char,int> ('I',1));
    	dict.insert(pair <char,int> ('V',5));
    	dict.insert(pair <char,int> ('X',10));
    	dict.insert(pair <char,int> ('L',50));
    	dict.insert(pair <char,int> ('C',100));
    	dict.insert(pair <char,int> ('D',500));
    	dict.insert(pair <char,int> ('M',1000));
    	total = dict[roman[0]];
    	prenum = total;
		for(i=1;i<roman.size();i++){
			if(prenum < dict[roman[i]])
				total = total+dict[roman[i]]-2*prenum;
			else
				total = total+dict[roman[i]];
			prenum = dict[roman[i]];
		}
		return total;
	}
};