import processing.serial.*;

Serial puerto;

int r = 0, g = 0, b = 0;

void setup() {
  size(400, 300);
  puerto = new Serial(this, "COM6", 9600);
}

void draw() {
  background(r, g, b); // fondo muestra el color actual

  // Slider Rojo
  fill(255, 0, 0);
  rect(50, 50, 255, 20);
  fill(0);
  rect(50 + r, 50, 10, 20);

  // Slider Verde
  fill(0, 255, 0);
  rect(50, 100, 255, 20);
  fill(0);
  rect(50 + g, 100, 10, 20);

  // Slider Azul
  fill(0, 0, 255);
  rect(50, 150, 255, 20);
  fill(0);
  rect(50 + b, 150, 10, 20);

  // Mostrar valores
  fill(0);
  text("R: " + r + " G: " + g + " B: " + b, 50, 200);
}

void mouseDragged() {
  // Detectar slider rojo
  if (mouseY > 50 && mouseY < 70 && mouseX > 50 && mouseX < 305) {
    r = mouseX - 50;
  }
  // Slider verde
  if (mouseY > 100 && mouseY < 120 && mouseX > 50 && mouseX < 305) {
    g = mouseX - 50;
  }
  // Slider azul
  if (mouseY > 150 && mouseY < 170 && mouseX > 50 && mouseX < 305) {
    b = mouseX - 50;
  }

  // Enviar valores al Arduino
  puerto.write(r + "," + g + "," + b + "\n");
}
