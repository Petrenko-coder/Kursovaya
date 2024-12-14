/**
 * @file rw.h
 * @brief Заголовочный файл для класса ReadWrite, предназначенного для чтения и записи данных.
 */

#pragma once

#include <string>
#include <vector>
#include <array>
#include <cstdint>
#include <fstream>
#include <sstream>
#include <iostream>
#include "error.h"

using namespace std;

/**
 * @class ReadWrite
 * @brief Класс для чтения и записи данных в файлы.
 */
class ReadWrite
{
public:
    /**
     * @brief Конструктор класса ReadWrite.
     * @param inVec Путь к входному файлу.
     * @param outVec Путь к выходному файлу.
     * @param cfg Путь к файлу конфигурации.
     */
    ReadWrite(string &inVec, string &outVec, string &cfg);

    /**
     * @brief Получить путь к входному файлу.
     * @return Путь к входному файлу.
     */
    string getIn();

    /**
     * @brief Получить путь к выходному файлу.
     * @return Путь к выходному файлу.
     */
    string getOut();

    /**
     * @brief Получить путь к файлу конфигурации.
     * @return Путь к файлу конфигурации.
     */
    string getCfg();

    /**
     * @brief Записать вектор данных в выходной файл.
     * @param data Вектор данных для записи.
     * @throw VClientError Если возникает ошибка при открытии или записи в файл.
     */
    void writeVec(const vector<uint32_t> &data);

    /**
     * @brief Прочитать вектор данных из входного файла.
     * @return Вектор векторов данных, считанных из файла.
     * @throw VClientError Если возникает ошибка при открытии или чтении файла.
     */
    vector<vector<uint32_t>> readVec();

    /**
     * @brief Прочитать данные конфигурации из файла конфигурации.
     * @return Массив строк с данными конфигурации.
     * @throw VClientError Если возникает ошибка при открытии или чтении файла конфигурации.
     */
    array<string, 2> readCfg();

private:
    string in; ///< Путь к входному файлу.
    string out; ///< Путь к выходному файлу.
    string cfg; ///< Путь к файлу конфигурации.
};

/**
 * @brief Функция для вывода вектора uint32_t.
 * @param vec Вектор данных для вывода.
 */
void printVector(const vector<uint32_t> &vec);

/**
 * @brief Функция для рекурсивного вывода вложенных векторов.
 * @param vec Вектор векторов данных для вывода.
 */
void printVectors(const vector<vector<uint32_t>> &vec);
