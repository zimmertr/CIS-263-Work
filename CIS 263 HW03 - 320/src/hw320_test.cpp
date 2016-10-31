//
//  HW3 LazyList Test
//

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "hw320_lazylist.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class LazyTest {
public:
    LazyTest() : onecopy{"michigan", "wisconsin", "minnesota", "ohio",
        "indiana", "illinois"}
    {
        for (auto it = onecopy.begin(); it != onecopy.end(); ++it)
            one.push_back(*it);
        for (auto it = onecopy.begin(); it != onecopy.end(); ++it)
            states.push_back (*it);
        //std::copy (onecopy.begin(), onecopy.end(), back_inserter(states));
    }
    gvsu::lazylist<std::string> one;
    std::list<std::string> onecopy;
    std::vector<std::string> states;
};

TEST_CASE_METHOD(LazyTest, "isEmpty()")
{
    gvsu::lazylist<std::string> tmp;
    REQUIRE (tmp.isEmpty());
    REQUIRE (tmp.size() == 0);
    REQUIRE_FALSE(one.isEmpty());
    REQUIRE(one.size() > 0);
}


TEST_CASE_METHOD(LazyTest, "contains()") {
    for (auto iter = onecopy.begin(); iter != onecopy.end(); ++iter)
    {
        REQUIRE (one.contains(*iter));
        REQUIRE_FALSE (one.contains(*iter + "123"));
    }
}

TEST_CASE_METHOD(LazyTest, "contains() after pop_back") {
    one.pop_back();
    REQUIRE_FALSE (one.contains(*onecopy.rbegin()));
}

TEST_CASE_METHOD(LazyTest, "contains() after pop_back loop") {
    for (auto iter = onecopy.rbegin(); iter != onecopy.rend(); ++iter) {
        one.pop_back();
        REQUIRE_FALSE (one.contains(*iter));
    }
}

TEST_CASE_METHOD(LazyTest, "front()") {
    REQUIRE (one.front() == onecopy.front());
}

TEST_CASE_METHOD(LazyTest, "pop_back()")
{
    int oldsize = one.size();
    one.pop_back();
    REQUIRE (oldsize == one.size() + 1);
    auto last = one.end();
    --last;
    REQUIRE (*last != onecopy.back());
    auto iter = onecopy.rbegin();
    ++iter;
    REQUIRE (*last == *iter);
}

TEST_CASE_METHOD(LazyTest, "insert() at begin") {
    one.insert (one.begin(), "Content");
    REQUIRE(one.front() == "Content");
    REQUIRE(one.size() == onecopy.size() + 1);
}

TEST_CASE_METHOD(LazyTest, "insert() at begin using loop") {
    gvsu::lazylist<std::string> tmp;
    for (int k = 0; k < 10; k++)
        tmp.insert (tmp.begin(), "Content" + ('A' + k));
    int k = 9;
    for (auto iter = tmp.begin(); iter != tmp.end(); ++iter) {
        REQUIRE(*iter == "Content" + ('A' + k));
        k--;
    }
}

TEST_CASE_METHOD(LazyTest, "erase() at begin") {
    std::string first = one.front();
    int old_size = one.size();
    one.erase (one.begin());
    REQUIRE(one.front() != first);
    REQUIRE(one.size() == old_size - 1);
    REQUIRE_FALSE(one.contains(first));
}

TEST_CASE_METHOD(LazyTest, "erase() front in loop") {
    for (int k = 1; k < states.size(); k++)
    {
        one.erase(one.begin());
        REQUIRE(states[k] == one.front());
    }
}

TEST_CASE_METHOD(LazyTest, "begin() should skip deleted")
{
    auto iter = one.begin();
    auto itercopy = iter;
    one.erase(iter);
    ++iter;
    one.erase(iter);

    auto oter = one.begin();
    REQUIRE(itercopy != oter);
    REQUIRE(*itercopy != *oter);
    REQUIRE(*oter == states[2]);
}



