#include <iostream>
using namespace std;

bool Range (int number);
void Sort (int array[]);
void Add (int number, int array[]);
void Create (int n, int arrayAdd[], int array[]);
void Union (int arrayOne[], int arrayTwo[], int array[]);
void Intersection (int arrayOne[], int arrayTwo[], int array[]);
void Difference (int arrayOne[], int arrayTwo[], int array[]);
void Symmetric (int arrayOne[], int arrayTwo[], int array[]);
void Complement (int arrayOne[], int arrayTwo[]);
bool Subset (int arrayOne[], int arrayTwo[]); 
bool Equal (int arrayOne[], int arrayTwo[]);
bool Empty (int array[]);
bool Nonempty (int array[]);
bool Element (int number, int array[]);
double Arithmetic (int array[]);
double Harmonic (int array[]);
void MinMax (int array[], int *min, int &max);
void Cardinality (int array[], int *power);
void Properties (int array[], char mark[], double &arithmetic, double *harmonic, int &min, int *max, int &power); 



bool Range (int number)
{
    if (number >= 1 && number <= 4095)
        return true;
    else
        return false;
}
void Sort (int array[])
{
    int temp;
    int size;
    Cardinality (array, &size);
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1; i++)
        {
            if (array[ i ] > array[ i + 1 ]) 
            {
                temp = array[ i ];
                array[ i ] = array[ i + 1 ];
                array[ i + 1 ] = temp;
            }
        }
    }
}

