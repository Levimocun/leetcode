/*
Integer to Roman ����������ת��Ϊ��������
   1    2     3     4    5    6    7      8      9
   I   II    III   IV    V   VI    VII   VIII    IX
10 11  12    13    14   15   16    17     18     19
X  XI  XII  XIII  XIV   XV   XVI  XVII   XVIII   XIX
20  30    40   50   60    70    80     90   100    110
XX  XXX   XL    L   LX    LXX   LXXX   XC    C      CX
(1)����������ת��Ϊ��������˼·��
��1-9��10��20��30��40��50��60��70��80��90��100��200��300��400��500��600��700��800��900��1000�г�����
ÿ�����ֽ���ת��Ϊa*1000+b*100+c*10+d,Ȼ��a,b,c,d���ձ�ת��������ƴ�����������������֡� 
(2)��������ת��Ϊ����������˼·��
���������ζ�ȡ�������֣�������ǰһ������С������ϣ���֮���ϲ��Ҽ�ȥǰһ�����ֵĶ���
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