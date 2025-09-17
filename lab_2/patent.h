#ifndef PATENT_H
#define PATENT_H

#include <QWidget>
#include <QDateEdit>
#include "QString"
#include <QValidator>
class patent : public QWidget
{
    Q_OBJECT
public:
    explicit patent(QWidget *parent = nullptr);

    int oblastCombo_3; // возможно бесполезно

    // КОРОЧЕ ГОВОРЯ ТУТ УКАЗЫВАЕМ ТИПЫ ДАННЫХ ОКОШЕК, КОТОРЫЕ БУДЕМ МЕНЯТЬ
    QString name_3;
    int year_3;
    QString autors_3;
    bool nobel_3;
    bool patent_3;
    QDate patent_data_3;
    int zapisNum_2;


signals:

public slots:
};

#endif // PATENT_H
