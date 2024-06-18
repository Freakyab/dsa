// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;
// // Function to find the length of the longest common subsequence
// int lcsLength(char *X, char *Y, int m, int n) {
//     int L[m + 1][n + 1];
//     int i, j;

//     // Build the L[m+1][n+1] table in bottom-up manner
//     for (i = 0; i <= m; i++) {
//         for (j = 0; j <= n; j++) {
//             if (i == 0 || j == 0)
//                 L[i][j] = 0;
//             else if (X[i - 1] == Y[j - 1])
//                 L[i][j] = L[i - 1][j - 1] + 1;
//             else
//                 L[i][j] = max(L[i - 1][j], L[i][j - 1]);
//         }
//     }

//     // L[m][n] contains the length of LCS of X[0..m-1] & Y[0..n-1]
//     return L[m][n];
// }

// int main() {
//     char X[] = "AGGTAB";
//     char Y[] = "GXTXAYB";

//     int m = strlen(X);
//     int n = strlen(Y);

//     std::cout << "Length of LCS is " << lcsLength(X, Y, m, n) << std::endl;

//     return 0;
// }

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int lcs(char * X,char *Y,int m ,int n){
    int l[m+1][n+1];

    for(int i =0; i <=m;i++){
        for(int j =0; j<=n;j++){
            if(i == 0 || j==0)
                l[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                l[i][j] = l[i-1][j-1] +1;
            else 
                l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    }
    return l[m][n];
}

int main(){

    char X[] = "ONE";
    char Y[] = "ARYANONE";

    int m = strlen(X);
    int n = strlen(Y);

    cout << lcs(X,Y,m,n);
}