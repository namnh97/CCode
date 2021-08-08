long long modInverse(long long b, long long m) {
    long long res = modularExponentiation(b, m - 2, m);
    if (res * b % m == 1)
        return res;
    return -1;
}