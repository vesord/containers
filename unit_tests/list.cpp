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
	ft::list<int>::iterator itF = ftList.begin();
	ft::list<int>::iterator itFe = ftList.end();
	std::list<int>::iterator itS = stdList.begin();
	std::list<int>::iterator itSe = stdList.end();
};

template <typename itFt, typename itFtEnd, typename itStd, typename itStdEnd>
void checkListEqual(itFt itF, itFtEnd itFe, itStd itS, itStdEnd itSe, size_t size = 50) {
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

TEST_F(ListTest, fillConstruction) {
	ft::list<std::string> f(5, "str");
	std::list<std::string> s(5, "str");

	ft::list<std::string>::iterator itF;
	ft::list<std::string>::iterator itFe;
	std::list<std::string>::iterator itS;
	std::list<std::string>::iterator itSe;

	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	f.push_front("front"); s.push_front("front");
	f.push_back("back"); s.push_back("back");

	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);
}

TEST_F(ListTest, rangeConstruction) {
	ft::list<int>::iterator itF;
	ft::list<int>::iterator itFe;
	std::list<int>::iterator itS;
	std::list<int>::iterator itSe;

	itF = ftList.begin(); itFe = ftList.end();
	itS = stdList.begin(); itSe	= stdList.end();
	++itF; ++itF; ++itS; ++itS;
	--itFe; --itFe; --itSe; --itSe;

	ft::list<int> f(itF, itFe);
	std::list<int> s(itS, itSe);
	EXPECT_EQ(s.size(), f.size());
	itF = f.begin(); itFe = f.end();
	itS = s.begin(); itSe = s.end();
	checkListEqual(itF, itFe, itS, itSe);

	itF = f.end(); itS = s.end();
	ft::list<int> f1(itF, itF);
	std::list<int> s1(itS, itS);
	EXPECT_EQ(s1.size(), f1.size());
	itF = f1.begin(); itFe = f1.end();
	itS = s1.begin(); itSe = s1.end();
	checkListEqual(itF, itFe, itS, itSe);

	itF = f.begin(); itS = s.begin();
	ft::list<int> f2(itF, itF);
	std::list<int> s2(itS, itS);
	EXPECT_EQ(s2.size(), f2.size());
	itF = f2.begin(); itFe = f2.end();
	itS = s2.begin(); itSe = s2.end();
	checkListEqual(itF, itFe, itS, itSe);

	itF = f.begin(); itS = ++s.begin();
	ft::list<int> f3(itF, itF);
	std::list<int> s3(itS, itS);
	EXPECT_EQ(s3.size(), f3.size());
	itF = f3.begin(); itFe = f3.end();
	itS = s3.begin(); itSe = s3.end();
	checkListEqual(itF, itFe, itS, itSe);

	ft::list<int> f4(itS, itSe);
	std::list<int> s4(itF, itFe);
	EXPECT_EQ(s4.size(), f4.size());
	itF = f4.begin(); itFe = f4.end();
	itS = s4.begin(); itSe = s4.end();
	checkListEqual(itF, itFe, itS, itSe);

	int arr[] = {9, 42, 21, 84, 543};
	ft::list<int> f5(arr + 1, arr + 4);
	std::list<int> s5(arr + 1, arr + 4);
	EXPECT_EQ(s4.size(), f4.size());
	itF = f4.begin(); itFe = f4.end();
	itS = s4.begin(); itSe = s4.end();
	checkListEqual(itF, itFe, itS, itSe);
}

TEST_F(ListTest, assign) {
	++itF; ++itF; ++itS; ++itS;
	--itFe; --itFe; --itSe; --itSe;

	ft::list<int> f(ftList);
	std::list<int> s(stdList);
	f.assign(itF, itFe);
	s.assign(itS, itSe);
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.assign(ftList.begin(), --ftList.end());
	s.assign(stdList.begin(), --stdList.end());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.assign(80, 42);
	s.assign(80, 42);
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.assign(0, 42);
	s.assign(0, 42);
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	int arr[] = {9, 42, 21, 84, 543};
	f.assign(arr + 1, arr + 4);
	s.assign(arr + 1, arr + 4);
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());
}

