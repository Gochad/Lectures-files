#include <iostream>

using namespace std;

int main()
{
    int N;
    int i = 0;
    int punktyGracza1;
    int punktyGracza2;

    float wygraneA = 0;
    float wygraneB = 0;
    float wygraneC = 0;
    float wygraneD = 0;
    float wygraneE = 0;

    float przegraneA = 0;
    float przegraneB = 0;
    float przegraneC = 0;
    float przegraneD = 0;
    float przegraneE = 0;

    float remisyA = 0;
    float remisyB = 0;
    float remisyC = 0;
    float remisyD = 0;
    float remisyE = 0;

    int iloscGierA = 0;
    int iloscGierB = 0;
    int iloscGierC = 0;
    int iloscGierD = 0;
    int iloscGierE = 0;

    char idGracza1;
    char idGracza2;

    int liczba1_1;
    int liczba1_2;
    int liczba1_3;
    int liczba1_4;
    int liczba2_1;
    int liczba2_2;
    int liczba2_3;
    int liczba2_4;

    cin >> N;
    while (i < N)
    {
        punktyGracza1 = 0;
        punktyGracza2 = 0;
        cin >> idGracza1 >> liczba1_1 >> liczba1_2 >> liczba1_3 >> liczba1_4 >> idGracza2 >> liczba2_1 >> liczba2_2 >> liczba2_3 >> liczba2_4;
        
        if (punktyGracza1 == 0)
        {
            if (liczba1_1 == liczba1_2 && liczba1_1 == liczba1_3 && liczba1_1 == liczba1_4 && liczba1_2 == liczba1_4 && liczba1_3 == liczba1_4 && liczba1_2 == liczba1_2)
            {
                punktyGracza1 = 500 + liczba1_1;
            }
        }
        if (punktyGracza1 == 0)
        {
            if (liczba1_1 != liczba1_2 && liczba1_1 != liczba1_3 && liczba1_1 != liczba1_4 && liczba1_2 != liczba1_3 && liczba1_2 != liczba1_4 && liczba1_3 != liczba1_4)
            {
                punktyGracza1 = 300;
            }
        }
        if (punktyGracza1 == 0)
        {
            if (liczba1_1 == liczba1_2 && liczba1_3 == liczba1_4)
            {
                if (liczba1_1 > liczba1_3)
                {
                    punktyGracza1 = 200 + 5 * liczba1_1 + liczba1_3;
                }
                else
                {
                    punktyGracza1 = 200 + 5 * liczba1_3 + liczba1_1;
                }
            }

            if (liczba1_1 == liczba1_3 && liczba1_2 == liczba1_4)
            {
                if (liczba1_1 > liczba1_2)
                {
                    punktyGracza1 = 200 + 5 * liczba1_1 + liczba1_2;
                }
                else
                {
                    punktyGracza1 = 200 + 5 * liczba1_2 + liczba1_1;
                }
            }
            
            if (liczba1_1 == liczba1_4 && liczba1_2 == liczba1_3)
            {
                if (liczba1_1 > liczba1_3)
                {
                    punktyGracza1 = 200 + 5 * liczba1_1 + liczba1_3;
                }
                else
                {
                    punktyGracza1 = 200 + 5 * liczba1_3 + liczba1_1;
                }
            }
        }
        if (punktyGracza1 == 0)
        {
            if (liczba1_1 == liczba1_2 && liczba1_1 == liczba1_3 && liczba1_3 == liczba1_2)
            {
                punktyGracza1 = 125 + 5 * liczba1_1 + liczba1_4;
            }
            if(liczba1_1 == liczba1_2 && liczba1_1 == liczba1_4 && liczba1_2 == liczba1_4)
            {
                punktyGracza1 = 125 + 5 * liczba1_1 + liczba1_3;
            }   
            if(liczba1_3 == liczba1_2 && liczba1_2 == liczba1_4 && liczba1_3 == liczba1_4)
            {
                punktyGracza1 = 125 + 5 * liczba1_3 + liczba1_1;
            }           
            if(liczba1_1 == liczba1_3 && liczba1_1 == liczba1_4 && liczba1_3 == liczba1_4)
            {
                punktyGracza1 = 125 + 5 * liczba1_1 + liczba1_2;
            }
        }
        if (punktyGracza1 == 0)
        {
            if (liczba1_1 == liczba1_2)
            {
                punktyGracza1 = 50 + 5 * liczba1_1 + liczba1_3 + liczba1_4;
            }
            if (liczba1_1 == liczba1_3)
            {
                punktyGracza1 = 50 + 5 * liczba1_1 + liczba1_2 + liczba1_4;
            }  
            if (liczba1_1 == liczba1_4)
            {
                punktyGracza1 = 50 + 5 * liczba1_1 + liczba1_2 + liczba1_3;
            } 
            if (liczba1_2 == liczba1_3)
            {
                punktyGracza1 = 50 + 5 * liczba1_2 + liczba1_1 + liczba1_4;
            }      
            if (liczba1_2 == liczba1_4)
            {
                punktyGracza1 = 50 + 5 * liczba1_2 + liczba1_1 + liczba1_3;
            }      
            if (liczba1_3 == liczba1_4)
            {
                punktyGracza1 = 50 + 5 * liczba1_3 + liczba1_1 + liczba1_2;
            } 
        }
        if (punktyGracza2 == 0)
            {
            if (liczba2_1 == liczba2_2 && liczba2_1 == liczba2_3 && liczba2_1 == liczba2_4 && liczba2_2 == liczba2_3 && liczba2_2 == liczba2_4 && liczba2_3 == liczba2_4)
            {
                punktyGracza2 = 500 + liczba2_1;
            }
        }
        if (punktyGracza2 == 0)
        {
            if (liczba2_1 != liczba2_2 && liczba2_1 != liczba2_3 && liczba2_1 != liczba2_4 && liczba2_2 != liczba2_3 && liczba2_2 != liczba2_4 && liczba2_3 != liczba2_4)
            {
                punktyGracza2 = 300;
            }
        } 
        if (punktyGracza2 == 0)
        {
            if (liczba2_1 == liczba2_2 && liczba2_3 == liczba2_4)
            {
                if (liczba2_1 > liczba2_3)
                {
                    punktyGracza2 = 200 + 5 * liczba2_1 + liczba2_3;
                }
                else
                {
                    punktyGracza2 = 200 + 5 * liczba2_3 + liczba2_1;
                }
            }
            if (liczba2_1 == liczba2_3 && liczba2_2 == liczba2_4)
            {
                if (liczba2_1 > liczba2_2)
                {
                    punktyGracza2 = 200 + 5 * liczba2_1 + + liczba2_2;
                }
                else
                {
                    punktyGracza2 = 200 + 5 * liczba2_2 + liczba2_1;
                }
            }
                
            if (liczba2_1 == liczba2_4 && liczba2_2 == liczba2_3)
            {
                if (liczba2_1 > liczba2_3)
                {
                    punktyGracza2 = 200 + 5 * liczba2_1 + liczba2_3;
                }
                else
                {
                    punktyGracza2 = 200 + 5 * liczba2_3 + liczba2_1;
                }
            } 
        }
        if (punktyGracza2 == 0)
        {
            if (liczba2_1 == liczba2_2 && liczba2_2 == liczba2_3 && liczba2_1 == liczba2_3)
            {
                punktyGracza2 = 125 + 5 * liczba2_1 + liczba2_4;
            }
            if (liczba2_1 == liczba2_2 && liczba2_1 == liczba2_4 && liczba2_2 == liczba2_4)
            {
                punktyGracza2 = 125 + 5 * liczba2_1 + + liczba2_3;
            }       
            if (liczba2_3 == liczba2_2 && liczba2_2 == liczba2_4 && liczba2_3 == liczba2_4)
            {
                punktyGracza2 = 125 + 5 * liczba2_3 + + liczba2_1;
            }  
            if (liczba2_1 == liczba2_3 && liczba2_1 == liczba2_4 && liczba2_3 == liczba2_4)
            {
                punktyGracza2 = 125 + 5 * liczba2_1 + liczba2_2;
            }   
        }
        if (punktyGracza2 == 0)
        {
            if (liczba2_1 == liczba2_2)
            {
                punktyGracza2 = 50 + 5 * liczba2_1 + liczba2_3 + liczba2_4;
            }
            if (liczba2_1 == liczba2_3)
            {
                punktyGracza2 = 50 + 5 * liczba2_1 + liczba2_2 + liczba2_4;
            }
            if (liczba2_1 == liczba2_4)
            {
                punktyGracza2 = 50 + 5 * liczba2_1 + liczba2_2 + liczba2_3;
            }       
            if (liczba2_2 == liczba2_3)
            {
                punktyGracza2 = 50 + 5 * liczba2_2 + liczba2_1 + liczba2_4;
            }     
            if (liczba2_2 == liczba2_4)
            {
                punktyGracza2 = 50 + 5 * liczba2_2 + liczba2_1 + liczba2_3;
            }                          
            if (liczba2_3 == liczba2_4)
            {
                punktyGracza2 = 50 + 5 * liczba2_3 + liczba2_1 + liczba2_2;
            }
        }
        if (punktyGracza1 > punktyGracza2)
        {
            if (idGracza1 == 'a')
            {
                wygraneA++;
                iloscGierA++;
            }     
            if (idGracza1 == 'b')
            {
                wygraneB++;
                iloscGierB++;
            }
            if (idGracza1 == 'c')
            {
                wygraneC++;
                iloscGierC++;
            }
            if (idGracza1 == 'd')
            {
                wygraneD++;
                iloscGierD++;
            }
            if (idGracza1 == 'e')
            {
                wygraneE++;
                iloscGierE++;
            }
        
            if (idGracza2 == 'a')
            {
                przegraneA++;
                iloscGierA++;
            }
            if (idGracza2 == 'b')
            {
                przegraneB++;
                iloscGierB++;
            }
            if (idGracza2 == 'c')
            {
                przegraneC++;
                iloscGierC++;
            }
            if (idGracza2 == 'd')
            {   
                przegraneD++;
                iloscGierD++;
            }
            if (idGracza2 == 'e')   
            {
                przegraneE++;
                iloscGierE++;
            }
        }
        if (punktyGracza1 < punktyGracza2)
        {
            if (idGracza2 == 'a')
            {   
                wygraneA++;
                iloscGierA++;
            }
            if (idGracza2 == 'b')
            {   
                wygraneB++;
                iloscGierB++;
            }
            if (idGracza2 == 'c')
            {
                wygraneC++;
                iloscGierC++;
            }
            if (idGracza2 == 'd')
            {  
                wygraneD++;
                iloscGierD++;
            }
            if (idGracza2 == 'e')
            {
                wygraneE++;
                iloscGierE++;
            }
            if (idGracza1 == 'a')
            {
                przegraneA++;
                iloscGierA++;
            }
            if (idGracza1 == 'b')
            {
                przegraneB++;
                iloscGierB++;
            }
            if (idGracza1 == 'c')
            {
                przegraneC++;
                iloscGierC++;
            }
            if (idGracza1 == 'd')
            {   
                przegraneD++;
                iloscGierD++;
            }
            if (idGracza1 == 'e')   
            {
                przegraneE++;
                iloscGierE++;
            }
            
        }
        if (punktyGracza1 == punktyGracza2)
        {
            if (idGracza1 == 'a')
            {
                remisyA++;
                iloscGierA++;
            }
            if (idGracza1 == 'b')
            {
                remisyB++;
                iloscGierB++;
            }
            if (idGracza1 == 'c')
            {
                remisyC++;
                iloscGierC++;
            }
            if (idGracza1 == 'd')
            {   
                remisyD++;
                iloscGierD++;
            }
            if (idGracza1 == 'e')   
            {
                remisyE++;
                iloscGierE++;
            }
            if (idGracza2 == 'a')
            {
                remisyA++;
                iloscGierA++;
            }
            if (idGracza2 == 'b')
            {
                remisyB++;
                iloscGierB++;
            }
            if (idGracza2 == 'c')
            {
                remisyC++;
                iloscGierC++;
            }
            if (idGracza2 == 'd')
            {   
                remisyD++;
                iloscGierD++;
            }
            if (idGracza2 == 'e')   
            {
                remisyE++;
                iloscGierE++;
            }   
        }
        i++;
    }  

    if (iloscGierA > 0)
    {
        cout << "gracz a" << endl;
        if (wygraneA > 0)
        {
            cout << "    wygrane: " << (wygraneA / iloscGierA) * 100 << "%" << endl;
        }
        if (remisyA > 0)
        {
            cout << "    remisy: " << (remisyA / iloscGierA) * 100 << "%" << endl;
        }
        if (przegraneA > 0)
        {
            cout << "    przegrane: " << (przegraneA / iloscGierA) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (iloscGierB > 0)
    {
        cout << "gracz b" << endl;
        if (wygraneB > 0)
        {
            cout << "    wygrane: " << (wygraneB / iloscGierB) * 100 << "%" << endl;
        }
        if (remisyB > 0)
        {
            cout << "    remisy: " << (remisyB / iloscGierB) * 100 << "%" << endl;
        }
        if (przegraneB > 0)
        {
            cout << "    przegrane: " << (przegraneB / iloscGierB) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (iloscGierC > 0)
    {
        cout << "gracz c" << endl;
        if (wygraneC > 0)
        {
            cout << "    wygrane: " << (wygraneC / iloscGierC) * 100 << "%" << endl;
        }
        if (remisyC > 0)
        {
            cout << "    remisy: " << (remisyC / iloscGierC) * 100 << "%" << endl;
        }
        if (przegraneC > 0)
        {
            cout << "    przegrane: " << (przegraneC / iloscGierC) * 100 << "%" << endl;
        }
        cout << endl;
    }
    if (iloscGierD > 0)
    {
        cout << "gracz d" << endl;
        if (wygraneD > 0)
        {
            cout << "    wygrane: " << (wygraneD / iloscGierD) *100 << "%" << endl;
        }
        if (remisyD > 0)
        {
            cout << "    remisy: " << (remisyD / iloscGierD) * 100 << "%" << endl;
        }
        if (przegraneD > 0)
        {
            cout << "    przegrane: " << (przegraneD / iloscGierD) * 100 << "%" << endl;
        }
        cout << endl;
        
    }
    if (iloscGierE > 0)
    {
        cout << "gracz e" << endl;
        if (wygraneE > 0)
        {
            cout << "    wygrane: " << (wygraneE / iloscGierE) * 100 << "%" << endl;
        }
        if (remisyE > 0)
        {
            cout << "    remisy: " << (remisyE / iloscGierE) * 100 << "%" << endl;
        }
        if (przegraneE > 0)
        {
            cout << "    przegrane: " << (przegraneE / iloscGierE) * 100 << "%" << endl;
        }
        cout << endl;
    }
    return 0;  
}