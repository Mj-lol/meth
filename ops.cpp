#include "logic gate.cpp"

bool half_adder_sum(bool input1, bool input2)
{
    return xor_gate(input1, input2); // sum = xor of the two
}

bool half_adder_carry(bool input1, bool input2)
{
    return and_gate(input1, input2); // carry is the and
}

bool full_adder_sum(bool input1, bool input2, bool carry_in)
{
    bool sum1 = half_adder_sum(input1, input2);
    return half_adder_sum(sum1, carry_in);
}

bool full_adder_carry(bool input1, bool input2, bool carry_in)
{
    bool carry1 = half_adder_carry(input1, input2);
    bool sum1 = half_adder_sum(input1, input2);
    bool carry2 = half_adder_carry(sum1, carry_in);
    return or_gate(carry1, carry2);
}
