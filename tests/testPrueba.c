/*
 * File:   testPrueba.c
 * Author: qwerty
 *
 * Created on 6 sep. 2021, 19:07:39
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "cabecera.h"

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
    char* Path;
    int* result = generarMatriz(Path);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testTransponerMatrices() {
    int* matriz;
    int filas;
    int columnas;
    int* result = transponerMatrices(matriz, filas, columnas);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testMultiplyMatrices() {
    int* primerMatriz;
    int pFila;
    int pColumna;
    int* segundaMatriz;
    int sFila;
    int sColumna;
    int* result = multiplyMatrices(primerMatriz, pFila, pColumna, segundaMatriz, sFila, sColumna);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testIntegrantes() {
    const char* result = integrantes();
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

void testLeer() {
    char* Path;
    char* result = leer(Path);
    if (1 /*check result*/) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("testPrueba", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testGenerarMatriz", testGenerarMatriz)) ||
            (NULL == CU_add_test(pSuite, "testTransponerMatrices", testTransponerMatrices)) ||
            (NULL == CU_add_test(pSuite, "testMultiplyMatrices", testMultiplyMatrices)) ||
            (NULL == CU_add_test(pSuite, "testIntegrantes", testIntegrantes)) ||
            (NULL == CU_add_test(pSuite, "testLeer", testLeer))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
