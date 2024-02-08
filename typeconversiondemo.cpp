#include <iostream>

class Sample
{
    int data;

public:
    Sample()
    {
        data = 0;
    }

    Sample(int d)
    {
        data = d;
    }

    // type conversion operator; Sample to int coversion
    operator int()
    {
        return data;
    }

    // functor
    void operator () ()
    {
        std::cout << "This is a functor" << std::endl;
    }
};


int main()
{
    Sample s(2);

    std::cout << s << std::endl;    // Type conversion operator calling

    s();                            // Functor calling

    return 0;
}
