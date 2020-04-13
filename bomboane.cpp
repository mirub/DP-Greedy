// Banu Miruna-Elena 321CA
// Copyright 2020
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;


class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int n, m;
    vector<pair<int, int>> problems;

    void read_input() {
        ifstream fin("bomboane.in");
        fin >> n >> m;
        for (int i = 0; i < n; i++) {
            int x, y;
            fin >> x >> y;
            problems.push_back(make_pair(x, y));
        }
        fin.close();
    }

    long find_ways(int n, int m, vector<pair<int, int>> problems) {
        // Initialize the solution matrix with 0: lines represent
        // the children and columns represent the number of ways that
        // the current number of candies could be given to the current child
        vector<vector<long>> candies(n + 1, vector<long>(m + 1, 0));

        // For the first child, the number of ways candies corresponding to the
        // interval of solved problems can be given is 1
        for (int i = problems[0].first; i <= problems[0].second && i <= m;
            ++i) {
                candies[1][i] = 1;
        }

        // For every other child, the number of ways the candies can be given is
        // equal to the sum between the current value and the number of ways
        // the previous child has received (j - possible_amount) candies
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int k = problems[i - 1].first; k <= problems[i - 1].second
                    && k <= j; ++k) {
                    candies[i][j] = ((candies[i][j] % MOD) +
                                        (candies[i - 1][j - k] % MOD)) % MOD;
                }
            }
        }

        // The result is the down right corner of the matrix, meaning the number
        // of ways the last child can receive m candies
        return (candies[n][m] % MOD);
    }

    long get_result() {
        return find_ways(n, m, problems);
    }

    void print_output(int result) {
        ofstream fout("bomboane.out");
        fout << result;
        fout.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
