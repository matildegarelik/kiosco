---------------------------------INTRODUCCIÓN----------------------------------
Programa desarollado por estudiantes de la Universidad del Litoral - Ingeniería 
en Informática, para la materia Programación Orientada a Objetos.
Este programa tiene por objetivo llevar a cabo la gestión de un Quiosco, imple-
mentando una pequeña base de datos basada en la utilización de archivos binarios
y archivos de texto. Tiene funcionalidades como el manejo de productos que se
realiza dentro del quiosco y el control de su stock, listar las personas que 
realizan las compras, ya sea pagando en el momento o fiando, además de gestionar
los pedidos e ingreso de mercadería y permitir consultas al historial de ventas.


--------------------------------VENTANA PRODUCTOS--------------------------------
Esta es la ventana de bienvenida al programa. Tiene por función Agregar Nuevos 
Productos detallando cada uno de las características del producto, Nombre del 
Producto - Marca - Tipo - Código - Stock - Precio.
Además de eso tiene funcionalidades de Actualizar el Stock y el Precio de un 
determinado Producto o incluso Eliminarlo.
Tiene funciones de Ayudas Visuales como Buscar un determinado producto por Có-
digo, Nombre y/o Tipo. También se puede Organizar la lista de productos de for-
ma tal que se ordenen en forma Descendente según el argumento elegido. Cuenta 
con Accesos Directos a otras Ventanas del Programa.


--------------------------------VENTANA VENTAS--------------------------------
En esta Ventana se gestionan las ventas realizadas por el Usuario. Se ingresa 
el Código y la Cantidad de productos que se van a vender, estos productos gene-
ran una lista que luego el Usuario indica si la compra se paga en el momento o 
se fia. 


------------------------------VENTANA HACER PEDIDO------------------------------
Es la encargada de generar un archivo .txt con los productos que se cargaron en
la lista para poder realizar un pedido de Productos. Se pueden ingresar produc-
tos mediantes su Código o seleccionandolos en el menú desplegable.



-------------------------------VENTANA INGRESO STOCK-------------------------------
En esta ventana se modifica el Stock de Productos que hay en el Quiosco, se in-
gresa el Código y la Cantidad, y se modifica la cantidad de productos disponi-
bles. Se guarda una lista de todas los Ingresos de Stock que se realizaron.



---------------------------------VENTANA FIADOS--------------------------------
En esta ventana se guardan las personas que a la hora de comprar eligieron la 
opción de fiar, se les guarda el nombre del cliente, la fecha y el total que de
ben. La última columna tiene la opción de eliminar el cliente si este ya pagó.


----------------------------VENTANA CONSULTAS HISTORIAL----------------------------
Esta ventana está encargada de mostrar el historial de los Productos más vendi-
dos, las Últimas Ventas, las Ventas por Producto, las Ventas por Cliente y los
Detalles de las Facturas. Dependiendo la opción elegida permite buscar qué términos queremos encontrar.
