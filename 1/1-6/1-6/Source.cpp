#include <iostream>
#include <cmath>
#include <string>
void URLify(std::string& s, int l) { // 1.3
    std::string temp;
    for (int i = 0; i < l; ++i) {
        if (s[i] != ' ') {
            temp += s[i];
        }
        else {
            temp += "%20";
        }
    }
    s = temp;
}

bool permutation(std::string& s1, std::string& s2) { // 1.2
    int arr[26] = { 0 };
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == ' ') {
            continue;
        }
        if (s1[i] - 'a' <= 25 && s1[i] - 'a' >= 0) {
            ++arr[s1[i] - 'a'];
        }
        else {
            ++arr[s1[i] - 'A'];
        }
    }

    int brr[26] = { 0 };
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] == ' ') {
            continue;
        }
        if (s2[i] - 'a' <= 25 && s2[i] - 'a' >= 0) {
            ++brr[s2[i] - 'a'];
        }
        else {
            ++brr[s2[i] - 'A'];
        }
    }


    for (int i = 0; i < 26; ++i) {
        if (arr[i]) {
            if (!brr[i]) {
                return false;
            }
        }
        else if (brr[i]) {
            if (!arr[i]) {
                return false;
            }
        }
    }
    return true;
}

bool isUniqe(std::string& s) {  //1.1
    std::string temp = s;
    for (int i = 0; i < temp.length(); ++i) {
        for (int j = i + 1; j < temp.length(); ++j) {
            if (temp[i] > temp[j]) {
                char x = temp[i];
                temp[i] = temp[j];
                temp[j] = x;
            }
        }
    }
    for (int i = 0; i < temp.length() - 1; ++i) {
        if (temp[i] == temp[i + 1]) {
            return false;
        }
    }
    return true;
}

bool oneAway(std::string& s1, std::string& s2) { // 1.5
    if (std::abs(s1.length() - s2.length()) > 1) {
        return false;
    }

    int arr[128] = { 0 };
    for (int i = 0; i < s1.length(); ++i) {
        ++arr[s1[i] - 0];
    }
    for (int i = 0; i < s2.length(); ++i) {
        ++arr[s2[i] - 0];
    }

    int count = 0;
    for (int i = 0; i < 128; ++i) {
        if (arr[i] == 1) {
            ++count;
        }
        if (count > 2) {
            return false;
        }
        if (arr[i] > 2) {
            return false;
        }
    }
    return true;
}

bool palindromePermutation(std::string& s) { // 1.4
    if (!s.length()) {
        return false;
    }
    int arr[26] = { 0 };
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ' ') {
            continue;
        }
        if (s[i] - 'a' >= 0 && s[i] - 'a' < 26) {
            ++arr[s[i] - 'a'];
        }
        else {
            ++arr[s[i] - 'A'];
        }
    }

    int count = 0;
    for (int i = 0; i < 27; ++i) {
        if (arr[i] == 0) {
            continue;
        }
        if (arr[i] % 2 == 1) {
            ++count;
        }
        if (count > 1) {
            return false;
        }
    }

    return true;
}

std::string& compression(std::string& s) { //1.6
    std::string tmp;
    int count = 1;
    for (int i = 1; i <= s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            ++count;
            continue;
        }
        else {
            tmp += s[i - 1] + std::to_string(count);
            count = 1;
        }
    }
    s = tmp;
    return s;
}


int main()
{
    std::string a = "pale";
    std::string b = "bake";

    /*std::cout << compression(b);

    if(oneAway(a,b)) {
        std::cout << "ok";
    }

    if(isUniqe(a)) {
        std::cout << "ok";
    }
    if(permutation(a,b)) {
        std::cout << "ok";
    }
    int l = 13;
    URLify(a, l);*/


    return 0;
}
