
double myPow(double x, int n) {
    // if(n==1) return x;

    // int half_n = n/2;
    // double half_l = myPow(x,half_n-1);
    // double half_r = myPow(x,half_n+1);

    // return half_l * half_r;
    if(n==0) return 1.0;
    else if(n>0){
        return x*myPow(x,n-1);
    }else return 1/myPow(x,-n);
}

// double myPow(double x, int n) {
//     // Case 1: Base case when n is 0
//     if (n == 0) return 1.0;
    
//     if (n > 0) {
//         return x * myPow(x, n - 1);
//     } 
    
//     else {
//         return 1.0 / myPow(x, -n);
//     }
// }
