// Banu Miruna-Elena 321CA
// Copyright 2020

#include <bits/stdc++.h>
using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<pair<int, int>> fence;

    void read_input() {
        ifstream fin("gard.in");
        fin >> n;
        int start, stop;
        for (int i = 0, d; i < n; i++) {
            fin >> start >> stop;
            fence.push_back(make_pair(start, stop));
        }
        fin.close();
    }

    static bool sort_lower(pair<int, int> p1, pair<int, int> p2) {
        if (p1.first < p2.first) {
            return true;
        } else if (p1.first == p2.first) {
            if (p1.second > p2.second) {
                return true;
            }
        }
        return false;
    }

    int get_result() {
        sort(fence.begin(), fence.end(), sort_lower);
        int largest_end = fence[0].second;
        int size = 0;
        for (int i = 1; i < fence.size(); ++i) {
            if (fence[i].second <= largest_end) {
                size++;
            } else {
                largest_end = fence[i].second;
            }
        }
        return size;
    }

    void print_output(int result) {
        ofstream fout("gard.out");
        fout << result;
        fout.close();
    }
};

// Please always keep this simple main function!
int main() {
    // Allocate a Task object on heap in order to be able to
    // declare huge static-allocated data structures inside the class.
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
