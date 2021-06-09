#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <algorithm>
#include <time.h>

// Класс содержит данные и методы,
// необходимые для выполнения тестового задания
class Task
{
protected:
    std::mt19937 random_engine;

    std::vector<int> vector;
    std::map<int, int> map;

    int get_random_int(const int min, const int max);

    std::vector<int> get_intersection(std::vector<int> v1,
                                      std::vector<int> v2);

public:
    Task(const int seed = time(0));

    virtual ~Task() {}

    // Добавляет в vector и map n чисел в диапозоне от 1 до 9
    virtual void random_fill(size_t n);

    // Удаляет из vector и map случаное число элементов (не более 15)
    virtual void random_delete();

    // Оставляет в каждмо из контейнеров только те элементы,
    // которые также есть в другом
    virtual void synchronization();

    // Выводит в консоль содержимое vector и map
    virtual void print() const;

    // Демонстрирует работу всех 3 функций,
    // выводя при этом содержимое vector и map
    virtual void demonstration();

    virtual void clear();
};

#endif // TASK_H
