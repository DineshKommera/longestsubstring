//Author: Dinesh Reddy Kommera
//Date: 19th September, 2021
//Purpose: Program to output 2D grid of longest common substring 

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
// Function to find the longest common substring of sequences
string longestsubstring(string X, string Y, int m, int n)
{
    int maxlen = 0;         // stores the max length 
    int endIndex = m;    // stores the ending index
 
    // To store the length of substring
    int lcs[m + 1][n + 1];
    
    // initialize all cells of the lcs table to 0
    memset(lcs, 0, sizeof(lcs));
 
    // fill the lookup table in a bottom-up manner
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
 
                // update the maximum length and ending index
                if (lcs[i][j] > maxlen)
                {
                    maxlen = lcs[i][j];
                    endIndex = i;
                }
            }
        }
    }
    // return longest common substring having length
    return X.substr(endIndex - maxlen, maxlen);
}
 
int main(){
    string X = "ABAB", Y = "BABA";
    int m = X.length(), n = Y.length();
    // Find longest common substring
    cout << "The longest common substring is " << longestsubstring(X, Y, m, n);
    return 0;
}