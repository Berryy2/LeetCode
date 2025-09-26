bool isMatch(char* s, char* p) 
{
// make 2 variables storing the length of the 2 strings.
int m = strlen(s) + 1;
int n = strlen(p) + 1;   
// Start by making all the 2D array = false;
bool Dp[m][n];
for (int i = 0; i < m ; i++)
{
    for (int j = 0; j < n; j++)
    {
        Dp[i][j] = false;
    }
}
Dp[0][0] = true;
// Handling case p = "a*b*c*" and empty s "".
for(int j = 2; j < n; j++)
{   
    // row 0 column 1 -> as zero is the empty char.
    if((p[j - 1] == '*') && (Dp[0][j - 2]))
    {
        Dp[0][j] = true;
    }
}

for (int i = 1; i < m; i++)
{
    for(int j = 1; j < n; j++)
    {
        if((p[j - 1] == '.') || (s[i - 1] == p[j - 1]))
        {
        Dp[i][j] = Dp[i - 1][j - 1];
        }
        else if(p[j - 1] == '*')
        {
            Dp[i][j] = Dp[i][j - 2];
            if((p[j - 2] == '.') || (p[j - 2] == s[i - 1]))
            Dp[i][j] = (Dp[i][j]) || (Dp[i-1][j]);
        }
    }
}
//Last element of the table
return Dp[m - 1][n - 1];
}