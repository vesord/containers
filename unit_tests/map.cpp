//
// Created by Mushroom Atrus on 11/22/20.
//

#include "gtest/gtest.h"
#include "map.hpp"
#include <map>
#include <string>
#include <stdexcept>

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