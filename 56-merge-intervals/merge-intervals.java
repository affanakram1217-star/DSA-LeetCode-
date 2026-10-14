class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) {
            return new int[0][0];
        }

        // Sort by starting time: intervals[i][0]
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> merged = new ArrayList<>();
        merged.add(intervals[0]);

        for (int i = 1; i < intervals.length; i++) {
            int[] last = merged.get(merged.size() - 1);
            int currEnd = last[1];
            int nextStart = intervals[i][0];
            int nextEnd = intervals[i][1];

            if (currEnd >= nextStart) {
                last[1] = Math.max(currEnd, nextEnd);
            } else {
                merged.add(intervals[i]); // No overlap, add new interval
            }
        }

        return merged.toArray(new int[merged.size()][]);
    }
}