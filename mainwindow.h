#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void razbor(QString s,int m);
    QString sdvig(QString s,int k,int b);
    void p_sred();
    void obsh_sred();
    void p_square();
    void Robsh();
    void Rf();
    void Rost();
    void Sf();
    void Sost();
    void Fnabl();

private slots:
    void on_OK_clicked();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
