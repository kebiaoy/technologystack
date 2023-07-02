#include "MainWindow.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/qt_sinks.h"

MainWindow::MainWindow()
{
    setMinimumSize(640, 480);
    auto log_widget = new QTextEdit(this);
    setCentralWidget(log_widget);
    int max_lines = 500; // keep the text widget to max 500 lines. remove old lines if needed.
    auto logger = spdlog::qt_color_logger_mt("qt_logger", log_widget, max_lines);
    logger->info("Some info message");
}