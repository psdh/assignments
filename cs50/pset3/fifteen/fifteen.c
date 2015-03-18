/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements the Game of Fifteen (generalized to d x d).
 *
 * Usage: ./fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [MIN,MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// board's minimal dimension
#define MIN 3

// board's maximal dimension
#define MAX 9

// board, whereby board[i][j] represents row i and column j
int board[MAX][MAX];

// board's dimension
int dim;

int x, y ;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
void save(void);

int main(int argc, string argv[])
{
    // greet player
    greet();

    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    dim = atoi(argv[1]);
    if (dim < MIN || dim > MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            MIN, MIN, MAX, MAX);
        return 2;
    }

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // saves the current state of the board (for testing)
        save();

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep for animation's sake
        usleep(500000);
    }

    // that's all folks
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1,
 * (i.e., fills board with values but does not actually print them),
 * whereby board[i][j] represents row i and column j.
 */
void init(void)
{
    int i;
    int k = dim * dim - 1; 
    for(i = 0; i < dim ; i++)
    {
        for( int j = 0 ; j < dim; j++)
        {
            board[i][j] = k--;
        } 
    }
    if ( dim % 2 == 0 )
    {
        board[dim - 1][dim - 2] = 2; 
        board[dim - 1][dim - 3] = 1; 
    }
    x = dim - 1;
    y = dim - 1;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // showing the matrix on console output using printf
    for(int i = 0; i < dim ; i++)
    {
        for(int j = 0 ; j < dim ; j++)
        {
            if (board[i][j] == 0 )
            {
                printf("_   ");
                continue;
            }
            printf("%d   ", board[i][j]);
        
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    if ( x + 1 < dim && board[x + 1][y] == tile)
    {
        int temp = board[x + 1][y];
        board[x + 1][y] = 0;
        board[x][y] = temp ;
        x++;
        return true;
    }
    else
    if ( y + 1 < dim && board[x][y + 1] == tile)
    {
        int temp = board[x][y + 1];
        board[x][y + 1] = 0;
        board[x][y] = temp ;
        y++;
        return true;
    }
    else
    if ( x - 1 >= 0 && board[x - 1][y] == tile)
    {
        int temp = board[x - 1][y];
        board[x - 1][y] = 0;
        board[x][y] = temp ;
        x--;
        return true;
    }
    else
    if ( y - 1 >= 0 && board[x][y - 1] == tile)
    {
        int temp = board[x][y - 1];
        board[x][y - 1] = 0;
        board[x][y] = temp ;
        y--;
        return true;   
    }
    else 
        return false; 
    
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    // TODO
    
    for(int i = 0 ; i < dim ; i++)
    {
        for( int j = 0 ; j < dim ; j++)
        {
            if (i == dim - 1 && j == dim - 1)
            {
                continue;
            }
            else
            if ( !( board[i][j] == i * dim + j + 1))
            {
                return false;
            }
        }
    }    
     
    return true;
}

/**
 * Saves the current state of the board to disk (for testing).
 */
void save(void)
{
    // log
    const string log = "log.txt";

    // delete existing log, if any, before first save
    static bool saved = false;
    if (!saved)
    {
        unlink(log);
        saved = true;
    }

    // open log
    FILE* p = fopen(log, "a");
    if (p == NULL)
    {
        return;
    }

    // log board
    fprintf(p, "{");
    for (int i = 0; i < dim; i++)
    {
        fprintf(p, "{");
        for (int j = 0; j < dim; j++)
        {
            fprintf(p, "%i", board[i][j]);
            if (j < dim - 1)
            {
                fprintf(p, ",");
            }
        }
        fprintf(p, "}");
        if (i < dim - 1)
        {
            fprintf(p, ",");
        }
    }
    fprintf(p, "}\n");

    // close log
    fclose(p);
}
