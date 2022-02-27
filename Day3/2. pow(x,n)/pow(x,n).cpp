class Solution {
public:
    double bigpow(double x, int y){
        double res=1;
        while(y>0){
            if(y&1){
                res = res*x;
            }
            x = x*x;
            y=y>>1;
            
        }
        if(y<0){
            y=abs(y);
            while(y>0){
            if(y&1){
                res = res*x;
            }
            x = x*x;
            y=y>>1;
            
            }
            return 1/res;
        }
        return res;
    }
    double myPow(double x, int n) {
        return bigpow(x,n);
    }
};