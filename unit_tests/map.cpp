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

class MapBoundAccessTest : public testing::Test {
protected:
	virtual void SetUp() {

	}
};

TEST_F(MapBoundAccessTest, beginsEmpty) {
	ft::map<std::string, int> f;
	std::map<std::string, int> s;

	ft::map<std::string, int>::iterator itf =	f.begin();
	ft::map<std::string, int>::iterator itfe =	f.end();

	std::map<std::string,int>::iterator its =	s.begin();
	std::map<std::string,int>::iterator itse =	s.end();

	EXPECT_EQ(its, itse);
	EXPECT_EQ(itf, itfe);

	ft::map<std::string, int>::reverse_iterator ritf =	f.rbegin();
	ft::map<std::string, int>::reverse_iterator ritfe =	f.rend();

	std::map<std::string,int>::reverse_iterator rits =	s.rbegin();
	std::map<std::string,int>::reverse_iterator ritse =	s.rend();

	EXPECT_EQ(rits, ritse);
	EXPECT_EQ(ritf, ritfe);
}

TEST_F(MapBoundAccessTest, beginsOneForvard) {
	ft::map<std::string, int> f;
	std::map<std::string, int> s;
	ft::map<std::string, int>::iterator itf;
	ft::map<std::string, int>::iterator itfe;
	std::map<std::string,int>::iterator its;
	std::map<std::string,int>::iterator itse;

	f.insert(std::make_pair("a", 123));
	s.insert(std::make_pair("a", 123));

	itf =	f.begin();	its =	s.begin();
	itfe =	f.end();	itse =	s.end();
	EXPECT_EQ(++its, itse);
	EXPECT_EQ(++itf, itfe);

	itf =	f.begin();	its =	s.begin();
	itfe =	f.end();	itse =	s.end();
	EXPECT_EQ(its, --itse);
	EXPECT_EQ(itf, --itfe);
}

TEST_F(MapBoundAccessTest, beginsOneReverse) {
	ft::map<std::string, int> f;
	std::map<std::string, int> s;
	ft::map<std::string, int>::reverse_iterator itf;
	ft::map<std::string, int>::reverse_iterator itfe;
	std::map<std::string,int>::reverse_iterator its;
	std::map<std::string,int>::reverse_iterator itse;

	f.insert(std::make_pair("a", 123));
	s.insert(std::make_pair("a", 123));

	itf =	f.rbegin();	its =	s.rbegin();
	itfe =	f.rend();	itse =	s.rend();
	EXPECT_EQ(++its, itse);
	EXPECT_EQ(++itf, itfe);

	itf =	f.rbegin();	its =	s.rbegin();
	itfe =	f.rend();	itse =	s.rend();
	EXPECT_EQ(its, --itse);
	EXPECT_EQ(itf, --itfe);
}

class MapInsertTest : public testing::Test {
protected:
	virtual void SetUp() {
		itf =	f.begin();
		itfe =	f.end();

		its =	s.begin();
		itse =	s.end();
	}
	std::pair<ft::map<std::string,int>::iterator, bool> pf;
	std::pair<std::map<std::string,int>::iterator, bool> ps;

	ft::map<std::string, int> f;
	std::map<std::string,int> s;

	ft::map<std::string, int>::iterator itf;
	std::map<std::string,int>::iterator its;
	ft::map<std::string, int>::iterator itfe;
	std::map<std::string,int>::iterator itse;
};

TEST_F(MapInsertTest, insertValCaseSingle) {
	pf = f.insert(std::make_pair("a", 1));
	ps = s.insert(std::make_pair("a", 1));

	EXPECT_EQ(pf.second, ps.second);

	checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertValCaseOverride) {
	pf = f.insert(std::make_pair("a", 1));
	pf = f.insert(std::make_pair("a", 42));
	ps = s.insert(std::make_pair("a", 1));
	ps = s.insert(std::make_pair("a", 42));

	EXPECT_EQ(pf.second, ps.second);
	EXPECT_EQ(pf.first, f.begin());
	EXPECT_EQ(ps.first, s.begin());
	EXPECT_EQ(ps.first->second, 1);
	EXPECT_EQ(pf.first->second, 1);

	checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertValCaseDouble1) {
	pf = f.insert(std::make_pair("a", 1));
	ps = s.insert(std::make_pair("a", 1));

	pf = f.insert(std::make_pair("b", 1));
	ps = s.insert(std::make_pair("b", 1));

	EXPECT_EQ(pf.second, ps.second);
	EXPECT_EQ(pf.first, --f.end());
	EXPECT_EQ(ps.first, --s.end());

	checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertValCaseDouble2) {
	pf = f.insert(std::make_pair("b", 1));
	ps = s.insert(std::make_pair("b", 1));

	pf = f.insert(std::make_pair("a", 1));
	ps = s.insert(std::make_pair("a", 1));

	EXPECT_EQ(pf.second, ps.second);
	EXPECT_EQ(pf.first, f.begin());
	EXPECT_EQ(ps.first, s.begin());

	checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertValCaseTriple1) {
	pf = f.insert(std::make_pair("b", 1));
	ps = s.insert(std::make_pair("b", 1));

	pf = f.insert(std::make_pair("a", 1));
	ps = s.insert(std::make_pair("a", 1));

	pf = f.insert(std::make_pair("c", 1));
	ps = s.insert(std::make_pair("c", 1));

	EXPECT_EQ(pf.second, ps.second);
	EXPECT_EQ(pf.first, --f.end());
	EXPECT_EQ(ps.first, --s.end());

	checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertValCaseTriple2) {
	pf = f.insert(std::make_pair("b", 1));
	ps = s.insert(std::make_pair("b", 1));

	pf = f.insert(std::make_pair("c", 1));
	ps = s.insert(std::make_pair("c", 1));

	pf = f.insert(std::make_pair("a", 1));
	ps = s.insert(std::make_pair("a", 1));

	EXPECT_EQ(pf.second, ps.second);
	EXPECT_EQ(pf.first, f.begin());
	EXPECT_EQ(ps.first, s.begin());

	checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, ultimative) {
	srand(1);
	int gen_key, gen_val;
	const int keys_limit = 500;

	for (int i = 0; i < keys_limit * 2; ++i) {
		gen_key = rand() % keys_limit;
		gen_val = rand();
		ps = s.insert(std::make_pair(std::to_string(gen_key), gen_val));
		pf = f.insert(std::make_pair(std::to_string(gen_key), gen_val));

		EXPECT_EQ(pf.second, ps.second);

		checkMapsAreEqualIt(pf.first, f.end(), ps.first, s.end());
		checkIfMapsAreEqual(f, s);
	}
}

