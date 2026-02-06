#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> len(n, 1);
    vector<long long> cnt(n, 1);

    int maxLen = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (len[j] + 1 > len[i]) {
                    len[i] = len[j] + 1;
                    cnt[i] = cnt[j];
                } else if (len[j] + 1 == len[i]) {
                    cnt[i] += cnt[j];
                }
            }
        }
        maxLen = max(maxLen, len[i]);
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        if (len[i] == maxLen) {
            total += cnt[i];
        }
    }

    cout << maxLen << " " << total << '\n';
    return 0;
}
