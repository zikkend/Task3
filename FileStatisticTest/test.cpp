#include "pch.h"
#include "../FileStatisticLib/LineCounter.h"

#include <string>

//const std::string ROOT_FOLDER = ".\\Test\\";
const std::string ROOT_FOLDER = "C:\\Users\\Admin\\Documents\\Visual Studio 2019\\Softserve Projects\\FileStatisticTest\\Test\\";

TEST(TestCointInFile, OrdinaryCase) {
	LineCounter lc;

	lc.CountLinesInFile(ROOT_FOLDER + "test1.cpp");

	LineCountStatistic statistic = lc.get_total_line_count();

	EXPECT_EQ(1, statistic.code_lines);
	EXPECT_EQ(2, statistic.blank_lines);
	EXPECT_EQ(3, statistic.comment_lines);
}

TEST(TestCointInFile, TestMultiLineComment) {
	LineCounter lc;

	lc.CountLinesInFile(ROOT_FOLDER + "test2.cpp");

	LineCountStatistic statistic = lc.get_total_line_count();

	EXPECT_EQ(1, statistic.code_lines);
	EXPECT_EQ(2, statistic.blank_lines);
	EXPECT_EQ(4, statistic.comment_lines);
}

TEST(TestCointInFile, TestLineAndCodeInOneLine) {
	LineCounter lc;

	lc.CountLinesInFile(ROOT_FOLDER + "test3.cpp");

	LineCountStatistic statistic = lc.get_total_line_count();

	EXPECT_EQ(4, statistic.code_lines);
	EXPECT_EQ(2, statistic.blank_lines);
	EXPECT_EQ(5, statistic.comment_lines);
}

TEST(TestCointInFile, TestString) {
	LineCounter lc;

	lc.CountLinesInFile(ROOT_FOLDER + "test4.cpp");

	LineCountStatistic statistic = lc.get_total_line_count();

	EXPECT_EQ(4, statistic.code_lines);
	EXPECT_EQ(2, statistic.blank_lines);
	EXPECT_EQ(4, statistic.comment_lines);
}

TEST(TestCointInFile, TestDoubleQuotesInString) {
	LineCounter lc;

	lc.CountLinesInFile(ROOT_FOLDER + "test5.cpp");

	LineCountStatistic statistic = lc.get_total_line_count();

	EXPECT_EQ(3, statistic.code_lines);
	EXPECT_EQ(2, statistic.blank_lines);
	EXPECT_EQ(2, statistic.comment_lines);
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}