TEST_F(ListTest, insertPosVal) {
	++itF; ++itS;
	++itF; ++itS;
	ft::list<int>::iterator fret;
	std::list<int>::iterator sret;
	fret = ftList.insert(itF, 442);
	sret = stdList.insert(itS, 442);
	EXPECT_EQ(ftList.size(), stdList.size());
	checkListEqual(fret, ftList.end(), sret, stdList.end());
	checkListEqual(itF, ftList.end(), itS, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	ft::list<int> f;
	std::list<int>	s;
	fret = f.insert(f.begin(), 42);
	sret = s.insert(s.begin(), 42);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(fret, f.end(), sret, s.end());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	fret = f.insert(f.begin(), 421);
	sret = s.insert(s.begin(), 421);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(fret, f.end(), sret, s.end());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	fret = f.insert(--f.end(), 4210);
	sret = s.insert(--s.end(), 4210);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(fret, f.end(), sret, s.end());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	fret = f.insert(f.end(), 4210);
	sret = s.insert(s.end(), 4210);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(fret, f.end(), sret, s.end());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());
}

TEST_F(ListTest, insertRangeN) {
	++itF; ++itS;
	++itF; ++itS;
	ftList.insert(itF, 4, 909);
	stdList.insert(itS, 4, 909);
	EXPECT_EQ(ftList.size(), stdList.size());
	checkListEqual(itF, ftList.end(), itS, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	ft::list<int> f;
	std::list<int>	s;
	f.insert(f.begin(), 4, 42);
	s.insert(s.begin(), 4, 42);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), 1, 42);
	s.insert(s.begin(), 1, 42);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), 0, 42);
	s.insert(s.begin(), 0, 42);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.insert(f.begin(), 1, 42);
	s.insert(s.begin(), 1, 42);
	f.insert(f.begin(), 5, 21);
	s.insert(s.begin(), 5, 21);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), 1, 42);
	s.insert(s.begin(), 1, 42);
	f.insert(--f.end(), 5, 21);
	s.insert(--s.end(), 5, 21);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.end(), 5, 21);
	s.insert(s.end(), 5, 21);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), 1, 42);
	s.insert(s.begin(), 1, 42);
	f.insert(f.end(), 5, 21);
	s.insert(s.end(), 5, 21);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());
}

