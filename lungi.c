#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void adunare(char *c1, char c2[], long long n)
{
    long long re1, im1, i, sre, sim, re2, im2, re3, im3;
    re1 = re2 = re3 = 0;
    im1 = im2 = im3 = 0;
    if(c1[0] == '0') // verificam daca partea reala a primului numar este pozitiva sau negativa
        sre = 1;
    else
        sre = -1;
    for(i = 1; i <= n / 2 - 1; i++) // transformam sirul de caractere ce reprezinta partea reala intr-un numar
    {
        re1 = re1 * 10 + ((int)(c1[i]) - (int)('0'));
    }
    re1 = re1 * sre; // punem semnul numarului
    if(c1[n / 2] == '0') // verificam daca partea imaginara a primului numar este pozitiva sau negativa
        sim = 1;
    else
        sim = -1;
    for(i = n / 2 + 1; i < n - 1; i++) // transformam sirul de caractere ce reprezinta partea imaginara intr-un numar
    {
        im1 = im1 * 10 + ((int)(c1[i]) - (int)('0'));
    }
    im1 = im1 * sim;// punem semnul numarului
    if(c2[0] == '0')// verificam daca partea reala al celui de al doilea numar este pozitiva sau negativa
        sre = 1;
    else
        sre = -1;
    for(i = 1; i <= n / 2 - 1; i++)// transformam sirul de caractere ce reprezinta partea reala intr-un numar
    {
        re2 = re2 * 10 + ((int)(c2[i]) - (int)('0'));
    }
    re2 = re2 * sre; // punem semnul numarului
    if(c2[n / 2] == '0')// verificam daca partea imaginara al celui de al doilea numar este pozitiva sau negativa
        sim = 1; // sim = 1;
    else
        sim = -1;
    for(i = n / 2 + 1; i < n - 1; i++)// transformam sirul de caractere ce reprezinta partea reala intr-un numar
    {
        im2 = im2 * 10 + ((int)(c2[i]) - (int)('0'));
    }
    im2 = im2 * sim;// punem semnul numarului
    re3 = re1 + re2;// efectuam adunarea partilor reale
    im3 = im1 + im2;// efectuam adunarea partilor imaginare
    if(re3 >= 0)// verificam semnul rezultatului partii reale
        c1[0] = '0';
    else
        c1[0] = '1';
    for(i = n / 2 - 1; i >= 1; i --)// convertim rezultatul in sir de caractere
    {
        c1[i] = (re3 % 10) + '0';
        re3 = re3 / 10;
    }
    if(im3 >= 0)// verificam semnul rezultatului partii imaginare
        c1[n / 2] = '0';
    else
    {
        c1[n / 2] = '1';
        im3 = im3 * (-1);
    }
    for(i = n - 2; i >= n / 2 + 1; i--)// convertim rezultatul in sir de caractere
    {
        c1[i] = (im3 % 10) + '0';
        im3 = im3 / 10;
    }
}
void scadere(char *c1, char c2[], long long n)
{
    long long re1, im1, i, sre, sim, re2, im2, re3, im3;
    re1 = re2 = re3 = 0;
    im1 = im2 = im3 = 0;
    if(c1[0] == '0')// verificam daca partea reala a primului numar este pozitiva sau negativa
        sre = 1;
    else
        sre = -1;
    for(i = 1; i <= n / 2 - 1; i++)// transformam sirul de caractere ce reprezinta partea reala intr-un numar
    {
        re1 = re1 * 10 + ((int)(c1[i]) - (int)('0'));
    }
    re1 = re1 * sre;// punem semnul numarului
    if(c1[n / 2] == '0')// verificam daca partea imaginara a primului numar este pozitiva sau negativa
        sim = 1;
    else
        sim = -1;
    for(i = n / 2 + 1; i < n - 1; i++)// transformam sirul de caractere ce reprezinta partea imaginara intr-un numar
    {
        im1 = im1 * 10 + ((int)(c1[i]) - (int)('0'));
    }
    im1 = im1 * sim;// punem semnul numarului
    if(c2[0] == '0')// verificam daca partea reala al celui de al doilea numar este pozitiva sau negativa
        sre = 1;
    else
        sre = -1;
    for(i = 1; i <= n / 2 - 1; i++)// transformam sirul de caractere ce reprezinta partea reala intr-un numar
    {
        re2 = re2 * 10 + ((int)(c2[i]) - (int)('0'));
    }
    re2 = re2 * sre;// punem semnul numarului
    if(c2[n / 2] == '0')// verificam daca partea imaginara al celui de al doilea numar este pozitiva sau negativa
        sim = 1;
    else
        sim = -1;
    for(i = n / 2 + 1; i < n - 1; i++)// transformam sirul de caractere ce reprezinta partea reala intr-un numar
    {
        im2 = im2 * 10 + ((int)(c2[i]) - (int)('0'));
    }
    im2 = im2 * sim;// punem semnul numarului
    re3 = re1 - re2;// efectuam scaderea numerelor reale
    im3 = im1 - im2;// efectuam scaderea numerelor imaginare
    if(re3 >= 0)// verificam semnul rezultatului partii reale
        c1[0] = '0';
    else
    {
        c1[0] = '1';
        re3 = re3 * (-1);
    }
    for(i = n / 2 - 1; i >= 1; i --)// convertim rezultatul in sir de caractere
    {
        c1[i] = (re3 % 10) + '0';
        re3 = re3 / 10;
    }
    if(im3 >= 0)// verificam semnul rezultatului partii imaginare
        c1[n / 2] = '0';
    else
    {
        c1[n / 2] = '1';
        im3 = im3 * (-1);
    }
    for(i = n - 2; i >= n / 2 + 1; i--)// convertim rezultatul in sir de caractere
    {
        c1[i] = (im3 % 10) + '0';
        im3 = im3 / 10;
    }
}
int main()
{
    long long n, r, im;
    char c1[1001], s[1001], c2[1001];
    scanf("%d", &n);
    scanf("%s", &c1);
    scanf("%s", &s);
    while(c1 != '0')
    {
        scanf("%s", &c2);
        if(s[0] == '+')
            adunare(c1, c2, n);
        if(s[0] == '-')
            scadere(c1, c2, n);
        printf("%s\n", c1);
        scanf("%s", &s);
        if(strlen(s) == 1 && s[0] == '0')
            break;

    }
    return 0;
}
