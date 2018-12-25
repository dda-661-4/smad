#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QByteArray>
#include <qDebug>
#include <QTextStream>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tableWidget->setColumnCount(13);
    ui->tableWidget->setRowCount(100);
     ui->tableWidget->setShowGrid(true);
      ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem(tr("proga")));
     ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem(tr("date")));
      ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem(tr("P1")));
      ui->tableWidget->setHorizontalHeaderItem(3,new QTableWidgetItem(tr("P2")));
      ui->tableWidget->setHorizontalHeaderItem(4,new QTableWidgetItem(tr("OBSH_SRED")));
      ui->tableWidget->setHorizontalHeaderItem(5,new QTableWidgetItem(tr("p1^2")));
      ui->tableWidget->setHorizontalHeaderItem(6,new QTableWidgetItem(tr("p2^2")));
      ui->tableWidget->setHorizontalHeaderItem(7,new QTableWidgetItem(tr("Robsh")));
       ui->tableWidget->setHorizontalHeaderItem(8,new QTableWidgetItem(tr("Rf")));
       ui->tableWidget->setHorizontalHeaderItem(9,new QTableWidgetItem(tr("Rost")));
       ui->tableWidget->setHorizontalHeaderItem(10,new QTableWidgetItem(tr("Sf")));
       ui->tableWidget->setHorizontalHeaderItem(11,new QTableWidgetItem(tr("Sost")));
       ui->tableWidget->setHorizontalHeaderItem(12,new QTableWidgetItem(tr("Fnabl")));





}

MainWindow::~MainWindow()
{
    delete ui;
}

QFile file;
int STROKA=0;
QTableWidgetItem *item;
int mass1[1000];
int mass2[10];
int MASS=0;
void MainWindow::on_OK_clicked()
{
    QString s = QFileDialog::getOpenFileName(0,"open the file","D:/c++11/smad/smad/SMAD.txt","");
     file.setFileName(s);

      QString line ;
      int c ;
     file.open(QIODevice::ReadOnly);

         QTextStream in(&file);
         while (!in.atEnd())
         {
         line = in.readLine();
        c = line.size();

           MainWindow::razbor(line,c);
           if(MASS==10)
           {
              // qDebug()<<MASS;
              // qDebug()<<STROKA<<"stroka";
               MASS=1;

           }

         ui->table->append(line);
        }

          MainWindow::p_sred();
          MainWindow::obsh_sred();
          MainWindow::p_square();
          MainWindow::Robsh();
          MainWindow::Rf();
          MainWindow::Rost();
          MainWindow::Sf();
          MainWindow::Sost();
          MainWindow::Fnabl();
   file.close();
}

int k=0;
double d;
int i;
int j;
int h;

void MainWindow::razbor(QString s,int m)
{
    k=0;
    int A=1;
    QString str;
    QChar mass[100];

    for(int i=0;i<m;i++)
    {
        mass[i]=s[i];
    }
          if(mass[0].isDigit())
          {
              for( i=0;i<m;i++)
              {
               if(mass[i]==',')
               {
                   k++;
                   item= new QTableWidgetItem;
                   item->setText(str);
                   ui->tableWidget->setItem(STROKA,k,item);
                    //mass1[MASS]=str.toInt();
                   str="";
               }
               else
               {
               str=str+mass[i];
               }
              }
          }
          else
          {
              if(STROKA%9==0)
              {
                  //qDebug()<<str;
                  item= new QTableWidgetItem;
                  str=s;
                  item->setText(str);
                  ui->tableWidget->setItem(STROKA,k,item);
              }
           }
      STROKA++;
      MASS++;
      //qDebug()<<ui->tableWidget->item(12,2);
      //qDebug()<<MASS;
str="";
}

QString MainWindow::sdvig(QString s, int k,int b)
{
    return s;
}
int a=0;
void MainWindow::p_sred()
{

    int b=0;
    double n=0;
    //a=STROKA;

   for(int u=0;u<4;u++)
   {
     for(int v=1;v<=7;v++)
     {
         a++;
        b=b+ui->tableWidget->item(a,2)->text().toInt();

        //b=b+mass1[v];
     }
     n=(double)b/7;
     item= new QTableWidgetItem;
     item->setText(QString::number(n));
     ui->tableWidget->setItem(a+1,2,item);
     a=a+2;
     //a=0;
     b=0;
     n=0;
   }
   a=0;
   b=0;
   n=0;
   for(int u=0;u<4;u++)
   {
     for(int v=1;v<=7;v++)
     {
         a++;
        b=b+ui->tableWidget->item(a,3)->text().toInt();
     }
     n=(double)b/7;
     item= new QTableWidgetItem;
     item->setText(QString::number(n));
     ui->tableWidget->setItem(a+1,3,item);
     a=a+2;
     //a=0;
     b=0;
     n=0;
   }
}
void MainWindow ::obsh_sred()
{
    float a,b,c;
    float n;
    int y=8;
    for(int i=0;i<4;i++)
    {
       a=ui->tableWidget->item(y,2)->text().toFloat();
       qDebug()<<a;
       b=ui->tableWidget->item(y,3)->text().toFloat();
       c=a+b;
       n=(float)c/2;
       item= new QTableWidgetItem;
       item->setText(QString::number(n));
       ui->tableWidget->setItem(y,4,item);
       a=0;
       b=0;
       c=0;
       n=0;
       y=y+9;
    }
}
void MainWindow::p_square()
{
    int a=0;
    int b;
    for(int u=0;u<4;u++)
    {
      for(int v=1;v<=7;v++)
      {
          a++;
         b=ui->tableWidget->item(a,2)->text().toInt();
         b=b*b;
         item= new QTableWidgetItem;
         item->setText(QString::number(b));
         ui->tableWidget->setItem(a,5,item);
      }
      a=a+2;
      //a=0;
      b=0;
    }
    a=0;

    for(int u=0;u<4;u++)
    {
      for(int v=1;v<=7;v++)
      {
          a++;
         b=ui->tableWidget->item(a,3)->text().toInt();
         b=b*b;
         item= new QTableWidgetItem;
         item->setText(QString::number(b));
         ui->tableWidget->setItem(a,6,item);
      }
      a=a+2;
      //a=0;
      b=0;
    }
}

