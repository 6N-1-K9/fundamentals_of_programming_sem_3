#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include "validator.h"
#include <QValidator>
#include <QSpinBox>
#include <QMessageBox>
#include "patent.h"
#include <QRandomGenerator>
#include <iostream>
#include <QListWidgetItem>
#include <QLineEdit>
#include <QStandardItemModel>
#include <QString>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // подключаем кнопки
    connect(ui->save, SIGNAL(clicked(bool)), this, SLOT(on_save()));
    connect(ui->otmena, SIGNAL(clicked(bool)), this, SLOT(on_otmena()));
    connect(ui->listWidget,SIGNAL(currentRowChanged(int)),this,SLOT(change_record(int )));

    connect(ui->have_patent, SIGNAL(stateChanged(int)), this, SLOT(knopka(int)));

    //connect(ui->oblastCombo_3, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrtntIndexChanged(int)));
    connect(ui->oblast, SIGNAL(currentIndexChanged(int)), this, SLOT(ne_matan(int))); // короче первый инт это к

    QValidator *valid = new Validator(this); //
    ui->autors->setValidator(valid);// подключили валидатор к строке фио

    connect(ui->zapis_num, SIGNAL(valueChanged(int)), this, SLOT(list_num(int))); // подключили функцию к кнопке спинбокса

    connect(ui->save, SIGNAL(clicked()), this, SLOT(true_autors()));

    connect(ui->fill, SIGNAL(clicked(bool)), this, SLOT(on_fill()));
    connect(ui->del, SIGNAL(clicked(bool)), this, SLOT(on_delete()));
    connect(ui->create, SIGNAL(clicked(bool)), this, SLOT(on_create()));

    count = 0;
    ui->zapis_num->setValue(1);
}


MainWindow::~MainWindow()
{
    delete ui;
}



// РУБРИКА ЭКСПЕРИМЕНТЫ
// валедаторы отдельным файлом писать?

// функция запрета нобельки для математиков
void MainWindow::ne_matan(int k)
{
    if(k == 4)
    {
        Newrecord.setNobel(false);
        ui->nobel->setEnabled(false);
    }
    else
    {
        Newrecord.setNobel(false);
        ui->nobel->setEnabled(true);
    }
}
/*

*/

// а правильно ли оно работает?
void MainWindow::true_autors()
{
    if(!ui->autors->hasAcceptableInput())
        QMessageBox::warning(this,"Корректность ФИО", "Введи нормально ФИО");
    //QMessageBox::information(this,"Корректность строки", "Строка введена правильно");
    //else
}

// функция запрета ввода даты патента при его отсутсятвии
void MainWindow::knopka(int i)
{
    if(i)
    {
        ui->date_reg->setEnabled(true);
    }
    else
    {
        ui->date_reg->setEnabled(false);
    }
}

