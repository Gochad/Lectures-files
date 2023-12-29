#include <iostream>
using namespace std;

int main ()
{
    int lenArray; 

    int numberOperations; 
    int iterationOperations = 0; 

    int iteration = 0; 

    char nameOfOperation;
    int firstIndex = 0; 
    int realIndex = 0;
    int lenPart = 0;
    int movement = 0;
    int parts = 0;
    int endIndex = 0;
    int saver = 0;
    int iterationHalf = 0;;
    int lenHalf = 0;
    int lastIndex = 0;
    int iterPart = 0;
    int endChange;
    int endFrag;
    int movingState;
    int lenChange;
    int i = 0;
    int iterationPart;
    int previousIndex;
    int movement2;
    int shift = 0;
    int j = 0;

    cin >> numberOperations;

    while (iterationOperations < numberOperations)
    {
        cin >> lenArray;
        int array[lenArray];
        iteration = 0;
        while (iteration < lenArray)
        {
            cin >> array[iteration];
            ++iteration;
        }

        iteration = 0;

        while (iteration < lenArray)
        {
            cout << array[iteration] << " ";
            ++iteration;
        }
        cout << endl;

        do
        {
            cin >> nameOfOperation;
            if (nameOfOperation == 'R') 
            {
                cin >> firstIndex >> lenPart; 

                if (lenPart > 0)
                {       
                    
                    firstIndex = ((firstIndex % lenArray) + lenArray) % lenArray;
                    
                    parts = lenArray / lenPart; 
                    
                    lenHalf = lenPart / 2;
                    realIndex = ((firstIndex % lenArray) + lenArray) % lenArray;
                    iterPart = 0;

                    while (iterPart < parts)
                    {   
                        iterationHalf = 0;
                        realIndex = ((firstIndex % lenArray)+ (lenPart * iterPart)) % lenArray;
                        endIndex = ( ((firstIndex % lenArray) + (lenPart * (iterPart + 1))) - 1) % lenArray;
                        
                        while (iterationHalf < lenHalf)
                        {

                            saver = array[realIndex];
                            array[realIndex] = array[endIndex];
                            array[endIndex] = saver;
                        
                            realIndex++;
                            endIndex--;

                            realIndex = realIndex % lenArray;
                            endIndex = endIndex % lenArray;

                            iterationHalf++;
                        }
                        iterPart++;
                    }
                } 
            }
            if (nameOfOperation == 'S') 
            {
                cin >> firstIndex >> lenPart;

                if (lenPart > 0)
                { 
                    firstIndex = ((firstIndex % lenArray) + lenArray) % lenArray;
                    
                    parts = lenArray / lenPart; 
                    
                    realIndex = ((firstIndex % lenArray) + lenArray) % lenArray;
                    iterPart = 0;
                    shift = 0;
                    parts /= 2;
                    while (iterPart < parts)
                    {   
                        iterationHalf = 0;
                        realIndex = ((firstIndex % lenArray)+ (lenPart * shift)) % lenArray;
                        endIndex = ( ((firstIndex % lenArray) + (lenPart * (shift + 1))) ) % lenArray;
                        shift += 2;
                        while (iterationHalf < lenPart)
                        {
                            saver = array[realIndex];
                            array[realIndex] = array[endIndex];
                            array[endIndex] = saver;

                            realIndex++;
                            endIndex++;

                            realIndex = ((realIndex % lenArray) + lenArray) % lenArray;
                            endIndex = ((endIndex % lenArray) + lenArray) % lenArray;

                            iterationHalf++;
                        }
                        iterPart++;
                    }
                }
            }
            
            if (nameOfOperation == 'C')
            {
                cin >> firstIndex >> lenPart >> movement;

                if (lenPart > 0)
                {
                    firstIndex = ((firstIndex % lenArray) + lenArray) % lenArray;
                    
                    parts = lenArray / lenPart;
                    movement2 = (movement % lenPart + lenPart) % lenPart;
                    realIndex = (firstIndex % lenArray + lenArray) % lenArray;
                    lenChange = lenPart - 1;
                    while (movement2 > 0)
                    {
                        iterationPart = 1;
                        while (iterationPart <= parts)
                        {
                            movingState = lenPart * iterationPart;
                            lastIndex = (realIndex + movingState - 1) % lenArray;
                            previousIndex = lastIndex - 1;
                            previousIndex = (previousIndex + lenArray) % lenArray;

                            i = 0;
                            while (i < lenChange)
                            {
                                saver = array[lastIndex];
                                array[lastIndex] = array[previousIndex];
                                array[previousIndex] = saver;
                
                                --lastIndex;
                                lastIndex = (lastIndex + lenArray) % lenArray;
                                --previousIndex;
                                previousIndex = (previousIndex + lenArray) % lenArray;
                                ++i;
                            }
                            ++iterationPart;
                        }
                        --movement2;
                    }
                    endFrag = lenArray % lenPart;
                    endChange = ((movement % endFrag) + endFrag) % endFrag;
                        
                    if (endFrag > 0)
                    {
                        i = 0;
                        
                        while (i < endChange)
                        {
                            j = 0;
                            lastIndex = (firstIndex - 1 + lenArray) % lenArray;
                            previousIndex = lastIndex - 1;
                            previousIndex = (previousIndex + lenArray) % lenArray;


                            while (j < endFrag - 1)
                            {
                                saver = array[lastIndex];
                                array[lastIndex] = array[previousIndex];
                                array[previousIndex] = saver;
                                --lastIndex;
                                lastIndex = (lastIndex + lenArray) % lenArray;
                                --previousIndex;
                                previousIndex = (previousIndex + lenArray) % lenArray;
                                ++j;
                            }
                            ++i;
                        }
                    }
                }
            }
        }
        while (nameOfOperation != 'F');

        ++iterationOperations;

        iteration = 0;
        while (iteration < lenArray)
        {
            cout << array[iteration] << " ";
            ++iteration;
        }
        cout << endl;
    }

    

    
    return 0;
    
}