#include <bits/stdc++.h>
#include <iostream>
#include <direct.h>
#include <unistd.h>
#include <climits>
#include <windows.h>
#include <fcntl.h>
#include <io.h>
#include <set>
#include <queue>

#define N 8
using namespace std;

/* ------------------------------------------------------------- GAME -------------------------------------------------------------*/


int Side;
int Mine;
pair<int, int> inputcoordinate()
{
    int x;
    int y;
    cout << "Enter your move " << endl;
    cin >> x >> y;
    pair<int, int> p;
    p.first = x;
    p.second = y;
    return p;
}
bool checkPossible(pair<int, int> prev, pair<int, int> p)
{
    int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    int diffx = prev.first - p.first;
    int diffy = prev.second - p.second;

    for (int i = 0; i < 8; i++)
    {
        if (diffx == x[i] && diffy == y[i])
        {
            return true;
        }
    }
    return false;
}

bool checkValid(int row, int col)
{
    if ((row >= 0) && (row < Side) && (col >= 0) && (col < Side))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkMine(int row, int col, char **realboard)
{
    if (realboard[row][col] == '*')
    {
        return (true);
    }
    else
    {
        return (false);
    }
}

void displayBoard(char **playBoard)
{
    int i, j;
    cout << "\t\t\t\t\t";
    cout << "      ";
    for (i = 0; i < Side; i++)
    {
        if (i < 10)
        {
            cout << i << "     ";
        }
        else
        {
            cout << i << "    ";
        }
    }
    cout << endl;
    for (i = 0; i < Side; i++)
    {
        if (i < 10)
        {
            cout << "\t\t\t\t\t"
                 << " ";
        }
        else
        {
            cout << "\t\t\t\t\t";
        }
        cout << i << "   ";
        for (j = 0; j < Side; j++)
        {
            if (playBoard[i][j] == 0)
            {
                cout << "|♘|   ";
            }
            else
                cout << "|" << playBoard[i][j] << "|   ";
        }
        cout << endl;
    }
    return;
}

int countMines(int row, int col, int **minesloc, char **realBoard)
{
    int counter = 0;
    if (checkValid(row + 2, col + 1) == true)
    {
        if (checkMine(row + 2, col + 1, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row + 1, col + 2) == true)
    {
        if (checkMine(row + 1, col + 2, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row - 1, col + 2) == true)
    {
        if (checkMine(row - 1, col + 2, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row - 2, col + 1) == true)
    {
        if (checkMine(row - 2, col + 1, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row - 2, col - 1) == true)
    {
        if (checkMine(row - 2, col - 1, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row - 1, col - 2) == true)
    {
        if (checkMine(row - 1, col - 2, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row + 1, col - 2) == true)
    {
        if (checkMine(row + 1, col - 2, realBoard) == true)
        {
            counter++;
        }
    }
    if (checkValid(row + 2, col - 1) == true)
    {
        if (checkMine(row + 2, col - 1, realBoard) == true)
        {
            counter++;
        }
    }
    return counter;
}

bool playknight(char **realBoard, char **playBoard, int row, int col, int **minesloc, int *movesleft)
{
    if (playBoard[row][col] != '-')
    {
        return false;
    }
    int i;
    int j;
    if (realBoard[row][col] == '*')
    {
        playBoard[row][col] = '*';

        for (i = 0; i < Mine; i++)
        {
            playBoard[minesloc[i][0]][minesloc[i][1]] = '*';
        }
        displayBoard(playBoard);
        cout << "You lost! " << endl;
        return true;
    }
    else
    {
        int c = countMines(row, col, minesloc, realBoard);
        (*movesleft)--;

        playBoard[row][col] = c + '0';

        if (!c)
        {
            if (checkValid(row - 1, col) == true)
            {
                if (checkMine(row - 1, col, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row - 1, col, minesloc, movesleft);
                }
            }

            if (checkValid(row + 1, col) == true)
            {
                if (checkMine(row + 1, col, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row + 1, col, minesloc, movesleft);
                }
            }
            if (checkValid(row, col + 1) == true)
            {
                if (checkMine(row, col + 1, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row, col + 1, minesloc, movesleft);
                }
            }
            if (checkValid(row, col - 1) == true)
            {
                if (checkMine(row, col - 1, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row, col - 1, minesloc, movesleft);
                }
            }
            if (checkValid(row - 1, col + 1) == true)
            {
                if (checkMine(row - 1, col + 1, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row - 1, col + 1, minesloc, movesleft);
                }
            }
            if (checkValid(row - 1, col - 1) == true)
            {
                if (checkMine(row - 1, col - 1, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row - 1, col - 1, minesloc, movesleft);
                }
            }
            if (checkValid(row + 1, col + 1) == true)
            {
                if (checkMine(row + 1, col + 1, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row + 1, col + 1, minesloc, movesleft);
                }
            }
            if (checkValid(row + 1, col - 1) == true)
            {
                if (checkMine(row + 1, col - 1, realBoard) == false)
                {
                    playknight(realBoard, playBoard, row + 1, col - 1, minesloc, movesleft);
                }
            }
        }
        return false;
    }
}

void placeMines(int **minesloc, char **realBoard)
{
    bool mark[Side * Side];
    memset(mark, false, sizeof(mark));

    for (int i = 0; i < Mine;)
    {
        int random = rand() % (Side * Side);
        int x = random / Side;
        int y = random % Side;
        if (!((x == 0 && y == 0) || (x == Side - 1 && y == Side - 1)))
            if (mark[random] == false)
            {
                minesloc[i][0] = x;
                minesloc[i][1] = y;
                realBoard[minesloc[i][0]][minesloc[i][1]] = '*';
                mark[random] = true;
                i++;
            }
    }
    return;
}

void replaceMine(int row, int col, char **realboard)
{
    for (int i = 0; i < Side; i++)
    {
        for (int j = 0; j < Side; j++)
        {
            if (realboard[i][j] != '*')
            {
                realboard[i][j] = '*';
                realboard[row][col] = '-';
                return;
            }
        }
    }
    return;
}

void initialise(char **realBoard, char **playBoard)
{
    srand(time(NULL));
    for (int i = 0; i < Side; i++)
    {
        for (int j = 0; j < Side; j++)
        {
            playBoard[i][j] = '-';
            realBoard[i][j] = '-';
        }
    }
    return;
}

pair<int, int> checkKnightMove(pair<int, int> prev, pair<int, int> p)
{
    if (checkValid(p.first, p.second), checkPossible(prev, p))
    {
        return p;
    }
    else
    {
        cout << "Wrong input try again . the knight cannot move here" << endl;
        p = inputcoordinate();
        p = checkKnightMove(prev, p);
    }
    return p;
}

void playKnightSweeper()
{
    bool gameOver = false;
    char **realBoard = new char *[Side];

    for (int i = 0; i < Side; i++)
    {
        realBoard[i] = new char[Side];
    }
    char **playBoard = new char *[Side];
    for (int i = 0; i < Side; i++)
    {
        playBoard[i] = new char[Side];
    }

    int totalMoves = (Side * Side) - Mine;
    int **minesloc = new int *[Mine];
    for (int i = 0; i < Mine; i++)
    {
        minesloc[i] = new int[2];
    }
    initialise(realBoard, playBoard);
    placeMines(minesloc, realBoard);

    int movesleft = Side * Side - Mine;
    int currentmovecount = 0;

    pair<int, int> prev;

    while (gameOver == false)
    {
        if (currentmovecount == 0)
        {
            prev.first = 0;
            prev.first = 0;
            currentmovecount++;
            continue;
        }
        cout << "Current Status of Board :" << endl;
        displayBoard(playBoard);
        pair<int, int> p;
        p = inputcoordinate();
        p = checkKnightMove(prev, p);
        currentmovecount++;
        prev.first = p.first;
        prev.second = p.second;
        gameOver = playknight(realBoard, playBoard, p.first, p.second, minesloc, &movesleft);
        if ((gameOver == false) && (movesleft == 0))
        {
            cout << "you won " << (Side * Side - Mine) - movesleft << endl;
            gameOver = true;
        }
    }
    for (int i = 0; i < Side; i++)
    {
        delete[] realBoard[i];
    }
    delete realBoard;
    for (int i = 0; i < Side; i++)
    {
        delete[] playBoard[i];
    }
    delete playBoard;
    return;
}

void chooseLevel()
{
    int ch;
    cout << "\n\nENTER THE DIFFICULTY LEVEL YOU WISH TO PLAY" << endl;
    cout << "Press 0 for BEGINNER (8 * 8 Cells and 10 Mines)" << endl;
    cout << "Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)" << endl;
    cout << "Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)" << endl;
    cin >> ch;
    if (ch == 0)
    {
        cout << "BEGINNER LEVEL SELECTED" << endl;
        Side = 8;
        Mine = 10;
    }
    if (ch == 1)
    {
        cout << "INTERMEDIATE LEVEL SELECTED" << endl;
        Side = 16;
        Mine = 40;
    }
    if (ch == 2)
    {
        cout << "ADVANCED LEVEL SELECTED" << endl;
        Side = 24;
        Mine = 99;
    }
    sleep(1);
    return;
}

/*-------------------------------------------------------------  ALL SQUARES --------------------------------------------------*/

static int cx[N] = {1, 1, 2, 2, -1, -1, -2, -2};
static int cy[N] = {2, -2, 1, -1, 2, -2, 1, -1};

bool limits(int x, int y)
{
    return ((x >= 0 && y >= 0) && (x < N && y < N));
}

bool isempty(int a[], int x, int y)
{
    return (limits(x, y)) && (a[y * N + x] < 0);
}

int getDegree(int a[], int x, int y)
{
    int count = 0;
    for (int i = 0; i < N; ++i)
        if (isempty(a, (x + cx[i]), (y + cy[i])))
            count++;

    return count;
}

bool nextMove(int a[], int *x, int *y)
{
    int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

    int start = rand() % N;
    for (int count = 0; count < N; ++count)
    {
        int i = (start + count) % N;
        nx = *x + cx[i];
        ny = *y + cy[i];
        if ((isempty(a, nx, ny)) &&
            (c = getDegree(a, nx, ny)) < min_deg)
        {
            min_deg_idx = i;
            min_deg = c;
        }
    }

    if (min_deg_idx == -1)
        return false;

    nx = *x + cx[min_deg_idx];
    ny = *y + cy[min_deg_idx];

    a[ny * N + nx] = a[(*y) * N + (*x)] + 1;

    *x = nx;
    *y = ny;

    return true;
}

void print(int a[])
{
    int **board = new int *[N];
    for (int i = 0; i < N; ++i)
    {
        board[i] = new int[N];
        for (int j = 0; j < N; ++j)
        {
            board[i][j] = a[j * N + i];
        }
    }
    int z = 0;
    while (z <= N * N + 1)
    {
        system("CLS");
        for (int x = 0; x < N; x++)
        {
            for (int y = 0; y < N; y++)
            {
                if (z > board[x][y])
                {
                    cout << setw(2) << board[x][y] << " ";
                }
                else if (z == board[x][y])
                {
                    if (((x % 2 == 0) && (y % 2 == 0)) || ((x % 2 != 0) && (y % 2 != 0)))
                    {
                        printf(" ♘ ");
                    }
                    else
                    {
                        printf(" ♞ ");
                    }
                }
                else
                {
                    if (((x % 2 == 0) && (y % 2 == 0)) || ((x % 2 != 0) && (y % 2 != 0)))
                    {
                        printf(" ◻ ");
                    }
                    else
                    {
                        printf(" ◼ ");
                    }
                }
            }
            cout << endl;
        }
        sleep(1);
        z++;
    }
}

bool neighbour(int x, int y, int xx, int yy)
{
    for (int i = 0; i < N; ++i)
        if (((x + cx[i]) == xx) && ((y + cy[i]) == yy))
            return true;

    return false;
}

bool findClosedTour(int sx, int sy)
{

    int a[N * N];
    for (int i = 0; i < N * N; ++i)
        a[i] = -1;
    int x = sx, y = sy;
    a[y * N + x] = 1;

    for (int i = 0; i < N * N - 1; ++i)
        if (nextMove(a, &x, &y) == 0)
            return false;
    if (!neighbour(x, y, sx, sy))
        return false;

    print(a);
    return true;
}

void all_squares()
{
    int sx; 
    int sy; 
    cout << "\n\nEnter the position of the knight\nx-coordinate: ";
    cin >> sx;
    cout << "y-coordinate: ";
    cin >> sy;
    srand(time(NULL));
    while (!findClosedTour(sx, sy))
    {
        ;
    }
}

/*------------------------------------------------------ n-knights --------------------------------------------------------*/

int m, n, k;
int c = 0;

void makeBoard(char **board)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '_';
        }
    }
}

void displayBoardunder(char **board)
{
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 'K')
            {
                if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0)))
                {
                    printf(" ♘ ");
                }
                else
                {
                    printf(" ♞ ");
                }
            }
            else
            {
                if (((i % 2 == 0) && (j % 2 == 0)) || ((i % 2 != 0) && (j % 2 != 0)))
                {
                    printf(" ◻ ");
                }
                else
                {
                    printf(" ◼ ");
                }
            }
        }
        cout << endl;
    }
}

