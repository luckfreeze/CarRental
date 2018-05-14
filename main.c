//
//  PimIV.c
//
//  Created by Lucas Moraes on 25/10/2017.
//  Copyright © 2017 Lucas Moraes. All rights reserved.
//
//  Sistema exclusivo para Legal Rent a Car

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keyWord;
int i = 0;
int numberOfClients = 0;

// Estruturas de dados que serão utilizadas para o armazenamento de carros, clientes etc
struct createClient {
    int cod;
    char name [40];
    int age;
    int cpf;
    char city [35];
    int days;
    int carCode;
};

struct createCar {
    int carCode;
    char model [20]; // modelo do carro
    char brand [15]; // marca do carro
    char board [15]; // placa do carro
    int stats; // status de devolvido o não
};

struct createClient Client[100];
struct createCar Car[100];

// Função para para cadastro de clientes \\

void createClient() {
    
    printf("* Lembre-se, Cadastro %d de 50 clientes cadastrados no Sistema\n", numberOfClients);
    printf("## Cadastro de Clientes ## \n");
    
    if (numberOfClients<50)
    {
        printf("Digite o codigo do Cliente: ");
        scanf("%d", &Client[numberOfClients].cod);
        fflush(stdin);
        
        printf("Digite o nome do Cliente: ");
        scanf("%s",Client[numberOfClients].name);
        fflush(stdin);
        
        printf("Digite a idade do Cliente: ");
        scanf("%d", &Client[numberOfClients].age);
        fflush(stdin);
        
        printf("Digite o CPF do Cliente: ");
        scanf("%d", &Client[numberOfClients].cpf);
        fflush(stdin);
        
        printf("Digite o nome da Cidade: ");
        scanf("%s",Client[numberOfClients].city);
        numberOfClients++;
    }
 
} // Fim da Função

// Função para a consulta de clientes numberOfClientsá cadastrados
void getClients() {
    int i=0;
    
    if (numberOfClients == 0) {
        printf("Não temos Clientes");
    } else {
        for(i=0; i<numberOfClients; i++) {
            
            printf("\nNome do Cliente: %s\n", Client[i].name);
            printf("\nCPF: %i\n", Client[i].cpf);
            printf("\nCarro locado: %i\n", Client[i].carCode);
            
        }
    }
    

} // Fim da Função

void getCars() {
    
    
}
// Função para ver carros disponíveis
void getCarAvailable() {
    
    for(i=0; i<100; i++)
    {
        printf("Marca do carro: %s \n", Car[i].model);
        printf("Marca do carro: %s \n", Car[i].brand);
        printf("Marca do carro: %s \n", Car[i].board);
        printf("Marca do carro: %i \n\n\n", Car[i].stats);
    };
} // Fim da Função

// Função para adicionar Carro
void addCar () {
    
    printf("* Lembre-se, Cadastro %d de 50 carros cadastrados no Sistema\n", i);
    printf("## Cadastro de Clientes ##");
    {
        printf("Digite o codigo do veiculo: ");
        scanf("%d", &Car[i].carCode);
        fflush(stdin);
        
        printf("Digite o modelo do carro: ");
        scanf("%c",Car[i].model);
        fflush(stdin);
        
        printf("Digite a marca do carro: ");
        scanf("%c",Car[i].brand); // Marca do carro
        fflush(stdin);
        
        printf("Digite a placa do carro: ");
        scanf("%c",Car[i].board); // Placa do carro
        i++;
    }

} // Fim da Função

//Função para locar veículos
void leaseCar() {
    
    int i = 0;
    int cod;
    
    int value;
    char condition;
    
    int valuePerDay = 49.30;
    int valueToPay;
    int finalValueToPay;
    
    fflush(stdin);
    
    printf("\n Digite o nome do cliente que quer locar um veículo: ");
    scanf("%d", &value);

    for(i=0; i<100; i++)
    {
        if(value == Client[i].cpf)
        {
            printf("\n Cliente cadastrado, deseja locar veículo ? S/N: ");
            scanf("%c", &condition);
            fflush(stdin);
            
            printf("Digite o número de dias que o veículo será locado");
            
            if(condition == 's')
            {
                printf("\n Digite o código do Carro: ");
                scanf("%d", &cod);
                
                valueToPay = valuePerDay * Client[i].days;
                
                if (Client[i].age < 50) {
                    finalValueToPay = valueToPay  * 0.10 / 100;
                }
                
                Client[i].carCode = cod;
                Car[i].stats= 1;
            }
        };
    };
    printf("Cliente não Cadastrado");

    
} // Fim da Função





//Função para devolução do carro
void returnCar() {
    
    int value;
    char condition;
    
    int daysLate;
  
    int valuePerDay = 49.30;
    int valueToPay;
 
    
    
    
    printf("Digite o CPF do cliente que vai devolver o veículo: ");
    scanf("%d", &value);
    for (i=0; i<100; i++)
    {
        if(value == Client[i].cpf)
        {
            
            printf("O usuário %s realizar devolução S/N? ", Client[i].name);
            scanf("%c", &condition);
            
            if (condition == 's')
            {
                
                printf("O cliente teve atraso na devolução do veículo ? Se sim quantos dias ?");
                scanf("%d", &daysLate);
                
                if (daysLate != 0) {
                    
                    valueToPay = valuePerDay * daysLate;
                    
                    
                    
                    printf("O usuário tem que pagar uma multa de %d", valueToPay);
                    
                    Client[i].carCode=0 ;
                    Car[i].stats=0;

                } else {
                    Client[i].carCode=0 ;
                    Car[i].stats=0;
                }
                
            }
        }
    }

} // Fim da Função


int main (void) {
    int option = 0;
    while(option<8)
    {
        
        printf("\n  \n\n");
        printf("\n Digite um número para começar \n");
        
        printf("1 - Cadastrar Clientes \n");
        printf("2 - Mostrar Clientes já Cadastrados \n");
        printf("3 - Cadastrar Veículos \n");
        printf("4 - Locar Veículos \n");
        printf("5 - Clientes Com Veículos Locados \n");
        printf("6 - Devolver Veículos \n");
        printf("7 - SAIR \n");
        fflush(stdin);
        scanf("%d", &option);
        switch(option)
        {
            case 1: createClient();
                break;
            case 2: getClients();
                break;
            case 3: getCarAvailable();
                break;
            case 4: addCar();
                break;
            case 5: leaseCar();
                break;
            case 6: returnCar();
                break;
            
            case 7: exit(0);
                break;
                
            default: printf("\n\n Opção invalida");
                fflush(stdin);
                while ((keyWord = getchar())!='\r')
                    break;
        }
    }
    return(0);
}

























































