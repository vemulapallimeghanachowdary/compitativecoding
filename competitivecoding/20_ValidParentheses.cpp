#include <iostream>
#include <stack>
#include <string>
using namespace std;

class vp {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                } else {
                    if ((st.top() == '{' && s[i] == '}') || 
                        (st.top() == '[' && s[i] == ']') || 
                        (st.top() == '(' && s[i] == ')')) {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        return st.empty();
    }
};

int main() {
    string expression;
    cin >> expression;

    vp validator; // Create an instance of the vp class
    if (validator.isValid(expression)) {
        cout << "Valid expression" << endl;
    } else {
        cout << "Invalid expression" << endl;
    }

    return 0;
}
