int climbStairs_help(int n, int* arr){
    if(arr[n]!=-1)return arr[n];
    else{
        arr[n] = climbStairs_help(n-1,arr) + climbStairs_help(n-2,arr);
    }
    return arr[n];
}
int climbStairs(int n) {
    //Write your code
    int arr[n+1];
    for(int i=0;i++;i<n+1){
        arr[i] = -1;
    }
    arr[1]=1;
    arr[2]=2;
    
    if(arr[n]!=-1) return arr[n];
    
    return climbStairs_help(n,arr);
}
