#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCryptographicHash>
#include <QRandomGenerator>
#include <QByteArrayView>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()    // Klicken der Taste 1
{
    this->generateCode(ui->pushButton->text().at(0).toLatin1());

}
void MainWindow::backupCounter()        // Counter klonen
{
    this->secondCounter = this->counter;
}
void MainWindow::generateCode(char a)
{
    this->saveTime(true);
    this->q1.push(a);
    this->counter++;
    int localCounter=0;
    this->setCode(localCounter);
    this->saveTime(false);


}
void MainWindow::reset() // Zurücksetzung des Gesamtsystems bzw. der GUI-Objekte
{
    this->resetCounter();
    this->entryTime.clear();
    this->outTime.clear();
    ui->label_8->clear();
    ui->label_9->clear();
    ui->label_10->clear();
    ui->label_11->clear();
    ui->label_12->clear();
    ui->label_18->clear();
    ui->label_19->clear();
    ui->label_21->clear();
   // ui->label_22->clear();
    ui->textEdit->clear();
    ui->label_6->clear();
    this->stringNumbersBackUp = "";
}
void MainWindow::on_pushButton_14_clicked()
{
    this->reset();
}
void MainWindow::on_pushButton_13_clicked()
{
    /*
     *   Eingabelänge abfragen.
     *
     */
    if(this->clickedStart)
    {
                                                                        /*
                                                                         * Auswertung der Zeitdaten
                                                                         */
    this->backupCounter();
    for(int i = 1; i<=this->secondCounter; i++)
    {

        switch(i)
        {
        case 1:
            ui->label_8->setText(QString::number(this->entryTime[0] - this->startTime)); // 1 - 2 [1] - [0]
            break;
        case 2:
            ui->label_9->setText(QString::number(this->entryTime[1] - this->outTime[0])); // 2 - 3 [2] - [1]
            break;
        case 3:
            ui->label_10->setText(QString::number(this->entryTime[2] - this->outTime[1])); // 3 - 4 [3] - [2]
            break;
        case 4:
            ui->label_11->setText(QString::number(this->entryTime[3] - this->outTime[2]));// 4 - 5  [4] - [3]
            break;
        case 5:                                     //     [5] - [4]
            ui->label_12->setText(QString::number(this->entryTime[4] - this ->outTime[3]));   // 5 -6
            break;
        case 6:
            ui->label_18->setText(QString::number(this->entryTime[5] - this->outTime[4]));
            break;
        case 7:
            ui->label_19->setText(QString::number(this->entryTime[6] - this->outTime[5]));
            break;
        case 8:
            ui->label_21->setText(QString::number(this->entryTime[7] - this->outTime[6]));
            break;
        case 9:
            ui->label_20->setText(QString::number(this->entryTime[8] - this->outTime[7]));
            break;
            continue;
        }

    }
                                /*
                                 * Überprüfung der Passwörter
                                 */
    if(this->row <4)
    { int localCounter = 0;
    this->decryptCode(localCounter,false, true);
    int n1 = this->stringNumbersBackUp.length();
    int n2 = this->Password[this->row].length();
    int counter2 = 0;
    if(n1 != n2)
        return;
    for(int i = 0; i<n1; i++)
    {

        if(this->stringNumbersBackUp.at(i) == this->Password[this->row].at(i))  
            counter2++;

    }
    if(counter2 == n1 && counter2 == n2)
        ui->label_6->setText(QString::fromStdString("PASSWORD IS VALID"));
    else
        ui->label_6->setText(QString::fromStdString("PASSWORD IS NOT VALID"));
    }
    else
    {
        int localCounter = 0;
        this->decryptCode(localCounter,false, true);
        int n1 = this->stringNumbersBackUp.length();
        int n2 = this->dynamicPassword[this->row -4].length();
        int counter2 = 0;
        if(n1 != n2)
            return;
        for(int i = 0; i<n1; i++)
        {

            if(this->stringNumbersBackUp.at(i) == this->dynamicPassword[this->row-4].at(i))  
                counter2++;

        }
        if(counter2 == n1 && counter2 == n2)
            ui->label_6->setText(QString::fromStdString("PASSWORD IS VALID"));
        else
            ui->label_6->setText(QString::fromStdString("PASSWORD IS NOT VALID"));
    }
        }
    else
    {
        return;
    }
    this->clickedStart = false;
    return;
}

                                                        /*
                                                         *
                                                         *  Erstellung des Zeitstempels
                                                         */

