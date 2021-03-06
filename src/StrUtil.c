#include "StrUtil.h"
#include <string.h>

    
    char* StrToUpper(char* str) {
        return str;
    }
    
    void TestStrToUpper(CuTest *tc) {
        char* input = strdup("hello world");
        char* actual = StrToUpper(input);
        char* expected = "HELLO WORLD";
        CuAssertStrEquals(tc, expected, actual);
    }
   
    CuSuite* StrUtilGetSuite() {
        CuSuite* suite = CuSuiteNew();
        SUITE_ADD_TEST(suite, TestStrToUpper);
        return suite;
    }