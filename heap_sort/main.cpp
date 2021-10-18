#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

void heapify (ll i, ll cur, vector<ll> &vec) {
    ll l = 2 * i, r = 2 * i + 1, n = cur, t = i;
    if (l < n && vec[l] > vec[i])
        t = l;
    else if (r < n && vec[r] > vec[i])
        t = r;
    else
        t = i;

    if (t != i) {
        swap(vec[i], vec[t]);
        heapify(t, cur, vec);
    }
}

void build_heap(vector<ll> &vec) {
    for (ll i = vec.size() / 2 - 1; i >= 0; --i)
        heapify(i, vec.size(), vec);
}

void heap_sort (vector <ll> & vec) {
    build_heap(vec);
    for (ll i = vec.size() - 1; i >= 0; --i) {
        swap(vec[0], vec[i]);
        heapify(0, i, vec);
    }
}

int main() {
    ll n;  cin >> n;
    vector<ll> vec(n);

    for (ll i = 0; i < n; ++i)
        cin >> vec[i];

    heap_sort(vec);

    for (ll i = 0; i < n; ++i)
        cout << vec[i] << " ";
    return 0;
}
