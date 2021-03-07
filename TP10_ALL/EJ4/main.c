#include <stdio.h>
#include "const.h"
#include "PORTS.h"

int main()
{
    for (int i = 0; i < 16; i++)
    {
        bitSet('D', i);
    }

    printf(" 1) Puertos deberian estar prendidos:\t");
    estado_bits('D');

    for (int i = 0; i < 16; i++)
    {
        bitClr('D', i);
    }

    printf(" 2) Puertos deberian estar apagados:\t");
    estado_bits('D');

    bitSet('A', 1);
    bitSet('A', 5);
    bitSet('A', 7);

    printf(" 3) Prender dif bits:\t\t\t");
    estado_bits('D');

    bitToggle('D', 7);

    printf(" 4) Togglean algunos bits: \t\t");
    estado_bits('D');

    estado_bits('A');
    estado_bits('B');
    estado_bits('D');
    
    return 0;
}