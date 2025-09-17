#include "patent.h"

PATENT::PATENT()
{

}

int PATENT::getOblast()
{
    return oblast;
}
void PATENT::setOblast(int _Oblast)
{
    oblast=_Oblast;
}

QString PATENT::getName()
{
    return name;
}
void PATENT::setName(QString _Name)
{
    name = _Name;
}

int PATENT::getYear()
{
    return year;
}
void PATENT::setYear(int _Year)
{
    year = _Year;
}

QString PATENT::getAutors()
{
    return autors;
}
void PATENT::setAutors(QString _Autors)
{
    autors = _Autors;
}

int PATENT::getNobel()
{
    return nobel;
}
void PATENT::setNobel(int _Nobel)
{
    nobel = _Nobel;
}

int PATENT::getHave_Patent()
{
    return have_patent;
}
void PATENT::setHave_Patent(int _Have_Patent)
{
    have_patent = _Have_Patent;
}

QDate PATENT::getDate_Reg()
{
    return date_reg;
}
void PATENT::setDate_Reg(QDate _Date_Reg)
{
    date_reg = _Date_Reg;
}

int PATENT::getZapis_Num()
{
    return zapis_num;
}
void PATENT::setZapis_Num(int _Zapis_Num)
{
    zapis_num = _Zapis_Num;
}


bool PATENT::operator==(const PATENT &other) const
{
    if (oblast == other.oblast)
    {
        if (year == other.year)
        {
            if (name == other.name)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool PATENT::operator!=(const PATENT &other) const
{
    if (oblast == other.oblast)
    {
        if (year == other.year)
        {
            if (name == other.name)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}

bool PATENT::operator < (const PATENT &other) const
{
    bool flag_oblast = 0;
    bool flag_year = 0;
    bool flag_name = 0;

    if (oblast > other.oblast)
    {
        flag_oblast = 1;
    }

    if (year > other.year && (flag_oblast || oblast == other.oblast))
    {
        flag_year = 1;
    }

    if (name > other.name && (flag_oblast || oblast == other.oblast) && (flag_year || year == other.year))
    {
        flag_name = 1;
    }

    return (flag_name || flag_year || flag_oblast);
}

bool PATENT::operator > (const PATENT &other) const
{
    bool flag_oblast = 0;
    bool flag_year = 0;
    bool flag_name = 0;
    if (oblast < other.oblast)
    {
        flag_oblast = 1;
    }
    if (year < other.year && (flag_oblast || oblast == other.oblast))
    {
        flag_year = 1;
    }
    if (name < other.name && (flag_oblast || oblast == other.oblast) && (flag_year || year == other.year))
    {
        flag_name = 1;
    }
    return (flag_oblast || flag_year || flag_name);
}

bool PATENT::operator <= (const PATENT &other) const
{
    bool flag_oblast = 0;
    bool flag_year = 0;
    bool flag_name = 0;
    if (oblast >= other.oblast)
    {
        flag_oblast = 1;
    }
    if (year >= other.year && (flag_oblast || oblast == other.oblast))
    {
        flag_year = 1;
    }
    if (name >= other.name && (flag_oblast || oblast == other.oblast) && (flag_year || year == other.year))
    {
        flag_name = 1;
    }
    return (flag_oblast || flag_year || flag_name);
}

bool PATENT::operator >= (const PATENT &other) const
{
    bool flag_oblast = 0;
    bool flag_year = 0;
    bool flag_name = 0;
    if (oblast <= other.oblast)
    {
        flag_oblast = 1;
    }
    if (year <= other.year && (flag_oblast || oblast == other.oblast))
    {
        flag_year = 1;
    }
    if (name <= other.name && (flag_oblast || oblast == other.oblast) && (flag_year || year == other.year))
    {
        flag_name = 1;
    }
    return (flag_oblast || flag_year || flag_name);
}


// ДОПИСАТЬ ПЕРЕГРУЗКУ + MAIN CPP
// заполнить попозже
void PATENT::operator=(PATENT &other)
{
    oblast = other.oblast;
    name = other.name;
    year = other.year;
    autors = other.autors;
    nobel = other.nobel;
    have_patent = other.have_patent;
    date_reg = other.date_reg;
    zapis_num = other.zapis_num;
}
