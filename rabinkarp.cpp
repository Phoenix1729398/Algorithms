#include <bits/stdc++.h>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;
    int n = text.size();
    int m = pattern.size();
    if (m > n) return 0;
    const int base = 256;
    const int mod = 101;
    int patHash = 0, txtHash = 0, power = 1;
    for (int i = 0; i < m - 1; i++)
        power = (power * base) % mod;
    for (int i = 0; i < m; i++) {
        patHash = (patHash * base + pattern[i]) % mod;
        txtHash = (txtHash * base + text[i]) % mod;
    }
    for (int i = 0; i <= n - m; i++) {
        if (patHash == txtHash) {
            if (text.substr(i, m) == pattern)
                cout << i << " ";
        }
        if (i < n - m) {
            txtHash = (txtHash - text[i] * power) % mod;
            txtHash = (txtHash * base + text[i + m]) % mod;

            if (txtHash < 0) txtHash += mod;
        }
    }
    return 0;
}
