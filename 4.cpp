#include <iostream>
#include <vector>  
#include <algorithm>  
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Solution {
private:
	int middle,p1,p2,count;
	bool two,cur;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        p1 = 0;
        p2 = 0;
        count = 0;
        middle = nums1.size()+nums2.size();
        two = middle%2 ? false : true;
		middle = ceil(middle/2.0);
		if(!nums1.size()){
			if(two)
				return (nums2[middle-1]+nums2[middle])/2.0;
			else
				return nums2[middle-1];
		}else if(!nums2.size()){
			if(two)
				return (nums1[middle-1]+nums1[middle])/2.0;
			else
				return nums1[middle-1];
		} 
		while(p1 != nums1.size() or p2 != nums2.size()){
		    if(middle == count){
		    	if(!two && !cur)
		    		return nums1[p1-1];
		    	else if(!two && cur)
		    		return nums2[p2-1];
		    	else if(two && !cur){
		    		if(nums1[p1] < nums2[p2])
		    			return (nums1[p1]+nums1[p1-1])/2.0;
		    		else
		    			return (nums1[p1-1]+nums2[p2])/2.0;
				}else{
					if(nums1[p1] < nums2[p2])
						return (nums1[p1]+nums2[p2-1])/2.0;
					else
						return (nums1[p2]+nums2[p2-1])/2.0;
				}
				break;	
			}
			if(nums1[p1] < nums2[p2]){
				p1++;
				cur = false;
			}
        	else{
        		p2++;
        		cur = true;
			}
        	count++;	
		}
    }
};

int main(int argc, char** argv) {
	vector<int> a={};
	vector<int> b={3,4};
	double ret;
	Solution solution;
	ret = solution.findMedianSortedArrays(b,a); 
	cout << ret;
	return 0;
}