void MainWindow::saveTime(bool v1)
{

    auto now = chrono::system_clock::now();

    // Convert the current time to time since epoch
    auto duration = now.time_since_epoch();

    // Convert duration to milliseconds
    auto milliseconds
        = chrono::duration_cast<chrono::milliseconds>(
              duration)
              .count();
    if(v1)
        this->entryTime.push_back(milliseconds);
    else
        this->outTime.push_back(milliseconds);
}
void MainWindow::on_pushButton_10_clicked()
{
    auto now = chrono::system_clock::now();

    // Convert the current time to time since epoch
    auto duration = now.time_since_epoch();

    // Convert duration to milliseconds

    this->startTime = chrono::duration_cast<chrono::milliseconds>(
              duration)
              .count();
    this->clickedStart = true;

   // ui->label->setText(QString::number(this->startTime));
}

void MainWindow::on_pushButton_2_clicked()  // Klicken Taste 2
{
    this->generateCode(ui->pushButton_2->text().at(0).toLatin1());
}


void MainWindow::on_pushButton_3_clicked()  // Klicken Taste 3
{

    this->generateCode(ui->pushButton_3->text().at(0).toLatin1());
}




void MainWindow::on_pushButton_4_clicked()    // Klicken Taste 4
{
    this->generateCode(ui->pushButton_4->text().at(0).toLatin1());
}




void MainWindow::on_pushButton_5_clicked()    // Klicken Taste 5
{
    this->generateCode(ui->pushButton_5->text().at(0).toLatin1());
}




void MainWindow::on_pushButton_6_clicked() // Klicken Taste 6
{
    this->generateCode(ui->pushButton_6->text().at(0).toLatin1());
}




void MainWindow::on_pushButton_7_clicked() // Klicken Taste 7
{
    this->generateCode(ui->pushButton_7->text().at(0).toLatin1());
}



void MainWindow::on_pushButton_8_clicked() // Klicken Taste 8
{
    this->generateCode(ui->pushButton_8->text().at(0).toLatin1());
}


void MainWindow::on_pushButton_9_clicked() // Klicken Taste 9
{
    this->generateCode(ui->pushButton_9->text().at(0).toLatin1());
}
void MainWindow::on_pushButton_15_clicked()
{
    this->generateCode('0');
}
void MainWindow::setCode(int c)            // Erzeugung des Unicodes
{

    if(c == this->counter)
    {
        ui->textEdit->setText(this->stringChain.c_str());
        this->stringChainBackUp.assign(this->stringChain);
        this->stringChain = "";
        return;
    }
    else{
        this->stringChain += "*";
        setCode(++c);

    }
    return;
    }

void MainWindow::decryptCode(int c, bool visible, bool stop)    // Ausgabe der eigentlichen Nutzdaten
{
    if(c == this->counter)
    {
        if(visible == true && stop == false)
        {    ui->textEdit->setText(this->stringNumbersBackUp.c_str());
            return;
        }
        else
            ui->textEdit->setText(this->stringChainBackUp.c_str());
        this->stringNumbersBackUp.assign(this->stringNumbers);
        this->stringNumbers = "";
        this->resetCounter();
        if(stop != true)
            decryptCode(0, visible = true, stop = false);
        return;
    }
    else
    {
        this->stringNumbers += this->q1.front();
        this->q1.pop();
        decryptCode(++c, visible = false, stop);
    }
}

