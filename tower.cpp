/* Problema celor 8 turnuri: să se scrie un program care plasează 8 turnuri pe tabla
de șah, fără ca acestea să se atace reciproc.*/

#include <iostream>
#include <vector>

const int N = 8;

bool can_place_tower(const std::vector<std::vector<int>>& board, int r, int c)
{
    for (int i = 0; i < N; i++)
    {
        if (board[r][i] == 1 || board[i][c] == 1)
            return false;
    }
    return true;
}

bool place_tower(std::vector<std::vector<int>>& board, int nr_towers)
{
    if (nr_towers == N)
    {
        //afisare solutie
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cout << board[i][j];
            }
            std::cout << std::endl;
        }
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (can_place_tower(board, i, j))
            {
                board[i][j] = 1;
                if (place_tower(board, nr_towers + 1))
                    return true;
                board[i][j] = 0;
            }
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> board(N, std::vector<int>(N, 0));
    place_tower(board, 0);
    return 0;
}