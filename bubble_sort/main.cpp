#include <iostream>
#include <vector>

using namespace std;

void swap (int *p1, int *p2) {
    int *t = p1;
    p1 = p2;
    p2 = t;
}

void bubble_sort(vector<int> &vec) {
    for (int i = 0; i < vec.size() - 1; ++i) {
        for (int j = 0; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j+1])
                swap(vec[j], vec[j+1]);
        }
    }
}

int main() {
    int n;  cin >> n;
    vector<int> vec;    vec.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> vec[i];

    bubble_sort(vec);

    for (int i = 0; i < n; ++i)
        cout << vec[i] << " ";

    return 0;
}
