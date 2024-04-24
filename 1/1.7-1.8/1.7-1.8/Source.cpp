#include <iostream>
#include <vector>

int main()
{
    /*const int row = 4;   //// ex. 1.7
    const int col = 5;
    int mtx[row][col];
    int a = 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            mtx[i][j] = a;
            ++a;
        }
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::cout << mtx[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int rteMtx[col][row];
    for (int i = 0; i < col; ++i) {
        int idx = 0;
        for (int j = row - 1; j >= 0; --j) {
            rteMtx[i][j] = mtx[idx][i];
            ++idx;
        }
    }

    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            std::cout << rteMtx[i][j] << ' ';
        }
        std::cout << std::endl;
    }*/

    //ex. 1.8
    const int r = 4;
    const int c = 5;
    int mtx[r][c];
    int k = 1;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            mtx[i][j] = k;
            ++k;
        }
    }

    mtx[1][3] = 0;
    mtx[2][0] = 0;
    std::vector<int> p(c, 0);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (p[j]) {
                break;
            }
            if (mtx[i][j] == 0) {
                for (int k = 0; k < r; ++k) {
                    mtx[k][j] = 0;
                }
                for (int k = 0; k < c; ++k) {
                    mtx[i][k] = 0;
                }
                ++p[j];
                break;
            }
        }

    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {

            std::cout << mtx[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    /*  ex. 1.8*
    const int N = 4;
    int a[N][N];
    int k = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a[i][j] = k;
            ++k;
        }
    }

    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }*/

    return 0;
}
