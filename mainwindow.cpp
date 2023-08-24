#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QVector>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    morse = new Morse(this);

//    connect(this, &MainWindow::fromMorse, morse, &Morse::fromMorse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plainTextEdit_textChanged()
{
    ui->plainTextEdit_2->setPlainText(morsetranslator->autoTranslate(ui->plainTextEdit->toPlainText()));
}

void MainWindow::on_saveFile_triggered()
{
    QString path = QFileDialog::getSaveFileName(0,"Сохранить файл", "", "*.txt");
    qDebug() << path;
    if(!path.isEmpty()){
        QFile file(path);
        if(file.isOpen()){
            qDebug() << "Файл открыт";
            return;
        }
        file.open(QIODevice::WriteOnly);
        QString temp = ui->plainTextEdit_2->toPlainText();
        QByteArray text = temp.toUtf8();
        file.write(text);
        file.close();

    }
}


void MainWindow::on_loadFile_triggered()
{
    QString path = QFileDialog::getOpenFileName(0, "Открыть файл", "*.txt");
    qDebug() << path;
    if(!path.isEmpty()){
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray text = file.readAll();
        ui->plainTextEdit->setPlainText(text);
        file.close();
    }
}

