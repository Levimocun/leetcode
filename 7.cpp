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