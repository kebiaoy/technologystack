#include <QApplication>
#include "MainWindow.h"
int main(int arc,char** argv)
{
	QApplication app(arc, argv);

	MainWindow w;
	w.show();

	app.exec();
	return 1;
}