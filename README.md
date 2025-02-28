# Project "Hello"  

Этот проект демонстрирует использование **Docker**, **Dev Containers** и **CMake** для разработки на **C++**. 

### Для запуска проекта необходимо выполнить следующие шаги:  
- Склонируйте проект с GitHub:  
```sh
https://github.com/JKurdina/Hello.git
cd Hello
```

- Откройте проект в VS Code
- Запустите Dev Container
- Соберите и запустите проект:

  Через CMake:
```sh
mkdir -p build && cd build
cmake ..
make
./main
```
Или 
```sh
g++ main.cpp -o main
./main
```
