#include <cmath>

#include "graphingcalculator.h"

void GraphingCalculator::resetCalculator()
{
    number1 = 0;
    operation = '=';
    buffer = "0";
    dot = false;
    sign = '+';
    number2 = number1;
}

void GraphingCalculator::slotC()
{
    resetCalculator();
    printBuffer();
}

void GraphingCalculator::printBuffer()
{
    lineEdit->setText(buffer);
}

void GraphingCalculator::readText()
{
    number1 = (lineEdit->text()).toDouble(&ok);
    if(!ok) {
        resetCalculator();
        err();
    } else {
        buffer = "0";
        dot = false;
        sign = '+';
        number2 = number1;
    }
}

void GraphingCalculator::printResult(double number)
{
    //lineEdit->setText(QString::number(number));
    lineEdit->setText(QString("%1").arg(number, 0, 'g', 16));
}

void GraphingCalculator::addDigit(char digit)
{
    if(digit != 'S') {
        if(buffer == "0" && digit != '.') {
            buffer.clear();
        }
        if(buffer.size() < 16 + dot) {
            buffer += digit;
        }
    }
        if(sign == '-') {
            bufferTemp = sign + buffer;
        } else {
            bufferTemp = buffer;
        }
        number1 = bufferTemp.toDouble(&ok);
        if(!ok) {
            resetCalculator();
            err();
        } else {
            lineEdit->setText(bufferTemp);
        }
}

void GraphingCalculator::err()
{
    lineEdit->setText("ERROR");
}

void GraphingCalculator::slotDot()
{
    if(!dot) {
        dot = true;
        addDigit('.');
    }
}

void GraphingCalculator::slot0()
{
    //if(buffer != "0") {
        addDigit('0');
    //}
}

void GraphingCalculator::slot1()
{
    addDigit('1');
}

void GraphingCalculator::slot2()
{
    addDigit('2');
}

void GraphingCalculator::slot3()
{
    addDigit('3');
}

void GraphingCalculator::slot4()
{
    addDigit('4');
}

void GraphingCalculator::slot5()
{
    addDigit('5');
}

void GraphingCalculator::slot6()
{
    addDigit('6');
}

void GraphingCalculator::slot7()
{
    addDigit('7');
}

void GraphingCalculator::slot8()
{
    addDigit('8');
}

void GraphingCalculator::slot9()
{
    addDigit('9');
}

void GraphingCalculator::slotSign()
{
    if(buffer != "0" && sign == '+') {
        sign = '-';
    } else {
        sign = '+';
    }
    addDigit('S');
}

void GraphingCalculator::slot1X()
{
    operation = 'X';
    if(number1 == 0) {
        resetCalculator();
        err();
    } else {
        number1 = 1 / number1;
        printResult(number1);
        buffer = lineEdit->text();
        number2 = 0;
    }
}

void GraphingCalculator::slotAdd()
{
    operation = '+';
    readText();
}

void GraphingCalculator::slotSub()
{
    operation = '-';
    readText();
}

void GraphingCalculator::slotMultiply()
{
    operation = '*';
    readText();
}

void GraphingCalculator::slotDiv()
{
    operation = '/';
    readText();
}

void GraphingCalculator::slotSquare()
{
    operation = 'V';
    if(number1 < 0) {
        resetCalculator();
        err();
    } else {
        number1 = sqrt(number1);
        printResult(number1);
        buffer = lineEdit->text();
        number2 = 0;
    }
}

void GraphingCalculator::slotEquals()
{
    buffer = "0";
    switch (operation)
    {
        case '=':
            resetCalculator();
            break;
        case '+':
            number2 = number2 + number1;
            printResult(number2);
            break;
        case '-':
            number2 = number2 - number1;
            printResult(number2);
            break;
        case '*':
            number2 = number2 * number1;
            printResult(number2);
            break;
        case '/':
            number2 = number2 / number1;
            printResult(number2);
            break;
        case 'V':
            break;
        case 'X':
            break;
    }
}
