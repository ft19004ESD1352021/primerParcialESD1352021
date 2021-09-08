/*
 * File:   productoMatriz.c
 * Author: joel
 *
 * Created on 8 sep. 2021, 16:19:12
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

void testProductoMatriz() {
    int matriz[3][2]={1,2,3,4,5,6};
    int pFila=3;
    int pColumna=2;
    int matriz2[2][3] = {1,2,3,4,5,6};
    int sFila=2;
    int sColumna=3;
    int *result = productoMatriz(&matriz[0][0], pFila, pColumna, &matriz2[0][0], sFila, sColumna);
       
    CU_ASSERT_EQUAL(*(result + 0 *3+ 0), 9);
    CU_ASSERT_EQUAL(*(result + 1 *3+ 1), 26);
    CU_ASSERT_EQUAL(*(result + 2 *3+ 2), 51);
  
     int matriz1[2][2]={1,2,3,4};
    int Fila=2;
    int Columna=2;
    int matriz3[2][3] = {1,2,3,4,5,6};
    int sila=2;
    int solumna=3;
    int *result2 = productoMatriz(&matriz1[0][0], Fila, Columna, &matriz3[0][0], sila, solumna);
      if(result2 == 0){
        CU_PASS("PASS");
    }
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("productoMatriz", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testProductoMatriz", testProductoMatriz))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
