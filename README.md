# Тестовое задание на вакансию junior C++

## Задача:
1. Заполнить случайными числами от 1 до 9 значения контейнеров vector[i] и map[i];
2. Удалить случайное число элементов (не более 15) в каждом контейнере;
3. После этого провести синхронизацию, чтобы в vector и map остались только имеющиеся в обоих контейнерах элементы (дубликаты не удалять).

## Решение:
Был создан класс Task, содержащий данные и методы для решения поставленной задачи. Код класса был вынесен в отдельные .h и .cpp файлы для удобства чтения.   
Длинна строк кода в файлах была ограничена 79 символами для удобства работы с несколькими открытыми бок о бок окнами.   

Ссылки на файлы с кодом: [main.cpp](task/main.cpp), [task.h](task/task.h), [task.cpp](task/task.cpp). 

## Сборка и запуск
Находясь в папке `task`:
- Сборка: `g++ -std=c++14 -o main.cpp task.cpp  task`   
- Запуск: `./task`

Альтернативно, возможна сборка и запуск из QT Creator, для этого в репозитории есть [.pro файл](task/task.pro)  