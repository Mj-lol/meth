int addition(int a, int b)
{
    while (b != 0)
    {
        int carry = a & b; // Calculate carry bits
        a = a ^ b;         // Sum bits without carry
        b = carry << 1;    // Shift carry to left by one place
    }
    return a;
}
int subtraction(int a, int b)
{
    while (b != 0)
    {
        // Borrow contains common set bits of a and b
        int borrow = (~a) & b; // Where we need to borrow
        // Subtraction without borrow
        a = a ^ b;
        // Borrow is shifted by 1 so that it can be subtracted from the next higher bit
        b = borrow << 1;
    }
    return a;
}
int twos_subtract(int a, int b)
{
    // Subtract by adding two's complement of b
    return addition(a, addition(~b, 1));
}
int twos_addition(int a, int b)
{
    return subtraction(a, subtraction(~b, 1));
}
