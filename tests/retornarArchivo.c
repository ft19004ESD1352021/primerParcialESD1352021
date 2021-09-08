/*
 * File:   retornarArchivo.c
 * Author: joel
 *
 * Created on 8 sep. 2021, 13:06:41
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

void testRetornarArchivo() {
    
    char* path="peliculasFavoritasESD135_2021.csv";
    char* pathio="peliculas";
    cambio* result = retornarArchivo(path);
    
    CU_ASSERT_PTR_NOT_NULL(result);
    
    CU_ASSERT_STRING_EQUAL(*(result+9*7+0),"lr19047");
    CU_ASSERT_STRING_EQUAL(*(result+15*7+0),"ft19004");
    CU_ASSERT_STRING_EQUAL(*(result+59*7+6),"0\0");
    CU_ASSERT_STRING_EQUAL(*(result+15*7+6),"1\n");
    CU_ASSERT_STRING_EQUAL(*(result+9*7+6),"1\n");
     
    cambio* resultado = retornarArchivo(pathio);
    CU_ASSERT_TRUE(resultado==NULL);
   
}
int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("retornarArchivo", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testRetornarArchivo", testRetornarArchivo))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
