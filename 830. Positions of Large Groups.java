class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> groupList = new ArrayList<>();
        int beginIndex = 0;
        int endIndex = 0;
        int size = S.length();
        for (int i = 1; i < size; i++) {
            if (S.charAt(i) != S.charAt(i - 1)) {
                endIndex = i - 1;
                if (endIndex - beginIndex + 1 >= 3) {
                    List<Integer> group = new ArrayList<>();
                    group.add(beginIndex);
                    group.add(endIndex);
                    groupList.add(group);
                }
                beginIndex = i;
            }
        }
        endIndex = size - 1;
        if (S.charAt(beginIndex) == S.charAt(endIndex) && endIndex - beginIndex + 1 >= 3) {
            List<Integer> group = new ArrayList<>();
            group.add(beginIndex);
            group.add(endIndex);
            groupList.add(group);
        }
        return groupList;
    }
}

class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        List<List<Integer>> groupList = new ArrayList<>();
        int size = S.length();
        int beginIndex = 0;
        while (beginIndex < size - 1) {
            char keyLetter = S.charAt(beginIndex);
            int endIndex = beginIndex + 1;
            while (endIndex < size && S.charAt(endIndex) == keyLetter) {
                endIndex++;
            }
            if (endIndex - beginIndex >= 3) {
                groupList.add(new ArrayList<>(Arrays.asList(beginIndex, endIndex - 1)));
            }
            beginIndex = endIndex;
        }
        return groupList;
    }
}