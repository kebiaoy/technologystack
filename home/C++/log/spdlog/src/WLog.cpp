#include "WLog.h"
#include "SpdWLogger.h"
static WLog::LEVEL g_Level = WLog::INFO_LEVEL;

WLogAble::WLogAble()
{
    SetLogger(WLogger::CreateLogger(WLogger::SPDLOG_QT_QTEXTEDIT));
}

void WLogAble::SetLogLevel(WLog::LEVEL nLevel)
{
    g_Level = nLevel;
}




WLogTrace& WLogAble::LoggerTrace()
{
    return m_logTrace;
}

WLogDebug& WLogAble::LoggerDebug()
{
    return m_logDebug;
}

WLogInfo& WLogAble::LoggerInfo()
{
    return m_logInfo;
}

WLogError& WLogAble::LoggerError()
{
    return m_logError;
}



void WLogAble::SetLogger(WLoggerPtr pLogger)
{
    m_logTrace.SetLogger(pLogger);
    m_logDebug.SetLogger(pLogger);
    m_logInfo.SetLogger(pLogger);
    m_logError.SetLogger(pLogger);
}

WLogFormatter& WLogFormatter::operator<<(const int& nData)
{
    m_strLog+=QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const unsigned int& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const char& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const unsigned char& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const short& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const unsigned short& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const long long& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const unsigned long long& nData)
{
    m_strLog += QString().setNum(nData);
    return *this;
}

WLogFormatter& WLogFormatter::operator<<(const QString& strData)
{
    m_strLog += strData;
   return *this;
}

const QString& WLogFormatter::Log()
{
    return m_strLog;
}

WLog& WLog::operator<<(WLogFormatter& formatter)
{
    WriteLog(formatter.Log());
    return *this;
}

void WLog::WriteLog(const QString& strData)
{
    if (Level() < g_Level)
    {
        return;
    }
    if (m_pLogger)
    {
        m_pLogger->WriteLog(Level(), strData);
    }
}

void WLog::SetLogger(std::shared_ptr<WLogger> pLogger)
{
    m_pLogger = pLogger;
}

std::shared_ptr<WLogger> WLogger::CreateLogger(WLogger::TYPE nType)
{
    switch (nType)
    {
    case WLogger::SPDLOG_QT_QTEXTEDIT:
    {
        static std::shared_ptr<SpdQtQTextEditWLogger> g_SpdQtQTextEditLogger = std::make_shared<SpdQtQTextEditWLogger>();
        return g_SpdQtQTextEditLogger;
    }
        break;
    default:
        break;
    }
    return std::shared_ptr<WLogger>();
}
