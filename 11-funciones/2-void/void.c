#include<stdio.h>

void incrementDecrement(int, int);

int main()
{
    incrementDecrement( 15, 10 );
    return 0;
}

void incrementDecrement(int v1, int v2)
{
    if( v1 < v2 )
    {
        printf("\nCreciente\n");
    }
    else if( v2 < v1 )
    {
        printf("\nDecreciente\n");
    }

}