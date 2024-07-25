#include <iostream>
#include <vector>
#include <conio.h>
#include <utility>

class TicTacToe
{
private:
    std::vector<std::vector<char>> m_board;
    std::vector<std::pair<int, int>> m_coordsX;
    std::vector<std::pair<int, int>> m_coords0;
    const int m_row_size = 3;
    const int m_col_size = 3;

public:
    void createBoard();
    void printBoard();
    void gameLogic();
    void startGame();
    bool logicForX();
    bool logicFor0();
};


void TicTacToe::createBoard()
{
    m_board.resize(m_row_size);
    for (int i = 0; i < m_row_size; i++)
    {
        m_board[i].resize(m_col_size, '.');
    }
}

void TicTacToe::printBoard()
{
    for (int i = 0; i < m_row_size; i++)
    {
        for (int j = 0; j < m_col_size; j++)
        {
            std::cout << m_board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToe::logicForX()
{
    bool flag = false;
    if (m_coordsX.size() >= 3)
    {
        if ((m_coordsX[0].first + m_coordsX[0].second == m_board.size() - 1) && (m_coordsX[1].first + m_coordsX[1].second == m_board.size() - 1)
            && (m_coordsX[2].first + m_coordsX[2].second == m_board.size() - 1))
        {
            std::cout << "\n'X' wins in secondary diagonal direction :)\n";
            flag = true;
        }
        if ((m_coordsX[0].first == m_coordsX[0].second) && (m_coordsX[1].first == m_coordsX[1].second)
            && (m_coordsX[2].first == m_coordsX[2].second))
        {
            std::cout << "\n'X' wins in primary diagonal direction :)\n";
            flag = true;
        }
        if (m_coordsX[0].first == m_coordsX[1].first && m_coordsX[0].first == m_coordsX[2].first && m_coordsX[1].first == m_coordsX[2].first)
        {
            std::cout << "\n'X' wins in horizontal direction :)\n";
            flag = true;
        }
        if (m_coordsX[0].second == m_coordsX[1].second && m_coordsX[0].second == m_coordsX[2].second && m_coordsX[1].second == m_coordsX[2].second)
        {
            std::cout << "\n'X' wins in vertical direction :)\n";
            flag = true;
        }
    }
    return flag;
}

bool TicTacToe::logicFor0()
{
    bool flag = false;
    if (m_coords0.size() >= 3)
    {
        if ((m_coords0[0].first + m_coords0[0].second == m_board.size() - 1) && (m_coords0[1].first + m_coords0[1].second == m_board.size() - 1)
            && (m_coords0[2].first + m_coords0[2].second == m_board.size() - 1))
        {
            std::cout << "\n'0' wins in secondary diagonal direction direction :)\n";
            flag = true;
        }
        if ((m_coords0[0].first == m_coords0[0].second) && (m_coords0[1].first == m_coords0[1].second)
            && (m_coords0[2].first == m_coords0[2].second))
        {
            std::cout << "\n'0' wins in primary diagonal direction :)\n";
            flag = true;
        }
        if (m_coords0[0].first == m_coords0[1].first && m_coords0[0].first == m_coords0[2].first && m_coords0[1].first == m_coords0[2].first)
        {
            std::cout << "\n'0' wins in horizontal direction :)\n";
            flag = true;
        }
        if (m_coords0[0].second == m_coords0[1].second && m_coords0[0].second == m_coords0[2].second && m_coords0[1].second == m_coords0[2].second)
        {
            std::cout << "\n'0' wins in vertical direction :)\n";
            flag = true;
        }
    }
    return flag;
}


void TicTacToe::gameLogic()
{
    createBoard();
    int row_x, col_x;
    int row_0, col_0;
    bool flag_X = false;
    bool flag_0 = false;
    bool stop_game = false;

    try
    {
        while (!stop_game)
        {
            //for 'X'
            std::cout << "Enter coordinates of 'X'" << std::endl;
            std::cin >> row_x;
            std::cin >> col_x;
            if (row_x < 3 && col_x < 3)
            {
                if (m_board[row_x][col_x] == '.')
                {
                    m_coordsX.push_back(std::make_pair(row_x, col_x));
                    m_board[row_x][col_x] = 'X';                  
                }
                else
                {
                    std::cout << "[" << row_x << "][" << col_x << "] place is not empty\n";
                    return;
                }
                system("cls");
                printBoard();
                flag_X = logicForX();

                if (flag_X == true)
                {
                    stop_game = true;
                    break;
                }
                //check Draw condition 
                if (m_coordsX.size() == 5 && stop_game == false)
                {
                    std::cout << "\nThe Game ended with Draw\n";
                    break;
                }
            }
            else
            {
                throw std::invalid_argument("Coordinates entered for 'X' are out of range\n");
            }

            //for '0'
            std::cout << "Enter coordinates of '0'" << std::endl;
            std::cin >> row_0;
            std::cin >> col_0;

            if (row_0 < 3 && col_0 < 3)
            {
                if (m_board[row_0][col_0] == '.')
                {
                    m_coords0.push_back(std::make_pair(row_0, col_0));
                    m_board[row_0][col_0] = '0';
                }
                else
                {
                    std::cout << "[" << row_0 << "][" << col_0 << "] place is not empty\n";
                    return;
                }
                system("cls");
                printBoard();
                flag_0 = logicFor0();

                if (flag_0 == true)
                {
                    stop_game = true;
                    break;
                }
            }
            else
            {
                throw std::invalid_argument("Coordinates entered for '0' are out of range\n");
            }
        }  
    }
    catch (...)
    {
        std::cout << "Please enter valid coordinates\n";
    }
}

void TicTacToe::startGame()
{
    gameLogic();
}

int main()
{
    TicTacToe ob;
    ob.startGame();

    return 0;
}

