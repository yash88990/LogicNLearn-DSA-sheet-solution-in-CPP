class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        
        while (s.length() > 1) {
            if (s.back() == '0') {
                // If the number is even, divide by 2 (remove the last character)
                s.pop_back();
            } else {
                // If the number is odd, add 1
                // Start from the end and handle the carry
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    // If all characters are '1', we need to add an additional '1' at the start
                    s = '1' + s;
                }
            }
            steps++;
        }
        
        return steps;
    }
};