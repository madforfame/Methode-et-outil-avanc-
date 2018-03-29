#include "CuTest.h"
#include "checkUtil.h"
    
    CuSuite* StrUtilGetSuite();
    
    void RunAllTests(void) {
        CuString *output = CuStringNew();
        CuSuite* suite = CuSuiteNew();
        
        CuSuiteAddSuite(suite, StrUtilGetSuite());
    
        CuSuiteRun(suite);
        CuSuiteSummary(suite, output);
        CuSuiteDetails(suite, output);
        printf("%s\n", output->buffer);
    }
    
    int main(void) {
        RunAllTests();
    }
