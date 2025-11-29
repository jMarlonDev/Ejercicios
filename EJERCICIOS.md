# 🎓 Taller de Objetos - Ejercicios sobre Getters, Setters y Herencia

## Nivel 1️⃣: Getters y Setters

### Ejercicio 1.1: Clase Vehículo

Crea una clase `Vehículo` con los siguientes atributos **privados**:

- `marca` (string)
- `modelo` (string)
- `año` (int)
- `velocidadMaxima` (double)

**Requisitos:**

- ✅ Constructor que inicialice todos los atributos
- ✅ Getters para todos los atributos
- ✅ Setters para todos los atributos con validaciones:
  - El año debe ser mayor a 1886 (primer vehículo motorizado)
  - La velocidad máxima debe ser positiva
- ✅ Método `mostrarInfo()` que imprima todos los datos
- ✅ Método `acelerar(double incremento)` que aumente la velocidad máxima

**Ejemplo de uso esperado:**

```
Vehículo auto("Toyota", "Corolla", 2023, 180);
auto.mostrarInfo();
auto.acelerar(20);
auto.mostrarInfo();
```

---

### Ejercicio 1.2: Clase Producto

Crea una clase `Producto` para una tienda con:

- `codigo` (string)
- `nombre` (string)
- `precio` (double)
- `cantidad` (int)

**Requisitos:**

- ✅ Constructor inicializador
- ✅ Getters y Setters con validaciones:
  - Precio no puede ser negativo
  - Cantidad no puede ser negativa
- ✅ Método `calcularValorTotal()` que retorne precio × cantidad
- ✅ Método `aplicarDescuento(double porcentaje)` que reduzca el precio
- ✅ Método `mostrarInfo()` que muestre todos los datos

**Ejemplo de uso:**

```
Producto laptop("001", "Laptop HP", 850.00, 5);
laptop.mostrarInfo();
cout << "Valor total: $" << laptop.calcularValorTotal() << endl;
laptop.aplicarDescuento(10); // 10% de descuento
laptop.mostrarInfo();
```

---

## Nivel 2️⃣: Herencia Simple

### Ejercicio 2.1: Vehículos (Auto y Motocicleta)

Partiendo de la clase `Vehículo` del Ejercicio 1.1, crea dos clases derivadas:

#### Clase `Auto` hereda de `Vehículo`

Atributos adicionales:

- `numeroPuertas` (int)
- `tipoCombustible` (string)

Métodos:

- Constructor
- Getters y Setters
- `mostrarInfo()` sobrescrito (override)

#### Clase `Motocicleta` hereda de `Vehículo`

Atributos adicionales:

- `tieneAlarón` (bool)
- `cilindrada` (int)

Métodos:

- Constructor
- Getters y Setters
- `mostrarInfo()` sobrescrito (override)

**Ejemplo de uso:**

```
Auto miAuto("Ford", "Mustang", 2023, 220, 4, "Gasolina");
Motocicleta miMoto("Harley-Davidson", "Sportster", 2023, 200, true, 1200);

miAuto.mostrarInfo();
miMoto.mostrarInfo();
```

---

### Ejercicio 2.2: Sistema de Empleados

Crea una clase base `Empleado` con:

- `nombreCompleto` (string)
- `numeroEmpleado` (string)
- `salarioBase` (double)

Crea dos clases derivadas:

#### Clase `EmpleadoTiempoCompleto` hereda de `Empleado`

Atributos:

- `beneficios` (string)
- `bono` (double)

Métodos:

- `calcularSalarioTotal()` → salarioBase + bono
- `mostrarInfo()` sobrescrito

#### Clase `EmpleadoPorHoras` hereda de `Empleado`

Atributos:

- `horasTrabajadas` (int)
- `tarifaPorHora` (double)

Métodos:

- `calcularSalarioTotal()` → horasTrabajadas × tarifaPorHora
- `mostrarInfo()` sobrescrito

**Ejemplo de uso:**

```
EmpleadoTiempoCompleto emp1("Juan López", "001", 2000, "Seguro médico", 500);
EmpleadoPorHoras emp2("María García", "002", 0, 40, 15);

emp1.mostrarInfo();
cout << "Salario: $" << emp1.calcularSalarioTotal() << endl;

emp2.mostrarInfo();
cout << "Salario: $" << emp2.calcularSalarioTotal() << endl;
```

---

## Nivel 3️⃣: Herencia Multinivel

### Ejercicio 3.1: Jerarquía de Animales

Crea la siguiente jerarquía:

```
        Животное (Animal)
           /        \
       Mamífero    Ave
        /   \       / \
     Perro Gato  Loro Aguila
```

**Clase base `Animal`:**

- `nombre` (string)
- `edad` (int)
- `peso` (double)

Métodos virtuales:

- `hacerSonido()` virtual
- `mostrarInfo()` virtual
- Getters y Setters

**Clase intermedia `Mamífero` hereda de `Animal`:**

- Atributo: `tieneColaMamífero` (bool)
- Sobrescribir métodos

**Clase intermedia `Ave` hereda de `Animal`:**

