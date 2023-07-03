#include "SpdWLogger.h"
#include <QVBoxLayout>
#include <QTextEdit>
#include "spdlog/sinks/daily_file_sink.h"
#include <QApplication>

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

void SpdWLogger::SetLogLevel(WLog::LEVEL nLevel)
{
	switch (nLevel)
	{
	case WLog::LEVEL::TRACE_LEVEL:
		spdlog::set_level(spdlog::level::trace);
		break;
	case WLog::DEBUG_LEVEL:
		spdlog::set_level(spdlog::level::debug);
		break;
	case WLog::LEVEL::INFO_LEVEL:
		spdlog::set_level(spdlog::level::info);
		break;
	case WLog::LEVEL::ERROR_LEVEL:
		spdlog::set_level(spdlog::level::err);
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

std::shared_ptr<spdlog::logger> SpdDailyWLogger::g_DailyLogger = nullptr;

SpdDailyWLogger::SpdDailyWLogger()
{
	auto logfilePath = QApplication::applicationDirPath() + "/logs/daily.txt";
	g_DailyLogger = spdlog::daily_logger_mt("daily_logger", logfilePath.toStdString(), 0, 0, false, 3);
	g_DailyLogger->flush_on(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger> SpdDailyWLogger::Logger()
{
	return g_DailyLogger;
}
