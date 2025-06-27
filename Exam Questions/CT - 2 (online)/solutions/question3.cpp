#include <iostream>
#include <deque>
using namespace std;

int findCeleb(int matrix[][100], int n) {
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        dq.push_back(i);
    }

    while(dq.size() > 1) {
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();

        if(matrix[a][b] == 1) {
            dq.push_back(b);
        } else {
            dq.push_back(a);
        }
    }

    int candidate = dq.front();
    for(int i = 0; i < n; i++) {
        if(i != candidate) {
            if(matrix[candidate][i] == 1 || matrix[i][candidate] == 0) {
                return -1;
            }
        }
    }
    return candidate;
}

int main() {
    int n = 4;
    int matrix[100][100] = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int celeb = findCeleb(matrix, n);
    if(celeb == -1) {
        cout << "No celebrity found" << endl;
    } else {
        cout << "Celebrity is person " << celeb << endl;
    }

    return 0;
}