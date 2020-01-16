#include <fstream>
#include <stdint.h>

class CSVLogger
{
public:
	CSVLogger (const char* filename);
	~CSVLogger();

	template<class T>
	friend CSVLogger &operator<<(CSVLogger& CSV, const T val)
	{
		CSV.csvfile_ << val << ",";
		return CSV;
	}

	friend CSVLogger &operator<<(CSVLogger& CSV, const int8_t val)
	{
		CSV.csvfile_ << (int32_t)val << ",";
		return CSV;
	}

	friend CSVLogger &operator<<(CSVLogger& CSV, const uint8_t val)
	{
		CSV.csvfile_ << (uint32_t)val << ",";
		return CSV;
	}

	friend CSVLogger &operator<<(CSVLogger& CSV, const char* val)
	{
		CSV.csvfile_ << val << ",";
		return CSV;
	}

	template<typename T, std::size_t N>
	friend CSVLogger &operator<<(CSVLogger& CSV, const T(&array)[N])
	{
		for(std::size_t i = 0; i < N; ++i)
			CSV.csvfile_ << array[i] << ",";
		return CSV;
	}

	friend CSVLogger &operator<<(CSVLogger& CSV, std::ostream& (*os)(std::ostream&))
	{
		CSV.csvfile_ << os;
		return CSV;
	}

private:
	std::ofstream csvfile_;
    CSVLogger(const CSVLogger &);
    CSVLogger operator=(const CSVLogger &);
};
