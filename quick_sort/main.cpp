#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &vec, int l, int r) {
    int pivot = vec[r - 1];
    int i = l - 1;
    for (int j = l; j <= r; ++j) {
        if (vec[j] < pivot) {
            ++i;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[r - 1]);
    return i + 1;
}

void quick_sort(vector<int> &vec, int l, int r) {
    if (r - l <= 1)
        return;
    int p = partition(vec, l, r);
    quick_sort(vec, l, p);
    quick_sort(vec, p + 1, r);
}

int main() {
    int n;  cin >> n;
    vector<int> vec;    vec.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    quick_sort(vec, 0, n);

    for (int i = 0; i < n; ++i)
        cout << vec[i] << " ";
    return 0;
}
