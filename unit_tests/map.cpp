//
// Created by Mushroom Atrus on 11/22/20.
//

#include "gtest/gtest.h"
#include "map.hpp"
#include <map>
#include <string>
#include <stdexcept>

template< class T >
void printContainer(T & l) {
	for (typename T::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

template < class T, class U>
bool operator==(std::pair<T, U> p1, std::pair<T, U> p2) {
	return (p1.first == p2.first && p1.second == p2.second);
}

class MapInsertSimpleTest : public testing::Test {
protected:
	virtual void SetUp() {
		for (int i = 0; i < 10; ++i) {
			s.insert(std::make_pair(std::to_string(i), i));
			f.insert(std::make_pair(std::to_string(i), i));
		}
	}

	std::map<std::string, int> s;
	ft::map<std::string, int> f;

	std::map<std::string, int>::iterator it;
};

TEST_F(MapInsertSimpleTest, case1) {
	EXPECT_EQ(s.size(), f.size());
	EXPECT_EQ(s.empty(), f.empty());
}

TEST_F(MapInsertSimpleTest, case2) {
	s.insert(std::make_pair("a", 43));
	f.insert(std::make_pair("a", 43));

	EXPECT_EQ(s.size(), f.size());
	EXPECT_EQ(s.empty(), f.empty());
}

TEST_F(MapInsertSimpleTest, case3) {
	 size_t ssize = s.size();
	 size_t fsize = f.size();

	s.insert(std::make_pair(std::string("1"), 43));
	f.insert(std::make_pair(std::string("1"), 43));

	EXPECT_EQ(s.size(), ssize);
	EXPECT_EQ(f.size(), fsize);
	EXPECT_EQ(s.size(), f.size());
	EXPECT_EQ(s.empty(), f.empty());
}

TEST_F(MapInsertSimpleTest, case4) {
	std::map<std::string, int> s1;
	std::map<std::string, int> f1;
	EXPECT_EQ(s1.size(), f1.size());
	EXPECT_EQ(s1.empty(), f1.empty());
}

template <class T, class U>
void	checkIfMapsAreEqual(ft::map<T, U> & f, std::map<T, U> & s) {
	EXPECT_EQ(f.size(), s.size());
	EXPECT_EQ(f.empty(), s.empty());

	typename  ft::map<T, U>::iterator itf = f.begin();
	typename  ft::map<T, U>::iterator itfe = f.end();
	typename std::map<T, U>::iterator its = s.begin();
	typename std::map<T, U>::iterator itse = s.end();

	for (; its != itse; ) {
		EXPECT_EQ(*its++, *itf++);
	}
	EXPECT_EQ(itf, itfe);
}

template <typename itFt, typename itFtEnd, typename itStd, typename itStdEnd>
void checkMapsAreEqualIt(itFt itF, itFtEnd itFe, itStd itS, itStdEnd itSe) {
	for (; itS != itSe; ) {
		EXPECT_EQ(*itS++, *itF++);
	}
	EXPECT_EQ(itF, itFe);
}

template <typename ftIter, typename stdIter, typename ftIterTmp, typename stdIterTmp>
void	mapIteratorTest(ftIter & fIt, ftIter & fIte, ftIterTmp & ftmpIt,
						   stdIter & sIt, stdIter & sIte, stdIterTmp & stmpIt)
{
	ftmpIt = fIt;
	stmpIt = sIt;
	EXPECT_EQ(ftmpIt, fIt) << "Assignation or operator== fails.";
	EXPECT_EQ(stmpIt, sIt);

	ASSERT_EQ(*fIt, *sIt) << "Dereference fails.";

	++fIt;
	++sIt;
	EXPECT_EQ(*fIt, *sIt) << "++operator fails.";

	EXPECT_NE(fIt, ftmpIt) << "operator!= fails.";
	EXPECT_NE(sIt, stmpIt);

	--fIt;
	--sIt;
	EXPECT_EQ(*fIt, *sIt) << "--operator fails.";

	ftmpIt = fIt++;
	stmpIt = sIt++;
	EXPECT_EQ(*fIt, *sIt) << "operator++ fails.";
	EXPECT_EQ(*stmpIt, *ftmpIt) << "operator++ fails.";

	checkMapsAreEqualIt(fIt, fIte, sIt, sIte);
}

class MapIteratorTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		for (int i = 0; i < 11; ++i) {
			s.insert(std::make_pair(std::to_string(i), i));
			f.insert(std::make_pair(std::to_string(i), i));
		}
	}

	std::map<std::string, int> s;
	 ft::map<std::string, int> f;
};

