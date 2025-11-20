import processing.serial.*;

Serial puerto;

void setup() {
  size(600, 200);
  // Ajusta el nombre del puerto según tu PC
  puerto = new Serial(this, "COM6", 9600);
}

void draw() {
  background(200);

  // Dibujar cuadros
  fill(255, 0, 0);   rect(20, 50, 100, 100);   // Rojo
  fill(0, 255, 0);   rect(140, 50, 100, 100);  // Verde
  fill(0, 0, 255);   rect(260, 50, 100, 100);  // Azul
  fill(255, 255, 0); rect(380, 50, 100, 100);  // Amarillo
  fill(255);         rect(500, 50, 100, 100);  // Blanco
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
