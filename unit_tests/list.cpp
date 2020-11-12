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

}

TEST_F(ListTest, accessBack) {

}

TEST_F(ListTest, accessFront) {
	ft::list<int>::iterator itF = ftList.begin();
	std::list<int>::iterator itS = stdList.begin();

	EXPECT_EQ(*itF, *itS);
	ftList.push_front(42);
	stdList.push_front(42);
	EXPECT_EQ(*itS, *itF);
	--itS;
	--itF;
	EXPECT_EQ(*itS, *itF);
}