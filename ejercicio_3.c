#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto
{
	int productoID;
	int cantidad;
	char *tipoProducto;
	float precioUnitario;
}typedef Producto;

struct Cliente
{
	int ClienteID;
	char *nombreCliente;
	int cantidadProductosAPedir;
	Producto *productos;
}typedef Cliente;

int main(){

	Cliente *cliente;
	char *tipoProducto = {"Caramelos","Detergente","Gaseosa","Snaks","Cerveza","Vino","Carne","Adereso"};
	int numeroClientes;
	printf("Indique la cantidad de clientes: ");
	scanf("%d", &numeroClientes);

	cliente = (Cliente*)malloc(sizeof(Cliente*)* numeroClientes);

	srand(time(NULL));

	for (int i = 0; i < numeroClientes; i++)
	{
		printf("\nEl nombre %d es: %s",i+1, cliente[i].nombreCliente);
		free(cliente[i].nombreCliente);
	}
	
	free(cliente);
	return 0;
}

void cargarClientes(Cliente *cliente, char *tipoProductos, int cantidad)
{
	char *buff;
	buff = (char*)malloc(sizeof(char)*100);
	for (int i = 0; i < cantidad; i++)
	{
		cliente[i].ClienteID = i + 1;
		printf("Indique el nombre del cliente %d: ",i+1);
		gets(buff);
		cliente[i].nombreCliente = (char*)malloc(sizeof(char)*(strlen(buff)+1));
		strcpy(cliente[i].nombreCliente, buff);

		cliente[i].cantidadProductosAPedir = rand() % 7 + 1;
		cliente[i].productos = (Producto*)malloc(sizeof(Producto*)*(cliente[i].cantidadProductosAPedir));
		for (int j = 0; j < cliente[i].cantidadProductosAPedir; j++)
		{
			cliente[i].productos[j].productoID = j + 1;
			cliente[i].productos[j].cantidad = rand() % 4 + 1;
			cliente[i].productos[j].tipoProducto = (char*)malloc(sizeof(char)*(strlen(tipoProductos[rand()%7]+1)));
			strcpy(cliente[i].productos[j].tipoProducto, tipoProductos[rand()%5]);
			cliente[i].productos[j].precioUnitario = rand() % 99 + 1;
		} 		
	}
}