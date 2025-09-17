#include "validator.h"
#include <QByteArray>
#include <QChar>
#include <QString>
#include <QValidator>
Validator::Validator(QObject* parent)
    : QValidator (parent)
{

}

// не лезть
Validator::~Validator()
{

}

QValidator::State Validator::validate(QString &string, int &pos) const
{
    // Запрет ввода посторонних символов
    for (int i = 0; i < string.length(); i++)
    {
        if (!string[i].isLetter() && string[i] != ' ' && string[i] != ',')
            return QValidator::Invalid;
    }

    // запреты на два символа подряд
    for (int i = 1; i < string.length(); i++)
    {
        if (string[i] == ',' && string[i - 1] == ' ')
            return QValidator::Invalid;
    }

    for (int i = 1; i < string.length(); i++)
    {
        if (string[i] == ' ' && string[i - 1] == ' ')
            return QValidator::Invalid;
    }

    for (int i = 1; i < string.length(); i++)
    {
        if (string[i] == ',' && string[i - 1] == ',')
            return QValidator::Invalid;
    }

    if (string[0].isLower()) return QValidator::Invalid; // запрет первой прописной

    // большая буква после пробела
    for (int i = 1; i <string.length(); i++)
    {
        if(string[i].isLower() && string[i-1] == ' ') return QValidator::Invalid;
    }

    // запрет на ввод букв после запятой
    for (int i = 1; i<string.length(); i++)
    {
        if (string[i].isLetter() && string[i-1] == ',') return QValidator::Invalid;
    }

    // запрет на заглавные в серединне слова
    for(int i = 1; i<string.length(); i++)
    {
        if(string[i].isUpper() && (string[i-1].isUpper() || string[i-1].isLower())) // модернизировать условие
            return QValidator::Invalid;
    }

    // запятая после фио
    int uppers = 0; // счетчик заглавных буков
    for(int i = 0; i < string.length(); i++)
    {
        if(string[i].isUpper())
            uppers++;
        if(uppers % 3 == 0)
        {
            if(string[i] == ' ' && string[i - 1].isLower()) return QValidator::Invalid; // запрет ввода четвертого слова в фио
        }
        else
        {
            if(string[i] == ',') return QValidator::Invalid; // запрет ввода пробела в середине фио
        }
    }

    // строка заканчивается на ,
    int fio_razd = 0; // счетчик запятых
    for (int i = 0; i < string.length(); i++)
    {
        if (string[i] == ',')
            fio_razd++;
    }

    if ((uppers)/3 - fio_razd != 1)
            return QValidator::Intermediate;

    if(uppers % 3 == 0 && uppers != 0)
        return QValidator::Acceptable;
    //if (string[string.length()] == ' ' || string[string.length()] == ',')
    //return QValidator::Intermediate;
}