void attack(int i, int j, char a, char **board)
{
    if ((i + 2) < m && (j - 1) >= 0)
    {
        board[i + 2][j - 1] = a;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0)
    {
        board[i - 2][j - 1] = a;
    }
    if ((i + 2) < m && (j + 1) < n)
    {
        board[i + 2][j + 1] = a;
    }
    if ((i - 2) >= 0 && (j + 1) < n)
    {
        board[i - 2][j + 1] = a;
    }
    if ((i + 1) < m && (j + 2) < n)
    {
        board[i + 1][j + 2] = a;
    }
    if ((i - 1) >= 0 && (j + 2) < n)
    {
        board[i - 1][j + 2] = a;
    }
    if ((i + 1) < m && (j - 2) >= 0)
    {
        board[i + 1][j - 2] = a;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0)
    {
        board[i - 1][j - 2] = a;
    }
}

bool canPlace(int i, int j, char **board)
{
    if (board[i][j] == '_')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void place(int i, int j, char k, char a, char **board, char **new_board)
{
    for (int y = 0; y < m; y++)
    {
        for (int z = 0; z < n; z++)
        {
            new_board[y][z] = board[y][z];
        }
    }

    new_board[i][j] = k;
    attack(i, j, a, new_board);
}

void kkn(int k, int sti, int stj, char **board)
{
    if (k == 0)
    {
        displayBoardunder(board);
        c++;
    }
    else
    {
        for (int i = sti; i < m; i++)
        {
            for (int j = stj; j < n; j++)
            {
                if (canPlace(i, j, board))
                {
                    char **new_board = new char *[m];
                    for (int x = 0; x < m; x++)
                    {
                        new_board[x] = new char[n];
                    }
                    place(i, j, 'K', 'A', board, new_board);

                    kkn(k - 1, i, j, new_board);

                    for (int x = 0; x < m; x++)
                    {
                        delete[] new_board[x];
                    }
                    delete[] new_board;
                }
            }
            stj = 0;
        }
    }
}

int kknn(int k, int sti, int stj, char **board, int c0)
{
    if (k == 0)
    {
        c0++;
    }
    else
    {
        for (int i = sti; i < m; i++)
        {
            for (int j = stj; j < n; j++)
            {
                if (canPlace(i, j, board))
                {
                    char **new_board = new char *[m];

                    for (int x = 0; x < m; x++)
                    {
                        new_board[x] = new char[n];
                    }

                    place(i, j, 'K', 'A', board, new_board);

                    c0 = kknn(k - 1, i, j, new_board, c0);
                    for (int x = 0; x < m; x++)
                    {
                        delete[] new_board[x];
                    }
                    delete[] new_board;
                }
            }
            stj = 0;
        }
    }
    return c0;
}

void k_knights()
{
    cout << "\n\nENTER THE SIZE OF GRID:\nx-coordinate: ";
    cin >> m;
    cout << "y-coordinate: ";
    cin >> n;
    char **board = new char *[m];
    for (int i = 0; i < m; i++)
    {
        board[i] = new char[n];
    }
    makeBoard(board);
    int k1 = m * n;
    int l = 0;
    int r = k1;
    int ans = INT_MIN;
    int c0 = 0;
    if (k1 > 50)
    {
        ans = (k1 / 2) + 1;
    }
    else
    {
        while (l <= r)
        {
            int mid = l + ((r - l) / 2);
            c0 = 0;
            c0 = kknn(mid, 0, 0, board, c0);
            if (c0 > 0)
            {
                ans = mid;
                l = mid + 1;
            }
            else if (c0 <= 0)
            {
                r = mid - 1;
            }
        }
    }
    cout << "\nMaximum number of knights possible = " << ans << endl;
    cout << "\nEnter the number of knights: ";
    cin >> k;
    if (k > ans)
    {
        cout << "\nSolution not possible. Max " << ans << " knights can be placed such that they are not under attack.\n";
        kkn(ans, 0, 0, board);
    }
    else
    {
        kkn(k, 0, 0, board);
    }
    cout << endl;
    cout << "TOTAL NUMBER OF SOLUTIONS : " << c << endl
         << endl;
}

/*-------------------------------------------------- A TO B -----------------------------------------------------------------*/

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool isValid(int x, int y, int M)
{
    return (x >= 0 && x < M) && (y >= 0 && y < M);
}

struct Node
{
    int x, y, dist;
    Node(int x, int y, int dist = 0) : x(x), y(y), dist(dist) {}
    bool operator<(const Node &o) const
    {
        return x < o.x || (x == o.x && y < o.y);
    }
};

int findShortestDistance(int M, Node src, Node dest)
{
    set<Node> visited;
    queue<Node> q;
    q.push(src);
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();

        int x = node.x;
        int y = node.y;
        int dist = node.dist;
        if (x == dest.x && y == dest.y)
        {
            return dist;
        }
        if (!visited.count(node))
        {
            visited.insert(node);
            for (int i = 0; i < 8; i++)
            {
                int x1 = x + row[i];
                int y1 = y + col[i];

                if (isValid(x1, y1, N))
                {
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }
    return INT_MAX;
}

void a_to_b()
{
    int M = 8;
    int x, y, tx, ty;
    cout << "\n\nEnter Source of Knight: ";
    cin >> x >> y;
    cout << "Enter destination: ";
    cin >> tx >> ty;
    Node src = {x, y};
    Node dest = {tx, ty};

    cout << "\n\nThe minimum number of steps required is " << findShortestDistance(N, src, dest);
}


/*--------------------------------------------------- MAIN -----------------------------------------------------------------*/

void knightstourgame()
{
    cout << "\n\n\t\t\t************** THE KNIGHT'S TOUR PROBLEM **************\t\t\t\n\n"
         << endl;
    cout << "1 - ALL SQUARES" << endl;
    cout << "2 - KNIGHTSWEEPER GAME" << endl;
    cout << "3 - N-KNIGHTS PROBLEM" << endl;
    cout << "4 - FROM A TO B IN MIN STEPS" << endl;
    cout << "\nEnter your choice_";
    int t;
    cin >> t;
    if (t == 1)
    {
        all_squares();
    }
    else if (t == 2)
    {
        chooseLevel();
        playKnightSweeper();
    }
    else if (t == 3)
    {
        k_knights();
    }
    else if (t == 4)
    {
        a_to_b();
    }
    else
    {
        cout << " WRONG CHOICE PLEASE SELECT AGAIN " << endl;
        knightstourgame();
    }
}

int main()
{
    SetConsoleOutputCP(65001);
    char c = 'y';
    while (c == 'y')
    {
        system("CLS");
        knightstourgame();
        cout << "\n\nEnter 0 to exit, 1 to continue...";
        cin >> c;
        if (c == '0')
            return 0;
        else
            c = 'y';
    }
    return 0;
}