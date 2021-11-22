#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor& p)
: AudioProcessorEditor (&p), processorRef (p)
{
    juce::ignoreUnused (processorRef);
    setSize (1280, 720);

    //set callbacks for setting parameters

    addAndMakeVisible(osc1WaveformSelector);

    addAndMakeVisible(osc2WaveformSelector);
    addAndMakeVisible(osc2PitchSemitonesControl);
    addAndMakeVisible(osc2PitchFineControl);

    addAndMakeVisible(osc1LevelControl);
    addAndMakeVisible(osc2LevelControl);
    addAndMakeVisible(noiseLevelControl);

    addAndMakeVisible(ampAttackControl);
    addAndMakeVisible(ampDecayControl);
    addAndMakeVisible(ampSustainControl);
    addAndMakeVisible(ampReleaseControl);

    addAndMakeVisible(filterFrequencyControl);
    addAndMakeVisible(filterResonanceControl);
    addAndMakeVisible(filterEnvelopeAmountControl);

    addAndMakeVisible(filterAttackControl);
    addAndMakeVisible(filterDecayControl);
    addAndMakeVisible(filterSustainControl);
    addAndMakeVisible(filterReleaseControl);

    addAndMakeVisible(volumeControl);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::yellow);
    g.setFont (15.0f);
}

void AudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    osc1WaveformSelector.setBounds(0, 0, 100, 125);
    osc2WaveformSelector.setBounds(0, 125, 100, 125);

    osc2PitchSemitonesControl.setBounds(100, 125, 100, 125);
    osc2PitchFineControl.setBounds(200, 125, 100, 125);

    osc1LevelControl.setBounds(350, 0, 100, 125);
    osc2LevelControl.setBounds(450, 0, 100, 125);
    noiseLevelControl.setBounds(550, 0, 100, 125);

    ampAttackControl.setBounds(700, 0, 100, 125);
    ampDecayControl.setBounds(800, 0, 100, 125);
    ampSustainControl.setBounds(900, 0, 100, 125);
    ampReleaseControl.setBounds(1000, 0, 100, 125);

    filterFrequencyControl.setBounds(0, 250, 100, 125);
    filterResonanceControl.setBounds(100, 250, 100, 125);
    filterEnvelopeAmountControl.setBounds(200, 250, 100, 125);

    filterAttackControl.setBounds(350, 250, 100, 125);
    filterDecayControl.setBounds(450, 250, 100, 125);
    filterSustainControl.setBounds(550, 250, 100, 125);
    filterReleaseControl.setBounds(650, 250, 100, 125);

    volumeControl.setBounds(getWidth() - 100, getHeight() - 125, 100, 125);
}