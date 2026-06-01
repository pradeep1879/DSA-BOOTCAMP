#include <iostream>;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> freq(101, 0);

    for (int i = 0; i < N; i++) {
        int age;
        cin >> age;
        freq[age]++;
    }

    bool first = true;
    for (int age = 0; age <= 100; age++) {
        while (freq[age]--) {
            if (!first) cout << ' ';
            cout << age;
            first = false;
        }
    }

    cout << '\n';
    return 0;
}