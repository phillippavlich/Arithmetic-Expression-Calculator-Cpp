#ifndef ADDITION_H
#define ADDITION_H
#include <string>
using namespace std;
class Addition
{
    public:
        Addition();
        string evaluate(string &a, string &b);
        virtual ~Addition();
    protected:
    private:
};

#endif // ADDITION_H
