#include<bits/stdc++.h>
using namespace std;

// given two numbers abcde and fghij where a,b,c,d,e,f,g,h,i,j are the combination of 0-9 digits and so we have to find abcde/fghij = n, where n <= 80, find all such combination of abcde, fghij such that it satisfy the above equation. 

int solve(){
    long long sum = 0; 
    // O(10^6 - 10^7 tak not tle)
    for(int n = 1; n <= 80; n++){
        for (int fghij = 1234; fghij <= 98765; fghij++)
        {
            int abcde = fghij * n;
            set<int> s;
            while (abcde){
                s.push(abcde % 10);
                abcde /= 10;
            }
            int j = fghij;
            while (j)
            {
                s.push(j % 10);
                j /= 10;
            }
            if(s.size() == 10){
                sum++;
            }
            else if(s.size() == 9 and s.find(0) == s.end()){
                sum++;
            }
        }
    }
    cout << sum << endl;
}


// Recursive brute force 
// N Queens, you have N queens, find the number of ways you can place the queen such that, they so not cross each other(affect each other), as queen can move in all the four diagonals and four sides,

int n, ans = 0;
// placed store the current position which are safe to place queen. 
vector<int> placed;

// position is used to store the all possible position array which are safe to keep the queens. 
vector<vector<int>> positions;
void n_queen(int row){
    // if we reach the nth row that means we have successfully found all the positions. 
    if(row == n){
        ans++;
        positions.push_back(placed);
        return;
    }

    // we are looping over all the columns to check which columns are safe tp keep 
    for (int col = 0; col < n; col++){
        // assuming this is safe 
        bool safe = true;
        // now as we have store in placed the column values where we have kept the queens till now, i.e placed has size row. 
        for (int pRow = 0; pRow < row; pRow++){
            // now storing the ith row column value, 
            int pCol = placed[pRow];
            // and checking whether the current row is same as the current col, aur they are in diagonal positions. 
            if(col == pCol || abs(pRow - row) == abs(pCol - col)){
                safe = false;
                break;
            }
        }
        // if the column is safe then we move forward to the next row and store the column in placed. 
        if(safe){
            placed.push_back(col);
            n_queen(row + 1);
            placed.pop_back();
        }
    }
}

int solve_n_queens(){
    cin >> n;
    n_queen(0);
    return ans;
}

// Given a chocolate of m * n pieces and and we have to break it down to k pieces which are square and the cost of cutting the chocolate is equal to square of the side it is breaking from, we need to find the minimum cost possible in order to break the chocolate and note that we can throw the extra pieces.  

// using dp to reduce the result
long long dp[101][101][105];
long long find_min_cost(int n, int m, int needed){
    if(dp[n][m][needed] != -1)
        return dp[n][m][needed];
    if(needed == 0)
        return 0;
    if(n*m < needed){
        // not possible to generate k chocolate
        return 1e15;
    }
    if(n == m and needed == 1){
        return 0;
    }
    long long ans = 1e15;
    // for finding all the combination with the rows, 
    for (int i = 1; i < n; i++){
        for (int k = 0; k <= needed; k++){
            ans = min(ans, min((find_min_cost(i, m, k) + find_min_cost(n - i, m, needed - k) + m * m),( find_min_cost(i, m, needed - k) + find_min_cost(n - i, m, k) + m * m)));
        }
    }

    // for finding all the combination with columns
    for (int i = 1; i < m; i++)
    {
        for (int k = 0; k <= needed; k++)
        {
            ans = min(ans, min((find_min_cost(n, i, k) + find_min_cost(n, m - i, needed - k) + n*n), (find_min_cost(n, m - i, needed - k) + find_min_cost(n, i, k) + n * n)));
        }
    }
    return dp[n][m][needed] = ans;
}

void solve_chocolate(){
    memset(dp, -1, sizeof(dp));
    int n, m, k;
    cin >> n >> m >> k;
    cout << find_min_cost(n, m, k) << endl;
}

