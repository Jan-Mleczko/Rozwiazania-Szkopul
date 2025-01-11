#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, K, Q;

int main () {
    int i, j, C, P, R;
    int zbior, cecha;
    int S, Sprim;

    cin.sync_with_stdio (false);
    cin.tie (NULL);
    cin >> N >> K >> Q;
    vector<pair<int,int>> dp (1 << K, {INT_MAX, -1});
    zbior = 0;
    for (i = 0; i < N; ++i) {
        cin >> C >> P;
        zbior = 0;
        for (j = 0; j < P; ++j) {
            cin >> cecha;
            zbior |= 1 << (cecha - 1);
            }
        dp[zbior] = min (dp[zbior], {C, i});
        }

    for (S = (1 << K) - 1; S > 0; --S)
        for (i = 0; i < K; ++i) {
            Sprim = S & ~(1 << i);
            dp[Sprim] = min (dp[Sprim], dp[S]);
            }

    for (i = 0; i < Q; ++i) {
        cin >> R;
        zbior = 0;
        for (j = 0; j < R; ++j) {
            cin >> cecha;
            zbior |= 1 << (cecha - 1);
            }
        if (dp[zbior].second < 0)
            cout << "NIE\n";
        else
            cout << dp[zbior].second + 1 << '\n';
        }

    return 0;
    }
