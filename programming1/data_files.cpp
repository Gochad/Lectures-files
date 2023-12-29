using namespace std;

void SortCount (string firstFile, string secondFile, string thirdFile);
void SortInt (string firstFile, string secondFile, string thirdFile);
void SortString (string firstFile, string secondFile, string thirdFile);
void SymmetricDifference (string firstFile, string secondFile, string thirdFile);

void SortCount (string firstFile, string secondFile, string thirdFile)
{
    fstream file;
    fstream file2;
    fstream file3;
    int numberOne;
    int numberTwo;
    int size = 0;
    int dataSize = 0;
    int counter = 0;
    int isCounted;
    int counting;
    char space;
    string enter;
    string temp;
    string text;
    string character;
    int max = 0;
    int beforeMax = 0;
    int intWithMax = 0;
    int tempSize;
    int maximum;
    int sizeSet;
    bool checkB = false;
    bool firstBoolOne;
    bool secondBoolOne;
    bool thirdBoolOne;
    bool fourBoolOne;
    short firstCharOne;
    short secondCharOne;
    short thirdCharOne;
    short fourCharOne;
    float firstFloatOne;
    float secondFloatOne;
    float thirdFloatOne;
    float fourFloatOne;
    int mainSize;
    int number;
    int maxSumChar = 0;
    int sizee;
    file2.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file2 << "";
    file2.close ();
    file3.open (thirdFile.c_str (), fstream::out | fstream::trunc);
    file3 << "";
    file3.close ();
    
    file.open (firstFile.c_str (), fstream::in);
    while (!file.eof ())
    {
        getline(file, temp);
        if (!file.eof ())
        {
            for (int i = 0; i < 6; i++)
            {
                getline (file, temp);
            }
            ++size;
        }
    }
    file.close();
    file2.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file2 << "";
    file2.close ();
    
    sizee = size;
    while (sizee > 0)
    {
        maxSumChar = 0;
        file3.open (thirdFile.c_str (), fstream::out | fstream::trunc);
        file3 << "";
        file3.close();
        file.open (firstFile.c_str(), fstream::in);
        for (int i = 0; i < sizee; i++)
        {
            file >> numberOne;
            for (int k = 0; k < 3; k++)
            {
                getline (file, temp);
            }
            file >> firstBoolOne >> firstCharOne >> firstFloatOne;
            getline (file, temp);
            file >> secondBoolOne >> secondCharOne >> secondFloatOne;
            getline (file, temp);
            file >> thirdBoolOne >> thirdCharOne >> thirdFloatOne;
            getline (file, temp);
            file >> fourBoolOne >> fourCharOne >> fourFloatOne;
            getline (file, temp);
            if (i == 0)
            {
                maxSumChar = (firstCharOne + secondCharOne + thirdCharOne + fourCharOne) % 256;
            }
            else
            {
                if (((firstCharOne + secondCharOne + thirdCharOne + fourCharOne) % 256) > maxSumChar)
                {
                    maxSumChar = (firstCharOne + secondCharOne + thirdCharOne + fourCharOne) % 256;
                }
            }
        } 
        file.close ();
        file2.open (secondFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::app | fstream::out);
        file.open (firstFile.c_str (), fstream::in);
        tempSize = sizee;
        for (int j = 0; j < tempSize; j++)
        {
            file >> number;
            if (!file.eof())
            {
                getline (file, temp);
                getline (file, text);
                getline (file, character);
                file >> firstBoolOne >> firstCharOne >> firstFloatOne;
                getline (file, temp);
                file >> secondBoolOne >> secondCharOne >> secondFloatOne;
                getline (file, temp);
                file >> thirdBoolOne >> thirdCharOne >> thirdFloatOne;
                getline (file, temp);
                file >> fourBoolOne >> fourCharOne >> fourFloatOne;
                getline (file, temp);
                if (((firstCharOne + secondCharOne + thirdCharOne + fourCharOne) % 256) == maxSumChar)
                {
                    file2 << number << endl;
                    file2 << text << endl << character << endl;
                    file2 << firstBoolOne << ' ' << firstCharOne << ' ' << firstFloatOne << endl;
                    file2 << secondBoolOne << ' ' << secondCharOne << ' ' << secondFloatOne << endl;
                    file2 << thirdBoolOne << ' ' << thirdCharOne << ' ' << thirdFloatOne << endl;
                    file2 << fourBoolOne << ' ' << fourCharOne << ' ' << fourFloatOne << endl;
                    --sizee;
                }
                else
                {
                    file3 << number << endl;
                    file3 << text << endl << character << endl;
                    file3 << firstBoolOne << ' ' << firstCharOne << ' ' << firstFloatOne << endl;
                    file3 << secondBoolOne << ' ' << secondCharOne << ' ' << secondFloatOne << endl;
                    file3 << thirdBoolOne << ' ' << thirdCharOne << ' ' << thirdFloatOne << endl;
                    file3 << fourBoolOne << ' ' << fourCharOne << ' ' << fourFloatOne << endl;
                }
            }
        }
        file.close ();
        file2.close ();
        file3.close ();
        file.open (firstFile.c_str (), fstream::out | fstream::trunc);
        file << "";
        file.close();
        file.open (firstFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::in);
        while (!file3.eof ())
        {
            for (int i = 0; i < 7; i++)
            {
                getline (file3, temp);
                file << temp << endl;
            }
        }
        file.close ();
        file3.close ();
    }
    file.open (firstFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();
    file.open (firstFile.c_str (), fstream::app | fstream::out);
    file2.open (secondFile.c_str (), fstream::in);
    while (!file2.eof ())
    {
        getline (file2, temp);
        if (!file2.eof())
        {
            file << temp << endl;
            for (int i = 0; i < 6; i++)
            {
                getline (file2, temp);
                file << temp << endl;
            }
        }
    }
    file.close();
    file2.close();

    file2.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file2 << "";
    file2.close ();
    sizeSet = size;
    while (sizeSet > 0)
    {
        file3.open (thirdFile.c_str (), fstream::out | fstream::trunc);
        file3 << "";
        file3.close();
        file.open (firstFile.c_str (), fstream::in);
        for (int j = 0; j < sizeSet; j++)
        {
            file >> number;
            getline (file, enter);
            if (j == 0)
            {
                maximum = number;
            }
            else
            {
                if (number > maximum)
                {
                    maximum = number;
                }
            }
            for (int i = 0; i < 6; i++)
            {
                getline (file, temp);
            }
        }

        file.close ();
        file2.open (secondFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::app | fstream::out);
        file.open (firstFile.c_str (), fstream::in);
        tempSize = sizeSet;
        for (int j = 0; j < tempSize; j++)
        {
            file >> number;
            getline (file, enter);
            if (!file.eof())
            {
                if (number == maximum)
                {
                    file2 << number << endl;
                    for (int i = 0; i < 6; i++)
                    {
                        getline (file, temp);
                        file2 << temp << endl; 
                    }
                    --sizeSet;
                }
                else
                {
                    file3 << number << endl;
                    for (int i = 0; i < 6; i++)
                    {
                        getline (file, temp);
                        file3 << temp << endl;
                    } 
                }
            }
        }
        file.close ();
        file2.close ();
        file3.close ();

        file.open (firstFile.c_str (), fstream::out | fstream::trunc);
        file << "";
        file.close();
        file.open (firstFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::in);
        while (!file3.eof ())
        {
            for (int i = 0; i < 7; i++)
            {
                getline (file3, temp);
                file << temp << endl;
            }
        }
        file.close ();
        file3.close ();
    }
    file.open (firstFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();
    
    file.open (firstFile.c_str (), fstream::app | fstream::out);
    file2.open (secondFile.c_str (), fstream::in);
    while (!file2.eof ())
    {
        getline (file2, temp);
        if (!file2.eof())
        {
            file << temp << endl;
            for (int i = 0; i < 6; i++)
            {
                getline (file2, temp);
                file << temp << endl;
            }
        }
    }
    file.close();
    file2.close();
    
    
    file2.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file2 << "";
    file2.close ();
    mainSize = size;
    
    while (size > 0)
    {
        file3.open (thirdFile.c_str (), fstream::out | fstream::trunc);
        file3 << "";
        file3.close();
        file.open (firstFile.c_str (), fstream::in);
        for (int i = 0; i < size; i++)
        {
            file >> numberOne;
            for (int j = 0; j < 7; j++)
            {
                getline (file, temp);
            }
        
            file2.open (firstFile.c_str (), fstream::in);
            for (int j = 0; j < size; j++)
            {
                file2 >> numberTwo;
                for (int k = 0; k < 7; k++)
                {
                    getline (file2, temp);
                }
                
                if (numberOne == numberTwo)
                {
                    ++counter;
                }
            }
            if (i == 0)
            {
                max = counter;
                intWithMax = numberOne;
            }
            else
            {
                if (counter > max)
                {
                    max = counter;
                    intWithMax = numberOne;
                }
        
            }
            file2.close ();
            counter = 0;  
        }
        file.close ();

        file.open (firstFile.c_str(), fstream::in);
        file2.open (secondFile.c_str(), fstream::out | fstream::app);
        file3.open (thirdFile.c_str(), fstream::out | fstream::app);
        tempSize = size;
        for (int i = 0; i < tempSize; i++)
        {
            file >> numberOne;
            getline (file, temp);
            if (numberOne == intWithMax)
            {
                file2 << numberOne << endl;
                for (int j = 0; j < 6; j++)
                {
                    getline (file, temp);
                    file2 << temp << endl;
                }
                --size;
            }
            else
            {
                file3 << numberOne << endl;
                for (int j = 0; j < 6; j++)
                {
                    getline (file, temp);
                    file3 << temp << endl;
                }
            }
        }
        file.close ();
        file2.close ();
        file3.close ();

        file.open (firstFile.c_str (), fstream::out | fstream::trunc);
        file << "";
        file.close ();

        file.open (firstFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::in);
        while (!file3.eof ())
        {
            for (int i = 0; i < 7; i++)
            {
                getline (file3, temp);
                file << temp << endl;
            }
        }
        file.close ();
        file3.close ();
    }
    file.open (firstFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close ();
    file.open (firstFile.c_str (), fstream::app | fstream::out);
    file2.open (secondFile.c_str (), fstream::in);
    while (!file2.eof ())
    {
        getline (file2, temp);
        if (!file2.eof())
        {
            file << temp << endl;
            for (int i = 0; i < 6; i++)
            {
                getline (file2, temp);
                file << temp << endl;
            }
        }
    }
    file.close();
    file2.close();
}

void SortString (string firstFile, string secondFile, string thirdFile)
{ 
    fstream file;
    fstream file2;
    fstream file3;
    string temp;
    string temp2;
    int size = 0;
    string min = "";
    int check = 0;
    int tempSize;
    int k;
    file.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();
    
    file.open (firstFile.c_str (), fstream::in);
    while (!file.eof ())
    {
        getline(file, temp);
        if (!file.eof ())
        {
            for (int i = 0; i < 6; i++)
            {
                getline (file, temp);
            }
            ++size;
        }
    }

    file.close ();
    while (size > 0)
    {
        file3.open (thirdFile.c_str (), fstream::out | fstream::trunc);
        file3 << "";
        file3.close();
        file.open (firstFile.c_str (), fstream::in);
        for (int j = 0; j < size; j++)
        {
            getline (file, temp);
            getline (file, temp);
            if (check == 0)
            {
                min = temp;
            }
            else
            {
                if (temp < min)
                {
                    min = temp;
                }
            }
            for (int i = 0; i < 5; i++)
            {
                getline (file, temp);
            }
            ++check;
        }

        file.close ();
        check = 0;
        file2.open (secondFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::app | fstream::out);
        file.open (firstFile.c_str (), fstream::in);
        tempSize = size;
        k = 0;
        for (int j = 0; j < tempSize; j++)
        {
            getline (file, temp2);
            getline (file, temp);
            if (!file.eof())
            {
                if (temp == min)
                {
                    file2 << temp2 << endl;
                    file2 << temp << endl;

                    for (int i = 0; i < 5; i++)
                    {
                        getline (file, temp);
                        file2 << temp << endl; 
                    }
                    --size;
                    ++k;

                }
                else
                {
                    file3 << temp2 << endl;
                    file3 << temp << endl;
                    for (int i = 0; i < 5; i++)
                    {
                        getline (file, temp);
                        file3 << temp << endl;
                    } 
                }
            }
        }
        file.close ();
        file2.close ();
        file3.close ();

        file.open (firstFile.c_str (), fstream::out | fstream::trunc);
        file << "";
        file.close();
        file.open (firstFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::in);
        while (!file3.eof ())
        {
            for (int i = 0; i < 7; i++)
            {
                getline (file3, temp);
                file << temp << endl;
            }
        }
        file.close ();
        file3.close ();
    }
    file.open (firstFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();
    
    file.open (firstFile.c_str (), fstream::app | fstream::out);
    file2.open (secondFile.c_str (), fstream::in);
    while (!file2.eof ())
    {
        for (int i = 0; i < 7; i++)
        {
            getline (file2, temp);
            file << temp << endl;
        }
    }
    file.close();
    file2.close();
}
void SortInt (string firstFile, string secondFile, string thirdFile)
{ 
    fstream file;
    fstream file2;
    fstream file3;
    string temp;
    string enter;
    int size = 0;
    int number;
    int min;
    int check = 0;
    int tempSize;
    int k;
    file.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();
    
    file.open (firstFile.c_str (), fstream::in);
    while (!file.eof ())
    {
        getline(file, temp);
        if (!file.eof ())
        {
            for (int i = 0; i < 6; i++)
            {
                getline (file, temp);
            }
            ++size;
        }
    }

    file.close ();
    while (size > 0)
    {
        file3.open (thirdFile.c_str (), fstream::out | fstream::trunc);
        file3 << "";
        file3.close();
        file.open (firstFile.c_str (), fstream::in);
        for (int j = 0; j < size; j++)
        {
            file >> number;
            getline (file, enter);
            if (check == 0)
            {
                min = number;
            }
            else
            {
                if (number < min)
                {
                    min = number;
                }
            }
            for (int i = 0; i < 6; i++)
            {
                getline (file, temp);
            }
            ++check;
        }

        file.close ();
        check = 0;
        file2.open (secondFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::app | fstream::out);
        file.open (firstFile.c_str (), fstream::in);
        tempSize = size;
        k = 0;
        for (int j = 0; j < tempSize; j++)
        {
            file >> number;
            getline (file, enter);
            if (!file.eof())
            {
                if (number == min)
                {
                    file2 << number << endl;

                    for (int i = 0; i < 6; i++)
                    {
                        getline (file, temp);
                        file2 << temp << endl; 
                    }
                    --size;

                }
                else
                {
                    file3 << number << endl;
                    for (int i = 0; i < 6; i++)
                    {
                        getline (file, temp);
                        file3 << temp << endl;
                    } 
                }
            }
        }
        file.close ();
        file2.close ();
        file3.close ();

        file.open (firstFile.c_str (), fstream::out | fstream::trunc);
        file << "";
        file.close();
        file.open (firstFile.c_str (), fstream::app | fstream::out);
        file3.open (thirdFile.c_str (), fstream::in);
        while (!file3.eof ())
        {
            for (int i = 0; i < 7; i++)
            {
                getline (file3, temp);
                file << temp << endl;
            }
        }
        file.close ();
        file3.close ();
    }
    file.open (firstFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();
    
    file.open (firstFile.c_str (), fstream::app | fstream::out);
    file2.open (secondFile.c_str (), fstream::in);
    while (!file2.eof ())
    {
        for (int i = 0; i < 7; i++)
        {
            getline (file2, temp);
            file << temp << endl;
        }
    }
    file.close();
    file2.close();
}
void SymmetricDifference (string firstFile, string secondFile, string thirdFile)
{
    fstream file;
    fstream file2;
    fstream file3;

    string temp;
    string txtOneFTwo;
    string txtTwoFTwo;
    string txtThreeFTwo;
    string txtFourFTwo;
    string txtFiveFTwo;
    string txtSixFTwo;
    string txtSevenFTwo;
    string txtOneFOne;
    string txtTwoFOne;
    string txtThreeFOne;
    string txtFourFOne;
    string txtFiveFOne;
    string txtSixFOne;
    string txtSevenFOne;

    bool isEqual = true;
    int sizeTwo = 0;
    int sizeOne = 0;
    int sameCounter = 0;

    file.open (thirdFile.c_str (), fstream::out | fstream::trunc);
    file << "";
    file.close();

    file2.open (secondFile.c_str (), fstream::in);
    while (!file2.eof ())
    {
        getline(file2, temp);
        if (!file2.eof ())
        {
            for (int i = 0; i < 6; i++)
            {
                getline (file2, temp);
            }
            ++sizeTwo;
        }
    }
    file2.close ();

    file.open (firstFile.c_str (), fstream::in);
    while (!file.eof ())
    {
        getline(file, temp);
        if (!file.eof ())
        {
            for (int i = 0; i < 6; i++)
            {
                getline (file, temp);
            }
            ++sizeOne;
        }
    }
    file.close ();
    
    file3.open (thirdFile.c_str(), fstream::app | fstream::out);
    file2.open (secondFile.c_str(), fstream::in);
    for (int i = 0; i < sizeTwo; i++)
    {
        getline (file2, txtOneFTwo);
        getline (file2, txtTwoFTwo);
        getline (file2, txtThreeFTwo);
        getline (file2, txtFourFTwo);
        getline (file2, txtFiveFTwo);
        getline (file2, txtSixFTwo);
        getline (file2, txtSevenFTwo);
        file.open (firstFile.c_str(), fstream::in);
        if (sizeOne != 0)
        {
            for (int j = 0; j < sizeOne; j++)
            {
                getline (file, txtOneFOne);
                getline (file, txtTwoFOne);
                getline (file, txtThreeFOne);
                getline (file, txtFourFOne);
                getline (file, txtFiveFOne);
                getline (file, txtSixFOne);
                getline (file, txtSevenFOne);
                if (txtOneFTwo.compare (txtOneFOne) == 0 && 
                txtTwoFTwo.compare (txtTwoFOne) == 0 && 
                txtThreeFTwo.compare (txtThreeFOne) == 0 && 
                txtFourFTwo.compare (txtFourFOne) == 0 && 
                txtFiveFTwo.compare (txtFiveFOne) == 0 && 
                txtSixFTwo.compare (txtSixFOne) == 0 && 
                txtSevenFTwo.compare (txtSevenFOne) == 0)
                {
                    file3 << txtOneFTwo << endl
                        << txtTwoFTwo << endl
                        << txtThreeFTwo << endl
                        << txtFourFTwo << endl
                        << txtFiveFTwo << endl
                        << txtSixFTwo << endl
                        << txtSevenFTwo << endl;
                    break;
                }
                else
                {
                    if (j == sizeOne - 1)
                    {
                        isEqual = false;
                    } 
                }
            }
            file.close ();
            file.open (firstFile.c_str(), fstream::app | fstream::out);
            
            if (isEqual == false)
            {
                file << endl << txtOneFTwo << endl
                    << txtTwoFTwo << endl
                    << txtThreeFTwo << endl
                    << txtFourFTwo << endl
                    << txtFiveFTwo << endl
                    << txtSixFTwo << endl
                    << txtSevenFTwo;
                isEqual = true;
            }
            file.close ();
        }
        else
        {
            file.close ();
            file.open (firstFile.c_str(), fstream::app | fstream::out);
            file << txtOneFTwo << endl
                 << txtTwoFTwo << endl
                 << txtThreeFTwo << endl
                 << txtFourFTwo << endl
                 << txtFiveFTwo << endl
                 << txtSixFTwo << endl
                 << txtSevenFTwo << endl;
            file.close ();
        }
        
    }
    file2.close ();
    file3.close ();

    file2.open (secondFile.c_str (), fstream::out | fstream::trunc);
    file2 << "";
    file2.close();

    file2.open (secondFile.c_str (), fstream::app | fstream::out);
    file3.open (thirdFile.c_str (), fstream::in);
    while (!file3.eof ())
    {
        for (int i = 0; i < 7; i++)
        {
            getline (file3, temp);
            if (!file3.eof ())
            {
                file2 << temp << endl;
            }
            else
            {
                break;
            }
        }  
    }
    file2.close ();
    file3.close ();
}