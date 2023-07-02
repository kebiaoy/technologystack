#pragma once
#include <QString>
#include <memory>



class WLogger;

class WLogFormatter
{
public:
	WLogFormatter& operator<<(const int& nData);
	WLogFormatter& operator<<(const unsigned int& nData);
	WLogFormatter& operator<<(const char& nData);
	WLogFormatter& operator<<(const unsigned char& nData);
	WLogFormatter& operator<<(const short& nData);
	WLogFormatter& operator<<(const unsigned short& nData);
	WLogFormatter& operator<<(const long long& nData);
	WLogFormatter& operator<<(const unsigned long long& nData);
	WLogFormatter& operator<<(const QString& strData);
	const QString& Log();
private:
	QString m_strLog;
};

class WLog
{
public:
	enum LEVEL
	{
		NONE_LEVEL,
		TRACE_LEVEL,
		DEBUG_LEVEL,
		INFO_LEVEL,
		ERROR_LEVEL
	};
public:
	WLog& operator<<(WLogFormatter& formatter);
	void WriteLog(const QString& strData);
	void SetLogger(std::shared_ptr<WLogger> pLogger);
protected:
	virtual WLog::LEVEL Level() = 0;
private:
	std::shared_ptr<WLogger> m_pLogger = nullptr;
};

typedef std::shared_ptr<WLog> WLogPtr;


class WLogNone : public WLog
{

protected:
	WLog::LEVEL Level() override
	{
		return WLog::NONE_LEVEL;
	}
};

class WLogTrace : public WLog
{

protected:
	WLog::LEVEL Level() override
	{
		return WLog::TRACE_LEVEL;
	}
};


class WLogDebug : public WLog
{
protected:
	WLog::LEVEL Level() override
	{
		return WLog::DEBUG_LEVEL;
	}
};

class WLogInfo : public WLog
{
protected:
	WLog::LEVEL Level() override
	{
		return WLog::INFO_LEVEL;
	}
};

class WLogError : public WLog
{
protected:
	WLog::LEVEL Level() override
	{
		return WLog::ERROR_LEVEL;
	}
};


class WLogger
{
public:
	enum TYPE
	{
		SPDLOG_QT_QTEXTEDIT
	};
public:
	virtual void WriteLog(WLog::LEVEL nLevel, const QString& strData) = 0;
public:
	static std::shared_ptr<WLogger> CreateLogger(WLogger::TYPE nType);
};
typedef std::shared_ptr<WLogger> WLoggerPtr;

class WLogAble
{
public:
	WLogAble();
	static void SetLogLevel(WLog::LEVEL nLevel);
public:
	WLogTrace& LoggerTrace();
	WLogDebug& LoggerDebug();
	WLogInfo& LoggerInfo();
	WLogError& LoggerError();
	void SetLogger(WLoggerPtr pLogger);
private:
	WLogNone m_logNone;
	WLogTrace m_logTrace;
	WLogDebug m_logDebug;
	WLogInfo m_logInfo;
	WLogError m_logError;
};

