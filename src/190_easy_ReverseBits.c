int reverseBits(int n) {
    int res = 0;
    for (int i=0; i<32; i++) {
        if ((n & (1U << i)) > 0) res |= 1U << 31-i;
    }
    return res;
}
