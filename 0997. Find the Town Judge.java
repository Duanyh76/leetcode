class Solution {
    public int findJudge(int N, int[][] trust) {
        if (trust.length < 1 && N == 1) {
            return 1;
        }
        Map<Integer, Integer> judge = new HashMap<>();
        Set<Integer> normal = new HashSet<>();
        for (int[] trustPair : trust) {
            int a = trustPair[0];
            int b = trustPair[1];
            if (judge.containsKey(a)) {
                judge.remove(a);
            }
            normal.add(a);
            if (!normal.contains(b)) {
                Integer count = judge.get(b) == null ? 0 : judge.get(b);
                judge.put(b, ++count);
            }
        }
        if (judge.size() != 1) {
            return -1;
        }
        for (Map.Entry<Integer, Integer> person : judge.entrySet()) {
            if (person.getValue() == N - 1) {
                return person.getKey();
            } else {
                return -1;
            }
        }
        return -1;
    }
}

class Solution {
    public int findJudge(int N, int[][] trust) {
        int[] count=new int[N+1];
        for(int[] t:trust){
            count[t[0]]--;
            count[t[1]]++;
        }
        for(int i=1;i<=N;i++){
            if(count[i]==N-1){
                return i;
            }
        }
        return -1;
    }
}