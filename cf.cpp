#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b, c;
        bool possible = false;

        for (int i = 0; i < n; ++i) {
            if (!possible) {
                b.push_back(a[i]);
                possible = true;
            } else {
                bool found = false;
                for (int j = 0; j < b.size(); ++j) {
                    if (a[i] % b[j] != 0) {
                        c.push_back(a[i]);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    b.push_back(a[i]);
                }
            }
        }

        if (b.size() >= 1 && c.size() >= 1) {
            cout << b.size() << " " << c.size() << endl;
            for (int num : b) {
                cout << num << " ";
            }
            cout << endl;
            for (int num : c) {
                cout << num << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
