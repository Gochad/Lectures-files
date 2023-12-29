
#include <string>
using namespace std;
string FormatujNapis ();
string NajwiekszeSlowo (string napis);
string NormalizujNapis (string napis);
string UsunSlowo (string napis, int liczba);

string FormatujNapis (string napis, string pJeden, string pDwa, string pTrzy)
{
    string wynikoweSlowo = "";
    char znakPolecenia;
    int n;
    char c;
    int m;
    int pomocniczyRozmiar;
    int rozmiar = napis.size();

    for (int i = 0; i < rozmiar; i++)
    {
        if (napis [ i ] != '}' && napis [ i ] != '{')
        {
            wynikoweSlowo += napis [ i ];
        }
        else if (napis [ i ] == '{')
        {
            znakPolecenia = napis [ i + 1 ];
            if (znakPolecenia == 'p') 
            {
                n = napis [ i + 3 ] - '0';
                c = napis [ i + 5 ];
                for (int j = 0; j < n; j++)
                {
                    wynikoweSlowo += c;
                }
                i += 6;
            }
            else if (znakPolecenia == 'u') 
            {
                n = napis [ i + 3 ] - '0';
                i += n + 4;
            }
            else if (znakPolecenia == 'U') 
            {
                n = napis [ i + 3 ] - '0';
                pomocniczyRozmiar = wynikoweSlowo.size() - n;
                wynikoweSlowo.resize (pomocniczyRozmiar);
                i += 4;
            }
            else if (znakPolecenia == 'w') 
            {
                n = napis [ i + 3 ] - '0';
                if (n == 1)
                {
                    wynikoweSlowo += pJeden;
                }
                else if (n == 2)
                {
                    wynikoweSlowo += pDwa;
                }
                else if (n == 3)
                {
                    wynikoweSlowo += pTrzy;
                }
                i += 4;
            }
            else if (znakPolecenia == 'W') 
            {
                n = napis [ i + 3 ] - '0';
                m = napis [ i + 5 ] - '0';
                if (n == 1)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (j < pJeden.size())
                        {
                            wynikoweSlowo += pJeden [ j ];
                        }
                        else
                        {
                            wynikoweSlowo += ' ';
                        }
                    }   
                }
                else if (n == 2)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (j < pDwa.size())
                        {
                            wynikoweSlowo += pDwa [ j ];
                        }
                        else
                        {
                            wynikoweSlowo += ' ';
                        }
                    } 
                }
                else if (n == 3)
                {
                    for (int j = 0; j < m; j++)
                    {
                        if (j < pTrzy.size())
                        {
                            wynikoweSlowo += pTrzy [ j ];
                        }
                        else
                        {
                            wynikoweSlowo += ' ';
                        }
                    } 
                }

                i += 6;
            }
        }
    }
    return wynikoweSlowo;
}

string NajwiekszeSlowo (string napis) 
{
    string wynikoweSlowo = "";
    string aktualneSlowo = "";
    int rozmiar = napis.size (); 

    for (int i = 0; i <= rozmiar; i++)
    {
        if (i < rozmiar)
        {
            if (napis [ i ] == ' ')
            {
                if (i == rozmiar - 1)
                {
                    aktualneSlowo += napis [ i ];
                }
                if (aktualneSlowo > wynikoweSlowo)
                {
                    wynikoweSlowo = aktualneSlowo;
                }
                aktualneSlowo = "";
            }
            else 
            {
                aktualneSlowo += napis [ i ];
                if (wynikoweSlowo == "" && i == rozmiar - 1)
                {
                    wynikoweSlowo = aktualneSlowo;
                }
            }
        }
        else 
        {
            if (aktualneSlowo > wynikoweSlowo)
            {
                wynikoweSlowo = aktualneSlowo;
            }
        }
    }

    return wynikoweSlowo;
}

string NormalizujNapis (string napis)
{
    string wynikoweSlowo = "";
    string odwroconeSlowo = "";
    int rozmiar = napis.size();
    int koncowyRozmiar;
    bool spacjaAlert = true;
    bool kropkaAlert = true;

    for (int i = rozmiar - 1; i >= 0; i--)
    {
        if ((napis [ i ] == '.' || napis [ i ] == ','))
        {
            if (i != 0 && i != rozmiar - 1 && kropkaAlert == false)
            {
                wynikoweSlowo += ' ';
                wynikoweSlowo += napis [ i ];
            }
            else
            {
                wynikoweSlowo += napis [ i ];
            }
            kropkaAlert = true;
        }
        else if (napis [ i ] != ' ')
        {
            wynikoweSlowo += napis [ i ];
            spacjaAlert = false;
            kropkaAlert = false;
        }
        
        else if (napis [ i ] == ' ')
        {
            if (spacjaAlert == false && kropkaAlert == false && i != 0 && i != rozmiar - 1)
            {
                wynikoweSlowo += ' ';
                spacjaAlert = true;
                kropkaAlert = true;
            }
        }
        
    }
    
    koncowyRozmiar = wynikoweSlowo.size();
    for (int i = koncowyRozmiar - 1; i >= 0; i--)
    {
        if (!(i == koncowyRozmiar - 1 && wynikoweSlowo [ i ] == ' '))
        {
            odwroconeSlowo += wynikoweSlowo [ i ];
        }  
    }
    return odwroconeSlowo;
}


string UsunSlowo (string napis, int liczba)
{
    string wynikoweSlowo = "";
    string aktualneSlowo = "";
    string sprawdzenieSlowa = "";
    int licznikSlow = 0;
    int rozmiar = napis.size();
    int aktualnyRozmiar = 0;

    for (int i = 0; i < rozmiar; i++)
    {
        if (napis [ i ] == ' ')
        {
            aktualnyRozmiar = 0;
            wynikoweSlowo += napis [ i ];
        }
        else 
        {
            if (aktualnyRozmiar == 0)
            {
                ++licznikSlow;
            }
            if (licznikSlow != liczba)
            {
                wynikoweSlowo += napis [ i ];
            }
           
            aktualnyRozmiar += 1;
        }
    }

    return wynikoweSlowo;
}