// функция рандомного заполнения
void MainWindow::on_fill()
{
    for (int i = 0; i < 10; i++)
    {
    count++;
    current = count - 1;
    if (count == 1)
    {
        int j;
        j = QRandomGenerator::global()->bounded(0, 5);
        Newrecord.setOblast(j);

        QString randNames[10]={"Имя_1",
                               "Имя_2",
                               "Имя_3",
                               "Имя_4",
                               "Имя_5",
                               "Имя_6",
                               "Имя_7",
                               "Имя_8",
                               "Имя_9",
                               "Имя_10"};
        j = QRandomGenerator::global()->bounded(0, 10);
        Newrecord.setName(randNames[j]);

        j = QRandomGenerator::global()->bounded(1900, 2024);
        Newrecord.setYear(j);

        QString randAutors[10]={"Иванов Иван Иванович",
                                "Петров Петр Петрович",
                                "Сидоров Сидор Сидорович",
                                "Козлова Елена Ивановна",
                                "Смирнова Наталья Александровна",
                                "Волков Алексей Викторович",
                                "Кузнецов Александр Александрович",
                                "Николаева Екатерина Павловна",
                                "Морозов Михаил Сергеевич",
                                "Калинина Ольга Андреевна"};
        j = QRandomGenerator::global()->bounded(0, 10);
        Newrecord.setAutors(randAutors[j]);

        j = QRandomGenerator::global()->bounded(0, 2);
        if (ui->oblast->currentIndex() != 4)
        {
            ui->nobel->setEnabled(false);
            if (j == 1)
            {
                //ui->nobel->setEnabled(true);
                Newrecord.setNobel(true);
            }
            else
            {
                Newrecord.setNobel(false);
            }
        }
        else
        {
            Newrecord.setNobel(false);
            ui->nobel->setEnabled(false);
        }


        // ДОПИСАТЬ
// Newrecord


        //Newrecord.setNobel(j);

        j = QRandomGenerator::global()->bounded(0, 2);
        if (j == 1)
        {
            Newrecord.setHave_Patent(true);
        }
        else
        {
             Newrecord.setHave_Patent(false);
        }
        //Newrecord.setHave_Patent(j);

        /* не получилось реализовать рандом по дате
        QString randData[10]={"10/10/2010",
                               "17/07/1978",
                               "01/03/2008",
                               "04/08/2002",
                               "02/07/1977",
                               "25/11/1987",
                               "01/02/1911",
                               "29/12/1999",
                               "18/08/1984",
                               "14/05/2014"};
        QDate data = QDate::fromString(QRandomGenerator::global()->bounded(0, 10));
        */
        record[current].setOblast(ui->oblast->currentIndex());
        record[current].setName(ui->name->text());
        record[current].setYear(ui->year->value());
        record[current].setAutors(ui->autors->text());
        record[current].setNobel(ui->nobel->isChecked());
        record[current].setHave_Patent(ui->have_patent->isChecked());
        record[current].setDate_Reg(ui->date_reg->date());
        append(current);
    }
    else
    {
        int j;
        j = QRandomGenerator::global()->bounded(0, 5);
        Newrecord.setOblast(j);

        QString randNames[10]={"Имя_1",
                               "Имя_2",
                               "Имя_3",
                               "Имя_4",
                               "Имя_5",
                               "Имя_6",
                               "Имя_7",
                               "Имя_8",
                               "Имя_9",
                               "Имя_10"};
        j = QRandomGenerator::global()->bounded(0, 10);
        Newrecord.setName(randNames[j]);

        j = QRandomGenerator::global()->bounded(1900, 2024);
        Newrecord.setYear(j);

        QString randAutors[10]={"Иванов Иван Иванович",
                               "Петров Петр Петрович",
                               "Сидоров Сидор Сидорович",
                               "Козлова Елена Ивановна",
                               "Смирнова Наталья Александровна",
                               "Волков Алексей Викторович",
                               "Кузнецов Александр Александрович",
                               "Николаева Екатерина Павловна",
                               "Морозов Михаил Сергеевич",
                               "Калинина Ольга Андреевна"};
        j = QRandomGenerator::global()->bounded(0, 10);
        Newrecord.setAutors(randAutors[j]);

        // ДОПИСАТЬ
        j = QRandomGenerator::global()->bounded(0, 2);
        if (ui->oblast->currentIndex() != 4)
        {
            ui->nobel->setEnabled(false);
            if (j == 1)
            {
                Newrecord.setNobel(true);
            }
            else
            {
                Newrecord.setNobel(false);
            }
        }
        else
        {
            Newrecord.setNobel(false);
            ui->nobel->setEnabled(false);
        }


        j = QRandomGenerator::global()->bounded(0, 2);
        if (j == 1)
        {
            Newrecord.setHave_Patent(true);
        }
        else
        {
             Newrecord.setHave_Patent(false);
        }

        insertRecord();
    }
    }
    //активность кнопок
    if (count>0)
    {
        ui->del->setEnabled(true);
        ui->save->setEnabled(true);
        ui->otmena->setEnabled(true);
    }

    if(count<90)
    {
        ui->create->setEnabled(true);
        ui->fill->setEnabled(true);
    }

    if (count==0)
    {
        ui->del->setEnabled(false);
        ui->save->setEnabled(false);
        ui->otmena->setEnabled(false);
    }
    if (count>90)
    {
        ui->create->setEnabled(false);
        ui->fill->setEnabled(false);
    }
}

