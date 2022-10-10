#include "Dekker.h"

deccer_mutex D_M;

void deccer_mutex_init()
{
    D_M.lock = lock;
    D_M.unlock = unlock;
    D_M.turn = 0;
    D_M.flag[0] = 1;
    D_M.flag[1] = 1;
}

void lock(int i)
{
   //тут будет ваш код
}

void unlock(int i)
{
   //тут будет ваш код
}