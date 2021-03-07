#include <stdio.h>
#include "math.h"
#include "const.h"


float sum(float x, float y, int *error)
{
    *error = -1;
    return x + y;
}
float subst(float x, float y, int *error)
{
    return x - y;
}
float multip(float x, float y, int *error)
{
    return x*y;
}
float expo(float x, float y, int *error)
{
    int negativeExp = 0;
    float result = 1;

    if( (y - (int)y ) != 0)
    {
        *error = DECIMAL_EXP;
        return 0;
    }
    else
    {
        if( y < 0)
        {                       
            y = -y;
            negativeExp = 1;
        }

        for(int i=0; i < (int)y; i ++) // supposing y as an integer
        {
            result = result * x;

        }

        if(negativeExp)
        {                       
            result = 1/result;
        }

        return result;
    }
    
}
float divi(float x , float y, int *error)
{
    if(y)
    {
        return x / y;
    }
    *error = DIV_0X0;
    return 0;
}