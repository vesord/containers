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

template <typename itFt, typename itFtEnd, typename itStd, typename itStdEnd>
void checkListEqual(itFt itF, itFtEnd itFe, itStd itS, itStdEnd itSe, size_t size = 25) {
	for (size_t i = 0; i < size; ++i)
	{
		--itF; --itS;
		if (itS == itSe) {
			ASSERT_EQ(itF, itFe);
			continue;
		}
		EXPECT_EQ(*itF, *itS);
	}
	for (size_t i = 0; i < size; ++i)
	{
		++itF; ++itS;
		if (itS == itSe) {
			ASSERT_EQ(itF, itFe);
			continue;
		}
		EXPECT_EQ(*itF, *itS);
	}
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

	checkListEqual(fIt, fIte, sIt, sIte);
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

TEST_F(ListTest, creationAssignationIterators)
{
	ft::list<int>::iterator					It1 = ftList.begin();
	ft::list<int>::iterator					It2;
	ft::list<int>::const_iterator			It1const = ftList.begin();
	ft::list<int>::const_iterator			It2const;
	ft::list<int>::reverse_iterator			It1rev = ftList.rbegin();
	ft::list<int>::reverse_iterator			It2rev;
	ft::list<int>::const_reverse_iterator	It1revConst = ftList.rbegin();
	ft::list<int>::const_reverse_iterator	It2revConst;

//	It1 = It1const; // should not work
	It1const = It1;
	EXPECT_EQ(It1const, It1);
	EXPECT_EQ(It1, It1const);
	It2const = It1const;
	EXPECT_EQ(It2const, It1const);
	EXPECT_EQ(It1const, It2const);
//	It1rev = It1revConst; // should not work
	It1revConst = It1rev;
	EXPECT_EQ(It1rev, It1revConst);
	EXPECT_EQ(It1revConst, It1rev);
	It2revConst = It1revConst;
	EXPECT_EQ(It1revConst, It2revConst);
	EXPECT_EQ(It2revConst, It1revConst);
}

TEST_F(ListTest, creationAssignationIteratorsStd)
{
	std::list<int>::iterator					It1 = stdList.begin();
	std::list<int>::iterator					It2;
	std::list<int>::const_iterator			It1const = stdList.begin();
	std::list<int>::const_iterator			It2const;
	std::list<int>::reverse_iterator			It1rev = stdList.rbegin();
	std::list<int>::reverse_iterator			It2rev;
	std::list<int>::const_reverse_iterator	It1revConst = stdList.rbegin();
	std::list<int>::const_reverse_iterator	It2revConst;

//	It1 = It1const; // should not work
	It1const = It1;
	EXPECT_EQ(It1const, It1);
	EXPECT_EQ(It1, It1const);
	It2const = It1const;
	EXPECT_EQ(It2const, It1const);
	EXPECT_EQ(It1const, It2const);
//	It1rev = It1revConst; // should not work
	It1revConst = It1rev;
	EXPECT_EQ(It1rev, It1revConst);
	EXPECT_EQ(It1revConst, It1rev);
	It2revConst = It1revConst;
	EXPECT_EQ(It1revConst, It2revConst);
	EXPECT_EQ(It2revConst, It1revConst);
}

TEST_F(ListTest, pushFront) {
	ft::list<int> f;
	std::list<int> s;

	ft::list<int>::iterator itF;
	ft::list<int>::iterator itFe = f.end();
	std::list<int>::iterator itS;
	std::list<int>::iterator itSe = s.end();

	f.push_front(42);
	s.push_front(42);
	itF = f.begin();
	itS = s.begin();
	EXPECT_EQ(*itS, *itF);
	++itF;
	++itS;
	EXPECT_EQ(itF, itFe);
	EXPECT_EQ(itS, itSe);
	++itF;
	++itS;
	EXPECT_EQ(itF, f.begin());
	EXPECT_EQ(itS, s.begin());
	EXPECT_EQ(*itF, *itS);
	EXPECT_EQ(*itF, 42);
	EXPECT_EQ(*itS, 42);
	f.push_front(21); s.push_front(21);
	--itS; --itF;
	EXPECT_EQ(itF, f.begin());
	EXPECT_EQ(itS, s.begin());
	EXPECT_EQ(*itS, 21);
	--itS; --itF;
	EXPECT_EQ(itF, itFe);
	EXPECT_EQ(itS, itSe);
	--itS; --itF;
	EXPECT_EQ(*itF, *itS);
	EXPECT_EQ(*itF, 42);
}

TEST_F(ListTest, pushBack) {
	ft::list<int> f;
	std::list<int> s;

	ft::list<int>::iterator itF;
	ft::list<int>::iterator itFe = f.end();
	std::list<int>::iterator itS;
	std::list<int>::iterator itSe = s.end();

	f.push_back(42);
	s.push_back(42);
	itF = f.begin();
	itS = s.begin();
	EXPECT_EQ(*itS, *itF);
	++itF;
	++itS;
	EXPECT_EQ(itF, itFe);
	EXPECT_EQ(itS, itSe);
	++itF;
	++itS;
	EXPECT_EQ(itF, f.begin());
	EXPECT_EQ(itS, s.begin());
	EXPECT_EQ(*itF, *itS);
	EXPECT_EQ(*itF, 42);
	EXPECT_EQ(*itS, 42);
	f.push_back(21); s.push_back(21);
	EXPECT_EQ(itF, f.begin());
	EXPECT_EQ(itS, s.begin());
	++itS; ++itF;
	EXPECT_EQ(*itF, 21);
	EXPECT_EQ(*itS, 21);
	++itS; ++itF;
	EXPECT_EQ(itF, itFe);
	EXPECT_EQ(itS, itSe);
	++itS; ++itF;
	EXPECT_EQ(*itF, *itS);
	EXPECT_EQ(*itF, 42);
}

TEST_F(ListTest, assignationOperator) {
	ft::list<int> f;
	std::list<int> s;

	ft::list<int>::iterator itF;
	ft::list<int>::iterator itFe;
	std::list<int>::iterator itS;
	std::list<int>::iterator itSe;

	f = ftList; s = stdList;
	itFe = f.end(); itSe = s.end();
	itF = f.begin(); itS = s.begin();
	checkListEqual(itF, itFe, itS, itSe);
	ft::list<int> f1;
	std::list<int> s1;
	f = f1; s = s1;
	itFe = f.end(); itSe = s.end();
	itF = f.begin(); itS = s.begin();
	checkListEqual(itF, itFe, itS, itSe);
	for (int i = 0; i < 15; ++i) {
		f1.push_back(i - 8);
		s1.push_back(i - 8);
	}
	itFe = f.end(); itSe = s.end();
	itF = f.begin(); itS = s.begin();
	checkListEqual(itF, itFe, itS, itSe);
	f = f1; s = s1;
	itFe = f.end(); itSe = s.end();
	itF = f.begin(); itS = s.begin();
	checkListEqual(itF, itFe, itS, itSe);
}

TEST_F(ListTest, clear) {
	ftList.clear();
	stdList.clear();

	ft::list<int>::iterator itF = ftList.begin();
	ft::list<int>::iterator itFe = ftList.end();
	std::list<int>::iterator itS = stdList.begin();
	std::list<int>::iterator itSe = stdList.end();

	for (size_t i = 0; i < 10; ++i) {
		EXPECT_EQ(itF, itFe);
		EXPECT_EQ(itS, itSe);
		++itF; ++itS;
	}
	ftList.clear();
	stdList.clear();
	for (size_t i = 0; i < 10; ++i) {
		EXPECT_EQ(itF, itFe);
		EXPECT_EQ(itS, itSe);
		++itF; ++itS;
	}
	for (int i = 0; i < 15; ++i) {
		ftList.push_back(i - 8);
		stdList.push_back(i - 8);
	}
	itF = ftList.begin(); itFe = ftList.end();
	itS = stdList.begin(); itSe = stdList.end();
	checkListEqual(itF, itFe, itS, itSe);
	ftList.clear();
	stdList.clear();
	itF = ftList.begin(); itFe = ftList.end();
	itS = stdList.begin(); itSe = stdList.end();
	for (size_t i = 0; i < 10; ++i) {
		EXPECT_EQ(itF, itFe);
		EXPECT_EQ(itS, itSe);
		++itF; ++itS;
	}
}

TEST_F(ListTest, defaultConstruction) {
	ft::list<int> f;
	std::list<int> s;

	ft::list<int>::iterator itF = f.begin();
	ft::list<int>::iterator itFe = f.end();
	std::list<int>::iterator itS = s.begin();
	std::list<int>::iterator itSe = s.end();

	EXPECT_EQ(itS, itSe);
	EXPECT_EQ(itF, itFe);
}

TEST_F(ListTest, copyConstruction) {
	ft::list<int> f = ftList;
	std::list<int> s = stdList;

	ft::list<int>::iterator itF = f.begin();
	ft::list<int>::iterator itFe = f.end();
	std::list<int>::iterator itS = s.begin();
	std::list<int>::iterator itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	ft::list<int> f1(f);
	std::list<int> s1(s);

	itF = f1.begin();
	itFe = f1.end();
	itS = s1.begin();
	itSe = s1.end();
	checkListEqual(itF, itFe, itS, itSe);
}

TEST_F(ListTest, accessFront) {
	EXPECT_EQ(ftList.front(), stdList.front());
	ftList.push_front(42);
	stdList.push_front(42);
	EXPECT_EQ(ftList.front(), stdList.front());
	EXPECT_EQ(42, stdList.front());
	EXPECT_EQ(ftList.front(), 42);

	ftList.push_back(-42);
	stdList.push_back(-42);
	EXPECT_EQ(ftList.front(), stdList.front());
	EXPECT_EQ(42, stdList.front());
	EXPECT_EQ(ftList.front(), 42);

	ftList.push_front(21);
	stdList.push_front(21);
	EXPECT_EQ(ftList.front(), stdList.front());
	EXPECT_EQ(21, stdList.front());
	EXPECT_EQ(ftList.front(), 21);
}

TEST_F(ListTest, accessBack) {
	EXPECT_EQ(ftList.back(), stdList.back());
	ftList.push_back(42);
	stdList.push_back(42);
	EXPECT_EQ(ftList.back(), stdList.back());
	EXPECT_EQ(42, stdList.back());
	EXPECT_EQ(ftList.back(), 42);

	ftList.push_front(-42);
	stdList.push_front(-42);
	EXPECT_EQ(ftList.back(), stdList.back());
	EXPECT_EQ(42, stdList.back());
	EXPECT_EQ(ftList.back(), 42);

	ftList.push_back(21);
	stdList.push_back(21);
	EXPECT_EQ(ftList.back(), stdList.back());
	EXPECT_EQ(21, stdList.back());
	EXPECT_EQ(ftList.back(), 21);
}

TEST_F(ListTest, popBack) {
	ft::list<int> f;
	std::list<int> s;
	ft::list<int>::iterator itF;
	ft::list<int>::iterator itFe;
	std::list<int>::iterator itS;
	std::list<int>::iterator itSe;

	f.push_back(42); s.push_back(42);
	f.push_back(21); s.push_back(21);

	f.pop_back(); s.pop_back();
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.push_front(1); s.push_front(1);
	f.push_front(2); s.push_front(2);

	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.pop_back(); s.pop_back();
	f.pop_back(); s.pop_back();
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.pop_back(); s.pop_back();
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);
}

TEST_F(ListTest, popFront) {
	ft::list<int> f;
	std::list<int> s;
	ft::list<int>::iterator itF;
	ft::list<int>::iterator itFe;
	std::list<int>::iterator itS;
	std::list<int>::iterator itSe;

	f.push_back(42); s.push_back(42);
	f.push_back(21); s.push_back(21);

	f.pop_front(); s.pop_front();
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.push_front(1); s.push_front(1);
	f.push_front(2); s.push_front(2);

	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.pop_front(); s.pop_front();
	f.pop_front(); s.pop_front();
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.pop_front(); s.pop_front();
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);
}