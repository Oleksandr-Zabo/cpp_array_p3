#include <iostream>
using namespace std;

int main()
{
    srand(time(0));
    const int full_col = 100;
    const int full_row = 100;
    int row, col;
    do
    {
        cout << "Enter the number of columns: ";
        cin >> row;
    } while (row < 1 || row > 100);
    do
    {
        cout << "Enter the number of rows: ";
        cin >> col;
    } while (col < 1 || col > 100);


    int arr[full_col][full_row];
    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            arr[i][j] = rand() % 10;
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
    cout << endl << endl;

    cout << "\t\tMenu choice" << endl;
    cout << "\t\t0- exit" << endl;
    cout << "\t\t1- shift to top" << endl;
    cout << "\t\t2- shift to down" << endl;
    cout << "\t\t3- shift to right" << endl;
    cout << "\t\t4- shift to left" << endl;
    int choice;
    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice < 0 || choice > 4);


    switch (choice)
    {
        case 0:
        {
            exit(0);
        }break;

        case 1://top
        {
            int step_of_move;
            do
            {
                cout << "Enter the step(from 1): ";
                cin >> step_of_move;
            } while (step_of_move < 1 || step_of_move > col);//step-col


            int temp[full_col][full_row];//create copy of top elements
            for (size_t i = 0; i < step_of_move; i++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    temp[i][j] = arr[i][j];
                }
            }

            for (int i = col - step_of_move; i >= 0; i--)//shift to down
            {
                for (size_t j = 0; j < row; j++)
                {
                    arr[i + step_of_move][j] = arr[i][j];
                }
            }

            for (int i = 0; i < step_of_move; i++)//write old elements from down to top
            {
                for (size_t j = 0; j < row; j++)
                {
                    arr[i][j] = temp[i][j];
                }
            }

            cout << "Array after swapping: " << endl;
            for (size_t i = 0; i < col; i++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }   
        }break;


        case 2://down
        {
            int step_of_move;
            do
            {
                cout << "Enter the step(from 1): ";
                cin >> step_of_move;
            } while (step_of_move < 1 || step_of_move > col);//step-col

            int temp[full_col][full_row];//create copy of down elements
            for (int i = col-step_of_move, k=0; i < col; i++, k++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    temp[k][j] = arr[i][j];
                }
            }

            for (int i = 0; i <= step_of_move; i++)//shift to down
            {
                for (size_t j = 0; j < row; j++)
                {
                    arr[i][j] = arr[step_of_move + i][j];
                }
            }

            for (int i = col - step_of_move, k = 0; i < col; i++, k++)//write old elements from top to down
            {
                for (size_t j = 0; j < row; j++)
                {
                    arr[i][j] = temp[k][j];
                }
            }

            cout << "Array after swapping: " << endl;
            for (size_t i = 0; i < col; i++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }


        }break;


        case 3://right
        {

            int step_of_move;
            do
            {
                cout << "Enter the step(from 1): ";
                cin >> step_of_move;
            } while (step_of_move < 1 || step_of_move > row);//step-row

            int temp[full_col][full_row];//create copy of right elements
            for (size_t i = 0; i < col; i++)
            {
                for (int j = row - step_of_move, k = 0; j < row; j++, k++)
                {
                    temp[i][k] = arr[i][j];
                }
            }

            /*cout << "temp: " << endl;//print copy
            for (size_t i = 0; i < col; i++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    cout << temp[i][j] << " ";
                }
                cout << endl;
            }*/


            for (int i = 0; i < col; i++)//shift to right
            {
                for (int j = row - step_of_move; j >= 0; j--)
                {
                    arr[i][j + step_of_move] = arr[i][j];
                }
            }

            for (int i = 0; i < col; i++)//write old elements from right to left
            {
                for (int j = 0; j < step_of_move; j++)
                {
                    arr[i][j] = temp[i][j];
                }
            }

            cout << "Array after swapping: " << endl;
            for (size_t i = 0; i < col; i++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }break;

        case 4://left
        {
            int step_of_move;
            do
            {
                cout << "Enter the step(from 1): ";
                cin >> step_of_move;
            } while (step_of_move < 1 || step_of_move > row);//step-row

            int temp[full_col][full_row];//create copy of left elements
            for (size_t i = 0; i < col; i++)
            {
                for (int j = 0; j < step_of_move; j++)
                {
                    temp[i][j] = arr[i][j];
                }
            }


            for (int i = 0; i < col; i++)//shift to left
            {
                for (int j = 0; j < row - step_of_move; j++)
                {
                    arr[i][j] = arr[i][j + step_of_move];
                }
            }

            for (int i = 0; i < col; i++)//write old elements from left to right
            {
                for (int j = row - step_of_move, k = 0; j < row; j++, k++)
                {
                    arr[i][j] = temp[i][k];
                }
            }

            cout << "Array after swapping: " << endl;
            for (size_t i = 0; i < col; i++)
            {
                for (size_t j = 0; j < row; j++)
                {
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }break;
    }


    
    /*for (size_t i = step_of_move; i < col; i++)//from lesson
    {
        for (size_t j = 0; j < row; j++)
        {
            arr[i - step_of_move][j] = arr[i][j];
        }
    }
    int k = step_of_move - 1;
    for (size_t i = col - 1; i > step_of_move; i--)
    {
        for (size_t j = 0; j < row; j++)
        {
            arr[i][j] = temp[k][j];
        }
        k--;
    }*/


    return 0;
}