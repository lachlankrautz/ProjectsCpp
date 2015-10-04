#include <iostream>
#include <sstream>
#include <c++/iomanip>
#include <c++/limits>

using namespace std;

int    getDecimals();
void   printSavedPi(int decimals);
void   printPi(int digit);
double getPower(double num, int power);
double getPiDigit(int digit);
double getPiToDigit(int digit);

int main()
{
    cout << " -[ Pi Calculator ]-" << endl;
    int decimals = getDecimals();
    printSavedPi(decimals);
    printPi(decimals);
    return 0;
}

int getDecimals()
{
    int x = 0;
    bool loop = true;
    while(loop)
    {
        std::cout << "How many decimals? ";
        std::string s;
        std::getline(std::cin, s);

        std::stringstream stream{s};
        if(stream >> x && x > 0 && x < 12)
        {
            loop = false;
        }
        else
        {
            x = 0;
            std::cout << "Invalid! Enter a number between 1 and 11" << std::endl;
        }
    }
    return x;
}

void printSavedPi(int decimals)
{
    std::string pi = "3.141592653589793238462643383279502884197169399375105820974944592307816406286";
    //cout << "Saved Pi: " << pi << endl;
    //cout << "Ans   Pi: " << pi.substr(0, (uint32_t)decimals+2) << endl;
}

void printPi(int decimals)
{
    std::stringstream width;
    for(int i = 0; i < decimals; ++i)
    {
        width << "x";
    }
    double rawPi = getPiToDigit(decimals+1);
    std::ostringstream pi;
    pi.precision(decimals+1);
    pi << rawPi;
    //cout << "Raw   Pi: " << pi.str() << endl;
    cout << std::fixed;
    cout << std::setprecision(decimals);
    cout << "Gen   Pi: " << rawPi << endl;
}

double getPiToDigit(int digit)
{
    double pi = 0;
    for( int i = 0; i < digit; ++i )
    {
        double piDigit = getPiDigit(i);
        pi += piDigit;
    }
    return pi;
}

double getPiDigit(int digit)
{
    double dDigit = (double) digit;
    double piDigit;

    piDigit = ( 1L / getPower(16L, digit) )
             * ( ( 4L / ( 8L*dDigit+1 ) )
               - ( 2L / ( 8L*dDigit+4 ) )
               - ( 1L / ( 8L*dDigit+5 ) )
               - ( 1L / ( 8L*dDigit+6 ) ) );

    return piDigit;
}

double getPower(double num, int power)
{
    double total;
    if (num <= 0)
    {
        total = 0;
    }
    else
    {
        total = 1;
        for(int i = 0; i < power; ++i)
        {
            total *= num;
        }
    }
    return total;
}
