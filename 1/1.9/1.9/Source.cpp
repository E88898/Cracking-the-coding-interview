#include <iostream>

bool isSubstring(std::string& s1, std::string& s2) {
    if (s1.length() != s2.length() && s1.length() <= 0) {
        return false;
    }
    int j = 0;
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] == s1[j]) {
            for (int k = i; k < s2.length(); ++k) {
                if (s2[k] != s1[j]) {
                    j = 0;
                    break;
                }
                if (k == s2.length() - 1) {
                    k = -1;
                }
                if (j == s1.length() - 1) {
                    return true;
                }
                ++j;
            }
        }
    }

    return false;
}

int main()
{
    std::string s1 = "gavligavl";
    std::string s2 = "ligavlgav";
 
    if (isSubstring(s1, s2)) {
        std::cout << "ok";
    }
    return 0;
}
