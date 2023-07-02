#include <glog/logging.h>
#include <iostream>
#include <iomanip>

// 日志格式
void LogPreCallback(std::ostream& s, const google::LogMessageInfo& l, void* data)
{
	s << "[" << l.severity[0]
		<< std::setw(4) << 1900 + l.time.year()
		<< std::setw(2) << 1 + l.time.month()
		<< std::setw(2) << l.time.day()
		<< ' '
		<< std::setw(2) << l.time.hour() << ':'
		<< std::setw(2) << l.time.min() << ':'
		<< std::setw(2) << l.time.sec() << "."
		<< std::setw(6) << l.time.usec()
		<< ' '
		<< std::setfill(' ') << std::setw(5)
		<< l.thread_id << std::setfill('0')
		<< ' '
		<< l.filename << ':' << l.line_number << "]";
}

int main(int argc, char** argv)
{
	//FLAGS_logtostderr = true;
	google::EnableLogCleaner(3); // keep your logs for 3 days

	FLAGS_log_dir = "C:\\ykb\\workspace\\technologystack\\home\\C++\\log\\glog\\general\\bin\\debug";
	google::InitGoogleLogging(argv[0], LogPreCallback,"1");
	LOG(INFO) << "Stack consumption of symbolize signal handler: ";

	
	return 0;
}