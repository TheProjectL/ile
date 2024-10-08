# Ile калькулятор квадратных уравнений / (МФТИ, часть проекта L)

## Краткая информация

* Приложение написанное на С(2011)
* Решает квадратные уравнения в любой возможной записи
* Демонстрирует пошаговое решение
* Может быть интегрировано на веб сервер и веб сайт
* Реализовано по средствам CGI

## Состсавные части программы

Приложения доступные пользователю:

* (ile.exe) Лаунчер (он же веб сервер) - приложение, которое может принять аргументы и выбрать режим работы.

Скрытые приложения:

* (ile.cgi) Запускается на веб сервере.
* (ile.dll) динамически подключаемая библиотека включающая лексер, парсер и всё что требуется для решения уравнения.

## Алгоритм работы приложения

1. Создаётся веб сервер по адресу 8000
2. Инициализируется приложение по средствам CGI в языке Си
3. Приложение работает и реагирует на изменения и вводимые данные на странице
4. При закрытии веб страницы приложение закрывается и завершает работу сервера.

## Более подробно

Существует лишь одно .exe приложение.

a. Если нет флагов для запуска в статическом режиме

    1. Инициализируется Web сервер, во время этого демоснтрируется иконка загрузки.
    2. CGI часть приложения связывается с сервером, и загружает интерфейс.
    3. Приложение работает
        3.1 Ожидает полного ввода уравнения и нажатия кнопки решения.
        3.2 Проводит токенизацию выражения и проверку на ошибки.
        3.3 Проводит парсинг и одновременно выводит шаги решения. (склоняюсь к сортировочной станции)
        3.4 Выводит результат вычислений.
        3.5 Может экспортировать решение в виде HTML файла страницы.
        3.6 Ожидает нажатия на кнопку "Решить другое"
    4. При закрытии начинает деинициализацию CGI
    5. Завершает работу сервера.
    6. Процесс приложения завершается.

b. Если есть флаги для статического режима

    1 Проводит токенизацию выражения и проверку на ошибки.
    2 Если есть флаг тишины --quite:
        2.1 Решение производиться и записывается либо в консоль, либо в любой файл.
    2 Если флага нет.
        2.2 Решение производиться пошагово аналогично графической веб версии. И может записаться аналогично тихому решению.
    3. Завершает работу в зависимости от режима работы.

## Более подробно о каждом приложении

### ile.exe

* Кросс-платформенная реализация с минимальным GUI. (Windows API или Linux X11)
* В статическом режиме самостоятельно вызывает ile.dll библиотеку с необходимым функционалом.
* В интерактивном режиме создаёт веб сервер и запускает ile.cgi файл.

### ile.cgi

* После запуска подключает ile.dll библиотеку.
* Начинает свою работу вплоть до завершения.

### ile.dll

* Содержит все функции связанные с парсером и математической составляющей.
