#include "logic gate.cpp"

struct bit
{
    bool value;

    void set()
    {
        value = true;
    }
    void clear()
    {
        value = false;
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
        value = true; // Incrementing a bit just sets it to 1 fact check this? true because ensuring its in its max state
        return *this;
    }
    bit &operator--()
    {
        value = false; // Decrementing a bit just sets it to 0 minum state
        return *this;
    }
    operator bool() const
    {
        return value;
    }
};
