#include "logic gate.cpp"

struct bit // equivalent to memory cell (should we consider )
{
    unsigned int value : 1;

    void set()
    {
        value = 1;
    }
    void clear()
    {
        value = 0;
    }
    void toggle()
    {
        value = not_gate(value);
    }

    bool get()
    {
        return value;
    }
    bit &operator=(const bit &other)
    {
        if (this != &other)
        {
            value = other.value;
        }
        return *this;
    }
    bit operator&(const bit &other) const
    {
        bit result;
        result.value = and_gate(value, other.value);
        return result;
    }

    bit operator|(const bit &other) const
    {
        bit result;
        result.value = or_gate(value, other.value);
        return result;
    }

    bit operator^(const bit &other) const
    {
        bit result;
        result.value = xor_gate(value, other.value);
        return result;
    }

    bool operator==(const bit &other) const
    {
        return xnor_gate(value, other.value);
    }
    bool operator!=(const bit &other) const
    {
        return !(*this == other); // Use the == operator and negate it
    }

    bit operator~() const
    {
        bit result;
        result.value = not_gate(value);
        return result;
    }
    bool operator!() const
    {
        return not_gate(value);
    }
    bool operator&&(const bit &other) const
    {
        return and_gate(value, other.value);
    }
    bool operator||(const bit &other) const
    {
        return or_gate(value, other.value);
    }
    bit &operator++()
    {
        value = 1; // Incrementing a bit just sets it to 1 fact check this? 1 because ensuring its in its max state
        return *this;
    }
    bit &operator--()
    {
        value = 0; // Decrementing a bit just sets it to 0 minum state
        return *this;
    }
    operator bool() const
    {
        return value;
    }
};

struct byte
{
    bit b0;
    bit b1;
    bit b2;
    bit b3;
    bit b4;
    bit b5;
    bit b6;
    bit b7;
};
