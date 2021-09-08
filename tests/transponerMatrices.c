/*
 * File:   transponerMatrices.c
 * Author: joel
 *
 * Created on 8 sep. 2021, 15:32:09
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../cabecera.h"
int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testTransponerMatrices() {
    
    int matriz[2][3]={1,2,3,4,5,6};
   
    int filas=2;
    int columnas=3;
    int* result = transponerMatrices(matriz, filas, columnas);
    
    CU_ASSERT_EQUAL(*(result + 0 *2+ 1), 4);
    CU_ASSERT_EQUAL(*(result + 1 *2+ 1), 5);
    CU_ASSERT_EQUAL(*(result + 0 *2+ 0), 1);
    CU_ASSERT_EQUAL(*(result + 2 *2+ 0), 3);
  
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("transponerMatrices", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testTransponerMatrices", testTransponerMatrices))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
