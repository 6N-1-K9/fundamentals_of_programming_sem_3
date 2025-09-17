#ifndef PATENT_H
#define PATENT_H


#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDate>
#include "QString"
#include "QValidator"


class PATENT //: public QWidget
{
     //Q_OBJECT
public:
    //explicit PATENT(QWidget *parent = nullptr); мб нужно вернуть

    PATENT();

    void setOblast(int _Oblast);
    int getOblast();

    void setName(QString _Name);
    QString getName();

    void setYear(int _Year);
    int getYear();

    void setAutors(QString _Autors);
    QString getAutors();

    void setNobel(int _Nobel);
    int getNobel();

    void setHave_Patent(int _Have_Patent);
    int getHave_Patent();

    void setDate_Reg(QDate _Date_Reg);
    QDate getDate_Reg();

    void setZapis_Num(int _Zapis_Num);
    int getZapis_Num();

    QValidator::State validate(QString & string, int & pos) const;

    void operator =(PATENT &other);
    bool  operator==(const PATENT &other)const;
    bool  operator!=(const PATENT &other)const;
    bool  operator<(const PATENT &other)const;
    bool  operator>(const PATENT &other)const;
    bool  operator>=(const PATENT &other)const;
    bool  operator<=(const PATENT &other)const;
    QString OBLAST[5]={"Электроника и ВТ","Химия","Физика", "Биология", "Математика"};

public:

    int oblast; //
    QString name; //
    int year; //
    QString autors; //
    bool nobel; //
    bool have_patent; //
    QDate date_reg; //
    int zapis_num; //



private:
    //PATENT();
/*
    int oblast; //
    QString name; //
    int year; //
    QString autors; //
    bool nobel; //
    bool have_patent; //
    QDate date_reg; //
    int zapis_num; //

*/


//signals:

};

#endif // PATENT_CLASS
