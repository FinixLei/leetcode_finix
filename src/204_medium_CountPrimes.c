int countPrimes(int n) {
    if (n <= 2) return 0;

    int * flags = (int *) malloc (sizeof(int) * n);
    flags[0] = flags[1] = false;

    for (int i=2; i<n; i++) {
        flags[i] = true;
    }

    int h = (int) sqrt(n);
    for (int i=2; i<=h; i++) {
        for (int j=i*i; j<n; j+=i) {
            flags[j] = false;
        }
    }

    int count = 0;
    for (int i=0; i<n; i++) {
        if (flags[i]) count ++;
    }
    return count;
}
