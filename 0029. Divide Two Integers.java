class Solution {
    public int divide(int dividend, int divisor) {
        long a = dividend;
        long b = divisor;
        int factor = 1;
        if(a < 0){
            factor = -factor;
            a = -a;
        }
        if(b < 0){
            factor = -factor;
            b = -b;
        }
        
        if(a < b){
            return 0;
        }
        
        long[] keyArray = new long[33];
        long[] numArray = new long[33];
        int index = 0;
        long key = 1;
        while(b <= a){
            index++;
            keyArray[index] = key;
            key += key;
            numArray[index] = b;
            b += b;
        }
        long result = 0;
        while(index != 0){
            if(a >= numArray[index]){
                result += keyArray[index];
                a -= numArray[index];
            }else{
                index--;
            }
        }
        if(factor == -1){
            result = -result;
        }
        if(result >= Integer.MAX_VALUE){
            return Integer.MAX_VALUE;
        }
        return (int)result;
    }
}