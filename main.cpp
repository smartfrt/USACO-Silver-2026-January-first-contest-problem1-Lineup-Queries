#include <iostream>

using namespace std;

long long query1(long long c, long long t) {
    if (t < 2 * c) {
        return c;
    }
    long long curr_t = 2 * c - 1;
    long long pos = c;
    while (true) {
        if (curr_t + pos >= t) {
            return pos - (t - curr_t);
        }
        curr_t += pos + 1;
        pos = curr_t / 2;
    }
}

long long query2(long long x, long long t) {
    if (t < 2 * x) {
        return x;
    }
    long long curr_t = t + x;
    while (curr_t > 0 && curr_t % 3 != 2) {
        curr_t -= (curr_t / 3) + 1;
    }
    if (curr_t == 0) {
        return 0;
    }
    
    return (curr_t / 3) + 1;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int type;
        long long a, t;
        cin >> type >> a >> t;
        if (type == 1) {
            cout << query1(a, t) << endl;
        } else {
            cout << query2(a, t) << endl;
        }
    }

    return 0;
}
