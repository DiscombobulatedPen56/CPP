#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<vector<int>> table(a, vector<int>(b));

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i < a; i++){
        table[i][0] += table[i - 1][0];
    }
    for (int i = 1; i < b; i++) {
        table[0][i] += table[0][i-1];
    }
    for (int i = 1; i < a; i++) {
        for (int j = 1; j < b; j++) {
            table[i][j] += min(table[i-1][j], table[i][j-1]);
        }
    }
    cout << table[a - 1][b - 1];
}
