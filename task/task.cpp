#include "task.h"

int Task::get_random_int(const int min, const int max)
{
    std::uniform_int_distribution<int> uni(min, max);
    return uni(random_engine);
}

std::vector<int> Task::get_intersection(
        std::vector<int> v1, std::vector<int> v2)
{
    std::vector<int> v3;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::set_intersection(v1.begin(), v1.end(),
                          v2.begin(), v2.end(),
                          back_inserter(v3));
    return v3;
}

Task::Task(const int seed)
{
    random_engine.seed(seed);
}

void Task::random_fill(size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        this->vector.push_back(this->get_random_int(1, 9));
        this->map.insert(std::make_pair(i, this->get_random_int(1, 9)));
    }
}

void Task::random_delete()
{
    // В задании не было указано, как именно удалить случайное
    // количество элементов,
    // Было решено элементы удалять подряд, начиная с конца
    size_t elements_to_delete = this->get_random_int(1, 15);
    for (size_t i = 0; i < elements_to_delete; ++i)
        this->vector.pop_back();

    elements_to_delete = this->get_random_int(1, 15);
    for (size_t i = 0; i < elements_to_delete; ++i)
        this->map.erase(prev(this->map.end()));
}

void Task::synchronization()
{
    // Получаем вектор значений map, нужный для std::set_intersection
    std::vector<int> vector_of_map_values;
    for (const auto& pair : this->map) {
        vector_of_map_values.push_back(pair.second);
    }

    // Получаем вектор общих элементов
    std::vector<int> intersection =
            this->get_intersection(this->vector, vector_of_map_values);

    // Удаляем "не общие" элементы из vector
    for (auto it = this->vector.begin(); it != this->vector.end(); )
    {
        if (find(intersection.begin(), intersection.end(), *it) ==
                intersection.end())
        {
            it = this->vector.erase(it);
        }
        else
        {
            ++it;
        }
    }

    // Удаляем "не общие" элементы из map
    for (auto it = this->map.cbegin(); it != this->map.cend(); )
    {
        if (find(intersection.begin(), intersection.end(), it->second) ==
                intersection.end())
        {
            it = this->map.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void Task::print() const
{
    std::cout << "vector: ";
    for (auto i : this->vector)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout<<"map: ";
    for (auto i : this->map)
    {
        std::cout << i.second << " ";
    }
    std::cout << std::endl;
}

void Task::demonstration()
{
    this->random_fill(23);
    std::cout<<"vector и map после заполнения:\n";
    this->print();

    this->random_delete();
    std::cout<<"\nvector и map после удаления случайного"
               " числа элементов:\n";
    this->print();

    this->synchronization();
    std::cout<<"\nvector и map после \"синхронизации\":\n";
    this->print();

    this->clear();
}

void Task::clear()
{
    this->vector.clear();
    this->map.clear();
}
