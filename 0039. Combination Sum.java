class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> result = combination(candidates, target);
        return filter(result);
    }

    private List<List<Integer>> filter(List<List<Integer>> result) {
        List<List<Integer>> r = new ArrayList<>();
        Set<Map<Integer, Integer>> record = new HashSet<>();
        for (List<Integer> list : result) {
            Collections.sort(list);
            Map<Integer, Integer> map = new HashMap<>();
            for (Integer i : list) {
                map.put(i, (map.get(i) == null ? 0 : map.get(i)) + 1);
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
//
//    public static void main(String[] args) {
//        Solution solution = new Solution();
//        int[] candidates = {2, 3, 6, 7};
//        List<List<Integer>> lists = solution.combinationSum(candidates, 7);
//        System.out.println(lists);
//    }
}