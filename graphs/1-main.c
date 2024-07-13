#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;

    graph = graph_create();
    if (!graph)
    {
        fprintf(stderr, "Failed to create graph\n");
        return (EXIT_FAILURE);
    }

    /* if (!graph_add_vertex(graph, "San Francisco"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    } */

    graph_display(graph);

    if (/* !graph_add_vertex(graph, "Seattle") ||
        !graph_add_vertex(graph, "New York") ||
        !graph_add_vertex(graph, "Miami") ||
        !graph_add_vertex(graph, "Chicago") ||
        !graph_add_vertex(graph, "Houston") ||
        !graph_add_vertex(graph, "Las Vegas") ||
        !graph_add_vertex(graph, "Boston") || */
        !graph_add_vertex(graph, "Abel") ||
        !graph_add_vertex(graph, "Adrienne") ||
        !graph_add_vertex(graph, "Alberta") ||
        !graph_add_vertex(graph, "Alejandro") ||
        !graph_add_vertex(graph, "Allan") ||
        !graph_add_vertex(graph, "Andrew") ||
        !graph_add_vertex(graph, "Angie") ||
        !graph_add_vertex(graph, "Annie") ||
        !graph_add_vertex(graph, "Antonia") ||
        !graph_add_vertex(graph, "Audrey") ||
        !graph_add_vertex(graph, "Bennie") ||
        !graph_add_vertex(graph, "Bethany") ||
        !graph_add_vertex(graph, "Bill") ||
        !graph_add_vertex(graph, "Bobby") ||
        !graph_add_vertex(graph, "Brett") ||
        !graph_add_vertex(graph, "Bruce") ||
        !graph_add_vertex(graph, "Carol") ||
        !graph_add_vertex(graph, "Cary") ||
        !graph_add_vertex(graph, "Casey") ||
        !graph_add_vertex(graph, "Cesar") ||
        !graph_add_vertex(graph, "Christina") ||
        !graph_add_vertex(graph, "Cindy") ||
        !graph_add_vertex(graph, "Claire") ||
        !graph_add_vertex(graph, "Courtney") ||
        !graph_add_vertex(graph, "Curtis") ||
        !graph_add_vertex(graph, "Dan") ||
        !graph_add_vertex(graph, "Daniel") ||
        !graph_add_vertex(graph, "Darrell") ||
        !graph_add_vertex(graph, "Denise") ||
        !graph_add_vertex(graph, "Don") ||
        !graph_add_vertex(graph, "Dora") ||
        !graph_add_vertex(graph, "Doyle") ||
        !graph_add_vertex(graph, "Dwayne") ||
        !graph_add_vertex(graph, "Ebony") ||
        !graph_add_vertex(graph, "Edith") ||
        !graph_add_vertex(graph, "Edward") ||
        !graph_add_vertex(graph, "Elaine") ||
        !graph_add_vertex(graph, "Ella") ||
        !graph_add_vertex(graph, "Elmer") ||
        !graph_add_vertex(graph, "Elsa") ||
        !graph_add_vertex(graph, "Emma") ||
        !graph_add_vertex(graph, "Emmett") ||
        !graph_add_vertex(graph, "Erick") ||
        !graph_add_vertex(graph, "Erma") ||
        !graph_add_vertex(graph, "Estelle") ||
        !graph_add_vertex(graph, "Esther") ||
        !graph_add_vertex(graph, "Eunice") ||
        !graph_add_vertex(graph, "Eva") ||
        !graph_add_vertex(graph, "Everett") ||
        !graph_add_vertex(graph, "Flora") ||
        !graph_add_vertex(graph, "Frank") ||
        !graph_add_vertex(graph, "Fred") ||
        !graph_add_vertex(graph, "Freddie") ||
        !graph_add_vertex(graph, "Gabriel") ||
        !graph_add_vertex(graph, "Gail") ||
        !graph_add_vertex(graph, "Gene") ||
        !graph_add_vertex(graph, "Genevieve") ||
        !graph_add_vertex(graph, "Geoffrey") ||
        !graph_add_vertex(graph, "Gertrude") ||
        !graph_add_vertex(graph, "Gilbert") ||
        !graph_add_vertex(graph, "Gilberto") ||
        !graph_add_vertex(graph, "Ginger") ||
        !graph_add_vertex(graph, "Glen") ||
        !graph_add_vertex(graph, "Grady") ||
        !graph_add_vertex(graph, "Grant") ||
        !graph_add_vertex(graph, "Guadalupe") ||
        !graph_add_vertex(graph, "Guillaume") ||
        !graph_add_vertex(graph, "Guillermo") ||
        !graph_add_vertex(graph, "Hazel") ||
        !graph_add_vertex(graph, "Heather") ||
        !graph_add_vertex(graph, "Heidi") ||
        !graph_add_vertex(graph, "Henrietta") ||
        !graph_add_vertex(graph, "Hope") ||
        !graph_add_vertex(graph, "Howard") ||
        !graph_add_vertex(graph, "Ignacio") ||
        !graph_add_vertex(graph, "Ivan") ||
        !graph_add_vertex(graph, "Jacqueline") ||
        !graph_add_vertex(graph, "Jaime") ||
        !graph_add_vertex(graph, "Jake") ||
        !graph_add_vertex(graph, "Jamie") ||
        !graph_add_vertex(graph, "Javier") ||
        !graph_add_vertex(graph, "Jeffery") ||
        !graph_add_vertex(graph, "Jenna") ||
        !graph_add_vertex(graph, "Jennie") ||
        !graph_add_vertex(graph, "Jenny") ||
        !graph_add_vertex(graph, "Jerome") ||
        !graph_add_vertex(graph, "Jesse") ||
        !graph_add_vertex(graph, "Jessie") ||
        !graph_add_vertex(graph, "Jimmie") ||
        !graph_add_vertex(graph, "Joann") ||
        !graph_add_vertex(graph, "Joanna") ||
        !graph_add_vertex(graph, "Johnnie") ||
        !graph_add_vertex(graph, "Jon") ||
        !graph_add_vertex(graph, "Josephine") ||
        !graph_add_vertex(graph, "Josh") ||
        !graph_add_vertex(graph, "Juana") ||
        !graph_add_vertex(graph, "Julien") ||
        !graph_add_vertex(graph, "June") ||
        !graph_add_vertex(graph, "Justin") ||
        !graph_add_vertex(graph, "Karen") ||
        !graph_add_vertex(graph, "Karl") ||
        !graph_add_vertex(graph, "Karla") ||
        !graph_add_vertex(graph, "Katherine") ||
        !graph_add_vertex(graph, "Katrina") ||
        !graph_add_vertex(graph, "Kellie") ||
        !graph_add_vertex(graph, "Ken") ||
        !graph_add_vertex(graph, "Kenny") ||
        !graph_add_vertex(graph, "Kerry") ||
        !graph_add_vertex(graph, "Kimberly") ||
        !graph_add_vertex(graph, "Kristy") ||
        !graph_add_vertex(graph, "Lana") ||
        !graph_add_vertex(graph, "Lance") ||
        !graph_add_vertex(graph, "Leah") ||
        !graph_add_vertex(graph, "Leonard") ||
        !graph_add_vertex(graph, "Lillie") ||
        !graph_add_vertex(graph, "Lloyd") ||
        !graph_add_vertex(graph, "Loren") ||
        !graph_add_vertex(graph, "Lorene") ||
        !graph_add_vertex(graph, "Lowell") ||
        !graph_add_vertex(graph, "Lucille") ||
        !graph_add_vertex(graph, "Luke") ||
        !graph_add_vertex(graph, "Luther") ||
        !graph_add_vertex(graph, "Luz") ||
        !graph_add_vertex(graph, "Madeline") ||
        !graph_add_vertex(graph, "Malcolm") ||
        !graph_add_vertex(graph, "Mandy") ||
        !graph_add_vertex(graph, "Marcella") ||
        !graph_add_vertex(graph, "Marguerite") ||
        !graph_add_vertex(graph, "Marianne") ||
        !graph_add_vertex(graph, "Marie") ||
        !graph_add_vertex(graph, "Marion") ||
        !graph_add_vertex(graph, "Marshall") ||
        !graph_add_vertex(graph, "Marta") ||
        !graph_add_vertex(graph, "Marty") ||
        !graph_add_vertex(graph, "Maryann") ||
        !graph_add_vertex(graph, "Megan") ||
        !graph_add_vertex(graph, "Melanie") ||
        !graph_add_vertex(graph, "Melody") ||
        !graph_add_vertex(graph, "Melvin") ||
        !graph_add_vertex(graph, "Meredith") ||
        !graph_add_vertex(graph, "Merle") ||
        !graph_add_vertex(graph, "Michele") ||
        !graph_add_vertex(graph, "Michelle") ||
        !graph_add_vertex(graph, "Mindy") ||
        !graph_add_vertex(graph, "Miriam") ||
        !graph_add_vertex(graph, "Mitchell") ||
        !graph_add_vertex(graph, "Muriel") ||
        !graph_add_vertex(graph, "Myra") ||
        !graph_add_vertex(graph, "Neal") ||
        !graph_add_vertex(graph, "Nicolas") ||
        !graph_add_vertex(graph, "Oliver") ||
        !graph_add_vertex(graph, "Omar") ||
        !graph_add_vertex(graph, "Pat") ||
        !graph_add_vertex(graph, "Patrick") ||
        !graph_add_vertex(graph, "Patti") ||
        !graph_add_vertex(graph, "Paula") ||
        !graph_add_vertex(graph, "Phil") ||
        !graph_add_vertex(graph, "Rafael") ||
        !graph_add_vertex(graph, "Ramona") ||
        !graph_add_vertex(graph, "Randy") ||
        !graph_add_vertex(graph, "Renee") ||
        !graph_add_vertex(graph, "Rickey") ||
        !graph_add_vertex(graph, "Roger") ||
        !graph_add_vertex(graph, "Roman") ||
        !graph_add_vertex(graph, "Rose") ||
        !graph_add_vertex(graph, "Ross") ||
        !graph_add_vertex(graph, "Ruby") ||
        !graph_add_vertex(graph, "Rudolph") ||
        !graph_add_vertex(graph, "Sabrina") ||
        !graph_add_vertex(graph, "Sam") ||
        !graph_add_vertex(graph, "Samantha") ||
        !graph_add_vertex(graph, "Saul") ||
        !graph_add_vertex(graph, "Shawna") ||
        !graph_add_vertex(graph, "Shirley") ||
        !graph_add_vertex(graph, "Simon") ||
        !graph_add_vertex(graph, "Spencer") ||
        !graph_add_vertex(graph, "Stanley") ||
        !graph_add_vertex(graph, "Stephanie") ||
        !graph_add_vertex(graph, "Stephen") ||
        !graph_add_vertex(graph, "Steven") ||
        !graph_add_vertex(graph, "Suzanne") ||
        !graph_add_vertex(graph, "Tamara") ||
        !graph_add_vertex(graph, "Tammy") ||
        !graph_add_vertex(graph, "Teri") ||
        !graph_add_vertex(graph, "Thelma") ||
        !graph_add_vertex(graph, "Theodore") ||
        !graph_add_vertex(graph, "Thomas") ||
        !graph_add_vertex(graph, "Timmy") ||
        !graph_add_vertex(graph, "Tomas") ||
        !graph_add_vertex(graph, "Tony") ||
        !graph_add_vertex(graph, "Tonya") ||
        !graph_add_vertex(graph, "Travis") ||
        !graph_add_vertex(graph, "Trevor") ||
        !graph_add_vertex(graph, "Valerie") ||
        !graph_add_vertex(graph, "Vincent") ||
        !graph_add_vertex(graph, "Virgil") ||
        !graph_add_vertex(graph, "Wade") ||
        !graph_add_vertex(graph, "Wallace") ||
        !graph_add_vertex(graph, "Wesley") ||
        !graph_add_vertex(graph, "Willie"))
    {
        fprintf(stderr, "Failed to add vertex\n");
        return (EXIT_FAILURE);
    }

    graph_display(graph);

    /* if (!graph_add_vertex(graph, "San Francisco")) */
    if (!graph_add_vertex(graph, "Willie"))
        fprintf(stderr, "Failed to add \"Willie\"\n");

    return (EXIT_SUCCESS);
}
