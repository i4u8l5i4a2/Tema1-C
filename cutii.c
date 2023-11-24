#include <stdio.h>
#include <stdlib.h>
int deschidere(int n, int c[], int i)
/*contorizam de cate cutii este nevoie sa fie deschise ca sa ne intoarcem la numarul primeia
adica i = v[k] adevarat => verificam daca am deschis mai putin sau egal de n/2 cutii,
daca sunt mai multe returnam 0, daca sunt mai putine sau egale returnam 1.
Subprogramul functioneaza ca o functie de bool care verifica conditia pt care ar trai puscariasii.
*/
{
    int nr, ct = 0;
    nr = c[i];// nr reprezinta numarul din cutie
    ct++;
    while(ct <= n / 2)
    {
        if(i == nr)
            break;
        else
        {
            nr = c[nr];
            ct++;
        }
    }
    if(ct <= n / 2) return 1;
    else return 0;
}
void siruri(int n, int c[])
// generarea sirurilor
/*vom altera vectorul, pentru a genera sirusile
plecam de prima pozitie si incarcam variabila inceput cu i,
apoi incarcam nr cu numarul din cutia de pe pozitia i, iar cutia se va goli, adica devine 0
if-ul este redundant pentru primul sir, dar foarte util pt al doilea;
golind cutiile nu o sa mai trecem peste ce am verificat deja si o sa ne ducem acolo unde nu au fost verificate
astfel ca dupa primul sir, ni se vor goli cateva cutii, iar al doilea sir va incepe cu prima cutie cu numar ce
nu a fost inca deschisa, aceasta este utilizarea if-ului*/
{
    int i, nr, inceput, poz;
    for(i = 1; i <= n; i++)
    {
        if(c[i])
        {
            inceput = i;
            printf("%d ", i);
            nr = c[i];
            c[i] = 0;
            while(nr != inceput)
            {
                printf("%d ", nr);
                poz = nr;
                nr = c[nr];
                c[poz] = 0;

            }
            printf("\n");
        }
    }
}
int main()
{
    int p, v[500], i, nr = 0, ok = 1;
    scanf("%d", &p);
    for(i = 1; i <= p; i++)
        scanf("%d", &v[i]);
// verificam daca puscariasii pot castiga cu ajutorul subprogramului deschidere()
    for( i = 1; i <= p; i++)
        if(deschidere(p,v,i) == 0)
            {
                printf("Nu\n");
                ok = 0; // ne folosim de ok pentru a verifica da puscariasii pierd
                break;
            }
    if(ok)
        printf("Da\n");
    siruri(p, v);// generam sirurile
    return 0;
}
