#include <stdio.h>
#include <stdlib.h>

int won(char arr[][3], char player)
{
    int xWon = 1;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j] == player;
        }
        if (sum == 3)
            return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[j][i] == player;
        }
        if (sum == 3)
            return 1;
    }

    if ((arr[0][0] == player && arr[1][1] == player && arr[2][2] == player) || (arr[0][2] == player && arr[1][1] == player && arr[2][0] == player))
        return 1;

    return 0;
}
int completed(char arr[][3])
{

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (arr[i][j] == ' ')
                return 0;
        }
    }

    return 1;
}

void draw(char arr[][3])
{
    system("cls");
    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            printf("%c ", arr[i][j]);
            if (j < 2)
                printf("| ");
        }
        printf("\n");
        if (i < 2)
        {
            for (int j = 0; j <= 2; j++)
                printf("___");
        }
        printf("\n");
    }
}

int main()
{

    system("cls");
    char ticTac[3][3];

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            ticTac[i][j] = ' ';
        }
    }

    char turn = 'O';

    while (1)
    {

        draw(ticTac);

        int index;
        scanf("%d", &index);
        int row = index / 3, col = index % 3 - 1;

        if (ticTac[row][col] != ' ')
            continue;

        ticTac[row][col] = turn;
        turn = (turn == 'O' ? 'X' : 'O');

        if (won(ticTac, 'X'))
        {
            draw(ticTac);
            printf("X WON!!");
            break;;
        }
        if (won(ticTac, 'O'))
        {
            draw(ticTac);
            printf("O WON!!");
            break;
        }

        if (completed(ticTac))
        {
            for (int i = 0; i <= 2; i++)
            {
                for (int j = 0; j <= 2; j++)
                {
                    ticTac[i][j] = ' ';
                }
            }
            draw(ticTac);
        }
    }

    return 0;
}
                                                                                    