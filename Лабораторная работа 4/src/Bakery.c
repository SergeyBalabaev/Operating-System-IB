#include "Bakery.h"

bakery_mutex B_M;

#define N_threads 2

void bakery_mutex_init()
{
    B_M.lock = lock;
    B_M.unlock = unlock;
    for (int i = 0; i < N_threads; i++)
    {
        B_M.ticket[i] = 0;
        B_M.choosing[i] = 0;
    }
}

void lock(int i)
{
   //тут будет ваш код
}

void unlock(int i)
{
    //тут будет ваш код
}