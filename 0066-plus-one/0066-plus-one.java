class Solution {
    public int[] plusOne(int[] digits) {

        int n = digits.length;

        // Traverse from last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
            // if digit is 9, make it 0
            digits[i] = 0;
        }

        // if all digits were 9 → create new array
        int[] result = new int[n + 1];
        result[0] = 1;

        return result;
    }
}