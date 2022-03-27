inline int mod(int x) {
    x %= MOD;
    return (x < 0 ? MOD : 0) + x;
}
 
inline int mul(int a, int b) {
    return mod(mod(a) * mod(b));
}
 
int powm(int a, int b) {
    if (!b) return 1;
    int res = powm(a, b >> 1);
    res = mul(res, res);
    if (b & 1) res = mul(res, a);
    return res;
}
 
inline int divide(int a, int b) {
    return mul(a, powm(b, MOD - 2));
}
