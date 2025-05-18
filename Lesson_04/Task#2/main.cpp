#include <catch2/catch_test_macros.hpp>
#include "List.h"

TEST_CASE("List: Empty and Size") {
    List lst;
    REQUIRE(lst.Empty());
    REQUIRE(lst.Size() == 0);
}

TEST_CASE("List: PushFront and PushBack increase size") {
    List lst;

    lst.PushFront(1);
    REQUIRE(lst.Size() == 1);

    lst.PushBack(2);
    REQUIRE(lst.Size() == 2);

    lst.PushFront(3);
    REQUIRE(lst.Size() == 3);
}

TEST_CASE("List: PopFront from empty list throws") {
    List lst;
    REQUIRE_THROWS_AS(lst.PopFront(), std::runtime_error);
}

TEST_CASE("List: PopBack from empty list throws") {
    List lst;
    REQUIRE_THROWS_AS(lst.PopBack(), std::runtime_error);
}

TEST_CASE("List: PushFront and PopFront") {
    List lst;
    lst.PushFront(42);
    REQUIRE(lst.PopFront() == 42);
    REQUIRE(lst.Empty());
}

TEST_CASE("List: PushBack and PopBack") {
    List lst;
    lst.PushBack(99);
    REQUIRE(lst.PopBack() == 99);
    REQUIRE(lst.Empty());
}

TEST_CASE("List: Mixed push/pop scenario") {
    List lst;

    lst.PushBack(1);    // [1]
    lst.PushBack(2);    // [1, 2]
    lst.PushFront(3);   // [3, 1, 2]
    lst.PushFront(4);   // [4, 3, 1, 2]
    REQUIRE(lst.Size() == 4);

    REQUIRE(lst.PopFront() == 4); // [3, 1, 2]
    REQUIRE(lst.PopBack() == 2);  // [3, 1]
    REQUIRE(lst.PopFront() == 3); // [1]
    REQUIRE(lst.PopBack() == 1);  // []
    REQUIRE(lst.Empty());
}
