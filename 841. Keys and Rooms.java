class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        List<Integer> keys = new ArrayList<>();
        keys.add(0);
        int index = 0;
        while (index < keys.size()) {
            int key = keys.get(index);
            for (int i = 0; i < rooms.get(key).size(); i++) {
                if (!keys.contains(rooms.get(key).get(i))) {
                    keys.add(rooms.get(key).get(i));
                }
            }
            index++;
        }
        return keys.size() == rooms.size();
    }
}