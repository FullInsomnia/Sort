#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swapElement ( int anArray[], int index1, int index2 );
int findSmallestElement ( int anArray[], int starting_index, int size );
void selectionSort ( int anArray[], int size );
void printArray( int anArray[], int size );

int main ()
{
    srand ( time ( NULL ) );

    int exampleArray[ 10 ];
    for ( int i = 0; i < 10; i++ )
    {
        exampleArray[ i ] = rand() % 50;
    }
    cout << "Array: ";
    printArray ( exampleArray, 10 );
    selectionSort ( exampleArray, 10 );
    cout << "Sorted array: ";
    printArray ( exampleArray , 10 );
    cout << endl;
}

void swapElement ( int anArray[], int index1, int index2 )
{
    int temp1 = anArray[ index1 ];
    int temp2 = anArray[ index2 ];
    anArray[ index1 ] = temp2;
    anArray[ index2 ] = temp1;
}

int findSmallestElement ( int anArray[], int starting_index, int size )
{
    int small = starting_index;
    for (int place = small + 1; place < size; place++)
    {
        if (  anArray[ place ] < anArray[ small ] )
        {
            small = place;
        }
    }
    return small;
}

void printArray ( int anArray[], int size )
{
    cout << "[";
    for ( int i = 0; i < size; i++ )
    {
        cout << anArray[ i ];
        if ( i < size - 1 )
        {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}

void selectionSort ( int theArray[], int length )
{
    for ( int i = 0; i < length; i++ )
    {

        swapElement ( theArray, i,
            findSmallestElement ( theArray, i, length ) );
    }
}
