#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>

double integrate(double a, double b, double n)
{

    //тут будет ваш код
}

struct IntegrateTask
{                               // Шаблон для структуры "Задача потоку"
    double from, to, step, res; // интегрировать "от" (from), "до" (to), с "шагом" (step), результат сохранить в res
};

void *integrateThread(void *data)
{                                                              // ф-я приведения типов задания и т.д.
    struct IntegrateTask *task = (struct IntegrateTask *)data; // объявления структуры task и присвоения аргументов
    task->res = integrate(task->from, task->to, task->step);   // вызов ф-и интегрирования с передачей параметров (задача)
    pthread_exit(NULL); // завершение потока
}

int main(int argc, char *argv[])
{

    double I;
    if (argc != 5)
    {
        fprintf(stderr, "Not enough arguments\n");
        exit(1);
    }
    long int N = atoi(argv[3]);
    long int NUM_THREADS = atoi(argv[4]);
    pthread_t threads[NUM_THREADS];          // Объявляем массив структур потоков (системные)
    struct IntegrateTask tasks[NUM_THREADS]; // Объявляем массив структур заданий потокам

    struct IntegrateTask mainTask = {strtod(argv[1], 0), strtod(argv[2], 0), N / NUM_THREADS}; // Общее задание, интегрировать от 0 до 10 с шагом 00000001
    double distance = (mainTask.to - mainTask.from) / NUM_THREADS;                             // Делим общее задание на части
    int i;

    for (i = 0; i < NUM_THREADS; ++i) // создаем задания и потоки
    {
        tasks[i].from = mainTask.from + i * distance;     // задаем "от"
        tasks[i].to = mainTask.from + (i + 1) * distance; // задаем "до"
        tasks[i].step = mainTask.step;                    // задаем "шаг"

        pthread_create(&threads[i], NULL, integrateThread, (void *)&tasks[i]); // создание потоков и передача параметров (задания)
    }

    double res = 0;
    for (i = 0; i < NUM_THREADS; ++i)
    {                                   // Барьер
        pthread_join(threads[i], NULL); // ждем завершения потока
        res += tasks[i].res;            // суммируем результаты
    }
    printf("I = %lf \n", res);

    return 0;
}
