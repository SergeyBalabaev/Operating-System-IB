#include "Peterson.h"

peterson_mutex P_M;

void peterson_mutex_init()
{
    P_M.lock = lock;
    P_M.unlock = unlock;
    P_M.turn = 0;
    P_M.flag[0] = 1;
    P_M.flag[1] = 1;
}

void lock(int i)
{
    //тут будет ваш код
}

void unlock(int i)
{
    //тут будет ваш код
}