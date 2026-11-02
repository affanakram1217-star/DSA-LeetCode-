class Solution {
    public int partition(int low, int high, int[] nums) {
        int idx = low - 1;
        int pivot = nums[high];
        for (int i = low; i < high; i++) {
            if (nums[i] <= pivot) {
                idx++;
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
            }
        }
        idx++;
        int temp = nums[idx];
        nums[idx] = nums[high];
        nums[high] = temp;
        return idx;
    }

    public int quickselect(int low, int high, int[] nums, int k) {
        if (low <= high) {
            int pivIdx = partition(low, high, nums);
            if (pivIdx == k) {
                return nums[pivIdx];
            } else if (pivIdx > k) {
                return quickselect(low, pivIdx - 1, nums, k);
            } else {
                return quickselect(pivIdx + 1, high, nums, k);
            }
        }
        return -1;
    }

    public int minMoves2(int[] nums) {
        int n = nums.length;
        int median = quickselect(0, n - 1, nums, n / 2);
        int moves = 0;
        for (int num : nums) {
            moves += Math.abs(num - median);
        }
        return moves;
    }
}