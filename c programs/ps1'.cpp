#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<string> strings(n);

    getchar(); // Consume newline after number input
    for (int i = 0; i < n; i++) {
        char buffer[20];
        fgets(buffer, 20, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove newline
        strings[i] = buffer;
    }

    set<string> uniqueStrings(strings.begin(), strings.end());
    printf("%d\n", uniqueStrings.size());

    return 0;
}
