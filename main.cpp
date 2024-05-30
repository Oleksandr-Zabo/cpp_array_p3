#include <iostream>
#include <ctime>;
using namespace std;

//
int main()
{
    srand(time(0));
    const int full_col = 20;
    const int full_row = 7;
    int row, col;
    do
    {
        cout << "Enter the number of columns(1-6): ";
        cin >> row;
    } while (row < 1 || row > full_row);
    do
    {
        cout << "Enter the number of rows(how much numers you have): ";
        cin >> col;
    } while (col < 1 || col > full_col);


    int arr[full_col][full_row], user_num;
    for (size_t i = 0; i < col; i++)
    {
        cout << "Enter your number: ";
        cin >> user_num;
        for (size_t j = 0; j < row; j++)
        {
            arr[i][j] = user_num;
            user_num *= 2;
        }
    }
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}