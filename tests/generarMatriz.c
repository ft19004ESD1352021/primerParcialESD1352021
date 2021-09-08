/*
 * File:   generarMatriz.c
 * Author: joel
 *
 * Created on 8 sep. 2021, 14:42:26
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../cabecera.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testGenerarMatriz() {
    char* path = "peliculasFavoritasESD135_2021.csv";
    char* paths = "peliculas";
    int* result = generarMatriz(path);
    CU_ASSERT_EQUAL(*(result + 59 * 6 + 6), 0);
    CU_ASSERT_EQUAL(*(result + 1 * 6 + 0), 1);
    int *i = generarMatriz(paths);
    if(i == 0){
        CU_PASS("PASS");
    }else if(i == 1){
        CU_FAIL("FAIL");
    }
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("generarMatriz", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testGenerarMatriz", testGenerarMatriz))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
