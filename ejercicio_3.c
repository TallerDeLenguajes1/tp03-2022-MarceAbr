#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

	Cliente cliente;
	char *buff;
	int numeroClientes;

	printf("Indique la cantidad de clientes: ");
	scanf("%d", &numeroClientes);

	buff = (char *) malloc(numeroClientes*sizeof(char));

	for (int i = 0; i < numeroClientes; i++)
	{
		cliente.nombreCliente[i] = (char *) malloc((strlen(buff)+1)*sizeof(char));
		strcpy(cliente.nombreCliente[i], buff);
	}

	for (int i = 0; i < numeroClientes; i++)
	{
		printf("\nEl nombre %d es: %s",i+1, cliente.nombreCliente[i]);
		free(cliente.nombreCliente[i]);
	}
	

	free(buff);

	return 0;
}