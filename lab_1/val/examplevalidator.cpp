#include "examplevalidator.h"

ExampleValidator::ExampleValidator(QObject* parent)
    : QValidator (parent)
{

}

ExampleValidator::~ExampleValidator()
{

}

QValidator::State ExampleValidator::validate(QString &string, int &pos) const
{
    //запрет на ввод посторонних символов
    for(int i = 0; i<string.length(); i++)
    {
        if(!string[i].isLetter() && string[i] != ' ' && string[i] != '-')
            return QValidator::Invalid;
    }

    // запрет на два символа подряд
    for(int i = 1; i < string.length(); i++)
    {
        if((string[i] == ' ' || string[i] == '-') && (string[i-1] == ' ' || string[i-1] == '-'))
            return QValidator::Invalid;
    }

    // после тире или пробела заглавная
    for(int i = 1; i < string.length(); i++)
    {
        if(string[i].isLower() && (string[i - 1] == ' ' || string[i - 1] == '-'))
            return QValidator::Invalid;
    }

    // тире до первого пробела
    for(int i = 0; i < string.length(); i++)
    {
        if(string.count('-') == 2)
        {
            if(string.indexOf('-') > string.lastIndexOf(' '))
                return QValidator::Invalid;
        }
    }

    // запрет на прописные буквы в середине слов
    for(int i = 1; i<string.length(); i++)
    {
        if(string[i].isUpper() && (string[i-1].isUpper() || string[i-1].isLower())) // модернизировать условие
            return QValidator::Invalid;
    }

    //Допустимый ввод (количество пробелов и тире, начало не с символа, начало с большой буквы)
    if(string.count('-') <= 1 && string.count(' ') <= 2 && string[0] != ' ' && string[0] != '-' && !string[0].isLower())
        return QValidator::Acceptable;
    else
    {
        return QValidator::Invalid;
    }



    return QValidator::Intermediate;
}
