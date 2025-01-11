#include <iostream>
#include <climits>
using namespace std;

int tree[131072], shift[131072];

void push (int v) {
    tree[v << 1] += shift[v];
    tree[(v << 1) + 1] += shift[v];
    shift[v << 1] += shift[v];
    shift[(v << 1) + 1] += shift[v];
    shift[v] = 0;
    }

void update (int v, int val, int a, int b, int l, int r) {
    int mid, valA, valB;

    if (r < a || b < l)
        return;
    if (l >= a && r <= b) {
        tree[v] += val;
        shift[v] += val;
        return;
        }
    mid = l + ((r - l) >> 1);
    push (v);
    update (v << 1, val, a, b, l, mid);
    update ((v << 1) + 1, val, a, b, mid + 1, r);
    valA = tree[v << 1];
    valB = tree[(v << 1) + 1];
    tree[v] = (valA > valB) ? valA : valB;
    }

int query (int v, int a, int b, int l, int r) {
    int mid, valA, valB;

    if (r < a || b < l)
        return INT_MIN;
    if (a <= l && r <= b)
        return tree[v];
    mid = l + ((r - l) >> 1);
    push (v);
    valA = query (v << 1, a, b, l, mid);
    valB = query ((v << 1) + 1, a, b, mid + 1, r);
    return (valA > valB) ? valA : valB;
    }

int main () {
    int n, m, z;
    int i, p, k, lMiejsc;

    cin.sync_with_stdio (false);
    cin.tie (NULL);
    cin >> n >> m >> z;

    i = 0;
    do {
        cin >> p >> k >> lMiejsc;
        --k;
        if (m - query (1, p, k, 0, 65535) >= lMiejsc) {
            cout << "T\n";
            update (1, lMiejsc, p, k, 0, 65535);
            }
        else
            cout << "N\n";
        } while (++i < z);

    return 0;
    }
