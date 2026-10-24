class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0) {
           return false; 
        }
        else if(0<x&&x<10){
            return true;
        }
        else{
            int original =x;
            int LastD;
            long revNum =0;
            while(x>0){
                LastD = x%10;
                revNum= revNum*10+LastD;
                x/=10;
            }
            return revNum==original;
            return true;
            
        }


        
    }
};