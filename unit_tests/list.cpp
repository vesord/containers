//
// Created by Mushroom Atrus on 11/11/20.
//

#include "gtest/gtest.h"
//#include "allocator.hpp"
#include "list.hpp"
#include <list>
#include <string>
#include <sstream>

class ListTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		for (int i = 0; i < 10; ++i)
			ftList.push_front(i);
		for (int i = 0; i < 10; ++i)
			stdList.push_front(i);
	}
//	virtual void TearDown();

	ft::list<int> ftList;
	std::list<int> stdList;
};

template <typename ftIter, typename stdIter>
void	listIteratorTest(ftIter & fIt, ftIter & fIte, ftIter & ftmpIt,
						 stdIter & sIt, stdIter & sIte, stdIter & stmpIt)
{
	EXPECT_EQ(*fIt, *sIt);
	++fIt;
	++sIt;
	EXPECT_EQ(*fIt, *sIt);
	ftmpIt = fIt++;
	stmpIt = sIt++;
	EXPECT_EQ(*fIt, *sIt);
	EXPECT_EQ(*stmpIt, *ftmpIt);

	for (int i = 0; i < 25; ++i)
	{
		--fIt;
		--sIt;
		if (sIt == sIte) {
			ASSERT_EQ(*fIt, *fIte);
			continue;
		}
		EXPECT_EQ(*fIt, *sIt);
	}
}

TEST_F(ListTest, forwardIterator) {
	ft::list<int>::iterator fIt = ftList.begin();
	ft::list<int>::iterator fIte(ftList.end());
	ft::list<int>::iterator ftmpIt;
	std::list<int>::iterator sIt = stdList.begin();
	std::list<int>::iterator sIte = stdList.end();
	std::list<int>::iterator stmpIt;
	listIteratorTest(fIt, fIte, ftmpIt, sIt, sIte, stmpIt);
}

TEST_F(ListTest, forwardIteratorConst) {
	ft::list<int>::const_iterator fIt = ftList.begin();
	ft::list<int>::const_iterator fIte(ftList.end());
	ft::list<int>::const_iterator ftmpIt;
	std::list<int>::const_iterator sIt = stdList.begin();
	std::list<int>::const_iterator sIte = stdList.end();
	std::list<int>::const_iterator stmpIt;
	listIteratorTest(fIt, fIte, ftmpIt, sIt, sIte, stmpIt);
}

TEST_F(ListTest, reverseIterator) {
	ft::list<int>::reverse_iterator fIt = ftList.rbegin();
	ft::list<int>::reverse_iterator fIte(ftList.rend());
	ft::list<int>::reverse_iterator ftmpIt;
	std::list<int>::reverse_iterator sIt = stdList.rbegin();
	std::list<int>::reverse_iterator sIte = stdList.rend();
	std::list<int>::reverse_iterator stmpIt;
	listIteratorTest(fIt, fIte, ftmpIt, sIt, sIte, stmpIt);
}

TEST_F(ListTest, reverseIteratorConst) {
	ft::list<int>::const_reverse_iterator fIt = ftList.rbegin();
	ft::list<int>::const_reverse_iterator fIte(ftList.rend());
	ft::list<int>::const_reverse_iterator ftmpIt;
	std::list<int>::const_reverse_iterator sIt = stdList.rbegin();
	std::list<int>::const_reverse_iterator sIte = stdList.rend();
	std::list<int>::const_reverse_iterator stmpIt;
	listIteratorTest(fIt, fIte, ftmpIt, sIt, sIte, stmpIt);
}