TEST_F(ListTest, insertRangeIterator) {
	++itF; ++itS;
	++itF; ++itS;
	int arr[] = {642, 543, 641, 6321, 346, 74432, 21, 6736, 1111};
	ftList.insert(itF, arr + 2, arr + 7);
	stdList.insert(itS, arr + 2, arr + 7);
	EXPECT_EQ(ftList.size(), stdList.size());
	checkListEqual(itF, ftList.end(), itS, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	ft::list<int> f;
	std::list<int>	s;
	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	f.insert(--f.end(), arr + 2, arr + 7);
	s.insert(--s.end(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.end(), arr + 2, arr + 7);
	s.insert(s.end(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());

	f.clear(); s.clear();
	f.insert(f.begin(), arr + 2, arr + 7);
	s.insert(s.begin(), arr + 2, arr + 7);
	f.insert(f.end(), arr + 2, arr + 7);
	s.insert(s.end(), arr + 2, arr + 7);
	EXPECT_EQ(f.size(), s.size());
	checkListEqual(f.begin(), f.end(), s.begin(), s.end());
}

TEST_F(ListTest, erase) {
	++itF; ++itS;
	++itF; ++itS;
	ft::list<int>::iterator fret;
	std::list<int>::iterator sret;

	fret = ftList.erase(itF);
	sret = stdList.erase(itS);
	checkListEqual(fret, ftList.end(), sret, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	itF = --ftList.end();
	itS = --stdList.end();
	fret = ftList.erase(itF);
	sret = stdList.erase(itS);
	EXPECT_EQ(fret, itFe);
	EXPECT_EQ(sret, itSe);
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	fret = ftList.erase(ftList.begin());
	sret = stdList.erase(stdList.begin());
	checkListEqual(fret, ftList.end(), sret, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

//	ft::list<int> f;
//	std::list<int> s;

//	fret = f.erase(f.begin());
//	sret = s.erase(s.begin());
//	checkListEqual(fret, ftList.end(), sret, stdList.end());
//	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	fret = ftList.begin();
	sret = stdList.begin();
	while (sret != itSe)
		sret = stdList.erase(stdList.begin());
	while (fret != itFe)
		fret = ftList.erase(ftList.begin());
	EXPECT_EQ(true, ftList.empty());
	EXPECT_EQ(true, stdList.empty());
	EXPECT_EQ(fret++, itFe);
	EXPECT_EQ(sret++, itSe);
	EXPECT_EQ(fret++, itFe);
	EXPECT_EQ(sret++, itSe);
	EXPECT_EQ(fret--, itFe);
	EXPECT_EQ(sret--, itSe);
	EXPECT_EQ(fret--, itFe);
	EXPECT_EQ(sret--, itSe);
}

TEST_F(ListTest, eraseRange) {
	++itF; ++itS; --itFe; --itFe;
	++itF; ++itS; --itSe; --itSe;
	ft::list<int>::iterator fret;
	std::list<int>::iterator sret;

	fret = ftList.erase(itF, itFe);
	sret = stdList.erase(itS, itSe);
	checkListEqual(fret, ftList.end(), sret, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	fret = ftList.erase(ftList.begin(), ftList.end());
	sret = stdList.erase(stdList.begin(), stdList.end());
	EXPECT_EQ(true, ftList.empty());
	EXPECT_EQ(true, stdList.empty());
	itFe = ftList.end();
	itSe = stdList.end();
	EXPECT_EQ(fret++, itFe);
	EXPECT_EQ(sret++, itSe);
	EXPECT_EQ(fret++, itFe);
	EXPECT_EQ(sret++, itSe);
	EXPECT_EQ(fret--, itFe);
	EXPECT_EQ(sret--, itSe);
	EXPECT_EQ(fret--, itFe);
	EXPECT_EQ(sret--, itSe);

	ftList.push_back(1);
	stdList.push_back(1);
	fret = ftList.erase(ftList.end(), ftList.end());
	sret = stdList.erase(stdList.end(), stdList.end());
	EXPECT_EQ(1, ftList.size());
	EXPECT_EQ(1, stdList.size());
	checkListEqual(fret, ftList.end(), sret, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());

	ftList.push_back(2);
	stdList.push_back(2);
	fret = ftList.erase(--ftList.end(), ftList.end());
	sret = stdList.erase(--stdList.end(), stdList.end());
	EXPECT_EQ(1, ftList.size());
	EXPECT_EQ(1, stdList.size());
	checkListEqual(fret, ftList.end(), sret, stdList.end());
	checkListEqual(ftList.begin(), ftList.end(), stdList.begin(), stdList.end());
}

TEST_F(ListTest, swap) {
	ft::list<int> f1 = ftList;
	ft::list<int> f2;
	std::list<int> s1 = stdList;
	std::list<int> s2;

	int arr[] = {543, 54231, 1234, 341231, 4234, 4355555, 0};
	f2.insert(f2.begin(), arr, arr + 5);
	s2.insert(s2.begin(), arr, arr + 5);

	ft::list<int> f2ref = f2;
	std::list<int> s2ref = s2;

	ft::list<int>::iterator if11 = f1.begin();
	ft::list<int>::iterator if12 = ++(++f1.begin());
	ft::list<int>::iterator if13 = --f1.end();
	ft::list<int>::iterator if21 = f2.begin();
	ft::list<int>::iterator if22 = ++(++(++(f2.begin())));
	ft::list<int>::iterator if23 = f2.end();

	std::list<int>::iterator is11 = s1.begin();
	std::list<int>::iterator is12 = ++(++(s1.begin()));
	std::list<int>::iterator is13 = --s1.end();
	std::list<int>::iterator is21 = s2.begin();
	std::list<int>::iterator is22 = ++(++(++(s2.begin())));
	std::list<int>::iterator is23 = s2.end();

	size_t fsize1 = f1.size();
	size_t fsize2 = f2.size();
	size_t ssize1 = s1.size();
	size_t ssize2 = s2.size();

	f1.swap(f2);
	s1.swap(s2);
	EXPECT_EQ(fsize1, f2.size());
	EXPECT_EQ(fsize2, f1.size());
	EXPECT_EQ(ssize1, s2.size());
	EXPECT_EQ(ssize2, s1.size());

	checkListEqual(if11, f2.end(), is11, s2.end());
	checkListEqual(if12, f2.end(), is12, s2.end());
	checkListEqual(if13, f2.end(), is13, s2.end());
	checkListEqual(if21, f1.end(), is21, s1.end());
	checkListEqual(if22, f1.end(), is22, s1.end());
//	checkListEqual(if23, f1.end(), is23, s1.end()); // is23 does not remains the same WTF??

	checkListEqual(f1.begin(), f1.end(), f2ref.begin(), f2ref.end());
	checkListEqual(s1.begin(), s1.end(), s2ref.begin(), s2ref.end());

	checkListEqual(f2.begin(), f2.end(), ftList.begin(), ftList.end());
	checkListEqual(s2.begin(), s2.end(), stdList.begin(), stdList.end());
}