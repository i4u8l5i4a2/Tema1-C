#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char *brand;
    char *numar;
    char *combustibil;
    double consum;
    int km;
} masina;
void c_a(masina *a, int *b, int *m, int *h, int *e, int n)
{
    int i;
    for(i = 0; i < n; i++)// verificam tipul de combustibil si il contorizam
    {
        if(strcmp(a[i].combustibil, "benzina") == 0)
            *b = *b + 1;
        else if(strcmp(a[i].combustibil, "motorina") == 0)
            *m = *m + 1;
        else if(strcmp(a[i].combustibil, "hibrid") == 0)
            *h = *h + 1;
        else
            *e = *e + 1;
    }
}
void incarcare(masina *a, int marime_brand, int marime_nr, int marime_comb)
{
    a->brand = (char *)malloc(marime_brand * sizeof(char));
    a->numar = (char *)malloc(marime_nr * sizeof(char));
    a->combustibil = (char *)malloc(marime_comb * sizeof(char));
}
void contorizare(masina *a, int n, masina *ct, int *nr)
{
    /*incarc ct doar cu brandurile unice, contorizand care nu se repeta
    */
    int ok, i, j;
    incarcare(&ct[0], strlen(a[0].brand) + 1, strlen(a[0].numar) + 1, strlen(a[0].combustibil) + 1);// aloc dinamic memorie pentru un vector
    strcpy(ct[0].brand, a[0].brand);
    *nr = *nr + 1;
    for (i = 1; i < n; i++)
    {
        ok = 1;
        for (j = 0; j < *nr; j++)
            if (strcmp(a[i].brand, ct[j].brand) == 0)
            {
                ok = 0;
                break;
            }
        if (ok)
        {
            incarcare(&ct[*nr], strlen(a[i].brand) + 1, strlen(a[i].numar) + 1, strlen(a[i].combustibil) + 1);
            strcpy(ct[*nr].brand, a[i].brand);
            *nr += 1;
        }
    }
}
void c_b(masina *a, int n, masina *ct, int nr, double *consum, double *pret)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < nr; j++)
        {
            if (strcmp(a[i].brand, ct[j].brand) == 0)// adun in ct consumul si cheltuielile
            {
                consum[j] = consum[j] + (double)((a[i].consum * a[i].km) / 100);
                if (strcmp(a[i].combustibil, "benzina") == 0 || strcmp(a[i].combustibil, "hibrid") == 0)
                    pret[j] = pret[j] + (double)((a[i].consum * a[i].km) / 100) * 8.02;
                else if (strcmp(a[i].combustibil, "motorina") == 0)
                    pret[j] = pret[j] + (double)((a[i].consum * a[i].km) / 100) * 9.29;
                break;
            }
        }
    }
}
int c_c(char *s)
/*functia ruleaza precum o functie bool, daca intruneste conditiile returneaza 1, adica adevarat
daca nu intruneste conditiile, returneaza 0, adica fals*/
{
    int n = strlen(s);
    if(n == 6)// verificam numerele de forma A11AAA
    {
        if(s[0] >= 'A' && s[0] <= 'Z')
        {
            if(s[1] >= '0' && s[1] <= '9' && s[2] >= '0' && s[2] <= '9')
            {
                if(s[3] >= 'A' && s[3] <= 'Z' && s[4] >= 'A' && s[4] <= 'Z' && s[5] >= 'A' && s[5] <= 'Z')
                {
                    return 1;
                }
            }
        }
    }
    if(n == 7)// verificam numerele de forma A234TYU sau RT45SFY
    {
        if(s[0] >= 'A' && s[0] <= 'Z')
        {
            if((s[1] >= '0' && s[1] <= '9') || (s[1] >= 'A' && s[1] <= 'Z'))
            {
                if(s[2] >= '0' && s[2] <= '9' && s[3] >= '0' && s[3] <= '9')
                {
                    if(s[4] >= 'A' && s[4] <= 'Z' && s[5] >= 'A' && s[5] <= 'Z' && s[6] >= 'A' && s[6] <= 'Z')
                        return 1;
                }
            }

        }
    }
    if(n == 8)// verificam numerele de forma AA678GJM
    {
        if(s[0] >= 'A' && s[0] <= 'Z' && s[1] >= 'A' && s[1] <= 'Z')
        {
            if(s[2] >= '0' && s[2] <= '9' && s[3] >= '0' && s[3] <= '9' && s[4] >= '0' && s[4] <= '9')
            {
                if(s[5] >= 'A' && s[5] <= 'Z' && s[6] >= 'A' && s[6] <= 'Z' && s[7] >= 'A' && s[7] <= 'Z')
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    masina *a;
    int i, nrmasini, lung, km;
    int b, m, h, e;
    char sir[21];
    b = m = h = e = 0;
    double consum;
    char c;
    scanf("%d", &nrmasini);
    a = (masina *)malloc(nrmasini * sizeof(masina));
    for (i = 0; i < nrmasini; i++)
    {
        scanf("%s", sir);// citim mai intai un sir normal
        getchar();
        lung = strlen(sir);
        a[i].brand = (char *)malloc((lung + 1) * sizeof(char));// alocam memorie pt sirul anterior
        strcpy(a[i].brand, sir);// incarcam a[i].brand cu sirul
        scanf("%s", sir);// citim mai intai un sir normal
        getchar();
        lung = strlen(sir);
        a[i].numar = malloc((lung + 1) * sizeof(char));// alocam memorie pt sirul anterior
        strcpy(a[i].numar, sir);// incarcam a[i].numar cu sirul
        scanf("%s", sir);// citim mai intai un sir normal
        getchar();
        lung = strlen(sir);
        a[i].combustibil = malloc((lung + 1) * sizeof(char));// alocam memorie pt sirul anterior
        strcpy(a[i].combustibil, sir);// incarcam a[i].combustibil cu sirul
        scanf("%lf", &consum);// citim datele de tip double normal, iar apoi le incarcam in a[i].consum
        a[i].consum = consum;
        scanf("%d", &km);// citim datele de tip double normal, iar apoi le incarcam in a[i].km
        a[i].km = km;
    }
    getchar();
    scanf("%c", &c);
    if(c == 'a')
    {
        c_a(a, &b, &m, &h, &e, nrmasini);
        printf("benzina - %d\nmotorina - %d\nhibrid - %d\nelectric - %d\n", b, m, h, e);
    }
    if(c == 'b')
    {
        int nr = 0;
        double *consum, *pret;
        masina *ct;// folosesc o variabila auxiliara cu brand-uri unice
        ct = (masina *)malloc(nrmasini * sizeof(masina));
        contorizare(a, nrmasini, ct, &nr);
        consum = (double *)calloc(nr, sizeof(double));
        pret = (double *)calloc(nr, sizeof(double));
        c_b(a, nrmasini, ct, nr, consum, pret);
        for (i = 0; i < nr; i++)
            printf("%s a consumat %.2lf - %.2lf lei\n", ct[i].brand, consum[i], pret[i]);
    }
    if(c == 'c')
    {
        int verif = 1, k = 1;
        for(i = 0; i < nrmasini; i++)
        {
            strcpy(sir,a[i].numar);
            k = c_c(sir); // k se incarca cu cat returneaza functia
            if(k == 0)// pt k = 0, inseamna ca exista numere invalide, iar valoarea lui verif se schimba
            {
                verif = 0;
                printf("%s cu numarul %s: numar invalid\n", a[i].brand, a[i].numar);
            }
        }
        if(verif == 1)// daca valoarea lui verif ramane neschimbata, atunci numerele sunt corecte
            printf("Numere corecte!\n");
    }
    return 0;
}