// 8 Sided Matrix with some place reserved and we have tp place queens in such a way that they do not attack each other.
// Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

// How many possible ways are there to place the queens ?

int ans_ = 0;
vector<int> placed_;

void solve_chess(vector<vector<char>> &chess, int row){
    if(row == 8){
        ans++;
        return;
    }
    for (int col = 0; col < 8; col++){
        if(chess[row][col] != '*'){
            bool safe = true;
            for (int pRow = 0; pRow < row; pRow++){
                int pCol = placed_[pRow];
                if(pCol == col || abs(pCol - col) == abs(pRow - row)){
                    safe = false;
                    break;
                }
            }
            if(safe){
                placed_.push_back(col);
                solve_chess(chess, row + 1);
                placed_.pop_back();
            }
        }
    }
}

void solve(){
    vector<vector<char>> chess(8, vector<char>(8, ''));
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> chess[i][j];
        }
    }
    // so we have chess
    solve_chess(chess, 0);
    cout << ans << endl;
}


// Their Solution
int ans1 = 0;
bool takencols[8], takendiag1[16], takendiag2[16];

void place(string board[8], int r, int &ans)
{
    if (r == 8)
    {
        ans1++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {
        if (board[r][c] == '.')
        {
            if (!takencols[c] && !takendiag1[r - c + 8 - 1] && !takendiag2[r + c])
            {
                takencols[c] = takendiag1[r - c + 8 - 1] = takendiag2[r + c] = true;
                place(board, r + 1, ans1);
                takencols[c] = takendiag1[r - c + 8 - 1] = takendiag2[r + c] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    string board[8];
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> board[i];
    }
    place(board, 0, ans1);
    cout << ans1;
    return 0;
}



// Cyclic Prime - given n first numbers find the number of permutation of the numbers such that the consecutive numbers are prime and  along with first and last elements 

const int N = 100;

ll ans = 0;
bool isPrime[N];
bool marked[N];
vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

void solve(int m, int n, int prev, int par)
{
    if (!m)
    {
        if (isPrime[prev + 1])
        {
            ans++;
        }
        return;
    }
    for (int i = 1 + par; i <= n; i++)
    {
        if (!marked[i] && isPrime[i + prev])
        {
            marked[i] = true;
            solve(m - 1, n, i, 1 - par);
            marked[i] = false;
        }
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    if (n % 2 == 1)
    {
        cout << "0\n";
        return 0;
    }

    memset(isPrime, false, sizeof(isPrime));
    memset(marked, false, sizeof(marked));

    for (int u : prime)
    {
        isPrime[u] = true;
    }

    marked[1] = true;
    solve(n - 1, n, 1, 1);

    cout << ans << "\n";
}


// Place N S-Queen, such that the queen has the power of the knight and queen, i.e it can kill at 2.5 steps also
int ans2 = 0;
vector<int> Placed;


void solve_squeen(int row, int n){
    if(row == n){
        ans++;
        return; 
    }
    for (int col = 0; col < n; col++){
        bool safe = true;
        for (int pRow = 0; pRow < row; pRow++){
            int pCol = Placed[pRow];
            if(pCol == col || abs(pCol - col) == abs(pRow - row)){
                safe = false;
                break;
            }
            else if((pRow + 1) < n && (pCol - 2) >= 0 && (pRow + 1 == row && pCol - 2 == col)){
                safe = false;
                break;
            }
            else if ((pRow + 1) < n && (pCol + 2) < 0 && (pRow + 1 == row && pCol + 2 == col))
            {
                safe = false;
                break;
            }
            else if ((pRow + 2) < n && (pCol + 1) < n && (pRow + 2 == row && pCol + 1 == col))
            {
                safe = false;
                break;
            }
        }
        if(safe){
            Placed.push_back(col);
            solve(row + 1);
            Placed.pop_back();
        }
    }
}

void solve(){
    ans2 = 0;
    int n; 
    cin >> n;
    solve_squeen(0, n);
    cout << ans << endl;
}