void MainWindow::on_delete()
{
    ui->listWidget->blockSignals(true);
    if (count == 1)
    {
        count--;
        delete ui->listWidget->currentItem();
    }
    else
    {
        current = count - 1;
        count--;
        ROW = ui->listWidget->currentRow();

        delete ui->listWidget->currentItem();

        int j = 0;
        if (ROW != current)
        {
            for (j = ROW; j < current; j++)
            {
                record[j] = record[j+1];
            }
        }

        if (ROW > 1)
        {
            ui->listWidget->setCurrentRow(ROW-1);
            ui->oblast->setCurrentIndex(record[ROW - 1].getOblast());
            ui->name->setText(record[ROW - 1].getName());
            ui->year->setValue(record[ROW - 1].getYear());
            ui->autors->setText(record[ROW - 1].getAutors());
            ui->nobel->setChecked(record[ROW - 1].getNobel());
            ui->have_patent->setChecked(record[ROW - 1].getHave_Patent());
            ui->date_reg->setDate(record[ROW - 1].getDate_Reg());
        }
        else
        {
            ui->listWidget->setCurrentRow(0);
            ui->oblast->setCurrentIndex(record[0].getOblast());
            ui->name->setText(record[0].getName());
            ui->year->setValue(record[0].getYear());
            ui->autors->setText(record[0].getAutors());
            ui->nobel->setChecked(record[0].getNobel());
            ui->have_patent->setChecked(record[0].getHave_Patent());
            ui->date_reg->setDate(record[0].getDate_Reg());
        }
    }
    ui->listWidget->blockSignals(false);

    //активность кнопок
    if (count>0)
    {
        ui->del->setEnabled(true);
       // ui->save->setEnabled(true);
        //ui->otmena->setEnabled(true);
    }

    if(count<100)
    {
        ui->create->setEnabled(true);
       // ui->fill->setEnabled(true);
    }

    if (count==0)
    {
        ui->del->setEnabled(false);
        ui->save->setEnabled(false);
        ui->otmena->setEnabled(false);
    }
    if (count<=90)
    {
        //ui->create->setEnabled(false);
        ui->fill->setEnabled(true);
    }
}

// функция создания записи
void MainWindow::on_create()
{
    count++;
    current = count - 1;
    if (count == 1)
    {
        record[current].setOblast(ui->oblast->currentIndex());
        record[current].setName(ui->name->text());
        record[current].setYear(ui->year->value());
        record[current].setAutors(ui->autors->text());
        record[current].setNobel(ui->nobel->isChecked());
        record[current].setHave_Patent(ui->have_patent->isChecked());
        record[current].setDate_Reg(ui->date_reg->date());
        record[current].setZapis_Num(ui->zapis_num->value());
        append(current);
        ui->listWidget->setCurrentRow(0);
        //record[current].setYear(ui->year->value());
    }
    else
    {
        Newrecord.setOblast(ui->oblast->currentIndex());
        Newrecord.setName(ui->name->text());
        Newrecord.setYear(ui->year->value());
        Newrecord.setAutors(ui->autors->text());
        Newrecord.setNobel(ui->nobel->isChecked());
        Newrecord.setHave_Patent(ui->have_patent->isChecked());
        Newrecord.setDate_Reg(ui->date_reg->date());
        Newrecord.setZapis_Num(ui->zapis_num->value());

        insertRecord();
    }
    // активность кнопок
    if(count > 0)
    {
        ui->del->setEnabled(true);
        ui->save->setEnabled(true);
        ui->otmena->setEnabled(true);
    }
    if (count == 100)
    {
        ui->create->setEnabled(false);
    }
    else
    {
        ui->create->setEnabled(true);
    }
}

void MainWindow::insertRecord()
{
    // Записываем содержимое записи на основе полей ввода
    int j=0;
    bool flag=1;

    for(j=0;j<current+1&&flag;j++)//начинаем искать правильное место для вставки
    {
        if(Newrecord>record[j])//нашли запись которая должна стоять не в конце
        {
             boofer=record[j];//запоминаем старую запись
             record[j]=Newrecord;//ставим новую запись на место старой
             set(j);//обновляем запись в таблице
             flag=0;//ставим флаг на то что надо сдвинуть элементы вниз относительно этого индекса
             ui->listWidget->setCurrentRow(j);
        }
        else if (j==current)//запись надо написать на последнее место
        {
            record[current]=Newrecord;//записываем на последнее место
            append(current);//обновляем запись
            ui->listWidget->setCurrentRow(j);
        }
    }
    if(flag==0)//флаг на то что сдвигаем массив
    {
        for(int len=current;len>j;len--)//идем по массиву начиная с предпоследнего элемента
        {
            record[len]=record[len-1];//сдвигаем запсь на один вниз
            //append(len);//обновляем таблицу
        }
        record[j]=boofer;//ставим элемент на одну позицию ниже та запись вместо которой была поставлена новая запись
     //  append(j);//обновляем таблицу
    }
}

void MainWindow::change_record(int current_record)
{
    int num = current_record;

    int oblast = record[num].getOblast();
    QString name = record[num].getName();
    int year = record[num].getYear();
    QString autors = record[num].getAutors();
    int nobel = record[num].getNobel();
    int have_patent = record[num].getHave_Patent();
    QDate date_reg = record[num].getDate_Reg();

    ui->oblast->setCurrentIndex(oblast);
    ui->name->setText(name);
    ui->year->setValue(year);
    ui->autors->setText(autors);
    ui->nobel->setChecked(nobel);
    ui->have_patent->setChecked(have_patent);
    ui->date_reg->setDate(date_reg);
}