void MainWindow::on_radioButton_clicked()        //Klicken des Radiobuttons
{
    int localCounter = 0;
    this->decryptCode(localCounter,true);
}

void MainWindow::resetCounter()            // Zurücksetzen des Systems
{
    this->counter = 0;
     ui->label_6->setText(QString::fromStdString(this->password));
}

void MainWindow::on_listWidget_itemPressed(QListWidgetItem *item)        // Hinzufügen eines Elements in die  Tabelle
{
    this->row = item->listWidget()->currentRow();
    ui->label_13->setText(QString::fromStdString(to_string(this->row)));
}

                                                // Umschaltung zwischen Kleinbuchstaben und Großbuchstaben.
void MainWindow::on_pushButton_11_clicked()
{





    if("A" ==ui->pushButton->text())
    {
        ui->pushButton->setText("a");
        this->lowerCase = true;
    }
    else if("a" == ui->pushButton->text())
    {
        ui->pushButton->setText("A");
        this->lowerCase = false;
    }

    if( "B" ==ui->pushButton->text())
    {
        ui->pushButton->setText("b");
        this->lowerCase = true;
    }
    else if("b" == ui->pushButton->text())
    {
        ui->pushButton->setText("B");
        this->lowerCase = false;
    }
    if("C" == ui->pushButton->text())
    {
        ui->pushButton->setText("c");
        this->lowerCase = true;

    }
    else if("c" == ui->pushButton->text())
    {
        ui->pushButton->setText("C");
        this->lowerCase = false;
    }



    /**********
                                                 *
                                                 *  Taste 2
                                                 *********/
    if("D" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("d");
    }
    else if ("d" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("D");
    }
    if("E" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("e");
    }
    else if("e" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("E");
    }
    if("F" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("f");
    }
    else if("f" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("F");
    }





    /**
                                             *
                                             *  Taste 3
                                             *
                                             * ***/
    if("G" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("g");
    }
    else if("g" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("G");
    }
    if("H" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("h");
    }
    else if ("h" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("H");
    }
    if("I" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("i");
    }
    else if("i" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("I");
    }

    /**
                                             *
                                             *  Taste 4
                                             * */

    if("J" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("j");
    }
    else if("j" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("J");
    }
    if("K" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("k");
    }
    else if("k" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("K");
    }
    if("L" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("l");
    }
    else if("l" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("L");
    }


    /**
                                             *
                                             * Tastatur 5
                                             * **/
    if("M" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("m");
    }
    else if("m" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("M");
    }
    if("N" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("n");
    }
    else if("n" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("N");
    }
    if("O" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("o");
    }
    else if("o" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("O");
    }
    /**
                                                 *
                                                 *  Taste 6
                                                 * **/

    if("P" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("p");
    }
    else if("p" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("P");
    }
    if("Q" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("q");
    }
    else if("q" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("Q");
    }
    if("R" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("r");
    }
    else if("r" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("R");
    }

    /**
                                                                 *
                                                                 *  TASTE 7
                                                                 * **/
    if("S" == ui->pushButton_7->text())
    {
        ui->pushButton_7->setText("s");
    }
    else if("s" == ui->pushButton_7->text())
    {
        ui->pushButton_7->setText("S");
    }
    if("T" == ui->pushButton_7->text())
    {
        ui->pushButton_7->setText("t");
    }
    else if("t" == ui->pushButton_7->text())
    {
        ui->pushButton_7->setText("T");
    }
    if("U" == ui->pushButton_7->text())
    {
        ui->pushButton_7->setText("u");
    }
    else if("u" == ui->pushButton_7->text())
    {
        ui->pushButton_7->setText("U");
    }

    /***
                                                 *
                                                 *  Taste 8
                                                 * **/
    if("W" == ui->pushButton_8->text())
    {
        ui->pushButton_8->setText("w");
    }
    else if("w" == ui->pushButton_8->text())
    {
        ui->pushButton_8->setText("W");
    }
    if("V" == ui->pushButton_8->text())
    {
        ui->pushButton_8->setText("v");
    }
    else if("v" == ui->pushButton_8->text())
    {
        ui->pushButton_8->setText("V");
    }
    if("X" == ui->pushButton_8->text())
    {
        ui->pushButton_8->setText("x");
    }
    else if("x" == ui->pushButton_8->text())
    {
        ui->pushButton_8->setText("X");
    }
    /**
                                             *
                                             * Taste 9
                                             * */

    if("Y" == ui->pushButton_9->text())
    {
        ui->pushButton_9->setText("y");
    }
    else if("y" == ui->pushButton_9->text())
    {
        ui->pushButton_9->setText("Y");
    }
    if("Z" == ui->pushButton_9->text())
    {
        ui->pushButton_9->setText("z");
    }
    else if("z" == ui->pushButton_9->text())
    {
        ui->pushButton_9->setText("Z");
    }

    if(this->lowerCase)
    {
        ui->pushButton_16->setEnabled(false);
    }
    else
    {
        ui->pushButton_16->setEnabled(true);
    }

}



                                                    /**************
                                                     * TASTE 1 - Umschaltung des Tastenfelds
                                                     */




