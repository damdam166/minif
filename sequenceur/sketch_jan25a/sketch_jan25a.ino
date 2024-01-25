#include <Servo.h>

Servo servomoteur;
const int pinservomoteur = 3;
const int pininterrupteur_entree = 6;
const int pininterrupteur_sortie = 9;
bool interrupteurPresse = false;

void setup() {
  Serial.begin(9600);
  servomoteur.attach(pinservomoteur);
  servomoteur.write(0);

  pinMode(pininterrupteur_entree, INPUT);
}

void loop() {

  int etatInterrupteur = digitalRead(pininterrupteur_entree);

  if (etatInterrupteur == HIGH && !interrupteurPresse) {
    // Si le bouton-poussoir est pressé et l'interrupteur n'a pas été déjà pressé
    interrupteurPresse = true;
    servomoteur.write(90);  // Déclenchement au décollage
  } else if (etatInterrupteur == LOW && interrupteurPresse) {
    // Si le bouton-poussoir est relâché et l'interrupteur était pressé précédemment
    interrupteurPresse = false;
    servomoteur.write(0);  // Réinitialisation lorsque le bouton est relâché
  }

  delay(1000);
}