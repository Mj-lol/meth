template <typename T>
class myarray
{
private:
    /* data */
    T *data;
    size_t size;

public:
    myarray(size_t initialsize);
    ~myarray();
};

myarray::myarray(size_t initialsize)
{
    size = initialsize;
    data = new malloc(size)
}

myarray::~myarray()
{
}
