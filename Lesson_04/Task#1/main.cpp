#include <catch2/catch_test_macros.hpp>
#include "List.h"

TEST_CASE("List: Empty") {
    List lst;
    REQUIRE(lst.Empty());
    REQUIRE(lst.Size() == 0);
}

TEST_CASE("List: Push and Size") {
    List lst;

    lst.PushBack(10);
    REQUIRE_FALSE(lst.Empty());
    REQUIRE(lst.Size() == 1);

    lst.PushFront(20);
    lst.PushBack(30);
    REQUIRE(lst.Size() == 3);
}

TEST_CASE("List: Clear") {
    List lst;
    lst.PushBack(1);
    lst.PushBack(2);
    lst.PushFront(3);

    REQUIRE(lst.Size() == 3);
    lst.Clear();
    REQUIRE(lst.Size() == 0);
    REQUIRE(lst.Empty());
}
