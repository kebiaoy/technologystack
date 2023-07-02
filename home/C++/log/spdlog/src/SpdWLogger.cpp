#include "SpdWLogger.h"
#include <QVBoxLayout>
#include <QTextEdit>

std::shared_ptr<spdlog::logger> SpdQtQTextEditWLogger::g_QtQTextEditLogger = nullptr;

SpdWLogger::SpdWLogger(QWidget* parent) 
	: QFrame(parent)
{
	
}

void SpdWLogger::WriteLog(WLog::LEVEL nLevel, const QString& strData)
{
	switch (nLevel)
	{
	case WLog::LEVEL::TRACE_LEVEL:
		Logger()->trace(strData.toStdString().data());
		break;
	case WLog::DEBUG_LEVEL:
		Logger()->debug(strData.toStdString().data());
		break;
	case WLog::LEVEL::INFO_LEVEL:
		Logger()->info(strData.toStdString().data());
		break;
	case WLog::LEVEL::ERROR_LEVEL:
		Logger()->error(strData.toStdString().data());
		break;
	default:
		break;
	}
}

SpdQtQTextEditWLogger::SpdQtQTextEditWLogger(QWidget* parent) 
	: SpdWLogger(parent)
{
	QVBoxLayout* pLayout = new QVBoxLayout;
	setLayout(pLayout);

	QTextEdit* pEdit = new QTextEdit;
	pLayout->addWidget(pEdit);

	int max_lines = 500; // keep the text widget to max 500 lines. remove old lines if needed.
	g_QtQTextEditLogger = spdlog::qt_color_logger_mt("qt_logger", pEdit, max_lines);
	show();
}

std::shared_ptr<spdlog::logger> SpdQtQTextEditWLogger::Logger()
{
	return g_QtQTextEditLogger;
}
