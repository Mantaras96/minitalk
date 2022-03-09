<h1 align="center">Project n°4 - Minitalk
   <h4 align="center" style="width: 100%; margin: 2rem auto; font-weight: normal;">
   Crear un programa donde un cliente pueda enviar un mensaje mediante 2 señales y este muestre el mensaje
   </h4>
</h1>

<h4> Descripción </h4>
Necesitamos crear 2 ejecutables:

- Servidor: Cuando lo ejecutemos mostrará su Pid (Identificador de proceso).


- Cliente: Cuando lo ejecutemos necesitaremos enviarle 2 argumentos el pid del servidor y el mensaje que queremos mostar

```bash
 ./client "pid" "string"
```

<h4> Cliente </h4>

Lo primero que hacemos en nuestro cliente es comprobar que el número de argumentos es
correcto:
- El pid es numérico
- El mensaje a enviar no está vacío
- El número de argumentos son 3

Una vez validado ya estamos listos para trabajar con nuestra string. Como solo podemos usar
2 señales enviaremos nuestros caracteres en binario.

Para transformar un char a binario:

Para pasar un numero decimal a binario lo que necesitamos es dividir nuestro número entre 2 y nos quedamos con el residuo.
![Decimal to binari](./img/decimal_bin.jpeg)

Por cada char enviaremos una string de 8 números. Una vez tengamos todos los caracteres transformados a binario
recorreremos la string enviado las señales.
- SIGSUR1: Cuando el valor a enviar sea "1".
- SIGSUR2: Cuando el valor a enviar sea "0".

<h4> Servidor </h4>

Nuestro servidor irá recibiendo estas señales y cada 8 transformaremos los binarios en número decimal.

![Decimal to binari](./img/bin_decimal.jpeg)

Iremos mostrando todos nuestros caracteres de forma progresiva.

Hay que tener en cuenta que como el servidor es el primero en iniciarse hay que dejarlo en pausa
para que lleguen las señales esto lo hacemos con una condición que siempre se cumpla
y la función pause:

	while (1)
	{
		pause();
	}

##
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)


