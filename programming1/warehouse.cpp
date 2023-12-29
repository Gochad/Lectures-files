#include <iostream>
using namespace std;

const unsigned short MAX_SIZE = 128;
const unsigned short MAX_PLACES = 65535;

long long int sum = 0;

struct place
{
    unsigned short amount; 
    char label [ 2 ];
};

struct shelf 
{
    place places [ MAX_SIZE ];
    unsigned short placesNumber; 
};

struct rack
{
    shelf shelves [ MAX_SIZE ];
    unsigned short shelvesNumber;
};

struct warehouse
{
    rack racks [ MAX_SIZE ];
    shelf handyShelfWarehouse;
    unsigned short racksNumber;
};

struct Depot 
{
    warehouse warehouses [ MAX_SIZE ];
    shelf handyShelfDepot; 
    rack handyRack;
    unsigned short warehousesNumber; 
    
    void Fill () 
    {
        int W;
        int R;
        int S;
        int P;
        int A;
        sum = 0;
    
        cin >> W >> R >> S >> P >> A;

        if (W == 0 && R == 0 && S == 0 && P == 0)
        {
            warehousesNumber = W;
            handyRack.shelvesNumber = S;
            handyShelfDepot.placesNumber = P;

        }
        else if (W <= MAX_SIZE && R <= MAX_SIZE && S <= MAX_SIZE && P <= MAX_SIZE && W > 0 && R > 0 && S > 0 && P > 0 && A >= 0)
        {
            warehousesNumber = W;
            handyRack.shelvesNumber = S;
            handyShelfDepot.placesNumber = P;
            
            for (int i = 0; i < W; i++)
            {
                warehouses [ i ].racksNumber = R;
                warehouses [ i ].handyShelfWarehouse.placesNumber = P; 

                for (int j = 0; j < R; j++)
                {
                    warehouses [ i ].racks [ j ].shelvesNumber = S;
                    for (int k = 0; k < S; k++)
                    {
                        warehouses [ i ].racks [ j ].shelves [ k ].placesNumber = P;
                        handyRack.shelves [ k ].placesNumber = P; 
                        for (int n = 0; n < P; n++)
                        {
                            if (A >= MAX_PLACES)
                            {
                                warehouses [ i ].racks [ j ].shelves [ k ].places [ n ].amount = MAX_PLACES; 
                                sum += MAX_PLACES;
                            }
                            else
                            {
                                warehouses [ i ].racks [ j ].shelves [ k ].places [ n ].amount = A; 
                                sum += A;
                            }
                        }
                    }
                }
            }
            
            for (int i = 0; i < handyRack.shelvesNumber; i++) 
            {
                for (int j = 0; j < handyRack.shelves [ i ].placesNumber; j++)
                {
                    handyRack.shelves [ i ].places [ j ].amount = A;
                    sum += A;
                }
            }
            for (int i = 0; i < handyShelfDepot.placesNumber; i++) 
            {
                handyShelfDepot.places [ i ].amount = A; 
                sum += A;
            }
            for (int i = 0; i < warehousesNumber; i++) 
            {
                for (int j = 0; j < warehouses [ i ].handyShelfWarehouse.placesNumber; j++)
                {
                    warehouses [ i ].handyShelfWarehouse.places [ j ].amount = A; 
                    sum += A;
                }
            } 
        }
        else if (W == 0 || R == 0)
        {
            if (S == 0)
            {
                handyShelfDepot.placesNumber = P;
                for (int i = 0; i < P; i++) 
                {
                    handyShelfDepot.places [ i ].amount = A; 
                    sum += A;
                }
            }
            else
            {
                handyRack.shelvesNumber = S;
                handyShelfDepot.placesNumber = P;
                for (int i = 0; i < P; i++) 
                {
                    handyShelfDepot.places [ i ].amount = A; 
                    sum += A;
                }
                for (int i = 0; i < S; i++) 
                {
                    for (int j = 0; j < P; j++)
                    {
                        handyRack.shelves [ i ].places [ j ].amount = A;
                        sum += A;
                    }
                }
                
            }
            
        }
        else
        {
            cout << "error" << endl;
        }     
    };   
};

Depot depot;


