#include <iostream>
#include <vector>

using namespace std;

bool EmptySpace(int choise, vector<string> board)
{
    if (board[choise - 1].empty() || board[choise - 1] == "")
        return true;
    return false;
}

bool WinCheck(vector<string> board)
{
    if (board[0] == "X" || board[0] == "O")
        if (board[0] == board[1] && board[1] == board[2])
            return true;
    if (board[3] == "X" || board[3] == "O")
        if (board[3] == board[4] && board[4] == board[5])
            return true;
    if (board[6] == "X" || board[6] == "O")
        if (board[6] == board[7] && board[7] == board[8])
            return true;
    if (board[0] == "X" || board[0] == "O")
        if (board[0] == board[3] && board[3] == board[6])
            return true;
    if (board[1] == "X" || board[1] == "O")
        if (board[1] == board[4] && board[4] == board[7])
            return true;
    if (board[2] == "X" || board[2] == "O")
        if (board[2] == board[5] && board[5] == board[8])
            return true;
    if (board[0] == "X" || board[0] == "O")
        if (board[0] == board[4] && board[4] == board[8])
            return true;
    if (board[2] == "X" || board[2] == "O")
        if (board[2] == board[4] && board[4] == board[6])
            return true;
    return false;
}

void PrintBoard()
{
    cout << "\n";
    cout << "| 1 | | 2 | | 3 |\n";
    cout << "| 4 | | 5 | | 6 |\n";
    cout << "| 7 | | 8 | | 9 |\n";
    cout << "\n";
}

void PrintBoardUpdate(vector<string> board)
{
    cout << "\n";
    cout << "| " << board[0] << " |" << "| " << board[1] << " |" << "| " << board[2] << " |\n";
    cout << "| " << board[3] << " |" << "| " << board[4] << " |" << "| " << board[5] << " |\n";
    cout << "| " << board[6] << " |" << "| " << board[7] << " |" << "| " << board[8] << " |\n";
    cout << "\n";
}

bool isTie(vector<string> board)
{
    int count = 0;
    if (!WinCheck(board))
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (!board[i].empty())
                count++;
        }
    }
    if (count == 9)
        return true;
    return false;
}

void clearBoard(vector<string> board)
{
    for (int i = 0; i < board.size(); i++)
        board[i] = "";
}

int main()
{
    int player1, player2;
    int scoreP1 = 0,scoreP2 = 0;
    bool win = false;
    vector<string> board(9);
    for (int i = 0; i < board.size(); i++)
        board[i] = "";
    cout << "Welcome to TicTacToe\n";

    cout << "Player 1 is X and Player 2 is O\n\n";
    while (!win)
    {
        cout << "Player 1 TURN\n\n";
        cout << "choose a number between 1 - 9\n\n";
        PrintBoard();
        cin >> player1;
        bool enter1 = EmptySpace(player1, board);
        if(enter1)
            board[player1 - 1] = "X";
        while (!enter1)
        {
            cout << "Choose other number\n\n";
            cin >> player1;
            cout << "\n";
            if (EmptySpace(player1, board))
            {
                board[player1 - 1] = "X";
                enter1 = true;
            }
        }
        if (WinCheck(board))
        {
            cout << "-------------\n";
            cout << "Player 1 Won!\n";
            cout << "-------------\n";
            win = true;
            scoreP1++;
        }
        system("cls");
        PrintBoardUpdate(board);
        if (isTie(board))
        {
            win = true;
            cout << "----\n";
            cout << "Tie!\n";
            cout << "----\n";
            cout << "\n";
        }
        if (!win)
        {
            cout << "Player 2 TURN\n\n";
            cout << "choose a number between 1 - 9\n\n";
            PrintBoard();
            cin >> player2;
            bool enter2 = EmptySpace(player2, board);
            if (enter2)
                board[player2 - 1] = "O";
            while (!enter2)
            {
                cout << "\n";
                cout << "Choose other number\n\n";
                cin >> player2;
                cout << "\n";
                if (EmptySpace(player2, board))
                {
                    board[player2 - 1] = "O";
                    enter2 = true;
                }
            }
            if (WinCheck(board))
            {
                cout << "-------------\n";
                cout << "Player 2 Won!\n";
                cout << "-------------\n";
                win = true;
                scoreP2++;
            }
            if (isTie(board))
            {
                if (isTie(board))
                {
                    win = true;
                    cout << "----\n";
                    cout << "Tie!\n";
                    cout << "----\n";
                    cout << "\n";
                }
            }
            system("cls");
            PrintBoardUpdate(board);
        }

        if (win)
        {
            string PlayAgain;
            bool check = false;
            cout << "Score is:  Player 1 - " << scoreP1 << " , Player2 - " << scoreP2 << " \n";
            cout << "Would you like to play again? (Y/N)";
            cin >> PlayAgain;
            while (!check)
            {
                if (PlayAgain != "y" || PlayAgain != "n" || PlayAgain != "Y" || PlayAgain != "N")
                {
                    if (PlayAgain == "y" || PlayAgain == "Y")
                    {
                        win = false;
                        check = true;
                        for (int i = 0; i < board.size(); i++)
                            board[i] = "";
                        system("cls");
                    }
                    if (PlayAgain == "n" || PlayAgain == "N")
                    {
                        system("pause");
                        system("cls");
                    }
                }
            }
        }
    }
}