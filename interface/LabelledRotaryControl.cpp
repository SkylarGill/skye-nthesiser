#include "LabelledRotaryControl.h"

void LabelledRotaryControl::resized() {
    label.setBounds(3, 3, getWidth() - 6, 25);
    slider.setBounds(3, 25, getWidth() - 6, getHeight() - 38);
}