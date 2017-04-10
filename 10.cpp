/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

1.һ�Ű壬ÿ�����1����ȡ������֮������������
2.������֮����Ժ������м�����������İ�
3.���ǰ�������Ϊ��塢�Ұ壬���ڿ�������������������߶�Ϊh���ұ��Ұ�ͣ������֮��ľ���Ϊw�����ʱ�����װˮw*h��
��ʱ���ǳ����ƶ����塣�������������ƣ���ô�п���ʹ�ݻ�������磬����ұߵİ��Ӹ�h1�����Ǳ��Ұ�ͣ�����ʱ���װˮ
(w-1)*h1���п��ܱ�w*h��������Ұ������ƣ�����ˮ�ĸ߶Ȳ��ܸ�����壬�����ݻ����Ϊ(w-1)*h���϶���w*hС����������ļ�
�裬����ֻҪ����������������м俿£���Ϳ�����������ݻ���
https://leetcode.com/problems/container-with-most-water/?tab=Description#/description
*/
#include <iostream>
#include <vector>  
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int low,high,max=0,temp;
        low = 0;
        high = height.size() - 1;
		while(low < high){
			temp = (high-low)*min(height[low],height[high]);
			max = max > temp ? max : temp;
			if(height[low] < height[high])
				low++;
			else
				high--;
		}
		return max;
    }
};