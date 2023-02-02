namespace FJ::Math
{
    template <typename T>
    T GCD(T const &a, T const &b)
    {
        T r, rp, temp;
        (a > b) ? (r = a % b, rp = b % r) : (r = b % a, rp = a % r);
        while (rp != 0)
            temp = rp, rp = r % rp, r = temp;
        return r;
    }
}