#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void codificareaA(char *a, char cuv[])
{
    int m = strlen(cuv), n = strlen(a), l = strlen(a), ct = 0;
    if(n % m == 0) // calculam numarul de linii necesare
        n = n / m + 1;
    else
        n = n / m + 2;
    char mat[n][m], sol[505];
    for(int i = 0; i < m; i++)
    {
        mat[0][i] = cuv[i];// initializam linia 0 cu cuvantul dat
    }
    for(int i = 1; i < n; i++)// incarcam matricea cu sirul dat
    {
        for(int j = 0; j < m; j++)
            if(ct < l)
                mat[i][j] = a[ct++];
            else
                mat[i][j] = ' ';
    }
    for(int i = 0; i < m - 1; i++)// realizam codificarea a
    {
        int minn = 122, col;
        for(int j = i; j < m; j++)
        {
            if(mat[0][j] < minn)// sortam crescator coloanele, '122' = z
            {
                minn = mat[0][j];
                col = j;
            }
        }
        for(int j = 0; j < n; j++)// mutam coloanele conform sortarii
        {
            char x = mat[j][i];
            mat[j][i] = mat[j][col];
            mat[j][col] = x;
        }
    }
    ct = 0;
    for(int i = 0; i < m; i++)// folosim o valoare auxiliara pentru a incarca sirul din matrice
    {
        for(int j = 1; j < n; j++)
        {
            sol[ct++] = mat[j][i];
        }
    }
    sol[ct] = 0;
    strcpy(a, sol);// copiem sirul codificat in sirul sursa
}
void decodificareaA(char *a, char cuv[])
{
    int  m = strlen(cuv), used[m + 1], n = strlen(a), ct = 0;
    n = n / m + 1;
    char mat[n][m], aux[n][m], sol[500];
    memset(used, 0, sizeof(used));
    for(int i = 0; i < m; i++) // ordonam alfabetic cheia punand-o pe linia 0
    {
        int first = 122, index;
        for(int j = 0; j < m; j++)
        {
            if(cuv[j] < first && used[j] == 0)
            {
                first = cuv[j];
                index = j;
            }
        }
        mat[0][i] = cuv[index];
        used[index] = 1;
    }
    ct = 0;
    for(int i = 0; i < m; i++)// incarcam matricea cu sirul dat
    {
        for(int j = 1; j < n; j++)
            mat[j][i] = a[ct++];
    }
    memset(used, 0, sizeof(used));
    for(int i = 0; i < m; i++)
    {
        int col;
        for(int j = 0; j < m; j++)
        {
            if(mat[0][j]  == cuv[i] && used[j] == 0) // verificam daca caracterul de pe pozitia mat[0][j] este acelasi cu caracterele in ordinea normala din cuvantul cheie
            {
                col = j;
                break;
            }
        }
        used[col] = 1;
        for(int j = 0; j < n; j++) // daca se intampla asta , mutam coloanele intr-o matrice auxiliara
        {
            aux[j][i] = mat[j][col];
        }
    }
    ct = 0;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            sol[ct++] = aux[i][j];
        }
    }
    sol[ct] = 0;
    strcpy(a, sol);
}
void codificareaB(char *a, int n)
{
    char aux[505];
    int l = strlen(a), ct = 0;
    for(int i = l - n; i < l; i++)// codificam ultimele litere intr-o valoare auxiliara si le mutam la inceputul sirului
    {
        aux[ct++] = a[i]; // transformam caracterul conform cerintei
        if(aux[ct - 1] >= 'A' && aux[ct - 1] <= 'Z')
        {
            aux[ct - 1] -= 65; // scadem 'A'   adunam din nou cu 'A' pentr
            aux[ct - 1] += n; // adunam cu n-ul dat
            aux[ct - 1] %= 26; // modul la numarul de caractere din alfabet pentru a nu iesi din intervalul [A,Z],
            aux[ct - 1] += 65; // adunam 'A' pentru a ne intoarcem la alfabet
        }
        if(aux[ct - 1] >= 'a' && aux[ct - 1] <= 'z')
        {
            aux[ct - 1] -= 97;
            aux[ct - 1] += n;
            aux[ct - 1] %= 26;
            aux[ct - 1] += 97;
        }
    }
    for(int i = 0; i < l - n; i++)// adaugam la sfarsitul sirului auxiliar primele strlen(a) - n litere
    {
        aux[ct++] = a[i];
    }
    aux[ct] = 0;
    strcpy(a, aux);// copiem sirul codificat in sirul sursa
}
void decodificareaB(char *a, int n)
{
    char aux[505];
    int l = strlen(a), ct = 0;
    for(int i = n; i < l; i++)// copiem in sirul auxiliar caracterele de la n la sfarsitul sirului modificat, adica pana la l
    {
        aux[ct++] = a[i];
    }
    for(int i = 0; i < n; i++)// adaugam la finalul sirului auxiliar , modificat anterior, decodificarea primelor n caractere din sirul a
    {
        aux[ct++] = a[i];
        if(aux[ct - 1] >= 'A' && aux[ct - 1] <= 'Z')
        {
            aux[ct - 1] -= 65;
            aux[ct - 1] -= n;
            aux[ct - 1] += 26;
            aux[ct - 1] %= 26;
            aux[ct - 1] += 65;
        }
        if(aux[ct - 1] >= 'a' && aux[ct - 1] <= 'z')
        {
            aux[ct - 1] -= 97;
            aux[ct - 1] -= n;
            aux[ct - 1] += 26;
            aux[ct - 1] %= 26;
            aux[ct - 1] += 97;
        }
    }
    aux[ct] = 0;
    strcpy(a, aux); // copiem sirul decodificat in sirul sursa
}
int main()
{
    char text[500], cod[500], a[50];
    int b;
    gets(text);
    scanf("%s", cod);
    while(cod != 'STOP')
    {
        if(cod[strlen(cod) - 1] == 'A' && cod[0] == 'C')
        {
            scanf("%s", a);
            codificareaA(text, a);
            printf("%s\n", text);
        }
        if(cod[strlen(cod) - 1] == 'B' && cod[0] == 'C')
        {
            scanf("%d", &b);
            codificareaB(text, b);
            printf("%s\n", text);
        }
        if(cod[strlen(cod) - 1] == 'A' && cod[0] == 'D')
        {
            scanf("%s", a);
            decodificareaA(text, a);
            printf("%s\n", text);
        }
        if(cod[strlen(cod) - 1] == 'B' && cod[0] == 'D')
        {
            scanf("%d", &b);
            decodificareaB(text, b);
            printf("%s\n", text);
        }
        scanf("%s", cod);
        if(cod[0] == 'S' && cod[1] == 'T' && cod[2] == 'O' && cod[3] == 'P') break;
    }
    return 0;
}
