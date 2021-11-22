#include "WaveformSelector.h"

void WaveformSelector::resized() {
    label.setBounds(3, 3, getWidth() - 6, 20);
    squareButton.setBounds(3, 30, getWidth() - 6, 20);
    sawButton.setBounds(3, 55, getWidth() - 6, 20);
    sinButton.setBounds(3, 80, getWidth() - 6, 20);
    triangleButton.setBounds(3, 105, getWidth() - 6, 20);
}