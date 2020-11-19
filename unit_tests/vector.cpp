//
// Created by Mushroom Atrus on 11/19/20.
//

#include "gtest/gtest.h"
#include "vector.hpp"
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

template< class T >
void printContainer(T & l) {
	for (typename T::iterator it = l.begin(); it != l.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}

template <class T>
void	checkIfVectorsAreEqual(ft::vector<T> & f, std::vector<T> & s) {
	EXPECT_EQ(f.size(), s.size());
	EXPECT_EQ(f.empty(), s.empty());
	EXPECT_GE(f.capacity(), f.size());
	EXPECT_GE(s.capacity(), s.size());

	typename  ft::vector<T>::iterator itF = f.begin();
	typename  ft::vector<T>::iterator itFe = f.end();
	typename std::vector<T>::iterator itS = s.begin();
	typename std::vector<T>::iterator itSe = s.end();

	for (; itS != itSe; ) {
		EXPECT_EQ(*itS++, *itF++);
	}
	EXPECT_EQ(itF, itFe);
}

class VectorConstructorTest : public ::testing::Test {
protected:
	virtual void SetUp() { }
};

TEST_F(VectorConstructorTest, defaultConstructor) {
	ft::vector<int> f;
	std::vector<int> s;
	checkIfVectorsAreEqual(f, s);
}

TEST_F(VectorConstructorTest, valueConstructor1) {
	ft::vector<int> f(60);
	std::vector<int> s(60);
	checkIfVectorsAreEqual(f, s);
	ft::vector<std::string> f1(60);
	std::vector<std::string> s1(60);
	checkIfVectorsAreEqual(f1, s1);
}

TEST_F(VectorConstructorTest, valueConstructor2) {
	ft::vector<int> f(60,5);
	std::vector<int> s(60, 5);
	checkIfVectorsAreEqual(f, s);
	ft::vector<std::string> f1(60, "Hello World!");
	std::vector<std::string> s1(60, "Hello World!");
	checkIfVectorsAreEqual(f1, s1);
}

TEST_F(VectorConstructorTest, rangeConstructor) {
	std::vector<int> sample;
	sample.push_back(54);
	sample.push_back(42);
	sample.push_back(21);
	ft::vector<int> f(sample.begin(), sample.end());
	std::vector<int> s(sample.begin(), sample.end());
	checkIfVectorsAreEqual(f, s);
}

TEST_F(VectorConstructorTest, copyConstructor) {
	ft::vector<std::string> f1(60, "Hello World!");
	std::vector<std::string> s1(60, "Hello World!");
	ft::vector<std::string> f2(f1);
	std::vector<std::string> s2(s1);
	checkIfVectorsAreEqual(f2, s2);
	ft::vector<std::string> f3 = f2;
	std::vector<std::string> s3 = s2;
	checkIfVectorsAreEqual(f3, s3);
}

class VectorIteratorTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		std::vector<int> sample;
		sample.push_back(54);
		sample.push_back(42);
		sample.push_back(21);
		sample.push_back(12);
		sample.push_back(99);
		sample.push_back(66);

		std::vector<int> s(sample.begin(), sample.end());
		ft::vector<int> f(sample.begin(), sample.end());

		std::vector<int>::iterator its =			s.begin();
		std::vector<int>::iterator itse =			s.end();
		std::vector<int>::const_iterator cits =		s.begin();
		std::vector<int>::const_iterator citse =	s.end();
		std::vector<int>::reverse_iterator rits =	s.rbegin();
		std::vector<int>::reverse_iterator ritse =	s.rend();
		std::vector<int>::reverse_iterator crits =	s.rbegin();
		std::vector<int>::reverse_iterator critse =	s.rend();

		ft::vector<int>::iterator itf =						f.begin();
		ft::vector<int>::iterator itfe =					f.end();
		ft::vector<int>::const_iterator citf =				f.begin();
		ft::vector<int>::const_iterator citfe =				f.end();
		ft::vector<int>::reverse_iterator ritf =			f.rbegin();
		ft::vector<int>::reverse_iterator ritfe =			f.rend();
		ft::vector<int>::const_reverse_iterator critf =		f.rbegin();
		ft::vector<int>::const_reverse_iterator critfe =	f.rend();
	}
};
