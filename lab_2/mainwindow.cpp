#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include "validator.h"
#include <QValidator>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // подключаем кнопки
    connect(ui->btnSave_2, SIGNAL(clicked(bool)), this, SLOT(on_save()));
    connect(ui->btnOtmena_2, SIGNAL(clicked(bool)), this, SLOT(on_otmena()));


    connect(ui->patent_3, SIGNAL(stateChanged(int)), this, SLOT(knopka(int)));

    //connect(ui->oblastCombo_3, SIGNAL(currentIndexChanged(int)), this, SLOT(onCurrtntIndexChanged(int)));
    connect(ui->oblastCombo_3, SIGNAL(currentIndexChanged(int)), this, SLOT(ne_matan(int))); // короче первый инт это к

    QValidator *valid = new Validator(this); //
    ui->autors_3->setValidator(valid);// подключили валидатор к строке фио

    connect(ui->zapisNum_2, SIGNAL(valueChanged(int)), this, SLOT(list_num(int))); // подключили функцию к кнопке спинбокса
}

MainWindow::~MainWindow()
{
    delete ui;
}

// РУБРИКА ЭКСПЕРИМЕНТЫ
// валедаторы отдельным файлом писать?


void MainWindow::ne_matan(int k)
{

    if(k == 4)
    {
        ui->nobel_3->setEnabled(false);
    }
    else
    {
        ui->nobel_3->setEnabled(true);
    }
}


// функция запрета ввода даты патента при его отсутсятвии
void MainWindow::knopka(int i)
{
    if(i)
    {
        ui->patent_data_3->setEnabled(true);
    }
    else
    {
        ui->patent_data_3->setEnabled(false);
    }
}

// функция сохранения ококн в память (кнопка сохранить)
void MainWindow::on_save()
{
    record[ui->zapisNum_2->value()-1].oblastCombo_3 = ui->oblastCombo_3->currentIndex(); // выбрали область

    record[ui->zapisNum_2->value()-1].name_3 = ui->name_3->text(); //сохранили название работы
    record[ui->zapisNum_2->value()-1].autors_3 = ui->autors_3->text(); // сохранили авторов

    record[ui->zapisNum_2->value()-1].nobel_3 = ui->nobel_3->isChecked(); //сохранили нобелевку
    record[ui->zapisNum_2->value()-1].patent_3 = ui->patent_3->isChecked(); //сохранили патент с ним вопросты с сохраном

    record[ui->zapisNum_2->value()-1].year_3 = ui->year_3->value(); // сохранили год
    record[ui->zapisNum_2->value()-1].patent_data_3 = ui->patent_data_3->date(); // сохранили дату патента

    record[ui->zapisNum_2->value()-1].zapisNum_2 = ui->zapisNum_2->value(); // сохранили номер записи


}

// функция возврата значений оконо из памяти (кнопка отмена)
void MainWindow::on_otmena()
{
    ui->oblastCombo_3->setCurrentIndex(record[ui->zapisNum_2->value()-1].oblastCombo_3); // вывели область из памяти

    ui->name_3->setText(record[ui->zapisNum_2->value()-1].name_3); // вывели название работы из памяти
    ui->autors_3->setText(record[ui->zapisNum_2->value()-1].autors_3); // вывели авторов из памяти

    ui->nobel_3->setChecked(record[ui->zapisNum_2->value()-1].nobel_3); //вывели нобелевку из памяти
    ui->patent_3->setChecked(record[ui->zapisNum_2->value()-1].patent_3); // вывели патент из памяти

    ui->year_3->setValue(record[ui->zapisNum_2->value()-1].year_3); // вывели год
    ui->patent_data_3->setDate(record[ui->zapisNum_2->value()-1].patent_data_3); //вывели дату патента из памяти

    ui->zapisNum_2->setValue(record[ui->zapisNum_2->value()-1].zapisNum_2); //вывели номер записи из памяти
}

// функция смены значений ококн по спинбоксу
void MainWindow::list_num(int s)
{
    s = ui->zapisNum_2->value();
    if (s == 1)
    {
        ui->oblastCombo_3->setCurrentIndex(record[ui->zapisNum_2->value()-1].oblastCombo_3); // вывели область из памяти

        ui->name_3->setText(record[ui->zapisNum_2->value()-1].name_3); // вывели название работы из памяти
        ui->autors_3->setText(record[ui->zapisNum_2->value()-1].autors_3); // вывели авторов из памяти

        ui->nobel_3->setChecked(record[ui->zapisNum_2->value()-1].nobel_3); //вывели нобелевку из памяти
        ui->patent_3->setChecked(record[ui->zapisNum_2->value()-1].patent_3); // вывели патент из памяти

        ui->year_3->setValue(record[ui->zapisNum_2->value()-1].year_3); // вывели год
        ui->patent_data_3->setDate(record[ui->zapisNum_2->value()-1].patent_data_3); //вывели дату патента из памяти

        ui->zapisNum_2->setValue(record[ui->zapisNum_2->value()-1].zapisNum_2); //вывели номер записи из памяти
    }
    else
    {
        ui->oblastCombo_3->setCurrentIndex(record[ui->zapisNum_2->value()-1].oblastCombo_3); // вывели область из памяти

        ui->name_3->setText(record[ui->zapisNum_2->value()-1].name_3); // вывели название работы из памяти
        ui->autors_3->setText(record[ui->zapisNum_2->value()-1].autors_3); // вывели авторов из памяти

        ui->nobel_3->setChecked(record[ui->zapisNum_2->value()-1].nobel_3); //вывели нобелевку из памяти
        ui->patent_3->setChecked(record[ui->zapisNum_2->value()-1].patent_3); // вывели патент из памяти

        ui->year_3->setValue(record[ui->zapisNum_2->value()-1].year_3); // вывели год
        ui->patent_data_3->setDate(record[ui->zapisNum_2->value()-1].patent_data_3); //вывели дату патента из памяти

        ui->zapisNum_2->setValue(record[ui->zapisNum_2->value()-1].zapisNum_2); //вывели номер записи из памяти
    }
}
