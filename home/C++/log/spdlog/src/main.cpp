#include <QApplication>
#include "spdlog/spdlog.h"
#include "MainWindow.h"

int main(int argc, char** argv)
{
	spdlog::set_level(spdlog::level::info);
	QApplication app(argc, argv);
	MainWindow w;
	w.show();

	return app.exec();
}