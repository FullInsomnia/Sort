#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swapElement ( int anArray[], int index1, int index2 );
int findSmallestElement ( int anArray[], int starting_index, int size );
void selectionSort ( int anArray[], int size );
void printArray( int anArray[], int size );
double median ( int dataSet[], int size );

int main ()
{
    srand ( time ( NULL ) );

    int exampleArray[ 17 ];
    int sz = 10;
    for ( int i = 0; i < sz; i++ )
    {
        exampleArray[ i ] = rand() % 50;
    }
    cout << "Array: ";
    printArray ( exampleArray, sz );
    cout << '\n';
    selectionSort ( exampleArray, sz );
    cout << "Sorted array: ";
    printArray ( exampleArray , sz );
    cout << endl << "Median: " << median( exampleArray, sz ) << '\n';
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
    cout << ']';
}

void selectionSort ( int theArray[], int length )
{
    for ( int i = 0; i < length; i++ )
    {

        swapElement ( theArray, i,
            findSmallestElement ( theArray, i, length ) );
    }
}

double median ( int dataSet[], int size )
{
    if ( size % 2 != 0 )
    {
        return dataSet[ ( size / 2 ) + 1 ];
    }
    else
    {
        int i = size / 2;
        int j = size / 2 - 1;
        double avg1 = dataSet[ i ];
        double avg2 = dataSet[ j ];
        return ( avg1 + avg2 ) / 2;
    }
}