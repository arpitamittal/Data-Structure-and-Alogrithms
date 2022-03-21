class Solution {
public:
    int fib(int n) {
        return nFib(n);
    }
    int nFib(int num)
    {
        if(num == 0) return 0;
        if(num == 1) return 1;
        
        int a = nFib(num-1);
        int b = nFib(num-2);
        
        return a+b;
    }
};