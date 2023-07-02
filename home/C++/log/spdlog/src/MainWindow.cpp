#include "MainWindow.h"
#include <QTextEdit>

MainWindow::MainWindow()
{

    setMinimumSize(640, 480);
    auto log_widget = new QTextEdit(this);
    setCentralWidget(log_widget);
    LoggerInfo() << (WLogFormatter() << "Some info message " << 12121);
}