TEST_F(MapInsertTest, insertPosVal1) {
	itf = f.insert(f.begin(), std::make_pair("123", 123));
	its = s.insert(s.begin(), std::make_pair("123", 123));

	checkMapsAreEqualIt(itf, f.end(), its, s.end());
	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertPosVal2) {
	const int times = 100;

	for (int i = 0; i < times; ++i) {
		its = s.insert(s.begin(), std::make_pair(std::to_string(i + 10), i));
		itf = f.insert(f.begin(), std::make_pair(std::to_string(i + 10), i));

		checkMapsAreEqualIt(itf, f.end(), its, s.end());
		checkIfMapsAreEqual(f, s);
	}
}

TEST_F(MapInsertTest, insertRangeSameMap) {
	const int times = 100;

	for (int i = 0; i < times; ++i) {
		its = s.insert(s.begin(), std::make_pair(std::to_string(i + 10), i));
		itf = f.insert(f.begin(), std::make_pair(std::to_string(i + 10), i));
	}

	s.insert(s.begin(), s.end());
	f.insert(f.begin(), f.end());

	checkIfMapsAreEqual(f, s);
}

TEST_F(MapInsertTest, insertAnotherRange) {
	const int times = 100;
	std::map<std::string, int> sample;

	for (int i = 0; i < times; ++i) {
		sample.insert(std::make_pair(std::to_string(i + 10), i));
	}

	its = sample.begin();
	std::advance(its, 30);

	s.insert(its, sample.end());
	f.insert(its, sample.end());

	checkIfMapsAreEqual(f, s);
}

class MapConstructionRange : public testing::Test {
protected:
	virtual void SetUp() {
		for (int i = 0; i < 100; ++i) {
			sample.insert(std::make_pair(std::to_string(i + 142), i - 121));
		}
	}
	std::pair<ft::map<std::string,int>::iterator, bool> pf;
	std::pair<std::map<std::string,int>::iterator, bool> ps;

	ft::map<std::string, int>::iterator itf;
	std::map<std::string,int>::iterator its;
	ft::map<std::string, int>::iterator itfe;
	std::map<std::string,int>::iterator itse;

	std::map<std::string, int> sample;
};

TEST_F(MapConstructionRange, emptyRange) {
	ft::map<std::string, int> f(sample.begin(), sample.begin());
	std::map<std::string,int> s(sample.begin(), sample.begin());

	checkIfMapsAreEqual(f, s);
}

TEST_F(MapConstructionRange, oneRange) {
	ft::map<std::string, int> f(sample.begin(), ++sample.begin());
	std::map<std::string,int> s(sample.begin(), ++sample.begin());

	checkIfMapsAreEqual(f, s);
}

TEST_F(MapConstructionRange, oneHundredRange) {
	ft::map<std::string, int> f(sample.begin(), sample.end());
	std::map<std::string,int> s(sample.begin(), sample.end());

	checkIfMapsAreEqual(f, s);
}

class MapObserversTest : public testing::Test {
protected:
	virtual void SetUp() {
		s.insert(std::make_pair('x', 1001));
		s.insert(std::make_pair('y', 2002));
		s.insert(std::make_pair('z', 3003));
		f.insert(std::make_pair('x', 1001));
		f.insert(std::make_pair('y', 2002));
		f.insert(std::make_pair('z', 3003));

		its = s.begin();
		itf = f.begin();

	}

	std::map<char,int>::iterator its;
	ft::map<char, int>::iterator itf;
	std::map<char,int> s;
	ft::map<char, int> f;
	std::map<char,int> sfill;
	ft::map<char, int> ffill;
};

TEST_F(MapObserversTest, valueComp) {
	std::pair<char, int> shighest = *s.rbegin();
	std::pair<char, int> fhighest = *f.rbegin();

	do {
		sfill.insert(*its);
	} while ( s.value_comp()(*its++, shighest) );

	do {
		ffill.insert(*itf);
	} while ( f.value_comp()(*itf++, fhighest) );

	checkIfMapsAreEqual(ffill, sfill);
}

TEST_F(MapObserversTest, keyComp) {
	char shighest = s.rbegin()->first;
	char fhighest = f.rbegin()->first;

	std::map<char,int>::key_compare scomp = s.key_comp();
	ft::map<char,int>::key_compare fcomp = f.key_comp();

	do {
		sfill.insert(*its);
	} while ( scomp((*its++).first, shighest) );

	do {
		ffill.insert(*itf);
	} while ( scomp((*itf++).first, fhighest) );

	checkIfMapsAreEqual(ffill, sfill);
}


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
