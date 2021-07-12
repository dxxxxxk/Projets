#include "lemin.h"

void    reset_cb(t_lem *data)
{
    int i;

    i = 0;
    while (i < data->nb)
    {
        data->cb[0][i] = 0;
        i++;
    }
    i = 0;
    while (i < data->lrooms[data->end][1])
    {
        data->cb[1][i] = 0;
        i++;
    }
    data->cb[0][data->start] = 1;
    data->cb[0][data->end] = 1;
}

void    fill_cb(t_lem *data)
{
    int i;
    int j;

    i = 0;
    j = 2;
    while (i < data->r)
    {
        while (j < data->pt[data->corr[0][data->rendu[i]]][data->corr[1][data->rendu[i]]][0])
        {
            data->cb[0][data->pt[data->corr[0][data->rendu[i]]][data->corr[1][data->rendu[i]]][j]] = 1;
            data->cb[1][data->corr[0][data->rendu[i]]] = 1;
            j++;
        }
        j = 2;
        i++;
    }
}