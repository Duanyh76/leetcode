class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if (Arrays.stream(candidates).sum() < target) {
            return new ArrayList<>();
        }
        List<List<Integer>> result = combination(candidates, target);
        return filter(result, candidates);
    }

    private List<List<Integer>> filter(List<List<Integer>> result, int[] candidates) {
        Map<Integer, Integer> cm = new HashMap<>();
        for (int c : candidates) {
            cm.put(c, (cm.get(c) == null ? 0 : cm.get(c)) + 1);
        }
        List<List<Integer>> r = new ArrayList<>();
        Set<Map<Integer, Integer>> record = new HashSet<>();
        for (List<Integer> list : result) {
            boolean b = false;
            Collections.sort(list);
            Map<Integer, Integer> map = new HashMap<>();
            for (Integer i : list) {
                map.put(i, (map.get(i) == null ? 0 : map.get(i)) + 1);
                if (map.get(i) > cm.get(i)) {
                    b = true;
                    break;
                }
            }
            if (b) {
                continue;
            }
            if (!record.contains(map)) {
                r.add(list);
                record.add(map);
            }
        }
        return r;
    }

    private List<List<Integer>> combination(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        for (int c : candidates) {
            if (target < c) {
                continue;
            }
            if (target == c) {
                List<Integer> list = new ArrayList<>();
                list.add(c);
                result.add(list);
                continue;
            }
            List<List<Integer>> temp = combination(candidates, target - c);
            for (List<Integer> list : temp) {
                list.add(c);
                result.add(list);
            }
        }
        return result;
    }

//    public static void main(String[] args) {
//        Solution solution = new Solution();
//        int[] candidates = {10, 1, 2, 7, 6, 1, 5};
//        List<List<Integer>> lists = solution.combinationSum2(candidates, 8);
//        System.out.println(lists);
//    }
}