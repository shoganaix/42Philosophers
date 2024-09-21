/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoriano <msoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:11:04 by msoriano          #+#    #+#             */
/*   Updated: 2024/08/20 18:36:03 by msoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

#define NUM_THREADS 7

void *routine(void *arg)
{
    //EL ARGUMENTO QUE LE HEMOS PASADO EN PTHREAD TIENE QUE SER CASTEADO   
    int id = *(int *)arg;

    //ASIGNAMOS UNA PALABRA A CADA VEZ, DE MANERA QUE SE ASIGNA UNA NUEVA CADA VEZ QUE CREEMOS UN NUEVO HILO
    const char *message[] = { "This", "is", "a", "really", "long", "string", "!" };

    int i = id;

    //CREAMOS UN BUCLE QUE SE EJECUTE TANTAS VECES COMO PALABRAS//HILOS HAYA
    while (i < NUM_THREADS)
    {
        printf("%d : %s\n", id, message[i]);
        break;
    }
    return NULL;
}
int main(int argc, char **argv)
{
    (void)argc;
    (void)**argv;
    int   i;

    //INICIALIZAMOS NUESTROS HILOS

    pthread_t threads[NUM_THREADS];
    int id[NUM_THREADS];

    //UN BUCLE QE SE LLAMA TANTAS VECES COMO FILOSOFOS HAYA
    // EN ESTE BUCLE LE ASIGNAMOS A CADA FILOSOFO SU ID 
    // TAMBIEN LOS CREAMOS UTILIZANDO PTHREAD_CREATE: (If successful,returns 0)

    // int pthread_create(pthread_t *restrict thread,                       -> pointer to our pthread
                          //const pthread_attr_t *restrict attr,            -> attribute (NULL) and sets default
                          //void *(*start_routine)(void *),                 -> function(pointer if you want to pass it as an argument) that executes
                          //void *restrict arg);                            -> argument to the function

    // EN ESTE BUCLE TAMBIÉN UTILIZAMOS PTHREAD_JOIN, ESTE ESPERA A QUE NUESTRO HILO PASADO TERMINE
    // PTHREAD_JOIN: (If successful,returns 0)

    //int pthread_join (pthread_t thread,                                       -> Our pthread
                        //void **status);                                       -> DOUBLE POINTER, return value of our function/ NULL, if we dont want value
    

    i = 0;
    while (i < NUM_THREADS)
    {
        id[i] = i;       
        pthread_create(&threads[i], NULL, routine, &id[i]);
        pthread_join(threads[i], NULL);

        i++;
    }
    printf("All threads finished!\n");
    return 0;
}