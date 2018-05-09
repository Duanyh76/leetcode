class Solution {
    public List<String> readBinaryWatch(int num) {
        List<String> times = new ArrayList<>();
        for (int numHourLight = 0; numHourLight <= Math.min(3, num); numHourLight++) {
            int numMinuteLight = num - numHourLight;
            List<Integer> hours = getTimeList(numHourLight, 8, 11);
            List<Integer> minutes = getTimeList(numMinuteLight, 32, 59);
            for (Integer hour : hours) {
                for (Integer minute : minutes) {
                    String minuteString = minute.toString();
                    if (minute <= 9) {
                        minuteString = "0" + minute.toString();
                    }
                    String time = hour.toString() + ":" + minuteString;
                    times.add(time);
                }
            }
        }
        return times;
    }

    private List<Integer> getTimeList(int numLight, int maxTime, int limit) {
        List<Integer> timeList = new ArrayList<>();
        if (numLight == 0) {
            timeList.add(0);
            return timeList;
        }

        List<Set<Integer>> indexGroup = new ArrayList<>();

        for (int light = 1; light <= numLight; light++) {
            int indexGroupSize = indexGroup.size();
            if (indexGroupSize != 0) {
                for (int i = 0; i < indexGroupSize; i++) {
                    Set<Integer> timeSet = indexGroup.get(i);
                    for (int smallTime = 1; smallTime <= maxTime; smallTime *= 2) {
                        if (!timeSet.contains(smallTime)) {
                            Set<Integer> newTimeSet = new HashSet(timeSet);
                            newTimeSet.add(smallTime);
                            if (!indexGroup.contains(newTimeSet)) {
                                indexGroup.add(newTimeSet);
                            }
                        }
                    }
                }
            } else {
                for (int smallTime = 1; smallTime <= maxTime; smallTime *= 2) {
                    Set<Integer> timeSet = new HashSet<>();
                    timeSet.add(smallTime);
                    indexGroup.add(timeSet);
                }
            }

        }

        for (Set<Integer> index : indexGroup) {
            if (index.size() != numLight) {
                continue;
            }
            int time = 0;
            for (Integer smallTime : index) {
                time += smallTime;
            }
            if (time <= limit) {
                timeList.add(time);
            }
        }
        return timeList;
    }
}

class Solution {
    public List<String> readBinaryWatch(int num) {
       List<String> times = new ArrayList<>();
       for (int hour = 0; hour < 12; hour++) {
           for (int minute = 0; minute < 60; minute++) {
               if (Integer.bitCount(hour * 64 + minute) == num) {
                   times.add(String.format("%d:%02d", hour, minute));
               }
           }
       }
       return times;
   }
}