# Kabuki.Toolkit #
Kabuki.Toolkit is a robust cross-platform C++17 SDK that unifies many popular C++ APIs into a common naming scheme and coding convention. C++17 is not fully out yet, so we're using UTF8++ and Boost for the time being. The toolkit (when it's working) speeds up cross-platform C++ app development by unifying some of the best C and C++ libraries into a single unified namesapce with ubiquitous coding and naming conventions designed to reduce typing. Cross-platform code exists in dummy templates, allowing cross-platform code to be mixed in with the main library.

The toolkit is written with C++17 in mind, which currently isn't out . We plan on being the world's first all cross-platform C++17 API. Currently, all libraries are getting stripped of any junk, ran through ReSharper++, and all unit tests unified into a single runner. Currently these APIs are loaded up with all kinds of stupid bad programming practices, so its just a matter of getting the libraries working one at a time.

# Modules #
| Name | Description |
|------|:------------|
| _2D | 3D Geometry.|
| _3D | 2D Geometry.|
| _Data | Data Structures.|
| _App | Application framework.|
| _G | Generic graphics.|
| _GUI | GUI toolkit.|
| _Math | Math.|
| _MM | Audio, MIDI, and Video.|
| _Test | Unit testing framework.|
| _Text | Text utilities.|
| _World | Time/Date utilities (GPS in the future.).|

# License #
Kabuki.Toolkit is distributed multiple licenses. Copies of the original copyright notices can be found in the Copyright folder. Original code is licensed under the Apache 2.0 license. You may obtain a copy of the License at:
[http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)

# Included Libraries #
* [Cairo](http://cairographics.org/) 1.14.6
* [FreeImage](http://freeimage.sourceforge.net/) 3.17.0
* [GLUI](http://glui.sourceforge.net/) 3.36
* [Theora Playback Library](http://libtheoraplayer.cateia.com/) 1.0RC2
* [Poco](http://pocoproject.org/) 1.7.0
* [Tess2](https://github.com/diatomic/tess2/issues/4) x.?
* [UTF8++](https://github.com/Drako/utf8pp) 2.3.4
* [C++ String Toolkit](https://github.com/ArashPartow/strtk)
