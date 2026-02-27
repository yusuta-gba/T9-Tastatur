#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <queue>
#include <chrono>
#include <vector>
#include <QListWidget>
#include <QPoint>
#include <QMouseEvent>
#include <stdio.h>
//#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void setCode(int counter);
    void generateCode(char a);
    void decryptCode(int counter, bool visible, bool stop);
    void on_radioButton_clicked();
    void resetCounter();
    void saveTime(bool v1);
    void reset();
    void backupCounter();

    void ConvertButton1();
    void ConvertButton2();
    void ConvertButton3();
    void ConvertButton4();
    void ConvertButton5();
    void ConvertButton6();
    void ConvertButton7();
    void ConvertButton8();
    void ConvertButton9();

   // QTimer * timer;
    void on_listWidget_itemPressed(QListWidgetItem *item);

    void on_pushButton_11_clicked();

    void on_pushButton_17_clicked();


private:
    Ui::MainWindow *ui;
    std::queue<char> q1;
    std::string stringChain;
    std::string stringChainBackUp;
    std::string stringNumbers;
    std::string stringNumbersBackUp;
    std::string Password[4] = {"123456","z00Z2z3", "Z3z00z4Z", "0z4Z20zZ2" };
    std::vector<string>dynamicPassword;
    string password;
    QString pw;
    int row;
    long long startTime;
    vector<long long> entryTime;
    vector<long long> outTime;
    int counter = 0;
    int secondCounter;
    bool lowerCase = false;
    int seed = 1;
    bool clickedStart = false;
    bool generateStatic = true;

};
#endif // MAINWINDOW_H

