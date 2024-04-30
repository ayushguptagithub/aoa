#include&lt;stdio.h&gt;
#include&lt;string.h&gt;

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    // A loop to slide pat[] one by one
    for (int i = 0; i &lt;= N - M; i++) {
        int j;

        // For current index i, check for pattern match
        for (j = 0; j &lt; M; j++)
            if (txt[i + j] != pat[j])
                break;
        
        if (j == M) // If pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d\n", i);
    }
}

void rabinKarp(char pattern[], char text[], int q) {
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    
    for (i = 0; i &lt; m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and text
    for (i = 0; i &lt; m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i &lt;= n - m; i++) {
        if (p == t) {
            for (j = 0; j &lt; m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                printf("Pattern is found at position: %d \n", i + 1);
        }
        if (i &lt; n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t &lt; 0)
                t = (t + q);
        }
    }
}

// Driver's code
int main() {
    char txt[] = "AABAACAADAABAAABAA";
    char pat[] = "AABA";
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";
    int q = 13;

    printf("Naive Pattern Search:\n");
    search(pat, txt);

    printf("\nRabin-Karp Pattern Search:\n");
    rabinKarp(pattern, text, q);

    return 0;
}