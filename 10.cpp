/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

1.一排板，每排相隔1，求取两个板之间面积最大的情况
2.两个板之间可以忽略其中间相隔的其他的板
3.我们把两块板分为左板、右板，现在考虑如下情况。假设左板高度为h，且比右板低，两块板之间的距离为w，则此时最多能装水w*h，
此时我们尝试移动隔板。如果将左板向右移，那么有可能使容积变大，例如，左板右边的板子高h1（还是比右板低），此时最多装水
(w-1)*h1，有可能比w*h大；如果将右板向左移，由于水的高度不能高于左板，所以容积最多为(w-1)*h，肯定比w*h小。基于上面的假
设，我们只要把两块隔板依次向中间靠拢，就可以求出最大的容积。
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