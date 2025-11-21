import processing.serial.*;

Serial puerto;

void setup() {
  size(630, 250);
  surface.setResizable(true); // permitir agrandar ventana
  puerto = new Serial(this, "COM6", 9600);
  // Ajusta el nombre del puerto en mi caso COM6
  puerto = new Serial(this, "COM6", 9600);
}

void draw() {
  background(0);

  // Dibujar cuadros
  fill(255);         rect(500, 50, 100, 100);  // Blanco
  fill(255, 255, 0); rect(380, 50, 100, 100);  // Amarillo
  fill(0, 0, 255);   rect(260, 50, 100, 100);  // Azul
  fill(0, 255, 0);   rect(140, 50, 100, 100);  // Verde
  fill(255, 0, 0);   rect(20, 50, 100, 100);   // Rojo
}

void mousePressed() {
  // Detectar clic en cada cuadro
  if (mouseX > 20 && mouseX < 120 && mouseY > 50 && mouseY < 150) {
    puerto.write('R'); // Rojo
  }
  if (mouseX > 140 && mouseX < 240 && mouseY > 50 && mouseY < 150) {
    puerto.write('G'); // Verde
  }
  if (mouseX > 260 && mouseX < 360 && mouseY > 50 && mouseY < 150) {
    puerto.write('B'); // Azul
  }
  if (mouseX > 380 && mouseX < 480 && mouseY > 50 && mouseY < 150) {
    puerto.write('Y'); // Amarillo
  }
  if (mouseX > 500 && mouseX < 600 && mouseY > 50 && mouseY < 150) {
    puerto.write('W'); // Blanco
  }
}

