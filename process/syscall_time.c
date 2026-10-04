#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    printf("Measure system call time\n");
    
    struct timeval start, end;

    long long n = 1000000;

    gettimeofday(&start, NULL);

    for (long long i = 0; i < n; i++) {
        getpid();
    }

    gettimeofday(&end, NULL);

    long long sec = end.tv_sec - start.tv_sec;
    long long usec = end.tv_usec - start.tv_usec;

    double t = sec + (usec / 1000000.0);

    printf("Total time for %lld syscalls: %.6f seconds\n", n, t);
    printf("Avg time: %.3f nsec\n", (t / n) * 1e9);
}
