class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fiveDollar = 0;
        int tenDollar = 0;
        for (int bill : bills) {
            if (bill == 5) {
                fiveDollar++;
            } else if (bill == 10) {
                if (fiveDollar == 0) {
                    return false;
                }
                fiveDollar--;
                tenDollar++;
            } else {
                if (fiveDollar == 0) {
                    return false;
                }
                fiveDollar--;
                if (tenDollar == 0) {
                    if (fiveDollar <= 2) {
                        return false;
                    } else {
                        fiveDollar -= 2;
                    }
                } else {
                    tenDollar--;
                }
            }
        }
        return true;
    }
}