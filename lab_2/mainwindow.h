#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patent.h"
#include "validator.h"
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    patent record[2];

    // описание функций для кнопок
private slots:
    void on_save();
    void on_otmena();


    void knopka(int i); // сделали чекбокс патента кнопкой
    void ne_matan(int k);

    void list_num(int s); // функция смены зеачений по спинбоксу
};
#endif // MAINWINDOW_H
