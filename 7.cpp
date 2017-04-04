/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        int temp,i;
        long long int result=0;
		temp = x;
		while(temp){
			result = result*10 + (temp%10);
			temp /= 10;
		}
		cout << result << endl;
		return (result > INT_MAX || result < INT_MIN) ? 0 : result;
    }
};

int main(int argc, char** argv) {
	int input;
	cin >> input;
	Solution solution;
	cout << solution.reverse(input); 
	return 0;
}