# Используем Ubuntu 20.04
FROM ubuntu:20.04

# Подавляем интерактивные запросы
ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow

# Используем быстрые зеркала для репозиториев
RUN sed -i 's|http://archive.ubuntu.com/ubuntu/|http://mirror.yandex.ru/ubuntu/|g' /etc/apt/sources.list

# Устанавливаем необходимые пакеты
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    gdb \
    cmake \
    git && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Устанавливаем рабочую директорию
WORKDIR /workspace

COPY . /workspace

# Команда по умолчанию
CMD ["bash"]

