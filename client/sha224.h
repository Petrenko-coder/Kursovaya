/**
 * @file sha224.h
 * @brief Заголовочный файл для функций хеширования и генерации соли.
 */

#pragma once

#include <string>
#include <cryptopp/hex.h>
#include <cryptopp/sha.h>
#include <cryptopp/osrng.h>

using namespace std;

/**
 * @brief Генерация случайной соли.
 * @return Случайная строка соли.
 */
string salt();

/**
 * @brief Вычисление SHA-224 хеша для данных.
 * @param data Ссылка на строку с данными для хеширования.
 * @return Строка с хешем данных в шестнадцатеричном представлении.
 */
string sha224(string &data);
