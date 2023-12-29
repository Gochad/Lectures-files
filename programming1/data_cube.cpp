#include <iostream>
using namespace std;


long long Deter (int array[ 32 ][ 32 ], int size, int sign) 
{
    int m;
    int n;
    long long det = 0;
    
    if (size == 1)
    {
        det = array[ 0 ][ 0 ];
    }
    else
    {
        int temp[ 32 ][ 32 ];
        for (int k = 0; k < size; k++)
        {
            m = 0;
            for (int i = 1; i < size; i++)
            {
                n = 0;
                for (int j = 0; j < size; j++)
                {
                    if (j != k)
                    {
                        temp[ m ][ n ] = array[ i ][ j ];
                        ++n;
                    }
                }
                ++m;
            }
            if (array[ 0 ][ k ] != 0)
            {
                det += array[ 0 ][ k ] * sign * Deter (temp, size - 1, 1); 
            }

            sign *= -1;
        }
    }
    return det;
}

int main ()
{
    int size;
    char nameOperation;
    
    cin >> size;
    int cube[ 32 ][ 32 ][ 32 ];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {   
                cin >> cube[ k ][ j ][ i ];
            }
        }
    }
     
    do
    {
        cin >> nameOperation;
        if (nameOperation == 'C')
        {
            int l;
            int v; 
            int p; 
            int h; 
            int w; 
            int d; 
            int l2;
            int v2;
            int p2;
            int suma = 0;
            int temp;

            cin >> l >> v >> p >> h >> w >> d;

            if (l > size / 2)
            {
                h = -h;
            }
            if (v > size / 2)
            {
                w = -w;
            }
            if (p > size / 2)
            {
                d = -d;
            }
            l2 = l + h;
            v2 = v + w;
            p2 = p + d;
            if ((l > size - 1 && l2 > size -1) || (v > size - 1 && v2 > size - 1) || (p > size - 1 && p2 > size - 1) 
                || (l < 0 && l2 < 0) || (v < 0 && v2 < 0) || (p < 0 && p2 < 0))
            {
                cout << 0 << endl;
            }
            else
            {
                if (l < 0)
                {
                    l = 0;
                }
                else if (l > size - 1)
                {
                    l = size - 1;
                }
                if (v < 0)
                {
                    v = 0;
                }
                else if (v > size - 1)
                {
                    v = size - 1;
                }
                if (p < 0)
                {
                    p = 0;
                }
                else if (p > size - 1)
                {
                    p = size - 1;
                }

                if (l2 < 0)
                {
                    l2 = 0;
                }
                else if (l2 > size - 1)
                {
                    l2 = size - 1;
                }
                if (v2 < 0)
                {
                    v2 = 0;
                }
                else if (v2 > size - 1)
                {
                    v2 = size - 1;
                }
                if (p2 < 0)
                {
                    p2 = 0;
                }
                else if (p2 > size - 1)
                {
                    p2 = size - 1;
                }
                if (l > l2)
                {
                    temp = l;
                    l = l2;
                    l2 = temp;
                }
                if (v > v2)
                {
                    temp = v;
                    v = v2;
                    v2 = temp;
                }
                if (p > p2)
                {
                    temp = p;
                    p = p2;
                    p2 = temp;
                }
                for (int i = p; i <= p2; i++)
                {
                    for(int j = l; j <= l2; j++)
                    {
                        for (int k = v; k <= v2; k++)
                        {      
                            suma += cube[ k ][ j ][ i ];   
                        }
                    }
                }
                cout << suma << endl;
            }
        }

        if (nameOperation == 'T')
        {
            int l;
            int v;
            int p;
            int e;
            int l2;
            int v2;
            int p2;
            int lenL;
            int lenP;
            int lenV;
            int suma = 0;
            int temp = e;
            int temp1;
            int temp2;
            int temp3;

            cin >> l >> v >> p >> e;

            if (l > size / 2)
            {
                lenL = -e;
            }
            else
            {
                lenL = e;
            }
            if (v > size / 2)
            {
                lenV = -e;
            }
            else
            {
                lenV = e;
            }
            if (p > size / 2)
            {
                lenP = -e;
            }
            else
            {
                lenP = e;
            }
            l2 = l + lenL;
            v2 = v + lenV;
            p2 = p + lenP;
            if ((l > size - 1 && l2 > size - 1) || (v > size - 1 && v2 > size - 1) || (p > size - 1 && p2 > size - 1) 
                || (l < 0 && l2 < 0) || (v < 0 && v2 < 0) || (p < 0 && p2 < 0))
            {
                cout << 0 << endl;
            }
            else
            {
                if (p <= size / 2 - 1)
                {
                    temp1 = 1;
                }
                else
                {
                    temp1 = -1;
                }
                if (l <= size / 2 - 1)
                {
                    temp2 = 1;
                }
                else
                {
                    temp2 = -1;
                }
                if (v <= size / 2 - 1)
                {
                    temp3 = 1;
                }
                else
                {
                    temp3 = -1;
                }
                for (int i = 0, p2 = p; i <= e ; i++, p2 += temp1)
                {
                    for (int j = 0, l2 = l; j <= e; j++, l2 += temp2)
                    {
                        for (int k = 0, v2 = v; k <= e; k++, v2 += temp3)
                        {
                            if (p2 >= 0 && p2 <= size && l2 >= 0 && l2 <= size && v2 >= 0 && v2 <= size && j + k + i <= e && j + k + i >= 0)
                            {
                                suma += cube[ v2 ][ l2 ][ p2 ];
                            }
                        }
                    }
                }   
            }
            cout << suma << endl;
        }

        if (nameOperation == 'O')
        {
            int l;
            int v;
            int p; 
            int r;
            int l2;
            int v2;
            int p2;
            int lenL;
            int lenP;
            int lenV;
            int suma = 0;
            int temp = r;
            int temp1;
            int temp2;
            int temp3;
            cin >> l >> v >> p >> r;

            if (l > size / 2)
            {
                lenL = -r;
            }
            else
            {
                lenL = r;
            }
            if (v > size / 2)
            {
                lenV = -r;
            }
            else
            {
                lenV = r;
            }
            if (p > size / 2)
            {
                lenP = -r;
            }
            else
            {
                lenP = r;
            }
            l2 = l + lenL;
            v2 = v + lenV;
            p2 = p + lenP;
            if ((l > size - 1 && l2 > size - 1) || (v > size - 1 && v2 > size - 1) || (p > size - 1 && p2 > size - 1) 
                || (l < 0 && l2 < 0) || (v < 0 && v2 < 0) || (p < 0 && p2 < 0))
            {
                cout << 0 << endl;
            }
            else
            {
                if (p <= size / 2 - 1)
                {
                    temp1 = 1;
                }
                else
                {
                    temp1 = -1;
                }
                if (l <= size / 2 - 1)
                {
                    temp2 = 1;
                }
                else
                {
                    temp2 = -1;
                }
                if (v <= size / 2 - 1)
                {
                    temp3 = 1;
                }
                else
                {
                    temp3 = -1;
                }
                for (int i = 0, p2 = p; i <= r ; i++, p2 += temp1)
                {
                    
                    for (int j = 0, l2 = l; j <= r; j++, l2 += temp2)
                    {
                        
                        for (int k = 0, v2 = v; k <= r; k++, v2 += temp3)
                        {
                            
                            if (p2 >= 0 && p2 < size && l2 >= 0 && l2 < size && v2 >= 0 && v2 < size &&
                            (p2 - p) * (p2 - p) + (v2 - v) * (v2 - v) + (l2 - l) * (l2 - l) <= r * r)
                            {
                                suma += cube[ v2 ][ l2 ][ p2 ];
                            }
                        }
                    }
                }   
                cout << suma << endl;
            }   
        }
        
        if (nameOperation == 'D')
        {
            char p;
            int num; 
            long long det = 0;
            int sign = 1;
            bool check;
            
            cin >> p >> num;
            
            int tempArray[ 32 ][ 32 ];
            if (p == 'l') 
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        tempArray[ i ][ j ] = cube[ i ][ num ][ j ];
                    }
                }
                for (int i = 0; i < size; i++) 
                {
                    for (int j = i + 1; j < size; j++)
                    {   
                        for (int k = 0; k < size; k++)
                        {
                            if (tempArray[ i ][ k ] == tempArray[ j ][ k ])
                            {
                                check = true;
                            }
                            else
                            {
                                check = false;
                                break;
                            }
                        }
                    }
                }
                if (check == false)
                {
                    cout << Deter (tempArray, size, sign) << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
                
            }
            if (p == 'v')
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        tempArray[ i ][ j ] = cube[ num ][ i ][ j ];
                    }
                }
                for (int i = 0; i < size; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {   
                        for (int k = 0; k < size; k++)
                        {
                            if (tempArray[ i ][ k ] == tempArray[ j ][ k ])
                            {
                                check = true;
                            }
                            else
                            {
                                check = false;
                                break;
                            }
                        }
                    }
                }
                if (check == false)
                {
                    cout << Deter (tempArray, size, sign) << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            if (p == 'p')
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        tempArray[ i ][ j ] = cube[ i ][ j ][ num ];
                    }
                }
                for (int i = 0; i < size; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {   
                        for (int k = 0; k < size; k++)
                        {
                            if (tempArray[ i ][ k ] == tempArray[ j ][ k ])
                            {
                                check = true;
                            }
                            else
                            {
                                check = false;
                                break;
                            }
                        }
                    }
                }
                if (check == false)
                {
                    cout << Deter (tempArray, size, sign) << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
        }
    } 
    while (nameOperation != 'E');
    return 0;
}

