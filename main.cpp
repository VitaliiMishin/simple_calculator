#include <QApplication>
#include "./ui_graphingcalculator.h"
#include "graphingcalculator.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GraphingCalculator window(nullptr);
    Ui::GraphingCalculator GraphingCalculator;
    GraphingCalculator.setupUi(&window);
    window.lineEdit = GraphingCalculator.lineEdit;
    window.resize(320, 300);
    window.slotC();
    window.setWindowTitle("Calculator");
    window.show();
    return QApplication::exec();
}
