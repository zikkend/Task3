#include "pch.h"
#include "LineParser.h"

void LineParser::ParseLine(std::wstring_view line)
{
	size_t line_len = line.length();

	if (line_len == 0)
	{
		m_line_count.blank_lines++;
		return;
	}

	for (size_t i = 0; i < line_len; i++)
	{
		// chekc if inside " "
		if (m_is_in_text)
		{
			if (line[i] == '"' && line[i - 1] != '\\')
			{
				m_is_in_text = false;
				continue;
			}
		}
		// check if it is last character
		else if (i == line_len - 1)
		{
			// chekc for /* */;
			if (!m_is_multi_comment)
			{
				m_has_code = true;
			}
			continue;
		}

		else if (m_is_multi_comment)
		{
			if (line[i] == '*' && line[i + 1] == '/')
			{
				i++;
				m_is_multi_comment = false;
			}
		}
		else if (line[i] == '/' && line[i + 1] == '/')
		{
			m_has_comment = true;
			break;
		}
		else if (line[i] == '/' && line[i + 1] == '*')
		{
			m_is_multi_comment = true;
			m_has_comment = true;
		}
		else
		{
			m_has_code = true;
			if (line[i] == '"')
			{
				m_is_in_text = true;
			}
		}
	}

	if (m_has_code)
		m_line_count.code_lines++;
	m_has_code = m_is_in_text;

	if (m_has_comment)
		m_line_count.comment_lines++;
	m_has_comment = m_is_multi_comment;
}