void MainWindow::ConvertButton1()
{
    if( "1" == ui->pushButton->text())
    {
        ui->pushButton->setText("A");
        return;
    }
    if( "A" == ui->pushButton->text())
    {
        ui->pushButton->setText("B");
        return;
    }
    if( "B" == ui->pushButton->text())
    {
        ui->pushButton->setText("C");
        return;
    }
    if( "C" == ui->pushButton->text())
    {
        ui->pushButton->setText("1");
        return;
    }
}
                                    /*
                                    * TASTE 2 - Umschaltung des Tastenfelds
                                    */

void MainWindow::ConvertButton2()
{
    if( "2" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("D");
        return;
    }
    if( "D" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("E");
        return;
    }
    if( "E" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("F");
        return;
    }
    if( "F" == ui->pushButton_2->text())
    {
        ui->pushButton_2->setText("2");
        return;
    }

}
                                     /*
                                      * TASTE 3 - Umschaltung des Tastenfelds
                                      */

void MainWindow::ConvertButton3()
{
    if( "3" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("G");
        return;
    }
    if( "G" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("H");
        return;
    }
    if( "H" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("I");
        return;
    }
    if( "I" == ui->pushButton_3->text())
    {
        ui->pushButton_3->setText("3");
        return;
    }
}
                                     /*
                                      * TASTE 4 - Umschaltung des Tastenfelds
                                      */
void MainWindow::ConvertButton4()
{
    if( "4" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("J");
        return;
    }
    if( "J" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("K");
        return;
    }
    if( "K" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("L");
        return;
    }
    if( "L" == ui->pushButton_4->text())
    {
        ui->pushButton_4->setText("4");
        return;
    }
}
                                     /*
                                      * TASTE 5 - Umschaltung des Tastenfelds
                                      */
void MainWindow::ConvertButton5()
{
    if( "5" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("M");
        return;
    }
    if( "M" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("N");
        return;
    }
    if( "N" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("O");
        return;
    }
    if( "O" == ui->pushButton_5->text())
    {
        ui->pushButton_5->setText("5");
        return;
    }
}                                    /*
                                      * TASTE 6 - Umschaltung des Tastenfelds
                                      */
void MainWindow::ConvertButton6()
{
    if( "6" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("P");
        return;
    }
    if( "P" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("Q");
        return;
    }
    if( "Q" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("R");
        return;
    }
    if( "R" == ui->pushButton_6->text())
    {
        ui->pushButton_6->setText("6");
        return;
    }
}
                                     /*
                                      * TASTE 7 - Umschaltung des Tastenfelds
                                      */