void MainWindow::set(int indexs)
{
    QString patent = ((QString("Область ") + ((record[indexs].OBLAST[record[indexs].getOblast()]))
                      + QString("\t год ") + (QString::number(record[indexs].getYear()))
                      + QString("\t наименование " + ((record[indexs].getName())))));
    ui->listWidget->insertItem(indexs, patent);
}

// функция добавления записи
void MainWindow::append(int index)
{
    // добавляем запись в браузер
    QString patent = ((QString("Область ") + ((record[index].OBLAST[record[index].getOblast()]))
                      + QString("\t год ") + (QString::number(record[index].getYear()))
                      + QString("\t наименование " + ((record[index].getName())))));
    ui->listWidget->addItem(patent);
}


// функция сохранения ококн в память (кнопка сохранить)
void MainWindow::on_save()
{
    record[ui->zapis_num->value()-1].oblast = ui->oblast->currentIndex(); // выбрали область

    record[ui->zapis_num->value()-1].name = ui->name->text(); //сохранили название работы
    record[ui->zapis_num->value()-1].autors = ui->autors->text(); // сохранили авторов

    record[ui->zapis_num->value()-1].nobel = ui->nobel->isChecked(); //сохранили нобелевку
    record[ui->zapis_num->value()-1].have_patent = ui->have_patent->isChecked(); //сохранили патент с ним вопросты с сохраном

    record[ui->zapis_num->value()-1].year = ui->year->value(); // сохранили год
    record[ui->zapis_num->value()-1].date_reg = ui->date_reg->date(); // сохранили дату патента

    record[ui->zapis_num->value()-1].zapis_num = ui->zapis_num->value(); // сохранили номер записи

}

// функция возврата значений оконо из памяти (кнопка отмена)
void MainWindow::on_otmena()
{
    ui->oblast->setCurrentIndex(record[ui->zapis_num->value()-1].oblast); // вывели область из памяти

    ui->name->setText(record[ui->zapis_num->value()-1].name); // вывели название работы из памяти
    ui->autors->setText(record[ui->zapis_num->value()-1].autors); // вывели авторов из памяти

    ui->nobel->setChecked(record[ui->zapis_num->value()-1].nobel); //вывели нобелевку из памяти
    ui->have_patent->setChecked(record[ui->zapis_num->value()-1].have_patent); // вывели патент из памяти

    ui->year->setValue(record[ui->zapis_num->value()-1].year); // вывели год
    ui->date_reg->setDate(record[ui->zapis_num->value()-1].date_reg); //вывели дату патента из памяти

    ui->zapis_num->setValue(record[ui->zapis_num->value()-1].zapis_num); //вывели номер записи из памяти
}

// функция смены значений ококн по спинбоксу
void MainWindow::list_num(int s)
{
    s = ui->zapis_num->value();
    if (s == 1)
    {
        ui->oblast->setCurrentIndex(record[ui->zapis_num->value()-1].oblast); // вывели область из памяти

        ui->name->setText(record[ui->zapis_num->value()-1].name); // вывели название работы из памяти
        ui->autors->setText(record[ui->zapis_num->value()-1].autors); // вывели авторов из памяти

        ui->nobel->setChecked(record[ui->zapis_num->value()-1].nobel); //вывели нобелевку из памяти
        ui->have_patent->setChecked(record[ui->zapis_num->value()-1].have_patent); // вывели патент из памяти

        ui->year->setValue(record[ui->zapis_num->value()-1].year); // вывели год
        ui->date_reg->setDate(record[ui->zapis_num->value()-1].date_reg); //вывели дату патента из памяти

        //ui->zapis_num->setValue(record[ui->zapis_num->value()-1].zapis_num); //вывели номер записи из памяти
    }
    else
    {
        ui->oblast->setCurrentIndex(record[ui->zapis_num->value()-1].oblast); // вывели область из памяти

        ui->name->setText(record[ui->zapis_num->value()-1].name); // вывели название работы из памяти
        ui->autors->setText(record[ui->zapis_num->value()-1].autors); // вывели авторов из памяти

        ui->nobel->setChecked(record[ui->zapis_num->value()-1].nobel); //вывели нобелевку из памяти
        ui->have_patent->setChecked(record[ui->zapis_num->value()-1].have_patent); // вывели патент из памяти

        ui->year->setValue(record[ui->zapis_num->value()-1].year); // вывели год
        ui->date_reg->setDate(record[ui->zapis_num->value()-1].date_reg); //вывели дату патента из памяти

       // ui->zapis_num->setValue(record[ui->zapis_num->value()-1].zapis_num); //вывели номер записи из памяти
    }
}

