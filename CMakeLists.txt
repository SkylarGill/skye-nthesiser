cmake_minimum_required(VERSION 3.20)

project(Skyenthesiser VERSION 0.0.1)

add_subdirectory("lib/Juce" JUCE)
add_subdirectory("lib/DaisySP" DaisySP)

juce_add_plugin(Skyenthesiser
        VST_CATEGORIES Instrument Synth
        NEEDS_MIDI_INPUT TRUE               # Does the plugin need midi input?
        PLUGIN_MANUFACTURER_CODE Skye               # A four-character manufacturer id with at least one upper-case character
        PLUGIN_CODE Skye                            # A unique four-character plugin id with exactly one upper-case character
        FORMATS AU VST3 Standalone                  # The formats to build. Other valid formats are: AAX Unity VST AU AUv3
        PRODUCT_NAME "Skye-nthesiser")        # The name of the final executable, which can differ from the target name

juce_generate_juce_header(Skyenthesiser)

target_sources(Skyenthesiser
        PRIVATE
        PluginEditor.cpp
        PluginEditor.h
        PluginProcessor.cpp
        PluginProcessor.h
        modulation/Modulatable.h
        synth/Synth.h
        synth/SynthEngine.cpp
        synth/SynthEngine.h
        interface/LabelledRotaryControl.cpp
        interface/LabelledRotaryControl.h
        interface/WaveformSelector.cpp
        interface/WaveformSelector.h)

target_compile_definitions(Skyenthesiser
        PUBLIC
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_plugin` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_plugin` call
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(Skyenthesiser
        PRIVATE
        # AudioPluginData           # If we'd created a binary data target, we'd link to it here
        juce::juce_audio_utils
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
        DaisySP)
