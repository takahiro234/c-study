#include <iostream>
#include <vector>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    // 各行の合計
    vector<int> rowSum(H, 0);

    // 各列の合計
    vector<int> colSum(W, 0);

    // 行と列の合計を計算
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            rowSum[i] += A[i][j];
            colSum[j] += A[i][j];
        }
    }

    // 答えを出力
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << rowSum[i] + colSum[j] - A[i][j];
            if (j != W - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;
}
