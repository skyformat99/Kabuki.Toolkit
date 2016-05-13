# Kabuki.Toolkit #
Kabuki.Toolkit is a robust cross-platform C++ SDK that unifies some of the best C and C++ APIs into a common naming scheme and coding convention designed to reduce typing. The cross-platform graphics engine is based on the Theora Player, GLUI, GFX engine, and some original code.

# Modules #
| Name | Description |
|------|:------------|
| _2D | 2D tools, images, fonts, and video.|
| _3D | 3D tools.|
| _4D | 4D tools.|
| _Audio | Audio.|
| _Data | Data structures, XML, and JSON.|
| _App | Application framework.|
| _G | Graphics.|
| _GUI | GUI toolkit.|
| _Math | Math.|
| _MM | Audio, MIDI, and Video.|
| _Test | Unit testing framework.|
| _Text | Text utilities.|

# Included Libraries #
* [Cairo](http://cairographics.org/) 1.14.6
* [FreeImage](http://freeimage.sourceforge.net/) 3.17.0
* [GLUI](http://glui.sourceforge.net/) 3.36
* [GFX Engine](http://gfx.sio2interactive.com/)
* [MathGeoLib](http://clb.demon.fi/MathGeoLib/nightly/)
* [Theora Playback Library](http://libtheoraplayer.cateia.com/) 1.0RC2
* [Poco](http://pocoproject.org/) 1.7.0
* [Tess2](https://github.com/diatomic/tess2/issues/4)
* [CPPUnit](https://sourceforge.net/projects/cppunit/)
* [UTF8++](https://github.com/Drako/utf8pp) 2.3.4
* [C++ String Toolkit](https://github.com/ArashPartow/strtk)

# Status: Alpha #
The SDK is not funcitoning right now due to me collapsing the file structures of all the libraries to remove all junk. Currently, all libraries have been stripped of almost all the junk, and the copyright notices put into the Copyright folder. There are about 20 sub-modules that need to get the "include/ModuleName" stripped form the includes. The reason for me doing this is 1.) becuase the libraries have not changed in many many years. 2.) it ones the files back up for being edited again.

 The next step is to unify all the unit tests into a single runner. Also, most of the libraries are setup to export to different libraries. These DLL tags need to _KabukiToolkit.

## Under Construction ##
1.) 

# License #
Kabuki.Toolkit is distributed multiple licenses. Copies of the original copyright notices can be found in the Copyright folder. Original code is licensed under the Apache 2.0 license. You may obtain a copy of the License at:
[http://www.apache.org/licenses/LICENSE-2.0](http://www.apache.org/licenses/LICENSE-2.0)
