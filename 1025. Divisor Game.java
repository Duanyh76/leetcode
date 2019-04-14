class Solution {
    public boolean divisorGame(int N) {
        boolean[] gameCondition = new boolean[1001];
        gameCondition[1] = false;
        for (int condition = 2; condition <= 1000; condition++) {
            List<Integer> factorList = getFactorList(condition);
            gameCondition[condition] = false;
            for (Integer factor : factorList) {
                if (gameCondition[condition - factor] == false) {
                    gameCondition[condition] = true;
                    break;
                }
            }
        }
        return gameCondition[N];
    }

    private List<Integer> getFactorList(int condition) {
        int sqrt = (int)Math.sqrt(condition);
        List<Integer> factorList=new ArrayList<>();
        for(int factor=1;factor<=sqrt;factor++){
            if(condition%factor==0){
                factorList.add(factor);
            }
        }
        return factorList;
    }
}