void MainWindow::ConvertButton7()
{


        if( "7" == ui->pushButton_7->text())
        {
            ui->pushButton_7->setText("S");
            return;
        }
        if( "S" == ui->pushButton_7->text())
        {
            ui->pushButton_7->setText("T");
            return;
        }
        if( "T" == ui->pushButton_7->text())
        {
            ui->pushButton_7->setText("U");
            return;
        }
        if( "U" == ui->pushButton_7->text())
        {
            ui->pushButton_7->setText("7");
            return;
        }

}
                             /*
                              * TASTE 8 - Umschaltung des Tastenfelds
                              */
void MainWindow::ConvertButton8()
{

        if( "8" == ui->pushButton_8->text())
        {
            ui->pushButton_8->setText("W");
            return;
        }
        if( "W" == ui->pushButton_8->text())
        {
            ui->pushButton_8->setText("V");
            return;
        }
        if( "V" == ui->pushButton_8->text())
        {
            ui->pushButton_8->setText("X");
            return;
        }
        if( "X" == ui->pushButton_8->text())
        {
            ui->pushButton_8->setText("8");
            return;
        }

}
                                     /*
                                      * TASTE 9 - Umschaltung des Tastenfelds
                                      */
void MainWindow::ConvertButton9()
{

        if( "9" == ui->pushButton_9->text())
        {
            ui->pushButton_9->setText("Y");
            return;
        }
        if( "Y" == ui->pushButton_9->text())
        {
            ui->pushButton_9->setText("Z");
            return;
        }
        if( "Z" == ui->pushButton_9->text())
        {
            ui->pushButton_9->setText(" ");
            return;
        }
        if( " " == ui->pushButton_9->text())
        {
            ui->pushButton_9->setText("9");
            return;
        }


}
                            // Ausführung der Umschaltung
void MainWindow::on_pushButton_16_clicked()
{

    this->ConvertButton1();
    this->ConvertButton2();
    this->ConvertButton3();
    this->ConvertButton4();
    this->ConvertButton5();
    this->ConvertButton6();
    this->ConvertButton7();
    this->ConvertButton8();
    this->ConvertButton9();

}

    /*
    * Generierung eines dynamischen Passworts
    */
void MainWindow::on_pushButton_17_clicked()
{
    this->clickedStart = true;
    if(this->generateStatic == true)
    {  
        /*
         * Statische Passwörter
         */
        ui->listWidget->addItem(QString::fromStdString(this->Password[0]));
        ui->listWidget->addItem(QString::fromStdString(this->Password[1]));
        ui->listWidget->addItem(QString::fromStdString(this->Password[2]));
        ui->listWidget->addItem(QString::fromStdString(this->Password[3]));
        this->generateStatic = false;
    }
    /*
     * Erzeugung von Pseudozufallszahlen, dieser als Message-parameter der Md5-Funktion übergeben wird.
     */
    QCryptographicHash * MD5 = new QCryptographicHash(QCryptographicHash::Md5);
    QRandomGenerator64 * PRNG = new QRandomGenerator64(this->seed);
    QByteArray * data = new QByteArray();
    QByteArray * output = new QByteArray();
    int x = PRNG->generate();
    QString tmp  = QString::number(x);

    QString tmp3 = QString(QCryptographicHash::hash((tmp.toStdString()),QCryptographicHash::Md5).toHex());
    string passwords = tmp3.toStdString();
    string wordLen;
    for(int i = 0; i<2; i++)    // Erstellung zwei Passwörter mit der Länge 9
    {
        for(int j = 9 * i; j< 9 * i + 9; j++)
        {
            wordLen += passwords.at(j);
        }
        ui->listWidget->addItem(QString::fromStdString(wordLen));
        this->dynamicPassword.push_back(wordLen);
        wordLen.clear();
    }
    this->seed = this->seed +1;
}









