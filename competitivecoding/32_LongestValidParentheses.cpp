#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        st.push(-1);
        int maxl = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    int len = i - st.top();
                    maxl = std::max(maxl, len);
                }
            }
        }
        return maxl;
    }
};

int main() {
    Solution solution;
    
    // Test cases
    std::string input1 = "(()";
    std::cout <<  input1 << "\": " << solution.longestValidParentheses(input1) << std::endl;
    
    std::string input2 = ")()())";
    std::cout << input2 << "\": " << solution.longestValidParentheses(input2) << std::endl;
    
    std::string input3 = "";
    std::cout <<  input3 << "\": " << solution.longestValidParentheses(input3) << std::endl;
    
    std::string input4 = "(()())";
    std::cout << input4 << "\": " << solution.longestValidParentheses(input4) << std::endl;

    return 0;
}
