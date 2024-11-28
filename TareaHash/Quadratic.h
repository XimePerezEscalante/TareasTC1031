#include <string>
#include <sstream>

template <class Key, class Value>
class Quadratic
{
private:
    unsigned int (*func)(const Key);
    unsigned int size;
    unsigned int count;

    Key *keys;
    Key initialValue;
    Value *values;

    long indexOf(const Key) const;

public:
void put(std::string, int);
};


/*i = (k*K) + d

*/