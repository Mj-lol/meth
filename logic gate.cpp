#include "transistors.cpp"
bool and_gate(bool input1, bool input2)
{
    // first transistor checks if input1 is true
    bool intermediate_output = npn_transistor(input1, true);

    // second transistor checks if input2 is true, using the output from the first
    return npn_transistor(input2, intermediate_output);
}

bool not_gate(bool input1)
{

    return pnp_transistor(input1, true);
}

bool or_gate(bool input1, bool input2)
{
    bool intermediate_output1 = npn_transistor(input1, true);

    bool intermediate_output2 = npn_transistor(input2, true);
    if (intermediate_output1)
    {
        return true;
    }
    else if (intermediate_output2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool nand_gate(bool input1, bool input2)
{
    bool intermediate_output = and_gate(input1, input2);

    return not_gate(intermediate_output);
}

bool nor_gate(bool input1, bool input2)
{
    bool intermediate_output = or_gate(input1, input2);

    return not_gate(intermediate_output);
}

bool xor_gate(bool input1, bool input2)
{

    // (input1 AND NOT input2) OR (NOT input1 AND input2)
    return or_gate(and_gate(input1, not_gate(input2)), and_gate(not_gate(input1), input2));
}

bool xnor_gate(bool input1, bool input2) // also the eqvgate also the xnand
{

    return not_gate(xor_gate(input1, input2));
}

bool buffer_gate(bool input1)
{

    return input1;
}

bool imp_gate(bool input1, bool input2)
{
    return not_gate(and_gate(input1, not_gate(input2))); // if input1, then input2
}
bool nimp_gate(bool input1, bool input2)
{
    return and_gate(input1, not_gate(input2)); // if input1, not input2
}
