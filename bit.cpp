#include "logic gate.cpp"
#include "iostream"
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

union byte
{
    struct
    {
        unsigned int b0 : 1;
        unsigned int b1 : 1;
        unsigned int b2 : 1;
        unsigned int b3 : 1;
        unsigned int b4 : 1;
        unsigned int b5 : 1;
        unsigned int b6 : 1;
        unsigned int b7 : 1;
    };
    unsigned char value;

    void setBit(int index, bool state)
    {
        if (index < 0 || index > 7)
            throw std::out_of_range("Bit index out of range");
        switch (index)
        {
        case 0:
            b0 = state;
            break;
        case 1:
            b1 = state;
            break;
        case 2:
            b2 = state;
            break;
        case 3:
            b3 = state;
            break;
        case 4:
            b4 = state;
            break;
        case 5:
            b5 = state;
            break;
        case 6:
            b6 = state;
            break;
        case 7:
            b7 = state;
            break;
        }
    }

    bool getBit(int index) const
    {
        if (index < 0 || index > 7)
            throw std::out_of_range("Bit index out of range");
        switch (index)
        {
        case 0:
            return b0;
        case 1:
            return b1;
        case 2:
            return b2;
        case 3:
            return b3;
        case 4:
            return b4;
        case 5:
            return b5;
        case 6:
            return b6;
        case 7:
            return b7;
        }
        return false;
    }

    void toggleBit(int index)
    {
        setBit(index, !getBit(index));
    }
};
