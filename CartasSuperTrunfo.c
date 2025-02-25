#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pt_br

typedef struct card {
    char *state;
    char *code;
    char *city_name;
    int population;
    float area;
    float pib;
    int locations;
    float density;
    float pib_per_capita;
    struct card *next;
    struct card *before;
} Card;

enum Sections {
    state,
    code,
    city_name,
    population,
    area,
    pib,
    locations
};

/*@Description: create translations for texts                   */
/* to ask users to insert information                           */
/*@param: enum to hold data topics                              */
/*@return: none                                                 */
void translations_insert(enum Sections sections);
/*@Description: create translation to print card                */
/* information.                                                 */
/*@param: enum to hold data topics                              */
/*@return: none                                                 */
void translations_print(enum Sections sections,
    char *value);
/*@Description:                                                 */
/*@param: none                                                  */
/*@return: none                                                 */
void translations_card_number(int actual,
    int total);
/*@Description: create a struct to handle the card              */
/*@param: none                                                  */
/*@return: pointer to struct                                    */
Card *create();
/*@Description: get values from stdin                           */
/*@param: card pointer                                          */
/*@return: none                                                 */
void get_card(Card *card);
/*@Description: print information from car                      */
/*@param: card pointer                                          */
/*@return: none                                                 */
void print_card_infos(Card *card);
/*@Description: delete struct to handle the card                */
/*@param: card pointer                                          */
/*@return: none                                                 */
void delete_card(Card *card);
/*@Description: delete struct to handle the card                */
/*@param: card pointer                                          */
/*@return: none                                                 */
void remove_new_line(char* string);
/*@Description: convert a float value to string                 */
/*@param: value to convert                                      */
/*@return: string                                               */
char *convert_float_to_string(float value);
/*@Description: convert an integer value to string              */
/*@param: value to convert                                      */
/*@return: string                                               */
char *convert_int_to_string(int value);

int main(int argc, char const *argv[]) {
    Card *card_one = create();
    Card *card_two = create();

    get_card(card_one);
    getchar();
    get_card(card_two);

    translations_card_number(1, 2);
    print_card_infos(card_one);
    translations_card_number(2, 2);
    print_card_infos(card_two);

    delete_card(card_one);
    delete_card(card_two);

    return 0;
}

Card *create() {
    Card *card = (Card *)calloc(1, sizeof(Card));
    return card;
}

void get_card(Card *card) {
    size_t len;

    printf("\n");
    translations_insert(state);
    getline(&card->state, &len, stdin);
    remove_new_line(card->state);

    translations_insert(code);
    getline(&card->code, &len, stdin);
    remove_new_line(card->code);

    translations_insert(city_name);
    getline(&card->city_name, &len, stdin);
    remove_new_line(card->city_name);

    translations_insert(population);
    scanf("%d", &card->population);

    translations_insert(area);
    scanf("%f", &card->area);

    translations_insert(pib);
    scanf("%f", &card->pib);

    translations_insert(locations);
    scanf("%d", &card->locations);
}

void print_card_infos(Card *card) {
    translations_print(state, card->state);
    translations_print(code, card->code);
    translations_print(city_name, card->city_name);
    translations_print(population, convert_int_to_string(card->population));
    translations_print(area, convert_float_to_string(card->area));
    translations_print(pib, convert_float_to_string(card->pib));
    translations_print(locations, convert_int_to_string(card->locations));
}

void translations_insert(enum Sections sections) {
    switch (sections) {
        case state:
            #ifdef en
                printf("Insert state and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira o estado e aperte enter: ");
            #endif
            break;

        case code:
            #ifdef en
                printf("Insert code and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira o código e aperte enter: ");
            #endif
            break;

        case city_name:
            #ifdef en
                printf("Insert the city name and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira o nome da cidade e aperte enter: ");
            #endif
            break;

        case population:
            #ifdef en
                printf("Insert population[billions] and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira a populacao[bilhoes] e aperte enter: ");
            #endif
            break;

        case area:
            #ifdef en
                printf("Insert area[km square] and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira a area[km quadrado] e aperte enter: ");
            #endif
            break;

        case pib:
            #ifdef en
                printf("Insert pib and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira o pib e aperte enter: ");
            #endif
            break;

        case locations:
            #ifdef en
                printf("Insert locations and press enter: ");
            #endif

            #ifdef pt_br
                printf("Insira os pontos turísticos e aperte enter: ");
            #endif
            break;

    }
}

void translations_print(enum Sections sections, char *value) {
    switch (sections) {
        case state:
            #ifdef en
                printf("\nState: %s\n", value);
            #endif

            #ifdef pt_br
                printf("\nEstado: %s\n", value);
            #endif
            break;

        case code:
            #ifdef en
                printf("Code: %s\n", value);
            #endif

            #ifdef pt_br
                printf("Codigo: %s\n", value);
            #endif
            break;

        case city_name:
            #ifdef en
                printf("City name: %s\n", value);
            #endif

            #ifdef pt_br
                printf("Nome da Cidade: %s\n", value);
            #endif
            break;

        case population:
            #ifdef en
                printf("Population: %s people\n", value);
            #endif

            #ifdef pt_br
                printf("Populacao: %s habitantes\n", value);
            #endif
            break;

        case area:
            #ifdef en
                printf("Area: %s km square\n", value);
            #endif

            #ifdef pt_br
                printf("Area: %s km quadrado\n", value);
            #endif
            break;

        case pib:
            #ifdef en
                printf("GDB: %s billions dollar\n", value);
            #endif

            #ifdef pt_br
                printf("PIB: %s bilhoes de reais\n", value);
            #endif
            break;

        case locations:
            #ifdef en
                printf("Locations: %s\n", value);
            #endif

            #ifdef pt_br
                printf("Numero de Pontos Turísticos: %s\n", value);
            #endif
            break;
    }
}

void translations_card_number(int actual, int total) {
    #ifdef en
        printf("\nCard %d of %d", actual, total);
    #endif

    #ifdef pt_br
        printf("\nCarta %d de %d", actual, total);
    #endif
}

void delete_card(Card *card) {
    free(card->state);
    free(card->code);
    free(card->city_name);
    free(card);
}

void remove_new_line(char* string) {
    *(string + (strlen(string) - 1)) = '\0';
}

char *convert_float_to_string(float value) {
    int length = snprintf( NULL, 0, "%.2f", value );
    char* string = malloc( length + 1 );
    snprintf(string , length + 1, "%.2f", value );
    return string;
}

char *convert_int_to_string(int value) {
    int length = snprintf( NULL, 0, "%d", value );
    char* string = malloc( length + 1 );
    snprintf(string , length + 1, "%d", value );
    return string;
}
