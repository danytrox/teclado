
# Mi Configuración Personal de Lily58 (QMK Firmware)

Este repositorio contiene la configuración personalizada para mi teclado ergonómico dividido **Lily58 (Revisión 1)**. Incluye un mapa de teclas optimizado, soporte para **Luces LED (RGB Underglow)** y personalización de las **pantallas OLED** con un logotipo gráfico de 16x16px.

## 📂 Contenido del Repositorio
* `nodelay.json`: Archivo de configuración compatible con QMK Configurator (para edición visual).
* `keymap.c`: Código fuente nativo en C con la programación avanzada de las pantallas OLED y el mapa de capas.

---

## 🚀 Guía de Instalación Rápida (Fedora Linux)

Sigue estos pasos en tu terminal para clonar este repositorio e instalar el firmware directamente en el teclado.

### 1. Clonar este repositorio
Descarga estos archivos en tu carpeta de Documentos:
```bash
cd ~/Documentos
git clone [https://github.com/TU_USUARIO/TU_REPOSITORIO.git](https://github.com/TU_USUARIO/TU_REPOSITORIO.git) teclado

#2. Configurar el entorno de QMK para Linux :P

Instala la interfaz de comandos de QMK y prepara el repositorio oficial del firmware:

# Instalar QMK CLI
python3 -m pip install --user qmk

# Inicializar el repositorio oficial de QMK
qmk setup

###3. Vincular el mapa de teclas personalizado
#Creamos la ruta correspondiente dentro del árbol de QMK y copiamos #nuestro archivo de código:

# Crear la ruta del keymap en el firmware de QMK
mkdir -p ~/qmk_firmware/keyboards/lily58/keymaps/danery

# Copiar el archivo keymap.c a la carpeta interna de QMK
cp ~/Documentos/teclado/keymap.c ~/qmk_firmware/keyboards/lily58/keymaps/danery/keymap.c

#4. Habilitar OLEDs y LEDs (RGB) en el Hardware
#Debemos asegurar que las características físicas del teclado estén encendidas en el firmware base de la revisión.

Abre el archivo de reglas con tu editor favorito:

nano ~/qmk_firmware/keyboards/lily58/rev1/rules.mk
Verifica o añade al final del archivo las siguientes líneas:

Makefile
RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes
Abre el archivo de configuración de hardware:

nano ~/qmk_firmware/keyboards/lily58/rev1/config.h
Asegúrate de reemplazar o verificar que existan estas líneas exactas para la gestión de los LEDs:

C
#define WS2812_DI_PIN D3
#define RGBLED_SPLIT { 6, 6 }

```
# 🎨 Cómo Personalizar o Crear Nuevos Logos para la OLED
Para transformar imágenes pixelart, dibujos o iconos en arreglos de bytes compatibles con la pantalla de la Lily58, se utiliza la siguiente herramienta web:

🔗 Herramientas de conversión: [Image2cpp (GitHub Pages)](https://javl.github.io/image2cpp/).

## Configuración correcta en la web para QMK:


* `Canvas size:` Define el tamaño exacto de tu imagen (ej. 16 x 16 píxeles para iconos independientes, o máximo 128 x 32 si es para ocupar la pantalla completa).

* `Background color:` Selecciona Black o White dependiendo del contraste que busques.

* `Scaling:` Scale to fit, keeping proportions.

* `Draw mode (CRÍTICO):` Selecciona Vertical - 1 bit per pixel (también conocido como Column major), ya que es el modo en el que el driver de QMK lee las pantallas SSD1306 de la Lily58.

* Haz clic en Generate code y copia el bloque de texto con los bytes hexadecimales (ej. 0x00, 0xFF, ...) directamente en el arreglo static const char PROGMEM icono_danery[] dentro de tu keymap.c.

# 🔄 Cómo actualizar el código si modificas el JSON
Si realizas cambios visuales en la web de QMK Configurator y descargas un nuevo archivo .json, debes transformarlo a código nativo en C reemplazando el archivo antiguo:


```Bash
# 1. Convertir el nuevo JSON al formato keymap.c de QMK
qmk json2c ~/Documentos/teclado/nodelay.json > ~/qmk_firmware/keyboards/lily58/keymaps/danery/keymap.c

# 2. ¡Importante!
# La conversión borrará el código personalizado de la pantalla OLED e Image2cpp. 
# Recuerda abrir el nuevo archivo con nano y pegar de nuevo el bloque '#ifdef OLED_ENABLE' al final.
nano ~/qmk_firmware/keyboards/lily58/keymaps/danery/keymap.c
⚡ Compilar y Flashear
Una vez guardados todos los archivos anteriores, conecta tu teclado y ejecuta el comando de flasheo:

qmk flash -kb lily58/rev1 -km danery
🔄 Proceso con el Bootloader (Caterina):
Tras ejecutar el comando, la terminal se detendrá mostrando puntos suspensivos (Waiting for USB serial port - reset your controller now...).

Presiona el botón físico de Reset en la mitad del teclado conectada por USB.

Al finalizar la barra de progreso, desconecta el cable USB, conéctalo a la otra mitad, ejecuta el mismo comando de flasheo y presiona el botón de Reset de ese lado. Ambas mitades se flashean de forma independiente.
```