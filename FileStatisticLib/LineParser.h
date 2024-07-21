#pragma once
#include "LineCountStatistic.h"

class LineParser
{
public:
	LineCountStatistic get_line_count() { return m_line_count; }
	void ParseLine(std::wstring_view line);
private:
	LineCountStatistic m_line_count;
	bool m_is_multi_comment = false;
	bool m_is_in_text = false;

	bool m_has_code = false;
	bool m_has_comment = false;
};

