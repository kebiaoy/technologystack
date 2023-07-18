#include <QMainWindow>
#include "qcustomplot.h"

class MainWindow :public QMainWindow
{
public:
	MainWindow();
	void setupQuadraticDemo(QCustomPlot* customPlot);
private:
	QCPItemTracer* itemDemoPhaseTracer;
};