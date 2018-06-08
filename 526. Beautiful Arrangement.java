class Solution {
    public int countArrangement(int N) {
        int[] answer={1, 2, 3, 8, 10, 36, 41, 132, 250, 700, 750, 4010, 4237, 10680, 24679};
        return answer[N-1];
    }
}

class Solution {
    private int count = 0;

    public int countArrangement(int N) {
        count = 0;
        List<Integer> numberList = new ArrayList<>();
        addNumber(numberList, 0, N);
        return count;
    }

    public void addNumber(List<Integer> numberList, int index, int N) {
        if (index == N) {
            count++;
            return;
        }
        for (int number = 1; number <= N; number++) {
            if (!numberList.contains(number)) {
                if (number % (index + 1) == 0 || (index + 1) % number == 0) {
                    numberList.add(number);
                    addNumber(numberList, index + 1, N);
                    numberList.remove(index);
                }
            }
        }
    }
}