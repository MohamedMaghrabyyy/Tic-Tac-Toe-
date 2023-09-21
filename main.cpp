#include <iostream>
using namespace std;

int main() {
    int n;
    bool flag_x = false;
    bool flag_o = false;
    cout << "Enter the size of the grid: "<<endl;
    cin >> n;
    if (n > 9 || n < 3) {
        cout << "Invalid grid size;";
        return 0;
    }
    char arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr[i][j] = '.';

    bool turn = true;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            for (int a = 0; a < n; a++) 
            {
                for (int b = 0; b < n; b++)
                    cout << arr[a][b] << " ";
                cout << '\n';
            }
            if (flag_x) 
            {
                cout << "Player x won!";
                return 0;
            }
            if (flag_o) 
            {
                cout << "Player o won!";
                return 0;
            }

            int r, c;
            while (true) 
            {
                if (turn)
                {
                    cout << "Player x turn. Enter empty location (r, c): ";
                    cin >> r >> c;
                    if (arr[r - 1][c - 1] == 'x' || arr[r - 1][c - 1] == 'o') {
                        cout << "Place already filled..try again" << endl;
                        continue;
                    }
                    arr[r - 1][c - 1] = 'x';
                    turn = false;
                } 
                else
                {
                    cout << "Player o turn. Enter empty location (r, c): ";
                    cin >> r >> c;
                    if (arr[r - 1][c - 1] == 'x' || arr[r - 1][c - 1] == 'o')
                    {
                        cout << "Place already filled..try again" << endl;
                        continue;
                    }
                    arr[r - 1][c - 1] = 'o';
                    turn = true;
                }
                break;
            }

            int cnt = 0;

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++) 
                    if (arr[i][j] == 'x')
                        cnt++;
                
                if (cnt == n) 
                {
                    flag_x = true;
                    break;
                } 
                else 
                    cnt = 0;
                
            }

            for (int i = 0; i < n; i++) 
            { 
                for (int j = 0; j < n; j++) {
                    if (arr[j][i] == 'x')
                        cnt++;
                }
                if (cnt == n) {
                    flag_x = true;
                    break;
                else
                    cnt = 0;
                
            }

            for (int i = 0; i < n; i++)
                if (arr[i][i] == 'x')
                    cnt++;
            
            if (cnt == n)
                flag_x = true;
            else
                cnt = 0;
            

            for (int i = 0; i < n; i++)
                if (arr[i][n - i - 1] == 'x')
                    cnt++;
            
            if (cnt == n) 
                flag_x= true;
            else
                cnt = 0;
            

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++)
                    if (arr[i][j] == 'o')
                        cnt++;
                
                if (cnt == n) 
                {
                    flag_o = true;
                    break;
                } 
                else
                    cnt = 0;
                
            }

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++)
                    if (arr[j][i] == 'o')
                        cnt++;
                
                if (cnt == n) 
                {
                    flag_o = true;
                    break;
                } 
                else
                    cnt = 0;
                
            }

            for (int i = 0; i < n; i++)
                if (arr[i][i] == 'o')
                    cnt++;
            if (cnt == n) 
                flag_o = true;
            else
                cnt = 0;
            

            for (int i = 0; i < n; i++)
                if (arr[i][n - i - 1] == 'o')
                    cnt++;
            if (cnt == n)
                flag_o = true;
            else
                cnt = 0;
            
        }
    }

    return 0;
}
