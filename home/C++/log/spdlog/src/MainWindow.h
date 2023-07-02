#include <QMainWindow>
#include "WLog.h"

class MainWindow :public QMainWindow, public WLogAble
{
public:
	MainWindow();
};