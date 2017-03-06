#include <cstdio>
#include <cstring>

const int Max = 60; 
bool exists[Max]; 

int main()
{
        int s,d,i = 0;
        while (scanf("%d %d", &s, &d) != EOF) {
                if (!s && !d) break;
                if (s == 0) printf("0\n");
                else if (d == 0) printf("Impossible\n");
                else {
                	i = 0;
                    memset(exists, 0, sizeof(exists));
                    while (true) {
                    		++i; 
                            exists[s] = true;
                            s = s*(d+1)%60;
                            if (!s) {
                                    printf("%d\n", i);
                                    break;
                            } 
                            if (exists[s]) {
                                    printf("Impossible\n"); 
                                    break;
                            }
                    }
                } 
        }
        return 0;
}
