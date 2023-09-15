#include "leetcode-definition.h"
/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start

class State {
  public:
    char c;
    bool isStar;
    State(char c, bool isStar) : c(c), isStar(isStar) {}
    bool match(char ch) const { return c == '.' || c == ch; }
};

class Solution {
  public:
    vector<State> states;
    bool search(const string& s, const string& p, int strIndex, int stateIndex) {
        if (strIndex == s.size() && stateIndex == states.size()) {
            return true;
        }
        if (strIndex == s.size() && stateIndex != states.size()) {
            return false;
        }
        if (strIndex != s.size() && stateIndex == states.size()) {
            return false;
        }
        State& state = states[stateIndex];
        char c = s[strIndex];
        if (state.isStar) {
            if (state.match(c)) {
                // loop
                if (search(s, p, strIndex + 1, stateIndex)) {
                    return true;
                }
                // if (search(s, p, strIndex + 1, stateIndex + 1)) {
                //     return true;
                // }
            }
            // skip
            if (search(s, p, strIndex, stateIndex + 1)) {
                return true;
            }

        } else {
            if (state.match(c)) {
                if (search(s, p, strIndex + 1, stateIndex + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool isMatch(string s, string p) {
        s.push_back('$');
        p.push_back('$');
        for (int i = 0; i < p.size(); i++) {
            if (i + 1 < p.size() && p[i + 1] == '*') {
                states.emplace_back(p[i], true);
                i++;
            } else {
                states.emplace_back(p[i], false);
            }
        }
        return search(s, p, 0, 0);
    }
};
// @lc code=end
