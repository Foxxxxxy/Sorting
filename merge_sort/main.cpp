#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int l, int r, int m) {
    vector<int> left, right;
    for (int i = l; i < m; ++i)
        left.push_back(vec[i]);
    for (int i = m; i < r; ++i)
        right.push_back(vec[i]);

    auto p1 = left.begin();
    auto p2 = right.begin();
    auto p = vec.begin() + l;

    while (p1 != left.end() && p2 != right.end()) {
        if (*p1 <= *p2) {
            *p = *p1;
            p1++;
            p++;
        } else {
            *p = *p2;
            p2++;
            p++;
        }
    }
    while (p1!=left.end()) {
        *p = *p1;
        p1++;
        p++;
    }
    while (p2!=right.end()) {
        *p = *p2;
        p2++;
        p++;
    }
}

void merge_sort(vector<int> &vec, int l, int r) {
    if (l >= r)
        return;

    int m =  (l + r) / 2;

    merge_sort(vec, l, m);
    merge_sort(vec, m + 1, r);
    merge(vec, l, r, m);
}


int main() {
    int n;  cin >> n;
    vector<int> vec;    vec.resize(n);
    for (int i = 0; i < n; ++i)
        cin>>vec[i];
    merge_sort(vec, 0, n);
    for (int i = 0; i < n; ++i)
        cout << vec[i] << " ";
    return 0;
}