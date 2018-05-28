class Solution {
    public int[][] reconstructQueue(int[][] people) {
        List<Integer> heightList = new ArrayList<>();
        for (int i = 0; i < people.length; i++) {
            int height = people[i][0];
            if (!heightList.contains(height)) {
                heightList.add(height);
            }
        }
        heightList.sort(null);
        List<int[]> waittingList = new ArrayList<>();
        for (int i = heightList.size() - 1; i >= 0; i--) {
            int height = heightList.get(i);
            List<Integer> numberList = new ArrayList<>();
            for (int j = 0; j < people.length; j++) {
                if (people[j][0] == height) {
                    numberList.add(people[j][1]);
                }
            }
            numberList.sort(null);
            int index = 0;
            int count = 0;
            for (int j = 0; j < numberList.size(); j++) {
                int[] person = new int[2];
                person[0] = height;
                person[1] = numberList.get(j);
                if (waittingList.isEmpty()) {
                    waittingList.add(person);
                } else {
                    index += person[1] - count;
                    count = person[1];
                    waittingList.add(index, person);
                }
            }
        }
        int[][] queue = new int[people.length][2];
        for (int i = 0; i < queue.length; i++) {
            queue[i][0] = waittingList.get(i)[0];
            queue[i][1] = waittingList.get(i)[1];
        }
        return queue;
    }

}

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] != o2[0] ? Integer.compare(o2[0], o1[0]) : Integer.compare(o1[1], o2[1]);
            }
        });
        List<int[]> list = new LinkedList<>();
        for (int[] person : people) {
            list.add(person[1], person);
        }
        return (int[][]) list.toArray(new int[people.length][]);
    }
}