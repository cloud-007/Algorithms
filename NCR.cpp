int fac[sz], ifac[sz],pw[sz], inv[sz];
int ncr(int n, int r) {
    if(r < 0 | r > n)
        return 0;
    return 1LL * fac[n] * ifac[r] % mod * ifac[n - r] % mod;
}
void precalc() {
    fac[0] = ifac[0] = fac[1] = ifac[1] = inv[0] = inv[1] = 1;
    for(int i = 2; i < sz; i++) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
        inv[i] = mod - 1LL * inv[mod % i] * (mod / i) % mod;
        ifac[i] = 1LL * ifac[i - 1] * inv[i] % mod;
    }
}
