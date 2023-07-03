#include <QApplication>
#include "spdlog/spdlog.h"
#include "MainWindow.h"

int main(int argc, char** argv)
{
	WLogAble::SetLogLevel(WLog::TRACE_LEVEL);
	QApplication app(argc, argv);
	MainWindow w;
	w.show();

	return app.exec();
}