void Add (int number, int array[])
{
    int size;
    Cardinality (array, &size);
    if (Range (number) && !Element (number, array))
    {
        array[ size ] = number;
        array[ size + 1 ] = -1;
        Sort (array);
    }
}
void Create (int number, int arrayAdd[], int arrayToDo[])
{
    arrayToDo[ 0 ] = -1;
    int j = 0;
    if (number > 0)
    {
        for (int i = 0; i < number; i++)
        {  
            if (Range (arrayAdd[ i ]) && !Element (arrayAdd[ i ], arrayToDo))
            {
                arrayToDo[ j ] = arrayAdd[ i ];
                ++j;
            }
        }
        arrayToDo[ j ] = -1;
    }
    Sort (arrayToDo);

}
void Union (int arrayOne[], int arrayTwo[], int array[])
{
    int sizeOne;
    int sizeTwo;
    int j = 0;

    array[ 0 ] = -1;

    Cardinality (arrayOne, &sizeOne);
    Cardinality (arrayTwo, &sizeTwo);
    
    if (sizeOne != 0)
    {
        for (int i = 0; i < sizeOne; i++)
        {
            if (!Element (arrayOne[ i ], arrayTwo))
            {
                array [ j ] = arrayOne [ i ];
                ++j;
            }
        }
    }
    if (sizeTwo != 0)
    {
        for (int i = 0; i < sizeTwo; i++)
        {
            if (!Element (arrayTwo[ i ], arrayOne))
            {
                array [ j ] = arrayTwo [ i ];
                ++j;
            }
        }
    }
    if (sizeOne != 0)
    {
        for (int i = 0; i < sizeOne; i++)
        {
            if (Element (arrayOne[ i ], arrayTwo))
            {
                array [ j ] = arrayOne [ i ];
                ++j;
            }
        }
    }
    array[ j ] = -1;
    Sort (array);
}
void Intersection (int arrayOne[], int arrayTwo[], int array[])
{
    int sizeOne;
    int j = 0;

    array[ 0 ] = -1;

    Cardinality (arrayOne, &sizeOne);
    if (sizeOne != 0)
    {
        for (int i = 0; i < sizeOne; i++)
        {
            if (Element (arrayOne[ i ], arrayTwo))
            {
                array [ j ] = arrayOne [ i ];
                ++j;
            }
        }
        array[ j ] = -1;
    }
    else
    {
        array[ 0 ] = -1;
    }
    Sort (array);
}
void Difference (int arrayOne[], int arrayTwo[], int array[])
{
    int sizeOne;
    int j = 0;

    array[ 0 ] = -1;

    Cardinality (arrayOne, &sizeOne);
    if (sizeOne != 0)
    {
        for (int i = 0; i < sizeOne; i++)
        {
            if (!Element (arrayOne[ i ], arrayTwo))
            {
                array [ j ] = arrayOne [ i ];
                ++j;
            }
        }
        array[ j ] = -1;
    }
    else
    {
        array[ 0 ] = -1;
    }
    Sort (array);
}
void Symmetric (int arrayOne[], int arrayTwo[], int array[])
{
    int sizeOne;
    int sizeTwo;
    int j = 0;

    array[ 0 ] = -1;

    Cardinality (arrayOne, &sizeOne);
    Cardinality (arrayTwo, &sizeTwo);
    
    if (sizeOne != 0)
    {
        for (int i = 0; i < sizeOne; i++)
        {
            if (!Element (arrayOne[ i ], arrayTwo))
            {
                array [ j ] = arrayOne [ i ];
                ++j;
            }
        }
    }
    if (sizeTwo != 0)
    {
        for (int i = 0; i < sizeTwo; i++)
        {
            if (!Element (arrayTwo[ i ], arrayOne))
            {
                array [ j ] = arrayTwo [ i ];
                ++j;
            }
        }
    }
    array[ j ] = -1;
    Sort (array);
}
void Complement (int arrayOne[], int arrayTwo[])
{
    int j = 0;
    int size;
    Cardinality (arrayOne, &size);
    if (size != 0)
    {
        for (int i = 1; i <= 4095; i++)
        {
            if (!Element (i, arrayOne))
            {
                arrayTwo [ j ] = i;
                ++j;
            }
        }
        arrayTwo[ j ] = -1;
    }
    else
    {
        for (int i = 1; i <= 4095; i++)
        {
            arrayTwo [ j ] = i;
            ++j; 
        }
        arrayTwo[ j ] = -1;
    }
}
bool Subset (int arrayOne[], int arrayTwo[]) //One zawierany, Two zawierajacy 
{
    int sizeOne;
    int sizeTwo;
    bool check = false;
    Cardinality (arrayOne, &sizeOne);
    Cardinality (arrayTwo, &sizeTwo);
    if (sizeOne != 0)
    {
        if (sizeTwo != 0)
        {
            for (int i = 0; i < sizeOne; i++)
            {
                for (int j = 0; j < sizeTwo; j++)
                {
                    if (arrayOne [ i ] == arrayTwo[ j ])
                    {
                        check = true;
                        break;
                    }
                }
                if (!check)
                {
                    break;
                }
            }
            if (check)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}
bool Equal (int arrayOne[], int arrayTwo[])
{
    if (Subset (arrayOne, arrayTwo) == true && Subset (arrayTwo, arrayOne) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Empty (int array[])
{
    if (array[ 0 ] == -1)
    {
        return true;
    }
    else
        return false;
}

bool Nonempty (int array[])
{
    if (array[ 0 ] != -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Element (int number, int array[])
{
    bool check = false;
    int size;
    Cardinality (array, &size);
    if (Range (number) && size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (array[ i ] == number)
            {
                check = true;
                break;
            }
            else
            {
                check = false;
            }
        }
        if (check)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
double Arithmetic (int array[])
{
    int size;
    double average = 0.0;
    Cardinality (array, &size);
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            average += array [ i ];
        }
        average = average / size;
    }
    else
    {
        average = 0;
    }
    return average;
}
double Harmonic (int array[])
{
    int size;
    double sizeH = size;
    double sum = 0;
    double harmonic;
    Cardinality (array, &size);
    if (size != 0)
    {
        for (int i = 0; i < size; i++)
        {
            sum += (1.0) / array[ i ];
        }
        harmonic = (double) size / sum;
    }
    else
    {
        harmonic = 1;
    }
    return harmonic;

}
void MinMax (int array[], int *min, int &max)
{
    int size;
    Cardinality (array, &size);
    if (size != 0)
    {
        *min = array[ 0 ];
        max = array[ 0 ];
        for (int i = 1; i < size; i++)
        {
            if (array[ i ] < *min)
            {
                *min = array[ i ];
            }
            if (array[ i ] > max)
            {
                max = array[ i ];
            }
        }
    }
}
void Cardinality (int array[], int *power)
{
    *power = 0;
    while (array [ *power ] != -1)
    {
        ++*power;
    }
}
void Properties (int array[], char mark[], double &arithmetic, double *harmonic, int &min, int *max, int &power)
{
    int sizeChar = 0;
    while (mark[ sizeChar ] != '\0')
    {
        ++sizeChar;
    }
    for (int i = 0; i < sizeChar; ++i)
    {
        if (mark[ i ] == 'a')
        {
            arithmetic = Arithmetic (array);
        }
        if (mark[ i ] == 'h')
        {
            *harmonic = Harmonic (array);
        }
        if (mark[ i ] == 'm')
        {
            MinMax (array, &min, *max);
        }
        if (mark[ i ] == 'c')
        {
            Cardinality (array, &power);
        }
    }

}
