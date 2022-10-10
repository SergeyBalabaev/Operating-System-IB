#pragma once

typedef struct deccer_mutex
{
    int flag[2];
    int turn;
    void (*lock)(int i);
    void (*unlock)(int i);
} deccer_mutex;

void deccer_mutex_init();
static void lock(int);
static void unlock(int);