int main ()
{
    char operation [ 7 ];
    do
    {
        cin >> operation;
        
        
        if (operation [ 0 ]== 'F')
        {
            depot.Fill ();
        }
        else if (operation [ 0 ] == 'S')
        {
            if (operation [ 4 ] == 'A') 
            {
                if (operation [ 5 ] == 'P')
                {
                    int w;
                    int r;
                    int s;
                    int P;
                    cin >> w >> r >> s >> P;
                    if (w >= 0 && w < MAX_SIZE && r >= 0 && r < MAX_SIZE && s >= 0 && s < MAX_SIZE && P >= 0 && P <= MAX_SIZE && w < depot.warehousesNumber && r < depot.warehouses [ w ]. racksNumber && s < depot.warehouses [ w ].racks [ r ].shelvesNumber)
                    { 
                        if (depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber < P)
                        {
                            for (int i = depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber; i < P; i++)
                            {
                                depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ i ].amount = 0;
                            }
                        }
                        else if (depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber > P)
                        {
                            for (int i = P; i < depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber; i++)
                            {
                                sum -= depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ i ].amount;
                                depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ i ].amount = 0;
                            }
                        }
                        
                        depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber = P;
                    }
                    else 
                    {
                        cout << "error" << endl;
                    }
                    
                }
                else if (operation [ 5 ]== 'S') 
                {
                    int w;
                    int r;
                    int s;
                    int p;
                    cin >> w >> r >> s >> p;
                    if (w >= 0 && w < MAX_SIZE && r >= 0 && r < MAX_SIZE && s >= 0 && s <= MAX_SIZE && p >= 0 && p <= MAX_SIZE && w < depot.warehousesNumber && r < depot.warehouses [ w ]. racksNumber)
                    {
                        depot.warehouses [ w ].racks [ r ].shelvesNumber = s;
                        
                        for (int i = 0; i < s; i++)
                        {
                            depot.warehouses [ w ].racks [ r ].shelves [ i ].placesNumber = p;
                        }
                        
                        for (int i = s; i < MAX_SIZE; i++)
                        {
                            for (int j = 0; j < MAX_SIZE; j++)
                            {
                                sum -= depot.warehouses [ w ].racks [ r ].shelves [ i ].places [ j ].amount;
                                depot.warehouses [ w ].racks [ r ].shelves [ i ].places [ j ].amount = 0;
                            
                            }
                        } 
                        
                        for (int i = 0; i < s; i++)
                        {
                            for (int j = p; j < MAX_SIZE; j++)
                            {
                                sum -= depot.warehouses [ w ].racks [ r ].shelves [ i ].places [ j ].amount;
                                depot.warehouses [ w ].racks [ r ].shelves [ i ].places [ j ].amount = 0;
                            }
                        }
                        
                        
                        
                    }
                    else
                    {
                        cout << "error" << endl;
                    }

                }
                else if (operation [ 5 ]== 'R')
                {
                    int w;
                    int r;
                    int s;
                    int p;
                    cin >> w >> r >> s >> p;
                    if (w >= 0 && w < MAX_SIZE && r >= 0 && r <= MAX_SIZE && s >= 0 && s <= MAX_SIZE && p >= 0 && p <= MAX_SIZE && w < depot.warehousesNumber)
                    {
                        depot.warehouses [ w ].racksNumber = r;
                        for (int i = 0; i < r; i ++)
                        {
                            depot.warehouses [ w ].racks [ i ].shelvesNumber = s;
                            for (int j = 0; j < s; j++)
                            {
                                depot.warehouses [ w ].racks [ i ].shelves [ j ].placesNumber = p;
                            }
                        }
                        for (int i = r; i < MAX_SIZE; i++)
                        {
                            for (int j = s; j < MAX_SIZE; j++)
                            {
                                for (int k = p; k < MAX_SIZE; k++)
                                {
                                    sum -= depot.warehouses [ w ].racks [ i ].shelves [ j ].places [ k ].amount;
                                    depot.warehouses [ w ].racks [ i ].shelves [ j ].places [ k ].amount = 0;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ]== 'W') 
                {
                    int w;
                    int r;
                    int s;
                    int p;
                    cin >> w >> r >> s >> p;
                    if (w >= 0 && w <= MAX_SIZE && r >= 0 && r <= MAX_SIZE && s >= 0 && s <= MAX_SIZE && p >= 0 && p <= MAX_SIZE)
                    {
                        for (int n = w; n < MAX_SIZE; n++)
                        {
                            for (int i = r; i < MAX_SIZE; i++)
                            {
                                for (int j = s; j < MAX_SIZE; j++)
                                {
                                    for (int k = p; k < MAX_SIZE; k++)
                                    {
                                        sum -= depot.warehouses [ n ].racks [ i ].shelves [ j ].places [ k ].amount;
                                        depot.warehouses [ n ].racks [ i ].shelves [ j ].places [ k ].amount = 0;
                                    }
                                }
                            }
                        }
                        
                        for (int i = w; i < MAX_SIZE; i++)
                        {
                            for (int j = 0; j < MAX_SIZE; j++)
                            {
                                sum -= depot.warehouses [ i ].handyShelfWarehouse.places [ j ].amount;
                                depot.warehouses [ i ].handyShelfWarehouse.places [ j ].amount = 0;
                            }
                        }

                        depot.warehousesNumber = w;
                        
                        for (int k = 0; k < w; k++)
                        {
                            depot.warehouses [ k ].racksNumber = r;
                            for (int i = 0; i < r; i++)
                            {
                                depot.warehouses [ k ].racks [ i ].shelvesNumber = s;
                                for (int j = 0; j < s; j++)
                                {
                                    depot.warehouses [ k ].racks [ i ].shelves [ j ].placesNumber = p;
                                    
                                }
                            }
                        }
                        if ( w == 0)
                        {
                            depot.warehouses [ w ].racksNumber = r;
                            if (r == 0)
                            {
                                
                                if (s == 0)
                                {
                                    depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber = p;
                                }
                            }
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }

                }
            }
            else if (operation [ 4 ] == 'H')
            {
                if (operation [ 5 ] == 'W') 
                {
                    int w;
                    int P;
                    cin >> w >> P;
                    if (w >= 0 && w < MAX_SIZE && P >= 0 && P <= MAX_SIZE && w < depot.warehousesNumber)
                    {
                        depot.warehouses [ w ].handyShelfWarehouse.placesNumber = P;
                        for (int i = P; i < MAX_SIZE; i++)
                        {
                            sum -= depot.warehouses [ w ].handyShelfWarehouse.places [ i ].amount;
                            depot.warehouses [ w ].handyShelfWarehouse.places [ i ].amount = 0;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ] == 'R')
                {
                    int S;
                    int P;
                    cin >> S >> P;
                    if (S >= 0 && S <= MAX_SIZE && P >= 0 && P <= MAX_SIZE)
                    {
                        depot.handyRack.shelvesNumber = S;
                        for (int i = 0; i < S; i++)
                        {
                            depot.handyRack.shelves [ i ].placesNumber = P;
                        }
                        for (int i = S; i < MAX_SIZE; i++)
                        {
                            for (int j = 0; j < MAX_SIZE; j++)
                            {   
                                sum -= depot.handyRack.shelves [ i ].places [ j ].amount;
                                depot.handyRack.shelves [ i ].places [ j ].amount = 0;          
                            }
                        }
                        for (int i = 0; i < S; i++)
                        {
                            for (int j = P; j < MAX_SIZE; j++)
                            {   
                                sum -= depot.handyRack.shelves [ i ].places [ j ].amount;
                                depot.handyRack.shelves [ i ].places [ j ].amount = 0;          
                            }
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ] == 'S')
                {
                    int P;
                    cin >> P;
                    if (P >= 0 && P <= MAX_SIZE)
                    {
                        depot.handyShelfDepot.placesNumber = P;
                        for (int i = P; i < MAX_SIZE; i++)
                        {
                            sum -= depot.handyShelfDepot.places [ i ].amount;
                            depot.handyShelfDepot.places [ i ].amount = 0;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
            }
            else if (operation [ 4 ] == 'L')
            {
                if (operation [ 5 ] == 'W') 
                {   
                    int w;
                    int r;
                    int s;
                    int p;
                    char dd [ 3 ];
                    cin >> w >> r >> s >> p >> dd;
                    if (w >= 0 && w < depot.warehousesNumber && depot.warehousesNumber > 0 
                    && r >= 0 && r < depot.warehouses [ 0 ].racksNumber && depot.warehouses [ 0 ].racksNumber > 0
                    && s >= 0 && s < depot.warehouses [ 0 ].racks [ 0 ].shelvesNumber && depot.warehouses [ 0 ].racks [ 0 ].shelvesNumber > 0
                    && p >= 0 && p < depot.warehouses [ 0 ].racks [ 0 ].shelves [ 0 ].placesNumber && depot.warehouses [ 0 ].racks [ 0 ].shelves [ 0 ].placesNumber > 0)
                    {
                        depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].label [ 0 ]= dd [ 0 ];
                        depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].label [ 1 ]= dd [ 1 ];
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                    
                }
                else if (operation [ 5 ]== 'H')
                {
                    int w;
                    int p;
                    char dd [ 3 ];
                    cin >> w >> p >> dd;
                    if (w >= 0 && w < MAX_SIZE && depot.warehousesNumber > 0 && w < depot.warehousesNumber
                    && p >= 0 && p < MAX_SIZE && depot.warehouses[ 0 ].handyShelfWarehouse.placesNumber > 0 && p < depot.warehouses[ 0 ].handyShelfWarehouse.placesNumber)
                    {
                        depot.warehouses [ w ].handyShelfWarehouse.places [ p ].label [ 0 ] = dd [ 0 ];
                        depot.warehouses [ w ].handyShelfWarehouse.places [ p ].label [ 1 ] = dd [ 1 ];
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
    
                }
                else if (operation [ 5 ]== 'R')
                {
                    int s;
                    int p;
                    char dd [ 3 ];
                    cin >> s >> p >> dd;
                    if (s >= 0 && depot.handyRack.shelvesNumber > 0 && s < depot.handyRack.shelvesNumber
                    && p >= 0 && p < depot.handyRack.shelves [ 0 ].placesNumber && depot.handyRack.shelves [ 0 ].placesNumber > 0)
                    {
                        depot.handyRack.shelves [ s ].places [ p ].label [ 0 ] = dd [ 0 ];
                        depot.handyRack.shelves [ s ].places [ p ].label [ 1 ] = dd [ 1 ];
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                    
                }
                else if (operation [ 5 ]== 'S')
                {
                    int p;
                    char dd [ 3 ];
                    cin >> p >> dd;
                    if (p >= 0 && p < depot.handyShelfDepot.placesNumber && depot.handyShelfDepot.placesNumber > 0)
                    {
                        depot.handyShelfDepot.places [ p ].label [ 0 ] = dd [ 0 ];
                        depot.handyShelfDepot.places [ p ].label [ 1 ] = dd [ 1 ];
                    }
                    else
                    {
                        cout << "error" << endl;
                    }     
                }
            }

        }
        
        else if (operation [ 0 ] == 'P')
        {
            if (operation [ 1 ] == 'U') 
            {
                if (operation  [ 4 ] == 'W')
                {
                    int w;
                    int r;
                    int s;
                    int p;
                    int A;
                    cin >> w >> r >> s >> p >> A;
                    if (w >= 0 && r >= 0 && s >= 0 && p >= 0 && A >= 0 && w < depot.warehousesNumber && r < depot.warehouses [ w ].racksNumber 
                    && s < depot.warehouses [ w ].racks [ r ].shelvesNumber && p < depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber)
                    {
                        if ( (depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount + A ) >= MAX_PLACES)
                        {
                            sum -= depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount;
                            depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount = MAX_PLACES;
                            sum += MAX_PLACES;
                        }
                        else
                        {
                            depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount += A;
                            sum += A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }

                }
                else if (operation [ 4 ] == 'H')
                {
                    int w;
                    int p;
                    int A;
                    cin >> w >> p >> A;
                    if (w >= 0 && p >= 0 && A >= 0 && w < depot.warehousesNumber && p < depot.warehouses [ w ].handyShelfWarehouse.placesNumber)
                    {
                        if ((depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount + A) >= MAX_PLACES)
                        {
                            sum -= depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount;
                            depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount = MAX_PLACES;
                            sum += MAX_PLACES;
                        }
                        else
                        {
                            depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount += A;
                            sum += A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }

                }
                else if (operation [ 4 ] == 'R')
                {
                    int s;
                    int p;
                    int A;
                    cin >> s >> p >> A;
                    if (s >= 0 && p >= 0 && A >= 0 && s < depot.handyRack.shelvesNumber && p < depot.handyRack.shelves [ s ].placesNumber)
                    {
                        if ((depot.handyRack.shelves [ s ].places [ p ].amount + A) >= MAX_PLACES)
                        {
                            sum -= depot.handyRack.shelves [ s ].places [ p ].amount;
                            depot.handyRack.shelves [ s ].places [ p ].amount = MAX_PLACES;
                            sum += MAX_PLACES;
                        }
                        else
                        {
                            depot.handyRack.shelves [ s ].places [ p ].amount += A;
                            sum += A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }   
                else if (operation [ 4 ]== 'S')
                {
                    int p;
                    int A;
                    cin >> p >> A;
                    if (p >= 0 && p < depot.handyShelfDepot.placesNumber && A >= 0)
                    {
                        if ((depot.handyShelfDepot.places [ p ].amount + A) >= MAX_PLACES)
                        {
                            sum -= depot.handyShelfDepot.places [ p ].amount;
                            depot.handyShelfDepot.places [ p ].amount = MAX_PLACES;
                            sum += MAX_PLACES;
                        }
                        else
                        {
                            depot.handyShelfDepot.places [ p ].amount += A;
                            sum += A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
            }
            else if (operation [ 1 ] == 'O')
            {
                if (operation [ 4 ]== 'W')
                {
                    int w;
                    int r;
                    int s;
                    int p;
                    int A;
                    cin >> w >> r >> s >> p >> A;
                    if (w >= 0 && r >= 0 && s >= 0 && p >= 0 && w < depot.warehousesNumber && r < depot.warehouses [ w ].racksNumber && s < depot.warehouses [ w ].racks [ r ].shelvesNumber
                    && p < depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber && A >= 0)
                    {
                        if ((depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount - A) < 0)
                        {
                            sum -= depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount;
                            depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount = 0;
                        }
                        else
                        {
                            sum -= A;
                            depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount -= A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 4 ]== 'H')
                {
                    int w;
                    int p;
                    int A;
                    cin >> w >> p >> A;
                    if (w >= 0 && p >= 0 && w < depot.warehousesNumber && p < depot.warehouses [ w ].handyShelfWarehouse.placesNumber && A >= 0)
                    {
                        if ((depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount - A) <= 0)
                        {
                            sum -= depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount;
                            depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount = 0;
                        }
                        else
                        {
                            sum -= A;
                            depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount -= A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 4 ]== 'R')
                {
                    int s;
                    int p;
                    int A;
                    cin >> s >> p >> A;
                    if (s >= 0 && p >= 0 && s < depot.handyRack.shelvesNumber && p < depot.handyRack.shelves [ s ].placesNumber)
                    {
                        if ((depot.handyRack.shelves [ s ].places [ p ].amount - A) <= 0)
                        {
                            sum -= depot.handyRack.shelves [ s ].places [ p ].amount;
                            depot.handyRack.shelves [ s ].places [ p ].amount = 0;
                        }
                        else
                        {
                            sum -= A;
                            depot.handyRack.shelves [ s ].places [ p ].amount -= A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 4 ]== 'S')
                {
                    int p;
                    int A;
                    cin >> p >> A;
                    if (p >= 0 && p < depot.handyShelfDepot.placesNumber && A >= 0)
                    {
                        if ((depot.handyShelfDepot.places [ p ].amount - A) <= 0)
                        {
                            sum -= depot.handyShelfDepot.places [ p ].amount;
                            depot.handyShelfDepot.places [ p ].amount = 0;
                        }
                        else
                        {
                            depot.handyShelfDepot.places [ p ].amount -= A;
                            sum -= A;
                        }
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
            }
        }
        else if (operation [ 0 ] == 'M')
        {
            if (operation [ 4 ] == 'W')
            {
                int w1;
                int w2;
                int r1;
                int r2;
                int s1;
                int s2;
                int p;
                int A;
                cin >> w1 >> r1 >> s1 >> w2 >> r2 >> s2 >> p >> A;
                if (w1 >= 0 && w2 >= 0 && r1 >= 0 && r2 >= 0 && s1 >= 0 && s2 >= 0 && p >=0 && w1 < depot.warehousesNumber && w2 < depot.warehousesNumber
                && r1 < depot.warehouses [ w1 ].racksNumber && r2 < depot.warehouses [ w2 ].racksNumber && s1 < depot.warehouses [ w1 ].racks [ r1 ].shelvesNumber
                && s2 < depot.warehouses [ w2 ].racks [ r2 ].shelvesNumber && p < depot.warehouses [ w1 ].racks [ r1 ].shelves [ s1 ].placesNumber &&
                p < depot.warehouses [ w2 ].racks [ r2 ].shelves [ s2 ].placesNumber)
                {
                    if (depot.warehouses [ w1 ].racks [ r1 ].shelves [ s1 ].places [ p ].amount < A)
                    {
                        A = depot.warehouses [ w1 ].racks [ r1 ].shelves [ s1 ].places [ p ].amount;
                    }
                    if ((depot.warehouses [ w2 ].racks [ r2 ].shelves [ s2 ].places [ p ].amount + A) > MAX_PLACES)
                    {
                        A = MAX_PLACES - depot.warehouses [ w2 ].racks [ r2 ].shelves [ s2 ].places [ p ].amount;
                    }
                    depot.warehouses [ w1 ].racks [ r1 ].shelves [ s1 ].places [ p ].amount -= A;
                    depot.warehouses [ w2 ].racks [ r2 ].shelves [ s2 ].places [ p ].amount += A;
                    

                }
                else
                {
                    cout << "error" << endl;
                }

            }
            else if (operation [ 4 ] == 'H')
            {
                int w;
                int r;
                int s;
                int p;
                int A;
                cin >> w >> r >> s >> p >> A;
                if (w >= 0 && r >= 0 && s >= 0 && p >= 0 && w < depot.warehousesNumber && r < depot.warehouses [ w ].racksNumber 
                && s < depot.warehouses [ w ].racks [ r ].shelvesNumber && p < depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber
                && p < depot.handyShelfDepot.placesNumber)
                {
                    if (depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount < A)
                    {
                        A = depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount;
                    }
                    if ((depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount + A) > MAX_PLACES)
                    {
                        A = MAX_PLACES - depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount;
                    }
                    depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].amount -= A;
                    depot.warehouses [ w ].handyShelfWarehouse.places [ p ].amount += A;
                }
                else
                {
                    cout << "error" << endl;
                }
            }
            else if (operation [ 4 ] == 'R')
            {
                int w;
                int r;
                int s1;
                int s2;
                int p;
                int A;
                cin >> w >> r >> s1 >> s2 >> p >> A;
                if (w >= 0 && w < depot.warehousesNumber && r >= 0 && r < depot.warehouses [ w ].racksNumber && s1 >= 0 && s1 < depot.warehouses [ w ].racks [ r ].shelvesNumber
                && p < depot.warehouses [ w ].racks [ r ].shelves [ s1 ].placesNumber && s2 >= 0 && s2 < depot.warehouses [ w ].racks [ r ].shelvesNumber
                && p < depot.warehouses [ w ].racks [ r ].shelves [ s2 ].placesNumber && A >= 0)
                {
                    if (depot.warehouses [ w ].racks [ r ].shelves [ s1 ].places [ p ].amount < A)
                    {
                        A = depot.warehouses [ w ].racks [ r ].shelves [ s1 ].places [ p ].amount;
                    }
                    if ((depot.handyRack.shelves [ s2 ].places [ p ].amount + A) > MAX_PLACES)
                    {
                        A = MAX_PLACES - depot.handyRack.shelves [ s2 ].places [ p ].amount;
                    }
                    depot.warehouses [ w ].racks [ r ].shelves [ s1 ].places [ p ].amount -= A;
                    depot.handyRack.shelves [ s2 ].places [ p ].amount += A;
                }
                else
                {
                    cout << "error" << endl;
                }
            }
            else if (operation [ 4 ] == 'S')
            
            {
                int s;
                int p;
                int A;
                cin >> s >> p >> A;
                if (s >= 0 && s < depot.handyRack.shelvesNumber && p >= 0 && p < depot.handyRack.shelves [ s ].placesNumber && p < depot.handyShelfDepot.placesNumber)
                {
                    if (depot.handyRack.shelves [ s ].places [ p ].amount < A)
                    {
                        A = depot.handyRack.shelves [ s ].places [ p ].amount;
                    }
                    if ((depot.handyShelfDepot.places [ p ].amount + A) > MAX_PLACES)
                    {
                        A = MAX_PLACES - depot.handyShelfDepot.places [ p ].amount;
                    }
                    depot.handyRack.shelves [ s ].places [ p ].amount -= A;
                    depot.handyShelfDepot.places [ p ].amount += A;
                }
                else
                {
                    cout << "error" << endl;
                }
            }
        }
        
        else if (operation [ 0 ] == 'G')
        {
            if (operation [ 4 ]== 'E')
            {
                cout << sum << endl;
            }
            else if (operation [ 4 ] == 'W')
            {
                int w;
                unsigned long long sumW = 0;
                cin >> w;
                if (w >= 0 && w < depot.warehousesNumber)
                {
                    for (int i = 0; i < depot.warehouses [ w ].racksNumber; i++)
                    {
                        for (int j = 0; j < depot.warehouses [ w ].racks [ i ].shelvesNumber; j++)
                        {
                            for (int k = 0; k < depot.warehouses [ w ].racks [ i ].shelves [ j ].placesNumber; k++)
                            {
                                sumW += depot.warehouses [ w ].racks [ i ].shelves [ j ].places [ k ].amount;
                            }
                        }
                    }
                    for (int i = 0; i < depot.warehouses [ w ].handyShelfWarehouse.placesNumber; i++)
                    {
                        sumW += depot.warehouses [ w ].handyShelfWarehouse.places [ i ].amount;
                    }
                    cout << sumW << endl;
                }
                else
                {
                    cout << "error" << endl;
                }
            }
            else if (operation [ 4 ] == 'R')
            {
                if (operation [ 5 ]== 'W')
                {
                    unsigned long long sumRw = 0;
                    int w;
                    int r;
                    cin >> w >> r;
                    if (w >= 0 && w < depot.warehousesNumber && r >= 0 && r < MAX_SIZE && r < depot.warehouses [ w ].racksNumber)
                    {
                        for (int  i = 0; i < depot.warehouses [ w ].racks [ r ]. shelvesNumber; i++)
                        {
                            for (int j = 0; j < depot.warehouses [ w ]. racks [ r ]. shelves [ i ].placesNumber; j++)
                            {
                                sumRw += depot.warehouses [ w ]. racks [ r ]. shelves [ i ].places [ j ].amount;
                            }
                        }
                        cout << sumRw << endl;
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                    
                }
                else if (operation [ 5 ]== 'H')
                {
                    unsigned long long sumRh = 0;

                    for (int i = 0; i < depot.handyRack.shelvesNumber; i++)
                    {
                        for (int j = 0; j < depot.handyRack.shelves [ i ].placesNumber; j++)
                        {
                            sumRh += depot.handyRack.shelves [ i ].places [ j ].amount;
                        }
                    }
                    cout << sumRh << endl;
                }
            }
            else if (operation [ 4 ] == 'S')
            {
                if (operation [ 5 ] == 'W')
                { 
                    int w;
                    int r;
                    int s;
                    cin >> w >> r >> s;
                    if (w >= 0 && w < depot.warehousesNumber && depot.warehousesNumber > 0 
                    && r >= 0 && r < depot.warehouses [ 0 ].racksNumber && depot.warehouses [ 0 ].racksNumber > 0
                    && s >= 0 && s < depot.warehouses [ 0 ].racks [ 0 ].shelvesNumber && depot.warehouses [ 0 ].racks [ 0 ].shelvesNumber > 0)
                    {
                        unsigned long long sumSh = 0;
                        
                        for (int i = 0; i < depot.warehouses [ w ].racks [ r ].shelves [ s ].placesNumber; i++)
                        {
                            sumSh += depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ i ].amount;
                        }
                        
                        cout << sumSh << endl;
                    }
                    else
                    {
                        cout << "error" <<endl;
                    }
                    
                }
                else if (operation [ 5 ] == 'H')
                {
                    unsigned long long sumSh = 0;
                    int w;
                    cin >> w;
                    if (w >= 0 && w < depot.warehousesNumber)
                    {
                        for (int i = 0; i < depot.warehouses [ w ].handyShelfWarehouse.placesNumber; i++)
                        {
                            sumSh += depot.warehouses [ w ].handyShelfWarehouse. places [ i ].amount;
                        }
                        
                        cout << sumSh << endl;
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ] == 'R')
                {
                    int s;
                    cin >> s;
                    if (s >= 0 && depot.handyRack.shelvesNumber > 0 && s < depot.handyRack.shelvesNumber)
                    {
                        unsigned long long sumSr = 0;
                        for (int i = 0; i < depot.handyRack.shelves [ s ].placesNumber; i++)
                        {
                            sumSr += depot.handyRack.shelves [ s ].places [ i ].amount;
                        }
                        cout << sumSr << endl;
                    }   
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ] == '\0')
                {
                    unsigned long long sumS = 0;
                    if (depot.handyShelfDepot.placesNumber > 0)
                    {
                        for (int i = 0; i < depot.handyShelfDepot.placesNumber; i++)
                        {
                            sumS += depot.handyShelfDepot.places [ i ].amount;
                        }
                        cout << sumS << endl;
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                    
                }
            }
            else if (operation [ 4 ] == 'L')
            {
                if (operation [ 5 ]== 'W')
                {
                    int w;
                    int r;
                    int s;
                    int p;
                    cin >> w >> r >> s >> p;
                    if (w >= 0 && w < depot.warehousesNumber && depot.warehousesNumber > 0 
                    && r >= 0 && r < depot.warehouses [ 0 ].racksNumber && depot.warehouses [ 0 ].racksNumber > 0
                    && s >= 0 && s < depot.warehouses [ 0 ].racks [ 0 ].shelvesNumber && depot.warehouses [ 0 ].racks [ 0 ].shelvesNumber > 0
                    && p >= 0 && p < depot.warehouses [ 0 ].racks [ 0 ].shelves [ 0 ].placesNumber && depot.warehouses [ 0 ].racks [ 0 ].shelves [ 0 ].placesNumber > 0)
                    {
                        if (depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].label [ 0 ] != '\0')
                        {
                            cout << depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].label [ 0 ] << depot.warehouses [ w ].racks [ r ].shelves [ s ].places [ p ].label [ 1 ] << endl;
                        }
                        else
                        {
                            cout << "--" << endl;
                        }
                        
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                   
                }
                else if (operation [ 5 ]== 'H')
                {
                    int w;
                    int p;
                    cin >> w >> p;
                    if (w >= 0 && depot.warehousesNumber > 0 && w < depot.warehousesNumber
                    && p >= 0 && depot.warehouses[ 0 ].handyShelfWarehouse.placesNumber > 0 && p < depot.warehouses[ 0 ].handyShelfWarehouse.placesNumber)
                    {
                        if (depot.warehouses [ w ].handyShelfWarehouse.places [ p ].label [ 0 ] != '\0')
                        {
                            cout << depot.warehouses [ w ].handyShelfWarehouse.places [ p ].label [ 0 ] << depot.warehouses [ w ].handyShelfWarehouse.places [ p ].label [ 1 ] << endl;
                        }
                        else
                        {
                            cout << "--" << endl;
                        }
                        
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ]== 'R')
                {
                    int s;
                    int p;
                    cin >> s >> p;
                    if (s >= 0 && depot.handyRack.shelvesNumber > 0 && s < depot.handyRack.shelvesNumber
                    && p >= 0 && p < depot.handyRack.shelves [ 0 ].placesNumber && depot.handyRack.shelves [ 0 ].placesNumber > 0)
                    {
                        if (depot.handyRack.shelves [ s ].places [ p ].label [ 0 ] != '\0')
                        {
                            cout << depot.handyRack.shelves [ s ].places [ p ].label [ 0 ] << depot.handyRack.shelves [ s ].places [ p ].label [ 1 ] << endl;
                        }
                        else
                        {
                            cout << "--" << endl;
                        }
                        
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                }
                else if (operation [ 5 ]== 'S')
                {
                    int p;
                    cin >> p;
                    if (p >= 0 && p < depot.handyShelfDepot.placesNumber && depot.handyShelfDepot.placesNumber > 0)
                    {
                        if (depot.handyShelfDepot.places [ p ].label [ 0 ] != '\0')
                        {
                            cout << depot.handyShelfDepot.places [ p ].label [ 0 ] << depot.handyShelfDepot.places [ p ].label [ 1 ] << endl;
                        }
                        else
                        {
                            cout << "--" << endl;
                        }
                        
                    }
                    else
                    {
                        cout << "error" << endl;
                    }
                    
                }
            }
        }
    } 
    while (operation [ 0 ] != 'E');
    return 0;
}