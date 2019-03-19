#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void keylogger(stack<char>& result, const string& str) {
    stack<char> temp;
    for (int i = 0; i < str.size(); i++) {
        if(str[i] == '<') {
            if (!result.empty()) {
                temp.push(result.top());
                result.pop();
            }
        } else if (str[i] == '>') {
            if (!temp.empty()) {
                result.push(temp.top());
                temp.pop();
            }
        } else if (str[i] == '-') {
            if (!result.empty())
                result.pop();
        } else {
            result.push(str[i]);
        }
    }
    while (temp.size() != 0) {
        result.push(temp.top());
        temp.pop();
    }
}

int main (void) {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        string str, answer;
        cin >> str;
        stack<char> result;
        keylogger(result, str);
        while (result.size() != 0) {
            answer += result.top();
            result.pop();
        }
        reverse(answer.begin(), answer.end());
        cout << answer << "\n";
    }
    return 0;
}
