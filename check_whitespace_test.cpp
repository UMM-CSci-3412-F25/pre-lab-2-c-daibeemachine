#include <gtest/gtest.h>

#include "check_whitespace.h"

TEST(strip, EmptyString) {
    char const* str = strip("");
    ASSERT_STREQ("", str);
    free((void*)str);
    str = NULL;
}

TEST(strip, NoWhitespace) {
    char const* str = strip("frog");
    ASSERT_STREQ("frog", str);
    free((void*)str);
    str = NULL;
}

TEST(strip, WhitespaceOnFront) {
    char const* str = strip("   frog");
    ASSERT_STREQ("frog", str);
    free((void*)str);
    str = NULL;
}

TEST(strip, WhitespaceOnBack) {
    char const* str = strip("frog  ");
    ASSERT_STREQ("frog", str);
    free((void*)str);
    str = NULL;
}

TEST(strip, WhitespaceOnBothEnds) {
    char const* str = strip("  frog     ");
    ASSERT_STREQ("frog", str);
    free((void*)str);
    str = NULL;
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}