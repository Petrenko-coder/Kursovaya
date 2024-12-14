/**
 * @file vclient.h
 * @brief Заголовочный файл для класса VClient, предназначенного для взаимодействия с сервером.
 */

#pragma once

#include <cstdint>
#include <string>
#include <cstring>
#include <array>
#include <iostream>
#include <vector>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "error.h"
#include "sha224.h"

using namespace std;

/**
 * @class VClient
 * @brief Класс для взаимодействия с сервером.
 */
class VClient
{
private:
    int sock;              ///< Сокет для связи с сервером.
    string addr;           ///< Адрес сервера.
    uint16_t port;         ///< Порт сервера.
    array<string, 2> conf; ///< Конфигурационные данные (логин и пароль).

public:
    /**
     * @brief Конструктор класса VClient.
     * @param addr Адрес сервера.
     * @param port Порт сервера.
     * @param conf Конфигурационные данные (логин и пароль).
     */
    VClient(string addr, uint16_t port, array<string, 2> conf);

    /**
     * @brief Соединение с сервером.
     * @throw VClientError Если возникает ошибка при создании сокета, преобразовании адреса или соединении.
     */
    void conn();

    /**
     * @brief Остановка соединения с сервером.
     */
    void stop();

    /**
     * @brief Аутентификация на сервере.
     * @throw VClientError Если возникает ошибка при отправке сообщения аутентификации или при получении ответа.
     */
    void auth();

    /**
     * @brief Отправка данных на сервер для вычислений.
     * @param data Вектор векторов данных для отправки.
     * @return Вектор результатов, полученных от сервера.
     * @throw VClientError Если возникает ошибка при отправке данных или получении результатов.
     */
    vector<uint32_t> calc(vector<vector<uint32_t>> data);

    /**
     * @brief Получить сокет.
     * @return Сокет.
     */
    int getSock();

    /**
     * @brief Получить адрес сервера.
     * @return Адрес сервера.
     */
    string getAddr();

    /**
     * @brief Получить порт сервера.
     * @return Порт сервера.
     */
    uint16_t getPort();

    /**
     * @brief Получить конфигурационные данные.
     * @return Конфигурационные данные.
     */
    array<string, 2> getConf();
};
