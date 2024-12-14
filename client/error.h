/**
 * @file error.h
 * @brief Заголовочный файл для класса VClientError, предназначенного для обработки ошибок клиента.
 */

#pragma once

#include <string>
#include <exception>

using namespace std;

/**
 * @class VClientError
 * @brief Класс для представления ошибок клиента.
 */
class VClientError : public exception {
public:
    /**
     * @brief Конструктор класса VClientError.
     * @param errorName Название ошибки.
     * @param errorMsg Сообщение об ошибке.
     * @param funcName Название функции, где произошла ошибка.
     */
    VClientError(const string& errorName, const string& errorMsg, const string& funcName);

    /**
     * @brief Получить полное сообщение об ошибке.
     * @return Полное сообщение об ошибке.
     */
    const char* what() const noexcept override;

    /**
     * @brief Получить название ошибки.
     * @return Название ошибки.
     */
    string getErrorName() const;

    /**
     * @brief Получить сообщение об ошибке.
     * @return Сообщение об ошибке.
     */
    string getErrorMsg() const;

    /**
     * @brief Получить название функции, где произошла ошибка.
     * @return Название функции.
     */
    string getFuncName() const;

private:
    string errorName; ///< Название ошибки.
    string errorMsg; ///< Сообщение об ошибке.
    string funcName; ///< Название функции, где произошла ошибка.
    mutable string fullMsg; ///< Полное сообщение об ошибке.
};
