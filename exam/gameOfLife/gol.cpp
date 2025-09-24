#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int main(int ac, char **av)
{
    (void)ac;
    int w = atoi(av[1]), h = atoi(av[2]), iter = atoi(av[3]), x = 0, y = 0;
    int board[h][w], next[h][w];
    bool pen = false;
    char c;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            board[i][j] = 0;
    
    while (read(0, &c, 1) == 1) // 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
    {
        if (c == 'w' && x > 0)
            x--;
        else if(c == 's' && x < h -1)
            x++;
        else if (c == 'd' && y < w -1)
            y++;
        else if (c == 'a' && y > 0)
            y--;
        else if (c == 'x')
            pen =!pen;
        if (pen)
            board[x][y] = 1;
    }

    for(int it = 0; it < iter; it++)
    {
        for(int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int n = 0;

                for (int k = -1; k <= 1; k++)
                    for (int l = -1; l <=1 ; l++)
                        if ((k || l) && i + k >= 0 && i + k < h && j + l >= 0 && j + l < w)
                            n += board[i+k][j+l];
                printf("for board[%d][%d] , n is = %d\n",i, j, n);
                if ((board[i][j] && (n == 3 || n == 2)) || (!board[i][j] && n == 3))
                    next[i][j] = 1;
                else
                    next[i][j] = 0;
            }
        }
        for (int i = 0; i < h; i++)
        {
            for(int j = 0; j< w; j++)
            {
                board[i][j] = next[i][j];
            }
        }
    }

        for (int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                board[i][j] ? putchar('O') : putchar(' ');
            }
            putchar('\n');
        }
}