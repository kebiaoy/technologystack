#pragma once
#include "WLog.h"
#include <QFrame>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/qt_sinks.h"


class SpdWLogger :public QFrame, public WLogger
{
public:
	SpdWLogger(QWidget* parent = nullptr);
public:

	void WriteLog(WLog::LEVEL nLevel, const QString& strData) override;

protected:
	virtual std::shared_ptr<spdlog::logger> Logger() = 0;

};

class SpdQtQTextEditWLogger : public SpdWLogger
{
public:
	SpdQtQTextEditWLogger(QWidget* parent = nullptr);
protected:
	std::shared_ptr<spdlog::logger> Logger() override;
private:
	static std::shared_ptr<spdlog::logger> g_QtQTextEditLogger;
};