- Atributo: `envergaduraAlas` (double)
- Sobrescribir métodos

**Clases finales:**

- `Perro`, `Gato`, `Loro`, `Aguila` heredan de sus respectivas clases intermedias

**Ejemplo de uso:**

```
Perro perro("Rex", 5, 25, true);
Gato gato("Whiskers", 3, 4.5, false);
Loro loro("Tweety", 2, 0.5, 0.3);

perro.mostrarInfo();
perro.hacerSonido();

gato.mostrarInfo();
gato.hacerSonido();

loro.mostrarInfo();
loro.hacerSonido();
```

---

### Ejercicio 3.2: Sistema Bancario

Crea una jerarquía:

```
        Cuenta
       /      \
   CuentaAhorro CuentaCorriente
```

**Clase base `Cuenta`:**

- `numeroCuenta` (string)
- `propietario` (string)
- `saldo` (double)

Métodos:

- `depositar(double monto)` virtual
- `retirar(double monto)` virtual
- `mostrarInfo()` virtual
- Getters y Setters con validaciones

**Clase `CuentaAhorro` hereda de `Cuenta`:**

- Atributo: `tasaInteres` (double)
- Método: `generarInteres()` que calcule y agregue interés
- Sobrescribir `depositar()` y `retirar()`

**Clase `CuentaCorriente` hereda de `Cuenta`:**

- Atributo: `limiteDescubierto` (double)
- Método: `solicitarDescubierto(double monto)`
- Sobrescribir `depositar()` y `retirar()`

**Ejemplo de uso:**

```
CuentaAhorro ahorros("123456", "Carlos", 5000, 0.02);
CuentaCorriente corriente("789012", "Ana", 2000, 1000);

ahorros.depositar(1000);
ahorros.mostrarInfo();
ahorros.generarInteres();
ahorros.mostrarInfo();

corriente.retirar(2500); // Usa descubierto
corriente.mostrarInfo();
```

---

## Nivel 4️⃣: Desafío - Combinación de Conceptos

### Ejercicio 4.1: Sistema de Universidades

**Crea una estructura completa con:**

1. Clase `Persona` (base)

   - Atributos: nombre, edad, cédula
   - Métodos: getters, setters, mostrarInfo()

2. Clases derivadas de `Persona`:

   - `Estudiante` (carrera, promedio, semestre)
   - `Profesor` (especialidad, años_experiencia, número_estudiantes)
   - `Personal` (puesto, departamento, salario)

3. Dentro de `Estudiante`:

   - Crear clase `Curso` (código, nombre, creditos, profesor)
   - Métodos para matricular cursos, ver calificaciones

4. Métodos especiales en cada clase:
   - `Estudiante::calcularPromedioActual()`
   - `Profesor::estaDisponible(int horaDelDía)`
   - `Personal::calcularSalarioMensual()`

---

## 📋 Rúbrica de Evaluación

| Criterio                             | Puntos  |
| ------------------------------------ | ------- |
| Encapsulamiento (atributos privados) | 10      |
| Getters y Setters con validaciones   | 20      |
| Constructores correctos              | 10      |
| Métodos de instancia funcionales     | 20      |
| Herencia implementada correctamente  | 20      |
| Polimorfismo (override)              | 10      |
| Entrada interactiva desde consola    | 5       |
| Documentación/Comentarios            | 5       |
| **Total**                            | **100** |

---

## 🔍 Checklist para cada Ejercicio

Antes de entregar, verifica que:

- [ ] **Compilación:** El código compila sin errores
- [ ] **Ejecución:** El programa se ejecuta sin errores de runtime
- [ ] **Encapsulamiento:** Los atributos privados no son accesibles directamente
- [ ] **Validaciones:** Los setters validan los datos de entrada
- [ ] **Herencia:** Las clases derivadas heredan correctamente de sus bases
- [ ] **Polimorfismo:** Los métodos virtuales se sobrescriben correctamente
- [ ] **Entrada:** El programa pide datos por consola
- [ ] **Salida:** La información se muestra de manera clara y organizada
- [ ] **Documentación:** Hay comentarios explicando el código

---

## 💡 Consejos

1. **Comienza por lo simple:** Domina getters y setters antes de herencia
2. **Usa `protected` en clases base:** Permite acceso a las clases derivadas
3. **Haz métodos virtuales:** Para permitir sobrescritura en clases derivadas
4. **Valida siempre:** Especialmente en setters
5. **Prueba incrementalmente:** Compila y prueba después de cada cambio
6. **Usa `override`:** Para claridad al sobrescribir métodos (C++11+)
7. **Libera memoria:** Si usas `new`, usa `delete` (O mejor, evítalo)

---

## 📚 Recursos Adicionales

- Principios SOLID aplicados a POO
- Relaciones entre objetos (asociación, composición, agregación)
- Herencia vs Composición
- Polimorfismo paramétrico (templates)

---

**Fecha de entrega:** [Especificar fecha]  
**Formato de entrega:** Archivo .cpp compilable  
**Lenguaje:** C++17 o superior
