#include "MainWindow.h"
#include <QTextEdit>

#include <QTimer>
MainWindow::MainWindow()
{

    setMinimumSize(640, 480);
    auto log_widget = new QTextEdit(this);
    setCentralWidget(log_widget);

    QTimer* pTimer = new QTimer(this);
    pTimer->setInterval(1000);
    connect(pTimer, &QTimer::timeout, this, [this]() {
        LoggerInfo() << (WLogFormatter() << "Some info message " << 12121);
        });
    pTimer->start();
   
}