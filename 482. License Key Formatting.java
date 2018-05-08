class Solution {
    public String licenseKeyFormatting(String S, int K) {
        S = S.toUpperCase();
        StringBuilder tempStr = new StringBuilder();
        for (String s : S.split("-")) {
            tempStr.append(s);
        }
        if(tempStr.length()==0){
            return "";
        }
        int size = tempStr.length();
        int firstSize = size % K == 0 ? K : size % K;

        StringBuilder license = new StringBuilder(tempStr.substring(0, firstSize));
        for (int index = firstSize; index < size; index += K) {
            license.append("-");
            license.append(tempStr.substring(index, index + K));
        }
        return license.toString();
    }
}