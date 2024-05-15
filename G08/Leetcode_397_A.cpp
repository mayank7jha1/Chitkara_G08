#include<iostream>
#include<unordered_map>
using  namespace std;




class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> ump;

        for (int i = 0; i < t.size(); i++) {
            ump[t[i]] = i;
        }

        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += abs(i - ump[s[i]]);
        }

        return res;
    }
};


int main() {

}