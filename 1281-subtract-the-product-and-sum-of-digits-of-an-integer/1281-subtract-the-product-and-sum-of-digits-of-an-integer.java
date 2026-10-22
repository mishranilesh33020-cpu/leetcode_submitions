class Solution {
    public int subtractProductAndSum(int n) {
      int prod=1;
      int sum=0;
      int diff, digit;
      while(n>0){
        digit = n%10;
        prod = prod * digit;
        sum = sum + digit;
        n /= 10;
      }
      diff = prod - sum;
      return diff;
    }
}