template <typename T>
struct Pointer
{
private:
    T *address;

public:
    Pointer(T *addr) : address(addr) {}

    T &operator*()
    {
        return *address;
    }
    T *operator->()
    {
        return address;
    }
    void points_to(T *newaddr)
    {
        address = newaddr;
    }

    Pointer<T> operator+(int offset) const
    {
        return Pointer<T>(address + offset);
    }

    Pointer<T> operator-(int offset) const
    {
        return Pointer<T>(address - offset);
    }
}