void MainWindow::Robsh()
{
    int b=0,z=0;
    float obshc,m;
    int a=0;
    int x=0;
    int y=8;
    for(int u=0;u<4;u++)
    {
      for(int v=1;v<=7;v++)
      {
          a++;
         b=b+ui->tableWidget->item(a,5)->text().toInt();
      }
      item= new QTableWidgetItem;
      item->setText(QString::number(b));
      ui->tableWidget->setItem(y,5,item);
      for(int v=1;v<=7;v++)
      {
          x++;
         z=z+ui->tableWidget->item(x,6)->text().toInt();
      }
      item= new QTableWidgetItem;
      item->setText(QString::number(z));
      ui->tableWidget->setItem(y,6,item);

      obshc=ui->tableWidget->item(y,4)->text().toFloat();

      item= new QTableWidgetItem;

      m=z+b-7*2*obshc*obshc;
      qDebug()<<m;
      item->setText(QString::number(m));
      ui->tableWidget->setItem(y,7,item);
      y=y+9;
      a=a+2;
      x=x+2;
      z=0;
      b=0;
    }
}
void MainWindow::Rf()
{
    float a,b,c;
    float n;
    int y=8;
    for(int i=0;i<4;i++)
    {
       a=ui->tableWidget->item(y,2)->text().toFloat();
       qDebug()<<a;
       b=ui->tableWidget->item(y,3)->text().toFloat();
       a=a*a;
       b=b*b;
       c=a+b;
       c=c*7;
       n=ui->tableWidget->item(y,4)->text().toFloat();
       c=c-2*n*n;
       item= new QTableWidgetItem;
       item->setText(QString::number(c));
       ui->tableWidget->setItem(y,8,item);
       a=0;
       b=0;
       c=0;
       n=0;
       y=y+9;
    }
}
void MainWindow::Rost()
{
    float b,a;
   float c;
   float obshc,m,z,n;
   int y=8,x=0;
    for(int i=0;i<4;i++)
    {
       a=ui->tableWidget->item(y,2)->text().toFloat();
       qDebug()<<a;
       b=ui->tableWidget->item(y,3)->text().toFloat();
       a=a*a;
       b=b*b;
       c=a+b;
       c=c*7;
       n=ui->tableWidget->item(y,4)->text().toFloat();
       c=c-2*n*n; //Rf

       for(int v=1;v<=7;v++)
       {
           j++;
          b=b+ui->tableWidget->item(j,5)->text().toInt();
       }
       item= new QTableWidgetItem;
       item->setText(QString::number(b));
       ui->tableWidget->setItem(y,5,item);
       for(int v=1;v<=7;v++)
       {
           x++;
          z=z+ui->tableWidget->item(x,6)->text().toInt();
       }
       item= new QTableWidgetItem;
       item->setText(QString::number(z));
       ui->tableWidget->setItem(y,6,item);

       obshc=ui->tableWidget->item(y,4)->text().toFloat();

       item= new QTableWidgetItem;

       m=z+b-7*2*obshc*obshc;//Robsch


       m=m-c;
       item= new QTableWidgetItem;
       item->setText(QString::number(m));
       ui->tableWidget->setItem(y,9,item);

       j=j+2;
       x=x+2;
       z=0;
       b=0;
       a=0;
       b=0;
       c=0;
       n=0;
       y=y+9;
       m=0;
    }
}
void MainWindow::Sf()
{
    float a,b,c;
    float n;
    int y=8;
    for(int i=0;i<4;i++)
    {
       a=ui->tableWidget->item(y,2)->text().toFloat();
       qDebug()<<a;
       b=ui->tableWidget->item(y,3)->text().toFloat();
       a=a*a;
       b=b*b;
       c=a+b;
       c=c*7;
       n=ui->tableWidget->item(y,4)->text().toFloat();
       c=c-2*n*n;
       c=c/6;
       item= new QTableWidgetItem;
       item->setText(QString::number(c));
       ui->tableWidget->setItem(y,10,item);
       a=0;
       b=0;
       c=0;
       n=0;
       y=y+9;
    }
}
void MainWindow::Sost()
{
    float b,a;
   float c;
   float m,z;
   int y=8,x=0;
    for(int i=0;i<4;i++)
    {
       m=ui->tableWidget->item(y,9)->text().toFloat();
       z=m/2*(7-1);
       item= new QTableWidgetItem;
       item->setText(QString::number(z));
       ui->tableWidget->setItem(y,11,item);

       y=y+9;
       m=0;
       z=0;
    }
}
void MainWindow::Fnabl()
{
    float m,c,z;
    int y=8;
    for(int i=0;i<4;i++)
    {
       m=ui->tableWidget->item(y,10)->text().toFloat();
       c=ui->tableWidget->item(y,11)->text().toFloat();
       z=m/c;
       item= new QTableWidgetItem;
       item->setText(QString::number(z));
       ui->tableWidget->setItem(y,12,item);

       y=y+9;
       m=0;
       z=0;
    }


}
