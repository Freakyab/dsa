#include <stdio.h>
#include <string.h>

char chessBoard[8][8] = {
    {'R', 'H', 'B', 'K', 'Q', 'B', 'H', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'h', 'b', 'k', 'q', 'b', 'h', 'r'}};
int check(int, int);
int change(int, int,int);
int pawn(int,int);

int display()
{
    for(int i=-1;i<8;i++){
        for(int j=-1;j<8;j++){
            if(i == -1 )
            {
                printf("   %d",j+1);
                continue;
            }
            if(j == -1)
            {
                printf("%d ",i);
                continue;
            }
            printf("|%c| ",chessBoard[i][j]);
        }
        printf("\n");
    }
}

int move(int x, int i)
{
    display();
    int r,c,checkRes;
    printf("Enter the position of the piece you want to move: ");
    scanf("%d %d",&r,&c);
    checkRes = check(r,c);
    if(checkRes == 1)
    {
        change(r,c,i);
    }
}
int check(int r,int c)
{
    printf("%c\n",chessBoard[r][c]);
    if(chessBoard[r][c] == ' ')
    {
        printf("No piece at this position");
        return 0;
    }
    else
    {
        return 1;
    }
}
int pawn(int x,int i)
{
    if(i == 1)
    {
        return 2;
    }
    else{
        return 1;
    }
}
int change(int r, int c ,int i)
{
    int posibleMoves,atwhere;

    if(chessBoard[r][c]=='P')
       posibleMoves =  pawn(1,i);
    else if(chessBoard[r][c]=='p')
        posibleMoves= pawn(0,i);
    if(posibleMoves == 2)
    {
        printf("Available moves: \n");
        printf("1. %d %d\n",r+1,c);
        printf("2. %d %d\n",r+2,c);
        printf("Enter the position where you want to move: ");
        scanf("%d",&atwhere);
        if(atwhere == 1)
        {
            chessBoard[r+1][c] = chessBoard[r][c];
            chessBoard[r][c] = ' ';
        }
        else if(atwhere == 2)
        {
            chessBoard[r+2][c] = chessBoard[r][c];
            chessBoard[r][c] = ' ';
        }
        else
        {
            printf("Invalid move");
        }
        
    }
}
int main()
{
    int i = 1;
    move(0, i);
    return 0;
}
