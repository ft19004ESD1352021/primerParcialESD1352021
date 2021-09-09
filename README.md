# primerParcialESD1352021 

## Estudiantes
### FUENTES TRIGUEROS, JOEL EDUARDO 
### LOBATO ROMERO, CARLOS LUIS 
## CODIGO DE PRUEBA ESTE VA EN EL MAIN (este codigo solo fue creado para pruebas)
# PATH = "peliculasFavoritasESD135_2021.csv";
## En el archivo funciones.c esta dinamico


‘‘‘char *PATH = "peliculasFavoritasESD135_2021.csv";
    
   cambio *puntero= retornarArchivo(PATH);
    
    printf("\n\n-----------------------PRIMERA FUNCION----------------------\n\n");
            
   for (int j = 0; j < 60; j++) {
        for (int x = 0; x < 7; x++) {
            printf("%s ", *(puntero+j*7+x));
        }
        puts("");
    }

     printf("\n\n-----------------------SEGUNDA FUNCION----------------------\n\n");
    int *g;
    g = generarMatriz(PATH); //59x6
    for (int i = 0; i < 59; i++) {
        int j;
        for (j = 0; j < 6; j++) {

            printf("[%d],", *(g + i * 6 + j));
        }
        puts("");
    }
    printf("\n\n-----------------------TERCERA PARTE----------------------\n\n");
    int *t;
    t = transponerMatrices(g, 59, 6); //6x59
    for (int i = 0; i < 6; i++) {
        int j;
        for (int j = 0; j < 59; j++) {

            printf("[%d],", *(t + i * 59 + j));
            

        }
        puts("");
    }
    
    
    
    printf("\n\n-----------------------CUARTA FUNCION----------------------\n\n");
    int *punte; 
    punte = productoMatriz(generarMatriz(PATH), 59, 6, transponerMatrices(g, 59, 6), 6, 59);
    //punte= multiplyMatrices(&numeros[0][0], 3, 3, &numeros2[0][0], 3, 2);

    int q;
    for (q = 0; q < 59; q++) {
        int m;
        for (m = 0; m < 59; m++) {

            printf("[%d]", *(punte + q * 59 + m));
            

        }
        puts("");
    }
    
    printf("\n\n-----------------------QUINTA FUNCION----------------------\n\n");

    
    printf("%s",integrantes());
‘‘‘