#include "lemin.h"

void        print_ants(t_lem *data)
{
    int     i;
    int     j;
    int     nbf;

    i = 0;
    j = 0;
    nbf = 0;
    while (i < data->r)
    {
        data->pri2[i] = 0;
        i++;
    }
    i = 0;
    while (i < data->r)
    {
        if (i != 0)
            data->tmprendu[i] = 0 + data->pri2[i - 1];
        else
            data->tmprendu[i] = 0;
        nbf = data->pri[i] + nbf;
        data->pri2[i] = nbf;
        i++;
    }
    data->tmprendu[0] = 0;
    // printf("\n\n--------\n");
    // print_tab_normal(data->tmprendu, data->r);
    // printf("\n\n--------\n");
    // print_tab_normal(data->pri, data->r);
    // printf("\n\n--------\n");
    i = 0;
    int k;

    k = 0;
    j = 1;
    while (j < data->f + 1)
    {
        while (k < data->r)
        {
            if (k == 0 && j < data->f + 1)
            {
                data->fo[data->tmprendu[k]][2] = j;
                data->tmprendu[k] = data->tmprendu[k] + 1; 
                j++;
            }
            else if (data->tmprendu[k] < data->pri2[k] && j < data->f + 1)
            {
                data->fo[data->tmprendu[k]][2] = j;
                data->tmprendu[k] = data->tmprendu[k] + 1; 
                j++;
            }
            k++;
        }
        k = 0;
    }
    j = 0;
    i = 0;

    // int  k;

    // k = 1;
    nbf = data->f;
    while (nbf > 0)
    {
        // printf("k = %d\n", k);
        while (i < data->pri2[j])
        {
            data->fo[i][0] = data->rendu[j];
            data->fo[i][1] = data->paths[data->rendu[j]][0];
            // k = (i > 0) ? k + (data->r) : k; 
            i++;
        }
        nbf = nbf - data->pri[j];
        j++;
    }
    nbf = data->f;
    // print_tabb(data->fo, data->f, 3);
    // printf("\n");
    print_ants_norm(data, nbf);
}

void    print_ants_norm(t_lem *data, int nbf)
{
    int i;
    int k;

    k = 0;
    i = 0;
    while (nbf > 0)
    {
        while (k < data->r && i < data->f && nbf > 0)
        {
            while (i < data->f && i < data->pri2[k] && data->fo[i][1] == 1) //tant que egale a end =1 du coup
            {
                i++;
                nbf--;
            }
            while (i < data->f && data->fo[i][1] != data->paths[data->fo[i][0]][0] && i < data->pri2[k]) //tant que diff de la longueur a start et pas sur le deuxieme chemin
            {
                data->fo[i][1] = data->fo[i][1] - 1;
                if (data->fo[i][1] == 1)
                    data->fo[i][1] = -1;
                i++;
            }
            if (i < data->f && i < data->pri2[k] && data->fo[i][1] == data->paths[data->fo[i][0]][0]) //pr --start
            {
                data->fo[i][1] = data->fo[i][1] - 1;
                if (data->fo[i][1] == 1)
                    data->fo[i][1] = -1;
            }
            while (i < data->pri2[k])
            {
                i++;
            }
            k++;
        }
        print_instant(data);
        i = 0;
        while (i < data->f)
        {
            if (data->fo[i][1] == -1)
                data->fo[i][1] = 1;
            i++;
        }
        if (nbf == 0)
        {
            return ;
        }
        else
        {
            printf("\n");
            nbf = data->f;
        }
        // print_tabb(data->fo, data->f, 2);
        // printf("\n");
        k = 0;
        i = 0;
    }
}

void    print_instant(t_lem *data)
{
    int i;
    int k;

    k = 0;
    i = 0;
    while (i < data->f)
    {
        if (data->fo[i][1] == 1 || data->fo[i][1] == data->paths[data->fo[i][0]][0])
            i++;
        else if (data->fo[i][1] == -1)
        {
            if (k != 0)
                printf(" ");
            printf("L%d-%s", data->fo[i][2], data->names[data->end]);
            i++;
            k++;
        }
        else
        {
            if (k != 0)
                printf(" ");
            printf("L%d-%s", data->fo[i][2], data->names[data->paths[data->fo[i][0]][data->fo[i][1]]]);
            i++;
            k++;
        }
    }
}