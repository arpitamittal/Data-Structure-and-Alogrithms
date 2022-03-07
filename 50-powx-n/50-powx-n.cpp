class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) return myPow(1/x, abs(n));
        if(x == 1) return 1;
        if(n == 0) return 1;
        
        double value = myPow(x, n/2);
        
        if(n % 2 == 0) return value * value;
        else return x * value * value;

    }
};