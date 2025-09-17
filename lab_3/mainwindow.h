#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "patent.h"
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    PATENT record[101];
    PATENT boofer;
    PATENT Newrecord;

    int current; // индекс последнего элемента в массиве
    int count; // количество записей в человеческом виде
    void append(int);
    void set(int);
    QListWidgetItem Item;
    int ROW;


private:
    Ui::MainWindow *ui;

    //описание функций
private slots:
    void true_autors();

    void on_save();
    void on_otmena();

    void knopka(int i); // сделали чекбокс патента кнопкой
    void ne_matan(int k);

    void list_num(int s); // функция смены зеачений по спинбоксу

    void on_fill();
    void on_delete();
    void on_create();
    void insertRecord();
    void change_record(int current_record);

};
#endif // MAINWINDOW_H