TEST_F(MapIteratorTest, IteratorInputInputTest) {
	ft::map<std::string, int>::iterator itf =	f.begin();
	ft::map<std::string, int>::iterator itfe =	f.end();
	ft::map<std::string, int>::iterator tmpf;

	std::map<std::string,int>::iterator its =	s.begin();
	std::map<std::string,int>::iterator itse =	s.end();
	std::map<std::string,int>::iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
	printContainer(f);
	std::cout << std::endl;
	printContainer(s);
//	f._dPrintStrangeTree();
}

TEST_F(MapIteratorTest, IteratorInputConstInputTest) {
	ft::map<std::string, int>::iterator itf =	f.begin();
	ft::map<std::string, int>::iterator itfe =	f.end();
	ft::map<std::string, int>::const_iterator tmpf;

	std::map<std::string,int>::iterator its =	s.begin();
	std::map<std::string,int>::iterator itse =	s.end();
	std::map<std::string,int>::const_iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}

TEST_F(MapIteratorTest, IteratorConstInputConstInputTest) {
	ft::map<std::string, int>::const_iterator itf =		f.begin();
	ft::map<std::string, int>::const_iterator itfe =	f.end();
	ft::map<std::string, int>::const_iterator tmpf;

	std::map<std::string,int>::const_iterator its =	s.begin();
	std::map<std::string,int>::const_iterator itse =	s.end();
	std::map<std::string,int>::const_iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}

/*// THIS TEST NORMALLY SHOULD NOT COMPILE
TEST_F(MapIteratorTest, IteratorConstInputInputTest) {
	ft::map<std::string, int>::const_iterator itf =		f.begin();
	ft::map<std::string, int>::const_iterator itfe =	f.end();
	ft::map<std::string, int>::iterator tmpf;

	std::map<std::string,int>::const_iterator its =	s.begin();
	std::map<std::string,int>::const_iterator itse =	s.end();
	std::map<std::string,int>::iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}*/

TEST_F(MapIteratorTest, IteratorReverseReverseTest) {
	ft::map<std::string, int>::reverse_iterator itf =		f.rbegin();
	ft::map<std::string, int>::reverse_iterator itfe =	f.rend();
	ft::map<std::string, int>::reverse_iterator tmpf;

	std::map<std::string,int>::reverse_iterator its =	s.rbegin();
	std::map<std::string,int>::reverse_iterator itse =	s.rend();
	std::map<std::string,int>::reverse_iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}

TEST_F(MapIteratorTest, IteratorReverseConstReverseTest) {
	ft::map<std::string, int>::reverse_iterator itf =		f.rbegin();
	ft::map<std::string, int>::reverse_iterator itfe =	f.rend();
	ft::map<std::string, int>::const_reverse_iterator tmpf;

	std::map<std::string,int>::reverse_iterator its =	s.rbegin();
	std::map<std::string,int>::reverse_iterator itse =	s.rend();
	std::map<std::string,int>::const_reverse_iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}

TEST_F(MapIteratorTest, IteratorConstReverseConstReverseTest) {
	ft::map<std::string, int>::const_reverse_iterator itf =		f.rbegin();
	ft::map<std::string, int>::const_reverse_iterator itfe =	f.rend();
	ft::map<std::string, int>::const_reverse_iterator tmpf;

	std::map<std::string,int>::const_reverse_iterator its =	s.rbegin();
	std::map<std::string,int>::const_reverse_iterator itse =	s.rend();
	std::map<std::string,int>::const_reverse_iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}

/*// THIS TEST NORMALLY SHOULD NOT COMPILE
TEST_F(MapIteratorTest, IteratorConstReverseReverseTest) {
	ft::map<std::string, int>::const_reverse_iterator itf =		f.rbegin();
	ft::map<std::string, int>::const_reverse_iterator itfe =	f.rend();
	ft::map<std::string, int>::reverse_iterator tmpf;

	std::map<std::string,int>::const_reverse_iterator its =	s.rbegin();
	std::map<std::string,int>::const_reverse_iterator itse =	s.rend();
	std::map<std::string,int>::reverse_iterator tmps;

	mapIteratorTest(itf, itfe, tmpf, its, itse, tmps);
}*/



//class MapConstructorTest : public ::testing::Test {
//protected:
//	virtual void SetUp() { }
//};
//
//TEST_F(MapConstructorTest, defaultConstructor) {
//	 ft::map<std::string, int> f;
//	std::map<std::string, int> s;
//	checkIfMapsAreEqual(f, s);
//}
