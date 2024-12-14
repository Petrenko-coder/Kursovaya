/**
 * @file cmd.h
 * @brief Заголовочный файл для класса CMDParser, предназначенного для парсинга командной строки.
 */

#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "error.h"

using namespace std;

/**
 * @class CMDParser
 * @brief Класс для парсинга аргументов командной строки и предоставления значений параметров.
 */
class CMDParser
{
private:
    string in = "./in.txt";    ///< Путь к входному файлу по умолчанию.
    string out = "./out.txt";  ///< Путь к выходному файлу по умолчанию.
    string cfg = "./cfg.txt";  ///< Путь к файлу конфигурации по умолчанию.
    string addr = "127.0.0.1"; ///< Адрес сервера по умолчанию.
    uint16_t port = 33333;     ///< Порт сервера по умолчанию.

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    CMDParser() = default;

    /**
     * @brief Получить путь к входному файлу.
     * @return Путь к входному файлу.
     */
    string getIn() const;

    /**
     * @brief Получить путь к выходному файлу.
     * @return Путь к выходному файлу.
     */
    string getOut() const;

    /**
     * @brief Получить путь к файлу конфигурации.
     * @return Путь к файлу конфигурации.
     */
    string getCfg() const;

    /**
     * @brief Получить адрес сервера.
     * @return Адрес сервера.
     */
    string getAddr() const;

    /**
     * @brief Получить порт сервера.
     * @return Порт сервера.
     */
    uint16_t getPort() const;

    /**
     * @brief Парсинг аргументов командной строки.
     * @param argc Количество аргументов.
     * @param argv Массив аргументов.
     * @throw VClientError Если встречен некорректный аргумент.
     */
    void parse(int argc, char *argv[]);

    /**
     * @brief Показать сообщение с информацией о параметрах командной строки.
     */
    void showHelp() const;
};
