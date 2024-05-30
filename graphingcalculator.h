#ifndef GRAPHINGCALCULATOR_GRAPHINGCALCULATOR_H
#define GRAPHINGCALCULATOR_GRAPHINGCALCULATOR_H

#include <QMainWindow>
#include <QLineEdit>

class GraphingCalculator : public QMainWindow
{
    Q_OBJECT
public:

    GraphingCalculator(QWidget* parent = nullptr): QMainWindow(parent) {}
    QLineEdit *lineEdit = nullptr;

public slots:

    void slot0();
    void slot1();
    void slot2();
    void slot3();
    void slot4();
    void slot5();
    void slot6();
    void slot7();
    void slot8();
    void slot9();
    void slotC();
    void slot1X();
    void slotDiv();
    void slotAdd();
    void slotSign();
    void slotDot();
    void slotEquals();
    void slotSquare();
    void slotSub();
    void slotMultiply();

private:

    QString buffer = "0";
    QString bufferTemp = "";
    void printBuffer();
    void readText();
    void printResult(double number);
    void addDigit(char digit);
    void resetCalculator();
    void err();
    bool dot = false;
    bool ok = true;
    double number1 = 0;
    double number2 = 0;
    char sign = '+';
    char operation = '=';
};

#endif //GRAPHINGCALCULATOR_GRAPHINGCALCULATOR_H
