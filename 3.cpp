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
        	if(dict[s[i]] > start)//�ַ��ظ����� 
        		start = dict[s[i]];//��¼�ϴγ���λ�� 
        	dict[s[i]] = i;//�����ַ����³���λ�� 
			maxlen = max(maxlen,i-start);//��֮ǰ�����ֵ���ظ��ַ�֮��ľ�����бȽϣ�ѡ������	
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