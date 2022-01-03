#include <unistd.h>

void putchar(char c)
{
    write(1, &c, 1);
}

void putnbr(int nb)
{
    if (nb < 0)
    {
        nb = -nb;
        putchar('-');
    }
    if (nb < 10)
    {
        putchar('0' + nb);
    }
    else
    {
        putnbr(nb / 10);
        putnbr(nb % 10);
    }
    return;
}
