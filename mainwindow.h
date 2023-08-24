#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "morsetranslator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

private slots:
    void on_plainTextEdit_textChanged();
    void on_saveFile_triggered();
    void on_loadFile_triggered();

private:
    Ui::MainWindow *ui;

    MorseTranslator *morsetranslator = new MorseTranslator();
};
#endif // MAINWINDOW_H
